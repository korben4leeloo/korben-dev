//*****************************************************************************
//
//	Class:		TkScene
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_CORE_TK_SCENE_H__
#define __TARS_CORE_TK_SCENE_H__

#include "Root.h"

class TkEntity;

class TkScene
{
public:
						TkScene( const TkString& strSceneName );
						~TkScene();



private:
	TkString			_strSceneName;
	TkVector<TkEntity*>	_entityArray;
};

#endif