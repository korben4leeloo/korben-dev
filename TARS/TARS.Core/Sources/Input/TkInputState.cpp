//*****************************************************************************
//
//	File:		TkInputState.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "TkInputState.h"

#include <cstring>

//-----------------------------------------------------------------------------
// Name:		TkInputState constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkInputState::TkInputState()
{
	memset( _keyParamArray, TK_KEY_STATE_UP, sizeof(_keyParamArray) );
}

//-----------------------------------------------------------------------------
// Name:		TkInputState destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkInputState::~TkInputState()
{
	
}

//-----------------------------------------------------------------------------
// Name:		setKeyState
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void TkInputState::setKeyState( const TarsKeyEnum eTarsKey, const TarsKeyStateEnum eKeyState )
{
	if	( eTarsKey != TK_KEY_INVALID )
	{
		TkKeyParam& keyParam = _keyParamArray[eTarsKey];

		keyParam._eKeyState = eKeyState;

		for	( uint32 i = 0; i < keyParam._keyStateCallbackArray.size(); i++ )
		{
			(keyParam._keyStateCallbackArray[i])( eTarsKey, eKeyState );
		}
	}
}
