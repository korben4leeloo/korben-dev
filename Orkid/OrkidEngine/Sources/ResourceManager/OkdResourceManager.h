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

	OkdResourcePtr										createResource( const OkdResourceId& resourceId );
	//OkdResourcePtr										createResource( const OrkidResourceType eResourceType, const OkdString& strResourceName );
	//OkdResourcePtr										createResource( const OrkidResourceType& eResourceType, const OkdString& strResourceName );

private:
	struct OkdResourceMap
	{
												OkdResourceMap(): _pResourceHandler( 0 ) {}

		OkdAbstractResourceHandler*				_pResourceHandler;
		OkdMap<OkdString, OkdResourceHandle*>	_resourceHandleMap;
	};

														OkdResourceManager();
														~OkdResourceManager();

	void												initialize();
	inline OkdResourceMap*								getResourceMap( const OrkidResourceType eResourceType );

	void												deleteResource( const OkdResourceId& resourceId );


														/*void												registerResourceType( const OrkidResourceType eResourceType, const OkdAbstractResourceHandler* pResourceHandler );
														void												unregisterResourceType( const OrkidResourceType eResourceType, const OkdAbstractResourceHandler* pResourceHandler );*/

	//void												clearResources();

	//OkdMap<uint32, const OkdAbstractResourceHandler*>	_resourceHandlerMap;
	//const OkdAbstractResourceHandler*					_resourceHandlerArray[OrkidResourceTypeCount];
	OkdResourceMap					_resourceMapArray[OrkidResourceTypeCount];
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		getResourceMap
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourceManager::OkdResourceMap*	OkdResourceManager::getResourceMap(const OrkidResourceType	eResourceType)
{
	ORKID_ASSERT( eResourceType < OrkidResourceTypeCount );
	return	( &_resourceMapArray[eResourceType] );
}

#endif