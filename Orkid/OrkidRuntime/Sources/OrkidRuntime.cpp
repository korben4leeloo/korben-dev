//*****************************************************************************
//
//	File:		OrkidRuntime.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

//#include	<3dEngine/SceneManager/OrkidScene.h>

#include	<Math/Geometry/OrkidMat4f.h>
#include	<Math/Geometry/OrkidVec3f.h>
#include	<Math/Geometry/OrkidQuatf.h>

int main()
{
	//OrkidScene scene;

	okdMat4f	m1, m2, m3;
	okdVec3f	v1, v2, v3;
	okdQuatf	q1, q2, q3;

	v1 = OrkidVec3f( 3.0f, 5.0f, 1.0f );
	v2 = OrkidVec3f( -7.0f, 6.0f, 4.0f );

	m1.setIdentity();
	m2.setIdentity();

	m1.setTranslation( v1 );
	m2.setTranslation( v2 );

	q1 = OrkidQuatf(  OrkidVec3f::UnitY(), 0.785398163397448309616f );
	q2 = OrkidQuatf(  OrkidVec3f::UnitX(), 0.785398163397448309616f );

	m1.setRotation( q1 );
	m2.setRotation( q2 );

	m3 = m2 * m1;

	v3 = m3.getTranslation();
	q3 = m3.getQuaternion();

	return	( 0 );
}