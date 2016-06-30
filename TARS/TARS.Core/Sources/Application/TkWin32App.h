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
class TkWin32InputManager;

class TkWin32App
{
public:
								TkWin32App( const HINSTANCE& hInstance );
								~TkWin32App();

	inline HINSTANCE			getInstanceHandle() const;
	inline TkWin32InputManager*	getInputManager();

	TkWin32InputManager*		initInputs();
	TkWin32Wnd*					initWindow();

	int64_t						run();

private:
	void						destroy();

	HINSTANCE					_hInstance;
	TkWin32InputManager*		_pInputManager;
	TkWin32Wnd*					_pWindow;
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

//-----------------------------------------------------------------------------
// Name:		getInputManager
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkWin32InputManager* TkWin32App::getInputManager()
{
	return ( _pInputManager );
}

#endif