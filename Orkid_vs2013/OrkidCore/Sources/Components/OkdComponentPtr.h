//*****************************************************************************
//
//	Class:		OkdComponentPtr
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdComponentPtr_h__
#define __OrkidCore_OkdComponentPtr_h__

#include	"Root.h"

#include	ORKID_CORE_H(Memory/OkdSharedPtr)
#include	ORKID_CORE_H(Components/OkdAbstractComponent)

class OkdComponentPtr: public OkdSharedPtr<OkdAbstractComponent>
{
public:
			OkdComponentPtr();
	virtual	~OkdComponentPtr();

private:

};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif
