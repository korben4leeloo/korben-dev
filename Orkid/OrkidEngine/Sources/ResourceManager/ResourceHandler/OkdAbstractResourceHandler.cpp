//*****************************************************************************
//
//	File:		OkdAbstractResourceHandler.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdAbstractResourceHandler.h"

#include	ORKID_ENGINE_H(OrkidEngine)
#include	ORKID_ENGINE_H(ResourceManager/OkdResourceManager)

//-----------------------------------------------------------------------------
// Name:		OkdAbstractResourceHandler constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdAbstractResourceHandler::OkdAbstractResourceHandler(const OrkidResourceType	eResourceType)
: _strResourceTypeName	( OrkidEngine::_resourceTypeName[eResourceType] )
, _eResourceType		( eResourceType )
{
	OrkidEngine* pOrkidEngineInstance = OrkidEngine::instance();
	ORKID_ASSERT( pOrkidEngineInstance );
	
	if	( pOrkidEngineInstance )
	{
		OkdResourceManager* pResourceManager = pOrkidEngineInstance->getResourceManager();

		ORKID_ASSERT( pResourceManager );

		if	( pResourceManager )
		{
			pResourceManager->registerResourceType( this );
		}
	}
}

//-----------------------------------------------------------------------------
// Name:		OkdAbstractResourceHandler destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdAbstractResourceHandler::~OkdAbstractResourceHandler()
{
	OrkidEngine* pOrkidEngineInstance = OrkidEngine::instance();
	ORKID_ASSERT( pOrkidEngineInstance );

	if	( pOrkidEngineInstance )
	{
		OkdResourceManager* pResourceManager = pOrkidEngineInstance->getResourceManager();

		ORKID_ASSERT( pResourceManager );

		if	( pResourceManager )
		{
			pResourceManager->unregisterResourceType( this );
		}
	}
}
