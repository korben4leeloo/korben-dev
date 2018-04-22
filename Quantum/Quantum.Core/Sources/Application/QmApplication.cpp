//*****************************************************************************
//
//	File:		QmApplication.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "QmApplication.h"

#include QUANTUM_CORE_H(Rendering/Window/QmWindow)
#include QUANTUM_CORE_H(Input/QmInputManager)

//-----------------------------------------------------------------------------
// Name:		QmApplication constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmApplication::QmApplication( const HINSTANCE& hInstance )
: _hInstance		( hInstance )
, _pInputManager	( nullptr )
{
	
}

//-----------------------------------------------------------------------------
// Name:		QmApplication destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmApplication::~QmApplication()
{
	destroy();
}

//-----------------------------------------------------------------------------
// Name:		destroy
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void QmApplication::destroy()
{
	delete _pInputManager;
	_pInputManager = nullptr;

	destroyWindows();
}

//-----------------------------------------------------------------------------
// Name:		init
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void QmApplication::init()
{
	initInputs();
}

//-----------------------------------------------------------------------------
// Name:		initInputs
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmInputManager* QmApplication::initInputs()
{
	delete _pInputManager;

	_pInputManager = new QmInputManager();
	_pInputManager->registerDevices();

	return ( _pInputManager );
}

//-----------------------------------------------------------------------------
// Name:		createWindow
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmWindow* QmApplication::createWindow()
{
	QmWindow* pWindow = new QmWindow( this );

	pWindow->create();
	pWindow->show();

	_windowArray.pushBack( pWindow );

	return ( pWindow );
}

//-----------------------------------------------------------------------------
// Name:		destroyWindows
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void QmApplication::destroyWindows()
{
	uint32 uiWindowCount = _windowArray.size();

	for ( uint32 i = 0; i < uiWindowCount; i++ )
	{
		delete _windowArray[i];
	}

	_windowArray.clear();
}

//-----------------------------------------------------------------------------
// Name:		run
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
int64_t QmApplication::run()
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
			_TaskScheduler.execute();

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