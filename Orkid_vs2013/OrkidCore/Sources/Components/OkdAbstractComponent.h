//*****************************************************************************
//
//	Class:		OkdAbstractComponent
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdAbstractComponent_h__
#define __OrkidCore_OkdAbstractComponent_h__

#include	"Root.h"

typedef uint32 OkdComponentId;

class OkdAbstractComponent
{
public:
									OkdAbstractComponent();
	virtual							~OkdAbstractComponent();

protected:
};

typedef OkdAbstractComponent* (*pfnComponentCreator)();

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif
