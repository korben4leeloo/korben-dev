//*****************************************************************************
//
//	File:		OkdResourceManager.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdResourceManager.h"

#include	ORKID_ENGINE_H(Resources/OkdResourcePtr)
#include	ORKID_ENGINE_H(Entities/OkdMesh)
#include	ORKID_ENGINE_H(SceneGraph/OkdScene)
#include	ORKID_ENGINE_H(Shaders/OkdAbstractShader)

template<class T, typename...AllocatorArgs>
using pfnResourceAllocator = T* (*)(AllocatorArgs...allocArgs);

class OkdMeshResource
{

};

template<class T, typename...AllocatorArgs> 
class OkdResourceMap: public OkdMap<OkdResourceKey, T*>
{
public:
	OkdResourceMap(): _pfnResourceAllocator( 0 ) {}

	void setAllocator( pfnResourceAllocator<T, AllocatorArgs...> pfnResourceAllocator ) { _pfnResourceAllocator = pfnResourceAllocator; }

private:
	pfnResourceAllocator<T, AllocatorArgs...> _pfnResourceAllocator;
};

OkdResourceMap<OkdMeshResource> meshResourceMap;
OkdResourceMap<OkdAbstractShader, OrkidShaderType> shaderResourceMap;

OkdMeshResource* meshAllocator()
{
	return	( new OkdMeshResource() );
}

class OkdShaderResource: public OkdAbstractShader
{
public:
	OkdShaderResource( const OrkidShaderType eShaderType ): OkdAbstractShader( eShaderType ) {}
	virtual void compile() {}
};

OkdAbstractShader* shaderAllocator( OrkidShaderType eShaderType )
{
	return	( new OkdShaderResource( eShaderType ) );
}

//-----------------------------------------------------------------------------
// Name:		OkdResourceManager constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourceManager::OkdResourceManager()
{
	meshResourceMap.setAllocator( meshAllocator );
	shaderResourceMap.setAllocator( shaderAllocator );
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

////-----------------------------------------------------------------------------
//// Name:		addMesh
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//OkdMeshPtr	OkdResourceManager::addMesh(const OkdString&	strResourceName)
//{
//	return	( addResource<OkdMesh>( strResourceName ) );
//}
//
////-----------------------------------------------------------------------------
//// Name:		addScene
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//OkdScenePtr	OkdResourceManager::addScene(const OkdString&	strResourceName)
//{
//	return	( addResource<OkdScene>( strResourceName ) );
//}
