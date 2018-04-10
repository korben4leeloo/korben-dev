//*****************************************************************************
//
//	File:		QmInputState.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "QmInputState.h"

#include <cstring>

//-----------------------------------------------------------------------------
// Name:		QmInputState constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmInputState::QmInputState()
{
	memset( _keyParamArray, TK_KEY_STATE_UP, sizeof(_keyParamArray) );
}

//-----------------------------------------------------------------------------
// Name:		QmInputState destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmInputState::~QmInputState()
{

}

//-----------------------------------------------------------------------------
// Name:		setKeyState
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void QmInputState::setKeyState( const TarsKeyEnum eTarsKey, const TarsKeyStateEnum eKeyState )
{
	if	( eTarsKey != TK_KEY_INVALID )
	{
		QmKeyParam& keyParam = _keyParamArray[eTarsKey];

		keyParam._eKeyState = eKeyState;

		for	( uint32 i = 0; i < keyParam._keyStateCallbackArray.size(); i++ )
		{
			(keyParam._keyStateCallbackArray[i])( eTarsKey, eKeyState );
		}
	}
}
