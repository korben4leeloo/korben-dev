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

template<class T, bool UseDefaultAllocator = true>
class OkdResourceAllocator
{
public:
	T* operator()();
};

template<class T>
class OkdResourceAllocator<T, false>
{
public:
	T* operator()();
};

template<class T, class AllocatorType = OkdResourceAllocator<T, std::is_abstract<T>::value>>
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
// Name:		operator()
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, bool UseDefaultAllocator>
T* OkdResourceAllocator<T, UseDefaultAllocator>::operator()()
{
	return	( new T() );
}

//-----------------------------------------------------------------------------
// Name:		operator()
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
T* OkdResourceAllocator<T, false>::operator()()
{
	return	( 0 );
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
