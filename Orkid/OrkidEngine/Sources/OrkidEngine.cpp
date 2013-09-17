//*****************************************************************************
//
//	File:		OrkidEngine.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OrkidEngine.h"

#include	ORKID_CORE_H(OrkidCore)
#include	ORKID_ENGINE_H(ResourceManager/OkdResourceManager)

OrkidEngine*	OrkidEngine::_pInstance					= 0;
const char*		OrkidEngine::_strDefaultResourceManager	= "Default";
const char*		OrkidEngine::_strDefaultScene			= "Default";

//-----------------------------------------------------------------------------
// Name:		OrkidEngine constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OrkidEngine::OrkidEngine()
{
	OrkidCore::initialize();

	addResourceManager( OrkidEngine::_strDefaultResourceManager );
	addScene( OrkidEngine::_strDefaultScene );
}

//-----------------------------------------------------------------------------
// Name:		OrkidEngine destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OrkidEngine::~OrkidEngine()
{
	OrkidCore::clean();
}

//-----------------------------------------------------------------------------
// Name:		addResourceManager
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourceManager*	OrkidEngine::addResourceManager( const OkdString& strResourceManagerName )
{
	OkdResourceManagerMap::iterator itResourceManager = _resourceManagerList.find( strResourceManagerName );
	OkdResourceManager*				pResourceManager;

	if	( itResourceManager == _resourceManagerList.end() )
	{
		pResourceManager = _resourceManagerList[strResourceManagerName];
	}
	else
	{
		pResourceManager = itResourceManager->second;
	}

	return	( pResourceManager );
}

//-----------------------------------------------------------------------------
// Name:		getResourceManager
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourceManager*	OrkidEngine::getResourceManager( const OkdString& strResourceManagerName )
{
	OkdResourceManagerMap::iterator itResourceManager	= _resourceManagerList.find( strResourceManagerName );
	OkdResourceManager*				pResourceManager	= ( itResourceManager == _resourceManagerList.end() ) ? 0 : itResourceManager->second;

	return	( pResourceManager );
}

//-----------------------------------------------------------------------------
// Name:		addScene
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdScene*	OrkidEngine::addScene( const OkdString& strSceneName )
{
	OkdSceneMap::iterator	itScene = _sceneList.find( strSceneName );
	OkdScene*				pScene;

	if	( itScene == _sceneList.end() )
	{
		pScene = _sceneList[strSceneName];
	}
	else
	{
		pScene = itScene->second;
	}

	return	( pScene );
}

//-----------------------------------------------------------------------------
// Name:		getScene
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdScene*	OrkidEngine::getScene( const OkdString& strSceneName )
{
	OkdSceneMap::iterator	itScene = _sceneList.find( strSceneName );
	OkdScene*				pScene	= ( itScene == _sceneList.end() ) ? 0 : itScene->second;

	return	( pScene );
}
