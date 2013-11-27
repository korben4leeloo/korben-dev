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
#include	ORKID_ENGINE_H(Resources/OkdResourcePtr)
#include	ORKID_ENGINE_H(Entities/OkdMesh)

class OkdMesh;

class OkdMeshInstance: public OkdEntity
{
public:
				OkdMeshInstance();
				~OkdMeshInstance();

	inline void	setMeshPtr( const OkdMeshPtr& meshPtr );

private:
	OkdMeshPtr	_meshPtr;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		setMeshPtr
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdMeshInstance::setMeshPtr(const OkdMeshPtr&	meshPtr)
{
	_meshPtr = meshPtr;
}

#endif