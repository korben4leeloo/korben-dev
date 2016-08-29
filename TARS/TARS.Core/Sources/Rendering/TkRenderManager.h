//*****************************************************************************
//
//	Class:		TkRenderManager
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_CORE_TK_RENDER_MANAGER_H__
#define __TARS_CORE_TK_RENDER_MANAGER_H__

#include "Root.h"

class TkWin32Wnd;
class TkOpenGLContext;

class TkRenderManager
{
public:
						TkRenderManager();
						~TkRenderManager();

	TkWin32Wnd*			createWindow();
	void				destroyWindow( const TkWin32Wnd* pWindow );

	TkOpenGLContext*	createOpenGLContext( const TkWin32Wnd* pWindow );
	void				destroyOpenGLContext( const TkOpenGLContext* pContext );

private:
	struct TkRenderTarget
	{
							TkRenderTarget();

		TkWin32Wnd*			_pWindow;
		TkOpenGLContext*	_pContext;
	};
};

#endif