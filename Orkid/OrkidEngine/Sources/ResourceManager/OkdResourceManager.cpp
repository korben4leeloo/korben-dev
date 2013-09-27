//*****************************************************************************
//
//	File:		OkdResourceManager.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdResourceManager.h"

#include	ORKID_CORE_H(String/OkdCrc32)

//-----------------------------------------------------------------------------
// Name:		OkdResourceManager constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourceManager::OkdResourceManager()
{
	memset( _resourceHandlerArray, 0, sizeof(_resourceHandlerArray) );
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
// Name:		registerResourceType
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdResourceManager::registerResourceType(const OkdAbstractResourceHandler*	pResourceHandler)
{
	const OkdString&	strResourceTypeName	= pResourceHandler->getResourceTypeName();
	uint32				uiResourceTypeId	= getResourceTypeId( strResourceTypeName );

	ORKID_ASSERT( _resourceHandlerArray[pResourceHandler->getResourceType()] == 0 );

	_resourceHandlerMap.add( uiResourceTypeId, pResourceHandler );
	_resourceHandlerArray[pResourceHandler->getResourceType()] = pResourceHandler;
}

//-----------------------------------------------------------------------------
// Name:		unregisterResourceType
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdResourceManager::unregisterResourceType(const OkdAbstractResourceHandler*	pResourceHandler)
{
	const OkdString&	strResourceTypeName	= pResourceHandler->getResourceTypeName();
	uint32				uiResourceTypeId	= getResourceTypeId( strResourceTypeName );

	ORKID_ASSERT( _resourceHandlerArray[pResourceHandler->getResourceType()] != 0 );

	_resourceHandlerMap.remove( uiResourceTypeId );
	_resourceHandlerArray[pResourceHandler->getResourceType()] = 0;
}

//-----------------------------------------------------------------------------
// Name:		addResource
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdSharedResourcePtr	OkdResourceManager::addResource(const OkdResourceIdentifier&	resourceIdentifier)
{
	OkdSharedResource*		pSharedResource = new OkdSharedResource( resourceIdentifier );
	OkdSharedResourcePtr	resourcePtr( pSharedResource );

	ORKID_ASSERT( ( resourceIdentifier.getResourceType() >= (OrkidResourceType)0 ) && ( resourceIdentifier.getResourceType() < OrkidResourceTypeLast ) );

	if	( resourceIdentifier.getResourceId() == 0 )
	{

	}
	else if	( resourceIdentifier.getResourceId() > 0 )
	{

	}
	else
	{

	}

	return	( resourcePtr );
}

//-----------------------------------------------------------------------------
// Name:		getResourceTypeId
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
uint32	OkdResourceManager::getResourceTypeId(const OkdString&	strResourceTypeName)
{
	uint32 uiCrc32 = OkdCrc32::getCrc32( strResourceTypeName );
	return	( uiCrc32 );
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
