//*****************************************************************************
//
//	File:		OkdSceneHandler.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdSceneHandler.h"

#include	ORKID_ENGINE_H(OrkidEngine)
#include	ORKID_ENGINE_H(ResourceManager/OkdResourceManager)

//-----------------------------------------------------------------------------
// Name:		OkdSceneHandler constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdSceneHandler::OkdSceneHandler()
{
	REGISTER_RESOURCE_TYPE( "SCENE", this );
}

//-----------------------------------------------------------------------------
// Name:		OkdSceneHandler destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdSceneHandler::~OkdSceneHandler()
{
	UNREGISTER_RESOURCE_TYPE( "SCENE" );
}

//-----------------------------------------------------------------------------
// Name:		load
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdSceneHandler::load(OkdSharedResource*	pResource)
{
	
}

//-----------------------------------------------------------------------------
// Name:		unload
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdSceneHandler::unload(OkdSharedResource*	pResource)
{

}
