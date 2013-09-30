//*****************************************************************************
//
//	File:		OkdRuntime.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OrkidRuntimeRoot.h"

//#include	<3dEngine/SceneManager/OkdScene.h>

#include	ORKID_MATH_H(OkdMatrix4f)
#include	ORKID_MATH_H(OkdVector3f)
#include	ORKID_MATH_H(OkdQuaternionf)

//int main()
//{
//	//OkdScene scene;
//
//	OkdMatrix4f		m1, m2, m3;
//	OkdVector3f		v1, v2, v3;
//	OkdQuaternionf	q1, q2, q3;
//
//	v1 = OkdVector3f( 3.0f, 5.0f, 1.0f );
//	v2 = OkdVector3f( -7.0f, 6.0f, 4.0f );
//
//	m1.setIdentity();
//	m2.setIdentity();
//
//	m1.setTranslation( v1 );
//	m2.setTranslation( v2 );
//
//	q1 = OkdQuaternionf( OkdVector3f::unitY(), 0.785398163397448309616f );
//	q2 = OkdQuaternionf( OkdVector3f::unitX(), 0.785398163397448309616f );
//
//	m1.setRotation( q1 );
//	m2.setRotation( q2 );
//
//	m3 = m2 * m1;
//
//	v3 = m3.getTranslation();
//	q3 = m3.getQuaternion();
//
//	return	( 0 );
//}

#include	<Windows.h>
#include	ORKID_ENGINE_H(OpenGL/OkdOpenGLContext)

//OpenGLContext openglContext; // Our OpenGL Context class
OkdOpenGLContext openGLContext;

bool running = true; // Whether or not the application is currently running

HINSTANCE hInstance; // The HINSTANCE of this application
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); // Standard window callback

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

/**
	createWindow is going to create our window using Windows API calls. It is then going to
	create our OpenGL context on the window and then show our window, making it visible.
*/
//bool createWindow(LPCWSTR title, int width, int height) {
bool createWindow(LPCSTR title, int width, int height) {
	WNDCLASS windowClass;
	HWND hWnd;
	DWORD dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;

	hInstance = GetModuleHandle(NULL);

	windowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	windowClass.lpfnWndProc = (WNDPROC) WndProc;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = hInstance;
	windowClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.hbrBackground = NULL;
	windowClass.lpszMenuName = NULL;
	windowClass.lpszClassName = title;

	if (!RegisterClass(&windowClass)) {
		return false;
	}

	hWnd = CreateWindowEx(dwExStyle, title, title, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, width, height, NULL, NULL, hInstance, NULL);

	//openglContext.create30Context(hWnd); // Create our OpenGL context on the given window we just created
	openGLContext.create( hWnd );

	ShowWindow(hWnd, SW_SHOW);
    UpdateWindow(hWnd);

	return true;
}

//#include	ORKID_ENGINE_H(Entities/OkdMesh)

#include	ORKID_ENGINE_H(OrkidEngine)
//#include	ORKID_ENGINE_H(ResourceManager/OkdResourceManager)
#include	ORKID_ENGINE_H(ResourceManager/OkdResourceDatabase)
//#include	ORKID_ENGINE_H(ResourceManager/ResourceHandler/OkdMeshHandler)
//#include	ORKID_ENGINE_H(ResourceManager/ResourceHandler/OkdSceneHandler)
#include	ORKID_CORE_H(Xml/OkdXmlDocument)

/**
	WinMain is the main entry point for Windows based applications as opposed to 'main' for console
	applications. Here we will make the calls to create our window, setup our scene and then
	perform our 'infinite' loop which processes messages and renders.
*/
extern "C" {
int WINAPI WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR    lpCmdLine,
                     int       nCmdShow) {
	MSG msg;

	OrkidEngine*			pEngine				= OrkidEngine::create();
	/*OkdResourceManager*		pResourceManager	= pEngine->getResourceManager();
	OkdResourceId	defaultSceneIdentifier( OrkidScene, 0 );

	pResourceManager->addResource( defaultSceneIdentifier );*/

	OkdResourceDatabase db;

	OkdXmlDocument xmlDoc;

	xmlDoc.save( "c:\\test.xml" );

	//db.open();

	/*pResourceManager->registerResourceType( "MESH", 0 );
	pResourceManager->registerResourceType( "SCENE", 0 );*/

	/*OkdMeshHandler*		pMeshHandler	= OkdMeshHandler::create();
	OkdSceneHandler*	pSceneHandler	= OkdSceneHandler::create();*/

	/*OkdResourceManager* pResourceManager	= pEngine->addResourceManager( "TestResourceManager" );
	OkdScene*			pScene				= pEngine->addScene( "TestScene", "TestResourceManager" );
	OkdMeshResource		meshResource		= pResourceManager->addMesh( "TestMesh", "plouf.okm", RES_LOC_MEMORY );
	OkdMeshResource		meshResource2 = meshResource;
	OkdMeshResource		meshResource3 = meshResource2;

	meshResource2.load();*/

	//OkdResourceManager* pResourceManager	= pEngine->addResourceManager( "TestResourceManager" );
	//OkdScene*			pScene				= pEngine->addScene( "TestScene", "TestResourceManager" );

	//{
	//	OkdMeshResourcePtr	meshResource	= pResourceManager->addMesh( "TestMesh", "plouf.okm", RES_LOC_MEMORY );
	//	OkdMeshResourcePtr	meshResource4	= pResourceManager->addMesh( "TestMesh2", "plouf2.okm", RES_LOC_FILE );
	//	OkdMeshResourcePtr	meshResource2	= meshResource;
	//	OkdMeshResourcePtr	meshResource3	= meshResource2;

	//	meshResource2.load();
	//	meshResource.load();

	//	//meshResource2.load();
	//	meshResource2.unload();
	//	//meshResource3.unload();

	//	meshResource4.load();

	//	meshResource = meshResource4;
	//}

	OrkidEngine::destroy();

	/*HMODULE hLib = LoadLibrary( "D:\\DevJJA\\SVN\\korben-dev\\Orkid\\Debug\\OrkidRuntimeDll.dll" );
	FARPROC procAddr = GetProcAddress( hLib, "orkidRuntimeDllMainEntry" );*/

	//GetLastError():

	/**
		The following 6 lines of code do conversion between char arrays and LPCWSTR variables
		which are used in the Windows API.
	*/
	char *orig = "OpenGL 3 Project"; // Our windows title
	/*size_t origsize = strlen(orig) + 1;
    const size_t newsize = 100;
    size_t convertedChars = 0;
    wchar_t wcstring[newsize];
    mbstowcs_s(&convertedChars, wcstring, origsize, orig, _TRUNCATE);*/

	//createWindow(wcstring, 500, 500); // Create our OpenGL window
	createWindow(orig, 500, 500); // Create our OpenGL window

	//openglContext.setupScene(); // Setup our OpenGL scene

	/**
		This is our main loop, it continues for as long as running is true
	*/
	while (running)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) { // If we have a message to process, process it
			if (msg.message == WM_QUIT) {
				running = false; // Set running to false if we have a message to quit
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

	return (int) msg.wParam;
}

int __declspec(dllexport) launch( HMODULE hRuntimeModule )
{
	MSG msg;
	char *orig = "OpenGL 3 Project"; // Our windows title

	//createWindow(orig, 500, 500); // Create our OpenGL window

	WNDCLASS windowClass;
	HWND hWnd;
	DWORD dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;

	//hInstance = GetModuleHandle( "OrkidRuntime.exe" );

	windowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	windowClass.lpfnWndProc = (WNDPROC) WndProc;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	//windowClass.hInstance = hInstance;
	windowClass.hInstance = hRuntimeModule;
	/*windowClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);*/
	windowClass.hIcon = 0;
	windowClass.hCursor = 0;
	windowClass.hbrBackground = NULL;
	windowClass.lpszMenuName = NULL;
	windowClass.lpszClassName = "";

	if (!RegisterClass(&windowClass)) {
		return false;
	}

	hWnd = CreateWindowEx(dwExStyle, "", "", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, 500, 500, NULL, NULL, hInstance, NULL);

	//openglContext.create30Context(hWnd); // Create our OpenGL context on the given window we just created
	openGLContext.create( hWnd );

	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

	//openglContext.setupScene(); // Setup our OpenGL scene

	while (running)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) { // If we have a message to process, process it
			if (msg.message == WM_QUIT) {
				running = false; // Set running to false if we have a message to quit
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

	return	( 0 );
}
}
