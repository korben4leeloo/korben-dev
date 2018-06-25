//*****************************************************************************
//
//	File:		QmApplication.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "QmApplication.h"

#include QUANTUM_CORE_H(Rendering/Window/QmWindow)
#include QUANTUM_CORE_H(Rendering/D3D/QmD3DContext)
#include QUANTUM_CORE_H(Input/QmInputManager)
#include QUANTUM_CORE_H(Resources/QmResourceManager)

//-----------------------------------------------------------------------------
// Name:		QmApplication constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmApplication::QmApplication( const HINSTANCE& hInstance )
: _hInstance( hInstance )
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
	createInputManager();
	createResourceManager();
}

//-----------------------------------------------------------------------------
// Name:		createInputManager
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmInputManager* QmApplication::createInputManager()
{
	delete _pInputManager;

	_pInputManager = new QmInputManager();
	_pInputManager->registerDevices();

	return ( _pInputManager );
}

//-----------------------------------------------------------------------------
// Name:		createResourceManager
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmResourceManager* QmApplication::createResourceManager()
{
	delete _pResourceManager;

	_pResourceManager = new QmResourceManager();
	_pResourceManager->loadResourceDefinitions();

	return ( _pResourceManager );
}

//-----------------------------------------------------------------------------
// Name:		createWindow
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmWindow* QmApplication::createWindow()
{
	QmWindow* pWindow = new QmWindow();

	pWindow->create( _hInstance );
	pWindow->show();

	QM_SIGNAL_CONNECT( pWindow, OnInputReceived, _pInputManager, OnInputReceived );

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
// Name:		createWindow
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmD3DContext* QmApplication::createD3DContext( QmWindow* pWindow )
{
	QmD3DContext* pD3DContext = new QmD3DContext();
	pD3DContext->create( pWindow );
	return pD3DContext;
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