//*****************************************************************************
//
//	File:		TkWGLContext.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "TkWGLContext.h"

#include TARS_CORE_H(Window/TkWin32Wnd)
#include TARS_CORE_H(OpenGL/TkOpenGLExt)
#include TARS_CORE_H(OpenGL/TkWGLInterface)

#define COLOR_BITS_COUNT	32
#define DEPTH_BITS_COUNT	24
#define STENCIL_BITS_COUNT	8

//-----------------------------------------------------------------------------
// Name:		TkWin32OpenGLContext constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkWGLContext::TkWGLContext( const TkWin32Wnd* pWindow )
: _pWindow( pWindow )
{
	
}

//-----------------------------------------------------------------------------
// Name:		TkWin32OpenGLContext destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkWGLContext::~TkWGLContext()
{
	
}

//-----------------------------------------------------------------------------
// Name:		init
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void TkWGLContext::init()
{
	TARS_ASSERT( _pWindow );

	HDC deviceContext = GetDC( _pWindow->getWindowHandle() );

	if	( deviceContext == nullptr )
	{
		return;
	}

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

	nPixelFormat = ChoosePixelFormat( deviceContext, &pixelFormatDesc );

	if	( nPixelFormat == 0 )
	{
		return;
	}

	SetPixelFormat( deviceContext, nPixelFormat, &pixelFormatDesc );
	
	// Create a simple Windows OpenGL context and bind it ( will be used to get OpenGL extensions and create a more up-to-date context )
	HGLRC hGLRC = wglCreateContext( deviceContext );

	if	( hGLRC == nullptr )
	{
		return;
	}

	if	( wglMakeCurrent( deviceContext, hGLRC ) == FALSE )
	{
		return;
	}

	// Load OpenGL extensions functions
	TkWGLInterface::loadExtensions();

	int32 nMajorVersion = -1;
	int32 nMinorVersion = -1;

	glGetIntegerv( GL_MAJOR_VERSION, &nMajorVersion );
	glGetIntegerv( GL_MINOR_VERSION, &nMinorVersion );

	// Browse extensions
	int32 nExtensionCount;
	glGetIntegerv( GL_NUM_EXTENSIONS, &nExtensionCount );

	for	( int32 i = 0; i < nExtensionCount; i++ )
	{
		const GLubyte* pcExtensionName = glGetStringi( GL_EXTENSIONS, i );
		OutputDebugString( (LPCSTR)pcExtensionName );
		OutputDebugString( "\n" );
	}

	PFNWGLGETEXTENSIONSSTRINGARBPROC wglGetExtensionsStringARB = (PFNWGLGETEXTENSIONSSTRINGARBPROC)wglGetProcAddress( "wglGetExtensionsStringARB" );

	const char* pcWglExtensions = (const char*)wglGetExtensionsStringARB( deviceContext );

	TkString strWglExtensions( pcWglExtensions );
	TkVector<TkString> wglExtensionNameArray;

	strWglExtensions.split( " ", wglExtensionNameArray );

	int n = 0;
}
