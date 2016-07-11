//*****************************************************************************
//
//	Class:		TkOpenGLFuncs
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_CORE_TK_OPENGL_FUNCS_H__
#define __TARS_CORE_TK_OPENGL_FUNCS_H__

#include "Root.h"

#include <Windows.h>

#include <gl/GL.h>
#include <GLext.h>
#include <wglext.h>

#ifndef TARS_OPEN_GL_EXTERN
	#ifndef TARS_OPEN_GL_EXTERN_DISABLE
	#define TARS_OPEN_GL_EXTERN
#endif

#define TARS_OPEN_GL_FUNC_DECL( PFNOPENGLPROC, funcName ) extern PFNOPENGLPROC funcName;
#define TARS_OPEN_GL_FUNC_DEF( PFNOPENGLPROC, funcName ) PFNOPENGLPROC funcName = nullptr;
#define TARS_OPEN_GL_FUNC_PROC( PFNOPENGLPROC, funcName ) PFNOPENGLPROC funcName = (PFNOPENGLPROC)wglGetProcAddress( #funcName );

TARS_OPEN_GL_FUNC_DECL( PFNGLGETSTRINGIPROC, glGetStringi )

class TkOpenGLFuncs
{
	friend class TkWglContext;

private:
	static void	load();

	static bool	_bLoaded;
};

#endif