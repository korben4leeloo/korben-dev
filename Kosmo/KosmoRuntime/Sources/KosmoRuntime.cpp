//*****************************************************************************
//
//	File:		KosmoRuntime.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"KosmoRuntimeRoot.h"

#include	KOSMO_CORE_H(GUI/KsWindow)

//-----------------------------------------------------------------------------
// Name:		main
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
int main()
{
	return	( 0 );
}

//-----------------------------------------------------------------------------
// Name:		WinMain
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
int CALLBACK WinMain(_In_ HINSTANCE	hInstance, 
					 _In_ HINSTANCE	hPrevInstance,
					 _In_ LPSTR		lpCmdLine,
					 _In_ int		nCmdShow)
{
	KsWindow	wnd;
	MSG			msg;

	wnd.create();

	bool running = true;

	while (running)
	{
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) { // If we have a message to process, process it
			if (msg.message == WM_QUIT) {
				running = false; // Set running to false if we have a message to quit
			}
			else {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}

		{ // If we don't have a message to process
			//openglContext.renderScene(); // Render our scene (which also handles swapping of buffers)
			//openGLContext.render();
		}
	}

	return	( (int)msg.wParam );
}
