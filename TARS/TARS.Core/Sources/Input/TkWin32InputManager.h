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

class TkWin32InputManager
{
public:
			TkWin32InputManager();
			~TkWin32InputManager();

	void	registerDevices();
	void	enumDevices();

	uint64	onReceiveRawInput( const uint64 nRawInputHandle );

private:

};

#endif