//*****************************************************************************
//
//	Class:		QmRenderScene
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __QUANTUM_CORE_RENDER_SCENE_H__
#define __QUANTUM_CORE_RENDER_SCENE_H__

#include "Root.h"

class QmD3DContext;
class QmScene;

class QmRenderScene
{
public:
								QmRenderScene();
								~QmRenderScene();

private:
	QmD3DContext*	_pRenderContext	= nullptr;
	QmScene*		_pScene			= nullptr;
};

#endif