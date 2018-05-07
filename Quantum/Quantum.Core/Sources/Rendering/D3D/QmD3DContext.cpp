//*****************************************************************************
//
//	File:		QmD3DContext.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "QmD3DContext.h"

#include <d3d12.h>
#include <dxgi1_4.h>
//#include <d3d12sdklayers.h>

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
		return;
	}

	// Find a suitable D3D12 GPU adapter
	IDXGIAdapter1* pDXGIAdapter = findAdapter();

	if ( !pDXGIAdapter )
	{
		return;
	}

	// Create D3D12 device
	if ( FAILED( D3D12CreateDevice( pDXGIAdapter, D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS( &_pD3D12Device ) ) ) )
	{
		return;
	}

	DXGI_ADAPTER_DESC1 desc;
	pDXGIAdapter->GetDesc1( &desc );
	QUANTUM_MESSAGE( "Creating DirectX 12 device on following GPU: %s", QmString::fromUnicode( desc.Description ).buffer() );

	// Setup debug layer info queue
	ID3D12InfoQueue* pInfoQueue;

	/*ComPtr<ID3D12InfoQueue> InfoQueueComPtr;
	ComPtr<ID3D12Device> D3D12DeviceComPtr( _pD3D12Device );

	HRESULT hr = D3D12DeviceComPtr.As( &InfoQueueComPtr );*/

	if ( SUCCEEDED( hr = _pD3D12Device->QueryInterface( IID_PPV_ARGS( &pInfoQueue ) ) ) )
	{
		pInfoQueue->SetBreakOnSeverity( D3D12_MESSAGE_SEVERITY_CORRUPTION, TRUE );
		pInfoQueue->SetBreakOnSeverity( D3D12_MESSAGE_SEVERITY_ERROR, TRUE );
		pInfoQueue->SetBreakOnSeverity( D3D12_MESSAGE_SEVERITY_WARNING, TRUE );
	}

	int n = 0;
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
