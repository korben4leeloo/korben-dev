//*****************************************************************************
//
//	File:		OkdOpenGL_API.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdOpenGL_API.h"

#define	OKD_OPENGL_API_GET_FUNC( FuncPtr, FuncName ) FuncName = (FuncPtr)wglGetProcAddress( #FuncName )

PFNGLCLEARPROC						glClear						= 0;
PFNGLCLEARCOLORPROC					glClearColor				= 0;
PFNGLVIEWPORTPROC					glViewport					= 0;
PFNGLGETINTEGERVPROC				glGetIntegerv				= 0;
PFNGLGETSTRINGIPROC					glGetStringi				= 0;

PFNWGLCREATECONTEXTATTRIBSARBPROC	wglCreateContextAttribsARB	= 0;
PFNWGLCHOOSEPIXELFORMATARBPROC		wglChoosePixelFormatARB		= 0;

bool OkdOpenGL_API::_bIsInitialized = false;

//-----------------------------------------------------------------------------
// Name:		OkdOpenGL_API constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdOpenGL_API::OkdOpenGL_API()
{

}

//-----------------------------------------------------------------------------
// Name:		OkdOpenGL_API destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdOpenGL_API::~OkdOpenGL_API()
{

}

//-----------------------------------------------------------------------------
// Name:		initialize
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdOpenGL_API::initialize()
{
	if	( _bIsInitialized )
	{
		return;
	}

	OKD_OPENGL_API_GET_FUNC( PFNGLCLEARPROC, glClear );
	OKD_OPENGL_API_GET_FUNC( PFNGLCLEARCOLORPROC, glClearColor );
	OKD_OPENGL_API_GET_FUNC( PFNGLVIEWPORTPROC, glViewport );
	OKD_OPENGL_API_GET_FUNC( PFNGLGETINTEGERVPROC, glGetIntegerv );
	OKD_OPENGL_API_GET_FUNC( PFNGLGETSTRINGIPROC, glGetStringi );

	GLint nExtensionCount;
	
	glGetIntegerv( GL_NUM_EXTENSIONS, &nExtensionCount );

	for	( int i = 0; i < nExtensionCount; i++ )
	{
		const GLubyte* pExtensionName = glGetStringi( GL_EXTENSIONS, i );
		OutputDebugString( (LPCSTR)pExtensionName );
		OutputDebugString( "\n" );
	}

	OKD_OPENGL_API_GET_FUNC( PFNWGLCREATECONTEXTATTRIBSARBPROC, wglCreateContextAttribsARB );
	OKD_OPENGL_API_GET_FUNC( PFNWGLCHOOSEPIXELFORMATARBPROC, wglChoosePixelFormatARB );

	_bIsInitialized = true;
}
