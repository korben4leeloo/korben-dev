//*****************************************************************************
//
//	Class:		OkdResourceHandler
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdResourceHandler_h__
#define __OrkidEngine_OkdResourceHandler_h__

#include	"Root.h"

#include	ORKID_ENGINE_H(Resources/Handlers/OkdAbstractResourceHandler)
//#include	ORKID_ENGINE_H(Resources/OkdResourcePtr)
//#include	ORKID_ENGINE_H(Resources/OkdResourceRef)
#include	ORKID_CORE_H(Containers/OkdMap)
//#include	ORKID_CORE_H(String/OkdCrc32)

template<class T> class OkdResourceRef;

template<class T, OrkidResourceType resourceType>
class OkdResourceHandler: public OkdAbstractResourceHandler
{
	template<class T, OrkidResourceType resourceType> friend class OkdResourcePtr;

public:
												OkdResourceHandler();
	virtual 									~OkdResourceHandler();

	virtual OrkidResourceType					getResourceType() const;

private:
	typedef OkdResourceRef<T> OkdResourceRefImpl;

	/*OkdResourceRefImpl*							createResource( const OkdString& strResourceName );
	OkdResourceRefImpl*							bindResource( const OkdString& strResourceName );
	OkdResourceRefImpl*							bindResource( OkdResourceRefImpl* pResourceRef );
	OkdResourceRefImpl*							unbindResource( OkdResourceRefImpl* pResourceRef );*/

	//bool										addResource( const OkdResourceKey& resourceKey, OkdResourceRefImpl* pResourceRef );
	bool										addResource( const OkdResourceKey& resourceKey, const OkdString& strResourceName );
	bool										removeResource( const OkdResourceKey& resourceKey );
	//OkdResourceRefImpl*							getResource( const OkdResourceKey& resourceKey );

	OkdMap<OkdResourceKey, OkdResourceRefImpl*>	_resourceRefMap;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		OkdResourceHandler constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OrkidResourceType resourceType>
OkdResourceHandler<T, resourceType>::OkdResourceHandler()
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdResourceHandler destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OrkidResourceType resourceType>
OkdResourceHandler<T, resourceType>::~OkdResourceHandler()
{
	
}

//-----------------------------------------------------------------------------
// Name:		getResourceType
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OrkidResourceType resourceType>
OrkidResourceType	OkdResourceHandler<T, resourceType>::getResourceType() const
{
	return	( resourceType );
}

////-----------------------------------------------------------------------------
//// Name:		addResource
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T, OrkidResourceType resourceType>
//bool	OkdResourceHandler<T, resourceType>::addResource(const OkdResourceKey&	resourceKey, 
//														 OkdResourceRefImpl*	pResourceRef)
//{
//	return	( _resourceRefMap.add( resourceKey, pResourceRef ) );
//}

//-----------------------------------------------------------------------------
// Name:		addResource
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OrkidResourceType resourceType>
bool	OkdResourceHandler<T, resourceType>::addResource(const OkdResourceKey&	resourceKey, 
														 const OkdString&		strResourceName)
{
	return	( _resourceRefMap.add( resourceKey, pResourceRef ) );
}

//-----------------------------------------------------------------------------
// Name:		removeResource
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OrkidResourceType resourceType>
bool	OkdResourceHandler<T, resourceType>::removeResource(const OkdResourceKey&	resourceKey)
{
	uint32 uiCount = _resourceRefMap.remove( resourceKey );
	ORKID_ASSERT( uiCount == 1 );

	return	( uiCount > 0 );
}

////-----------------------------------------------------------------------------
//// Name:		getResource
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T, OrkidResourceType resourceType>
//OkdResourceRef<T>*	OkdResourceHandler<T, resourceType>::getResource(const OkdResourceKey&	resourceKey)
//{
//	OkdResourceRefImpl* pResourceRef = 0;
//
//	_resourceRefMap.find( resourceKey, &pResourceRef );
//	return	( pResourceRef );
//}

////-----------------------------------------------------------------------------
//// Name:		createResource
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T, OrkidResourceType resourceType>
//OkdResourceRef<T>*	OkdResourceHandler<T, resourceType>::createResource(const OkdString&	strResourceName)
//{
//	OkdResourceKey		resourceKey		= OkdCrc32::getCrc32( strResourceName );
//	OkdResourceRefImpl*	pResourceRef	= 0;
//
//	if	( _resourceRefMap.find( resourceKey, &pResourceRef ) )
//	{
//		return	( 0 );
//	}
//
//	pResourceRef = new OkdResourceRefImpl( resourceKey, strResourceName );
//	pResourceRef->addRef();
//
//	_resourceRefMap.add( resourceKey, pResourceRef );
//
//	return	( pResourceRef );
//}
//
////-----------------------------------------------------------------------------
//// Name:		bindResource
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T, OrkidResourceType resourceType>
//OkdResourceRef<T>*	OkdResourceHandler<T, resourceType>::bindResource(const OkdString&	strResourceName)
//{
//	OkdResourceKey		resourceKey		= OkdCrc32::getCrc32( strResourceName );
//	OkdResourceRefImpl*	pResourceRef	= 0;
//
//	if	( _resourceRefMap.find( resourceKey, &pResourceRef ) )
//	{
//		pResourceRef->addRef();
//	}
//	
//	return	( pResourceRef );
//}
//
////-----------------------------------------------------------------------------
//// Name:		bindResource
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T, OrkidResourceType resourceType>
//OkdResourceRef<T>*	OkdResourceHandler<T, resourceType>::bindResource(OkdResourceRef<T>*	pResourceRef)
//{
//	pResourceRef->addRef();
//	return	( pResourceRef );
//}
//
////-----------------------------------------------------------------------------
//// Name:		unbindResource
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T, OrkidResourceType resourceType>
//OkdResourceRef<T>*	OkdResourceHandler<T, resourceType>::unbindResource(OkdResourceRef<T>*	pResourceRef)
//{
//	if	( pResourceRef->removeRef() == 0 )
//	{
//		_resourceRefMap.remove( pResourceRef->getResourceKey() );
//		delete pResourceRef;
//		return	( 0 );
//	}
//	
//	return	( pResourceRef );
//}

#endif