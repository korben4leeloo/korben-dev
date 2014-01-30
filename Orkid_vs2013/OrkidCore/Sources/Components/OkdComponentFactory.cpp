//*****************************************************************************
//
//	File:		OkdComponentFactory.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdComponentFactory.h"

#include	ORKID_CORE_H(String/OkdString)
#include	ORKID_CORE_H(String/OkdCrc32)

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
void	OkdComponentFactory::registerComponent(const char*			pcComponentName, 
											   pfnComponentCreator	creatorFunc)
{
	OkdComponentId componentId = OkdCrc32::getCrc32( OkdString( pcComponentName ) );
	_componentCreatorMap.add( componentId, creatorFunc );
}
