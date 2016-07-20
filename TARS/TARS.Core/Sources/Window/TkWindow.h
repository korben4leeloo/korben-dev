//*****************************************************************************
//
//	Class:		TkWindow
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_CORE_TK_WIN32_WND_H__
#define __TARS_CORE_TK_WIN32_WND_H__

#include "Root.h"

#include <Windows.h>

class TkApplication;
class TkInputManager;

class TkWindow
{
public:
							TkWindow( const TkApplication* pWin32App );
							~TkWindow();

	void					create();
	void					show();
	void					hide();

	inline HWND				getWindowHandle() const;
	inline HDC				getDeviceContext() const;

private:
	static LRESULT CALLBACK WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );

	TkString				_strWindowName;

	int						_nClientWidth;
	int						_nClientHeight;
	int						_nBitsPerPixel;

	bool					_bFullscreen;

	const TkApplication*	_pWin32App;

	HWND					_hWnd;
	HDC						_hDC;
};

//-----------------------------------------------------------------------------
// Name:		getWindowHandle
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
HWND TkWindow::getWindowHandle() const
{
	return ( _hWnd );
}

//-----------------------------------------------------------------------------
// Name:		getDeviceContext
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
HDC TkWindow::getDeviceContext() const
{
	return ( _hDC );
}

#endif