//*****************************************************************************
//
//	File:		OkdResourcePtr.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdResourcePtr.h"

#include	ORKID_ENGINE_H(ResourceManager/OkdResourceHandle)

//-----------------------------------------------------------------------------
// Name:		OkdResourceHandle constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourcePtr::OkdResourcePtr(OkdResourceHandle*	pResourceHandle)
: _pResourceHandle( pResourceHandle )
{
	_pResourceHandle->addRef();
}

//-----------------------------------------------------------------------------
// Name:		OkdResourcePtr copy constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourcePtr::OkdResourcePtr(const OkdResourcePtr&	resourcePtr)
: _pResourceHandle( resourcePtr._pResourceHandle )
{
	_pResourceHandle->addRef();
}

//-----------------------------------------------------------------------------
// Name:		OkdResourcePtr destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourcePtr::~OkdResourcePtr()
{
	/*if	( _bHasLoadRef )
	{
		unload();
	}

	if	( _pRefCount->decrease() == 0 )
	{
		destroy();
	}*/

	_pResourceHandle->removeRef();
}

//-----------------------------------------------------------------------------
// Name:		OkdResourcePtr operator=
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourcePtr& OkdResourcePtr::operator=( const OkdResourcePtr& resourcePtr )
{
	/*if	( &sharedPtr != this )
	{
		if	( _bHasLoadRef )
		{
			unload();
		}

		if	( _pRefCount->decrease() == 0 )
		{
			destroy();
		}

		_pResourceHandle	= sharedPtr._pResourceHandle;
		_pRefCount			= sharedPtr._pRefCount;
		_pLoadRefCount		= sharedPtr._pLoadRefCount;

		_pRefCount->increase();
	}*/

	if	( _pResourceHandle )
	{
		_pResourceHandle->removeRef();
	}

	_pResourceHandle = resourcePtr._pResourceHandle;
	_pResourceHandle->addRef();

	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		destroy
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdResourcePtr::destroy()
{
	/*ORKID_ASSERT( _pLoadRefCount->getRefCount() == 0 );

	OrkidEngine::instance()->getResourceManager()->deleteResource( _pResourceHandle->getResourceId() );

	delete _pLoadRefCount;
	delete _pRefCount;*/
}

////-----------------------------------------------------------------------------
//// Name:		load
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//void	OkdResourcePtr::load()
//{
//	ORKID_ASSERT( _bHasLoadRef == false );
//
//	if	( _bHasLoadRef == false )
//	{
//		//
//		// Load resource
//		//
//
//		_bHasLoadRef = true;
//	}
//}
//
////-----------------------------------------------------------------------------
//// Name:		unload
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//void	OkdResourcePtr::unload()
//{
//	ORKID_ASSERT( _pLoadRefCount->getRefCount() > 0 );
//	ORKID_ASSERT( _bHasLoadRef );
//
//	if	( _bHasLoadRef )
//	{
//		if	( _pLoadRefCount->decrease() == 0 )
//		{
//			//
//			// unload resource
//			//
//		}
//	}
//
//	_bHasLoadRef = false;
//}
