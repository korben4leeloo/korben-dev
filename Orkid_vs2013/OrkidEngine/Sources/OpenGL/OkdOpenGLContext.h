//*****************************************************************************
//
//	Class:		OkdOpenGLContext
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdOpenGLContext_h__
#define __OrkidEngine_OkdOpenGLContext_h__

#include	"Root.h"

#ifdef _WIN32
	#include	<Windows.h>
#endif

class OkdOpenGLContext
{
public:
					OkdOpenGLContext();
					~OkdOpenGLContext();

#ifdef _WIN32
	OrkidErrorCode	create( const HWND hWnd );
#endif

	void			render();

private:
	HWND			_hWindow;
	HDC				_hDeviceContext;
	HGLRC			_hRenderContext;
};

#endif