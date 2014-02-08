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
#include	ORKID_CORE_H(Components/OkdComponentFactory)
#include	ORKID_ENGINE_H(Gameplay/OkdGameplayManager)
#include	ORKID_ENGINE_H(SceneGraph/OkdScene)

#include	ORKID_ENGINE_H(Components/OkdTransformComponent)
#include	ORKID_ENGINE_H(Components/OkdMeshComponent)
#include	ORKID_ENGINE_H(Components/OkdLightComponent)
#include	ORKID_ENGINE_H(Components/OkdCameraComponent)

#include	ORKID_ENGINE_H(Systems/OkdRenderSystem)

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
//, _pEntityFactory		( 0 )
, _pComponentFactory	( 0 )
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

	// Systems and Components
	_pComponentFactory = new OkdComponentFactory();

	registerComponents();
	registerSystems();

	// Entities
	//_pEntityFactory = new OkdEntityFactory();

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
	// Gameplay manager
	OkdGameplayManager::destroy();

	_pResourceDatabase->close();

	//OKD_CLEAR_POINTER( _pEntityFactory )
	OKD_CLEAR_POINTER( _pComponentFactory )
	OKD_CLEAR_POINTER( _pResourceManager )
	OKD_CLEAR_POINTER( _pResourceDatabase )

	OrkidCore::uninitialize();
}

//-----------------------------------------------------------------------------
// Name:		registerComponents
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OrkidEngine::registerComponents()
{
	OKD_REGISTER_COMPONENT( OkdTransformComponent, _pComponentFactory )
	OKD_REGISTER_COMPONENT( OkdMeshComponent, _pComponentFactory )
	OKD_REGISTER_COMPONENT( OkdLightComponent, _pComponentFactory )
	OKD_REGISTER_COMPONENT( OkdCameraComponent, _pComponentFactory )
}

//-----------------------------------------------------------------------------
// Name:		registerSystems
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OrkidEngine::registerSystems()
{
	// Render system
	OkdRenderSystem* pRenderSystem = new OkdRenderSystem();

	OKD_SIGNAL_CONNECT( _pComponentFactory, _onCreateComponentSignal, pRenderSystem, _onCreateComponentSlot );

	_systemList.add( pRenderSystem );
}

//-----------------------------------------------------------------------------
// Name:		update
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OrkidEngine::update()
{
	OkdSystemList::const_iterator itSystem = _systemList.begin();

	while	( itSystem != _systemList.end() )
	{
		(*itSystem)->update();
		itSystem++;
	}

	OkdGameplayManager::instance()->update();
}
