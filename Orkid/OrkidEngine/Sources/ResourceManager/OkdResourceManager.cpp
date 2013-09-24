//*****************************************************************************
//
//	File:		OkdResourceManager.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdResourceManager.h"

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

////-----------------------------------------------------------------------------
//// Name:		addMesh
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//OkdMeshResource	OkdResourceManager::addMesh(const OkdString&		strMeshName, 
//											const OkdString&		strMeshLocationName, 
//											const ResourceLocation	eResourceLocation)
//{
//	OkdMesh*		pMesh = new OkdMesh();
//	OkdMeshResource	meshResource( strMeshName, strMeshLocationName, eResourceLocation, pMesh );
//
//	_vMeshArray.add( meshResource );
//	return	( meshResource );
//}

////-----------------------------------------------------------------------------
//// Name:		addMesh
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//OkdMeshResourcePtr	OkdResourceManager::addMesh(const OkdString&		strMeshName, 
//												const OkdString&		strMeshLocationName, 
//												const ResourceLocation	eResourceLocation)
//{
//	OkdMesh*			pMesh			= new OkdMesh();
//	OkdMeshResource*	pMeshResource	= new OkdMeshResource( strMeshName, strMeshLocationName, eResourceLocation, pMesh );
//	OkdMeshResourcePtr	meshResourcePtr( pMeshResource );
//
//	_vMeshArray.add( meshResourcePtr );
//	return	( meshResourcePtr );
//}
//
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
