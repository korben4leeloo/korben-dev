//<<<<<<< HEAD
////*****************************************************************************
//=======
//﻿//*****************************************************************************
//>>>>>>> origin/master
////
////	File:		TkRenderManager.cpp
////	Created:	2013-08-26
////
////*****************************************************************************
//
//#include "TkRenderManager.h"
//
//<<<<<<< HEAD
//=======
//#include TARS_CORE_H(Rendering/Window/TkWindow)
//
//>>>>>>> origin/master
////-----------------------------------------------------------------------------
//// Name:		TkRenderManager constructor
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//<<<<<<< HEAD
//TkRenderManager::TkRenderManager()
//=======
//TkRenderManager::TkRenderManager( const TkApplication* pApplication )
//: _pApplication( pApplication )
//>>>>>>> origin/master
//{
//	
//}
//
////-----------------------------------------------------------------------------
//// Name:		TkRenderManager destructor
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//TkRenderManager::~TkRenderManager()
//{
//	
//}
//
////-----------------------------------------------------------------------------
//<<<<<<< HEAD
//// Name:		TkRenderTarget constructor
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//TkRenderManager::TkRenderTarget::TkRenderTarget()
//: _pWindow	( nullptr )
//, _pContext	( nullptr )
//{
//	
//=======
//// Name:		createWindow
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//TkWindow* TkRenderManager::createWindow( const TkString& strWindowTitle )
//{
//	TkWindow* pWindow = new TkWindow( _pApplication );
//
//	pWindow->setWindowTitle( strWindowTitle );
//	pWindow->create();
//
//	if	( pWindow->getWindowHandle() == nullptr )
//	{
//		delete pWindow;
//		pWindow = nullptr;
//	}
//
//	return ( pWindow );
//}
//
////-----------------------------------------------------------------------------
//// Name:		destroyWindow
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//void TkRenderManager::destroyWindow( const TkWindow* pWindow )
//{
//
//}
//
////-----------------------------------------------------------------------------
//// Name:		createOpenGLContext
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//TkOpenGLContext* TkRenderManager::createOpenGLContext( const TkWindow* pWindow )
//{
//
//}
//
////-----------------------------------------------------------------------------
//// Name:		destroyOpenGLContext
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//void TkRenderManager::destroyOpenGLContext( const TkOpenGLContext* pContext )
//{
//
//>>>>>>> origin/master
//}
