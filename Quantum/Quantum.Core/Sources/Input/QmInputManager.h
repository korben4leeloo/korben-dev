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

typedef struct tagRAWINPUT RAWINPUT;

class QmInputManager
{
public:
	QM_DECLARE_SLOT( QmInputManager, OnInputReceived, RAWINPUT* )

					QmInputManager();
					~QmInputManager();

	void			registerDevices();
	void			enumDevices();

	void			onRawInput( RAWINPUT* pRawInput );

private:
	void			initWin32KeyMapper();

	TarsKeyEnum		_win32KeyMapper[256];
	QmInputState	_inputState;
};

#endif