//*****************************************************************************
//
//	File:		OkdResourceManager.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdResourceManager.h"

//#include	ORKID_CORE_H(String/OkdCrc32)
#include	ORKID_ENGINE_H(ResourceManager/OkdResourceMap)
#include	ORKID_ENGINE_H(ResourceManager/ResourceHandler/OkdMeshHandler)
#include	ORKID_ENGINE_H(ResourceManager/ResourceHandler/OkdSceneHandler)

class OkdMesh;
class OkdScene;

typedef OkdBaseResourceManager<OkdMesh, OrkidMesh> OkdMeshResourceManager;

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
	// Create resource maps
	_resourceMapArray[OrkidMesh]	= new OkdResourceMap( new OkdMeshHandler() );
	_resourceMapArray[OrkidScene]	= new OkdResourceMap( new OkdSceneHandler() );

	OkdEngineResourceManager resMng;

	//OkdBaseResourceManager<OkdMesh>* pMeshMng = new OkdBaseResourceManager<OkdMesh>();
	resMng._resourceManagers[OrkidMesh] = new OkdMeshResourceManager();
	resMng._resourceManagers[OrkidScene] = new OkdBaseResourceManager<OkdScene, OrkidScene>();

	/*OkdBaseResourceManager<OkdMesh>* pMeshMng = dynamic_cast<OkdBaseResourceManager<OkdMesh>*>(resMng._resourceManagers[OrkidScene]);
	OkdResourcePtr<OkdMesh> meshPtr = pMeshMng->createResource( "test" );*/

	/*OkdMeshResourceManager* pMeshMng = (OkdMeshResourceManager*)resMng._resourceManagers[OrkidScene];*/
	OkdMeshResourceManager* pMeshMng = (OkdMeshResourceManager*)resMng._resourceManagers[OrkidMesh];
	ORKID_ASSERT( pMeshMng->_resType == OrkidMesh );
}

////-----------------------------------------------------------------------------
//// Name:		createResource
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//OkdResourcePtr	OkdResourceManager::createResource(const OkdResourceId&	resourceId)
//{
//	OkdResourceMap*				pResourceMap		= getResourceMap( resourceId.getResourceType() );
//	OkdAbstractResourceHandler*	pResourceHandler	= pResourceMap->_pResourceHandler;
//	void*						pResourceData		= pResourceHandler->allocateResource();
//	OkdResourceHandle*			pResourceHandle		= new OkdResourceHandle( resourceId, pResourceData );
//	OkdResourcePtr				resourcePtr( pResourceHandle );
//
//	pResourceMap->_resourceHandleMap.add( resourceId.getResourceName(), pResourceHandle );
//
//	return	( resourcePtr );
//}
//
////-----------------------------------------------------------------------------
//// Name:		deleteResource
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//void	OkdResourceManager::deleteResource(const OkdResourceId&	resourceId)
//{
//	OkdResourceMap*				pResourceMap		= getResourceMap( resourceId.getResourceType() );
//	OkdAbstractResourceHandler*	pResourceHandler	= pResourceMap->_pResourceHandler;
//	OkdResourceHandle*			pResourceHandle		= pResourceMap->_resourceHandleMap.find( resourceId.getResourceName() );
//
//	pResourceHandler->freeResource( pResourceHandle->_pData );
//
//	delete pResourceHandle;
//
//	return	( resourcePtr );
//}

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
