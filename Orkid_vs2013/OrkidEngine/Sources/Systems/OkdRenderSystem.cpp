//*****************************************************************************
//
//	File:		OkdRenderSystem.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdRenderSystem.h"

//-----------------------------------------------------------------------------
// Name:		OkdRenderSystem constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdRenderSystem::OkdRenderSystem()
: _onAddComponentSlot		( this, &OkdRenderSystem::onComponentAdded )
, _onRemoveComponentSlot	( this, &OkdRenderSystem::onComponentRemoved )
{

}

//-----------------------------------------------------------------------------
// Name:		OkdRenderSystem destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdRenderSystem::~OkdRenderSystem()
{
	
}

//-----------------------------------------------------------------------------
// Name:		onComponentAdded
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdRenderSystem::onComponentAdded(const OkdEntity*		pEntity, 
										  const OkdComponentId	componentId)
{
	
}

//-----------------------------------------------------------------------------
// Name:		onComponentRemoved
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdRenderSystem::onComponentRemoved(const OkdEntity*		pEntity, 
											const OkdComponentId	componentId)
{
	
}

//-----------------------------------------------------------------------------
// Name:		update
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdRenderSystem::update()
{
	
}
