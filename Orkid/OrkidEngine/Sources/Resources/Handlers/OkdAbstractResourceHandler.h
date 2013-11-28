//*****************************************************************************
//
//	Class:		OkdAbstractResourceHandler
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdAbstractResourceHandler_h__
#define __OrkidEngine_OkdAbstractResourceHandler_h__

#include	"Root.h"

class OkdAbstractResourceHandler
{
public:
								OkdAbstractResourceHandler();
	virtual						~OkdAbstractResourceHandler();

	virtual OkdResourceType	getResourceType() const = 0;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif