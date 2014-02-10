//*****************************************************************************
//
//	Class:		OrkidEngine
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OrkidEngine_h__
#define __OrkidEngine_OrkidEngine_h__

#include	"OrkidEngineRoot.h"

#include	ORKID_CORE_H(Singleton/OkdSingleton)
#include	ORKID_CORE_H(Containers/OkdMap)
#include	ORKID_CORE_H(Containers/OkdList)
#include	ORKID_CORE_H(String/OkdString)

class OkdResourceManager;
class OkdResourceDatabase;
class OkdEntityFactory;
class OkdComponentFactory;
class OkdAbstractSystem;

class OrkidEngine: public OkdSingleton<OrkidEngine>
{
	friend class OkdSingleton<OrkidEngine>;

public:
	// Resources
	inline OkdResourceManager*	getResourceManager();
	inline OkdResourceDatabase*	getResourceDatabase();

	// Entities
	//inline OkdEntityFactory*	getEntityFactory();

	// Components
	inline OkdComponentFactory*	getComponentFactory();

	// Update
	void						update();

	static const char*			_resourceTypeName[OrkidResourceTypeCount];

private:
	typedef OkdList<OkdAbstractSystem*> OkdSystemList;

								OrkidEngine();
								~OrkidEngine();

	void						initialize();
	void						uninitialize();

	void						registerComponents();
	void						registerSystems();

	OkdResourceManager*			_pResourceManager;
	OkdResourceDatabase*		_pResourceDatabase;
	//OkdEntityFactory*			_pEntityFactory;
	OkdComponentFactory*		_pComponentFactory;

	OkdSystemList				_systemList;

	//static OrkidEngine*			_pInstance;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		getResourceManager
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourceManager*	OrkidEngine::getResourceManager()
{
	return	( _pResourceManager );
}

//-----------------------------------------------------------------------------
// Name:		getResourceDatabase
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourceDatabase*	OrkidEngine::getResourceDatabase()
{
	return	( _pResourceDatabase );
}

////-----------------------------------------------------------------------------
//// Name:		getEntityFactory
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//OkdEntityFactory*	OrkidEngine::getEntityFactory()
//{
//	return	( _pEntityFactory );
//}

//-----------------------------------------------------------------------------
// Name:		getComponentFactory
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdComponentFactory*	OrkidEngine::getComponentFactory()
{
	return	( _pComponentFactory );
}

#endif