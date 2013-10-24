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

#include	ORKID_ENGINE_H(ResourceManager/OkdResourceHandle)
#include	ORKID_ENGINE_H(ResourceManager/ResourceHandler/OkdAbstractResourceHandler)

#include	ORKID_ENGINE_H(ResourceManager/OkdResourcePtr)
#include	ORKID_CORE_H(Containers/OkdVector)

class OkdResourceMap;

class OkdAbstractResourceTypeManager
{
public:
	OkdAbstractResourceTypeManager( const OrkidResourceType eResType ): _resType( eResType ) {}
	virtual ~OkdAbstractResourceTypeManager() {}

	OrkidResourceType _resType;
};

template<class T, OrkidResourceType resourceType>
class OkdResourceTypeManager: public OkdAbstractResourceManager
{
public:
	OkdResourceTypeManager(): OkdAbstractResourceManager( resourceType ) {}

	virtual OkdResourcePtr<T>	createResource( const OkdString& strResourceName )
	{
		OkdResourceRef<T>* pRef = new OkdResourceRef<T>();

		_resources.add( pRef );

		OkdResourcePtr<T> resPtr( pRef );
		return	( resPtr );
	}

	OkdVector<OkdResourceRef<T>*>	_resources;
};

class OkdEngineResourceManager
{
public:
								/*OkdEngineResourceManager() {}
								~OkdEngineResourceManager() {}*/

//private:
	OkdAbstractResourceTypeManager*	_resourceManagers[OrkidResourceTypeCount];
};

class OkdResourceManager
{
public:
	friend class OrkidEngine;

	//uint32					getResourceTypeId( const OkdString& strResourceTypeName );

	//OkdResourcePtr			createResource( const OkdResourceId& resourceId );
	//OkdResourcePtr			createResource( const OrkidResourceType eResourceType, const OkdString& strResourceName );
	//OkdResourcePtr			createResource( const OrkidResourceType& eResourceType, const OkdString& strResourceName );

private:
							OkdResourceManager();
							~OkdResourceManager();

	void					initialize();
	inline OkdResourceMap*	getResourceMap( const OrkidResourceType eResourceType );

	void					deleteResource( const OkdResourceId& resourceId );
							
	//void					clearResources();

	OkdResourceMap*			_resourceMapArray[OrkidResourceTypeCount];
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		getResourceMap
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourceMap*	OkdResourceManager::getResourceMap(const OrkidResourceType	eResourceType)
{
	ORKID_ASSERT( eResourceType < OrkidResourceTypeCount );
	return	( _resourceMapArray[eResourceType] );
}

#endif