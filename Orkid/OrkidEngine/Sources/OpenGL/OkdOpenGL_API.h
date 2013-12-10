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

//#include	"D:/DevJJA/SVN/korben-dev/Libraries/OpenGL/glew/include/GL/glew.h"
//#include	"D:/DevJJA/SVN/korben-dev/Libraries/OpenGL/glew/include/GL/wglew.h"

//#define GL_GLEXT_PROTOTYPES
//#define WGL_WGLEXT_PROTOTYPES

#include	<GL/GL.h>
//#include	<glcorearb.h>
#include	<glext.h>
#include	<wglext.h>
//
//// Declare extern OpenGL functions
//extern PFNGLGETERRORPROC					glGetError;
//extern PFNGLCLEARPROC						glClear;
//extern PFNGLCLEARCOLORPROC					glClearColor;
//extern PFNGLVIEWPORTPROC					glViewport;
//extern PFNGLGETINTEGERVPROC					glGetIntegerv;
extern PFNGLGETSTRINGIPROC					glGetStringi;
extern PFNGLVERTEXATTRIBPOINTERPROC			glVertexAttribPointer;
extern PFNGLENABLEVERTEXATTRIBARRAYPROC		glEnableVertexAttribArray;
extern PFNGLDISABLEVERTEXATTRIBARRAYPROC	glDisableVertexAttribArray;
//extern PFNGLDRAWARRAYSPROC					glDrawArrays;
extern PFNGLGENBUFFERSPROC					glGenBuffers;
extern PFNGLBINDBUFFERPROC					glBindBuffer;
extern PFNGLBUFFERDATAPROC					glBufferData;
//
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