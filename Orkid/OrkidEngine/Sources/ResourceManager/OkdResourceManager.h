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

#include	ORKID_CORE_H(Containers/OkdVector)
#include	ORKID_ENGINE_H(Entities/OkdMesh)

class OkdResourceManager
{
public:
								OkdResourceManager();
								~OkdResourceManager();

	//OkdMeshResource				addMesh( const OkdString& strMeshName, const OkdString& strMeshLocationName, const ResourceLocation eResourceLocation );
	OkdMeshResourcePtr				addMesh( const OkdString& strMeshName, const OkdString& strMeshLocationName, const ResourceLocation eResourceLocation );

private:
	void						clearResources();

	//OkdVector<OkdMeshResource>	_vMeshArray;
	OkdVector<OkdMeshResourcePtr>	_vMeshArray;
};

#endif