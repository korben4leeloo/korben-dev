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

#define	OKD_OPENGL_API_DECLARE_FUNC( FuncPtr, FuncName ) extern FuncPtr FuncName;

// Declare extern OpenGL functions
OKD_OPENGL_API_DECLARE_FUNC( PFNGLGETSTRINGIPROC, glGetStringi )
OKD_OPENGL_API_DECLARE_FUNC( PFNGLGENVERTEXARRAYSPROC, glGenVertexArrays )
OKD_OPENGL_API_DECLARE_FUNC( PFNGLBINDVERTEXARRAYPROC, glBindVertexArray )
OKD_OPENGL_API_DECLARE_FUNC( PFNGLVERTEXATTRIBPOINTERPROC, glVertexAttribPointer )
OKD_OPENGL_API_DECLARE_FUNC( PFNGLENABLEVERTEXATTRIBARRAYPROC, glEnableVertexAttribArray )
OKD_OPENGL_API_DECLARE_FUNC( PFNGLDISABLEVERTEXATTRIBARRAYPROC, glDisableVertexAttribArray )
OKD_OPENGL_API_DECLARE_FUNC( PFNGLGENBUFFERSPROC, glGenBuffers )
OKD_OPENGL_API_DECLARE_FUNC( PFNGLBINDBUFFERPROC, glBindBuffer )
OKD_OPENGL_API_DECLARE_FUNC( PFNGLBUFFERDATAPROC, glBufferData )

OKD_OPENGL_API_DECLARE_FUNC( PFNGLCREATESHADERPROC, glCreateShader )
OKD_OPENGL_API_DECLARE_FUNC( PFNGLSHADERSOURCEPROC, glShaderSource )
OKD_OPENGL_API_DECLARE_FUNC( PFNGLCOMPILESHADERPROC, glCompileShader )
OKD_OPENGL_API_DECLARE_FUNC( PFNGLGETSHADERIVPROC, glGetShaderiv )
OKD_OPENGL_API_DECLARE_FUNC( PFNGLGETSHADERINFOLOGPROC, glGetShaderInfoLog )
OKD_OPENGL_API_DECLARE_FUNC( PFNGLCREATEPROGRAMPROC, glCreateProgram )
OKD_OPENGL_API_DECLARE_FUNC( PFNGLATTACHSHADERPROC, glAttachShader )
OKD_OPENGL_API_DECLARE_FUNC( PFNGLLINKPROGRAMPROC, glLinkProgram )
OKD_OPENGL_API_DECLARE_FUNC( PFNGLGETPROGRAMIVPROC, glGetProgramiv )
OKD_OPENGL_API_DECLARE_FUNC( PFNGLGETPROGRAMINFOLOGPROC, glGetProgramInfoLog )
OKD_OPENGL_API_DECLARE_FUNC( PFNGLUSEPROGRAMPROC, glUseProgram )
OKD_OPENGL_API_DECLARE_FUNC( PFNGLGETATTRIBLOCATIONPROC, glGetAttribLocation )

OKD_OPENGL_API_DECLARE_FUNC( PFNWGLCREATECONTEXTATTRIBSARBPROC, wglCreateContextAttribsARB )
OKD_OPENGL_API_DECLARE_FUNC( PFNWGLCHOOSEPIXELFORMATARBPROC, wglChoosePixelFormatARB )

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