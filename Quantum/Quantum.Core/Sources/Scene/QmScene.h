//*****************************************************************************
//
//	Class:		QmScene
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __QUANTUM_CORE_TK_SCENE_H__
#define __QUANTUM_CORE_TK_SCENE_H__

#include "Root.h"

class QmEntity;

class QmScene
{
public:
						QmScene( const QmString& strSceneName );
						~QmScene();



private:
	QmString			_strSceneName;
	QmVector<QmEntity*>	_entityArray;
};

#endif