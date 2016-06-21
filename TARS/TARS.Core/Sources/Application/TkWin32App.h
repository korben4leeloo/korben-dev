//*****************************************************************************
//
//	Class:		TkWin32App
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_CORE_TK_WIN32_APP_H__
#define __TARS_CORE_TK_WIN32_APP_H__

#include "Root.h"
#include <Windows.h>

class TkWin32Wnd;

class TkWin32App
{
public:
						TkWin32App( const HINSTANCE& hInstance );
						~TkWin32App();

	inline HINSTANCE	getInstanceHandle() const;

	TkWin32Wnd*			createWindow();
	int64_t				runMessageLoop();

private:
	HINSTANCE			_hInstance;
};

//-----------------------------------------------------------------------------
// Name:		getInstanceHandle
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
HINSTANCE TkWin32App::getInstanceHandle() const
{
	return ( _hInstance );
}

#endif