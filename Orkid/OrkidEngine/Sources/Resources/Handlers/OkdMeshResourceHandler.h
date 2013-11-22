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

class OkdMesh;

class OkdMeshResourceHandler: public OkdResourceHandler<OkdMesh, OrkidMesh>
{
	friend class OkdResourceManager;

private:
			OkdMeshResourceHandler();
	virtual	~OkdMeshResourceHandler();
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif