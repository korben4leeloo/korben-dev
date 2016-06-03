//*****************************************************************************
//
//	Class:		TsWin32Window
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_Core_TsWin32Window_h__
#define __TARS_Core_TsWin32Window_h__

#include <Windows.h>
#include <QtCore/QString>

class TsEventManager;

class TsWin32Window
{
public:
							TsWin32Window();
							~TsWin32Window();

	void					create( const HINSTANCE& hInstance );
	void					show();

	inline void				setEventManager( TsEventManager* pEventManager );

private:
	static LRESULT CALLBACK WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );

	QString					_strWindowName;

	int						_nClientWidth;
	int						_nClientHeight;
	int						_nBitsPerPixel;

	bool					_bFullscreen;

	TsEventManager*			_pEventManager;

	HWND					_hWnd;
};

//-----------------------------------------------------------------------------
// Name:		setEventManager
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void TsWin32Window::setEventManager( TsEventManager* pEventManager )
{
	_pEventManager = pEventManager;
}

#endif