//*****************************************************************************
//
//	Class:		OkdResourceMap
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdResourceMap_h__
#define __OrkidEngine_OkdResourceMap_h__

#include	"Root.h"

#include	ORKID_ENGINE_H(Resources/Allocators/OkdResourceAllocator)

template<class T, class AllocatorType = OkdResourceAllocator<T>>
class OkdResourceMap: public OkdMap<OkdResourceKey, T*>
{
public:
					OkdResourceMap();
	T*				allocate();

private:
	AllocatorType	_allocator;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		OkdResourceMap constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, class AllocatorType>
OkdResourceMap<T, AllocatorType>::OkdResourceMap()
{

}

//-----------------------------------------------------------------------------
// Name:		allocate
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, class AllocatorType>
T*	OkdResourceMap<T, AllocatorType>::allocate()
{
	return	( _allocator() );
}

#endif
