//*****************************************************************************
//
//	Class:		OrkidVec3f
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OrkidVec3f_h__
#define __OrkidCore_OrkidVec3f_h__

#include	<Math/OrkidMathCommon.h>

class OrkidVec3f
{
								friend class OrkidMat4f;
								friend class OrkidQuatf;

private:
								typedef Eigen::Vector3f EigenVec3f;

public:
								OrkidVec3f();
								OrkidVec3f( const float x, const float y, const float z );

								~OrkidVec3f();

	inline static OrkidVec3f	UnitX();
	inline static OrkidVec3f	UnitY();
	inline static OrkidVec3f	UnitZ();

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
OrkidVec3f	OrkidVec3f::UnitX()
{
	return	( OrkidVec3f( 1.0f, 0.0f, 0.0f ) );
}

//-----------------------------------------------------------------------------
// Name:		UnitY
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OrkidVec3f	OrkidVec3f::UnitY()
{
	return	( OrkidVec3f( 0.0f, 1.0f, 0.0f ) );
}

//-----------------------------------------------------------------------------
// Name:		UnitZ
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OrkidVec3f	OrkidVec3f::UnitZ()
{
	return	( OrkidVec3f( 0.0f, 0.0f, 1.0f ) );
}

#endif