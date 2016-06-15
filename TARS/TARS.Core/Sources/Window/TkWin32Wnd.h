//*****************************************************************************
//
//	Class:		TkWin32Wnd
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_CORE_TK_WIN32_WND_H__
#define __TARS_CORE_TK_WIN32_WND_H__

#include <Windows.h>
#include <QtCore/QString>

class TkWin32App;
//class TkEventManager;

class TkWin32Wnd
{
public:
							TkWin32Wnd( const TkWin32App* pWin32App );
							~TkWin32Wnd();

	void					create();
	void					show();

	//inline void				setEventManager( TkEventManager* pEventManager );

private:
	static LRESULT CALLBACK WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );

	QString					_strWindowName;

	int						_nClientWidth;
	int						_nClientHeight;
	int						_nBitsPerPixel;

	bool					_bFullscreen;

	const TkWin32App*		_pWin32App;
	//TkEventManager*			_pEventManager;

	HWND					_hWnd;
};

////-----------------------------------------------------------------------------
//// Name:		setEventManager
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//void TkWin32Wnd::setEventManager( TkEventManager* pEventManager )
//{
//	_pEventManager = pEventManager;
//}

#endif