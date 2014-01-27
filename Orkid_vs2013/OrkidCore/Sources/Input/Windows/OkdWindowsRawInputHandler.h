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
	void		process( HRAWINPUT hRawInput );

private:
				OkdWindowsRawInputHandler();
				~OkdWindowsRawInputHandler();

	void		initializeKeyMapping();
	void		initializeDevices();

	OkdKeyCode	_keyMapping[256];
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif
