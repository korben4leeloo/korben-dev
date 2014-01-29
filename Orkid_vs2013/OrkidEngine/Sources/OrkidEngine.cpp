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
#include	ORKID_ENGINE_H(Entities/OkdEntityFactory)
#include	ORKID_ENGINE_H(Gameplay/OkdGameplayManager)
#include	ORKID_ENGINE_H(SceneGraph/OkdScene)

OrkidEngine* OrkidEngine::_pInstance = 0;

const char* OrkidEngine::_resourceTypeName[OrkidResourceTypeCount] =
{
	"OrkidMesh", 
	"OrkidScene",
	"OrkidShader",
	"OrkidShaderProgram",
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

	// Entities
	_pEntityFactory = new OkdEntityFactory();

	// Gameplay manager
	OkdGameplayManager::create();
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

	// Gameplay manager
	OkdGameplayManager::destroy();

	_pResourceDatabase->close();

	delete _pEntityFactory;
	delete _pResourceManager;
	delete _pResourceDatabase;

	OrkidCore::uninitialize();
}

//-----------------------------------------------------------------------------
// Name:		update
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OrkidEngine::update()
{
	OkdGameplayManager::instance()->update();
}
