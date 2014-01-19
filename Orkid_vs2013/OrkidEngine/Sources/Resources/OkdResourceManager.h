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

//#include	ORKID_CORE_H(Containers/OkdMap)
#include	ORKID_CORE_H(String/OkdString)
#include	ORKID_CORE_H(String/OkdCrc32)
#include	ORKID_ENGINE_H(Resources/OkdResourceMap)
#include	ORKID_ENGINE_H(Resources/Allocators/OkdDefaultResourceAllocator)

//class OkdAbstractResource;

//typedef OkdMap<OkdResourceKey, OkdAbstractResource*> OkdResourceMap;

//template<class T> class OkdResourcePtr;
//
//class OkdMesh;
//class OkdScene;
//class OkdAbstractShader;
//
////typedef OkdResourcePtr<OkdMesh>				OkdMeshPtr;
////typedef OkdResourcePtr<OkdScene>			OkdScenePtr;
////typedef OkdResourcePtr<OkdAbstractShader>	OkdShaderPtr;
//
//typedef OkdMap<OkdResourceKey, OkdMesh*> OkdMeshResourceMap;
//typedef OkdMap<OkdResourceKey, OkdScene*> OkdSceneResourceMap;
//typedef OkdMap<OkdResourceKey, OkdAbstractShader*> OkdShaderResourceMap;
//
//typedef std::tuple<
//	OkdMeshResourceMap,
//	OkdSceneResourceMap,
//	OkdShaderResourceMap
//> OkdResourceMapArray;

class OkdMesh;
class OkdScene;
class OkdAbstractShaderProgram;

//template<class T, class AllocatorType> class OkdResourceMap;
////template<class T> class OkdResourceMap;
//template<OkdResourceType ResourceType> class OkdAbstractShader;
//template<class T> class OkdDefaultResourceAllocator;
//
////typedef OkdAbstractShader<OrkidVertexShader>	OkdAbstractVertexShader;
//class OkdAbstractVertexShader;
//typedef OkdAbstractShader<OrkidFragmentShader>	OkdAbstractFragmentShader;
//typedef OkdAbstractShader<OrkidGeometryShader>	OkdAbstractGeometryShader;
//
//typedef OkdDefaultResourceAllocator<OkdMesh>			OkdMeshAllocator;
//typedef OkdDefaultResourceAllocator<OkdScene>			OkdSceneAllocator;
//typedef OkdResourceAllocator<OkdAbstractVertexShader>	OkdVertexShaderAllocator;
//typedef OkdResourceAllocator<OkdAbstractFragmentShader>	OkdFragmentShaderAllocator;
//typedef OkdResourceAllocator<OkdAbstractGeometryShader>	OkdGeometryShaderAllocator;
//typedef OkdResourceAllocator<OkdAbstractShaderProgram>	OkdShaderProgramAllocator;
//
//typedef OkdResourceMap<OkdMesh, OkdMeshAllocator>								OkdMeshResourceMap;
//typedef OkdResourceMap<OkdScene, OkdSceneAllocator>								OkdSceneResourceMap;
//typedef OkdResourceMap<OkdAbstractVertexShader, OkdVertexShaderAllocator>		OkdVertexShaderResourceMap;
//typedef OkdResourceMap<OkdAbstractFragmentShader, OkdFragmentShaderAllocator>	OkdFragmentShaderResourceMap;
//typedef OkdResourceMap<OkdAbstractGeometryShader, OkdGeometryShaderAllocator>	OkdGeometryShaderResourceMap;
//typedef OkdResourceMap<OkdAbstractShaderProgram, OkdShaderProgramAllocator>		OkdShaderProgramResourceMap;

template<class T> class OkdResourceMap;
template<OkdResourceType ResourceType> class OkdAbstractShader;

typedef OkdAbstractShader<OrkidVertexShader>	OkdAbstractVertexShader;
typedef OkdAbstractShader<OrkidFragmentShader>	OkdAbstractFragmentShader;
typedef OkdAbstractShader<OrkidGeometryShader>	OkdAbstractGeometryShader;

typedef OkdDefaultResourceMap<OkdMesh>				OkdMeshResourceMap;
typedef OkdResourceMap<OkdScene>					OkdSceneResourceMap;
typedef OkdResourceMap<OkdAbstractVertexShader>		OkdVertexShaderResourceMap;
typedef OkdResourceMap<OkdAbstractFragmentShader>	OkdFragmentShaderResourceMap;
typedef OkdResourceMap<OkdAbstractGeometryShader>	OkdGeometryShaderResourceMap;
typedef OkdResourceMap<OkdAbstractShaderProgram>	OkdShaderProgramResourceMap;

typedef std::tuple<
	OkdMeshResourceMap,
	OkdSceneResourceMap,
	OkdVertexShaderResourceMap,
	OkdFragmentShaderResourceMap,
	OkdGeometryShaderResourceMap,
	OkdShaderProgramResourceMap
> OkdResourceMapArray;

class OkdResourceManager
{
public:
	friend class OrkidEngine;
	friend class OkdOpenGL_API;
	template<class T> friend class OkdResourcePtr;

	/*static OkdMeshPtr				addMesh( const OkdString& strResourceName );
	static OkdScenePtr				addScene( const OkdString& strResourceName );*/

	/*static OkdShaderPtr				addVertexShader( const OkdString& strResourceName );
	static OkdShaderPtr				addFragmentShader( const OkdString& strResourceName );
	static OkdShaderPtr				addGeometryShader( const OkdString& strResourceName );*/

private:
									OkdResourceManager();
									~OkdResourceManager();

	void							initialize();
	
	template<class T>
	void							setAllocator( pfnOkdResourceAllocator<T> pfnResourceAllocator );

	template<class T> static T*		addResource( const OkdString& strResourceName );
	template<class T> static bool	removeResource( const OkdResourceKey& resourceKey );

	//OkdResourceMap					_resourceMapArray[OrkidResourceTypeCount];
	OkdResourceMapArray				_resourceMapArray;
	//std::tuple<OkdMeshResMap>		_test;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		setAllocator
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void	OkdResourceManager::setAllocator(pfnOkdResourceAllocator<T>	pfnResourceAllocator)
{
	std::get<T::_eResourceType>.setAllocator( pfnResourceAllocator );
}
 
//-----------------------------------------------------------------------------
// Name:		addResource
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
static T*	OkdResourceManager::addResource(const OkdString&	strResourceName)
{
	OkdResourceManager*			pResourceManager	= OrkidEngine::instance()->getResourceManager();
	OkdResourceKey				resourceKey			= OkdCrc32::getCrc32( strResourceName );
	//OkdResourceType			eResourceType		= T::_eResourceType;
	/*OkdResourceMap<T>&			resourceMap			= std::get<T::_eResourceType>(pResourceManager->_resourceMapArray);
	OkdResourceMap<T>::iterator	itResource			= resourceMap.add( resourceKey, 0 );*/
	auto&			resourceMap = std::get<T::_eResourceType>( pResourceManager->_resourceMapArray );
	auto	itResource = resourceMap.add( resourceKey, 0 );

	if	( itResource->second == 0 )
	{
		//T* pResource = new T();
		T* pResource = resourceMap.allocate();

		pResource->_resourceKey		= resourceKey;
		pResource->_strResourceName	= strResourceName;

		itResource->second = pResource;
	}

	return	( itResource->second );
}

//-----------------------------------------------------------------------------
// Name:		removeResource
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
bool	OkdResourceManager::removeResource(const OkdResourceKey& resourceKey)
{
	OkdResourceManager*							pResourceManager	= OrkidEngine::instance()->getResourceManager();
	//OkdResourceMap&							resourceMap			= pResourceManager->_resourceMapArray[eResourceType];
	/*OkdMap<OkdResourceKey, T*>&					resourceMap			= std::get<T::_eResourceType>(pResourceManager->_resourceMapArray);
	OkdMap<OkdResourceKey, T*>::const_iterator	itResource			= resourceMap.find( resourceKey );*/
	/*OkdResourceMap<T>&							resourceMap = std::get<T::_eResourceType>( pResourceManager->_resourceMapArray );
	OkdResourceMap<T>::const_iterator			itResource = resourceMap.find( resourceKey );*/
	auto&							resourceMap = std::get<T::_eResourceType>( pResourceManager->_resourceMapArray );
	auto			itResource = resourceMap.find( resourceKey );
	T*											pResource			= (*itResource).second;
	bool										bValid				= ( itResource != resourceMap.end() );

	ORKID_ASSERT( bValid );

	delete pResource;
	resourceMap.remove( resourceKey );

	return	( bValid );
}

#endif
