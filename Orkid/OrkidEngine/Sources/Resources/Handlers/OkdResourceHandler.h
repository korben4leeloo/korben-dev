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
#include	ORKID_ENGINE_H(Resources/OkdResourcePtr)
#include	ORKID_CORE_H(Containers/OkdVector)

template<class T, OrkidResourceType resourceType>
class OkdResourceHandler: public OkdAbstractResourceHandler
{
public:
									OkdResourceHandler();
	virtual 						~OkdResourceHandler();

	virtual OrkidResourceType		getResourceType() const;

	OkdResourcePtr<T>				createResource( const OkdString& strResourceName );

private:
	OkdVector<OkdResourceRef<T>*>	_resources;
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
// Name:		createResource
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OrkidResourceType resourceType>
OkdResourcePtr<T>	OkdResourceHandler<T, resourceType>::createResource(const OkdString&	strResourceName)
{
	OkdResourceRef<T>* pRef = new OkdResourceRef<T>();

	_resources.add( pRef );

	OkdResourcePtr<T> resPtr( pRef );
	return	( resPtr );
}

#endif