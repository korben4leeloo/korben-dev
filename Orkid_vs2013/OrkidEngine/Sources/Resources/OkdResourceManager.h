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

#include	ORKID_CORE_H(Containers/OkdMap)
#include	ORKID_CORE_H(String/OkdString)
#include	ORKID_CORE_H(String/OkdCrc32)

//class OkdAbstractResource;

//typedef OkdMap<OkdResourceKey, OkdAbstractResource*> OkdResourceMap;

template<class T> class OkdResourcePtr;

class OkdMesh;
class OkdScene;
class OkdAbstractShader;

typedef OkdResourcePtr<OkdMesh>				OkdMeshPtr;
typedef OkdResourcePtr<OkdScene>			OkdScenePtr;
typedef OkdResourcePtr<OkdAbstractShader>	OkdShaderPtr;

typedef OkdMap<OkdResourceKey, OkdMesh*> OkdMeshResourceMap;
typedef OkdMap<OkdResourceKey, OkdScene*> OkdSceneResourceMap;
typedef OkdMap<OkdResourceKey, OkdAbstractShader*> OkdShaderResourceMap;

typedef std::tuple<
	OkdMeshResourceMap, 
	OkdSceneResourceMap, 
	OkdShaderResourceMap> OkdResourceMapArray;

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

	template<class T, typename...ConstructArgs> static T*		addResource( const OkdString& strResourceName, ConstructArgs...constructArgs );
	template<class T> static bool	removeResource( const OkdResourceKey& resourceKey );

	//OkdResourceMap					_resourceMapArray[OrkidResourceTypeCount];
	OkdResourceMapArray				_resourceMapArray;
	//std::tuple<>					_test;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		addResource
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, typename...ConstructArgs>
static T*	OkdResourceManager::addResource(const OkdString&	strResourceName, ConstructArgs...constructArgs)
{
	OkdResourceManager*						pResourceManager	= OrkidEngine::instance()->getResourceManager();
	OkdResourceKey							resourceKey			= OkdCrc32::getCrc32( strResourceName );
	//OkdResourceType						eResourceType		= T::_eResourceType;
	OkdMap<OkdResourceKey, T*>&				resourceMap			= std::get<T::_eResourceType>(pResourceManager->_resourceMapArray);
	OkdMap<OkdResourceKey, T*>::iterator	itResource			= resourceMap.add( resourceKey, 0 );

	if	( itResource->second == 0 )
	{
		T* pResource = new T();

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
	OkdMap<OkdResourceKey, T*>&					resourceMap			= std::get<T::_eResourceType>(pResourceManager->_resourceMapArray);
	OkdMap<OkdResourceKey, T*>::const_iterator	itResource			= resourceMap.find( resourceKey );
	T*											pResource			= (*itResource).second;
	bool										bValid				= ( itResource != resourceMap.end() );

	ORKID_ASSERT( bValid );

	delete pResource;
	resourceMap.remove( resourceKey );

	return	( bValid );
}

#endif
