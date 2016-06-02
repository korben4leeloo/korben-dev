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

class TsWin32Window
{
public:
			TsWin32Window();
			~TsWin32Window();

	void	create( const HINSTANCE& hInstance );
	void	show();

private:
	static LRESULT CALLBACK WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );

	QString	_strWindowName;

	int		_nClientWidth;
	int		_nClientHeight;
	int		_nBitsPerPixel;

	bool	_bFullscreen;

	HWND	_hWnd;
};

#endif