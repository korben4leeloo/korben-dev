﻿//*****************************************************************************
//
//	File:		TkOpenGLApi.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "TkOpenGLApi.h"

#include <Windows.h>
#include <gl/GL.h>
#include <GLext.h>
#include <wglext.h>

#include TARS_CORE_H(Rendering/OpenGL/TkOpenGLContext)
#include TARS_CORE_H(Rendering/Window/TkWindow)

#define TARS_OPEN_GL_FUNC_NULL( PFNOPENGLPROC, funcName ) PFNOPENGLPROC funcName = nullptr;

#define TARS_OPEN_GL_FUNC_PROC( PFNOPENGLPROC, funcName )		\
	funcName = (PFNOPENGLPROC)wglGetProcAddress( #funcName );	\
	TARS_ASSERT( funcName );									\
	if ( funcName == nullptr ) return;

TARS_OPEN_GL_FUNC_NULL( PFNGLGETSTRINGIPROC, glGetStringi )
TARS_OPEN_GL_FUNC_NULL( PFNGLGENVERTEXARRAYSPROC, glGenVertexArrays )
TARS_OPEN_GL_FUNC_NULL( PFNGLBINDVERTEXARRAYPROC, glBindVertexArray )
TARS_OPEN_GL_FUNC_NULL( PFNGLVERTEXATTRIBPOINTERPROC, glVertexAttribPointer )
TARS_OPEN_GL_FUNC_NULL( PFNGLENABLEVERTEXATTRIBARRAYPROC, glEnableVertexAttribArray )
TARS_OPEN_GL_FUNC_NULL( PFNGLDISABLEVERTEXATTRIBARRAYPROC, glDisableVertexAttribArray )
TARS_OPEN_GL_FUNC_NULL( PFNGLGENBUFFERSPROC, glGenBuffers )
TARS_OPEN_GL_FUNC_NULL( PFNGLBINDBUFFERPROC, glBindBuffer )
TARS_OPEN_GL_FUNC_NULL( PFNGLBUFFERDATAPROC, glBufferData )
TARS_OPEN_GL_FUNC_NULL( PFNGLCREATESHADERPROC, glCreateShader )
TARS_OPEN_GL_FUNC_NULL( PFNGLSHADERSOURCEPROC, glShaderSource )
TARS_OPEN_GL_FUNC_NULL( PFNGLCOMPILESHADERPROC, glCompileShader )
TARS_OPEN_GL_FUNC_NULL( PFNGLGETSHADERIVPROC, glGetShaderiv )
TARS_OPEN_GL_FUNC_NULL( PFNGLGETSHADERINFOLOGPROC, glGetShaderInfoLog )
TARS_OPEN_GL_FUNC_NULL( PFNGLCREATEPROGRAMPROC, glCreateProgram )
TARS_OPEN_GL_FUNC_NULL( PFNGLATTACHSHADERPROC, glAttachShader )
TARS_OPEN_GL_FUNC_NULL( PFNGLLINKPROGRAMPROC, glLinkProgram )
TARS_OPEN_GL_FUNC_NULL( PFNGLGETPROGRAMIVPROC, glGetProgramiv )
TARS_OPEN_GL_FUNC_NULL( PFNGLGETPROGRAMINFOLOGPROC, glGetProgramInfoLog )
TARS_OPEN_GL_FUNC_NULL( PFNGLUSEPROGRAMPROC, glUseProgram )
TARS_OPEN_GL_FUNC_NULL( PFNGLGETATTRIBLOCATIONPROC, glGetAttribLocation )
TARS_OPEN_GL_FUNC_NULL( PFNWGLCREATECONTEXTATTRIBSARBPROC, wglCreateContextAttribsARB )
TARS_OPEN_GL_FUNC_NULL( PFNWGLCHOOSEPIXELFORMATARBPROC, wglChoosePixelFormatARB )
TARS_OPEN_GL_FUNC_NULL( PFNWGLGETEXTENSIONSSTRINGARBPROC, wglGetExtensionsStringARB );

bool TkOpenGLApi::_bApiLoaded = false;

//-----------------------------------------------------------------------------
// Name:		init
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void TkOpenGLApi::init()
{
	if	( _bApiLoaded )
	{
		return;
	}

	TARS_OPEN_GL_FUNC_PROC( PFNGLGETSTRINGIPROC, glGetStringi )
	TARS_OPEN_GL_FUNC_PROC( PFNGLGENVERTEXARRAYSPROC, glGenVertexArrays )
	TARS_OPEN_GL_FUNC_PROC( PFNGLBINDVERTEXARRAYPROC, glBindVertexArray )
	TARS_OPEN_GL_FUNC_PROC( PFNGLVERTEXATTRIBPOINTERPROC, glVertexAttribPointer )
	TARS_OPEN_GL_FUNC_PROC( PFNGLENABLEVERTEXATTRIBARRAYPROC, glEnableVertexAttribArray )
	TARS_OPEN_GL_FUNC_PROC( PFNGLDISABLEVERTEXATTRIBARRAYPROC, glDisableVertexAttribArray )
	TARS_OPEN_GL_FUNC_PROC( PFNGLGENBUFFERSPROC, glGenBuffers )
	TARS_OPEN_GL_FUNC_PROC( PFNGLBINDBUFFERPROC, glBindBuffer )
	TARS_OPEN_GL_FUNC_PROC( PFNGLBUFFERDATAPROC, glBufferData )
	TARS_OPEN_GL_FUNC_PROC( PFNGLCREATESHADERPROC, glCreateShader )
	TARS_OPEN_GL_FUNC_PROC( PFNGLSHADERSOURCEPROC, glShaderSource )
	TARS_OPEN_GL_FUNC_PROC( PFNGLCOMPILESHADERPROC, glCompileShader )
	TARS_OPEN_GL_FUNC_PROC( PFNGLGETSHADERIVPROC, glGetShaderiv )
	TARS_OPEN_GL_FUNC_PROC( PFNGLGETSHADERINFOLOGPROC, glGetShaderInfoLog )
	TARS_OPEN_GL_FUNC_PROC( PFNGLCREATEPROGRAMPROC, glCreateProgram )
	TARS_OPEN_GL_FUNC_PROC( PFNGLATTACHSHADERPROC, glAttachShader )
	TARS_OPEN_GL_FUNC_PROC( PFNGLLINKPROGRAMPROC, glLinkProgram )
	TARS_OPEN_GL_FUNC_PROC( PFNGLGETPROGRAMIVPROC, glGetProgramiv )
	TARS_OPEN_GL_FUNC_PROC( PFNGLGETPROGRAMINFOLOGPROC, glGetProgramInfoLog )
	TARS_OPEN_GL_FUNC_PROC( PFNGLUSEPROGRAMPROC, glUseProgram )
	TARS_OPEN_GL_FUNC_PROC( PFNGLGETATTRIBLOCATIONPROC, glGetAttribLocation )
	TARS_OPEN_GL_FUNC_PROC( PFNWGLCREATECONTEXTATTRIBSARBPROC, wglCreateContextAttribsARB )
	TARS_OPEN_GL_FUNC_PROC( PFNWGLCHOOSEPIXELFORMATARBPROC, wglChoosePixelFormatARB )
	TARS_OPEN_GL_FUNC_PROC( PFNWGLGETEXTENSIONSSTRINGARBPROC, wglGetExtensionsStringARB );

	_bApiLoaded = true;
}