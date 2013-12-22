//*****************************************************************************
//
//	File:		OkdResourceManager.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdResourceManager.h"

//#include	ORKID_ENGINE_H(Resources/Handlers/OkdMeshResourceHandler)
//#include	ORKID_ENGINE_H(Resources/Handlers/OkdSceneResourceHandler)
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
	//_resourceHandlers[OrkidMesh]	= new OkdMeshResourceHandler();
	//_resourceHandlers[OrkidScene]	= new OkdSceneResourceHandler();

	//// Must be set by the rendering API
	//_resourceHandlers[OrkidShader]			= 0;
	//_resourceHandlers[OrkidShaderProgram]	= 0;
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

//-----------------------------------------------------------------------------
// Name:		addResource
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
static OkdResourcePtr<T>	OkdResourceManager::addResource(const OkdString&	strResourceName)
{
	OkdResourceManager*			pResourceManager	= OrkidEngine::instance()->getResourceManager();
	OkdResourceKey				resourceKey			= OkdCrc32::getCrc32( strResourceName );
	OkdResourceType				eResourceType		= T::getResourceType();
	OkdResourceMap::iterator	itResource			= pResourceManager->_resourceMapArray[eResourceType].add( resourceKey, 0 );

	if	( itResource->second == 0 )
	{
		T* pResource = new T();

		pResource->_resourceKey		= resourceKey;
		pResource->_strResourceName	= strResourceName;

		itResource->second = pResource;
	}

	OkdResourcePtr<T> resourcePtr( static_cast<T*>(itResource->second) );

	return	( resourcePtr );
}

//-----------------------------------------------------------------------------
// Name:		removeResource
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
bool	OkdResourceManager::removeResource(const T*	pResource)
{
	OkdResourceManager*	pResourceManager	= OrkidEngine::instance()->getResourceManager();
	OkdResourceType		eResourceType		= T::getResourceType();
	uint32				uiCount				= pResourceManager->_resourceMapArray[eResourceType].remove( pResource->getResourceKey() );

	ORKID_ASSERT( uiCount == 1 );
	delete pResource;

	return	( uiCount > 0 );
}