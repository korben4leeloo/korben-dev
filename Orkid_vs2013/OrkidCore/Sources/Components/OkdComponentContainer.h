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

#include	ORKID_CORE_H(Containers/OkdList)
#include	ORKID_CORE_H(Components/OkdComponentPtr)

class OkdComponentContainer: public OkdList<OkdComponentPtr>
{
public:
			OkdComponentContainer();
	virtual	~OkdComponentContainer();

private:
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif
