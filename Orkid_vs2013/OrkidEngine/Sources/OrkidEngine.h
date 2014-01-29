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

#include	ORKID_CORE_H(Containers/OkdMap)
#include	ORKID_CORE_H(String/OkdString)

class OkdResourceManager;
class OkdResourceDatabase;
class OkdEntityFactory;

class OrkidEngine
{
public:
	inline static OrkidEngine*	create();
	inline static void			destroy();
	inline static OrkidEngine*	instance();

	// Resources
	inline OkdResourceManager*	getResourceManager();
	inline OkdResourceDatabase*	getResourceDatabase();

	// Entities
	inline OkdEntityFactory*	getEntityFactory();

	// Update
	void						update();

	static const char*			_resourceTypeName[OrkidResourceTypeCount];

private:
								OrkidEngine();
								~OrkidEngine();

	void						initialize();
	void						uninitialize();

	void						clear();
	template<class T> void		clearMap( T* pMap );

	OkdResourceManager*			_pResourceManager;
	OkdResourceDatabase*		_pResourceDatabase;
	OkdEntityFactory*			_pEntityFactory;

	static OrkidEngine*			_pInstance;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		create
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OrkidEngine*	OrkidEngine::create()
{
	destroy();

	_pInstance = new OrkidEngine();
	_pInstance->initialize();

	return	( _pInstance );
}

//-----------------------------------------------------------------------------
// Name:		destroy
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OrkidEngine::destroy()
{
	if	( _pInstance )
	{
		delete _pInstance;
		_pInstance = 0;
	}
}

//-----------------------------------------------------------------------------
// Name:		instance
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OrkidEngine*	OrkidEngine::instance()
{
	ORKID_ASSERT( _pInstance );
	return	( _pInstance );
}

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
// Name:		getEntityFactory
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdEntityFactory*	OrkidEngine::getEntityFactory()
{
	return	( _pEntityFactory );
}

#endif