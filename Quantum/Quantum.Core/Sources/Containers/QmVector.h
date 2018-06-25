//*****************************************************************************
//
//	Class:		QmVector
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __QUANTUM_CORE_VECTOR_H__
#define __QUANTUM_CORE_VECTOR_H__

#include <new>

#define QUANTUM_VECTOR_DEFAULT_REALLOC_SIZE 8

template<class T>
class QmVector
{
public:
					QmVector( const uint32 uiReallocSize = QUANTUM_VECTOR_DEFAULT_REALLOC_SIZE );
					~QmVector();

	void			pushBack( const T& value );

	void			remove( const uint32 uiIndex );
	void			remove( const T& value );

	inline uint32	size() const;

	inline T&		operator[]( const uint32 nIndex );

	void			resize( const uint32 uiSize, const T& defaultValue = T() );
	void			reserve( const uint32 uiSize );
	void			shrink();

	void			clear();
	void			deleteAll();

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
// Name:		QmVector constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
QmVector<T>::QmVector(const uint32	uiReallocSize)
: _pArray			( nullptr )
, _uiSize			( 0 )
, _uiAllocatedSize	( 0 )
, _uiReallocSize	( uiReallocSize )
{
	
}

//-----------------------------------------------------------------------------
// Name:		QmVector destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
QmVector<T>::~QmVector()
{
	destroy();
}

//-----------------------------------------------------------------------------
// Name:		destroy
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void QmVector<T>::destroy()
{
	clear();

	delete[] reinterpret_cast<char*>( _pArray );

	_pArray				= nullptr;
	_uiAllocatedSize	= 0;
}

//-----------------------------------------------------------------------------
// Name:		clear
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void QmVector<T>::clear()
{
	for	( uint32 i = 0; i < _uiSize; i++ )
	{
		( _pArray + i )->~T();
	}

	_uiSize	= 0;
}

//-----------------------------------------------------------------------------
// Name:		deleteAll
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void QmVector<T>::deleteAll()
{
	for	( uint32 i = 0; i < _uiSize; i++ )
	{
		delete _pArray[i];
	}

	_uiSize	= 0;
}

//-----------------------------------------------------------------------------
// Name:		pushBack
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void QmVector<T>::pushBack(const T&	value)
{
	resize( _uiSize + 1, value );
	new ( &_pArray[_uiSize-1] ) T( value );
}

//-----------------------------------------------------------------------------
// Name:		remove
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void QmVector<T>::remove(const uint32	uiIndex)
{
	QUANTUM_ASSERT( uiIndex < _uiSize );

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
// Name:		remove
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void QmVector<T>::remove(const T& value)
{
	for	( uint32 i = 0; i < _uiSize; i++ )
	{
		while	( _pArray[i] == value )
		{
			for	( uint32 j = i; j < _uiSize - 1; j++ )
			{
				_pArray[j] = _pArray[j+1];
			}

			(&_pArray[_uiSize-1])->~T();
			_uiSize--;
		}
	}
}

//-----------------------------------------------------------------------------
// Name:		size
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
uint32 QmVector<T>::size() const
{
	return	( _uiSize );
}

//-----------------------------------------------------------------------------
// Name:		operator[]
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
T& QmVector<T>::operator[](const uint32	uiIndex)
{
	QUANTUM_ASSERT( uiIndex < _uiSize );
	return	( _pArray[uiIndex] );
}

//-----------------------------------------------------------------------------
// Name:		resize
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void QmVector<T>::resize(const uint32	uiSize, 
						 const T&		defaultValue)
{
	if	( uiSize != _uiSize )
	{
		uint32 uiAllocationSize = ( ( uiSize % _uiReallocSize ) != 0 ) ? ( ( uiSize + _uiReallocSize ) / _uiReallocSize ) * _uiReallocSize
																		  : uiSize;

		if	( uiAllocationSize > _uiAllocatedSize )
		{
			T* pArray = reinterpret_cast<T*>( new char[uiAllocationSize*sizeof(T)] );

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
			QUANTUM_ASSERT( _pArray );

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
void QmVector<T>::shrink()
{
	uint32 uiAllocationSize = ( ( _uiSize % _uiReallocSize ) != 0 ) ? ( ( _uiSize + _uiReallocSize ) / _uiReallocSize ) * _uiReallocSize
																	: _uiSize;

	if	( uiAllocationSize < _uiAllocatedSize )
	{
		T* pArray = reinterpret_cast<T*>( new char[uiAllocationSize*sizeof(T)] );

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

#endif