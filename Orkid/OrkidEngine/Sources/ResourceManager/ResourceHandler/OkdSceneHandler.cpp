//*****************************************************************************
//
//	File:		OkdSceneHandler.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdSceneHandler.h"

#include	ORKID_ENGINE_H(SceneGraph/OkdScene)

//-----------------------------------------------------------------------------
// Name:		OkdSceneHandler constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdSceneHandler::OkdSceneHandler()
{

}

//-----------------------------------------------------------------------------
// Name:		OkdSceneHandler destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdSceneHandler::~OkdSceneHandler()
{
	
}

//-----------------------------------------------------------------------------
// Name:		allocateResource
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void*	OkdSceneHandler::allocateResource()
{
	OkdScene* pScene = new OkdScene();
	return	( pScene );
}

//-----------------------------------------------------------------------------
// Name:		freeResource
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdSceneHandler::freeResource(void*	pResource)
{

}

//-----------------------------------------------------------------------------
// Name:		loadResource
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdSceneHandler::loadResource(void*			pResource, 
									  const void*	pResourceData)
{

}

//-----------------------------------------------------------------------------
// Name:		unloadResource
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdSceneHandler::unloadResource(void*	pResource)
{

}

//-----------------------------------------------------------------------------
// Name:		saveResource
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdSceneHandler::saveResource(const void*	pResource, 
									  void*			pResourceData)
{

}
