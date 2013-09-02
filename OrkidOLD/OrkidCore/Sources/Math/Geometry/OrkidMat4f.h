//*****************************************************************************
//
//	Class:		OrkidMat4f
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OrkidMat4f_h__
#define __OrkidCore_OrkidMat4f_h__

#include	<Math/OrkidMathCommon.h>
#include	<Math/Geometry/OrkidVec3f.h>
#include	<Math/Geometry/OrkidQuatf.h>

class OrkidMat4f
{
private:
						typedef Eigen::Transform<float, 3, Eigen::Affine> EigenTransform4f;

public:
						OrkidMat4f();
						~OrkidMat4f();

	inline void			setIdentity();

	inline void			setTranslation( const OrkidVec3f& vTranslation );
	inline OrkidVec3f	getTranslation() const;

	inline void			setRotation( const OrkidQuatf& qRotation );

	inline OrkidQuatf	getQuaternion() const;

	inline OrkidMat4f	operator*( const OrkidMat4f& mOther );

private:
	EigenTransform4f	_m;
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
void	OrkidMat4f::setIdentity()
{
	_m.setIdentity();
}

//-----------------------------------------------------------------------------
// Name:		setTranslation
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline void	OrkidMat4f::setTranslation( const OrkidVec3f& vTranslation )
{
	_m.translation() = vTranslation._v;
}

//-----------------------------------------------------------------------------
// Name:		getTranslation
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline OrkidVec3f	OrkidMat4f::getTranslation() const
{
	OrkidVec3f vTranslation;

	vTranslation._v = _m.translation();
	return	( vTranslation );
}

//-----------------------------------------------------------------------------
// Name:		setRotation
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline void	OrkidMat4f::setRotation( const OrkidQuatf& qRotation )
{
	_m.linear() = qRotation._q.toRotationMatrix();
}

//-----------------------------------------------------------------------------
// Name:		getQuaternion
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline OrkidQuatf	OrkidMat4f::getQuaternion() const
{
	OrkidQuatf qRotation;

	qRotation._q = _m.rotation();
	return	( qRotation );
}

//-----------------------------------------------------------------------------
// Name:		operator*
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline OrkidMat4f	OrkidMat4f::operator*( const OrkidMat4f& mOther )
{
	OrkidMat4f mResult;

	mResult._m = _m * mOther._m;
	return	( mResult );
}

#endif