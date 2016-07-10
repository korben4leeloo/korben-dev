//*****************************************************************************
//
//	File:		main.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "Root.h"

#include <Windows.h>

#include TARS_CORE_H(Application/TkWin32App)
#include TARS_CORE_H(OpenGL/TkWglContext)

//-----------------------------------------------------------------------------
// Name:		WinMain
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
int WinMain( __in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in_opt LPSTR lpCmdLine, __in int nShowCmd )
{
	TkWin32App* pWin32App = new TkWin32App( hInstance );

	pWin32App->initInputs();
	
	TkWin32Wnd* pWindow = pWin32App->initWindow();
	TkWglContext* pWglContext = new TkWglContext( pWindow );

	pWglContext->init();

	pWin32App->run();

	delete pWin32App;

	return 0;
}
