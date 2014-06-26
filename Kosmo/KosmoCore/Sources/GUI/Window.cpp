//*****************************************************************************
//
//	File:		Window.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"Window.h"

//-----------------------------------------------------------------------------
// Name:		Window constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
Window::Window()
: _hwnd( NULL )
{
	
}

//-----------------------------------------------------------------------------
// Name:		Window destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
Window::~Window()
{

}

//-----------------------------------------------------------------------------
// Name:		create
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void Window::create()
{
	DWORD		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
	HINSTANCE	hInstance = GetModuleHandle( NULL );
	WNDCLASS	windowClass;

	windowClass.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	windowClass.lpfnWndProc		= (WNDPROC) WndProc;
	windowClass.cbClsExtra		= 0;
	windowClass.cbWndExtra		= 0;
	windowClass.hInstance		= hInstance;
	windowClass.hIcon			= LoadIcon( NULL, IDI_WINLOGO );
	windowClass.hCursor			= LoadCursor( NULL, IDC_ARROW );
	windowClass.hbrBackground	= NULL;
	windowClass.lpszMenuName	= NULL;
	windowClass.lpszClassName	= title;

	if	( !RegisterClass( &windowClass ) )
	{
		return;
	}

	_hWnd = CreateWindowEx( dwExStyle, title, title, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, width, height, NULL, NULL, hInstance, NULL );

	ShowWindow(hWnd, SW_SHOW);
}
