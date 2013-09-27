//*****************************************************************************
//
//	Class:		OkdResourceManager
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdResourceManager_h__
#define __OrkidEngine_OkdResourceManager_h__

#include	"Root.h"

#include	ORKID_CORE_H(Containers/OkdList)
#include	ORKID_CORE_H(Containers/OkdMap)
#include	ORKID_ENGINE_H(ResourceManager/OkdSharedResource)
#include	ORKID_ENGINE_H(ResourceManager/ResourceHandler/OkdAbstractResourceHandler)

class OkdResourceManager
{
public:
	friend class OrkidEngine;

	void												registerResourceType( const OkdAbstractResourceHandler* pResourceHandler );
	void												unregisterResourceType( const OkdAbstractResourceHandler* pResourceHandler );
	uint32												getResourceTypeId( const OkdString& strResourceTypeName );

	OkdSharedResourcePtr								addResource( const OkdResourceIdentifier& resourceIdentifier );

private:
														OkdResourceManager();
														~OkdResourceManager();

	//void												clearResources();

	OkdMap<uint32, const OkdAbstractResourceHandler*>	_resourceHandlerMap;
	const OkdAbstractResourceHandler*					_resourceHandlerArray[OrkidResourceTypeLast];
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif