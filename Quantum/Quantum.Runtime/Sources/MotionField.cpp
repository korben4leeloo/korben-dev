//*****************************************************************************
//
//	File:		MotionField.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "Root.h"

#define _USE_MATH_DEFINES
#include <DirectXMath.h>
using namespace DirectX;

#include QUANTUM_CORE_H(Math/agl/ap)
#include QUANTUM_CORE_H(Math/agl/linalg)
using namespace alglib;

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
		qEigen[i] = XMVectorSet( (float)eigenVectors[i][0], (float)eigenVectors[i][1], (float)eigenVectors[i][2], (float)eigenVectors[i][3] );
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