//*****************************************************************************
//
//	File:		OkdGameplayManager.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdGameplayManager.h"

#include	ORKID_ENGINE_H(Gameplay/OkdFreeCameraGameplay)

//-----------------------------------------------------------------------------
// Name:		OkdGameplayManager constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdGameplayManager::OkdGameplayManager()
{
	OkdFreeCameraGameplayHandler::create();

	OkdFreeCameraGameplay* pGameplay = OkdFreeCameraGameplayHandler::instance()->createGameplay();
}

//-----------------------------------------------------------------------------
// Name:		OkdGameplayManager destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdGameplayManager::~OkdGameplayManager()
{

}

//-----------------------------------------------------------------------------
// Name:		update
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdGameplayManager::update()
{
	OkdFreeCameraGameplayHandler::instance()->update();
}
