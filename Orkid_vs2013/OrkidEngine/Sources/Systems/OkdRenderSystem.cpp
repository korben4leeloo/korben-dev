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
: _onCreateComponentSlot( this, &OkdRenderSystem::onComponentCreated )
, _onRemoveComponentSlot( this, &OkdRenderSystem::onComponentRemoved )
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
// Name:		onComponentCreated
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdRenderSystem::onComponentCreated(const OkdComponentId	componentId)
{
	
}

//-----------------------------------------------------------------------------
// Name:		onComponentRemoved
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdRenderSystem::onComponentRemoved(const OkdComponentId	componentId)
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
