//*****************************************************************************
//
//	Class:		Vector3f
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __KosmoCore_Vector3f_h__
#define __KosmoCore_Vector3f_h__

#include	"Root.h"

KOSMO_CORE_NS_BEGIN

class Vector3f
{
	friend class Transform4f;
	friend class Quaternionf;
	friend class Vector4f;

public:
							Vector3f();
							Vector3f( const float x, const float y, const float z );
							~Vector3f();

	inline static Vector3f	unitX();
	inline static Vector3f	unitY();
	inline static Vector3f	unitZ();

private:
	Eigen::Vector3f			_v;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		unitX
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
Vector3f	Vector3f::unitX()
{
	return	( Vector3f( 1.0f, 0.0f, 0.0f ) );
}

//-----------------------------------------------------------------------------
// Name:		unitY
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
Vector3f	Vector3f::unitY()
{
	return	( Vector3f( 0.0f, 1.0f, 0.0f ) );
}

//-----------------------------------------------------------------------------
// Name:		unitZ
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
Vector3f	Vector3f::unitZ()
{
	return	( Vector3f( 0.0f, 0.0f, 1.0f ) );
}

KOSMO_CORE_NS_END

#endif