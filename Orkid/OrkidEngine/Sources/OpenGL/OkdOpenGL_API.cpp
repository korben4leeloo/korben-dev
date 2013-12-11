//*****************************************************************************
//
//	File:		OkdOpenGL_API.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdOpenGL_API.h"

//#pragma comment(lib, "C:/Users/jja/Downloads/glew-1.10.0/glew-1.10.0/lib/Debug/Win32/glew32d.lib")

#define	OKD_OPENGL_API_DEFINE_FUNC( FuncPtr, FuncName ) FuncPtr FuncName = 0;

#define	OKD_OPENGL_API_GET_FUNC( FuncPtr, FuncName )	\
	FuncName = (FuncPtr)wglGetProcAddress( #FuncName );	\
	ORKID_ASSERT( FuncName );

OKD_OPENGL_API_DEFINE_FUNC( PFNGLGETSTRINGIPROC, glGetStringi )
OKD_OPENGL_API_DEFINE_FUNC( PFNGLGENVERTEXARRAYSPROC, glGenVertexArrays )
OKD_OPENGL_API_DEFINE_FUNC( PFNGLBINDVERTEXARRAYPROC, glBindVertexArray )
OKD_OPENGL_API_DEFINE_FUNC( PFNGLVERTEXATTRIBPOINTERPROC, glVertexAttribPointer )
OKD_OPENGL_API_DEFINE_FUNC( PFNGLENABLEVERTEXATTRIBARRAYPROC, glEnableVertexAttribArray )
OKD_OPENGL_API_DEFINE_FUNC( PFNGLDISABLEVERTEXATTRIBARRAYPROC, glDisableVertexAttribArray )
OKD_OPENGL_API_DEFINE_FUNC( PFNGLGENBUFFERSPROC, glGenBuffers )
OKD_OPENGL_API_DEFINE_FUNC( PFNGLBINDBUFFERPROC, glBindBuffer )
OKD_OPENGL_API_DEFINE_FUNC( PFNGLBUFFERDATAPROC, glBufferData )

OKD_OPENGL_API_DEFINE_FUNC( PFNGLCREATESHADERPROC, glCreateShader )
OKD_OPENGL_API_DEFINE_FUNC( PFNGLSHADERSOURCEPROC, glShaderSource )
OKD_OPENGL_API_DEFINE_FUNC( PFNGLCOMPILESHADERPROC, glCompileShader )
OKD_OPENGL_API_DEFINE_FUNC( PFNGLGETSHADERIVPROC, glGetShaderiv )
OKD_OPENGL_API_DEFINE_FUNC( PFNGLGETSHADERINFOLOGPROC, glGetShaderInfoLog )
OKD_OPENGL_API_DEFINE_FUNC( PFNGLCREATEPROGRAMPROC, glCreateProgram )
OKD_OPENGL_API_DEFINE_FUNC( PFNGLATTACHSHADERPROC, glAttachShader )
OKD_OPENGL_API_DEFINE_FUNC( PFNGLLINKPROGRAMPROC, glLinkProgram )
OKD_OPENGL_API_DEFINE_FUNC( PFNGLGETPROGRAMIVPROC, glGetProgramiv )
OKD_OPENGL_API_DEFINE_FUNC( PFNGLGETPROGRAMINFOLOGPROC, glGetProgramInfoLog )
OKD_OPENGL_API_DEFINE_FUNC( PFNGLUSEPROGRAMPROC, glUseProgram )
OKD_OPENGL_API_DEFINE_FUNC( PFNGLGETATTRIBLOCATIONPROC, glGetAttribLocation )

OKD_OPENGL_API_DEFINE_FUNC( PFNWGLCREATECONTEXTATTRIBSARBPROC, wglCreateContextAttribsARB )
OKD_OPENGL_API_DEFINE_FUNC( PFNWGLCHOOSEPIXELFORMATARBPROC, wglChoosePixelFormatARB )

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
	OKD_OPENGL_API_GET_FUNC( PFNGLGETSTRINGIPROC, glGetStringi )
	OKD_OPENGL_API_GET_FUNC( PFNGLGENVERTEXARRAYSPROC, glGenVertexArrays )
	OKD_OPENGL_API_GET_FUNC( PFNGLBINDVERTEXARRAYPROC, glBindVertexArray )
	OKD_OPENGL_API_GET_FUNC( PFNGLVERTEXATTRIBPOINTERPROC, glVertexAttribPointer )
	OKD_OPENGL_API_GET_FUNC( PFNGLENABLEVERTEXATTRIBARRAYPROC, glEnableVertexAttribArray )
	OKD_OPENGL_API_GET_FUNC( PFNGLDISABLEVERTEXATTRIBARRAYPROC, glDisableVertexAttribArray )
	OKD_OPENGL_API_GET_FUNC( PFNGLGENBUFFERSPROC, glGenBuffers )
	OKD_OPENGL_API_GET_FUNC( PFNGLBINDBUFFERPROC, glBindBuffer )
	OKD_OPENGL_API_GET_FUNC( PFNGLBUFFERDATAPROC, glBufferData )

	OKD_OPENGL_API_GET_FUNC( PFNGLCREATESHADERPROC, glCreateShader )
	OKD_OPENGL_API_GET_FUNC( PFNGLSHADERSOURCEPROC, glShaderSource )
	OKD_OPENGL_API_GET_FUNC( PFNGLCOMPILESHADERPROC, glCompileShader )
	OKD_OPENGL_API_GET_FUNC( PFNGLGETSHADERIVPROC, glGetShaderiv )
	OKD_OPENGL_API_GET_FUNC( PFNGLGETSHADERINFOLOGPROC, glGetShaderInfoLog )
	OKD_OPENGL_API_GET_FUNC( PFNGLCREATEPROGRAMPROC, glCreateProgram )
	OKD_OPENGL_API_GET_FUNC( PFNGLATTACHSHADERPROC, glAttachShader )
	OKD_OPENGL_API_GET_FUNC( PFNGLLINKPROGRAMPROC, glLinkProgram )
	OKD_OPENGL_API_GET_FUNC( PFNGLGETPROGRAMIVPROC, glGetProgramiv )
	OKD_OPENGL_API_GET_FUNC( PFNGLGETPROGRAMINFOLOGPROC, glGetProgramInfoLog )
	OKD_OPENGL_API_GET_FUNC( PFNGLUSEPROGRAMPROC, glUseProgram )
	OKD_OPENGL_API_GET_FUNC( PFNGLGETATTRIBLOCATIONPROC, glGetAttribLocation )

	OKD_OPENGL_API_GET_FUNC( PFNWGLCREATECONTEXTATTRIBSARBPROC, wglCreateContextAttribsARB )
	OKD_OPENGL_API_GET_FUNC( PFNWGLCHOOSEPIXELFORMATARBPROC, wglChoosePixelFormatARB )

	GLint nExtensionCount;
	
	glGetIntegerv( GL_NUM_EXTENSIONS, &nExtensionCount );

	for	( int i = 0; i < nExtensionCount; i++ )
	{
		const GLubyte* pExtensionName = glGetStringi( GL_EXTENSIONS, i );
		OutputDebugString( (LPCSTR)pExtensionName );
		OutputDebugString( "\n" );
	}

	//glewInit();

	// Destroy dummy context
	wglMakeCurrent( 0, 0 );
	wglDeleteContext( hDummyGLContext );

	_bIsInitialized = true;

	return	( OKD_OK );
}
