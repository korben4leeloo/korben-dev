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

class OkdAbstractGameplay;
class OkdFreeCameraGameplay;

enum OkdGameplayType
{
	OkdGameplayTypeFreeCamera,
	OkdGameplayTypeFirstPerson,
	OkdGameplayTypeThirdPerson,
};



template<class T, class...Args>
class OkdGameplayHandler: public OkdSingleton<OkdGameplayHandler<T, Args...>>
{
	friend class OkdSingleton<OkdGameplayHandler>;

public:
	T* createGameplay( Args...args )
	{
		T* p = new T( args... );
		return	( p );
	}

	void update()
	{

	}

private:
				OkdGameplayHandler() {}
				~OkdGameplayHandler() {}

	OkdList<T*>	_gameplayList;
};

typedef OkdGameplayHandler<OkdFreeCameraGameplay> OkdFreeCameraGameplayHandler;

class OkdGameplayManager: public OkdSingleton<OkdGameplayManager>
{
	friend class OkdSingleton<OkdGameplayManager>;

public:
	/*template<class T, OkdGameplayType GameplayType>
	T* createGameplay( OkdHandle<T, Args...> hCreator )
	{
		T* p = hCreator::creator( args );
		return p;
	}*/

	void	update();

private:
	typedef OkdAbstractGameplay* (*pfnGameplayCreator)();

									OkdGameplayManager();
									~OkdGameplayManager();

	//OkdList<OkdAbstractGameplay*>	_gameplayList;
	//std::tuple<OkdFreeCameraGameplayHandler>
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif