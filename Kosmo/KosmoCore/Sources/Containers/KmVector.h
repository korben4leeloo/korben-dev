//*****************************************************************************
//
//	Class:		KmVector
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __KosmoCore_KmVector_h__
#define __KosmoCore_KmVector_h__

#include	"Root.h"

#define	KOSMO_DEFAULT_ALLOCATION_BASE	8

KOSMO_CORE_NAMESPACE_BEGIN

template<class T>
class KmVector
{
public:
				KmVector( const uint32 uiAllocationBase = KOSMO_DEFAULT_ALLOCATION_BASE );
				~KmVector();

	void		add( const T& item );
	const T&	get( const uint32 uiIndex ) const;
	T&			get( const uint32 uiIndex );

	void		resize( const uint32 uiCount );
	void		reserve( const uint32 uiCount );

private:
	T*			_pArray;
	uint32		_uiCount;
	uint32		_uiAllocated;
	uint32		_uiAllocationBase;
};

//*****************************************************************************
//	Template methods declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		KmVector constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
KmVector<T>::KmVector(const uint32	uiAllocationBase)
: _pArray			( NULL )
, _uiCount			( 0 )
, _uiAllocated		( 0 )
, _uiAllocationBase	( uiAllocationBase )
{
	
}

//-----------------------------------------------------------------------------
// Name:		KmVector destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
KmVector<T>::~KmVector()
{
	if	( _pArray )
	{
		delete[] _pArray;
	}
}

//-----------------------------------------------------------------------------
// Name:		add
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void KmVector<T>::add(const T&	item)
{
	resize( _uiCount + 1 );
	_pArray[_uiCount] = item;
}

//-----------------------------------------------------------------------------
// Name:		resize
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void KmVector<T>::resize(const uint32	uiCount)
{
	uint32 uiAllocationCount = ( uiCount + _uiAllocationBase ) / _uiAllocationBase;

	uiAllocationCount *= _uiAllocationBase;
}

KOSMO_CORE_NAMESPACE_END

#endif