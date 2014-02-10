//*****************************************************************************
//
//	Class:		OkdEntityManager
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdEntityManager_h__
#define __OrkidEngine_OkdEntityManager_h__

#include	"Root.h"

#include	ORKID_CORE_H(Framework/OkdAbstractComponent)

class OkdString;
class OkdEntity;
class OkdComponentFactory;

class OkdEntityManager
{
public:
							OkdEntityManager( OkdComponentFactory* pComponentFactory );
							~OkdEntityManager();

	OkdEntity*				createEntity( const OkdString& entityName );

	OkdComponentPtr			addComponent( OkdEntity* pEntity, const OkdComponentId componentId );
	void					removeComponent( OkdEntity* pEntity, const OkdComponentId componentId );

private:
	OkdComponentFactory*	_pComponentFactory;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif