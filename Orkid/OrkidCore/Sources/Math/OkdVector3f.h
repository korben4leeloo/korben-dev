//*****************************************************************************
//
//	Class:		OkdVector3f
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdVector3f_h__
#define __OrkidCore_OkdVector3f_h__

#include	"Root.h"

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

	inline static OkdVector3f	unitX();
	inline static OkdVector3f	unitY();
	inline static OkdVector3f	unitZ();

private:
	EigenVec3f					_v;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		unitX
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdVector3f	OkdVector3f::unitX()
{
	return	( OkdVector3f( 1.0f, 0.0f, 0.0f ) );
}

//-----------------------------------------------------------------------------
// Name:		unitY
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdVector3f	OkdVector3f::unitY()
{
	return	( OkdVector3f( 0.0f, 1.0f, 0.0f ) );
}

//-----------------------------------------------------------------------------
// Name:		unitZ
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdVector3f	OkdVector3f::unitZ()
{
	return	( OkdVector3f( 0.0f, 0.0f, 1.0f ) );
}

#endif