//*****************************************************************************
//
//	Class:		TkOpenGLApi
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_CORE_TK_OPEN_GL_API_H__
#define __TARS_CORE_TK_OPEN_GL_API_H__

#include "Root.h"

#include <Windows.h>

#include <gl/GL.h>
#include <GLext.h>
#include <wglext.h>

#define TARS_OPEN_GL_FUNC_EXTERN( PFNOPENGLPROC, funcName ) extern PFNOPENGLPROC funcName;

TARS_OPEN_GL_FUNC_EXTERN( PFNGLGETSTRINGIPROC, glGetStringi )
TARS_OPEN_GL_FUNC_EXTERN( PFNGLGENVERTEXARRAYSPROC, glGenVertexArrays )
TARS_OPEN_GL_FUNC_EXTERN( PFNGLBINDVERTEXARRAYPROC, glBindVertexArray )
TARS_OPEN_GL_FUNC_EXTERN( PFNGLVERTEXATTRIBPOINTERPROC, glVertexAttribPointer )
TARS_OPEN_GL_FUNC_EXTERN( PFNGLENABLEVERTEXATTRIBARRAYPROC, glEnableVertexAttribArray )
TARS_OPEN_GL_FUNC_EXTERN( PFNGLDISABLEVERTEXATTRIBARRAYPROC, glDisableVertexAttribArray )
TARS_OPEN_GL_FUNC_EXTERN( PFNGLGENBUFFERSPROC, glGenBuffers )
TARS_OPEN_GL_FUNC_EXTERN( PFNGLBINDBUFFERPROC, glBindBuffer )
TARS_OPEN_GL_FUNC_EXTERN( PFNGLBUFFERDATAPROC, glBufferData )
TARS_OPEN_GL_FUNC_EXTERN( PFNGLCREATESHADERPROC, glCreateShader )
TARS_OPEN_GL_FUNC_EXTERN( PFNGLSHADERSOURCEPROC, glShaderSource )
TARS_OPEN_GL_FUNC_EXTERN( PFNGLCOMPILESHADERPROC, glCompileShader )
TARS_OPEN_GL_FUNC_EXTERN( PFNGLGETSHADERIVPROC, glGetShaderiv )
TARS_OPEN_GL_FUNC_EXTERN( PFNGLGETSHADERINFOLOGPROC, glGetShaderInfoLog )
TARS_OPEN_GL_FUNC_EXTERN( PFNGLCREATEPROGRAMPROC, glCreateProgram )
TARS_OPEN_GL_FUNC_EXTERN( PFNGLATTACHSHADERPROC, glAttachShader )
TARS_OPEN_GL_FUNC_EXTERN( PFNGLLINKPROGRAMPROC, glLinkProgram )
TARS_OPEN_GL_FUNC_EXTERN( PFNGLGETPROGRAMIVPROC, glGetProgramiv )
TARS_OPEN_GL_FUNC_EXTERN( PFNGLGETPROGRAMINFOLOGPROC, glGetProgramInfoLog )
TARS_OPEN_GL_FUNC_EXTERN( PFNGLUSEPROGRAMPROC, glUseProgram )
TARS_OPEN_GL_FUNC_EXTERN( PFNGLGETATTRIBLOCATIONPROC, glGetAttribLocation )
TARS_OPEN_GL_FUNC_EXTERN( PFNWGLCREATECONTEXTATTRIBSARBPROC, wglCreateContextAttribsARB )
TARS_OPEN_GL_FUNC_EXTERN( PFNWGLCHOOSEPIXELFORMATARBPROC, wglChoosePixelFormatARB )
TARS_OPEN_GL_FUNC_EXTERN( PFNWGLGETEXTENSIONSSTRINGARBPROC, wglGetExtensionsStringARB );

class TkOpenGLContext;

class TkOpenGLApi
{
public:
	static void	init();

private:
				TkOpenGLApi();
				~TkOpenGLApi();

	static bool	_bApiLoaded;
};

#endif