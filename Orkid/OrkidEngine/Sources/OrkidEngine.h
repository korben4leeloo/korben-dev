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
class OkdScene;

typedef OkdMap<OkdString, OkdScene*>	OkdSceneMap;

//#define	REGISTER_RESOURCE_TYPE( ResourceHandlerPtr )	OrkidEngine::instance()->getResourceManager()->registerResourceType( ResourceHandlerPtr )
//#define	UNREGISTER_RESOURCE_TYPE( ResourceHandlerPtr )	OrkidEngine::instance()->getResourceManager()->unregisterResourceType( ResourceHandlerPtr )
//#define	REGISTER_RESOURCE_TYPE( ResourceTypeName, ResourceHandlerType )	OrkidEngine::instance()->getResourceManager()->registerResourceType( ResourceHandlerPtr );
//#define	UNREGISTER_RESOURCE_TYPE( ResourceHandlerType )	OrkidEngine::instance()->getResourceManager()->unregisterResourceType( ResourceTypeName );

class OrkidEngine
{
public:
	inline static OrkidEngine*	create();
	inline static void			destroy();
	inline static OrkidEngine*	instance();

	// Resource managers
	inline OkdResourceManager*	getResourceManager();

	// Scenes
	OkdScene*					addScene( const OkdString& strSceneName );
	OkdScene*					getScene( const OkdString& strSceneName );

	static const char*			_strDefaultScene;
	static const char*			_resourceTypeName[OrkidResourceTypeLast];

private:
								OrkidEngine();
								~OrkidEngine();

	void						initialize();
	void						uninitialize();

	void						registerResources();
	void						unregisterResources();

	void						clear();
	template<class T> void		clearMap( T* pMap );

	OkdResourceManager*			_pResourceManager;
	OkdSceneMap					_sceneList;

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

#endif