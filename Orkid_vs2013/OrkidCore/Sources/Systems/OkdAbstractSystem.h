//*****************************************************************************
//
//	Class:		OkdAbstractSystem
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdAbstractSystem_h__
#define __OrkidCore_OkdAbstractSystem_h__

#include	"Root.h"

class OkdAbstractSystem
{
public:
	virtual void	update() = 0;

protected:
					OkdAbstractSystem();
	virtual			~OkdAbstractSystem();
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif
