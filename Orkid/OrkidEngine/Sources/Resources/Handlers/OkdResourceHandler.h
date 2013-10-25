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
#include	ORKID_CORE_H(String/OkdCrc32)

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

	OkdResourceRefImpl*							createResourceRef( const OkdString& strResourceName );
	bool										deleteResourceRef( OkdResourceRefImpl* pResourceRef );

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

//-----------------------------------------------------------------------------
// Name:		createResourceRef
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OrkidResourceType resourceType>
OkdResourceRef<T>*	OkdResourceHandler<T, resourceType>::createResourceRef(const OkdString&	strResourceName)
{
	OkdResourceKey		resourceKey		= OkdCrc32::getCrc32( strResourceName );
	OkdResourceRefImpl*	pResourceRef	= 0;

	if	( _resourceRefMap.find( resourceKey, &pResourceRef ) )
	{
		return	( 0 );
	}

	pResourceRef = new OkdResourceRefImpl( resourceKey, strResourceName );
	_resourceRefMap.add( resourceKey, pResourceRef );

	return	( pResourceRef );
}

//-----------------------------------------------------------------------------
// Name:		deleteResourceRef
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OrkidResourceType resourceType>
bool	OkdResourceHandler<T, resourceType>::deleteResourceRef(OkdResourceRefImpl*	pResourceRef)
{
	const OkdResourceKey&	resourceKey	= pResourceRef->getResourceKey();
	uint32					uiCount		= _resourceRefMap.remove( resourceKey );

	ORKID_ASSERT( uiCount == 1 );
	delete pResourceRef;

	return	( uiCount > 0 );
}

#endif