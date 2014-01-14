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

class OkdMeshResource
{
public:
	OkdMeshResource()
	{

	}
};

template<class T>
T* defaultAllocator()
{
	return(new T());
}

template<class ReturnType, class...Parameters>
class OkdResourceAllocatorFn
{
public:
	inline ReturnType* operator()( Parameters...params )
	{
		return	( new ReturnType( params... ) );
	}
};

template<class T>
class OkdResourceMap
{
private:
	struct OkdInternalResourceAllocator
	{
		OkdInternalResourceAllocator(): _fnAllocator( 0 ) {}

		T* operator()()
		{
			if ( _fnAllocator )
			{
				return _fnAllocator();
			}
		
			return 0;
		}

	protected:
		typedef T* (*fnAllocator)();
		fnAllocator _fnAllocator;
	};

	struct OkdInternalDefaultResourceAllocator: public OkdInternalResourceAllocator
	{
		OkdInternalDefaultResourceAllocator()
		{
			_fnAllocator = defaultAllocator<T>;
		}
	};

public:
	OkdResourceMap()
	{
		T* p = _allocator();
	}

	class OkdResPtr
	{
	public:
		void create()
		{
			//return new T();
			//_ptr = OkdResourceMap::_pfnAllocator( allocArgs... );
			//_ptr = OkdResourceAllocatorFn<T, 
		}

	private:
		T* _ptr;
	};

private:
	typedef typename std::conditional<std::is_abstract<T>::value, OkdInternalResourceAllocator, OkdInternalDefaultResourceAllocator>::type AllocatorType;

	AllocatorType _allocator;
};

class OkdShaderResource: public OkdAbstractShader
{
public:
	OkdShaderResource( const OrkidShaderType eShaderType ): OkdAbstractShader( eShaderType ) {}
	virtual void compile() {}
};

class OkdVertexShaderResource: public OkdAbstractShader
{
public:
	OkdVertexShaderResource(): OkdAbstractShader( OrkidShaderTypeVertex ) {}
	virtual void compile() {}
};

//OkdAbstractShader* shaderAllocator( OrkidShaderType eShaderType )
//{
//	return	( new OkdShaderResource( eShaderType ) );
//}

OkdAbstractShader* vertexShaderAllocator()
{
	return	( new OkdVertexShaderResource() );
}

typedef OkdResourceMap<OkdMeshResource>		OkdMeshResMap;
typedef OkdResourceMap<OkdAbstractShader>	OkdShaderResMap;

typedef OkdMeshResMap::OkdResPtr	OkdMeshResPtr;
typedef OkdShaderResMap::OkdResPtr	OkdShaderResPtr;

//-----------------------------------------------------------------------------
// Name:		OkdResourceManager constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourceManager::OkdResourceManager()
{
	OkdMeshResMap meshResourceMap;
	/*OkdShaderResMap shaderResourceMap( shaderAllocator );*/
	OkdShaderResMap shaderResourceMap;
	//OkdShaderResMap shaderResourceMap;

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
