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

class QmApplication;
class QmInputManager;
class QmOpenGLContext;

class QmWindow
{
	friend class QmApplication;

public:
	void					show();
	void					hide();

	inline void				setWindowTitle( const QmString& strWindowTitle );

	inline HWND				getWindowHandle() const;
	inline HDC				getDeviceContext() const;

	QmOpenGLContext*		createOpenGLContext();
	void					destroyOpenGLContext();

private:
							QmWindow( const QmApplication* pWin32App );
							~QmWindow();

	void					create();
	void					destroy();

	static LRESULT CALLBACK WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );

	QmString				_strWindowTitle;
	
	int						_nClientWidth;
	int						_nClientHeight;
	int						_nBitsPerPixel;

	bool					_bFullscreen;

	const QmApplication*	_pWin32App;

	HWND					_hWnd;
	HDC						_hDC;

	QmOpenGLContext*		_pOpenGLContext;
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