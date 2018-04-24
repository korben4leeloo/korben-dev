//*****************************************************************************
//
//	Class:		QmInputManager
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __QUANTUM_CORE_TK_INPUT_MANAGER_H__
#define __QUANTUM_CORE_TK_INPUT_MANAGER_H__

#include "Root.h"
#include QUANTUM_CORE_H(Input/QmInputState)

class QmInputManager
{
public:
	QM_DECLARE_SLOT( QmInputManager, OnInputReceived, const uint64 )

					QmInputManager();
					~QmInputManager();

	void			registerDevices();
	void			enumDevices();

	uint64			onRawInput( const uint64 nRawInputHandle );

private:
	void			initWin32KeyMapper();

	TarsKeyEnum		_win32KeyMapper[256];
	QmInputState	_inputState;
};

#endif