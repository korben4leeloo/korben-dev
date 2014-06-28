//*****************************************************************************
//
//	File:		KsWindow.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"KsWindow.h"

//-----------------------------------------------------------------------------
// Name:		KsWindow constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KsWindow::KsWindow()
: _hWnd( NULL )
{
	
}

//-----------------------------------------------------------------------------
// Name:		KsWindow destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KsWindow::~KsWindow()
{

}

//-----------------------------------------------------------------------------
// Name:		create
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void KsWindow::create()
{
	const char* title	= "TestWindow";
	const int	width	= 500;
	const int	height	= 500;

	DWORD		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
	HINSTANCE	hInstance = GetModuleHandle( NULL );
	WNDCLASS	windowClass;

	windowClass.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	windowClass.lpfnWndProc		= KsWindow::windowMessageCallback;
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

	ShowWindow( _hWnd, SW_SHOW );
}

//-----------------------------------------------------------------------------
// Name:		windowMessageCallback
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
LRESULT KsWindow::windowMessageCallback( HWND hWnd, UINT uiMessage, WPARAM wParam, LPARAM lParam )
{
	switch	( uiMessage )
	{
		case WM_DESTROY:
		{
			PostQuitMessage( 0 );
			break;
		}
	}

	return	( DefWindowProc( hWnd, uiMessage, wParam, lParam ) );
}