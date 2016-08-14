//*****************************************************************************
//
//	File:		TkOpenGLContext.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "TkOpenGLContext.h"

#include TARS_CORE_H(Rendering/Window/TkWindow)
#include TARS_CORE_H(Rendering/OpenGL/TkOpenGLExtensions)
#include TARS_CORE_H(Rendering/OpenGL/TkOpenGLInterface)

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
TkOpenGLContext::TkOpenGLContext( const TkWindow* pWindow, const HGLRC hGLRC )
: _pWindow	( pWindow )
, _hGLRC	( hGLRC )
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
