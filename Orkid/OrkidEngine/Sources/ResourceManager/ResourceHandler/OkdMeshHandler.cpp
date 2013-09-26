//*****************************************************************************
//
//	File:		OkdMeshHandler.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdMeshHandler.h"

#include	ORKID_ENGINE_H(OrkidEngine)
#include	ORKID_ENGINE_H(ResourceManager/OkdResourceManager)

//-----------------------------------------------------------------------------
// Name:		OkdMeshHandler constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdMeshHandler::OkdMeshHandler()
{
	REGISTER_RESOURCE_TYPE( "MESH", this );
}

//-----------------------------------------------------------------------------
// Name:		OkdMeshHandler destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdMeshHandler::~OkdMeshHandler()
{
	UNREGISTER_RESOURCE_TYPE( "MESH" );
}

//-----------------------------------------------------------------------------
// Name:		load
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdMeshHandler::load(OkdSharedResource*	pResource)
{
	
}

//-----------------------------------------------------------------------------
// Name:		unload
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdMeshHandler::unload(OkdSharedResource*	pResource)
{

}
