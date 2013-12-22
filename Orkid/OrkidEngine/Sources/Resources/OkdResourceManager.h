//*****************************************************************************
//
//	Class:		OkdResourceManager
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdResourceManager_h__
#define __OrkidEngine_OkdResourceManager_h__

#include	"Root.h"

//class OkdAbstractResourceHandler;

//#include	ORKID_ENGINE_H(Resources/OkdResourcePtr)
//#include	ORKID_ENGINE_H(Entities/OkdMesh)
#include	ORKID_CORE_H(Containers/OkdMap)
#include	ORKID_CORE_H(String/OkdString)

class OkdAbstractResource;

typedef OkdMap<OkdResourceKey, OkdAbstractResource*> OkdResourceMap;

template<class T> class OkdResourcePtr;

class OkdMesh;
class OkdScene;
class OkdAbstractShader;

typedef OkdResourcePtr<OkdMesh>				OkdMeshPtr;
typedef OkdResourcePtr<OkdScene>			OkdScenePtr;
typedef OkdResourcePtr<OkdAbstractShader>	OkdShaderPtr;

class OkdResourceManager
{
public:
	friend class OrkidEngine;
	friend class OkdOpenGL_API;
	template<class T> friend class OkdResourcePtr;

	//inline OkdAbstractResourceHandler*	getResourceHandler( const OkdResourceType eResourceType );

	static OkdMeshPtr					addMesh( const OkdString& strResourceName );
	static OkdScenePtr					addScene( const OkdString& strResourceName );

	/*static OkdShaderPtr					addVertexShader( const OkdString& strResourceName );
	static OkdShaderPtr					addFragmentShader( const OkdString& strResourceName );
	static OkdShaderPtr					addGeometryShader( const OkdString& strResourceName );*/

private:
										OkdResourceManager();
										~OkdResourceManager();

	//inline void							setResourceHandler( const OkdResourceType eResourceType, OkdAbstractResourceHandler* pResourceHandler );

	void								initialize();

	template<class T>
	static OkdResourcePtr<T>			addResource( const OkdString& strResourceName );

	template<class T>
	static bool							removeResource( const T* pResource );

	//OkdAbstractResourceHandler*			_resourceHandlers[OrkidResourceTypeCount];
	OkdResourceMap						_resourceMapArray[OrkidResourceTypeCount];
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

////-----------------------------------------------------------------------------
//// Name:		setResourceHandler
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//void	OkdResourceManager::setResourceHandler(const OkdResourceType		eResourceType, 
//											   OkdAbstractResourceHandler*	pResourceHandler)
//{
//	_resourceHandlers[eResourceType] = pResourceHandler;
//}
//
////-----------------------------------------------------------------------------
//// Name:		getResourceHandler
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//OkdAbstractResourceHandler*	OkdResourceManager::getResourceHandler(const OkdResourceType	eResourceType)
//{
//	return	( _resourceHandlers[eResourceType] );
//}

////-----------------------------------------------------------------------------
//// Name:		addResource
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T>
//static OkdResourcePtr<T>	OkdResourceManager::addResource(const OkdString&	strResourceName)
//{
//	OkdResourceManager*			pResourceManager	= OrkidEngine::instance()->getResourceManager();
//	OkdResourceKey				resourceKey			= OkdCrc32::getCrc32( strResourceName );
//	OkdResourceType				eResourceType		= T::getResourceType();
//	OkdResourceMap::iterator	itResource			= pResourceManager->_resourceMapArray[eResourceType].add( resourceKey, 0 );
//
//	if	( itResource->second == 0 )
//	{
//		T* pResource = new T();
//
//		pResource->_resourceKey		= resourceKey;
//		pResource->_strResourceName	= strResourceName;
//
//		itResource->second = pResource;
//	}
//
//	OkdResourcePtr<T> resourcePtr( static_cast<T*>(itResource->second) );
//
//	return	( resourcePtr );
//}
//
////-----------------------------------------------------------------------------
//// Name:		removeResource
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T>
//bool	OkdResourceManager::removeResource(const T*	pResource)
//{
//	OkdResourceManager*	pResourceManager	= OrkidEngine::instance()->getResourceManager();
//	OkdResourceType		eResourceType		= T::getResourceType();
//	uint32				uiCount				= pResourceManager->_resourceMapArray[eResourceType].remove( pResource->getResourceKey() );
//
//	ORKID_ASSERT( uiCount == 1 );
//	delete pResource;
//
//	return	( uiCount > 0 );
//}

#endif