//*****************************************************************************
//
//	Class:		QmWindow
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __QUANTUM_CORE_TK_WIN32_WND_H__
#define __QUANTUM_CORE_TK_WIN32_WND_H__

#include "Root.h"

#include <Windows.h>

class QmWindow
{
	friend class QmApplication;

public:
	QM_DECLARE_SIGNAL( OnInputReceived, RAWINPUT* )

	void					show();
	void					hide();

	inline void				setWindowTitle( const QmString& strWindowTitle );

	inline HWND				getWindowHandle() const;
	inline HDC				getDeviceContext() const;

private:
							QmWindow();
							~QmWindow();

	void					create( const HINSTANCE hInstance );
	void					destroy();

	static LRESULT CALLBACK WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );

	QmString				_strWindowTitle;
	
	int						_nClientWidth;
	int						_nClientHeight;
	int						_nBitsPerPixel;

	bool					_bFullscreen;

	HWND					_hWnd;
	HDC						_hDC;
};

//-----------------------------------------------------------------------------
// Name:		setWindowTitle
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void QmWindow::setWindowTitle( const QmString& strWindowTitle )
{
	_strWindowTitle = strWindowTitle;
}

//-----------------------------------------------------------------------------
// Name:		getWindowHandle
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
HWND QmWindow::getWindowHandle() const
{
	return ( _hWnd );
}

//-----------------------------------------------------------------------------
// Name:		getDeviceContext
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
HDC QmWindow::getDeviceContext() const
{
	return ( _hDC );
}

#endif