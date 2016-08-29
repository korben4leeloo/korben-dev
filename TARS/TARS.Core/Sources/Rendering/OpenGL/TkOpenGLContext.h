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
public:

private:
					TkOpenGLContext( const TkWindow* pWindow, const HGLRC hGLRC );
					~TkOpenGLContext();

	void			destroy();

	const TkWindow*	_pWindow;
	HGLRC			_hGLRC;
};

#endif