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

class OkdSharedPtrRef
{
public:
	inline		OkdSharedPtrRef();
	inline 		~OkdSharedPtrRef();

	inline uint increase();
	inline uint decrease();

	inline uint	getRefCount() const;

private:
	uint		_uiRefCount;
};

template<class T>
class OkdSharedPtr
{
public:
	inline					OkdSharedPtr();
	inline					OkdSharedPtr( T* pObject );
	inline					OkdSharedPtr( const OkdSharedPtr& sharedPtr );
	inline					~OkdSharedPtr();

	inline T*				ptr();
	inline const T*			ptr() const;
	inline uint				getRefCount() const;

	inline OkdSharedPtr&	operator=( const OkdSharedPtr& sharedPtr );

protected:
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
OkdSharedPtrRef::OkdSharedPtrRef()
: _uiRefCount( 0 )
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdSharedPtrRef destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdSharedPtrRef::~OkdSharedPtrRef()
{

}

//-----------------------------------------------------------------------------
// Name:		increase
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
uint	OkdSharedPtrRef::increase()
{
	_uiRefCount++;
	return	( _uiRefCount );
}

//-----------------------------------------------------------------------------
// Name:		decrease
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
uint	OkdSharedPtrRef::decrease()
{
	ORKID_ASSERT( _uiRefCount > 0 );

	if	( _uiRefCount > 0 )
	{
		_uiRefCount--;
	}

	return	( _uiRefCount );
}

//-----------------------------------------------------------------------------
// Name:		getRefCount
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
uint	OkdSharedPtrRef::getRefCount() const
{
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

//-----------------------------------------------------------------------------
// Name:		ptr
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
T*	OkdSharedPtr<T>::ptr()
{
	return	( _pObject );
}

//-----------------------------------------------------------------------------
// Name:		ptr
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
const T*	OkdSharedPtr<T>::ptr() const
{
	return	( _pObject );
}

//-----------------------------------------------------------------------------
// Name:		increase
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
uint	OkdSharedPtr<T>::getRefCount() const
{
	return	( _pRefCount->getRefCount() );
}

#endif
