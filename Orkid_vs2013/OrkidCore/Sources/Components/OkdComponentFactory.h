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

class OkdComponentFactory
{
public:
												OkdComponentFactory();
												~OkdComponentFactory();

	void										registerComponent( const char* pcComponentName, pfnComponentCreator creatorFunc );
	OkdComponentPtr								createComponent( const OkdComponentId& componentType );
	
private:
	OkdMap<OkdComponentId, pfnComponentCreator>	_componentCreatorMap;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif