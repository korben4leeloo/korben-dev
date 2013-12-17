////*****************************************************************************
////
////	Class:		OkdResourceRef
////
////	Created:	2013-08-26
////
////*****************************************************************************
//
//#ifndef __OrkidEngine_OkdResourceRef_h__
//#define __OrkidEngine_OkdResourceRef_h__
//
//#include	"Root.h"
//
//#include	ORKID_CORE_H(String/OkdString)
//
//template<class T>
//class OkdResourceRef
//{
//	template<class T, OkdResourceType resourceType> friend class OkdResourcePtr;
//	template<class T, OkdResourceType resourceType> friend class OkdResourceHandler;
//
//public:
//	inline const OkdResourceKey&	getResourceKey() const;
//	inline T*						getResource();
//	inline const OkdString&			getResourceName() const;
//
//private:
//									OkdResourceRef( const OkdResourceKey& resourceKey, T* pResource, const OkdString& strResourceName );
//									~OkdResourceRef();
//
//	inline void						addRef();
//	inline uint32					removeRef();
//
//	OkdResourceKey					_resourceKey;
//	uint32							_uiRefCount;
//	uint32							_uiLoadRefCount;
//	T*								_pResource;
//	OkdString						_strResourceName;
//};
//
////*****************************************************************************
////	Inline functions declarations
////*****************************************************************************
//
////-----------------------------------------------------------------------------
//// Name:		OkdResourceRef constructor
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T>
//OkdResourceRef<T>::OkdResourceRef(const OkdResourceKey&	resourceKey,
//								  T*					pResource,
//								  const OkdString&		strResourceName)
//: _resourceKey		( resourceKey )
//, _pResource		( pResource )
//, _uiRefCount		( 0 )
//, _uiLoadRefCount	( 0 )
//, _strResourceName	( strResourceName )
//{
//	//_pResource = new T();
//}
//
////-----------------------------------------------------------------------------
//// Name:		OkdResourceRef destructor
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T>
//OkdResourceRef<T>::~OkdResourceRef()
//{
//	if	( _pResource )
//	{
//		delete _pResource;
//	}
//}
//
////-----------------------------------------------------------------------------
//// Name:		getResourceKey
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T>
//const OkdResourceKey&	OkdResourceRef<T>::getResourceKey() const
//{
//	return( _resourceKey );
//}
//
////-----------------------------------------------------------------------------
//// Name:		getResourceKey
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T>
//T*	OkdResourceRef<T>::getResource()
//{
//	return( _pResource );
//}
//
////-----------------------------------------------------------------------------
//// Name:		getResourceName
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T>
//const OkdString&	OkdResourceRef<T>::getResourceName() const
//{
//	return( _strResourceName );
//}
//
////-----------------------------------------------------------------------------
//// Name:		addRef
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T>
//void	OkdResourceRef<T>::addRef()
//{
//	_uiRefCount++;
//}
//
////-----------------------------------------------------------------------------
//// Name:		removeRef
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T>
//uint32	OkdResourceRef<T>::removeRef()
//{
//	ORKID_ASSERT( _uiRefCount > 0 );
//	_uiRefCount--;
//
//	return( _uiRefCount );
//}
//
//#endif