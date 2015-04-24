//*****************************************************************************
//
//	Class:		KmResourceId
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __KosmoCore_KmResourceId_h__
#define __KosmoCore_KmResourceId_h__

#include	"Root.h"

KOSMO_CORE_NAMESPACE_BEGIN

struct KmResourceId
{
	uint32	m_nIndex	: 24;
	uint32	m_nTag		: 8;
};

//*****************************************************************************
//	Inline methods declarations
//*****************************************************************************

KOSMO_CORE_NAMESPACE_END

#endif