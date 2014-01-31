//*****************************************************************************
//
//	File:		OrkidCoreRoot.h
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OrkidCoreRoot_h__
#define __OrkidCore_OrkidCoreRoot_h__

#include	"../../OrkidRoot.h"

#include	ORKID_CORE_H(Memory/OkdMemManager)

#define OKD_CLEAR_POINTER( p )	\
	if	( p )					\
	{							\
		delete p;				\
		p = 0;					\
	}

#endif
