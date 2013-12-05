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
OrkidErrorCode	OkdOpenGL_API::initialize(const HDC						hDeviceContext, 
										  const PIXELFORMATDESCRIPTOR *	pPixelformatDesc)
{
	if	( _bIsInitialized )
	{
		return	( OKD_OK );
	}

	// Ask for a matching pixel format descriptor and use it
	int nPixelFormat = ChoosePixelFormat( hDeviceContext, pPixelformatDesc );

	if	( nPixelFormat == 0 )
	{
		return	( OKD_FAIL );
	}

	BOOL result = SetPixelFormat( hDeviceContext, nPixelFormat, pPixelformatDesc );

	if	( !result )
	{
		return	( OKD_FAIL );
	}

	HGLRC hDummyGLContext = wglCreateContext( hDeviceContext ); // Create an OpenGL 2.1 context for our device context
	wglMakeCurrent( hDeviceContext, hDummyGLContext ); // Make the OpenGL 2.1 context current and active

	// Get function pointers
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

	OKD_OPENGL_API_GET_FUNC( PFNGLCLEARPROC, glClear );
	OKD_OPENGL_API_GET_FUNC( PFNGLCLEARCOLORPROC, glClearColor );
	OKD_OPENGL_API_GET_FUNC( PFNGLVIEWPORTPROC, glViewport );

	OKD_OPENGL_API_GET_FUNC( PFNWGLCREATECONTEXTATTRIBSARBPROC, wglCreateContextAttribsARB );
	OKD_OPENGL_API_GET_FUNC( PFNWGLCHOOSEPIXELFORMATARBPROC, wglChoosePixelFormatARB );

	// Destroy dummy context
	wglMakeCurrent( 0, 0 );
	wglDeleteContext( hDummyGLContext );

	_bIsInitialized = true;

	return	( OKD_OK );
}
