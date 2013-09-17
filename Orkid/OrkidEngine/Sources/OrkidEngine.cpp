//*****************************************************************************
//
//	File:		OrkidEngine.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OrkidEngine.h"

#include	ORKID_CORE_H(OrkidCore)
#include	ORKID_ENGINE_H(ResourceManager/OkdResourceManager)
#include	ORKID_ENGINE_H(SceneGraph/OkdScene)

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
	addScene( OrkidEngine::_strDefaultScene, OrkidEngine::_strDefaultResourceManager );
}

//-----------------------------------------------------------------------------
// Name:		OrkidEngine destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OrkidEngine::~OrkidEngine()
{
	clear();
	OrkidCore::clean();
}

//-----------------------------------------------------------------------------
// Name:		clear
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OrkidEngine::clear()
{
	clearMap<OkdResourceManagerMap>( &_resourceManagerList );
	clearMap<OkdSceneMap>( &_sceneList );
}

//-----------------------------------------------------------------------------
// Name:		clearMap
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void	OrkidEngine::clearMap( T* pMap )
{
	T::iterator it = pMap->begin();

	while	( it != pMap->end() )
	{
		delete it->second;
		it++;
	}

	pMap->clear();
}

//-----------------------------------------------------------------------------
// Name:		addResourceManager
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourceManager*	OrkidEngine::addResourceManager( const OkdString& strResourceManagerName )
{
	OkdResourceManager* pResourceManager = getResourceManager( strResourceManagerName );

	if	( !pResourceManager )
	{
		pResourceManager = new OkdResourceManager();
		_resourceManagerList[strResourceManagerName] = pResourceManager;
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
OkdScene*	OrkidEngine::addScene(const OkdString& strSceneName, 
								  const OkdString& strResourceManagerName)
{
	OkdScene* pScene = getScene( strSceneName );

	if	( pScene == 0 )
	{
		OkdResourceManager* pResourceManager = getResourceManager( strResourceManagerName );

		if	( !pResourceManager )
		{
			return	( 0 );
		}

		pScene = new OkdScene( pResourceManager );
		_sceneList[strSceneName] = pScene;
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
