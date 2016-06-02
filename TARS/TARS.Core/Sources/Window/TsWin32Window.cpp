//*****************************************************************************
//
//	File:		TsWin32Window.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "TsWin32Window.h"

#define DEFAULT_WINDOW_NAME		"TsMainWindow"
#define DEFAULT_CLIENT_WIDTH	1024
#define DEFAULT_CLIENT_HEIGHT	768
#define DEFAULT_BITS_PER_PIXEL	32

//-----------------------------------------------------------------------------
// Name:		TsWin32Window constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TsWin32Window::TsWin32Window()
: _strWindowName	( DEFAULT_WINDOW_NAME )
, _nClientWidth		( DEFAULT_CLIENT_WIDTH )
, _nClientHeight	( DEFAULT_CLIENT_HEIGHT )
, _nBitsPerPixel	( DEFAULT_BITS_PER_PIXEL )
, _bFullscreen		( false )
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
void	TsWin32Window::create( const HINSTANCE& hInstance )
{
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values

	WindowRect.left		= 0;				// Set Left Value To 0
	WindowRect.right	= _nClientWidth;	// Set Right Value To Requested Width
	WindowRect.top		= 0;				// Set Top Value To 0
	WindowRect.bottom	= _nClientHeight;	// Set Bottom Value To Requested Height

	//fullscreen=fullscreenflag;			// Set The Global Fullscreen Flag

	//hInstance			= GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc		= (WNDPROC)TsWin32Window::WndProc;		// WndProc Handles Messages
	wc.cbClsExtra		= 0;									// No Extra Window Data
	wc.cbWndExtra		= 0;									// No Extra Window Data
	wc.hInstance		= hInstance;							// Set The Instance
	wc.hIcon			= LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground	= NULL;									// No Background Required For GL
	wc.lpszMenuName		= NULL;									// We Don't Want A Menu
	wc.lpszClassName	= "TsWin32Window";						// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL,"Failed To Register The Window Class.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		//return FALSE;											// Return FALSE
	}
	
	if	( _bFullscreen )										// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings,0,sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize=sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth	= _nClientWidth;		// Selected Screen Width
		dmScreenSettings.dmPelsHeight	= _nClientHeight;		// Selected Screen Height
		dmScreenSettings.dmBitsPerPel	= _nBitsPerPixel;		// Selected Bits Per Pixel
		dmScreenSettings.dmFields=DM_BITSPERPEL|DM_PELSWIDTH|DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings,CDS_FULLSCREEN)!=DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL,"The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?","NeHe GL",MB_YESNO|MB_ICONEXCLAMATION)==IDYES)
			{
				_bFullscreen = false;		// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL,"Program Will Now Close.","ERROR",MB_OK|MB_ICONSTOP);
				//return FALSE;									// Return FALSE
			}
		}
	}

	if	( _bFullscreen )										// Are We Still In Fullscreen Mode?
	{
		dwExStyle	= WS_EX_APPWINDOW;							// Window Extended Style
		dwStyle		= WS_POPUP;									// Windows Style

		ShowCursor( FALSE );									// Hide Mouse Pointer
	}
	else
	{
		dwExStyle	= WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle		= WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx( &WindowRect, dwStyle, FALSE, dwExStyle );		// Adjust Window To True Requested Size

	// Create The Window
	if (!(_hWnd=CreateWindowEx(	dwExStyle,							// Extended Style For The Window
								"OpenGL",							// Class Name
								(LPCSTR)_strWindowName.data(),				// Window Title
								dwStyle |							// Defined Window Style
								WS_CLIPSIBLINGS |					// Required Window Style
								WS_CLIPCHILDREN,					// Required Window Style
								0, 0,								// Window Position
								WindowRect.right - WindowRect.left,	// Calculate Window Width
								WindowRect.bottom - WindowRect.top,	// Calculate Window Height
								NULL,								// No Parent Window
								NULL,								// No Menu
								hInstance,							// Instance
								NULL)))								// Dont Pass Anything To WM_CREATE
	{
		//KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Window Creation Error.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		//return FALSE;								// Return FALSE
	}
}

//-----------------------------------------------------------------------------
// Name:		WndProc
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
LRESULT CALLBACK TsWin32Window::WndProc(	HWND	hWnd,			// Handle For This Window
											UINT	uMsg,			// Message For This Window
											WPARAM	wParam,			// Additional Message Information
											LPARAM	lParam)			// Additional Message Information
{
	switch (uMsg)									// Check For Windows Messages
	{
		case WM_ACTIVATE:							// Watch For Window Activate Message
		{
			if (!HIWORD(wParam))					// Check Minimization State
			{
				//active=TRUE;						// Program Is Active
			}
			else
			{
				//active=FALSE;						// Program Is No Longer Active
			}

			return 0;								// Return To The Message Loop
		}

		case WM_SYSCOMMAND:							// Intercept System Commands
		{
			switch (wParam)							// Check System Calls
			{
				case SC_SCREENSAVE:					// Screensaver Trying To Start?
				case SC_MONITORPOWER:				// Monitor Trying To Enter Powersave?
				return 0;							// Prevent From Happening
			}
			break;									// Exit
		}

		case WM_CLOSE:								// Did We Receive A Close Message?
		{
			PostQuitMessage(0);						// Send A Quit Message
			return 0;								// Jump Back
		}

		case WM_KEYDOWN:							// Is A Key Being Held Down?
		{
			//keys[wParam] = TRUE;					// If So, Mark It As TRUE
			return 0;								// Jump Back
		}

		case WM_KEYUP:								// Has A Key Been Released?
		{
			//keys[wParam] = FALSE;					// If So, Mark It As FALSE
			return 0;								// Jump Back
		}

		case WM_SIZE:								// Resize The OpenGL Window
		{
			//ReSizeGLScene(LOWORD(lParam),HIWORD(lParam));  // LoWord=Width, HiWord=Height
			return 0;								// Jump Back
		}
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd,uMsg,wParam,lParam);
}