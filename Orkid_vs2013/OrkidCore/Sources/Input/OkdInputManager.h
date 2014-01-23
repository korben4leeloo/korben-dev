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

enum OkdKeyCode
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

	OkdKey_Num0,
	OkdKey_Num1,
	OkdKey_Num2,
	OkdKey_Num3,
	OkdKey_Num4,
	OkdKey_Num5,
	OkdKey_Num6,
	OkdKey_Num7,
	OkdKey_Num8,
	OkdKey_Num9,

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

	OkdKey_Enter,
	OkdKey_Space,
	OkdKey_Delete,
	OkdKey_Backspace,
	OkdKey_Tab,
	OkdKey_Escape,

	OkdKeyCount
};

enum OkdInputFlag
{
	OkdInputPressed,
	OkdInputReleased,
	OkdInputClick,
	OkdInputDoubleClick,
};

class OkdInputManager
{
public:
					OkdInputManager();
					~OkdInputManager();

private:
	struct OkdInputState
	{

	};

	OkdInputState	_inputStates[OkdKeyCount];
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

////-----------------------------------------------------------------------------
//// Name:		size
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//uint32 OkdInputManager::size() const
//{
//	return	( _str.size() );
//}

#endif
