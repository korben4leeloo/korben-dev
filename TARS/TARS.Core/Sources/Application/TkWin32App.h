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

#include TARS_CORE_H(Containers/TkVector)

class TkWin32Wnd;
class TkWin32InputManager;

class TkWin32App
{
public:
								TkWin32App( const HINSTANCE& hInstance );
								~TkWin32App();

	inline HINSTANCE			getInstanceHandle() const;
	inline TkWin32InputManager*	getInputManager() const;

	TkWin32InputManager*		initInputs();
	TkWin32Wnd*					initWindow();
	void						initWglContext();

	int64_t						run();

private:
	void						destroy();

	HINSTANCE					_hInstance;
	TkWin32InputManager*		_pInputManager;
	TkVector<TkWin32Wnd*>		_windowArray;
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
TkWin32InputManager* TkWin32App::getInputManager() const
{
	return ( _pInputManager );
}

#endif