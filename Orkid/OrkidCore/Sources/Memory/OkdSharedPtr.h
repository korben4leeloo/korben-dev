//*****************************************************************************
//
//	Class:		OkdSharedPtr
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdSharedPtr_h__
#define __OrkidCore_OkdSharedPtr_h__

#include	"Root.h"

template<class T>
class OkdSharedPtr
{
private:
	class OkdSharedPtrRef
	{
	public:
		inline		OkdSharedPtrRef();
		inline 		~OkdSharedPtrRef();

		inline uint increase();
		inline uint decrease();

	private:
		uint		_uiRefCount;
	};

public:
	inline					OkdSharedPtr();
	inline					OkdSharedPtr( T* pObject );
	inline					OkdSharedPtr( const OkdSharedPtr& sharedPtr );
	inline					~OkdSharedPtr();

	inline OkdSharedPtr&	operator=( const OkdSharedPtr& sharedPtr );

private:
	inline void				destroy();

	T*						_pObject;
	OkdSharedPtrRef*		_pRefCount;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		OkdSharedPtrRef constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
OkdSharedPtr<T>::OkdSharedPtrRef::OkdSharedPtrRef()
: _uiRefCount( 0 )
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdSharedPtrRef destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
OkdSharedPtr<T>::OkdSharedPtrRef::~OkdSharedPtrRef()
{

}

//-----------------------------------------------------------------------------
// Name:		increase
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
uint	OkdSharedPtr<T>::OkdSharedPtrRef::increase()
{
	_uiRefCount++;
	return	( _uiRefCount );
}

//-----------------------------------------------------------------------------
// Name:		decrease
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
uint	OkdSharedPtr<T>::OkdSharedPtrRef::decrease()
{
	ORKID_ASSERT( _uiRefCount > 0 );

	if	( _uiRefCount > 0 )
	{
		_uiRefCount--;
	}

	return	( _uiRefCount );
}

//-----------------------------------------------------------------------------
// Name:		OkdSharedPtr constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
OkdSharedPtr<T>::OkdSharedPtr()
: _pObject( 0 )
{
	_pRefCount = new OkdSharedPtrRef();
	_pRefCount->increase();
}

//-----------------------------------------------------------------------------
// Name:		OkdSharedPtr constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
OkdSharedPtr<T>::OkdSharedPtr( T* pObject )
: _pObject( pObject )
{
	_pRefCount = new OkdSharedPtrRef();
	_pRefCount->increase();
}

//-----------------------------------------------------------------------------
// Name:		OkdSharedPtr copy constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
OkdSharedPtr<T>::OkdSharedPtr( const OkdSharedPtr& sharedPtr )
: _pObject		( sharedPtr._pObject )
, _pRefCount	( sharedPtr._pRefCount )
{
	_pRefCount->increase();
}

//-----------------------------------------------------------------------------
// Name:		OkdSharedPtr destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
OkdSharedPtr<T>::~OkdSharedPtr()
{
	if	( _pRefCount->decrease() == 0 )
	{
		destroy();
	}
}

//-----------------------------------------------------------------------------
// Name:		OkdSharedPtr operator=
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
OkdSharedPtr<T>& OkdSharedPtr<T>::operator=( const OkdSharedPtr& sharedPtr )
{
	if	( &sharedPtr != this )
	{
		if	( _pRefCount->decrease() == 0 )
		{
			destroy();
		}

		_pObject	= sharedPtr._pObject;
		_pRefCount	= sharedPtr._pRefCount;

		_pRefCount->increase();
	}

	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		destroy
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void	OkdSharedPtr<T>::destroy()
{
	if	( _pObject )
	{
		delete _pObject;
	}

	delete _pRefCount;
}

#endif
