////*****************************************************************************
////
//<<<<<<< HEAD
////	Class:		TkRenderManager
//=======
////	Class:		TkScene
//>>>>>>> origin/master
////
////	Created:	2013-08-26
////
////*****************************************************************************
//
//#ifndef __TARS_CORE_TK_RENDER_MANAGER_H__
//#define __TARS_CORE_TK_RENDER_MANAGER_H__
//
//#include "Root.h"
//
//<<<<<<< HEAD
//class TkWin32Wnd;
//=======
//class TkApplication;
//class TkWindow;
//>>>>>>> origin/master
//class TkOpenGLContext;
//
//class TkRenderManager
//{
//public:
//<<<<<<< HEAD
//						TkRenderManager();
//						~TkRenderManager();
//
//	TkWin32Wnd*			createWindow();
//	void				destroyWindow( const TkWin32Wnd* pWindow );
//
//	TkOpenGLContext*	createOpenGLContext( const TkWin32Wnd* pWindow );
//	void				destroyOpenGLContext( const TkOpenGLContext* pContext );
//
//private:
//	struct TkRenderTarget
//	{
//							TkRenderTarget();
//
//		TkWin32Wnd*			_pWindow;
//		TkOpenGLContext*	_pContext;
//	};
//=======
//							TkRenderManager( const TkApplication* pApplication );
//							~TkRenderManager();
//
//	TkWindow*				createWindow( const TkString& strWindowTitle );
//	void					destroyWindow( const TkWindow* pWindow );
//
//	TkOpenGLContext*		createOpenGLContext( const TkWindow* pWindow );
//	void					destroyOpenGLContext( const TkOpenGLContext* pContext );
//
//private:
//	const TkApplication*	_pApplication;
//>>>>>>> origin/master
//};
//
//#endif