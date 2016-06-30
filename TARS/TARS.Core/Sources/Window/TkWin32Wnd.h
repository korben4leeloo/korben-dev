//*****************************************************************************
//
//	Class:		TkWin32Wnd
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_CORE_TK_WIN32_WND_H__
#define __TARS_CORE_TK_WIN32_WND_H__

#include "Root.h"

#include <Windows.h>

class TkWin32App;

class TkWin32Wnd
{
public:
							TkWin32Wnd( const TkWin32App* pWin32App );
							~TkWin32Wnd();

	void					create();
	void					show();

private:
	static LRESULT CALLBACK WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );

	TkString				_strWindowName;

	int						_nClientWidth;
	int						_nClientHeight;
	int						_nBitsPerPixel;

	bool					_bFullscreen;

	const TkWin32App*		_pWin32App;

	HWND					_hWnd;
};

#endif