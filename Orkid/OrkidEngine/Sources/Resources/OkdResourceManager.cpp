//*****************************************************************************
//
//	File:		OkdResourceManager.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdResourceManager.h"

#include	ORKID_ENGINE_H(Resources/OkdResourcePtr)
#include	ORKID_CORE_H(String/OkdCrc32)
#include	ORKID_ENGINE_H(Entities/OkdMesh)
#include	ORKID_ENGINE_H(SceneGraph/OkdScene)
#include	ORKID_ENGINE_H(Shaders/OkdAbstractShader)

//-----------------------------------------------------------------------------
// Name:		OkdResourceManager constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourceManager::OkdResourceManager()
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdResourceManager destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourceManager::~OkdResourceManager()
{
	//clearResources();
}

//-----------------------------------------------------------------------------
// Name:		initialize
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdResourceManager::initialize()
{

}

////-----------------------------------------------------------------------------
//// Name:		clearResources
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//void	OkdResourceManager::clearResources()
//{
//	/*for	( uint i = 0; i < _vMeshArray.size(); i++ )
//	{
//		const OkdMeshResource& meshResource = _vMeshArray[i];
//		ORKID_ASSERT( meshResource.getRefCount() == 1 );
//	}*/
//
//	for	( uint i = 0; i < _vMeshArray.size(); i++ )
//	{
//		const OkdMeshResourcePtr& meshResourcePtr = _vMeshArray[i];
//		ORKID_ASSERT( meshResourcePtr.getRefCount() == 1 );
//		ORKID_ASSERT( meshResourcePtr.getLoadRefCount() == 0 );
//	}
//}

//-----------------------------------------------------------------------------
// Name:		addMesh
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdMeshPtr	OkdResourceManager::addMesh(const OkdString&	strResourceName)
{
	return	( addResource<OkdMesh>( strResourceName ) );
}

//-----------------------------------------------------------------------------
// Name:		addScene
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdScenePtr	OkdResourceManager::addScene(const OkdString&	strResourceName)
{
	return	( addResource<OkdScene>( strResourceName ) );
}
