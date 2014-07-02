//*****************************************************************************
//
//	Class:		KmQuaternion
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __KosmoCore_KmQuaternion_h__
#define __KosmoCore_KmQuaternion_h__

#include	"Root.h"

KOSMO_CORE_NAMESPACE_BEGIN

class KmVector3;

class KmQuaternion
{
	friend class KmTransform4;

public:
						KmQuaternion();
						KmQuaternion( const KmVector3& vAxis, const float fAngle );

						~KmQuaternion();

	inline void			setIdentity();

	inline KmQuaternion	operator*( const KmQuaternion& qOther );

private:
	Eigen::Quaternionf	_q;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		setIdentity
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	KmQuaternion::setIdentity()
{
	_q.setIdentity();
}

//-----------------------------------------------------------------------------
// Name:		operator*
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline KmQuaternion	KmQuaternion::operator*( const KmQuaternion& qOther )
{
	KmQuaternion qResult;

	qResult._q = _q * qOther._q;
	return	( qResult );
}

typedef KmQuaternion KsQuat;

KOSMO_CORE_NAMESPACE_END

#endif