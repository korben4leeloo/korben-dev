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

//template<class T, typename...AllocatorArgs>
//using pfnResourceAllocator = T* (*)(AllocatorArgs...allocArgs);

class OkdMeshResource
{
public:
	OkdMeshResource()
	{

	}
};

template<class T, class...AllocArgs>
T* defaultAllocator( AllocArgs...allocArgs )
{
	return( new T( allocArgs...) );
}

//template<class T>
//class OkdResourceAllocatorFn
//{
//public:
//	template<class...AllocArgs>
//	inline T* operator()( AllocArgs...allocArgs )
//	{
//		return	( new T( allocArgs... ) );
//	}
//};

class OkdShaderAllocatorFn
{
public:
	inline OkdAbstractShader* operator()( const OrkidShaderType eShaderType )
	{
		return	( 0 );
	}
};

//template<class T, class AllocatorType = OkdResourceAllocatorFn<T> >
////template<class T>
////template<class T, template<class ReturnType, typename...AllocatorArgs> class> 
////template<class T, pfnResourceAllocator allocator> 
////template<class T, T* (*fnAllocator)() = defaultAllocator<T> >
////template<class T, class...Allocargs, T* (*fnAllocator)(Allocargs...)>
//class OkdResourceMap: public OkdMap<OkdResourceKey, T*>
//{
//public:
//	OkdResourceMap()//: _pfnResourceAllocator( 0 )
//	{
//		
//	}
//
//	//void setAllocator( pfnResourceAllocator<T, AllocatorArgs...> pfnResourceAllocator ) { _pfnResourceAllocator = pfnResourceAllocator; }
//
//	T* allocate()
//	{
//		AllocatorType fn;
//		return fn();
//		//return 0;
//	}
//
//private:
//	//pfnResourceAllocator<T, AllocatorArgs...> _pfnResourceAllocator;
//};

template<class ReturnType, class...Parameters>
class OkdResourceAllocatorFn
{
public:
	inline ReturnType* operator()( Parameters...params )
	{
		return	( new ReturnType( params... ) );
	}
};

template<class T, class...AllocArgs>
class OkdResourceMap
{
public:
	typedef T* (*pfnResourceAllocator)( AllocArgs...allocArgs );

	OkdResourceMap( pfnResourceAllocator allocator = defaultAllocator<T, AllocArgs...> ): _pfnAllocator( allocator ) {}

	class OkdResPtr
	{
	public:
		void create( AllocArgs...allocArgs )
		{
			//return new T();
			//_ptr = OkdResourceMap::_pfnAllocator( allocArgs... );
			//_ptr = OkdResourceAllocatorFn<T, 
		}

	private:
		T* _ptr;
	};

private:
	pfnResourceAllocator _pfnAllocator;
};

//OkdMeshResource* meshAllocator()
//{
//	return	( new OkdMeshResource() );
//}

//OkdMesh* meshAllocator()
//{
//	return	( new OkdMesh() );
//}

//typedef defaultAllocator<OkdMeshResource> fnMeshAllocator;

//typedef OkdResourceMap<OkdMesh>	OkdMeshResMap;
//
//typedef OkdMeshResMap::OkdResPtr				OkdMeshResPtr;
//typedef OkdResourceMap<OkdAbstractShader>::OkdResPtr	OkdShaderResPtr;

//OkdMeshResMap::pfnResourceAllocator OkdMeshResMap::_pfnAllocator = meshAllocator;

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

typedef OkdResourceMap<OkdMeshResource>						OkdMeshResMap;
typedef OkdResourceMap<OkdAbstractShader, OrkidShaderType>	OkdShaderResMap;

typedef OkdMeshResMap::OkdResPtr	OkdMeshResPtr;
typedef OkdShaderResMap::OkdResPtr	OkdShaderResPtr;

//OkdResourceMap<OkdMeshResource> meshResourceMap;
//OkdResourceMap<OkdMeshResource, OkdResourceAllocatorFn<OkdMeshResource>> meshResourceMap;
//OkdResourceMap<OkdMeshResource, decltype(defaultAllocator<OkdMeshResource>) > meshResourceMap;
//OkdResourceMap<OkdMeshResource, pfnResourceAllocator<OkdMeshResource>> meshResourceMap;
//OkdResourceMap<OkdMeshResource, decltype(meshAllocator)> meshResourceMap;
//OkdResourceMap<OkdMeshResource, meshAllocator> meshResourceMap;
//OkdResourceMap<OkdAbstractShader> shaderResourceMap;
//OkdResourceMap<OkdAbstractShader, OrkidShaderType> shaderResourceMap( shaderAllocator );
//OkdResourceMap<OkdMeshResource, defaultAllocator<OkdMeshResource>> meshResourceMap;
//OkdResourceMap<OkdAbstractShader, defaultAllocator<OkdAbstractShader>> shaderResourceMap;

//-----------------------------------------------------------------------------
// Name:		OkdResourceManager constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourceManager::OkdResourceManager()
{
	OkdMeshResMap meshResourceMap;
	OkdShaderResMap shaderResourceMap( shaderAllocator );

	std::tuple<OkdMeshResMap, OkdShaderResMap> resourceTuple = std::make_tuple{ meshResourceMap, shaderResourceMap };

	OkdMeshResPtr ptr;
	ptr.create();
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
