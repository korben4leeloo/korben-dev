//*****************************************************************************
//
//	Class:		OkdCreature
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdCreature_h__
#define __OrkidEngine_OkdCreature_h__

#include	"Root.h"

#include	ORKID_ENGINE_H(Entities/OkdEntity)
#include	ORKID_ENGINE_H(Resources/OkdResourcePtr)
#include	ORKID_ENGINE_H(Entities/OkdMesh)

class OkdMesh;

class OkdCreature: public OkdEntity
{
	friend class OkdEntityFactory;

public:
	inline void		setMeshPtr( const OkdMeshPtr& meshPtr );

	// OkdEntity implementation
	virtual void	read( OkdFileStream* pStream );
	virtual void	write( OkdFileStream* pStream );

private:
					OkdCreature();
	virtual			~OkdCreature();

	OkdMeshPtr		_meshPtr;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		setMeshPtr
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdCreature::setMeshPtr(const OkdMeshPtr&	meshPtr)
{
	_meshPtr = meshPtr;
}

#endif