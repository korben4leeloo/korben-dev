//*****************************************************************************
//
//	Class:		TkScene
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_CORE_TK_RENDER_MANAGER_H__
#define __TARS_CORE_TK_RENDER_MANAGER_H__

#include "Root.h"

class TkApplication;
class TkWindow;
class TkOpenGLContext;

class TkRenderManager
{
public:
							TkRenderManager( const TkApplication* pApplication );
							~TkRenderManager();

	TkWindow*				createWindow( const TkString& strWindowTitle );
	void					destroyWindow( const TkWindow* pWindow );

	TkOpenGLContext*		createOpenGLContext( const TkWindow* pWindow );
	void					destroyOpenGLContext( const TkOpenGLContext* pContext );

private:
	const TkApplication*	_pApplication;
};

#endif