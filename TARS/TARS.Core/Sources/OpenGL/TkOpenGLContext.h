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
							TkOpenGLContext( const TkWindow* pWindow );
							~TkOpenGLContext();

	void					init();

	HDC						getDeviceContext() const;

private:
	void					destroy();

	const TkWindow*			_pWindow;
	HGLRC					_hGLRC;
};

#endif