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

class OkdAbstractResourceHandler;

#include	ORKID_ENGINE_H(Resources/OkdResourcePtr)
#include	ORKID_CORE_H(Containers/OkdMap)

class OkdAbstractResource;

typedef OkdMap<OkdResourceKey, OkdAbstractResource*> OkdResourceMap;

//template <class T>
//class ResourceHandle
//{
//
//};
//
//class OkdMesh;
//typedef ResourceHandle<OkdMesh> MeshHandle;
//typedef OkdResourcePtr<OkdMesh> OkdMeshResPtr;
//
//class OkdAbstractShader;
//typedef ResourceHandle<OkdAbstractShader> ShaderHandle;
//typedef OkdResourcePtr<OkdAbstractShader> OkdShaderResPtr;

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

	inline OkdAbstractResourceHandler*	getResourceHandler( const OkdResourceType eResourceType );

	static OkdMeshPtr					addMesh( const OkdString& strResourceName );
	static OkdScenePtr					addScene( const OkdString& strResourceName );

	static OkdShaderPtr					addVertexShader( const OkdString& strResourceName );
	static OkdShaderPtr					addFragmentShader( const OkdString& strResourceName );
	static OkdShaderPtr					addGeometryShader( const OkdString& strResourceName );

private:
										OkdResourceManager();
										~OkdResourceManager();

	inline void							setResourceHandler( const OkdResourceType eResourceType, OkdAbstractResourceHandler* pResourceHandler );

	void								initialize();

	template<class T>
	static OkdResourcePtr<T>			addResource( const OkdString& strResourceName );

	OkdAbstractResourceHandler*			_resourceHandlers[OrkidResourceTypeCount];
	OkdResourceMap						_resourceMapArray[OrkidResourceTypeCount];
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		setResourceHandler
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdResourceManager::setResourceHandler(const OkdResourceType		eResourceType, 
											   OkdAbstractResourceHandler*	pResourceHandler)
{
	_resourceHandlers[eResourceType] = pResourceHandler;
}

//-----------------------------------------------------------------------------
// Name:		getResourceHandler
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdAbstractResourceHandler*	OkdResourceManager::getResourceHandler(const OkdResourceType	eResourceType)
{
	return	( _resourceHandlers[eResourceType] );
}

//-----------------------------------------------------------------------------
// Name:		addResource
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
static OkdResourcePtr<T>	OkdResourceManager::addResource( const OkdString& strResourceName )
{
	OkdResourcePtr<T> resPtr;
	return	( resPtr );
}

#endif