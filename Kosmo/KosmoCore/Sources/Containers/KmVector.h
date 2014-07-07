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
#include	<new>

#define	KOSMO_DEFAULT_ALLOCATION_BASE	8

KOSMO_CORE_NAMESPACE_BEGIN

template<class T>
class KmVector
{
public:
					KmVector( const uint32 uiAllocationBase = KOSMO_DEFAULT_ALLOCATION_BASE );
					~KmVector();

	void			add( const T& item );

	inline T&		operator[]( const uint32 nIndex );

	void			resize( const uint32 uiCount );
	void			reserve( const uint32 uiCount );

private:
	T*				_pArray;
	uint32			_uiCount;
	uint32			_uiAllocatedCount;
	uint32			_uiAllocationBase;
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
, _uiAllocatedCount	( 0 )
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
	delete[] _pArray;
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
	_pArray[_uiCount-1] = item;
}

//-----------------------------------------------------------------------------
// Name:		operator[]
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
T& KmVector<T>::operator[](const uint32	uiIndex)
{
	KOSMO_ASSERT( uiIndex < _uiCount );
	return	( _pArray[uiIndex] );
}

//-----------------------------------------------------------------------------
// Name:		resize
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void KmVector<T>::resize(const uint32	uiCount)
{
	uint32 uiAllocationCount = ( ( uiCount % _uiAllocationBase ) != 0 ) ? ( ( uiCount + _uiAllocationBase ) / _uiAllocationBase ) * _uiAllocationBase
																		: uiCount;

	if	( uiAllocationCount > _uiAllocatedCount )
	{
		T* pArray = new T[uiAllocationCount];

		if	( _pArray )
		{
			for	( uint32 i = 0; i < _uiCount; i++ )
			{
				pArray[i] = _pArray[i];
			}

			delete[] _pArray;
		}

		_pArray				= pArray;
		_uiAllocatedCount	= uiAllocationCount;
	}

	KOSMO_ASSERT( _pArray );

	if	( uiCount < _uiCount )
	{
		for	( uint32 i = uiCount; i < _uiCount; i++ )
		{
			( _pArray + i )->~T();
		}
	}
	else if	( uiCount > _uiCount )
	{
		for	( uint32 i = _uiCount; i < uiCount; i++ )
		{
			T* p = _pArray + i;
			new (p) T();
		}
	}

	_uiCount = uiCount;
}

KOSMO_CORE_NAMESPACE_END

#endif