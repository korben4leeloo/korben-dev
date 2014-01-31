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
// Name:		registerComponent
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdComponentFactory::registerComponent(const OkdComponentId	componentId, 
											   pfnComponentCreator	creatorFunc)
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
	OkdComponentPtr		componentPtr;//( creatorFunc() );

	return	( componentPtr );
}