//*****************************************************************************
//
//	Class:		OkdResourceHandle
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdResource_h__
#define __OrkidEngine_OkdResource_h__

#include	"Root.h"

#include	ORKID_CORE_H(Memory/OkdSharedPtr)
#include	ORKID_ENGINE_H(ResourceManager/OkdResourceId)

class OkdString;

class OkdResourceLocation
{

};

class OkdResourceHandle
{
public:
	inline 					OkdResourceHandle( const OkdResourceId& resourceId );
	inline					~OkdResourceHandle();

private:
	OkdResourceId			_resourceIdentifier;
	OkdResourceLocation*	_pLocation;
	OkdString*				_pName;
	void*					_pData;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		OkdResourceHandle constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourceHandle::OkdResourceHandle(const OkdResourceId&	resourceId)
: _resourceIdentifier	( resourceId )
, _pLocation			( 0 )
, _pName				( 0 )
, _pData				( 0 )
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdResourceHandle destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourceHandle::~OkdResourceHandle()
{
	
}

class OkdResourcePtr
{
public:
	friend class OkdResourceManager;

	inline							OkdResourcePtr( const OkdResourcePtr& sharedResource );
	inline							~OkdResourcePtr();

	inline OkdResourceHandle*				resource();
	inline const OkdResourceHandle*		resource() const;
	inline uint						getRefCount() const;

	inline void						load();
	inline void						unload();
	inline uint						getLoadRefCount() const;

	inline OkdResourcePtr&	operator=( const OkdResourcePtr& sharedPtr );

protected:
	inline							OkdResourcePtr( OkdResourceHandle* pSharedResource );

	inline void						destroy();
	
	OkdResourceHandle*					_pSharedResource;
	OkdSharedPtrRef*				_pRefCount;
	OkdSharedPtrRef*				_pLoadRefCount;
	bool							_bHasLoadRef;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		OkdResourceHandle constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourcePtr::OkdResourcePtr(OkdResourceHandle*	pSharedResource)
: _pSharedResource	( pSharedResource )
, _bHasLoadRef		( false )
{
	_pRefCount		= new OkdSharedPtrRef();
	_pLoadRefCount	= new OkdSharedPtrRef();

	_pRefCount->increase();
}

//-----------------------------------------------------------------------------
// Name:		OkdResourcePtr copy constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourcePtr::OkdResourcePtr(const OkdResourcePtr&	sharedPtr)
: _pSharedResource	( sharedPtr._pSharedResource )
, _pRefCount		( sharedPtr._pRefCount )
, _pLoadRefCount	( sharedPtr._pLoadRefCount )
, _bHasLoadRef		( false )
{
	_pRefCount->increase();
}

//-----------------------------------------------------------------------------
// Name:		OkdResourcePtr destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourcePtr::~OkdResourcePtr()
{
	if	( _bHasLoadRef )
	{
		unload();
	}

	if	( _pRefCount->decrease() == 0 )
	{
		destroy();
	}
}

//-----------------------------------------------------------------------------
// Name:		OkdResourcePtr operator=
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourcePtr& OkdResourcePtr::operator=( const OkdResourcePtr& sharedPtr )
{
	if	( &sharedPtr != this )
	{
		if	( _bHasLoadRef )
		{
			unload();
		}

		if	( _pRefCount->decrease() == 0 )
		{
			destroy();
		}

		_pSharedResource	= sharedPtr._pSharedResource;
		_pRefCount			= sharedPtr._pRefCount;
		_pLoadRefCount		= sharedPtr._pLoadRefCount;

		_pRefCount->increase();
	}

	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		destroy
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdResourcePtr::destroy()
{
	ORKID_ASSERT( _pLoadRefCount->getRefCount() == 0 );

	if	( _pSharedResource )
	{
		delete _pSharedResource;
	}

	delete _pLoadRefCount;
	delete _pRefCount;
}

//-----------------------------------------------------------------------------
// Name:		load
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdResourcePtr::load()
{
	ORKID_ASSERT( _bHasLoadRef == false );

	if	( _bHasLoadRef == false )
	{
		//
		// Load resource
		//

		_bHasLoadRef = true;
	}
}

//-----------------------------------------------------------------------------
// Name:		unload
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdResourcePtr::unload()
{
	ORKID_ASSERT( _pLoadRefCount->getRefCount() > 0 );
	ORKID_ASSERT( _bHasLoadRef );

	if	( _bHasLoadRef )
	{
		if	( _pLoadRefCount->decrease() == 0 )
		{
			//
			// unload resource
			//
		}
	}

	_bHasLoadRef = false;
}

//-----------------------------------------------------------------------------
// Name:		resource
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourceHandle*	OkdResourcePtr::resource()
{
	return	( _pSharedResource );
}

//-----------------------------------------------------------------------------
// Name:		resource
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const OkdResourceHandle*	OkdResourcePtr::resource() const
{
	return	( _pSharedResource );
}

//-----------------------------------------------------------------------------
// Name:		getRefCount
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
uint	OkdResourcePtr::getRefCount() const
{
	return	( _pRefCount->getRefCount() );
}

//-----------------------------------------------------------------------------
// Name:		getLoadRefCount
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
uint	OkdResourcePtr::getLoadRefCount() const
{
	return	( _pLoadRefCount->getRefCount() );
}

#endif