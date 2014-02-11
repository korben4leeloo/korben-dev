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

#include	ORKID_CORE_H(Framework/OkdAbstractComponent)
#include	ORKID_CORE_H(Containers/OkdMap)

#define OKD_REGISTER_COMPONENT( ComponentClass, pComponentFactory ) pComponentFactory->registerComponentType( ComponentClass::getComponentId(), ComponentClass::create );

class OkdComponentFactory
{
	typedef OkdMap<OkdComponentId, const pfnComponentCreator> OkdComponentCreatorMap;

public:
								OkdComponentFactory();
								~OkdComponentFactory();

	void						registerComponentType( const OkdComponentId componentId, const pfnComponentCreator creatorFn );
	OkdComponentPtr				createComponent( const OkdComponentId componentId );

private:
	OkdComponentCreatorMap		_componentCreatorMap;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif