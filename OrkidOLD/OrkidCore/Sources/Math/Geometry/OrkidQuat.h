//*****************************************************************************
//
//	Class:		OrkidQuatf
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OrkidQuatf_h__
#define __OrkidCore_OrkidQuatf_h__

#include	<Math/OrkidMathCommon.h>

class OrkidQuatf
{
private:
						typedef Eigen::Quaternionf EigenQuatf;

public:
						OrkidQuatf();
						OrkidQuatf( const OrkidVec3f& vAxis, const float fAngle );

						~OrkidQuatf();

	//inline void			setIdentity();

	//inline OrkidQuatf	operator*( const OrkidQuatf& mOther );

private:
	EigenQuatf	_q;
};

//*****************************************************************************
//
//	Inline functions declarations
//
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		setIdentity
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OrkidQuatf::setIdentity()
{
	_m.setIdentity();
}

////-----------------------------------------------------------------------------
//// Name:		operator*
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//inline OrkidQuatf	OrkidQuatf::operator*( const OrkidQuatf& mOther )
//{
//	OrkidQuatf mResult;
//
//	mResult._m = _m * mOther._m;
//	return	( mResult );
//}

#endif