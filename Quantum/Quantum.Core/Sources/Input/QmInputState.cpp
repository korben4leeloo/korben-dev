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
	memset( _keyParamArray, QmKeyStateUp, sizeof(_keyParamArray) );
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
void QmInputState::setKeyState( const QuantumKey eQuantumKey, const QuantumKeyState eKeyState )
{
	if	( eQuantumKey != QuantumKeyInvalid )
	{
		QmKeyParam& keyParam = _keyParamArray[eQuantumKey];

		keyParam._eKeyState = eKeyState;

		for	( uint32 i = 0; i < keyParam._keyStateCallbackArray.size(); i++ )
		{
			(keyParam._keyStateCallbackArray[i])( eQuantumKey, eKeyState );
		}
	}
}
