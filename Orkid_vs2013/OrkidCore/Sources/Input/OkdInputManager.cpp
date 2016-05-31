//*****************************************************************************
//
//	File:		OkdInputManager.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdInputManager.h"

#include	ORKID_CORE_H(Input/Windows/OkdWindowsRawInputHandler)

//-----------------------------------------------------------------------------
// Name:		OkdInputManager constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdInputManager::OkdInputManager()
: _pWindowsRawInputHandler( 0 )
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdInputManager destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdInputManager::~OkdInputManager()
{
	uninitialize();
}

//-----------------------------------------------------------------------------
// Name:		initialize
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdInputManager::initialize()
{
	_pWindowsRawInputHandler = new OkdWindowsRawInputHandler();
}

//-----------------------------------------------------------------------------
// Name:		uninitialize
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdInputManager::uninitialize()
{
	delete _pWindowsRawInputHandler;
	_pWindowsRawInputHandler = 0;
}

//-----------------------------------------------------------------------------
// Name:		getWindowsRawInputHandler
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdWindowsRawInputHandler*	OkdInputManager::getWindowsRawInputHandler()
{
	return	( _pWindowsRawInputHandler );
}

//-----------------------------------------------------------------------------
// Name:		updateKeyState
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdInputManager::updateKeyState(const OkdKeyCode	keyCode, 
										const bool			bPressed)
{
	_keyStates[keyCode]._bPressed = bPressed;
}
