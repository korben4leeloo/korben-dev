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

class OkdAbstractResourceHandler;

class OkdResourceManager
{
public:
	friend class OrkidEngine;

	//OkdResourcePtr					createResource( const OkdResourceId& resourceId );
	//OkdResourcePtr					createResource( const OrkidResourceType eResourceType, const OkdString& strResourceName );
	//OkdResourcePtr					createResource( const OrkidResourceType& eResourceType, const OkdString& strResourceName );

	inline OkdAbstractResourceHandler*	getResourceHandler( const OrkidResourceType eResourceType );

private:
										OkdResourceManager();
										~OkdResourceManager();

	void								initialize();

	//void								deleteResource( const OkdResourceId& resourceId );
	//void								clearResources();

	OkdAbstractResourceHandler*			_resourceHandlers[OrkidResourceTypeCount];
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		getResourceHandler
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdAbstractResourceHandler*	OkdResourceManager::getResourceHandler(const OrkidResourceType	eResourceType)
{
	return	( _resourceHandlers[eResourceType] );
}

#endif