//*****************************************************************************
//
//	Class:		OkdGameplayManager
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdGameplayManager_h__
#define __OrkidEngine_OkdGameplayManager_h__

#include	"Root.h"
#include	<tuple>

#include	ORKID_CORE_H(Singleton/OkdSingleton)
#include	ORKID_CORE_H(Containers/OkdList)

class OkdFreeCameraGameplay;

enum OkdGameplayType
{
	OkdGameplayTypeFreeCamera
};

template<class T>
struct OkdGameplayHandler
{
	static T* create()
	{
		return	( new T() );
	}

	OkdList<T*>	_gameplayList;
};

typedef std::tuple<OkdGameplayHandler<OkdFreeCameraGameplay>> OkdGameplayHandlerArray;

class OkdGameplayManager: public OkdSingleton<OkdGameplayManager>
{
	friend class OkdSingleton<OkdGameplayManager>;

public:
	template<class T>
	T* createGameplay( const OkdGameplayType eGameplayType )
	{
		auto m = std::get<eGameplayType>( _gameplayHandlerArray );
		return 0;
	}

private:
							OkdGameplayManager();
							~OkdGameplayManager();

	OkdGameplayHandlerArray	_gameplayHandlerArray;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif