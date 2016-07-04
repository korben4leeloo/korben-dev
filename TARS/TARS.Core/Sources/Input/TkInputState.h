//*****************************************************************************
//
//	Class:		TkInputState
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_CORE_TK_INPUT_STATE_H__
#define __TARS_CORE_TK_INPUT_STATE_H__

#include "Root.h"

enum TARS_KEY
{
	TK_KEY_A,
	TK_KEY_B,
	TK_KEY_C,
	TK_KEY_D,
	TK_KEY_E,
	TK_KEY_F,
	TK_KEY_G,
	TK_KEY_H,
	TK_KEY_I,
	TK_KEY_J,
	TK_KEY_K,
	TK_KEY_L,
	TK_KEY_M,
	TK_KEY_N,
	TK_KEY_O,
	TK_KEY_P,
	TK_KEY_Q,
	TK_KEY_R,
	TK_KEY_S,
	TK_KEY_T,
	TK_KEY_U,
	TK_KEY_V,
	TK_KEY_W,
	TK_KEY_X,
	TK_KEY_Y,
	TK_KEY_Z,

	TK_KEY_0,
	TK_KEY_1,
	TK_KEY_2,
	TK_KEY_3,
	TK_KEY_4,
	TK_KEY_5,
	TK_KEY_6,
	TK_KEY_7,
	TK_KEY_8,
	TK_KEY_9,

	TK_KEY_NUMPAD_0,
	TK_KEY_NUMPAD_1,
	TK_KEY_NUMPAD_2,
	TK_KEY_NUMPAD_3,
	TK_KEY_NUMPAD_4,
	TK_KEY_NUMPAD_5,
	TK_KEY_NUMPAD_6,
	TK_KEY_NUMPAD_7,
	TK_KEY_NUMPAD_8,
	TK_KEY_NUMPAD_9,

	TK_KEY_NUMPAD_ADD,
	TK_KEY_NUMPAD_SUBSTRACT,

	TK_KEY_RETURN,
	TK_KEY_ESCAPE,
	TK_KEY_SPACE,
	TK_KEY_BACKSPACE,
	TK_KEY_DELETE,
	TK_KEY_PAGE_UP,
	TK_KEY_PAGE_DOWN,
	TK_KEY_HOME,
	TK_KEY_END,
	TK_KEY_INSERT,

	TK_KEY_LSHIFT,
	TK_KEY_RSHIFT,
	TK_KEY_LCTRL,
	TK_KEY_RCTRL,

	TK_KEY_F1,
	TK_KEY_F2,
	TK_KEY_F3,
	TK_KEY_F4,
	TK_KEY_F5,
	TK_KEY_F6,
	TK_KEY_F7,
	TK_KEY_F8,
	TK_KEY_F9,
	TK_KEY_F10,
	TK_KEY_F11,
	TK_KEY_F12,

	TK_KEY_COUNT,

	TK_KEY_INVALID = 0xFFFFFFFF
};

enum TARS_KEY_STATE
{
	TK_KEY_STATE_UP,
	TK_KEY_STATE_DOWN
};

class TkInputState
{
public:
					TkInputState();
					~TkInputState();

	inline void		setKeyState( const TARS_KEY eTarsKey, const TARS_KEY_STATE eKeyState );

private:
	TARS_KEY_STATE	_keyState[TK_KEY_COUNT];
};

//-----------------------------------------------------------------------------
// Name:		setKeyState
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void TkInputState::setKeyState( const TARS_KEY eTarsKey, const TARS_KEY_STATE eKeyState )
{
	if	( eTarsKey != TK_KEY_INVALID )
	{
		_keyState[eTarsKey] = eKeyState;
	}
}

#endif