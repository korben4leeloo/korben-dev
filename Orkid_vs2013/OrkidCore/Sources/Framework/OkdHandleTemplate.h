//*****************************************************************************
//
//	Class:		OkdHandleTemplate
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdHandleTemplate_h__
#define __OrkidCore_OkdHandleTemplate_h__

#include	"Root.h"

template<class T, T handleBitCount>
class OkdHandleTemplate
{
public:
	T	_uiIndex		: handleBitCount;
	T	_uiGeneration	: 8 * sizeof(T) - handleBitCount;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif
