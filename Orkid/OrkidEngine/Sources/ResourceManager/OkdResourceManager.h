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

//#include	ORKID_CORE_H(Containers/OkdVector)
#include	ORKID_CORE_H(Containers/OkdList)
#include	ORKID_CORE_H(Containers/OkdMap)
//#include	ORKID_ENGINE_H(Entities/OkdMesh)
#include	ORKID_ENGINE_H(ResourceManager/OkdSharedResource)

class OkdSharedResource;

class OkdAbstractResourceHandler
{
	
};

#include	ORKID_CORE_H(String/OkdString)
class OkdResourceContainer
{
public:
	OkdList<OkdSharedResource*>			_resourceList;
	const OkdAbstractResourceHandler*	_pResourceHandler;
	OkdString							_strResourceTypeName;
};

class OkdResourceManager
{
public:
	friend class OrkidEngine;

	//OkdMeshResource						addMesh( const OkdString& strMeshName, const OkdString& strMeshLocationName, const ResourceLocation eResourceLocation );
	//OkdMeshResourcePtr					addMesh( const OkdString& strMeshName, const OkdString& strMeshLocationName, const ResourceLocation eResourceLocation );
	void									registerType( const OkdString& strResourceTypeName, const OkdAbstractResourceHandler* pResourceHandler );
	uint32									getResourceTypeId( const OkdString& strResourceTypeName );

	OkdSharedResourcePtr					retrieveResource( const OkdResourceIdentifier& resourceIdentifier );

private:
											OkdResourceManager();
											~OkdResourceManager();

	//void									clearResources();

	//OkdVector<OkdMeshResource>			_vMeshArray;
	//OkdVector<OkdMeshResourcePtr>			_vMeshArray;
	OkdMap<uint32, OkdResourceContainer*>	_resourceContainerMap;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif