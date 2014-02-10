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
class OkdEntityManager;
class OkdComponentFactory;
class OkdAbstractSystem;

class OrkidEngine: public OkdSingleton<OrkidEngine>
{
	friend class OkdSingleton<OrkidEngine>;

public:
	// OkdSingleton overloading
	virtual void				onCreate();

	// Resources
	inline OkdResourceManager*	getResourceManager();
	inline OkdResourceDatabase*	getResourceDatabase();

	// Entities
	inline OkdEntityManager*	getEntityManager();

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
	OkdEntityManager*			_pEntityManager;
	OkdComponentFactory*		_pComponentFactory;

	OkdSystemList				_systemList;
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

//-----------------------------------------------------------------------------
// Name:		getEntityManager
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdEntityManager*	OrkidEngine::getEntityManager()
{
	return	( _pEntityManager );
}

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