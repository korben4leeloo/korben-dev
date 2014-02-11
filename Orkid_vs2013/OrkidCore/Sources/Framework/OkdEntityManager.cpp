//*****************************************************************************
//
//	File:		OkdEntityManager.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdEntityManager.h"

#include	ORKID_CORE_H(Framework/OkdComponentFactory)
#include	ORKID_CORE_H(Framework/OkdEntity)

//-----------------------------------------------------------------------------
// Name:		OkdEntityManager constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdEntityManager::OkdEntityManager(OkdComponentFactory*	pComponentFactory)
: _pComponentFactory( pComponentFactory )
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdEntityManager destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdEntityManager::~OkdEntityManager()
{
	
}

//-----------------------------------------------------------------------------
// Name:		createEntity
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdEntity*	OkdEntityManager::createEntity(const OkdString&	entityName)
{
	OkdEntity* pEntity = new OkdEntity( entityName );
	return	( pEntity );
}

//-----------------------------------------------------------------------------
// Name:		addComponent
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdComponentPtr	OkdEntityManager::addComponent(OkdEntity*			pEntity, 
											   const OkdComponentId	componentId)
{
	OkdComponentPtr componentPtr = pEntity->getComponent( componentId );

	if	( componentPtr.isValid() )
	{
		componentPtr.reset();
	}
	else
	{
		componentPtr = _pComponentFactory->createComponent( componentId );

		pEntity->addComponent( componentId, componentPtr );
		_onAddComponentSignal.send( pEntity, componentId );
	}

	return	( componentPtr );
}

//-----------------------------------------------------------------------------
// Name:		addComponent
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdEntityManager::removeComponent(OkdEntity*			pEntity, 
										  const OkdComponentId	componentId)
{
	if	( pEntity->hasComponent( componentId ) )
	{
		pEntity->removeComponent( componentId );
		_onRemoveComponentSignal.send( pEntity, componentId );
	}
}
