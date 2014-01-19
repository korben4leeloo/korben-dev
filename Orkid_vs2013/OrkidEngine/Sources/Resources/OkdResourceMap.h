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

#include	ORKID_CORE_H(Containers/OkdMap)
#include	ORKID_ENGINE_H(Resources/Allocators/OkdResourceAllocator)
#include	ORKID_ENGINE_H(Resources/Allocators/OkdResourceAllocator)

//template<class T, class AllocatorType/* = OkdResourceAllocator<T>*/>
//class OkdResourceMap: public OkdMap<OkdResourceKey, T*>
//{
//public:
//					OkdResourceMap();
//	T*				allocate();
//
//private:
//	AllocatorType	_allocator;
//};
//
////*****************************************************************************
////	Inline functions declarations
////*****************************************************************************
//
////-----------------------------------------------------------------------------
//// Name:		OkdResourceMap constructor
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T, class AllocatorType>
//OkdResourceMap<T, AllocatorType>::OkdResourceMap()
//{
//
//}
//
////-----------------------------------------------------------------------------
//// Name:		allocate
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T, class AllocatorType>
//T*	OkdResourceMap<T, AllocatorType>::allocate()
//{
//	return	( _allocator() );
//}

template<class T>
class OkdResourceMap: public OkdMap<OkdResourceKey, T*>
{
public:
								OkdResourceMap();

	T*							allocate();
	void						setAllocator( pfnOkdResourceAllocator<T> fnResourceAllocator );

protected:
	pfnOkdResourceAllocator<T>	_fnAllocator;
};

template<class T>
class OkdDefaultResourceMap: public OkdResourceMap<T>
{
public:
	OkdDefaultResourceMap();
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		OkdResourceMap constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
OkdResourceMap<T>::OkdResourceMap()
: _fnAllocator( 0 )
{

}

//-----------------------------------------------------------------------------
// Name:		allocate
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
T*	OkdResourceMap<T>::allocate()
{
	if	( _fnAllocator )
	{
		return	( _fnAllocator() );
	}

	return	( 0 );
}

//-----------------------------------------------------------------------------
// Name:		setAllocator
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void	OkdResourceMap<T>::setAllocator(pfnOkdResourceAllocator<T>	fnResourceAllocator)
{
	_fnAllocator = fnResourceAllocator;
}

//-----------------------------------------------------------------------------
// Name:		OkdDefaultResourceMap constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
OkdDefaultResourceMap<T>::OkdDefaultResourceMap()
{
	_fnAllocator = []()
	{
		return	( new T() );
	};
}

#endif
