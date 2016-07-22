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

#include TARS_CORE_H(OpenGL/TkOpenGLContext)

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

//-----------------------------------------------------------------------------
// Name:		checkExtensions
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void TkOpenGLInterface::checkExtensions( const TkOpenGLContext* pContext )
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
	TkString			strWglExtensions( wglGetExtensionsStringARB( pContext->getDeviceContext() ) );
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

}
