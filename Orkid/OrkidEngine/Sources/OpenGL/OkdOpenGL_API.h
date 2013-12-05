//*****************************************************************************
//
//	Class:		OkdOpenGL_API
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdOpenGL_API_h__
#define __OrkidEngine_OkdOpenGL_API_h__

#include	"Root.h"

#ifdef _WIN32
	#include	<Windows.h>
#endif

//#include	<GL/GL.h>
#include	<glcorearb.h>
#include	<wglext.h>

// Declare extern OpenGL functions
extern PFNGLCLEARPROC						glClear;
extern PFNGLCLEARCOLORPROC					glClearColor;
extern PFNGLVIEWPORTPROC					glViewport;
extern PFNGLGETINTEGERVPROC					glGetIntegerv;
extern PFNGLGETSTRINGIPROC					glGetStringi;

extern PFNWGLCREATECONTEXTATTRIBSARBPROC	wglCreateContextAttribsARB;
extern PFNWGLCHOOSEPIXELFORMATARBPROC		wglChoosePixelFormatARB;

class OkdOpenGL_API
{
public:
	static OrkidErrorCode	initialize( const HDC hDeviceContext, const PIXELFORMATDESCRIPTOR* pPixelformatDesc );

private:
							OkdOpenGL_API();
							~OkdOpenGL_API();

	static bool				_bIsInitialized;
};

#endif