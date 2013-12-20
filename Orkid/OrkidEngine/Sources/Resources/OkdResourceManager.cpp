//*****************************************************************************
//
//	File:		OkdResourceManager.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdResourceManager.h"

#include	ORKID_ENGINE_H(Resources/Handlers/OkdMeshResourceHandler)
#include	ORKID_ENGINE_H(Resources/Handlers/OkdSceneResourceHandler)

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
	_resourceHandlers[OrkidMesh]	= new OkdMeshResourceHandler();
	_resourceHandlers[OrkidScene]	= new OkdSceneResourceHandler();

	// Must be set by the rendering API
	_resourceHandlers[OrkidShader]			= 0;
	_resourceHandlers[OrkidShaderProgram]	= 0;
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
	/*OkdResourceManager*			pResourceManager	= OrkidEngine::instance()->getResourceManager();
	OkdResourceKey				resourceKey			= OkdCrc32::getCrc32( strResourceName );
	OkdResourceMap::iterator	itResource			= pResourceManager->_resourceMapArray[OrkidMesh].add( resourceKey, 0 );
	OkdMeshPtr					meshPtr;

	if	( itResource->second == 0 )
	{
		OkdMesh* pResource = new OkdMesh();

		pResource->_resourceKey		= resourceKey;
		pResource->_strResourceName	= strResourceName;

		itResource->second = pResource;
	}

	meshPtr._pResource = static_cast<OkdMesh*>(itResource->second);

	return	( meshPtr );*/

	return	( addResource<OkdMesh>( OrkidMesh, strResourceName ) );
}
