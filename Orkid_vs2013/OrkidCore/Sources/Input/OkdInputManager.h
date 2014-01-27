//*****************************************************************************
//
//	Class:		OkdInputManager
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdInputManager_h__
#define __OrkidCore_OkdInputManager_h__

#include	"Root.h"

#include	ORKID_CORE_H(Containers/OkdList)
#include	ORKID_CORE_H(Input/OkdInputEvent)
#include	ORKID_CORE_H(SIngleton/OkdSingleton)

enum OkdKeyCode: uint8
{
	OkdKey_A,
	OkdKey_B,
	OkdKey_C,
	OkdKey_D,
	OkdKey_E,
	OkdKey_F,
	OkdKey_G,
	OkdKey_H,
	OkdKey_I,
	OkdKey_J,
	OkdKey_K,
	OkdKey_L,
	OkdKey_M,
	OkdKey_N,
	OkdKey_O,
	OkdKey_P,
	OkdKey_Q,
	OkdKey_R,
	OkdKey_S,
	OkdKey_T,
	OkdKey_U,
	OkdKey_V,
	OkdKey_W,
	OkdKey_X,
	OkdKey_Y,
	OkdKey_Z,

	OkdKey_0,
	OkdKey_1,
	OkdKey_2,
	OkdKey_3,
	OkdKey_4,
	OkdKey_5,
	OkdKey_6,
	OkdKey_7,
	OkdKey_8,
	OkdKey_9,

	OkdKey_NumPad0,
	OkdKey_NumPad1,
	OkdKey_NumPad2,
	OkdKey_NumPad3,
	OkdKey_NumPad4,
	OkdKey_NumPad5,
	OkdKey_NumPad6,
	OkdKey_NumPad7,
	OkdKey_NumPad8,	
	OkdKey_NumPad9,

	OkdKey_LeftShift,
	OkdKey_LeftControl,
	OkdKey_LeftAlt,

	OkdKey_RightShift,
	OkdKey_RightControl,
	OkdKey_RightAlt,

	OkdKey_F1,
	OkdKey_F2,
	OkdKey_F3,
	OkdKey_F4,
	OkdKey_F5,
	OkdKey_F6,
	OkdKey_F7,
	OkdKey_F8,
	OkdKey_F9,
	OkdKey_F10,
	OkdKey_F11,
	OkdKey_F12,

	OkdKey_Return,
	OkdKey_Space,
	OkdKey_Delete,
	OkdKey_Backspace,
	OkdKey_Tab,
	OkdKey_Escape,

	OkdKeyCount,

	OkdKey_Unknown = 0xFF
};

enum OkdInputKeyEventFlag
{
	OkdInputKeyPressed,
	OkdInputKeyReleased,
};

class OkdWindowsRawInputHandler;

class OkdInputManager: public OkdSingleton<OkdInputManager>
{
	friend class OkdSingleton<OkdInputManager>;

public:
	void						initialize();
	void						uninitialize();

	OkdWindowsRawInputHandler*	getWindowsRawInputHandler();

	void						updateKeyState( const OkdKeyCode keyCode, const bool bPressed );

private:
								OkdInputManager();
								~OkdInputManager();

	struct OkdInputState
	{
		bool					_bPressed;
		OkdList<OkdInputEvent>	_inputEvents;
	};

	OkdInputState				_keyStates[OkdKeyCount];

	OkdWindowsRawInputHandler*	_pWindowsRawInputHandler;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif
