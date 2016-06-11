//*****************************************************************************
//
//	Class:		TsWin32Wnd
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_CORE_TS_WIN32_WND_H__
#define __TARS_CORE_TS_WIN32_WND_H__

#include <Windows.h>
#include <QtCore/QString>

class TsWin32App;
//class TsEventManager;

class TsWin32Wnd
{
public:
							TsWin32Wnd( const TsWin32App* pWin32App );
							~TsWin32Wnd();

	void					create();
	void					show();

	//inline void				setEventManager( TsEventManager* pEventManager );

private:
	static LRESULT CALLBACK WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );

	QString					_strWindowName;

	int						_nClientWidth;
	int						_nClientHeight;
	int						_nBitsPerPixel;

	bool					_bFullscreen;

	const TsWin32App*		_pWin32App;
	//TsEventManager*			_pEventManager;

	HWND					_hWnd;
};

////-----------------------------------------------------------------------------
//// Name:		setEventManager
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//void TsWin32Wnd::setEventManager( TsEventManager* pEventManager )
//{
//	_pEventManager = pEventManager;
//}

#endif