//*****************************************************************************
//
//	Class:		OkdQuaternionf
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdQuaternionf_h__
#define __OrkidCore_OkdQuaternionf_h__

#include	<Math/OkdMathCommon.h>

class OkdVector3f;

class OkdQuaternionf
{
						friend class OkdMatrix4f;

private:
						typedef Eigen::Quaternionf	EigenQuatf;
						typedef Eigen::AngleAxisf	EigenAngleAxisf;

public:
						OkdQuaternionf();
						OkdQuaternionf( const OkdVector3f& vAxis, const float fAngle );

						~OkdQuaternionf();

	//inline void			setIdentity();

	//inline OkdQuaternionf	operator*( const OkdQuaternionf& mOther );

private:
	EigenQuatf	_q;
};

//*****************************************************************************
//
//	Inline functions declarations
//
//*****************************************************************************

////-----------------------------------------------------------------------------
//// Name:		setIdentity
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//void	OkdQuaternionf::setIdentity()
//{
//	_m.setIdentity();
//}

////-----------------------------------------------------------------------------
//// Name:		operator*
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//inline OkdQuaternionf	OkdQuaternionf::operator*( const OkdQuaternionf& mOther )
//{
//	OkdQuaternionf mResult;
//
//	mResult._m = _m * mOther._m;
//	return	( mResult );
//}

#endif