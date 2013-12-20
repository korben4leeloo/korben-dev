//*****************************************************************************
//
//	Class:		OkdMeshResourceHandler
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdMeshResourceHandler_h__
#define __OrkidEngine_OkdMeshResourceHandler_h__

#include	"Root.h"

#include	ORKID_ENGINE_H(Resources/Handlers/OkdResourceHandler)
#include	ORKID_ENGINE_H(Entities/OkdMesh)

//typedef OkdResourceHandler<OkdMesh> OkdMeshResourceHandler;

//class OkdMesh;

#include	ORKID_ENGINE_H(Resources/OkdResourcePtr)

class OkdMeshResourceHandler: public OkdResourceHandler<OkdMesh>
{
	friend class OkdResourceManager;

public:
	/*inline static OkdMeshPtr	addMesh( const OkdString& strMeshName )
	{
		OkdMeshPtr meshPtr = OkdResourceManager::addResource<OkdMesh>( strMeshName );
		return	( meshPtr );
	}*/

private:
								OkdMeshResourceHandler();
	virtual						~OkdMeshResourceHandler();
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif