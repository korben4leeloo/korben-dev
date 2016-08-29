//*****************************************************************************
//
//	Class:		TkOpenGLInterface
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_CORE_TK_WGL_INTERFACE_H__
#define __TARS_CORE_TK_WGL_INTERFACE_H__

#include "Root.h"

class TkOpenGLContext;
class TkWindow;

class TkOpenGLInterface
{
public:
	// OpenGL API
	static void				initApi();
	//static void				checkExtensions( const TkOpenGLContext* pContext );
	static void				getOpenGLVersion( int32& nMajorVersion, int32& nMinorVersion );

	// OpenGL contexts
	//static TkOpenGLContext*	createContext( TkWindow* pWindow );

private:
							TkOpenGLInterface();
							~TkOpenGLInterface();

	static bool				_bApiLoaded;
};

#endif