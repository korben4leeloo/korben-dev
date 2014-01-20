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

#include	ORKID_CORE_H(String/OkdString)
#include	ORKID_CORE_H(String/OkdCrc32)
#include	ORKID_ENGINE_H(Resources/OkdResourceMap)

class OkdMesh;
class OkdScene;
class OkdAbstractShaderProgram;

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

private:
							OkdResourceManager();
							~OkdResourceManager();

	void					initialize();
	
	template<class T> void	setAllocator( pfnOkdResourceAllocator<T> pfnResourceAllocator );

	template<class T> T*	addResource( const OkdString& strResourceName );
	template<class T> bool	removeResource( const OkdResourceKey& resourceKey );

	OkdResourceMapArray		_resourceMapArray;
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
T*	OkdResourceManager::addResource(const OkdString&	strResourceName)
{
	OkdResourceKey				resourceKey = OkdCrc32::getCrc32( strResourceName );
	OkdResourceMap<T>&			resourceMap = std::get<T::_eResourceType>( _resourceMapArray );
	OkdResourceMap<T>::iterator	itResource = resourceMap.add( resourceKey, 0 );

	if	( itResource->second == 0 )
	{
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
	OkdResourceMap<T>&					resourceMap	= std::get<T::_eResourceType>( _resourceMapArray );
	OkdResourceMap<T>::const_iterator	itResource	= resourceMap.find( resourceKey );
	T*									pResource	= (*itResource).second;
	bool								bValid		= ( itResource != resourceMap.end() );

	ORKID_ASSERT( bValid );

	delete pResource;
	resourceMap.remove( resourceKey );

	return	( bValid );
}

#endif
