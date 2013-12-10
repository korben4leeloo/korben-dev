//*****************************************************************************
//
//	File:		OkdOpenGL_API.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdOpenGL_API.h"

#pragma comment(lib, "C:/Users/jja/Downloads/glew-1.10.0/glew-1.10.0/lib/Debug/Win32/glew32d.lib")

#define	OKD_OPENGL_API_GET_FUNC( FuncPtr, FuncName )	\
	FuncName = (FuncPtr)wglGetProcAddress( #FuncName );	\
	ORKID_ASSERT( FuncName );

//PFNGLGETERRORPROC					glGetError					= 0;
//PFNGLCLEARPROC						glClear						= 0;
//PFNGLCLEARCOLORPROC					glClearColor				= 0;
//PFNGLVIEWPORTPROC					glViewport					= 0;
//PFNGLGETINTEGERVPROC				glGetIntegerv				= 0;
PFNGLGETSTRINGIPROC					glGetStringi				= 0;
PFNGLVERTEXATTRIBPOINTERPROC		glVertexAttribPointer		= 0;
PFNGLENABLEVERTEXATTRIBARRAYPROC	glEnableVertexAttribArray	= 0;
PFNGLDISABLEVERTEXATTRIBARRAYPROC	glDisableVertexAttribArray	= 0;
//PFNGLDRAWARRAYSPROC					glDrawArrays				= 0;
PFNGLGENBUFFERSPROC					glGenBuffers				= 0;
PFNGLBINDBUFFERPROC					glBindBuffer				= 0;
PFNGLBUFFERDATAPROC					glBufferData				= 0;
//
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

	//glGetError = (PFNGLGETERRORPROC)wglGetProcAddress( "glGetError" );
	//DWORD dw = GetLastError();

	//// Get function pointers
	//OKD_OPENGL_API_GET_FUNC( PFNGLGETERRORPROC, glGetError )
	//OKD_OPENGL_API_GET_FUNC( PFNGLGETINTEGERVPROC, glGetIntegerv )
	OKD_OPENGL_API_GET_FUNC( PFNGLGETSTRINGIPROC, glGetStringi )

	GLint nExtensionCount;
	
	glGetIntegerv( GL_NUM_EXTENSIONS, &nExtensionCount );

	for	( int i = 0; i < nExtensionCount; i++ )
	{
		const GLubyte* pExtensionName = glGetStringi( GL_EXTENSIONS, i );
		OutputDebugString( (LPCSTR)pExtensionName );
		OutputDebugString( "\n" );
	}

	//OKD_OPENGL_API_GET_FUNC( PFNGLCLEARPROC, glClear )
	//OKD_OPENGL_API_GET_FUNC( PFNGLCLEARCOLORPROC, glClearColor )
	//OKD_OPENGL_API_GET_FUNC( PFNGLVIEWPORTPROC, glViewport )
	OKD_OPENGL_API_GET_FUNC( PFNGLVERTEXATTRIBPOINTERPROC, glVertexAttribPointer )
		OKD_OPENGL_API_GET_FUNC( PFNGLENABLEVERTEXATTRIBARRAYPROC, glEnableVertexAttribArray )
		OKD_OPENGL_API_GET_FUNC( PFNGLDISABLEVERTEXATTRIBARRAYPROC, glDisableVertexAttribArray )
	//OKD_OPENGL_API_GET_FUNC( PFNGLDRAWARRAYSPROC, glDrawArrays )
	OKD_OPENGL_API_GET_FUNC( PFNGLGENBUFFERSPROC, glGenBuffers )
	OKD_OPENGL_API_GET_FUNC( PFNGLBINDBUFFERPROC, glBindBuffer );
	OKD_OPENGL_API_GET_FUNC( PFNGLBUFFERDATAPROC, glBufferData );

	OKD_OPENGL_API_GET_FUNC( PFNWGLCREATECONTEXTATTRIBSARBPROC, wglCreateContextAttribsARB )
	OKD_OPENGL_API_GET_FUNC( PFNWGLCHOOSEPIXELFORMATARBPROC, wglChoosePixelFormatARB )

	//glewInit();

	// Destroy dummy context
	wglMakeCurrent( 0, 0 );
	wglDeleteContext( hDummyGLContext );

	_bIsInitialized = true;

	return	( OKD_OK );
}
