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

	inline OkdAbstractResourceHandler*	getResourceHandler( const OkdResourceType eResourceType );

private:
										OkdResourceManager();
										~OkdResourceManager();

	void								initialize();

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
OkdAbstractResourceHandler*	OkdResourceManager::getResourceHandler(const OkdResourceType	eResourceType)
{
	return	( _resourceHandlers[eResourceType] );
}

#endif