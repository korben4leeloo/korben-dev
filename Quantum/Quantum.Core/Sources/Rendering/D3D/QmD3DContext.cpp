//*****************************************************************************
//
//	File:		QmD3DContext.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "QmD3DContext.h"

#include <d3d11.h>

#include QUANTUM_CORE_H(Rendering/Window/QmWindow)
//#include QUANTUM_CORE_H(Rendering/OpenGL/QmOpenGLExtensions)
//#include QUANTUM_CORE_H(Rendering/OpenGL/QmOpenGLApi)

//#define OPEN_GL_MAJOR_VERSION_REQUIRED	4
//#define OPEN_GL_MINOR_VERSION_REQUIRED	0
//
//#define COLOR_BITS_COUNT				32
//#define DEPTH_BITS_COUNT				24
//#define STENCIL_BITS_COUNT				8

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
: _pSwapChain			( nullptr )
, _pD3D11Device			( nullptr )
, _pD3D11DeviceContext	( nullptr )
, _pRenderTargetView	( nullptr )
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
	//Describe our Buffer
	DXGI_MODE_DESC bufferDesc;

	ZeroMemory(&bufferDesc, sizeof(DXGI_MODE_DESC));

	RECT wndRect;
	GetWindowRect( pWindow->getWindowHandle(), &wndRect );

	bufferDesc.Width					= wndRect.right - wndRect.left;
	bufferDesc.Height					= wndRect.bottom - wndRect.top;
	bufferDesc.RefreshRate.Numerator	= 60;
	bufferDesc.RefreshRate.Denominator	= 1;
	bufferDesc.Format					= DXGI_FORMAT_R8G8B8A8_UNORM;
	bufferDesc.ScanlineOrdering			= DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	bufferDesc.Scaling					= DXGI_MODE_SCALING_UNSPECIFIED;
    
	//Describe our SwapChain
	DXGI_SWAP_CHAIN_DESC swapChainDesc; 
    
	ZeroMemory(&swapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));

	swapChainDesc.BufferDesc			= bufferDesc;
	swapChainDesc.SampleDesc.Count		= 1;
	swapChainDesc.SampleDesc.Quality	= 0;
	swapChainDesc.BufferUsage			= DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.BufferCount			= 1;
	swapChainDesc.OutputWindow			= pWindow->getWindowHandle(); 
	swapChainDesc.Windowed				= TRUE; 
	swapChainDesc.SwapEffect			= DXGI_SWAP_EFFECT_DISCARD;

	//Create our SwapChain
	D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, NULL, NULL, NULL,
		D3D11_SDK_VERSION, &swapChainDesc, &_pSwapChain, &_pD3D11Device, NULL, &_pD3D11DeviceContext);

	//Create our BackBuffer
	ID3D11Texture2D* BackBuffer;
	_pSwapChain->GetBuffer( 0, __uuidof( ID3D11Texture2D ), (void**)&BackBuffer );

	//Create our Render Target
	_pD3D11Device->CreateRenderTargetView( BackBuffer, NULL, &_pRenderTargetView );
	BackBuffer->Release();

	//Set our Render Target
	_pD3D11DeviceContext->OMSetRenderTargets( 1, &_pRenderTargetView, NULL );
}

//-----------------------------------------------------------------------------
// Name:		destroy
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void QmD3DContext::destroy()
{
	RELEASE_D3D_INTERFACE( _pSwapChain )
	RELEASE_D3D_INTERFACE( _pD3D11Device );
	RELEASE_D3D_INTERFACE( _pD3D11DeviceContext );
}
