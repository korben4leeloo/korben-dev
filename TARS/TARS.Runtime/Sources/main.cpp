//*****************************************************************************
//
//	File:		main.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "Root.h"

#include <Windows.h>

#include TARS_CORE_H(Application/TkApplication)
#include TARS_CORE_H(Rendering/Window/TkWindow)
#include TARS_CORE_H(Rendering/OpenGL/TkOpenGLContext)
#include TARS_CORE_H(Rendering/OpenGL/TkOpenGLApi)

//-----------------------------------------------------------------------------
// Name:		WinMain
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
int WinMain( __in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in_opt LPSTR lpCmdLine, __in int nShowCmd )
{
	// Create the application instance and init it
	TkApplication* pApplication = new TkApplication( hInstance );
	pApplication->init();
	
	// Create a window with an OpenGL context
	TkWindow*			pWindow			= pApplication->createWindow();
	TkOpenGLContext*	pOpenGLContext	= pWindow->createOpenGLContext();

	// Run the application loop
	pApplication->run();

	delete pApplication;

	return 0;
}
