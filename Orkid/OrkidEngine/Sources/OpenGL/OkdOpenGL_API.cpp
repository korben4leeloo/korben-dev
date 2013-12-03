//*****************************************************************************
//
//	File:		OkdOpenGL_API.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdOpenGL_API.h"

#define	OKD_OPENGL_API_GET_FUNC( FuncPtr, FuncName ) FuncName = (FuncPtr)wglGetProcAddress( #FuncName )

PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = 0;

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

	OKD_OPENGL_API_GET_FUNC( PFNWGLCREATECONTEXTATTRIBSARBPROC, wglCreateContextAttribsARB );

	_bIsInitialized = true;
}
