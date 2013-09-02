//*****************************************************************************
//
//	File:		OkdRuntime.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

//#include	<3dEngine/SceneManager/OkdScene.h>

#include	<Math/Geometry/OkdMatrix4f.h>
#include	<Math/Geometry/OkdVector3f.h>
#include	<Math/Geometry/OkdQuaternionf.h>

int main()
{
	//OkdScene scene;

	OkdMatrix4f		m1, m2, m3;
	OkdVector3f		v1, v2, v3;
	OkdQuaternionf	q1, q2, q3;

	v1 = OkdVector3f( 3.0f, 5.0f, 1.0f );
	v2 = OkdVector3f( -7.0f, 6.0f, 4.0f );

	m1.setIdentity();
	m2.setIdentity();

	m1.setTranslation( v1 );
	m2.setTranslation( v2 );

	q1 = OkdQuaternionf( OkdVector3f::UnitY(), 0.785398163397448309616f );
	q2 = OkdQuaternionf( OkdVector3f::UnitX(), 0.785398163397448309616f );

	m1.setRotation( q1 );
	m2.setRotation( q2 );

	m3 = m2 * m1;

	v3 = m3.getTranslation();
	q3 = m3.getQuaternion();

	return	( 0 );
}