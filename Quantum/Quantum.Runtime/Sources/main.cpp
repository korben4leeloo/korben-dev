//*****************************************************************************
//
//	File:		main.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "Root.h"

#include <Windows.h>

#define _USE_MATH_DEFINES
#include <DirectXMath.h>
using namespace DirectX;

#include QUANTUM_CORE_H(Application/QmApplication)
#include QUANTUM_CORE_H(Rendering/Window/QmWindow)
#include QUANTUM_CORE_H(Rendering/D3D/QmD3DContext)
#include QUANTUM_CORE_H(File/QmTextFile)
#include QUANTUM_CORE_H(Containers/QmTree)

#include QUANTUM_CORE_H(Math/agl/ap)
#include QUANTUM_CORE_H(Math/agl/linalg)
using namespace alglib;

//#include QUANTUM_CORE_H(Rendering/OpenGL/QmOpenGLContext)
//#include QUANTUM_CORE_H(Rendering/OpenGL/QmOpenGLApi)

//#include <d3d11.h>
//
//IDXGISwapChain* SwapChain;
//ID3D11Device* d3d11Device;
//ID3D11DeviceContext* d3d11DevCon;
//ID3D11RenderTargetView* renderTargetView;
//
//float red = 0.0f;
//float green = 0.0f;
//float blue = 0.0f;
//int colormodr = 1;
//int colormodg = 1;
//int colormodb = 1;

//void RenderScene()
//{
//	//Update the colors of our scene
//    red += colormodr * 0.00005f;
//    green += colormodg * 0.00002f;
//    blue += colormodb * 0.00001f;
//
//    if(red >= 1.0f || red <= 0.0f)
//        colormodr *= -1;
//    if(green >= 1.0f || green <= 0.0f)
//        colormodg *= -1;
//    if(blue >= 1.0f || blue <= 0.0f)
//        colormodb *= -1;
//
//    //Clear our backbuffer to the updated color
//	const float bgColor[4] = { red, green, blue, 1.0f };
//
//    d3d11DevCon->ClearRenderTargetView(renderTargetView, bgColor);
//
//    //Present the backbuffer to the screen
//    SwapChain->Present(0, 0);
//}

float randFloat( float min, float max )
{
	float fAngle = min + ( (float)rand() / (float)RAND_MAX ) * ( max - min );
	return fAngle;
}

float Deg2Rad( float angle )
{
	return ( angle / 180.0f * (float)M_PI );
}

float Rad2Deg( float angle )
{
	return ( angle / (float)M_PI * 180.0f );
}

XMMATRIX QuatToMat( const XMVECTOR q )
{
	XMMATRIX m;

	float a = XMVectorGetX( q );
	float b = XMVectorGetY( q );
	float c = XMVectorGetZ( q );
	float d = XMVectorGetW( q );

	m.r[0] = XMVectorSet( a, -b, -c, -d );
	m.r[1] = XMVectorSet( b, a, -d, c );
	m.r[2] = XMVectorSet( c, d, a, -b );
	m.r[3] = XMVectorSet( d, -c, b, a );

	return m;
}

XMMATRIX QuatMulTranspose( const XMVECTOR& q )
{
	XMMATRIX m, mq, mqt;

	mq = XMMatrixSet( 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f );

	mq.r[0] = q;
	mqt = XMMatrixTranspose( mq );
	m = mqt * mq;

	return m;
}

void TestQuaternion()
{
	XMVECTOR vx = XMVectorSet( 1.0f, 0.0f, 0.0f, 0.0f );
	XMVECTOR vy = XMVectorSet( 0.0f, 1.0f, 0.0f, 0.0f );
	XMVECTOR vz = XMVectorSet( 0.0f, 0.0f, 1.0f, 0.0f );

	srand( 0 );

	static float fAngleMin = -45.0f;
	static float fAngleMax = 45.0f;
	static int uiQuatCount = 10;

	XMVECTOR* q = new XMVECTOR[uiQuatCount];
	float* w = new float[uiQuatCount];
	float wsum = 0.0f;

	for	( int i = 0; i < uiQuatCount; i++ )
	{
		float ax = randFloat( Deg2Rad( fAngleMin ), Deg2Rad( fAngleMax ) );
		float ay = randFloat( Deg2Rad( fAngleMin ), Deg2Rad( fAngleMax ) );
		float az = randFloat( Deg2Rad( fAngleMin ), Deg2Rad( fAngleMax ) );

		//w[i] = randFloat( 0.0f, 1.0f );
		w[i] = 1.0f / ( ( i + 1 ) * ( i + 1 ) );
		wsum += w[i];

		XMVECTOR qx = XMQuaternionRotationAxis( vx, ax );
		XMVECTOR qy = XMQuaternionRotationAxis( vy, ay );
		XMVECTOR qz = XMQuaternionRotationAxis( vz, az );

		q[i] = XMQuaternionRotationRollPitchYaw( ax, ay, az );

		/*XMVECTOR qln = XMQuaternionLn( q[i] );
		XMVECTOR qexp = XMQuaternionExp( qln );*/

		XMFLOAT4 qf;
		XMStoreFloat4( &qf, q[i] );

		QUANTUM_MESSAGE( "%f %f %f %f", qf.x, qf.y, qf.z, qf.w );
	}

	QUANTUM_MESSAGE( "\n" );

	for	( int i = 0; i < uiQuatCount; i++ )
	{
		w[i] /= wsum;
	}

	// Linear
	XMFLOAT4 qfBlend = { 0.0f, 0.0f, 0.0f, 0.0f };

	for	( int i = 0; i < uiQuatCount; i++ )
	{
		XMFLOAT4 qf;
		XMStoreFloat4( &qf, q[i] );

		qfBlend.x += w[i] * qf.x;
		qfBlend.y += w[i] * qf.y;
		qfBlend.z += w[i] * qf.z;
		qfBlend.w += w[i] * qf.w;
	}

	QUANTUM_MESSAGE( "qfBlend: %f %f %f %f", qfBlend.x, qfBlend.y, qfBlend.z, qfBlend.w );
	XMVECTOR norm = XMQuaternionLength( XMLoadFloat4( &qfBlend ) );
	XMVECTOR qBlendNorm = XMQuaternionNormalize( XMLoadFloat4( &qfBlend ) );
	XMFLOAT4 qfBlendNorm;
	XMStoreFloat4( &qfBlendNorm, qBlendNorm );
	QUANTUM_MESSAGE( "qBlendNorm: %f %f %f %f", qfBlendNorm.x, qfBlendNorm.y, qfBlendNorm.z, qfBlendNorm.w );

	// Exponential map
	XMMATRIX m = XMMatrixSet( 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f );

	for	( int i = 0; i < uiQuatCount; i++ )
	{
		XMMATRIX mq = QuatMulTranspose( q[i] );
		m += mq;
		int p = 0;
	}

	real_2d_array msym;
	msym.setlength( 4, 4 );
	//msym.setcontent( 4, 4, (const double*)m.r );

	for	( int i = 0; i < 4; i++ )
	{
		XMVECTOR row = m.r[i];

		for	( int j = 0; j < 4; j++ )
		{
			msym[i][j] = row.m128_f32[j];
		}
	}

	/*for	( int i = 0; i < 4; i++ )
	{
		QUANTUM_MESSAGE( "%.15f %.15f %.15f %.15f", msym[i][0], msym[i][1], msym[i][2], msym[i][3] );
	}*/

	real_1d_array eigenValues;
	real_2d_array eigenVectors;

	eigenValues.setlength( 4 );
	eigenVectors.setlength( 4, 4 );
	bool bResult = smatrixevd( msym, 4, 1, 1, eigenValues, eigenVectors );

	QUANTUM_MESSAGE( "eigenValues: %.15f %.15f %.15f %.15f", eigenValues[0], eigenValues[1], eigenValues[2], eigenValues[3] );

	XMVECTOR qEigen[4];

	for	( int i = 0; i < 4; i++ )
	{
		qEigen[i] = XMVectorSet( eigenVectors[i][0], eigenVectors[i][1], eigenVectors[i][2], eigenVectors[i][3] );
		QUANTUM_MESSAGE( "eigenVector %d: %.15f %.15f %.15f %.15f ( norm: %f )", 
			i, eigenVectors[i][0], eigenVectors[i][1], eigenVectors[i][2], eigenVectors[i][3], XMQuaternionLength( qEigen[i] ).m128_f32[0] );
	}

	// Find best reference quaternion
	float minSum = -1.0f;
	int nRefQuatIndex = 0;

	for	( int i = 0; i < 4; i++ )
	{
		float sum = 0.0f;

		for	( int j = 0; j < uiQuatCount; j++ )
		{
			float qdot = XMQuaternionDot( q[j], qEigen[i] ).m128_f32[0];
			sum += ( 1.0f - qdot * qdot );
		}

		minSum = ( i == 0 ) ? sum 
							: ( sum < minSum ) ? sum : minSum;
		nRefQuatIndex = ( sum == minSum ) ? i : nRefQuatIndex;
	}

	// Compute quaternions logs
	XMVECTOR qRefInv = XMQuaternionInverse( qEigen[nRefQuatIndex] );
	XMVECTOR qLogBlend = XMVectorSet( 0.0f, 0.0f, 0.0f, 0.0f );

	for	( int i = 0; i < uiQuatCount; i++ )
	{
		XMVECTOR qDelta = XMQuaternionMultiply( qRefInv, q[i] );
		XMVECTOR qlog = XMQuaternionLn( qDelta );
		float qlogNorm = XMQuaternionLength( qlog ).m128_f32[0];
		qLogBlend += w[i] * qlog;
	}

	XMVECTOR qexp = XMQuaternionExp( qLogBlend );
	XMVECTOR qexpBlend = XMQuaternionMultiply( qEigen[nRefQuatIndex], qexp );
	float qexpBlendNorm = XMQuaternionLength( qexpBlend ).m128_f32[0];

	float qdotDiff = XMQuaternionDot( qexpBlend, qBlendNorm ).m128_f32[0];

	float diff = XMScalarACos( qdotDiff );
	diff = Rad2Deg( diff );

	int n = 0;
}

//-----------------------------------------------------------------------------
// Name:		WinMain
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
int WinMain( __in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in_opt LPSTR lpCmdLine, __in int nShowCmd )
{
	TestQuaternion();

	// Create the application instance and init it
	QmApplication* pApplication = new QmApplication( hInstance );
	pApplication->init();
	
	// Create a window with an OpenGL context
	QmWindow*			pWindow			= pApplication->createWindow();
	//QmOpenGLContext*	pOpenGLContext	= pWindow->createOpenGLContext();
	QmD3DContext*		pD3DContext		= pApplication->createD3DContext( pWindow );

	typedef QmTree<int>::QmTreeNode QmIntNode;
	QmTree<int> test;
	QmIntNode* r = test.getRoot();
	QmIntNode* n = test.createNode();

	/*QmStdList<int> l;

	l.pushBack( 1 );
	l.pushBack( 2 );
	l.pushBack( 3 );
	l.pushBack( 4 );

	l.remove( 3 );
	l.remove( 4 );
	l.remove( 1 );
	l.remove( 2 );*/

	/*QmList<int> l;

	l.pushBack( 1 );
	l.pushBack( 2 );
	l.pushBack( 3 );
	l.pushBack( 4 );

	l.remove( 3 );
	l.remove( 4 );
	l.remove( 1 );
	l.remove( 2 );*/

	//QmListEx<int> li;

	//QmHierarchicalGraph<int>::NODE* root = test.

	//d3dContext.cr

	/*IDXGISwapChain* SwapChain;
	ID3D11Device* d3d11Device;
	ID3D11DeviceContext* d3d11DevCon;
	ID3D11RenderTargetView* renderTargetView;

	float red = 0.0f;
	float green = 0.0f;
	float blue = 0.0f;
	int colormodr = 1;
	int colormodg = 1;
	int colormodb = 1;*/

	{
		////Describe our Buffer
		//DXGI_MODE_DESC bufferDesc;

		//ZeroMemory(&bufferDesc, sizeof(DXGI_MODE_DESC));

		//RECT wndRect;
		//GetWindowRect( pWindow->getWindowHandle(), &wndRect );

		//bufferDesc.Width = wndRect.right - wndRect.left;
		//bufferDesc.Height = wndRect.bottom - wndRect.top;
		//bufferDesc.RefreshRate.Numerator = 60;
		//bufferDesc.RefreshRate.Denominator = 1;
		//bufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		//bufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		//bufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
  //  
		////Describe our SwapChain
		//DXGI_SWAP_CHAIN_DESC swapChainDesc; 
  //      
		//ZeroMemory(&swapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));

		//swapChainDesc.BufferDesc = bufferDesc;
		//swapChainDesc.SampleDesc.Count = 1;
		//swapChainDesc.SampleDesc.Quality = 0;
		//swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		//swapChainDesc.BufferCount = 1;
		//swapChainDesc.OutputWindow = pWindow->getWindowHandle(); 
		//swapChainDesc.Windowed = TRUE; 
		//swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;


		////Create our SwapChain
		//D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, NULL, NULL, NULL,
		//	D3D11_SDK_VERSION, &swapChainDesc, &SwapChain, &d3d11Device, NULL, &d3d11DevCon);

		////Create our BackBuffer
		//ID3D11Texture2D* BackBuffer;
		//SwapChain->GetBuffer( 0, __uuidof( ID3D11Texture2D ), (void**)&BackBuffer );

		////Create our Render Target
		//d3d11Device->CreateRenderTargetView( BackBuffer, NULL, &renderTargetView );
		//BackBuffer->Release();

		////Set our Render Target
		//d3d11DevCon->OMSetRenderTargets( 1, &renderTargetView, NULL );

		//pApplication->getTaskScheduler()->createTask( 0, RenderScene );
	}

	// Run the application loop
	pApplication->run();

	delete pApplication;

	return 0;
}
