//*****************************************************************************
//
//	File:		main.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "Root.h"

#include <Windows.h>

#include TARS_CORE_H(Application/TkApplication)
#include TARS_CORE_H(OpenGL/TkOpenGLContext)

//-----------------------------------------------------------------------------
// Name:		WinMain
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
int WinMain( __in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in_opt LPSTR lpCmdLine, __in int nShowCmd )
{
	TkApplication* pApplication = new TkApplication( hInstance );

	pApplication->initInputs();
	
	TkWindow* pWindow = pApplication->initWindow();
	TkOpenGLContext* pOpenGLContext = new TkOpenGLContext( pWindow );

	pOpenGLContext->init();

	pApplication->run();

	delete pApplication;

	return 0;
}
