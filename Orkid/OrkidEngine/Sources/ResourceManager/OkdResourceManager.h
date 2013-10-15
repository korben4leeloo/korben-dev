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
#include	ORKID_ENGINE_H(ResourceManager/OkdResourceHandle)
#include	ORKID_ENGINE_H(ResourceManager/ResourceHandler/OkdAbstractResourceHandler)

class OkdResourceManager
{
public:
	friend class OrkidEngine;

	//uint32												getResourceTypeId( const OkdString& strResourceTypeName );

	//OkdResourcePtr										createResource( const OkdResourceId& resourceId );
	OkdResourcePtr										createResource( const OrkidResourceType eResourceType, const OkdString& strResourceName );
	//OkdResourcePtr										createResource( const OrkidResourceType& eResourceType, const OkdString& strResourceName );

private:
														OkdResourceManager();
														~OkdResourceManager();

	void												initialize();

														/*void												registerResourceType( const OrkidResourceType eResourceType, const OkdAbstractResourceHandler* pResourceHandler );
														void												unregisterResourceType( const OrkidResourceType eResourceType, const OkdAbstractResourceHandler* pResourceHandler );*/

	//void												clearResources();

	//OkdMap<uint32, const OkdAbstractResourceHandler*>	_resourceHandlerMap;
	const OkdAbstractResourceHandler*					_resourceHandlerArray[OrkidResourceTypeCount];
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif