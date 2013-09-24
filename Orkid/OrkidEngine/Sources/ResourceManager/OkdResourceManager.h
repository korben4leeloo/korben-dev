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

class OkdSharedResource;

class OkdAbstractResourceHandler
{
	
};

class OkdResourceContainer
{
	OkdList<OkdSharedResource*>	_resourceList;
	OkdAbstractResourceHandler*	_pResourceHandler;
};

class OkdResourceManager
{
public:
	friend class OrkidEngine;

	//OkdMeshResource					addMesh( const OkdString& strMeshName, const OkdString& strMeshLocationName, const ResourceLocation eResourceLocation );
	//OkdMeshResourcePtr				addMesh( const OkdString& strMeshName, const OkdString& strMeshLocationName, const ResourceLocation eResourceLocation );

private:
									OkdResourceManager();
									~OkdResourceManager();

	//void							clearResources();

	//OkdVector<OkdMeshResource>	_vMeshArray;
	//OkdVector<OkdMeshResourcePtr>	_vMeshArray;
	OkdMap<uint, OkdResourceContainer*>	_resourceContainerMap;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif