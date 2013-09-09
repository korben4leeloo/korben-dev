#include	"OrkidRuntimeDllRoot.h"

#include	<Windows.h>
#include	ORKID_ENGINE_H(OpenGL/OkdOpenGLContext)

OkdOpenGLContext openGLContext;

/**
	WndProc is a standard method used in Win32 programming for handling Window messages. Here we
	handle our window resizing and tell our OpenGLContext the new window size.
*/
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
		case WM_SIZE: // If our window is resizing
		{
			//openglContext.reshapeWindow(LOWORD(lParam), HIWORD(lParam)); // Send the new window size to our OpenGLContext
			break;
		}

		case WM_DESTROY:
		{
			PostQuitMessage(0);
			break;
		}
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}

extern "C"
{
	__declspec(dllexport) void launch( HMODULE hRuntimeModule, HWND hEmbeddedWnd )
	{
		MSG msg;
		char *orig = "OpenGL 3 Project"; // Our windows title

		//createWindow(orig, 500, 500); // Create our OpenGL window

		WNDCLASS windowClass;
		HWND hWnd;
		//DWORD dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
		DWORD dwExStyle = 0;
		//DWORD dwStyle = WS_OVERLAPPEDWINDOW;
		DWORD dwStyle = WS_CHILD;

		//HINSTANCE hInstance = GetModuleHandle( 0 );

		windowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		windowClass.lpfnWndProc = (WNDPROC) WndProc;
		windowClass.cbClsExtra = 0;
		windowClass.cbWndExtra = 0;
		//windowClass.hInstance = hInstance;
		windowClass.hInstance = hRuntimeModule;
		windowClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
		windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		windowClass.hbrBackground = NULL;
		windowClass.lpszMenuName = NULL;
		windowClass.lpszClassName = "OrkidRuntimeDll";

		if (!RegisterClass(&windowClass)) {
			DWORD dwError = GetLastError();
			return;
		}

		hWnd = CreateWindowEx(dwExStyle, "OrkidRuntimeDll", "OrkidRuntimeDll", dwStyle,
			CW_USEDEFAULT, 0, 500, 500, hEmbeddedWnd, NULL, hRuntimeModule, NULL);

		if	( hWnd == 0 )
		{
			DWORD dwError = GetLastError();
			return;
		}

		//openglContext.create30Context(hWnd); // Create our OpenGL context on the given window we just created
		openGLContext.create( hWnd );

		ShowWindow(hWnd, SW_SHOW);
		UpdateWindow(hWnd);

		//openglContext.setupScene(); // Setup our OpenGL scene

		bool bRunning = true;

		while (bRunning)
		{
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) { // If we have a message to process, process it
				if (msg.message == WM_QUIT) {
					bRunning = false; // Set running to false if we have a message to quit
				}
				else {
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
			}
			else { // If we don't have a message to process
				//openglContext.renderScene(); // Render our scene (which also handles swapping of buffers)
				openGLContext.render();
			}
		}
	}
}
