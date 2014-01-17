//*****************************************************************************
//
//	Class:		OkdResourceAllocator
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdResourceAllocator_h__
#define __OrkidEngine_OkdResourceAllocator_h__

#include	"Root.h"

template<class T>
class OkdResourceAllocator
{
private:
	typedef T* (*pfnResourceAllocFunc)();

public:
							OkdResourceAllocator();

	void					setAllocatorFunc( pfnResourceAllocFunc pfnAllocateRessource );
	T*						operator()();

protected:
	pfnResourceAllocFunc	_pfnAllocateResource;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		OkdResourceAllocator constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
OkdResourceAllocator<T>::OkdResourceAllocator()
: _pfnAllocateResource( 0 )
{
	
}

//-----------------------------------------------------------------------------
// Name:		setAllocatorFunc
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void OkdResourceAllocator<T>::setAllocatorFunc(pfnResourceAllocFunc	pfnAllocateRessource)
{
	_pfnAllocateResource = pfnAllocateResource;
}

//-----------------------------------------------------------------------------
// Name:		operator()
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
T* OkdResourceAllocator<T>::operator()()
{
	return	( _pfnAllocateResource() );
}

#endif
