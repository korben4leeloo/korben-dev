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
#include	ORKID_ENGINE_H(Resources/OkdResourceDatabase)
#include	ORKID_CORE_H(Containers/OkdMap)
#include	ORKID_CORE_H(String/OkdCrc32)
#include	ORKID_CORE_H(String/OkdString)

template<class T>
class OkdResourceHandler: public OkdAbstractResourceHandler
{
	//template<class T> friend class OkdResourcePtr;

public:
									OkdResourceHandler();
	virtual 						~OkdResourceHandler();

protected:
	//virtual T*					allocateResource() = 0;

private:
	typedef OkdMap<OkdResourceKey, T*> OkdResourceMap;

	/*T*							addResource( const OkdString& strResourceName );
	bool						removeResource( const T* pResource );*/
	virtual OkdAbstractResource*	addResource( const OkdString& strResourceName );
	virtual bool					removeResource( const OkdAbstractResource* pResource );

	OkdMap<OkdResourceKey, T*>		_resourceRefMap;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		OkdResourceHandler constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
OkdResourceHandler<T>::OkdResourceHandler()
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdResourceHandler destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
OkdResourceHandler<T>::~OkdResourceHandler()
{
	
}

//-----------------------------------------------------------------------------
// Name:		addResource
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
OkdAbstractResource*	OkdResourceHandler<T>::addResource(const OkdString&	strResourceName)
{
	OkdResourceKey				resourceKey	= OkdCrc32::getCrc32( strResourceName );
	OkdResourceMap::iterator	itResource	= _resourceRefMap.add( resourceKey, 0 );

	if	( itResource->second == 0 )
	{
		//T* pResource = allocateResource();
		T* pResource = new T();

		pResource->_resourceKey		= resourceKey;
		pResource->_strResourceName	= strResourceName;

		itResource->second = pResource;
	}

	return	( itResource->second );
}

//-----------------------------------------------------------------------------
// Name:		removeResource
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
bool	OkdResourceHandler<T>::removeResource(const OkdAbstractResource*	pResource)
{
	uint32 uiCount = _resourceRefMap.remove( pResource->getResourceKey() );
	ORKID_ASSERT( uiCount == 1 );

	delete pResource;
	return	( uiCount > 0 );
}

////-----------------------------------------------------------------------------
//// Name:		addResource
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T>
//T*	OkdResourceHandler<T>::addResource(const OkdString&	strResourceName)
//{
//	OkdResourceKey				resourceKey	= OkdCrc32::getCrc32( strResourceName );
//	OkdResourceMap::iterator	itResource	= _resourceRefMap.add( resourceKey, 0 );
//
//	if	( itResource->second == 0 )
//	{
//		T* pResource = allocateResource();
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
//bool	OkdResourceHandler<T>::removeResource(const T*	pResource)
//{
//	uint32 uiCount = _resourceRefMap.remove( pResource->getResourceKey() );
//	ORKID_ASSERT( uiCount == 1 );
//
//	delete pResource;
//
//	return	( uiCount > 0 );
//}

#endif