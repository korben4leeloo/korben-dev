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

#include	<GL/GL.h>
#include	<wglext.h>

// Declare extern OpenGL functions
extern PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB;

class OkdOpenGL_API
{
public:
	static void	initialize();

private:
				OkdOpenGL_API();
				~OkdOpenGL_API();

	static bool	_bIsInitialized;
};

#endif