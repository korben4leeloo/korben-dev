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

enum ResourceLocation
{
	RES_LOC_MEMORY,
	RES_LOC_FILE
};

template<class T>
class OkdSharedResource
{
protected:
	class OkdSharedResourceRef
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

public:
	inline						OkdSharedResource();
	inline						OkdSharedResource( T* pObject );
	inline						OkdSharedResource( const OkdSharedResource& sharedResource );
	inline						~OkdSharedResource();

	inline T*					ptr();
	inline const T*				ptr() const;
	inline uint					getRefCount() const;

	inline void					load();
	inline void					unload();

	inline OkdSharedResource&	operator=( const OkdSharedResource& sharedPtr );

protected:
	inline void					destroy();

	T*							_pObject;
	OkdSharedResourceRef*		_pRefCount;
	OkdSharedResourceRef*		_pLoadRefCount;
};

//template<class T, void (*TLoadFunc)( T* pResource )>
//class OkdSharedResource
//{
//public:
//	friend class OkdResourceManager;
//	friend class OkdSharedPtr<OkdSharedResource>;
//
//	void				load();
//	void				unload();
//	uint				getLoadRefCount() const;
//
//private:
//						OkdSharedResource( const OkdString& strResourceName, const OkdString& strResourceLocName, const ResourceLocation eResourceLoc, T* pResource );
//						~OkdSharedResource();
//
//	OkdString			_strResourceName;
//	OkdString			_strResourceLocName;
//	ResourceLocation	_eResourceLoc;
//	T*					_pResource;
//	uint				_uiLoadRefCount;
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
//												   const ResourceLocation	eResourceLoc, 
//												   T*						pResource)
//: _strResourceName		( strResourceName )
//, _strResourceLocName	( strResourceLocName )
//, _eResourceLoc			( eResourceLoc )
//, _pResource			( pResource )
//, _uiLoadRefCount		( 0 )
//{
//	ORKID_ASSERT( pResource );
//}
//
//////-----------------------------------------------------------------------------
////// Name:		OkdSharedResource constructor
//////
////// Created:		2013-08-26
//////-----------------------------------------------------------------------------
////template<class T, void (*TLoadFunc)( T* pResource )>
////OkdSharedResource<T, TLoadFunc>::OkdSharedResource(const OkdSharedResource& other)
////: OkdSharedPtr		( other )
////, _pResourceInfo	( other._pResourceInfo )
////, _bHasLoadRef		( false )
////{
////	
////}
//
////-----------------------------------------------------------------------------
//// Name:		OkdSharedResource destructor
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T, void (*TLoadFunc)( T* pResource )>
//OkdSharedResource<T, TLoadFunc>::~OkdSharedResource()
//{
//	if	( _pResource )
//	{
//		delete _pResource;
//	}
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
//		TLoadFunc( _pResource );
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
//
//		if	( _uiLoadRefCount == 0 )
//		{
//			// unload resource
//		}
//	}
//}
//
////-----------------------------------------------------------------------------
//// Name:		getLoadRefCount
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T, void (*TLoadFunc)( T* pResource )>
//uint	OkdSharedResource<T, TLoadFunc>::getLoadRefCount() const
//{
//	return	( _uiLoadRefCount );
//}

//template<class T, void (*TLoadFunc)( T* pResource )>
//class OkdSharedResource: public OkdSharedPtr<T>
//{
//private:
//	struct OkdSharedResourceInfo
//	{
//		OkdString			_strResourceName;
//		OkdString			_strResourceLocName;
//		ResourceLocation	_eResourceLoc;
//		uint				_uiLoadRefCount;
//	};
//
//public:
//	friend class OkdResourceManager;
//
//								OkdSharedResource( const OkdSharedResource& other );
//	virtual						~OkdSharedResource();
//
//	void						load();
//	void						unload();
//
//private:
//								OkdSharedResource( const OkdString& strResourceName, const OkdString& strResourceLocName, const ResourceLocation eResourceLoc );
//
//	OkdSharedResourceInfo*		_pResourceInfo;
//	bool						_bHasLoadRef;
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
//: OkdSharedPtr		( new T() )
//, _bHasLoadRef		( false )
//{
//	_pResourceInfo = new OkdSharedResourceInfo();
//
//	_pResourceInfo->_strResourceName	= strResourceName;
//	_pResourceInfo->_strResourceLocName	= strResourceLocName;
//	_pResourceInfo->_eResourceLoc		= eResourceLoc;
//	_pResourceInfo->_uiLoadRefCount		= 0;
//}
//
////-----------------------------------------------------------------------------
//// Name:		OkdSharedResource constructor
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T, void (*TLoadFunc)( T* pResource )>
//OkdSharedResource<T, TLoadFunc>::OkdSharedResource(const OkdSharedResource& other)
//: OkdSharedPtr		( other )
//, _pResourceInfo	( other._pResourceInfo )
//, _bHasLoadRef		( false )
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
//	if	( _bHasLoadRef )
//	{
//		unload();
//	}
//
//	if	( getRefCount() == 1 )
//	{
//		ORKID_ASSERT( _pResourceInfo->_uiLoadRefCount == 0 );
//		delete _pResourceInfo;
//	}
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
//	ORKID_ASSERT( _bHasLoadRef == false );
//
//	if	( _bHasLoadRef == false )
//	{
//		if	( _pResourceInfo->_uiLoadRefCount == 0 )
//		{
//			TLoadFunc( ptr() );
//		}
//
//		_pResourceInfo->_uiLoadRefCount++;
//		_bHasLoadRef = true;
//	}
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
//	if	( _bHasLoadRef )
//	{
//		ORKID_ASSERT( _pResourceInfo->_uiLoadRefCount > 0 );
//
//		if	( _pResourceInfo->_uiLoadRefCount > 0 )
//		{
//			_pResourceInfo->_uiLoadRefCount--;
//
//			if	( _pResourceInfo->_uiLoadRefCount == 0 )
//			{
//				// unload resource
//			}
//		}
//
//		_bHasLoadRef = false;
//	}
//}

#endif