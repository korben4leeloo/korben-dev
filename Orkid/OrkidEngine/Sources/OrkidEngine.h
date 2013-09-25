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

typedef OkdMap<OkdString, OkdResourceManager*>	OkdResourceManagerMap;
typedef OkdMap<OkdString, OkdScene*>			OkdSceneMap;

class OrkidEngine
{
public:
	inline static OrkidEngine*	create();
	inline static void			destroy();
	inline static OrkidEngine*	instance();

	// Resource managers
	/*OkdResourceManager*			addResourceManager( const OkdString& strResourceManagerName );
	OkdResourceManager*			getResourceManager( const OkdString& strResourceManagerName );*/
	inline OkdResourceManager*	getResourceManager();

	// Scenes
	//OkdScene*					addScene( const OkdString& strSceneName, const OkdString& strResourceManagerName );
	OkdScene*					addScene( const OkdString& strSceneName );
	OkdScene*					getScene( const OkdString& strSceneName );

	static const char*			_strDefaultResourceManager;
	static const char*			_strDefaultScene;

private:
								OrkidEngine();
								~OrkidEngine();

	void						clear();
	template<class T> void		clearMap( T* pMap );

	//OkdResourceManagerMap		_resourceManagerList;
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