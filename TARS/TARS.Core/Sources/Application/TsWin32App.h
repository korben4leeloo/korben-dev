//*****************************************************************************
//
//	Class:		TsWin32App
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_CORE_TS_WIN32_APP_H__
#define __TARS_CORE_TS_WIN32_APP_H__

#include <Windows.h>

class TsWin32Wnd;

class TsWin32App
{
public:
						TsWin32App( const HINSTANCE& hInstance );
						~TsWin32App();

	inline HINSTANCE	getInstanceHandle() const;

	TsWin32Wnd*			createWindow();
	//int64_t				runMessageLoop();
	int					runMessageLoop();

private:
	HINSTANCE			_hInstance;
	TsWin32Wnd*			_pMainWindow;
};

//-----------------------------------------------------------------------------
// Name:		getInstanceHandle
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
HINSTANCE TsWin32App::getInstanceHandle() const
{
	return ( _hInstance );
}

#endif