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
	friend class OkdOpenGL_API;

	inline OkdAbstractResourceHandler*	getResourceHandler( const OkdResourceType eResourceType );

private:
										OkdResourceManager();
										~OkdResourceManager();

	inline void							setResourceHandler( const OkdResourceType eResourceType, OkdAbstractResourceHandler* pResourceHandler );

	void								initialize();

	OkdAbstractResourceHandler*			_resourceHandlers[OrkidResourceTypeCount];
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		setResourceHandler
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdResourceManager::setResourceHandler(const OkdResourceType		eResourceType, 
											   OkdAbstractResourceHandler*	pResourceHandler)
{
	_resourceHandlers[eResourceType] = pResourceHandler;
}

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