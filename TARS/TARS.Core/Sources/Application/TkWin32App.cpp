//*****************************************************************************
//
//	File:		TkWin32App.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "TkWin32App.h"

#include TARS_CORE_H(Window/TkWin32Wnd)

//-----------------------------------------------------------------------------
// Name:		TkWin32App constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkWin32App::TkWin32App( const HINSTANCE& hInstance )
: _hInstance( hInstance )
{
	
}

//-----------------------------------------------------------------------------
// Name:		TkWin32App destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkWin32App::~TkWin32App()
{
	
}

//-----------------------------------------------------------------------------
// Name:		createWindow
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkWin32Wnd* TkWin32App::createWindow()
{
	TkWin32Wnd*		pWindow		= new TkWin32Wnd( this );
	//TkEventManager*	pEventManager	= new TkEventManager();

	//pMainWindow->setEventManager( pEventManager );
	pWindow->create();
	pWindow->show();

	return ( pWindow );
}

//-----------------------------------------------------------------------------
// Name:		runMessageLoop
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
int64_t TkWin32App::runMessageLoop()
{
	BOOL	bRun = true;
	MSG		msg;
	
	//// Create Our OpenGL Window
	//if (!CreateGLWindow("NeHe's OpenGL Framework",640,480,16,fullscreen))
	//{
	//	return 0;									// Quit If Window Was Not Created
	//}

	while ( bRun )
	{
		if	( PeekMessage( &msg, nullptr, 0, 0, PM_REMOVE ) )	// Is There A Message Waiting?
		{
			if	( msg.message == WM_QUIT )				// Have We Received A Quit Message?
			{
				bRun = false;
			}
			else									// If Not, Deal With Window Messages
			{
				TranslateMessage( &msg );				// Translate The Message
				DispatchMessage( &msg );				// Dispatch The Message
			}
		}
		else										// If There Are No Messages
		{
			//// Draw The Scene.  Watch For ESC Key And Quit Messages From DrawGLScene()
			//if (active)								// Program Active?
			//{
			//	if (keys[VK_ESCAPE])				// Was ESC Pressed?
			//	{
			//		done=TRUE;						// ESC Signalled A Quit
			//	}
			//	else								// Not Time To Quit, Update Screen
			//	{
			//		DrawGLScene();					// Draw The Scene
			//		SwapBuffers(hDC);				// Swap Buffers (Double Buffering)
			//	}
			//}

			//if (keys[VK_F1])						// Is F1 Being Pressed?
			//{
			//	keys[VK_F1]=FALSE;					// If So Make Key FALSE
			//	KillGLWindow();						// Kill Our Current Window
			//	fullscreen=!fullscreen;				// Toggle Fullscreen / Windowed Mode
			//	// Recreate Our OpenGL Window
			//	if (!CreateGLWindow("NeHe's OpenGL Framework",640,480,16,fullscreen))
			//	{
			//		return 0;						// Quit If Window Was Not Created
			//	}
			//}
		}
	}

	// Shutdown
	return (msg.wParam);							// Exit The Program
}