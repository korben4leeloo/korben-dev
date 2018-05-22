//*****************************************************************************
//
//	File:		QmD3DContext.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "QmD3DContext.h"

#include <d3d12.h>
#include <dxgi1_5.h>
//#include <d3d12sdklayers.h>

#include QUANTUM_CORE_H(Rendering/Window/QmWindow)

#define RELEASE_D3D_INTERFACE( pInterface ) \
	if ( pInterface ) \
	{ \
		pInterface->Release(); \
		pInterface = nullptr; \
	} \

static uint32 uiSwapChainBufferCount = 3; // Default swap chain buffer count setup for triple buffering

//-----------------------------------------------------------------------------
// Name:		QmD3DContext constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmD3DContext::QmD3DContext()
//: _pSwapChain			( nullptr )
//, _pD3D11Device			( nullptr )
//, _pD3D11DeviceContext	( nullptr )
//, _pRenderTargetView	( nullptr )
{
	
}

//-----------------------------------------------------------------------------
// Name:		QmD3DContext destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmD3DContext::~QmD3DContext()
{
	destroy();
}

//-----------------------------------------------------------------------------
// Name:		create
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
bool QmD3DContext::create( QmWindow* pWindow )
{
	HRESULT hr;

	// Enable debug layer
	ID3D12Debug* pDebugInterface;
	hr = D3D12GetDebugInterface( IID_PPV_ARGS( &pDebugInterface ) );

	if ( SUCCEEDED( hr ) )
	{
		pDebugInterface->EnableDebugLayer();
	}

	// Create the factory
	if ( FAILED( CreateDXGIFactory2( DXGI_CREATE_FACTORY_DEBUG, IID_PPV_ARGS( &_pDXGIFactory ) ) ) )
	{
		return false;
	}

	// Find a suitable D3D12 GPU adapter
	IDXGIAdapter1* pDXGIAdapter = findAdapter();

	if ( !pDXGIAdapter )
	{
		return false;
	}

	// Create D3D12 device
	if ( FAILED( hr = D3D12CreateDevice( pDXGIAdapter, D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS( &_pD3DDevice ) ) ) )
	{
		return false;
	}

	DXGI_ADAPTER_DESC1 desc;
	pDXGIAdapter->GetDesc1( &desc );
	QUANTUM_MESSAGE( "Creating DirectX 12 device on following GPU: %s", QmString::fromUnicode( desc.Description ).buffer() );

	// Setup debug layer info queue
	if ( SUCCEEDED( hr = _pD3DDevice->QueryInterface( IID_PPV_ARGS( &_pD3DInfoQueue ) ) ) )
	{
		_pD3DInfoQueue->SetBreakOnSeverity( D3D12_MESSAGE_SEVERITY_CORRUPTION, TRUE );
		_pD3DInfoQueue->SetBreakOnSeverity( D3D12_MESSAGE_SEVERITY_ERROR, TRUE );
		_pD3DInfoQueue->SetBreakOnSeverity( D3D12_MESSAGE_SEVERITY_WARNING, TRUE );
	}

	// Create command queue
	D3D12_COMMAND_QUEUE_DESC cmdQueueDesc;

	cmdQueueDesc.Type		= D3D12_COMMAND_LIST_TYPE_DIRECT;
	cmdQueueDesc.Priority	= D3D12_COMMAND_QUEUE_PRIORITY_NORMAL;
	cmdQueueDesc.Flags		= D3D12_COMMAND_QUEUE_FLAG_NONE;
	cmdQueueDesc.NodeMask	= 0;

	if ( FAILED( _pD3DDevice->CreateCommandQueue( &cmdQueueDesc, IID_PPV_ARGS( &_pD3DCommandQueue ) ) ) )
	{
		return false;
	}

	// Create the swap chain
	DXGI_SWAP_CHAIN_DESC1 swapChainDesc = {};

	RECT wndRect;
	GetWindowRect( pWindow->getWindowHandle(), &wndRect );

	swapChainDesc.SampleDesc.Count		= 1; // minimal sampling
	swapChainDesc.SampleDesc.Quality	= 0;

	swapChainDesc.Width			= wndRect.right - wndRect.left;
	swapChainDesc.Height		= wndRect.bottom - wndRect.top;
	swapChainDesc.Format		= DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.Stereo		= FALSE;
	swapChainDesc.BufferUsage	= DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.BufferCount	= uiSwapChainBufferCount;
	swapChainDesc.Scaling		= DXGI_SCALING_STRETCH;
	swapChainDesc.SwapEffect	= DXGI_SWAP_EFFECT_FLIP_DISCARD;
	swapChainDesc.AlphaMode		= DXGI_ALPHA_MODE_UNSPECIFIED;

	// Check tearing support and setup swap chain desc in consequence
	// It is recommended to always allow tearing if tearing support is available.
	BOOL bTearingSupport = false;
	hr = _pDXGIFactory->CheckFeatureSupport( DXGI_FEATURE_PRESENT_ALLOW_TEARING, &bTearingSupport, sizeof( bTearingSupport ) );
	swapChainDesc.Flags = bTearingSupport ? DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING : 0;

	if ( FAILED( hr = _pDXGIFactory->CreateSwapChainForHwnd( _pD3DCommandQueue, pWindow->getWindowHandle(), &swapChainDesc, nullptr, nullptr, &_pD3DSwapChain ) ) )
	{
		return false;
	}

	// Creating the render target descriptor heap
	ID3D12DescriptorHeap*		pDescriptorHeapRTV;
	D3D12_DESCRIPTOR_HEAP_DESC	heapRTVDesc = {};

	heapRTVDesc.NumDescriptors	= uiSwapChainBufferCount;
	heapRTVDesc.Type			= D3D12_DESCRIPTOR_HEAP_TYPE_RTV;

	if ( FAILED( hr = _pD3DDevice->CreateDescriptorHeap( &heapRTVDesc, IID_PPV_ARGS( &pDescriptorHeapRTV ) ) ) )
	{
		return false;
	}

	// Get a handle to the first RTV descriptor in the descriptor heap ( in fact a pointer )
	D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle = pDescriptorHeapRTV->GetCPUDescriptorHandleForHeapStart();

	// Iterate through each RTV descriptor handle, create and bind a RTV to each back buffer of the swap chain
	UINT uiDescHeapRTVSize = _pD3DDevice->GetDescriptorHandleIncrementSize( D3D12_DESCRIPTOR_HEAP_TYPE_RTV );

	_ppRenderTargetArray = new ID3D12Resource*[uiSwapChainBufferCount];

	for ( uint32 i = 0; i < uiSwapChainBufferCount; i++ )
	{
		if ( FAILED( hr = _pD3DSwapChain->GetBuffer( i, IID_PPV_ARGS( &_ppRenderTargetArray[i] ) ) ) )
		{
			return false;
		}

		_pD3DDevice->CreateRenderTargetView( _ppRenderTargetArray[i], nullptr, rtvHandle );
		rtvHandle.ptr += uiDescHeapRTVSize;
	}

	return true;
}

//-----------------------------------------------------------------------------
// Name:		findAdapter
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
IDXGIAdapter1* QmD3DContext::findAdapter() const
{
	IDXGIAdapter1* pBestDXGIAdapter = nullptr;

	if ( _pDXGIFactory )
	{
		IDXGIAdapter1*		pDXGIAdapter	= nullptr; // adapters are the graphics card (this includes the embedded graphics on the motherboard)
		uint32				nAdapterIndex	= 0;
		DXGI_ADAPTER_DESC1	bestAdapterDesc;

		memset( &bestAdapterDesc, 0, sizeof(DXGI_ADAPTER_DESC1) );

		// Find the best hardware GPU that supports d3d 12
		while ( _pDXGIFactory->EnumAdapters1( nAdapterIndex, &pDXGIAdapter ) != DXGI_ERROR_NOT_FOUND )
		{
			DXGI_ADAPTER_DESC1 desc;
			pDXGIAdapter->GetDesc1( &desc );

			if ( desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE )
			{
				// We don't want a software device
				nAdapterIndex++;
				continue;
			}

			if ( !pBestDXGIAdapter || ( desc.DedicatedVideoMemory > bestAdapterDesc.DedicatedVideoMemory ) )
			{
				// nullptr for the last argument means just checking the d3d 12 compatibility, the device is actually not created
				if ( SUCCEEDED( D3D12CreateDevice( pDXGIAdapter, D3D_FEATURE_LEVEL_11_0, _uuidof( ID3D12Device ), nullptr ) ) )
				{
					pBestDXGIAdapter	= pDXGIAdapter;
					bestAdapterDesc		= desc;
				}
			}

			nAdapterIndex++;
		}
	}

	return pBestDXGIAdapter;
}

//-----------------------------------------------------------------------------
// Name:		destroy
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void QmD3DContext::destroy()
{
	/*RELEASE_D3D_INTERFACE( _pSwapChain )
	RELEASE_D3D_INTERFACE( _pD3D11Device );
	RELEASE_D3D_INTERFACE( _pD3D11DeviceContext );*/
}
