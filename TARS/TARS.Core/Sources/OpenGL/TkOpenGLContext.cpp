//*****************************************************************************
//
//	File:		TkOpenGLContext.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "TkOpenGLContext.h"

#include TARS_CORE_H(Window/TkWindow)
#include TARS_CORE_H(OpenGL/TkOpenGLExtensions)
#include TARS_CORE_H(OpenGL/TkOpenGLInterface)

#define OPEN_GL_MAJOR_VERSION_REQUIRED	4
#define OPEN_GL_MINOR_VERSION_REQUIRED	0

#define COLOR_BITS_COUNT				32
#define DEPTH_BITS_COUNT				24
#define STENCIL_BITS_COUNT				8

//-----------------------------------------------------------------------------
// Name:		TkOpenGLContext constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkOpenGLContext::TkOpenGLContext( const TkWindow* pWindow )
: _pWindow( pWindow )
{
	
}

//-----------------------------------------------------------------------------
// Name:		TkOpenGLContext destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkOpenGLContext::~TkOpenGLContext()
{
	destroy();
}

//-----------------------------------------------------------------------------
// Name:		init
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void TkOpenGLContext::init()
{
	TARS_ASSERT( _pWindow );

	HDC hDC = _pWindow->getDeviceContext();
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
		return;
	}

	SetPixelFormat( hDC, nPixelFormat, &pixelFormatDesc );
	
	// Create a simple Windows OpenGL context and bind it ( will be used to get OpenGL fucntions and create a more up-to-date context )
	HGLRC hDummyGLRC;

	if	( ( hDummyGLRC = wglCreateContext( hDC ) ) == nullptr )
	{
		return;
	}

	if	( wglMakeCurrent( hDC, hDummyGLRC ) == FALSE )
	{
		return;
	}

	// Load OpenGL extensions functions
	TkOpenGLInterface::initApi();

	// Display available OpenGL and WGL extensions
	TkOpenGLInterface::checkExtensions( this );

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
		return;
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

	_hGLRC = wglCreateContextAttribsARB( hDC, nullptr, contextAttribList );

	// Delete the dummy context and bind the real context
	wglMakeCurrent( hDC, _hGLRC );
	wglDeleteContext( hDummyGLRC );

	TkOpenGLInterface::getOpenGLVersion( nMajorVersion, nMinorVersion );
	TARS_ASSERT( nMajorVersion >= OPEN_GL_MAJOR_VERSION_REQUIRED );
	TARS_ASSERT( nMinorVersion >= OPEN_GL_MINOR_VERSION_REQUIRED );
}

//-----------------------------------------------------------------------------
// Name:		getDeviceContext
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
HDC TkOpenGLContext::getDeviceContext() const
{
	return ( _pWindow->getDeviceContext() );
}

//-----------------------------------------------------------------------------
// Name:		destroy
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void TkOpenGLContext::destroy()
{
	if	( _hGLRC != nullptr )
	{
		wglMakeCurrent( nullptr, nullptr );
		wglDeleteContext( _hGLRC );
		_hGLRC = nullptr;
	}
}
