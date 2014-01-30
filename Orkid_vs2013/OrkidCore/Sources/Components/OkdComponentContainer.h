//*****************************************************************************
//
//	Class:		OkdComponentContainer
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdComponentContainer_h__
#define __OrkidCore_OkdComponentContainer_h__

#include	"Root.h"

#include	ORKID_CORE_H(Containers/OkdMap)
#include	ORKID_CORE_H(Components/OkdComponentPtr)

typedef	OkdMap<OkdComponentId, OkdComponentPtr> OkdComponentPtrMap;

class OkdComponentContainer
{
public:
						OkdComponentContainer();
	virtual				~OkdComponentContainer();

	void				addComponent( const OkdComponentPtr& componentPtr );

private:
	OkdComponentPtrMap	_components;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif
