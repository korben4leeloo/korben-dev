//*****************************************************************************
//
//	File:		OkdEntity.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdEntity.h"

//-----------------------------------------------------------------------------
// Name:		OkdEntity constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdEntity::OkdEntity(const OkdString&	entityName)
: _entityName( entityName )
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdEntity destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdEntity::~OkdEntity()
{
	
}

//-----------------------------------------------------------------------------
// Name:		getComponent
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdComponentPtr	OkdEntity::getComponent(const OkdComponentId	componentId)
{
	OkdComponentPtr componentPtr;
		
	if	( _components.contains( componentId ) )
	{
		componentPtr = _components[componentId];
	}

	return	( componentPtr );
}

//-----------------------------------------------------------------------------
// Name:		read
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdEntity::read(OkdFileStream* pStream)
{
	
}

//-----------------------------------------------------------------------------
// Name:		write
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdEntity::write(OkdFileStream* pStream)
{
	
}
