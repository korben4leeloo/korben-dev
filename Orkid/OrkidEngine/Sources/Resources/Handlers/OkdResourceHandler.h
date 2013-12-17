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

template<class T, OkdResourceType resourceType>
class OkdResourceHandler: public OkdAbstractResourceHandler
{
	template<class T, OkdResourceType resourceType> friend class OkdResourcePtr;

public:
								OkdResourceHandler();
	virtual 					~OkdResourceHandler();

	virtual OkdResourceType		getResourceType() const;

protected:
	virtual T*					allocateResource() = 0;

private:
	typedef OkdMap<OkdResourceKey, T*> OkdResourceMap;

	T*							addResource( const OkdString& strResourceName );
	bool						removeResource( const OkdResourceKey& resourceKey );

	OkdMap<OkdResourceKey, T*>	_resourceRefMap;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		OkdResourceHandler constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OkdResourceType resourceType>
OkdResourceHandler<T, resourceType>::OkdResourceHandler()
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdResourceHandler destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OkdResourceType resourceType>
OkdResourceHandler<T, resourceType>::~OkdResourceHandler()
{
	
}

//-----------------------------------------------------------------------------
// Name:		getResourceType
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OkdResourceType resourceType>
OkdResourceType	OkdResourceHandler<T, resourceType>::getResourceType() const
{
	return	( resourceType );
}

//-----------------------------------------------------------------------------
// Name:		addResource
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OkdResourceType resourceType>
T*	OkdResourceHandler<T, resourceType>::addResource(const OkdString&	strResourceName)
{
	OkdResourceKey				resourceKey	= OkdCrc32::getCrc32( strResourceName );
	OkdResourceMap::iterator	itResource	= _resourceRefMap.add( resourceKey, 0 );

	if	( itResource->second == 0 )
	{
		T* pResource = allocateResource();
		itResource->second = pResource;
	}

	return	( itResource->second );
}

//-----------------------------------------------------------------------------
// Name:		removeResource
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OkdResourceType resourceType>
bool	OkdResourceHandler<T, resourceType>::removeResource(const OkdResourceKey&	resourceKey)
{
	uint32 uiCount = _resourceRefMap.remove( resourceKey );
	ORKID_ASSERT( uiCount == 1 );

	return	( uiCount > 0 );
}

#endif