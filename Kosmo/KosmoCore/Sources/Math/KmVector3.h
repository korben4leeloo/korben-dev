//*****************************************************************************
//
//	Class:		KmVector3
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __KosmoCore_KmVector3_h__
#define __KosmoCore_KmVector3_h__

#include	"Root.h"

KOSMO_CORE_NAMESPACE_BEGIN

class KmVector3
{
	friend class KmTransform4;
	friend class KmQuaternion;
	friend class KmVector4;

public:
							KmVector3();
							KmVector3( const float x, const float y, const float z );
							~KmVector3();

	inline static KmVector3	unitX();
	inline static KmVector3	unitY();
	inline static KmVector3	unitZ();

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
KmVector3	KmVector3::unitX()
{
	return	( KmVector3( 1.0f, 0.0f, 0.0f ) );
}

//-----------------------------------------------------------------------------
// Name:		unitY
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KmVector3	KmVector3::unitY()
{
	return	( KmVector3( 0.0f, 1.0f, 0.0f ) );
}

//-----------------------------------------------------------------------------
// Name:		unitZ
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KmVector3	KmVector3::unitZ()
{
	return	( KmVector3( 0.0f, 0.0f, 1.0f ) );
}

typedef KmVector3 KsVec3;

KOSMO_CORE_NAMESPACE_END

#endif