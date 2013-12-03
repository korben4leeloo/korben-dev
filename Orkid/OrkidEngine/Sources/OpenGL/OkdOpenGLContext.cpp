//*****************************************************************************
//
//	File:		OkdOpenGLContext.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdOpenGLContext.h"

// OpenGL includes
#include	ORKID_ENGINE_H(OpenGL/OkdOpenGL_API)

#define		ORKID_OPENGL_MAJOR_VERSION		3
#define		ORKID_OPENGL_MINOR_VERSION		2
#define		ORKID_OPENGL_CONTEXT_FLAGS_ARB	WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB

//-----------------------------------------------------------------------------
// Name:		OkdOpenGLContext constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdOpenGLContext::OkdOpenGLContext()
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdOpenGLContext destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdOpenGLContext::~OkdOpenGLContext()
{

}

#ifdef _WIN32
//-----------------------------------------------------------------------------
// Name:		create
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OrkidErrorCode	OkdOpenGLContext::create(const HWND	hWnd)
{
	// Store context information
	_hWindow		= hWnd;
	_hDeviceContext = GetDC( _hWindow );

	 // Create a pixel format descriptor
	PIXELFORMATDESCRIPTOR pixelFormatDesc;

	memset( &pixelFormatDesc, 0, sizeof(PIXELFORMATDESCRIPTOR) );

	pixelFormatDesc.nSize		= sizeof(PIXELFORMATDESCRIPTOR);
	pixelFormatDesc.dwFlags		= PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;
	pixelFormatDesc.iPixelType	= PFD_TYPE_RGBA;
	pixelFormatDesc.cColorBits	= 32;
	pixelFormatDesc.cDepthBits	= 32;
	pixelFormatDesc.iLayerType	= PFD_MAIN_PLANE;

	// Ask for a matching pixel format descriptor and use it
	int nPixelFormat = ChoosePixelFormat( _hDeviceContext, &pixelFormatDesc );

	if	( nPixelFormat == 0 )
	{
		return	( OKD_FAIL );
	}

	BOOL result = SetPixelFormat( _hDeviceContext, nPixelFormat, &pixelFormatDesc );

	if	( !result )
	{
		return	( OKD_FAIL );
	}

	HGLRC tempOpenGLContext = wglCreateContext(_hDeviceContext); // Create an OpenGL 2.1 context for our device context
	wglMakeCurrent(_hDeviceContext, tempOpenGLContext); // Make the OpenGL 2.1 context current and active

	//// Initialize GLEW
	//GLenum eGlewError = glewInit();

	//if	( eGlewError != GLEW_OK )
	//{
	//	OutputDebugString( (char*)glewGetErrorString( eGlewError ) );
	//	return	( OKD_FAIL );
	//}

	//// Ask GLEW to check if the requested OpenGL version is supported, then create and apply the OpenGL context
	//GLboolean glbResult = wglewIsSupported( "WGL_ARB_create_context" );

	//if	( glbResult != 1 )
	//{
	//	return	( OKD_FAIL );
	//}

	OkdOpenGL_API::initialize();

	// Build context attributes list
	int contextAttributesARB[] = 
	{
		WGL_CONTEXT_MAJOR_VERSION_ARB,	ORKID_OPENGL_MAJOR_VERSION,
		WGL_CONTEXT_MINOR_VERSION_ARB,	ORKID_OPENGL_MINOR_VERSION,
		WGL_CONTEXT_FLAGS_ARB,			ORKID_OPENGL_CONTEXT_FLAGS_ARB,
		0
	};

	_hRenderContext = wglCreateContextAttribsARB( _hDeviceContext, 0, contextAttributesARB );
	wglMakeCurrent( _hDeviceContext, _hRenderContext );

	return	( OKD_OK );
}
#endif

static int nFrame = 0;

//-----------------------------------------------------------------------------
// Name:		render
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdOpenGLContext::render()
{
	nFrame++;

	float fColor = (float)(nFrame%50) / 50.0f;

	//glClearColor(0.4f, 0.6f, 0.9f, 0.0f);
	glClearColor( fColor * 0.4f, fColor - 0.6f, fColor * 0.9f, 0.0f );
	glViewport(0, 0, 500, 500); // Set the viewport size to fill the window
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); // Clear required buffers
	SwapBuffers( _hDeviceContext ); // Swap buffers so we can see our rendering
}
