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

#define OKD_REGISTER_COMPONENT( ComponentClass, pComponentFactory ) pComponentFactory->registerComponent( ComponentClass::getComponentId(), ComponentClass::create );

class OkdComponentFactory
{
public:
												OkdComponentFactory();
												~OkdComponentFactory();

	void										registerComponent( const OkdComponentId componentId, pfnComponentCreator creatorFn );
	OkdComponentPtr								createComponent( const OkdComponentId componentId );
	
private:
	OkdMap<OkdComponentId, pfnComponentCreator>	_componentCreatorMap;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif