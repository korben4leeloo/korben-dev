//*****************************************************************************
//
//	File:		OkdGameplayManager.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdGameplayManager.h"

//-----------------------------------------------------------------------------
// Name:		OkdGameplayManager constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdGameplayManager::OkdGameplayManager()
{
	OkdFreeCameraGameplay* pGameplay = createGameplay<OkdFreeCameraGameplay>(OkdGameplayTypeFreeCamera);
}

//-----------------------------------------------------------------------------
// Name:		OkdGameplayManager destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdGameplayManager::~OkdGameplayManager()
{

}
