//*****************************************************************************
//
//	Class:		OkdEntity
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdEntity_h__
#define __OrkidCore_OkdEntity_h__

#include	"Root.h"

#include	ORKID_CORE_H(Containers/OkdMap)
#include	ORKID_CORE_H(String/OkdString)
#include	ORKID_CORE_H(Framework/OkdAbstractComponent)

class OkdFileStream;

class OkdEntity
{
	friend class OkdEntityManager;
	typedef OkdMap<OkdComponentId, OkdComponentPtr> OkdComponentPtrMap;

public:
	virtual void		read( OkdFileStream* pStream );
	virtual void		write( OkdFileStream* pStream );

	OkdComponentPtr		getComponent( const OkdComponentId componentId );
	inline bool			hasComponent( const OkdComponentId componentId ) const;

protected:
						OkdEntity( const OkdString& entityName );
	virtual				~OkdEntity();

	inline void			addComponent( const OkdComponentId componentId, const OkdComponentPtr& componentPtr );
	inline void			removeComponent( const OkdComponentId componentId );

	OkdString			_entityName;
	OkdComponentPtrMap	_components;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		addComponent
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdEntity::addComponent(const OkdComponentId	componentId, 
								const OkdComponentPtr&	componentPtr)
{
	_components.add( componentId, componentPtr );
}

//-----------------------------------------------------------------------------
// Name:		removeComponent
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdEntity::removeComponent(const OkdComponentId	componentId)
{
	_components.remove( componentId );
}

//-----------------------------------------------------------------------------
// Name:		hasComponent
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
bool	OkdEntity::hasComponent(const OkdComponentId	componentId) const
{
	return	( _components.contains( componentId ) );
}

#endif