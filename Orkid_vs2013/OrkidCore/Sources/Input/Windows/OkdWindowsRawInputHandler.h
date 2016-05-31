//*****************************************************************************
//
//	Class:		OkdWindowsRawInputHandler
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdWindowsRawInputHandler_h__
#define __OrkidCore_OkdWindowsRawInputHandler_h__

#include	"Root.h"

#include	<windows.h>
#include	ORKID_CORE_H(Input/OkdInputManager)

class OkdWindowsRawInputHandler
{
	friend class OkdInputManager;

public:
	void		processInput( HRAWINPUT hRawInput );

private:
				OkdWindowsRawInputHandler();
				~OkdWindowsRawInputHandler();

	void		initializeKeyMapping();
	void		enumDevices();

	void		processMouseInput( const RAWMOUSE& rawMouseInput );
	void		processKeyboardInput( const RAWKEYBOARD& rawKeyboardInput );

	OkdKeyCode	_keyMapping[256];
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif
