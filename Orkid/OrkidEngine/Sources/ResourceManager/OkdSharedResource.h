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
#include	ORKID_CORE_H(String/OkdString)

template<class T, void (*TLoadFunc)( T* pResource )>
class OkdSharedResource: public OkdSharedPtr<T>
{
public:
	enum ResourceLocation
	{
		RES_LOC_MEMORY,
		RES_LOC_FILE
	};

								OkdSharedResource( const OkdString& strResourceName, const OkdString& strResourceLocName, const ResourceLocation eResourceLoc );
								OkdSharedResource( const OkdSharedResource& other );
	virtual						~OkdSharedResource();

	void						load();
	void						unload();

	//inline OkdSharedResource&	operator=( const OkdSharedResource& sharedPtr );

private:
	OkdString					_strResourceName;
	OkdString					_strResourceLocName;
	ResourceLocation			_eResourceLoc;
	OkdSharedPtrRef*			_pLoadRefCount;
	bool						_bHasLoadRef;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		OkdSharedResource constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, void (*TLoadFunc)( T* pResource )>
OkdSharedResource<T, TLoadFunc>::OkdSharedResource(const OkdString&			strResourceName, 
												   const OkdString&			strResourceLocName,
												   const ResourceLocation	eResourceLoc)
: OkdSharedPtr			( new T() )
, _strResourceName		( strResourceName )
, _strResourceLocName	( strResourceLocName )
, _eResourceLoc			( eResourceLoc )
, _bHasLoadRef			( false )
{
	_pLoadRefCount = new OkdSharedPtrRef();
}

//-----------------------------------------------------------------------------
// Name:		OkdSharedResource constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, void (*TLoadFunc)( T* pResource )>
OkdSharedResource<T, TLoadFunc>::OkdSharedResource(const OkdSharedResource& other)
: OkdSharedPtr			( other )
, _pLoadRefCount		( other._pLoadRefCount )
, _strResourceName		( other._strResourceName )
, _strResourceLocName	( other._strResourceLocName )
, _eResourceLoc			( other._eResourceLoc )
, _bHasLoadRef			( false )
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdSharedResource destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, void (*TLoadFunc)( T* pResource )>
OkdSharedResource<T, TLoadFunc>::~OkdSharedResource()
{
	if	( _bHasLoadRef )
	{
		unload();
	}
}

//-----------------------------------------------------------------------------
// Name:		load
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, void (*TLoadFunc)( T* pResource )>
void	OkdSharedResource<T, TLoadFunc>::load()
{
	if	( _bHasLoadRef == false )
	{
		if	( _pLoadRefCount->increase() == 1 )
		{
			TLoadFunc( pointer() );
		}

		_bHasLoadRef = true;
	}
}

//-----------------------------------------------------------------------------
// Name:		unload
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, void (*TLoadFunc)( T* pResource )>
void	OkdSharedResource<T, TLoadFunc>::unload()
{
	if	( _bHasLoadRef )
	{
		uint uiLoadRefCount = _pLoadRefCount->getRefCount();
		ORKID_ASSERT( uiLoadRefCount > 0 );
			
		if	( ( uiLoadRefCount > 0 ) && ( _pLoadRefCount->decrease() == 0 ) )
		{
			// unload resource
		}

		_bHasLoadRef = false;
	}
}

////-----------------------------------------------------------------------------
//// Name:		OkdSharedResource operator=
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T, void (*TLoadFunc)( T* pResource )>
//OkdSharedResource<T, TLoadFunc>& OkdSharedResource<T, TLoadFunc>::operator=( const OkdSharedResource& sharedPtr )
//{
//	OkdSharedPtr::operator=( sharedPtr );
//	/*if	( &sharedPtr != this )
//	{
//		if	( _pRefCount->decrease() == 0 )
//		{
//			destroy();
//		}
//
//		_pObject	= sharedPtr._pObject;
//		_pRefCount	= sharedPtr._pRefCount;
//
//		_pRefCount->increase();
//	}
//
//	return	( *this );*/
//}

//typedef void (*pfnLoadResource)( T* pResource );

//template<class T, void (*TLoadFunc)( T* pResource )>
//class OkdSharedResource
//{
//public:
//	enum ResourceLocation
//	{
//		RES_LOC_MEMORY,
//		RES_LOC_FILE
//	};
//
//						OkdSharedResource( const OkdString& strResourceName, const OkdString& strResourceLocName, const ResourceLocation eResourceLoc );
//	virtual				~OkdSharedResource();
//
//	void				load();
//	void				unload();
//
//private:
//	OkdString			_strResourceName;
//	OkdString			_strResourceLocName;
//	ResourceLocation	_eResourceLoc;
//	uint				_uiLoadRefCount;
//	OkdSharedPtr<T>		_resourcePtr;
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
//template<class T, void (*TLoadFunc)( T* pResource )>
//OkdSharedResource<T, TLoadFunc>::OkdSharedResource(const OkdString&			strResourceName, 
//												   const OkdString&			strResourceLocName,
//												   const ResourceLocation	eResourceLoc)
//: _strResourceName		( strResourceName )
//, _strResourceLocName	( strResourceLocName )
//, _eResourceLoc			( eResourceLoc )
//, _uiLoadRefCount		( 0 )
//{
//
//}
//
////-----------------------------------------------------------------------------
//// Name:		OkdSharedResource destructor
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T, void (*TLoadFunc)( T* pResource )>
//OkdSharedResource<T, TLoadFunc>::~OkdSharedResource()
//{
//
//}
//
////-----------------------------------------------------------------------------
//// Name:		load
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T, void (*TLoadFunc)( T* pResource )>
//void	OkdSharedResource<T, TLoadFunc>::load()
//{
//	if	( _uiLoadRefCount == 0 )
//	{
//		TLoadFunc( _resourcePtr.pointer() );
//	}
//
//	_uiLoadRefCount++;
//}
//
////-----------------------------------------------------------------------------
//// Name:		unload
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T, void (*TLoadFunc)( T* pResource )>
//void	OkdSharedResource<T, TLoadFunc>::unload()
//{
//	ORKID_ASSERT( _uiLoadRefCount > 0 );
//
//	if	( _uiLoadRefCount > 0 )
//	{
//		_uiLoadRefCount--;
//	}
//}

#endif