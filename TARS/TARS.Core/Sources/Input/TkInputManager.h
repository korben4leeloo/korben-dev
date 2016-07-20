//*****************************************************************************
//
//	Class:		TkInputManager
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_CORE_TK_WIN32_INPUT_MANAGER_H__
#define __TARS_CORE_TK_WIN32_INPUT_MANAGER_H__

#include "Root.h"
#include TARS_CORE_H(Input/TkInputState)

class TkInputManager
{
public:
					TkInputManager();
					~TkInputManager();

	void			registerDevices();
	void			enumDevices();

	uint64			onRawInput( const uint64 nRawInputHandle );

private:
	void			initWin32KeyMapper();

	TarsKeyEnum		_win32KeyMapper[256];
	TkInputState	_inputState;
};

#endif