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
#include QUANTUM_RUNTIME_H(UnitTest/QmUnitTest)

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
	// Unit tests
	QmUnitTest unitTest;
	unitTest.launch();

	// Create the application instance and init it
	QmApplication* pApplication = new QmApplication( hInstance );
	pApplication->init();
	
	// Create a window with a Direct3D context
	QmWindow*		pWindow		= pApplication->createWindow();
	QmD3DContext*	pD3DContext	= pApplication->createD3DContext( pWindow );

	// Run the application loop
	pApplication->run();

	delete pApplication;

	return 0;
}
