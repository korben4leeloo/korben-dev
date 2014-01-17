//*****************************************************************************
//
//	Class:		OkdDefaultResourceAllocator
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdDefaultResourceAllocator_h__
#define __OrkidEngine_OkdDefaultResourceAllocator_h__

#include	"Root.h"

template<class T>
class OkdDefaultResourceAllocator: public OkdResourceAllocator<T>
{
public:
		OkdDefaultResourceAllocator();

private:
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		OkdDefaultResourceAllocator constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
OkdDefaultResourceAllocator<T>::OkdDefaultResourceAllocator()
{
	_pfnAllocateResource = [] ()
	{
		return	( new T() );
	};
}

#endif
