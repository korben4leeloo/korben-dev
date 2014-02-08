//*****************************************************************************
//
//	Class:		OkdComponentFactory
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdComponentFactory_h__
#define __OrkidEngine_OkdComponentFactory_h__

#include	"Root.h"

#include	ORKID_CORE_H(Components/OkdComponentPtr)
#include	ORKID_CORE_H(Containers/OkdMap)
#include	ORKID_ENGINE_H(Signals/OkdEngineSignals)

#define OKD_REGISTER_COMPONENT( ComponentClass, pComponentFactory ) pComponentFactory->registerComponent( ComponentClass::getComponentId(), ComponentClass::create );

class OkdComponentFactory
{
	typedef OkdMap<OkdComponentId, const pfnComponentCreator> OkdComponentCreatorMap;

public:
								OkdComponentFactory();
								~OkdComponentFactory();

	void						registerComponent( const OkdComponentId componentId, const pfnComponentCreator creatorFn );
	OkdComponentPtr				createComponent( const OkdComponentId componentId );
	
	OkdCreateComponentSignal	_onCreateComponentSignal;

private:
	OkdComponentCreatorMap		_componentCreatorMap;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif