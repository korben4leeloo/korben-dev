//*****************************************************************************
//
//	File:		TsWin32Window.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "TsWin32Window.h"

#include <Windows.h>

//-----------------------------------------------------------------------------
// Name:		TsWin32Window constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TsWin32Window::TsWin32Window( const QString& strWindowName, const int nClientWidth, const int nClientHeight )
: _strWindowName	( strWindowName )
, _nClientWidth		( nClientWidth )
, _nClientHeight	( nClientHeight )
{
	
}

//-----------------------------------------------------------------------------
// Name:		TsWin32Window destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TsWin32Window::~TsWin32Window()
{
	
}

//-----------------------------------------------------------------------------
// Name:		create
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	TsWin32Window::create( const HINSTANCE& hInstance, const bool bShow )
{
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style

	_hWnd=CreateWindowEx(	dwExStyle,							// Extended Style For The Window
								"OpenGL",							// Class Name
								strWindowName,								// Window Title
								dwStyle |							// Defined Window Style
								WS_CLIPSIBLINGS |					// Required Window Style
								WS_CLIPCHILDREN,					// Required Window Style
								0, 0,								// Window Position
								WindowRect.right-WindowRect.left,	// Calculate Window Width
								WindowRect.bottom-WindowRect.top,	// Calculate Window Height
								NULL,								// No Parent Window
								NULL,								// No Menu
								hInstance,							// Instance
								NULL)))								// Dont Pass Anything To WM_CREATE
}