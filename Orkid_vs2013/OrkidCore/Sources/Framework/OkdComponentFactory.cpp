//*****************************************************************************
//
//	File:		OkdComponentFactory.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdComponentFactory.h"

//-----------------------------------------------------------------------------
// Name:		OkdComponentFactory constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdComponentFactory::OkdComponentFactory()
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdComponentFactory destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdComponentFactory::~OkdComponentFactory()
{
	
}

//-----------------------------------------------------------------------------
// Name:		registerComponentType
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdComponentFactory::registerComponentType(const OkdComponentId			componentId, 
												   const pfnComponentCreator	creatorFunc)
{
	if	( _componentCreatorMap.contains( componentId ) )
	{
		ORKID_BREAK();
		return;
	}

	_componentCreatorMap.add( componentId, creatorFunc );
}

//-----------------------------------------------------------------------------
// Name:		createComponent
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdComponentPtr	OkdComponentFactory::createComponent(const OkdComponentId	componentId)
{
	pfnComponentCreator	creatorFunc = _componentCreatorMap[componentId];
	OkdComponentPtr		componentPtr( creatorFunc() );

	_onCreateComponentSignal.send( componentId );

	return	( componentPtr );
}
