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

#define	KOSMO_DEFAULT_REALLOC_SIZE	8

KOSMO_CORE_NAMESPACE_BEGIN

template<class T>
class KmVector
{
public:
					KmVector( const uint32 uiReallocSize = KOSMO_DEFAULT_REALLOC_SIZE );
					~KmVector();

	void			add( const T& value );
	void			remove( const uint32 uiIndex );

	inline uint32	getSize() const;

	inline T&		operator[]( const uint32 nIndex );

	void			resize( const uint32 uiSize, const T& defaultValue = T() );
	void			reserve( const uint32 uiSize );
	void			shrink();

private:
	void			destroy();

	T*				_pArray;
	uint32			_uiSize;
	uint32			_uiAllocatedSize;
	uint32			_uiReallocSize;
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
KmVector<T>::KmVector(const uint32	uiReallocSize)
: _pArray			( NULL )
, _uiSize			( 0 )
, _uiAllocatedSize	( 0 )
, _uiReallocSize	( uiReallocSize )
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
	destroy();
}

//-----------------------------------------------------------------------------
// Name:		destroy
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void KmVector<T>::destroy()
{
	for	( uint32 i = 0; i < _uiSize; i++ )
	{
		( _pArray + i )->~T();
	}

	delete reinterpret_cast<KmByte*>( _pArray );

	_pArray		= NULL;
	_uiSize	= 0;
}

//-----------------------------------------------------------------------------
// Name:		add
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void KmVector<T>::add(const T&	value)
{
	resize( _uiSize + 1, value );
}

//-----------------------------------------------------------------------------
// Name:		remove
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void KmVector<T>::remove(const uint32	uiIndex)
{
	KOSMO_ASSERT( uiIndex < _uiSize );

	if	( uiIndex < _uiSize )
	{
		for	( uint32 i = uiIndex; i < _uiSize - 1; i++ )
		{
			_pArray[i] = _pArray[i+1];
		}

		resize( _uiSize - 1 );
	}
}

//-----------------------------------------------------------------------------
// Name:		getSize
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
uint32 KmVector<T>::getSize() const
{
	return	( _uiSize );
}

//-----------------------------------------------------------------------------
// Name:		operator[]
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
T& KmVector<T>::operator[](const uint32	uiIndex)
{
	KOSMO_ASSERT( uiIndex < _uiSize );
	return	( _pArray[uiIndex] );
}

//-----------------------------------------------------------------------------
// Name:		resize
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void KmVector<T>::resize(const uint32	uiSize, 
						 const T&		defaultValue)
{
	if	( uiSize != _uiSize )
	{
		uint32 uiAllocationSize = ( ( uiSize % _uiReallocSize ) != 0 ) ? ( ( uiSize + _uiReallocSize ) / _uiReallocSize ) * _uiReallocSize
																		  : uiSize;

		if	( uiAllocationSize > _uiAllocatedSize )
		{
			T* pArray = reinterpret_cast<T*>( new KmByte[uiAllocationSize*sizeof(T)] );

			// Copy existing values
			for	( uint32 i = 0; i < _uiSize; i++ )
			{
				new ( pArray + i ) T( _pArray[i] );
			}

			// Construct new values
			for	( uint32 i = _uiSize; i < uiSize; i++ )
			{
				new ( pArray + i ) T( defaultValue );
			}

			destroy();

			_pArray				= pArray;
			_uiAllocatedSize	= uiAllocationSize;
		}
		else
		{
			KOSMO_ASSERT( _pArray );

			// Destruct old values
			for	( uint32 i = uiSize; i < _uiSize; i++ )
			{
				( _pArray + i )->~T();
			}

			// Construct new values
			for	( uint32 i = _uiSize; i < uiSize; i++ )
			{
				new ( _pArray + i ) T( defaultValue );
			}
		}

		_uiSize = uiSize;
	}
}

//-----------------------------------------------------------------------------
// Name:		shrink
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void KmVector<T>::shrink()
{
	uint32 uiAllocationSize = ( ( _uiSize % _uiReallocSize ) != 0 ) ? ( ( _uiSize + _uiReallocSize ) / _uiReallocSize ) * _uiReallocSize
																		  : _uiSize;

	if	( uiAllocationSize < _uiAllocatedSize )
	{
		T* pArray = reinterpret_cast<T*>( new KmByte[uiAllocationSize*sizeof(T)] );

		// Copy existing values
		for	( uint32 i = 0; i < _uiSize; i++ )
		{
			new ( pArray + i ) T( _pArray[i] );
		}

		destroy();

		_pArray				= pArray;
		_uiAllocatedSize	= uiAllocationSize;
	}
}

KOSMO_CORE_NAMESPACE_END

#endif