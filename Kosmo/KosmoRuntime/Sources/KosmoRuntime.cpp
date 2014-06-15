//*****************************************************************************
//
//	File:		KosmoRuntime.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"KosmoRuntimeRoot.h"

#include	KOSMO_CORE_H(Math/Vector3f)
#include	KOSMO_CORE_H(Math/Vector4f)

int main()
{
	Vector3f v3f( 0.0f, 2.0f, 1.0f );
	Vector4f v4f( 3.0f, 2.0f, -1.0f, 0.0f );
	Vector4f v4f2( v3f );

	v4f = v3f;

	return	( 0 );
}