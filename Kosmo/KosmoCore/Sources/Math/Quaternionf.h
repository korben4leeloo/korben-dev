//*****************************************************************************
//
//	Class:		Quaternionf
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __KosmoCore_Quaternionf_h__
#define __KosmoCore_Quaternionf_h__

#include	"Root.h"

namespace Kosmo {

class Vector3f;

class Quaternionf
{
	friend class Transform4f;

public:
						Quaternionf();
						Quaternionf( const Vector3f& vAxis, const float fAngle );

						~Quaternionf();

	inline void			setIdentity();

	inline Quaternionf	operator*( const Quaternionf& qOther );

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
void	Quaternionf::setIdentity()
{
	_q.setIdentity();
}

//-----------------------------------------------------------------------------
// Name:		operator*
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline Quaternionf	Quaternionf::operator*( const Quaternionf& qOther )
{
	Quaternionf qResult;

	qResult._q = _q * qOther._q;
	return	( qResult );
}

} // namespace Kosmo

#endif