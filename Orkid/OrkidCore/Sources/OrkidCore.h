//*****************************************************************************
//
//	Class:		OrkidCore
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OrkidCore_h__
#define __OrkidCore_OrkidCore_h__

#include	"OrkidCoreRoot.h"

class OrkidCore
{
public:
	static void	initialize();
	static void	uninitialize();

private:
				OrkidCore();
				~OrkidCore();
};

#endif
