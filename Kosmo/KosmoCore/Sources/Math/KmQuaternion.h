//*****************************************************************************
//
//	Class:		KsQuaternion
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __KosmoCore_KsQuaternion_h__
#define __KosmoCore_KsQuaternion_h__

#include	"Root.h"

KOSMO_CORE_NAMESPACE_BEGIN

class KsVector3;

class KsQuaternion
{
	friend class KsTransform4;

public:
						KsQuaternion();
						KsQuaternion( const KsVector3& vAxis, const float fAngle );

						~KsQuaternion();

	inline void			setIdentity();

	inline KsQuaternion	operator*( const KsQuaternion& qOther );

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
void	KsQuaternion::setIdentity()
{
	_q.setIdentity();
}

//-----------------------------------------------------------------------------
// Name:		operator*
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline KsQuaternion	KsQuaternion::operator*( const KsQuaternion& qOther )
{
	KsQuaternion qResult;

	qResult._q = _q * qOther._q;
	return	( qResult );
}

typedef KsQuaternion KsQuat;

KOSMO_CORE_NAMESPACE_END

#endif