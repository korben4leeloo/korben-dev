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

float testMeshPoints[24] = 
{
	-0.5, -0.5, 0.5,
	0.5, -0.5, 0.5,
	-0.5, 0.5, 0.5,
	0.5, 0.5, 0.5,
	-0.5, 0.5, -0.5,
	0.5, 0.5, -0.5,
	-0.5, -0.5, -0.5,
	0.5, -0.5, -0.5
};

uint32 testMeshPolygons[36] = 
{
	0, 1, 2,
	2, 1, 3,
	2, 3, 4,
	4, 3, 5,
	4, 5, 6,
	6, 5, 7,
	6, 7, 0,
	0, 7, 1,
	1, 7, 3,
	3, 7, 5,
	6, 0, 4,
	4, 0, 2
};

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
#include	ORKID_CORE_H(Input/OkdInputManager)
#include	ORKID_CORE_H(Input/Windows/OkdWindowsRawInputHandler)

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
	//ORKID_ASSERT( message != 0x0100 );
	switch (message) {
		case WM_SIZE: // If our window is resizing
		{
			//openglContext.reshapeWindow(LOWORD(lParam), HIWORD(lParam)); // Send the new window size to our OpenGLContext
			break;
		}

		case WM_KEYDOWN:
		{
			int n = 0;
			break;
		}

		case WM_KEYUP:
		{
			int n = 0;
			break;
		}

		case WM_CHAR:
		{
			int n = 0;
			break;
		}

		case WM_INPUT:
		{
			OkdInputManager::instance()->getWindowsRawInputHandler()->processInput( (HRAWINPUT)lParam );
			return	( 0 );
		}

		case WM_DESTROY:
		{
			PostQuitMessage(0);
			break;
		}

		default:
			break;
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
	//SetFocus( hWnd );

	return true;
}

//#include	ORKID_ENGINE_H(Entities/OkdMesh)

#include	ORKID_ENGINE_H(OrkidEngine)
//#include	ORKID_ENGINE_H(Resources/OkdResourceManager)
//#include	ORKID_ENGINE_H(Resources/OkdResourceDatabase)
//#include	ORKID_CORE_H(Xml/OkdXmlDocument)
#include	ORKID_ENGINE_H(Entities/OkdEntity)
#include	ORKID_ENGINE_H(Entities/OkdMesh)
#include	ORKID_ENGINE_H(Entities/OkdShape)
#include	ORKID_ENGINE_H(Entities/OkdLight)
#include	ORKID_ENGINE_H(SceneGraph/OkdScene)
#include	ORKID_ENGINE_H(SceneGraph/OkdNode)
#include	ORKID_ENGINE_H(Resources/OkdResourcePtr)
#include	ORKID_ENGINE_H(Shaders/OkdAbstractShader)
#include	ORKID_ENGINE_H(Components/OkdTransformComponent)
#include	ORKID_ENGINE_H(Components/OkdMeshComponent)
#include	ORKID_CORE_H(Containers/OkdList)
#include	ORKID_CORE_H(Components/OkdComponentFactory)
//#include	<rapidxml/rapidxml_print.hpp>
#include	<iostream>

void	testSaveScene()
{
	/*OkdScenePtr scenePtr;
	scenePtr.bind( "TestScene" );

	OkdScene*	pScene	= scenePtr.getResource();
	OkdNode*	pNode1	= pScene->createNode();
	OkdNode*	pNode2	= pScene->createNode();
	OkdNode*	pNode3	= pScene->createNode( pNode1 );
	OkdLight*	pLight	= pScene->createLight();
	OkdShape*	pShape1	= pScene->createShape( pNode2 );
	OkdShape*	pShape2	= pScene->createShape( pNode3 );
	OkdCamera*	pCamera	= pScene->createCamera( pNode2 );
	OkdMeshPtr	meshPtr;

	meshPtr.bind( "TestMesh" );

	pShape1->setMeshPtr( meshPtr );
	pShape2->setMeshPtr( meshPtr );

	scenePtr.save();*/
}

void	testLoadScene()
{
	OkdScenePtr scenePtr;
	scenePtr.bind( "TestScene" );
	scenePtr.load();
}

void	testSaveMesh()
{
	OkdMeshPtr meshPtr;
	meshPtr.bind( "TestMesh" );

	OkdMesh*	pMesh = meshPtr.getResource();
	uint32		uiVertexCount	= sizeof(testMeshPoints) / ( 3 * sizeof(float) );
	uint32		uiPolygonCount	= sizeof(testMeshPolygons) / ( 3 * sizeof(float) );
	OkdMeshInfo	meshInfo( uiVertexCount, uiPolygonCount );

	pMesh->create( meshInfo );
	pMesh->setVertexArray( testMeshPoints );

	for	( uint32 i = 0; i < uiPolygonCount; i++ )
	{
		pMesh->setPolygon( i, &testMeshPolygons[3*i] );
	}

	meshPtr.save();
}

void	testLoadMesh()
{
	OkdMeshPtr meshPtr;
	meshPtr.bind( "TestMesh" );

	meshPtr.load();

	OkdMesh* pMesh = meshPtr.getResource();
}

class OkdSlotTester
{
public:
	OkdSlotTester(): _onComponentCreatedSlot( this, &OkdSlotTester::onComponentCreated ) {}

	void onComponentCreated( OkdComponentId id )
	{
		int n = 4;
	}

	OkdSlot<OkdSlotTester, OkdComponentId> _onComponentCreatedSlot;
};

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

	OrkidEngine*		pEngine				= OrkidEngine::create();
	//OkdResourceManager*	pResourceManager	= pEngine->getResourceManager();

	{
		OkdMeshPtr meshPtr, meshPtr2;

		meshPtr.bind( "test");
		meshPtr2.bind( "test2" );

		//OkdMeshPtr meshPtr3( meshPtr );
		OkdMeshPtr meshPtr3;

		meshPtr3.bind( "test2" );
		meshPtr = meshPtr2;

		meshPtr2.unbind();
		//meshPtr2.release();

		OkdMeshPtr meshPtr4 = meshPtr;
		meshPtr4.bind( "test2" );
		
		meshPtr4.save();
		meshPtr4.load();

		//OkdMeshPtr meshResPtr = OkdMeshResourceHandler::addMesh( "test" );

		/*OkdString str( "C:\\Users\\jja\\Downloads" );
		const OkdVector<OkdString>& tokens = str.split( "\\" );*/

		/*OkdMesh* pMesh = meshPtr.getResource();
		OkdMeshInfo	meshInfo( 8, 12 );
		pMesh->create( meshInfo );*/
	}

	OkdEntity* pEntity = new OkdEntity();

	OkdComponentFactory*	pComponentFactory = pEngine->getComponentFactory();

	OkdSlotTester* pSlotTester = new OkdSlotTester();
	OKD_SIGNAL_CONNECT( pComponentFactory, _onCreateComponentSignal, pSlotTester, _onComponentCreatedSlot );

	pEntity->addComponent( OkdTransformComponent::getComponentId() );
	pEntity->addComponent( OkdMeshComponent::getComponentId() );
	pEntity->removeComponent( OkdMeshComponent::getComponentId() );

	OkdComponentPtr ptr1( pComponentFactory->createComponent( OkdTransformComponent::getComponentId() ) );
	OkdComponentPtr ptr2( pComponentFactory->createComponent( OkdMeshComponent::getComponentId() ) );
	OkdComponentPtr ptr3;

	ptr3 = ptr1;
	ptr1 = ptr2;
	ptr3 = ptr1;

	//testSaveMesh();
	//testLoadMesh();

	/*testSaveScene();
	testLoadScene();*/

	/*OkdScenePtr scenePtr;

	scenePtr.bind( "TestDAG.okd" );
	scenePtr.load();
	scenePtr.unbind();*/

	//return (0);

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

	{
		OkdVertexShaderPtr vertexShaderPtr;//( "test", OrkidVertexShader );
		//vertexShaderPtr.bind( "test" );;
	}

	//openglContext.setupScene(); // Setup our OpenGL scene

	/**
		This is our main loop, it continues for as long as running is true
	*/
	while (running)
	{
		//if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) { // If we have a message to process, process it
		//	if (msg.message == WM_QUIT) {
		//		running = false; // Set running to false if we have a message to quit
		//	}
		//	else {
		//		TranslateMessage(&msg);
		//		DispatchMessage(&msg);
		//	}
		//}
		//else { // If we don't have a message to process
		//	//openglContext.renderScene(); // Render our scene (which also handles swapping of buffers)
		//	openGLContext.render();
		//}

		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) { // If we have a message to process, process it
			if (msg.message == WM_QUIT) {
				running = false; // Set running to false if we have a message to quit
			}
			else {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}

		OrkidEngine::instance()->update();
		
		{ // If we don't have a message to process
			//openglContext.renderScene(); // Render our scene (which also handles swapping of buffers)
			//openGLContext.render();
		}
	}

	OrkidEngine::destroy();

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
	//openGLContext.create( hWnd );

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
			//openGLContext.render();
		}
	}

	return	( 0 );
}
}
