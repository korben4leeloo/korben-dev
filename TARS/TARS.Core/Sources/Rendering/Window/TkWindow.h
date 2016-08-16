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
	friend class TkRenderManager;

public:
	void					create();
	void					show();
	void					hide();

	inline void				setWindowTitle( const TkString& strWindowTitle );

	inline HWND				getWindowHandle() const;
	inline HDC				getDeviceContext() const;

private:
							TkWindow( const TkApplication* pWin32App );
							~TkWindow();

	static LRESULT CALLBACK WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );

	void					destroy();

	TkString				_strWindowTitle;

	int						_nClientWidth;
	int						_nClientHeight;
	int						_nBitsPerPixel;

	bool					_bFullscreen;

	const TkApplication*	_pWin32App;

	HWND					_hWnd;
	HDC						_hDC;
};

//-----------------------------------------------------------------------------
// Name:		setWindowTitle
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void TkWindow::setWindowTitle( const TkString& strWindowTitle )
{
	_strWindowTitle = strWindowTitle;
}

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