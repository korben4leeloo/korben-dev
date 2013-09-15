//*****************************************************************************
//
//	Class:		OkdMatrix4f
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdMatrix4f_h__
#define __OrkidCore_OkdMatrix4f_h__

#include	"Root.h"

#include	ORKID_MATH_H(OkdVector3f)
#include	ORKID_MATH_H(OkdQuaternionf)

class OkdMatrix4f
{
private:
							typedef Eigen::Transform<float, 3, Eigen::Affine> EigenTransform4f;

public:
							OkdMatrix4f();
							~OkdMatrix4f();

	inline void				setIdentity();

	inline void				setTranslation( const OkdVector3f& vTranslation );
	inline OkdVector3f		getTranslation() const;

	inline void				setRotation( const OkdQuaternionf& qRotation );

	inline OkdQuaternionf	getQuaternion() const;

	inline OkdMatrix4f		operator*( const OkdMatrix4f& mOther );

private:
	EigenTransform4f		_m;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		setIdentity
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdMatrix4f::setIdentity()
{
	_m.setIdentity();
}

//-----------------------------------------------------------------------------
// Name:		setTranslation
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline void	OkdMatrix4f::setTranslation( const OkdVector3f& vTranslation )
{
	_m.translation() = vTranslation._v;
}

//-----------------------------------------------------------------------------
// Name:		getTranslation
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline OkdVector3f	OkdMatrix4f::getTranslation() const
{
	OkdVector3f vTranslation;

	vTranslation._v = _m.translation();
	return	( vTranslation );
}

//-----------------------------------------------------------------------------
// Name:		setRotation
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline void	OkdMatrix4f::setRotation( const OkdQuaternionf& qRotation )
{
	_m.linear() = qRotation._q.toRotationMatrix();
}

//-----------------------------------------------------------------------------
// Name:		getQuaternion
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline OkdQuaternionf	OkdMatrix4f::getQuaternion() const
{
	OkdQuaternionf qRotation;

	qRotation._q = _m.rotation();
	return	( qRotation );
}

//-----------------------------------------------------------------------------
// Name:		operator*
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline OkdMatrix4f	OkdMatrix4f::operator*( const OkdMatrix4f& mOther )
{
	OkdMatrix4f mResult;

	mResult._m = _m * mOther._m;
	return	( mResult );
}

#endif