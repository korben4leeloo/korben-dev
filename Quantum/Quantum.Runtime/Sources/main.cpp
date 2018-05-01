//*****************************************************************************
//
//	File:		main.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "Root.h"

#include <Windows.h>

#include QUANTUM_CORE_H(Application/QmApplication)
#include QUANTUM_CORE_H(Rendering/Window/QmWindow)
#include QUANTUM_CORE_H(Rendering/D3D/QmD3DContext)
//#include QUANTUM_CORE_H(Rendering/OpenGL/QmOpenGLContext)
//#include QUANTUM_CORE_H(Rendering/OpenGL/QmOpenGLApi)

//#include <d3d11.h>
//
//IDXGISwapChain* SwapChain;
//ID3D11Device* d3d11Device;
//ID3D11DeviceContext* d3d11DevCon;
//ID3D11RenderTargetView* renderTargetView;
//
//float red = 0.0f;
//float green = 0.0f;
//float blue = 0.0f;
//int colormodr = 1;
//int colormodg = 1;
//int colormodb = 1;

//void RenderScene()
//{
//	//Update the colors of our scene
//    red += colormodr * 0.00005f;
//    green += colormodg * 0.00002f;
//    blue += colormodb * 0.00001f;
//
//    if(red >= 1.0f || red <= 0.0f)
//        colormodr *= -1;
//    if(green >= 1.0f || green <= 0.0f)
//        colormodg *= -1;
//    if(blue >= 1.0f || blue <= 0.0f)
//        colormodb *= -1;
//
//    //Clear our backbuffer to the updated color
//	const float bgColor[4] = { red, green, blue, 1.0f };
//
//    d3d11DevCon->ClearRenderTargetView(renderTargetView, bgColor);
//
//    //Present the backbuffer to the screen
//    SwapChain->Present(0, 0);
//}

//-----------------------------------------------------------------------------
// Name:		WinMain
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
int WinMain( __in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in_opt LPSTR lpCmdLine, __in int nShowCmd )
{
	// Create the application instance and init it
	QmApplication* pApplication = new QmApplication( hInstance );
	pApplication->init();
	
	// Create a window with an OpenGL context
	QmWindow*			pWindow			= pApplication->createWindow();
	//QmOpenGLContext*	pOpenGLContext	= pWindow->createOpenGLContext();
	QmD3DContext*		pD3DContext		= pApplication->createD3DContext( pWindow );

	//d3dContext.cr

	/*IDXGISwapChain* SwapChain;
	ID3D11Device* d3d11Device;
	ID3D11DeviceContext* d3d11DevCon;
	ID3D11RenderTargetView* renderTargetView;

	float red = 0.0f;
	float green = 0.0f;
	float blue = 0.0f;
	int colormodr = 1;
	int colormodg = 1;
	int colormodb = 1;*/

	{
		////Describe our Buffer
		//DXGI_MODE_DESC bufferDesc;

		//ZeroMemory(&bufferDesc, sizeof(DXGI_MODE_DESC));

		//RECT wndRect;
		//GetWindowRect( pWindow->getWindowHandle(), &wndRect );

		//bufferDesc.Width = wndRect.right - wndRect.left;
		//bufferDesc.Height = wndRect.bottom - wndRect.top;
		//bufferDesc.RefreshRate.Numerator = 60;
		//bufferDesc.RefreshRate.Denominator = 1;
		//bufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		//bufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		//bufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
  //  
		////Describe our SwapChain
		//DXGI_SWAP_CHAIN_DESC swapChainDesc; 
  //      
		//ZeroMemory(&swapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));

		//swapChainDesc.BufferDesc = bufferDesc;
		//swapChainDesc.SampleDesc.Count = 1;
		//swapChainDesc.SampleDesc.Quality = 0;
		//swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		//swapChainDesc.BufferCount = 1;
		//swapChainDesc.OutputWindow = pWindow->getWindowHandle(); 
		//swapChainDesc.Windowed = TRUE; 
		//swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;


		////Create our SwapChain
		//D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, NULL, NULL, NULL,
		//	D3D11_SDK_VERSION, &swapChainDesc, &SwapChain, &d3d11Device, NULL, &d3d11DevCon);

		////Create our BackBuffer
		//ID3D11Texture2D* BackBuffer;
		//SwapChain->GetBuffer( 0, __uuidof( ID3D11Texture2D ), (void**)&BackBuffer );

		////Create our Render Target
		//d3d11Device->CreateRenderTargetView( BackBuffer, NULL, &renderTargetView );
		//BackBuffer->Release();

		////Set our Render Target
		//d3d11DevCon->OMSetRenderTargets( 1, &renderTargetView, NULL );

		pApplication->getTaskScheduler()->createTask( 0, RenderScene );
	}

	// Run the application loop
	pApplication->run();

	delete pApplication;

	return 0;
}
