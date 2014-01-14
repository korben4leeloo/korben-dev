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

template<class T>
class OkdResourceAllocator
{
	T* operator()();
};

template<class T, class AllocatorType = OkdResourceAllocator<T>>
class OkdResourceMap: public OkdMap<OkdResourceKey, T*>
{
public:
					OkdResourceMap();

private:
	AllocatorType	_allocator;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		operator()
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
T* OkdResourceAllocator<T>::operator()()
{
	return	( new T() );
}

//-----------------------------------------------------------------------------
// Name:		OkdResourceMap constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, class AllocatorType>
OkdResourceMap<T, AllocatorType>::OkdResourceMap()
{

}

#endif
