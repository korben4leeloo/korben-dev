//*****************************************************************************
//
//	Class:		QmInputState
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __QUANTUM_CORE_INPUT_STATE_H__
#define __QUANTUM_CORE_INPUT_STATE_H__

#include "Root.h"

#include QUANTUM_CORE_H(Containers/QmVector)

enum QuantumKey
{
	QmKey_A,
	QmKey_B,
	QmKey_C,
	QmKey_D,
	QmKey_E,
	QmKey_F,
	QmKey_G,
	QmKey_H,
	QmKey_I,
	QmKey_J,
	QmKey_K,
	QmKey_L,
	QmKey_M,
	QmKey_N,
	QmKey_O,
	QmKey_P,
	QmKey_Q,
	QmKey_R,
	QmKey_S,
	QmKey_T,
	QmKey_U,
	QmKey_V,
	QmKey_W,
	QmKey_X,
	QmKey_Y,
	QmKey_Z,

	QmKey_0,
	QmKey_1,
	QmKey_2,
	QmKey_3,
	QmKey_4,
	QmKey_5,
	QmKey_6,
	QmKey_7,
	QmKey_8,
	QmKey_9,

	QmKey_Numpad0,
	QmKey_Numpad1,
	QmKey_Numpad2,
	QmKey_Numpad3,
	QmKey_Numpad4,
	QmKey_Numpad5,
	QmKey_Numpad6,
	QmKey_Numpad7,
	QmKey_Numpad8,
	QmKey_Numpad9,

	QmKey_NumpadAdd,
	QmKey_NumpadSubstract,

	QmKey_Return,
	QmKey_Escape,
	QmKey_Space,
	QmKey_Backspace,
	QmKey_Delete,
	QmKey_PageUp,
	QmKey_PageDown,
	QmKey_Home,
	QmKey_End,
	QmKey_Insert,

	QmKey_LeftShift,
	QmKey_RightShift,
	QmKey_LeftControl,
	QmKey_RightControl,

	QmKey_F1,
	QmKey_F2,
	QmKey_F3,
	QmKey_F4,
	QmKey_F5,
	QmKey_F6,
	QmKey_F7,
	QmKey_F8,
	QmKey_F9,
	QmKey_F10,
	QmKey_F11,
	QmKey_F12,

	QuantumKeyCount,

	QuantumKeyInvalid = 0xFFFFFFFF
};

enum QuantumKeyState
{
	QmKeyStateUp,
	QmKeyStateDown
};

struct QmKeyParam
{
	typedef void (*KeyStateChangedCallback)( const QuantumKey eQuantumKey, const QuantumKeyState eKeyState );

	QuantumKeyState						_eKeyState;
	QmVector<KeyStateChangedCallback>	_keyStateCallbackArray;
};

class QmInputState
{
public:
				QmInputState();
				~QmInputState();

	void		setKeyState( const QuantumKey eQuantumKey, const QuantumKeyState eKeyState );

private:
	QmKeyParam	_keyParamArray[QuantumKeyCount];
};

#endif
