//*****************************************************************************
//
//	File:		OkdResourceManager.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdResourceManager.h"

//#include	ORKID_CORE_H(String/OkdCrc32)
#include	ORKID_ENGINE_H(ResourceManager/ResourceHandler/OkdMeshHandler)
#include	ORKID_ENGINE_H(ResourceManager/ResourceHandler/OkdSceneHandler)

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
	// Register resource handlers
	_resourceMapArray[OrkidMesh]._pResourceHandler	= new OkdMeshHandler();
	_resourceMapArray[OrkidScene]._pResourceHandler	= new OkdSceneHandler();
}

////-----------------------------------------------------------------------------
//// Name:		registerResourceType
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//void	OkdResourceManager::registerResourceType(const OkdAbstractResourceHandler*	pResourceHandler)
//{
//	const OkdString&	strResourceTypeName	= pResourceHandler->getResourceTypeName();
//	uint32				uiResourceTypeId	= getResourceTypeId( strResourceTypeName );
//
//	ORKID_ASSERT( _resourceHandlerArray[pResourceHandler->getResourceType()] == 0 );
//
//	_resourceHandlerMap.add( uiResourceTypeId, pResourceHandler );
//	_resourceHandlerArray[pResourceHandler->getResourceType()] = pResourceHandler;
//}
//
////-----------------------------------------------------------------------------
//// Name:		unregisterResourceType
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//void	OkdResourceManager::unregisterResourceType(const OkdAbstractResourceHandler*	pResourceHandler)
//{
//	const OkdString&	strResourceTypeName	= pResourceHandler->getResourceTypeName();
//	uint32				uiResourceTypeId	= getResourceTypeId( strResourceTypeName );
//
//	ORKID_ASSERT( _resourceHandlerArray[pResourceHandler->getResourceType()] != 0 );
//
//	_resourceHandlerMap.remove( uiResourceTypeId );
//	_resourceHandlerArray[pResourceHandler->getResourceType()] = 0;
//}

//-----------------------------------------------------------------------------
// Name:		createResource
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourcePtr	OkdResourceManager::createResource(const OkdResourceId&	resourceId)
{
	OkdResourceMap*				pResourceMap		= getResourceMap( resourceId.getResourceType() );
	OkdAbstractResourceHandler*	pResourceHandler	= pResourceMap->_pResourceHandler;
	void*						pResourceData		= pResourceHandler->allocateResource();
	OkdResourceHandle*			pResourceHandle		= new OkdResourceHandle( resourceId, pResourceData );
	OkdResourcePtr				resourcePtr( pResourceHandle );

	pResourceMap->_resourceHandleMap.add( resourceId.getResourceName(), pResourceHandle );

	return	( resourcePtr );
}

////-----------------------------------------------------------------------------
//// Name:		createResource
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//OkdResourcePtr	OkdResourceManager::createResource(const OrkidResourceType	eResourceType, 
//												   const OkdString&			strResourceName)
//{
//	OkdResourceHandle*	pResourceHandle = new OkdResourceHandle( resourceId );
//	OkdResourcePtr	resourcePtr( pResourceHandle );
//
//	ORKID_ASSERT( ( resourceId.getResourceType() >= (OrkidResourceType)0 ) && ( resourceId.getResourceType() < OrkidResourceTypeLast ) );
//
//	if	( resourceId.getResourceId() == 0 )
//	{
//
//	}
//	else if	( resourceId.getResourceId() > 0 )
//	{
//
//	}
//	else
//	{
//
//	}
//
//	return	( resourcePtr );
//}

////-----------------------------------------------------------------------------
//// Name:		getResourceTypeId
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//uint32	OkdResourceManager::getResourceTypeId(const OkdString&	strResourceTypeName)
//{
//	uint32 uiCrc32 = OkdCrc32::getCrc32( strResourceTypeName );
//	return	( uiCrc32 );
//}

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
