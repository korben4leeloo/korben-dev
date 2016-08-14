//*****************************************************************************
//
//	File:		TkOpenGLInterface.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "TkOpenGLInterface.h"

#include <Windows.h>
#include <gl/GL.h>
#include <GLext.h>
#include <wglext.h>

#include TARS_CORE_H(Rendering/OpenGL/TkOpenGLContext)
#include TARS_CORE_H(Rendering/Window/TkWindow)

#define TARS_OPEN_GL_FUNC_NULL( PFNOPENGLPROC, funcName ) PFNOPENGLPROC funcName = nullptr;
#define TARS_OPEN_GL_FUNC_PROC( PFNOPENGLPROC, funcName ) funcName = (PFNOPENGLPROC)wglGetProcAddress( #funcName );

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

bool TkOpenGLInterface::_bApiLoaded = false;

#define OPEN_GL_MAJOR_VERSION_REQUIRED	4
#define OPEN_GL_MINOR_VERSION_REQUIRED	0

#define COLOR_BITS_COUNT				32
#define DEPTH_BITS_COUNT				24
#define STENCIL_BITS_COUNT				8

//-----------------------------------------------------------------------------
// Name:		initApi
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void TkOpenGLInterface::initApi()
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

//-----------------------------------------------------------------------------
// Name:		getOpenGLVersion
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void TkOpenGLInterface::getOpenGLVersion( int32& nMajorVersion, int32& nMinorVersion )
{
	nMajorVersion = 0;
	nMinorVersion = 0;

	if	( _bApiLoaded )
	{
		glGetIntegerv( GL_MAJOR_VERSION, &nMajorVersion );
		glGetIntegerv( GL_MINOR_VERSION, &nMinorVersion );

		TARS_MESSAGE( "\nOpenGL version: %d.%d", nMajorVersion, nMinorVersion );
	}
}

////-----------------------------------------------------------------------------
//// Name:		checkExtensions
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//void TkOpenGLInterface::checkExtensions( const TkOpenGLContext* pContext )
//{
//	// Browse available GL extensions
//	int32 nExtensionCount;
//	glGetIntegerv( GL_NUM_EXTENSIONS, &nExtensionCount );
//
//	TARS_MESSAGE( "\nAvailable OpenGL extensions" );
//	TARS_MESSAGE( "---------------------------" );
//
//	for	( int32 i = 0; i < nExtensionCount; i++ )
//	{
//		const GLubyte* pcExtensionName = glGetStringi( GL_EXTENSIONS, i );
//		TARS_MESSAGE( (char*)pcExtensionName );
//	}
//
//	// Browse available WGL extensions
//	TkString			strWglExtensions( wglGetExtensionsStringARB( pContext->getDeviceContext() ) );
//	TkVector<TkString>	wglExtensionNameArray;
//
//	TARS_MESSAGE( "\nAvailable WGL extensions" );
//	TARS_MESSAGE( "------------------------" );
//
//	strWglExtensions.split( " ", wglExtensionNameArray );
//
//	for	( uint32 i = 0; i < wglExtensionNameArray.size(); i++ )
//	{
//		TARS_MESSAGE( wglExtensionNameArray[i].buffer() );
//	}
//}

//-----------------------------------------------------------------------------
// Name:		checkExtensions
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void checkExtensions( const HDC hDC )
{
	// Browse available GL extensions
	int32 nExtensionCount;
	glGetIntegerv( GL_NUM_EXTENSIONS, &nExtensionCount );

	TARS_MESSAGE( "\nAvailable OpenGL extensions" );
	TARS_MESSAGE( "---------------------------" );

	for	( int32 i = 0; i < nExtensionCount; i++ )
	{
		const GLubyte* pcExtensionName = glGetStringi( GL_EXTENSIONS, i );
		TARS_MESSAGE( (char*)pcExtensionName );
	}

	// Browse available WGL extensions
	TkString			strWglExtensions( wglGetExtensionsStringARB( hDC ) );
	TkVector<TkString>	wglExtensionNameArray;

	TARS_MESSAGE( "\nAvailable WGL extensions" );
	TARS_MESSAGE( "------------------------" );

	strWglExtensions.split( " ", wglExtensionNameArray );

	for	( uint32 i = 0; i < wglExtensionNameArray.size(); i++ )
	{
		TARS_MESSAGE( wglExtensionNameArray[i].buffer() );
	}
}

//-----------------------------------------------------------------------------
// Name:		createContext
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkOpenGLContext* TkOpenGLInterface::createContext( TkWindow* pWindow )
{
	TARS_ASSERT( pWindow );

	HDC hDC = pWindow->getDeviceContext();
	TARS_ASSERT( hDC != nullptr );

	// Pixel Format Descriptor
	PIXELFORMATDESCRIPTOR	pixelFormatDesc;
	int32					nPixelFormat;

	memset( &pixelFormatDesc, 0, sizeof(PIXELFORMATDESCRIPTOR) );

	pixelFormatDesc.nSize			= sizeof(PIXELFORMATDESCRIPTOR);
	pixelFormatDesc.nVersion		= 1;
	pixelFormatDesc.dwFlags			= PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pixelFormatDesc.iPixelType		= PFD_TYPE_RGBA;
	pixelFormatDesc.cColorBits		= COLOR_BITS_COUNT;
	pixelFormatDesc.cDepthBits		= DEPTH_BITS_COUNT;
	pixelFormatDesc.cStencilBits	= STENCIL_BITS_COUNT;
	pixelFormatDesc.iLayerType		= PFD_MAIN_PLANE;

	if ( ( nPixelFormat = ChoosePixelFormat( hDC, &pixelFormatDesc ) ) == 0 )
	{
		return ( nullptr );
	}

	SetPixelFormat( hDC, nPixelFormat, &pixelFormatDesc );
	
	// Create a simple Windows OpenGL context and bind it ( will be used to get OpenGL fucntions and create a more up-to-date context )
	HGLRC hDummyGLRC;

	if	( ( hDummyGLRC = wglCreateContext( hDC ) ) == nullptr )
	{
		return ( nullptr );
	}

	if	( wglMakeCurrent( hDC, hDummyGLRC ) == FALSE )
	{
		return ( nullptr );
	}

	// Load OpenGL extensions functions
	TkOpenGLInterface::initApi();

	// Display available OpenGL and WGL extensions
	//TkOpenGLInterface::checkExtensions( this );
	checkExtensions( hDC );

	// Get OpenGL version
	int32 nMajorVersion, nMinorVersion;

	TkOpenGLInterface::getOpenGLVersion( nMajorVersion, nMinorVersion );
	TARS_ASSERT( nMajorVersion >= OPEN_GL_MAJOR_VERSION_REQUIRED );
	TARS_ASSERT( nMinorVersion >= OPEN_GL_MINOR_VERSION_REQUIRED );

	// Create pixel format with attributes
	UINT nPixelFormatCount;
	const int pixelFormatAttribList[] =
	{
		WGL_DRAW_TO_WINDOW_ARB,	GL_TRUE,
		WGL_SUPPORT_OPENGL_ARB,	GL_TRUE,
		WGL_DOUBLE_BUFFER_ARB,	GL_TRUE,
		WGL_PIXEL_TYPE_ARB,		WGL_TYPE_RGBA_ARB,
		WGL_COLOR_BITS_ARB,		COLOR_BITS_COUNT,
		WGL_DEPTH_BITS_ARB,		DEPTH_BITS_COUNT,
		WGL_STENCIL_BITS_ARB,	STENCIL_BITS_COUNT,
		0,						//End
	};

	// Not really necessary but...
	if ( wglChoosePixelFormatARB( hDC, pixelFormatAttribList, nullptr, 1, &nPixelFormat, &nPixelFormatCount ) == FALSE )
	{
		return ( nullptr );
	}

	memset( &pixelFormatDesc, 0, sizeof(PIXELFORMATDESCRIPTOR) );
	DescribePixelFormat( hDC, nPixelFormat, sizeof(pixelFormatDesc), &pixelFormatDesc );
	SetPixelFormat( hDC, nPixelFormat, &pixelFormatDesc );

	// Create WGL context with attributes
	const int contextAttribList[] =
	{
		WGL_CONTEXT_MAJOR_VERSION_ARB,	nMajorVersion,
        WGL_CONTEXT_MINOR_VERSION_ARB,	nMinorVersion, 
        WGL_CONTEXT_FLAGS_ARB,			WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
        WGL_CONTEXT_PROFILE_MASK_ARB,	WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
		0,								//End
	};

	HGLRC hGLRC = wglCreateContextAttribsARB( hDC, nullptr, contextAttribList );

	// Delete the dummy context and bind the real context
	wglMakeCurrent( hDC, hGLRC );
	wglDeleteContext( hDummyGLRC );

	TkOpenGLInterface::getOpenGLVersion( nMajorVersion, nMinorVersion );
	TARS_ASSERT( nMajorVersion >= OPEN_GL_MAJOR_VERSION_REQUIRED );
	TARS_ASSERT( nMinorVersion >= OPEN_GL_MINOR_VERSION_REQUIRED );

	TkOpenGLContext* pContext = new TkOpenGLContext( pWindow, hGLRC );

	return ( pContext );
}
