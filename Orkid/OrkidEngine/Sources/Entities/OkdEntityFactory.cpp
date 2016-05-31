//*****************************************************************************
//
//	File:		OkdEntityFactory.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdEntityFactory.h"

#include	ORKID_ENGINE_H(Entities/OkdCamera)
#include	ORKID_ENGINE_H(Entities/OkdLight)
#include	ORKID_ENGINE_H(Entities/OkdShape)
#include	ORKID_ENGINE_H(Entities/OkdCreature)

OkdEntityFactory::pfnEntityCreator OkdEntityFactory::_pfnEntityCreators[OrkidEntityTypeCount] = 
{
	OkdEntityFactory::entityCreator<OkdCamera>,
	OkdEntityFactory::entityCreator<OkdLight>,
	OkdEntityFactory::entityCreator<OkdShape>,
	OkdEntityFactory::entityCreator<OkdCreature>
};

//-----------------------------------------------------------------------------
// Name:		OkdEntityFactory constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdEntityFactory::OkdEntityFactory()
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdEntityFactory destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdEntityFactory::~OkdEntityFactory()
{

}

//-----------------------------------------------------------------------------
// Name:		createEntity
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdEntity*	OkdEntityFactory::createEntity(const OkdEntityType	eEntityType)
{
	OkdEntity* pEntity = _pfnEntityCreators[eEntityType]();
	return	( pEntity );
}
