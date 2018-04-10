//*****************************************************************************
//
//	Class:		QmOpenGLApi
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __QUANTUM_CORE_TK_OPEN_GL_API_H__
#define __QUANTUM_CORE_TK_OPEN_GL_API_H__

#include "Root.h"

#include <Windows.h>

#include <gl/GL.h>
#include <GLext.h>
#include <wglext.h>

#define QUANTUM_OPEN_GL_FUNC_EXTERN( PFNOPENGLPROC, funcName ) extern PFNOPENGLPROC funcName;

QUANTUM_OPEN_GL_FUNC_EXTERN( PFNGLGETSTRINGIPROC, glGetStringi )
QUANTUM_OPEN_GL_FUNC_EXTERN( PFNGLGENVERTEXARRAYSPROC, glGenVertexArrays )
QUANTUM_OPEN_GL_FUNC_EXTERN( PFNGLBINDVERTEXARRAYPROC, glBindVertexArray )
QUANTUM_OPEN_GL_FUNC_EXTERN( PFNGLVERTEXATTRIBPOINTERPROC, glVertexAttribPointer )
QUANTUM_OPEN_GL_FUNC_EXTERN( PFNGLENABLEVERTEXATTRIBARRAYPROC, glEnableVertexAttribArray )
QUANTUM_OPEN_GL_FUNC_EXTERN( PFNGLDISABLEVERTEXATTRIBARRAYPROC, glDisableVertexAttribArray )
QUANTUM_OPEN_GL_FUNC_EXTERN( PFNGLGENBUFFERSPROC, glGenBuffers )
QUANTUM_OPEN_GL_FUNC_EXTERN( PFNGLBINDBUFFERPROC, glBindBuffer )
QUANTUM_OPEN_GL_FUNC_EXTERN( PFNGLBUFFERDATAPROC, glBufferData )
QUANTUM_OPEN_GL_FUNC_EXTERN( PFNGLCREATESHADERPROC, glCreateShader )
QUANTUM_OPEN_GL_FUNC_EXTERN( PFNGLSHADERSOURCEPROC, glShaderSource )
QUANTUM_OPEN_GL_FUNC_EXTERN( PFNGLCOMPILESHADERPROC, glCompileShader )
QUANTUM_OPEN_GL_FUNC_EXTERN( PFNGLGETSHADERIVPROC, glGetShaderiv )
QUANTUM_OPEN_GL_FUNC_EXTERN( PFNGLGETSHADERINFOLOGPROC, glGetShaderInfoLog )
QUANTUM_OPEN_GL_FUNC_EXTERN( PFNGLCREATEPROGRAMPROC, glCreateProgram )
QUANTUM_OPEN_GL_FUNC_EXTERN( PFNGLATTACHSHADERPROC, glAttachShader )
QUANTUM_OPEN_GL_FUNC_EXTERN( PFNGLLINKPROGRAMPROC, glLinkProgram )
QUANTUM_OPEN_GL_FUNC_EXTERN( PFNGLGETPROGRAMIVPROC, glGetProgramiv )
QUANTUM_OPEN_GL_FUNC_EXTERN( PFNGLGETPROGRAMINFOLOGPROC, glGetProgramInfoLog )
QUANTUM_OPEN_GL_FUNC_EXTERN( PFNGLUSEPROGRAMPROC, glUseProgram )
QUANTUM_OPEN_GL_FUNC_EXTERN( PFNGLGETATTRIBLOCATIONPROC, glGetAttribLocation )
QUANTUM_OPEN_GL_FUNC_EXTERN( PFNWGLCREATECONTEXTATTRIBSARBPROC, wglCreateContextAttribsARB )
QUANTUM_OPEN_GL_FUNC_EXTERN( PFNWGLCHOOSEPIXELFORMATARBPROC, wglChoosePixelFormatARB )
QUANTUM_OPEN_GL_FUNC_EXTERN( PFNWGLGETEXTENSIONSSTRINGARBPROC, wglGetExtensionsStringARB );

class QmOpenGLContext;

class QmOpenGLApi
{
public:
	static void	init();

private:
				QmOpenGLApi();
				~QmOpenGLApi();

	static bool	_bApiLoaded;
};

#endif