//*****************************************************************************
//
//	Class:		TkOpenGLContext
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_CORE_TK_WGL_CONTEXT_H__
#define __TARS_CORE_TK_WGL_CONTEXT_H__

#include "Root.h"
#include <Windows.h>

class TkWindow;

class TkOpenGLContext
{
	friend class TkWindow;

public:
	inline bool	isValid() const;

private:
				TkOpenGLContext();
				~TkOpenGLContext();

	void		create( TkWindow* pWindow );
	void		destroy();

	void		getOpenGLVersion( int32& nMajorVersion, int32& nMinorVersion );
	void		checkExtensions( const HDC& hDC );

	TkWindow*	_pWindow;
	HGLRC		_hGLRC;
};

//-----------------------------------------------------------------------------
// Name:		isValid
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
bool TkOpenGLContext::isValid() const
{
	return ( _hGLRC != nullptr );
}

#endif