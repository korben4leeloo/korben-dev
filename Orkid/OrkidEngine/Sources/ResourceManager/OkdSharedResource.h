//*****************************************************************************
//
//	Class:		OkdSharedResource
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdSharedResource_h__
#define __OrkidEngine_OkdSharedResource_h__

#include	"Root.h"

#include	ORKID_CORE_H(Memory/OkdSharedPtr)
//#include	ORKID_CORE_H(String/OkdString)

class OkdString;

class OkdResourceLocation
{

};

class OkdResourceIdentifier
{
	uint	_uiResourceTypeId;
	int		_nResourceId;
};

class OkdSharedResource
{
public:
	inline 					OkdSharedResource( const OkdResourceIdentifier& resourceIdentifier );
	inline					~OkdSharedResource();

private:
	OkdResourceIdentifier	_resourceIdentifier;
	OkdResourceLocation*	_pLocation;
	OkdString*				_pName;
	void*					_pData;
};

class OkdSharedResourcePtr
{
public:
	//friend class OkdResourceManager;

	inline							OkdSharedResourcePtr( const OkdSharedResourcePtr& sharedResource );
	inline							~OkdSharedResourcePtr();

	inline OkdSharedResource*		resource();
	inline const OkdSharedResource*	resource() const;
	inline uint						getRefCount() const;

	inline void						load();
	inline void						unload();
	inline uint						getLoadRefCount() const;

	inline OkdSharedResourcePtr&	operator=( const OkdSharedResourcePtr& sharedPtr );

protected:
	inline							OkdSharedResourcePtr( OkdSharedResource* pSharedResource );

	inline void						destroy();
	
	OkdSharedResource*				_pSharedResource;
	OkdSharedPtrRef*				_pRefCount;
	OkdSharedPtrRef*				_pLoadRefCount;
	bool							_bHasLoadRef;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		OkdSharedResource constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdSharedResource::OkdSharedResource(const OkdResourceIdentifier&	resourceIdentifier)
: _resourceIdentifier	( resourceIdentifier )
, _pLocation			( 0 )
, _pName				( 0 )
, _pData				( 0 )
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdSharedResource destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdSharedResource::~OkdSharedResource()
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdSharedResource constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdSharedResourcePtr::OkdSharedResourcePtr(OkdSharedResource*	pSharedResource)
: _pSharedResource	( pSharedResource )
, _bHasLoadRef		( false )
{
	_pRefCount		= new OkdSharedPtrRef();
	_pLoadRefCount	= new OkdSharedPtrRef();

	_pRefCount->increase();
}

//-----------------------------------------------------------------------------
// Name:		OkdSharedResourcePtr copy constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdSharedResourcePtr::OkdSharedResourcePtr(const OkdSharedResourcePtr&	sharedPtr)
: _pSharedResource	( sharedPtr._pSharedResource )
, _pRefCount		( sharedPtr._pRefCount )
, _pLoadRefCount	( sharedPtr._pLoadRefCount )
, _bHasLoadRef		( false )
{
	_pRefCount->increase();
}

//-----------------------------------------------------------------------------
// Name:		OkdSharedResourcePtr destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdSharedResourcePtr::~OkdSharedResourcePtr()
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
// Name:		OkdSharedResourcePtr operator=
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdSharedResourcePtr& OkdSharedResourcePtr::operator=( const OkdSharedResourcePtr& sharedPtr )
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
void	OkdSharedResourcePtr::destroy()
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
void	OkdSharedResourcePtr::load()
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
void	OkdSharedResourcePtr::unload()
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
OkdSharedResource*	OkdSharedResourcePtr::resource()
{
	return	( _pSharedResource );
}

//-----------------------------------------------------------------------------
// Name:		resource
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const OkdSharedResource*	OkdSharedResourcePtr::resource() const
{
	return	( _pSharedResource );
}

//-----------------------------------------------------------------------------
// Name:		getRefCount
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
uint	OkdSharedResourcePtr::getRefCount() const
{
	return	( _pRefCount->getRefCount() );
}

//-----------------------------------------------------------------------------
// Name:		getLoadRefCount
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
uint	OkdSharedResourcePtr::getLoadRefCount() const
{
	return	( _pLoadRefCount->getRefCount() );
}


//template<class T>
//class OkdSharedResource
//{
//public:
//	inline 					OkdSharedResource( const OkdString& strResourceName, const OkdString& strResourceLocName, const ResourceLocation eResourceLoc, T* pResource );
//	inline					~OkdSharedResource();
//
//private:
//	OkdString			_strResourceName;
//	OkdString			_strResourceLocName;
//	ResourceLocation	_eResourceLoc;
//	T*					_pResource;
//};
//
//template<class T, void (*TLoadFunc)( OkdSharedResource<T>* pResource )>
//class OkdSharedResourcePtr
//{
//public:
//	friend class OkdResourceManager;
//
//	inline							OkdSharedResourcePtr( const OkdSharedResourcePtr& sharedResource );
//	inline							~OkdSharedResourcePtr();
//
//	inline T*						resource();
//	inline const T*					resource() const;
//	inline uint						getRefCount() const;
//
//	inline void						load();
//	inline void						unload();
//	inline uint						getLoadRefCount() const;
//
//	inline OkdSharedResourcePtr&	operator=( const OkdSharedResourcePtr& sharedPtr );
//
//protected:
//	inline							OkdSharedResourcePtr( OkdSharedResource<T>* pSharedResource );
//
//	inline void						destroy();
//	
//	OkdSharedResource<T>*			_pSharedResource;
//	OkdSharedPtrRef*				_pRefCount;
//	OkdSharedPtrRef*				_pLoadRefCount;
//	bool							_bHasLoadRef;
//};
//
////*****************************************************************************
////	Inline functions declarations
////*****************************************************************************
//
////-----------------------------------------------------------------------------
//// Name:		OkdSharedResource constructor
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T>
//OkdSharedResource<T>::OkdSharedResource(const OkdString&		strResourceName, 
//										const OkdString&		strResourceLocName, 
//										const ResourceLocation	eResourceLoc, 
//										T*						pResource )
//: _strResourceName		( strResourceName )
//, _strResourceLocName	( strResourceLocName )
//, _eResourceLoc			( eResourceLoc )
//, _pResource			( pResource )
//{
//	
//}
//
////-----------------------------------------------------------------------------
//// Name:		OkdSharedResource destructor
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T>
//OkdSharedResource<T>::~OkdSharedResource()
//{
//	delete _pResource;
//}
//
////-----------------------------------------------------------------------------
//// Name:		OkdSharedResource constructor
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T, void (*TLoadFunc)( OkdSharedResource<T>* pResource )>
//OkdSharedResourcePtr<T, TLoadFunc>::OkdSharedResourcePtr(OkdSharedResource<T>*	pSharedResource)
//: _pSharedResource	( pSharedResource )
//, _bHasLoadRef		( false )
//{
//	_pRefCount		= new OkdSharedPtrRef();
//	_pLoadRefCount	= new OkdSharedPtrRef();
//
//	_pRefCount->increase();
//}
//
////-----------------------------------------------------------------------------
//// Name:		OkdSharedResourcePtr copy constructor
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T, void (*TLoadFunc)( OkdSharedResource<T>* pResource )>
//OkdSharedResourcePtr<T, TLoadFunc>::OkdSharedResourcePtr(const OkdSharedResourcePtr&	sharedPtr)
//: _pSharedResource	( sharedPtr._pSharedResource )
//, _pRefCount		( sharedPtr._pRefCount )
//, _pLoadRefCount	( sharedPtr._pLoadRefCount )
//, _bHasLoadRef		( false )
//{
//	_pRefCount->increase();
//}
//
////-----------------------------------------------------------------------------
//// Name:		OkdSharedResourcePtr destructor
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T, void (*TLoadFunc)( OkdSharedResource<T>* pResource )>
//OkdSharedResourcePtr<T, TLoadFunc>::~OkdSharedResourcePtr()
//{
//	if	( _bHasLoadRef )
//	{
//		unload();
//	}
//
//	if	( _pRefCount->decrease() == 0 )
//	{
//		destroy();
//	}
//}
//
////-----------------------------------------------------------------------------
//// Name:		OkdSharedResourcePtr operator=
////
//			unload();
//		}
//
//		if	( _pRefCount->decrease() == 0 )
//		{
//			destroy();
//		}
//
//		_pSharedResource	= sharedPtr._pSharedResource;
//		_pRefCount			= sharedPtr._pRefCount;
//		_pLoadRefCount		= sharedPtr._pLoadRefCount;
//
//		_pRefCount->increase();
//	}
//
//	return	( *this );
//}
//
////-----------------------------------------------------------------------------
//// Name:		destroy
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T, void (*TLoadFunc)( OkdSharedResource<T>* pResource )>
//void	OkdSharedResourcePtr<T, TLoadFunc>::destroy()
//{
//	ORKID_ASSERT( _pLoadRefCount->getRefCount() == 0 );
//
//	if	( _pSharedResource )
//	{
//		delete _pSharedResource;
//	}
//
//	delete _pLoadRefCount;
//	delete _pRefCount;
//}
//
////-----------------------------------------------------------------------------
//// Name:		load
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T, void (*TLoadFunc)( OkdSharedResource<T>* pResource )>
//void	OkdSharedResourcePtr<T, TLoadFunc>::load()
//{
//	ORKID_ASSERT( _bHasLoadRef == false );
//
//	if	( _bHasLoadRef == false )
//	{
//		if	( _pLoadRefCount->increase() == 1 )
//		{
//			TLoadFunc( _pSharedResource );
//		}
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
//template<class T, void (*TLoadFunc)( OkdSharedResource<T>* pResource )>
//void	OkdSharedResourcePtr<T, TLoadFunc>::unload()
//{
//	ORKID_ASSERT( _pLoadRefCount->getRefCount() > 0 );
//	ORKID_ASSERT( _bHasLoadRef );
//
//	if	( _bHasLoadRef )
//	{
//		if	( _pLoadRefCount->decrease() == 0 )
//		{
//			// unload resource
//		}
//	}
//
//	_bHasLoadRef = false;
//}
//
////-----------------------------------------------------------------------------
//// Name:		resource
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T, void (*TLoadFunc)( OkdSharedResource<T>* pResource )>
//T*	OkdSharedResourcePtr<T, TLoadFunc>::resource()
//{
//	return	( _pResource );
//}
//
////-----------------------------------------------------------------------------
//// Name:		resource
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T, void (*TLoadFunc)( OkdSharedResource<T>* pResource )>
//const T*	OkdSharedResourcePtr<T, TLoadFunc>::resource() const
//{
//	return	( _pResource );
//}
//
////-----------------------------------------------------------------------------
//// Name:		getRefCount
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T, void (*TLoadFunc)( OkdSharedResource<T>* pResource )>
//uint	OkdSharedResourcePtr<T, TLoadFunc>::getRefCount() const
//{
//	return	( _pRefCount->getRefCount() );
//}
//
////-----------------------------------------------------------------------------
//// Name:		getLoadRefCount
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T, void (*TLoadFunc)( OkdSharedResource<T>* pResource )>
//uint	OkdSharedResourcePtr<T, TLoadFunc>::getLoadRefCount() const
//{
//	return	( _pLoadRefCount->getRefCount() );
//}

#endif