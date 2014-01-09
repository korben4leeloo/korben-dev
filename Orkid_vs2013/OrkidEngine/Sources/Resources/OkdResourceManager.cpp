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

//template<class T>
//T* defaultAllocator()
//{
//	return( new T() );
//}

template<class T>
class OkdResourceAllocatorFn
{
public:
	template<class...AllocArgs>
	inline T* operator()( AllocArgs...allocArgs )
	{
		return	( new T( allocArgs... ) );
	}
};

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

template<class T, class...BindArgs>
class OkdResourceMap
{
public:
	typedef T* (*pfnResourceAllocator)( BindArgs...bindArgs );

	class OkdResPtr
	{
	public:
		void create( BindArgs...bindArgs )
		{
			//return new T();
			_ptr = OkdResourceMap::_pfnAllocator( bindArgs... );
		}

	private:
		T* _ptr;
	};

private:
	static pfnResourceAllocator _pfnAllocator;
};

//OkdMeshResource* meshAllocator()
//{
//	return	( new OkdMeshResource() );
//}

OkdMesh* meshAllocator()
{
	return	( new OkdMesh() );
}

//typedef defaultAllocator<OkdMeshResource> fnMeshAllocator;

typedef OkdResourceMap<OkdMesh>	OkdMeshResMap;

typedef OkdMeshResMap::OkdResPtr				OkdMeshResPtr;
typedef OkdResourceMap<OkdAbstractShader>::OkdResPtr	OkdShaderResPtr;

OkdMeshResMap::pfnResourceAllocator OkdMeshResMap::_pfnAllocator = meshAllocator;

OkdResourceMap<OkdMeshResource> meshResourceMap;
//OkdResourceMap<OkdMeshResource, OkdResourceAllocatorFn<OkdMeshResource>> meshResourceMap;
//OkdResourceMap<OkdMeshResource, decltype(defaultAllocator<OkdMeshResource>) > meshResourceMap;
//OkdResourceMap<OkdMeshResource, pfnResourceAllocator<OkdMeshResource>> meshResourceMap;
//OkdResourceMap<OkdMeshResource, decltype(meshAllocator)> meshResourceMap;
//OkdResourceMap<OkdMeshResource, meshAllocator> meshResourceMap;
OkdResourceMap<OkdAbstractShader> shaderResourceMap;
//OkdResourceMap<OkdAbstractShader, OrkidShaderType> shaderResourceMap;
//OkdResourceMap<OkdMeshResource, defaultAllocator<OkdMeshResource>> meshResourceMap;
//OkdResourceMap<OkdAbstractShader, defaultAllocator<OkdAbstractShader>> shaderResourceMap;

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
	/*meshResourceMap.setAllocator( meshAllocator );
	shaderResourceMap.setAllocator( shaderAllocator );*/

	//pfnResourceAllocator<OkdMeshResource> f = meshAllocator;

	//ff<defaultAllocator<OkdMeshResource>>();

	/*OkdResourceAllocatorFn<OkdMeshResource> fnAllocMesh;
	OkdMeshResource* p = fnAllocMesh();

	OkdResourceAllocatorFn<OkdShaderResource> fnAllocShader;
	OkdAbstractShader* p2 = fnAllocShader( OrkidVertexShader );*/
	
	//OkdMeshResource* pMesh = meshResourceMap.allocate();
	//OkdAbstractShader* pShader = shaderResourceMap.allocate();
	//shaderResourceMap.allocate( OrkidVertexShader );*/

	/*OkdResPtr<int> int_ptr;
	OkdResPtr<float, float, float> float_ptr;
	
	int_ptr.create();
	float_ptr.create( -1.0f, 1.0f );*/

	/*typedef OkdResourceMap<int>::OkdResPtr OkdIntPtr;
	typedef OkdResourceMap<float, float>::OkdResPtr OkdFloatPtr;

	OkdIntPtr int_ptr;
	OkdFloatPtr float_ptr;

	int* pn = int_ptr.create();
	float* pf = float_ptr.create( 1.0f );*/

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
