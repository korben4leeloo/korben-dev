//*****************************************************************************
//
//	Class:		KsVector3
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __KosmoCore_KsVector3_h__
#define __KosmoCore_KsVector3_h__

#include	"Root.h"

KOSMO_CORE_NS_BEGIN

class KsVector3
{
	friend class KsTransform4;
	friend class KsQuaternion;
	friend class KsVector4;

public:
							KsVector3();
							KsVector3( const float x, const float y, const float z );
							~KsVector3();

	inline static KsVector3	unitX();
	inline static KsVector3	unitY();
	inline static KsVector3	unitZ();

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
KsVector3	KsVector3::unitX()
{
	return	( KsVector3( 1.0f, 0.0f, 0.0f ) );
}

//-----------------------------------------------------------------------------
// Name:		unitY
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KsVector3	KsVector3::unitY()
{
	return	( KsVector3( 0.0f, 1.0f, 0.0f ) );
}

//-----------------------------------------------------------------------------
// Name:		unitZ
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KsVector3	KsVector3::unitZ()
{
	return	( KsVector3( 0.0f, 0.0f, 1.0f ) );
}

typedef KsVector3 KsVec3;

KOSMO_CORE_NS_END

#endif