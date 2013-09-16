//*****************************************************************************
//
//	Class:		OkdMeshInstance
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdMeshInstance_h__
#define __OrkidEngine_OkdMeshInstance_h__

#include	"Root.h"

#include	ORKID_ENGINE_H(Entities/OkdEntity)

class OkdMesh;

class OkdMeshInstance: public OkdEntity
{
public:
				OkdMeshInstance();
				~OkdMeshInstance();

private:
	OkdMesh*	_pMesh;
};

#endif