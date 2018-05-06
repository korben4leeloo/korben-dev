//*****************************************************************************
//
//	File:		QmD3DContext.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "QmD3DContext.h"

#include <d3d12.h>
#include <dxgi1_4.h>

#include QUANTUM_CORE_H(Rendering/Window/QmWindow)

#define RELEASE_D3D_INTERFACE( pInterface ) \
	if ( pInterface ) \
	{ \
		pInterface->Release(); \
		pInterface = nullptr; \
	} \

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
void QmD3DContext::create( QmWindow* pWindow )
{
	// Find a suitable D3D12 GPU adapter
	IDXGIAdapter1* pDXGIAdapter = findAdapter();

	if ( !pDXGIAdapter )
	{
		return;
	}

	// Create D3D12 device
	HRESULT hr = D3D12CreateDevice( pDXGIAdapter, D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS( &_pD3D12Device ) );

	if ( SUCCEEDED( hr ) )
	{
		DXGI_ADAPTER_DESC1 desc;
		pDXGIAdapter->GetDesc1( &desc );

		QUANTUM_MESSAGE( "Creating DirectX 12 device on following GPU: %s", QmString::fromUnicode( desc.Description ).buffer() );
	}

	////Describe our Buffer
	//DXGI_MODE_DESC bufferDesc;

	//ZeroMemory(&bufferDesc, sizeof(DXGI_MODE_DESC));

	//RECT wndRect;
	//GetWindowRect( pWindow->getWindowHandle(), &wndRect );

	//bufferDesc.Width					= wndRect.right - wndRect.left;
	//bufferDesc.Height					= wndRect.bottom - wndRect.top;
	//bufferDesc.RefreshRate.Numerator	= 60;
	//bufferDesc.RefreshRate.Denominator	= 1;
	//bufferDesc.Format					= DXGI_FORMAT_R8G8B8A8_UNORM;
	//bufferDesc.ScanlineOrdering			= DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	//bufferDesc.Scaling					= DXGI_MODE_SCALING_UNSPECIFIED;
 //   
	////Describe our SwapChain
	//DXGI_SWAP_CHAIN_DESC swapChainDesc; 
 //   
	//ZeroMemory(&swapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));

	//swapChainDesc.BufferDesc			= bufferDesc;
	//swapChainDesc.SampleDesc.Count		= 1;
	//swapChainDesc.SampleDesc.Quality	= 0;
	//swapChainDesc.BufferUsage			= DXGI_USAGE_RENDER_TARGET_OUTPUT;
	//swapChainDesc.BufferCount			= 1;
	//swapChainDesc.OutputWindow			= pWindow->getWindowHandle(); 
	//swapChainDesc.Windowed				= TRUE; 
	//swapChainDesc.SwapEffect			= DXGI_SWAP_EFFECT_DISCARD;

	////Create our SwapChain
	//D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, NULL, NULL, NULL,
	//	D3D11_SDK_VERSION, &swapChainDesc, &_pSwapChain, &_pD3D11Device, NULL, &_pD3D11DeviceContext);

	////Create our BackBuffer
	//ID3D11Texture2D* BackBuffer;
	//_pSwapChain->GetBuffer( 0, __uuidof( ID3D11Texture2D ), (void**)&BackBuffer );

	////Create our Render Target
	//_pD3D11Device->CreateRenderTargetView( BackBuffer, NULL, &_pRenderTargetView );
	//BackBuffer->Release();

	////Set our Render Target
	//_pD3D11DeviceContext->OMSetRenderTargets( 1, &_pRenderTargetView, NULL );
}

//-----------------------------------------------------------------------------
// Name:		findAdapter
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
IDXGIAdapter1* QmD3DContext::findAdapter() const
{
	IDXGIFactory4*	pDXGIFactory		= nullptr;
	IDXGIAdapter1*	pDXGIAdapter		= nullptr; // adapters are the graphics card (this includes the embedded graphics on the motherboard)
	IDXGIAdapter1*	pBestDXGIAdapter	= nullptr;

	// Create factory
	if ( SUCCEEDED( CreateDXGIFactory1( IID_PPV_ARGS( &pDXGIFactory ) ) ) )
	{
		uint32				nAdapterIndex = 0; // we'll start looking for directx 12  compatible graphics devices starting at index 0
		DXGI_ADAPTER_DESC1	bestAdapterDesc;

		memset( &bestAdapterDesc, 0, sizeof(DXGI_ADAPTER_DESC1) );

		// find first hardware gpu that supports d3d 12
		while ( pDXGIFactory->EnumAdapters1( nAdapterIndex, &pDXGIAdapter ) != DXGI_ERROR_NOT_FOUND )
		{
			DXGI_ADAPTER_DESC1 desc;
			pDXGIAdapter->GetDesc1( &desc );

			if ( desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE )
			{
				// we dont want a software device
				nAdapterIndex++; // add this line here. Its not currently in the downloadable project
				continue;
			}

			if ( !pBestDXGIAdapter || ( desc.DedicatedVideoMemory > bestAdapterDesc.DedicatedVideoMemory ) )
			{
				HRESULT hr = D3D12CreateDevice( pDXGIAdapter, D3D_FEATURE_LEVEL_11_0, _uuidof( ID3D12Device ), nullptr );

				if ( SUCCEEDED( hr ) )
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
