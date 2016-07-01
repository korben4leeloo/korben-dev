//*****************************************************************************
//
//	Class:		TkWin32InputManager
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_CORE_TK_WIN32_INPUT_MANAGER_H__
#define __TARS_CORE_TK_WIN32_INPUT_MANAGER_H__

#include "Root.h"
#include TARS_CORE_H(Input/TkInputState)

class TkWin32InputManager
{
public:
					TkWin32InputManager();
					~TkWin32InputManager();

	void			registerDevices();
	void			enumDevices();

	uint64			onReceiveRawInput( const uint64 nRawInputHandle );

private:
	void			initWin32KeyMapper();

	TARS_KEY		_win32KeyMapper[256];

	TkInputState	_inputState;
};

#endif