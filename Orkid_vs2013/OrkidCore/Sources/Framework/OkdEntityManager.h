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
#include	ORKID_CORE_H(Framework/OkdHandleTemplate)
#include	ORKID_CORE_H(Signals/OkdCoreSignals)

class OkdString;
class OkdEntity;
class OkdComponentFactory;

typedef OkdHandleTemplate<uint32, 24> OkdEntityHandle;

class OkdEntityManager
{
public:
								OkdEntityManager( OkdComponentFactory* pComponentFactory );
								~OkdEntityManager();

	OkdEntityHandle				createEntity( const OkdString& entityName );

	OkdComponentPtr				addComponent( OkdEntity* pEntity, const OkdComponentId componentId );
	void						removeComponent( OkdEntity* pEntity, const OkdComponentId componentId );

	OkdAddComponentSignal		_onAddComponentSignal;
	OkdRemoveComponentSignal	_onRemoveComponentSignal;

private:
	OkdComponentFactory*		_pComponentFactory;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif