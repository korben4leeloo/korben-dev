//*****************************************************************************
//
//	File:		QmD3DContext.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "QmD3DContext.h"

#include <d3d12.h>
#include <dxgi1_6.h>

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
	// Create factory
	IDXGIFactory4* pDXGIFactory = nullptr;

	HRESULT hr;
	
	hr = CreateDXGIFactory1( IID_PPV_ARGS( &pDXGIFactory ) );

	IDXGIAdapter1* adapter; // adapters are the graphics card (this includes the embedded graphics on the motherboard)

	int adapterIndex = 0; // we'll start looking for directx 12  compatible graphics devices starting at index 0

	bool adapterFound = false; // set this to true when a good one was found

							   // find first hardware gpu that supports d3d 12
	while (pDXGIFactory->EnumAdapters1(adapterIndex, &adapter) != DXGI_ERROR_NOT_FOUND)
	{
		DXGI_ADAPTER_DESC1 desc;
		adapter->GetDesc1(&desc);

		if (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
		{
			// we dont want a software device
			adapterIndex++; // add this line here. Its not currently in the downloadable project
			continue;
		}

		// we want a device that is compatible with direct3d 12 (feature level 11 or higher)
		/*hr = D3D12CreateDevice(adapter, D3D_FEATURE_LEVEL_11_0, _uuidof(ID3D12Device), nullptr);
		if (SUCCEEDED(hr))
		{
			adapterFound = true;
			break;
		}*/

		adapterIndex++;
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
