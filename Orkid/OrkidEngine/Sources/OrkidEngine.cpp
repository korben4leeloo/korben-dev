//*****************************************************************************
//
//	File:		OrkidEngine.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OrkidEngine.h"

#include	ORKID_CORE_H(OrkidCore)
#include	ORKID_ENGINE_H(Resources/OkdResourceManager)
#include	ORKID_ENGINE_H(Resources/OkdResourceDatabase)
#include	ORKID_ENGINE_H(SceneGraph/OkdScene)

OrkidEngine*	OrkidEngine::_pInstance			= 0;
//const char*		OrkidEngine::_strDefaultScene	= "Default";

const char*		OrkidEngine::_resourceTypeName[OrkidResourceTypeCount] =
{
	"OrkidMesh", 
	"OrkidScene",
};

//-----------------------------------------------------------------------------
// Name:		OrkidEngine constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OrkidEngine::OrkidEngine()
: _pResourceManager		( 0 )
, _pResourceDatabase	( 0 )
{
	
}

//-----------------------------------------------------------------------------
// Name:		OrkidEngine destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OrkidEngine::~OrkidEngine()
{
	
}

//-----------------------------------------------------------------------------
// Name:		clear
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OrkidEngine::clear()
{
	//clearMap<OkdResourceManagerMap>( &_resourceManagerList );
	//clearMap<OkdSceneMap>( &_sceneList );
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
// Name:		initialize
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OrkidEngine::initialize()
{
	OrkidCore::initialize();

	// Resource database
	_pResourceDatabase = new OkdResourceDatabase();
	_pResourceDatabase->open();

	// Resource manager
	_pResourceManager = new OkdResourceManager();
	_pResourceManager->initialize();

	//registerResources();
	//addScene( OrkidEngine::_strDefaultScene );
}

//-----------------------------------------------------------------------------
// Name:		uninitialize
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OrkidEngine::uninitialize()
{
	clear();
	//unregisterResources();

	_pResourceDatabase->close();

	delete _pResourceManager;
	delete _pResourceDatabase;

	OrkidCore::uninitialize();
}

////-----------------------------------------------------------------------------
//// Name:		registerResources
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//void	OrkidEngine::registerResources()
//{
//	OkdMeshHandler::create();
//	OkdSceneHandler::create();
//}
//
////-----------------------------------------------------------------------------
//// Name:		unregisterResources
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//void	OrkidEngine::unregisterResources()
//{
//	OkdMeshHandler::destroy();
//	OkdSceneHandler::destroy();
//}

////-----------------------------------------------------------------------------
//// Name:		addScene
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//OkdScene*	OrkidEngine::addScene(const OkdString& strSceneName)
//{
//	OkdScene* pScene = getScene( strSceneName );
//
//	if	( !pScene )
//	{
//		pScene = new OkdScene();
//		_sceneList.add( strSceneName, pScene );
//	}
//
//	return	( pScene );
//}

////-----------------------------------------------------------------------------
//// Name:		getScene
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//OkdScene*	OrkidEngine::getScene( const OkdString& strSceneName )
//{
//	OkdScene* pScene = 0; 
//	
//	_sceneList.find( strSceneName, &pScene );
//	return	( pScene );
//}
