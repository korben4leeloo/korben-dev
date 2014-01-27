//*****************************************************************************
//
//	File:		OrkidCore.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OrkidCore.h"

#include	ORKID_CORE_H(Memory/OkdMemManager)
#include	ORKID_CORE_H(Input/OkdInputManager)

//-----------------------------------------------------------------------------
// Name:		OrkidCore constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OrkidCore::OrkidCore()
{

}

//-----------------------------------------------------------------------------
// Name:		OrkidCore destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OrkidCore::~OrkidCore()
{
	
}

//-----------------------------------------------------------------------------
// Name:		initialize
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OrkidCore::initialize()
{
	OrkidCore::uninitialize();
	OkdMemManager::create();

	OkdInputManager::create();
	OkdInputManager::instance()->initialize();
}

//-----------------------------------------------------------------------------
// Name:		uninitialize
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OrkidCore::uninitialize()
{
	OkdInputManager::destroy();
	OkdMemManager::destroy();
}
