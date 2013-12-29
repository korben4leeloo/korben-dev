//*****************************************************************************
//
//	File:		OkdOpenGLContext.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdOpenGLContext.h"

// OpenGL includes
#include	ORKID_ENGINE_H(OrkidEngine)
#include	ORKID_ENGINE_H(Resources/OkdResourceDatabase)
#include	ORKID_ENGINE_H(OpenGL/OkdOpenGL_API)
#include	ORKID_CORE_H(Stream/OkdFileStream)
#include	ORKID_CORE_H(String/OkdString)

#define		ORKID_OPENGL_MAJOR_VERSION		3
#define		ORKID_OPENGL_MINOR_VERSION		3
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

	// Build pixel format descriptor
	PIXELFORMATDESCRIPTOR pixelFormatDesc;

	memset( &pixelFormatDesc, 0, sizeof(PIXELFORMATDESCRIPTOR) );

	pixelFormatDesc.nSize			= sizeof(PIXELFORMATDESCRIPTOR);
	pixelFormatDesc.dwFlags			= PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;
	pixelFormatDesc.iPixelType		= PFD_TYPE_RGBA;
	pixelFormatDesc.cColorBits		= 32;
	pixelFormatDesc.cDepthBits		= 24;
	pixelFormatDesc.cStencilBits	= 8;
	pixelFormatDesc.iLayerType		= PFD_MAIN_PLANE;

	OkdOpenGL_API::initialize( _hDeviceContext, &pixelFormatDesc );

	// Pixel format attributes
	const int pixelFormatAttribList[] = 
	{ 
		WGL_DRAW_TO_WINDOW_ARB, GL_TRUE, 
		WGL_SUPPORT_OPENGL_ARB, GL_TRUE, 
		WGL_DOUBLE_BUFFER_ARB,	GL_TRUE, 
		WGL_PIXEL_TYPE_ARB,		WGL_TYPE_RGBA_ARB, 
		WGL_COLOR_BITS_ARB,		32, 
		WGL_DEPTH_BITS_ARB,		24, 
		WGL_STENCIL_BITS_ARB,	8, 
		0
	};

	int		nPixelFormat;
	UINT	uiFormatCount;

	wglChoosePixelFormatARB( _hDeviceContext, pixelFormatAttribList, 0, 1, &nPixelFormat, &uiFormatCount );
	SetPixelFormat( _hDeviceContext, nPixelFormat, &pixelFormatDesc );

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

float trianglePoints[9] = 
{
	-0.5f, 0.0f, 0.0f,
	0.0f, 0.5f, 0.0f,
	0.5f, 0.0f, 0.0f
};

GLuint uiVBO, uiVAO, uiVertexShader, uiPixelShader, uiShaderProgram;
GLint nAttribPos = -1;

//float trianglePoints[9] = 
//{
//	-0.5f, 0.0f, 5.0f,
//	0.5f, 0.0f, 5.0f,
//	0.0f, 0.5f, 5.0f
//};

//-----------------------------------------------------------------------------
// Name:		render
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdOpenGLContext::render()
{
	if	( nFrame == 0 )
	{
		const OkdString&	strResourceDBPath	= OrkidEngine::instance()->getResourceDatabase()->getResourceDatabasePath();
		OkdString			strVertexShaderPath	= strResourceDBPath + "\\Shaders\\GLSL\\color.vs";
		OkdString			strPixelShaderPath	= strResourceDBPath + "\\Shaders\\GLSL\\color.ps";

		OkdFileStream vertexShaderFileStream( strVertexShaderPath, OkdFileStream::OpenModeIn | OkdFileStream::OpenModeBinary );
		OkdFileStream pixelShaderFileStream( strPixelShaderPath, OkdFileStream::OpenModeIn | OkdFileStream::OpenModeBinary );

		uiVertexShader = glCreateShader( GL_VERTEX_SHADER );
		uiPixelShader = glCreateShader( GL_FRAGMENT_SHADER );

		GLint uiShaderLength = OkdFileStream::length( strVertexShaderPath );
		GLchar* pcShaderText = new GLchar[uiShaderLength+1];
		GLint nResult;

		vertexShaderFileStream.read( pcShaderText, uiShaderLength );
		pcShaderText[uiShaderLength] = '\0';

		glShaderSource( uiVertexShader, 1, (const GLchar**)&pcShaderText, &uiShaderLength );
		glCompileShader( uiVertexShader );
		
		glGetShaderiv( uiVertexShader, GL_COMPILE_STATUS, &nResult );
		ORKID_ASSERT( nResult == GL_TRUE );

		if	( nResult == GL_FALSE )
		{
			GLint maxLength = 0;
			glGetShaderiv( uiVertexShader, GL_INFO_LOG_LENGTH, &maxLength );
 
			//The maxLength includes the NULL character
			GLchar* pcShaderLog = new GLchar[maxLength];
			glGetShaderInfoLog( uiVertexShader, maxLength, &maxLength, &pcShaderLog[0] );

			OutputDebugString( pcShaderLog );
		}

		uiShaderLength = OkdFileStream::length( strPixelShaderPath );

		pixelShaderFileStream.read( pcShaderText, uiShaderLength );
		pcShaderText[uiShaderLength] = '\0';

		glShaderSource( uiPixelShader, 1, (const GLchar**)&pcShaderText, &uiShaderLength );
		glCompileShader( uiPixelShader );
		glGetShaderiv( uiPixelShader, GL_COMPILE_STATUS, &nResult );
		ORKID_ASSERT( nResult == GL_TRUE );

		uiShaderProgram = glCreateProgram();
		glAttachShader( uiShaderProgram, uiVertexShader );
		glAttachShader( uiShaderProgram, uiPixelShader );
		glLinkProgram( uiShaderProgram );

		glGetProgramiv( uiShaderProgram, GL_LINK_STATUS, &nResult );
		ORKID_ASSERT( nResult == GL_TRUE );

		if	( nResult != GL_TRUE )
		{
			GLint maxLength = 0;
			glGetProgramiv( uiShaderProgram, GL_INFO_LOG_LENGTH, &maxLength );

			//The maxLength includes the NULL character
			GLchar* pcProgramLog = new GLchar[maxLength];
			glGetProgramInfoLog( uiShaderProgram, maxLength, &maxLength, &pcProgramLog[0] );

			OutputDebugString( pcProgramLog );
		}

		nAttribPos = glGetAttribLocation( uiShaderProgram, "inputPosition" );

		glGenBuffers( 1, &uiVBO );
		glGenVertexArrays( 1, &uiVAO );

		glBindBuffer( GL_ARRAY_BUFFER, uiVBO );
		glBindVertexArray( uiVAO );

		glBufferData( GL_ARRAY_BUFFER, sizeof(trianglePoints), trianglePoints, GL_STATIC_DRAW );

		glEnableVertexAttribArray( nAttribPos );

		glVertexAttribPointer( nAttribPos, 3, GL_FLOAT, GL_FALSE, 0, 0 );

		glBindVertexArray( 0 );
		glBindBuffer( GL_ARRAY_BUFFER, 0 );
	}

	nFrame++;

	float fColor = (float)(nFrame%50) / 50.0f;

	glClearColor(0.4f, 0.4f, 0.4f, 0.0f);
	//glClearColor( fColor * 0.4f, fColor - 0.6f, fColor * 0.9f, 0.0f );
	glViewport(0, 0, 500, 500); // Set the viewport size to fill the window
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT ); // Clear required buffers

	glUseProgram( uiShaderProgram );

	glBindBuffer( GL_ARRAY_BUFFER, uiVBO );
	glBindVertexArray( uiVAO );

	glDrawArrays( GL_TRIANGLES, 0, 3 );

	glBindVertexArray( 0 );
	glBindBuffer( GL_ARRAY_BUFFER, 0 );

	glUseProgram( 0 );

	SwapBuffers( _hDeviceContext ); // Swap buffers so we can see our rendering
}
