//*****************************************************************************
//
//	File:		OkdComponentContainer.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdComponentContainer.h"

#include	ORKID_CORE_H(Components/OkdComponentFactory)
#include	ORKID_ENGINE_H(OrkidEngine)

//-----------------------------------------------------------------------------
// Name:		OkdComponentContainer constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdComponentContainer::OkdComponentContainer()
{

}

//-----------------------------------------------------------------------------
// Name:		OkdComponentContainer destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdComponentContainer::~OkdComponentContainer()
{
	
}

//-----------------------------------------------------------------------------
// Name:		addComponent
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdComponentContainer::addComponent(const OkdComponentId	componentId)
{
	OkdComponentFactory*	pComponentFactory	= OrkidEngine::instance()->getComponentFactory();
	OkdComponentPtr			componentPtr		= pComponentFactory->createComponent( componentId );

	_components.add( componentId, componentPtr );
}

//-----------------------------------------------------------------------------
// Name:		removeComponent
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdComponentContainer::removeComponent(const OkdComponentId	componentId)
{
	uint32 uiCount = _components.remove( componentId );
	ORKID_ASSERT( uiCount == 1 );
}

//-----------------------------------------------------------------------------
// Name:		getComponent
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdComponentPtr	OkdComponentContainer::getComponent(const OkdComponentId	componentId)
{
	ORKID_ASSERT( _components.contains( componentId ) );

	OkdComponentPtr componentPtr = _components[componentId];
	return	( componentPtr );
}
