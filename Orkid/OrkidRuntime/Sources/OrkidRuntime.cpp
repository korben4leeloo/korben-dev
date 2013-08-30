//*****************************************************************************
//
//	File:		OrkidRuntime.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

//#include	<3dEngine/SceneManager/OrkidScene.h>
#include	<Math/OrkidMathCommon.h>

int main()
{
	//OrkidScene scene;

	OrkidMat4f m;
	OrkidVec3f v;

	v.setRandom();

	m.setIdentity();
	m.setTranslation( v );

	return	( 0 );
}