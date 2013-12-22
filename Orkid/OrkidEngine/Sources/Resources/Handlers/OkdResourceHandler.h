////*****************************************************************************
////
////	Class:		OkdResourceHandler
////
////	Created:	2013-08-26
////
////*****************************************************************************
//
//#ifndef __OrkidEngine_OkdResourceHandler_h__
//#define __OrkidEngine_OkdResourceHandler_h__
//
//#include	"Root.h"
//
//#include	ORKID_ENGINE_H(Resources/Handlers/OkdAbstractResourceHandler)
//#include	ORKID_ENGINE_H(Resources/OkdResourceDatabase)
//#include	ORKID_CORE_H(Containers/OkdMap)
//#include	ORKID_CORE_H(String/OkdCrc32)
//#include	ORKID_CORE_H(String/OkdString)
//
//template<class T>
//class OkdResourceHandler: public OkdAbstractResourceHandler
//{
//public:
//									OkdResourceHandler();
//	virtual 						~OkdResourceHandler();
//
//private:
//	typedef OkdMap<OkdResourceKey, T*> OkdResourceMap;
//
//	virtual OkdAbstractResource*	addResource( const OkdString& strResourceName );
//	virtual bool					removeResource( const OkdAbstractResource* pResource );
//
//	OkdResourceMap					_resourceRefMap;
//};
//
////*****************************************************************************
////	Inline functions declarations
////*****************************************************************************
//
////-----------------------------------------------------------------------------
//// Name:		OkdResourceHandler constructor
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T>
//OkdResourceHandler<T>::OkdResourceHandler()
//{
//	
//}
//
////-----------------------------------------------------------------------------
//// Name:		OkdResourceHandler destructor
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T>
//OkdResourceHandler<T>::~OkdResourceHandler()
//{
//	
//}
//
////-----------------------------------------------------------------------------
//// Name:		addResource
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T>
//OkdAbstractResource*	OkdResourceHandler<T>::addResource(const OkdString&	strResourceName)
//{
//	OkdResourceKey				resourceKey	= OkdCrc32::getCrc32( strResourceName );
//	OkdResourceMap::iterator	itResource	= _resourceRefMap.add( resourceKey, 0 );
//
//	if	( itResource->second == 0 )
//	{
//		T* pResource = new T();
//
//		pResource->_resourceKey		= resourceKey;
//		pResource->_strResourceName	= strResourceName;
//
//		itResource->second = pResource;
//	}
//
//	return	( itResource->second );
//}
//
////-----------------------------------------------------------------------------
//// Name:		removeResource
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T>
//bool	OkdResourceHandler<T>::removeResource(const OkdAbstractResource*	pResource)
//{
//	uint32 uiCount = _resourceRefMap.remove( pResource->getResourceKey() );
//	ORKID_ASSERT( uiCount == 1 );
//
//	delete pResource;
//	return	( uiCount > 0 );
//}
//
//#endif