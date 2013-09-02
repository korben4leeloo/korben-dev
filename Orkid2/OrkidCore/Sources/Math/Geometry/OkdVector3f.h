//*****************************************************************************
//
//	Class:		OkdVector3f
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdVector3f_h__
#define __OrkidCore_OkdVector3f_h__

#include	<Math/OkdMathCommon.h>

class OkdVector3f
{
								friend class OkdMatrix4f;
								friend class OkdQuaternionf;

private:
								typedef Eigen::Vector3f EigenVec3f;

public:
								OkdVector3f();
								OkdVector3f( const float x, const float y, const float z );

								~OkdVector3f();

	inline static OkdVector3f	UnitX();
	inline static OkdVector3f	UnitY();
	inline static OkdVector3f	UnitZ();

private:
	EigenVec3f					_v;
};

//*****************************************************************************
//
//	Inline functions declarations
//
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		UnitX
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdVector3f	OkdVector3f::UnitX()
{
	return	( OkdVector3f( 1.0f, 0.0f, 0.0f ) );
}

//-----------------------------------------------------------------------------
// Name:		UnitY
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdVector3f	OkdVector3f::UnitY()
{
	return	( OkdVector3f( 0.0f, 1.0f, 0.0f ) );
}

//-----------------------------------------------------------------------------
// Name:		UnitZ
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdVector3f	OkdVector3f::UnitZ()
{
	return	( OkdVector3f( 0.0f, 0.0f, 1.0f ) );
}

#endif