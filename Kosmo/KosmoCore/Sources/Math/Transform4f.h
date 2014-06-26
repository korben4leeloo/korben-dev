//*****************************************************************************
//
//	Class:		Transform4f
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __KosmoCore_Transform4f_h__
#define __KosmoCore_Transform4f_h__

#include	"Root.h"

#include	KOSMO_CORE_H(Math/Vector3f)
#include	KOSMO_CORE_H(Math/Quaternionf)

KOSMO_CORE_NS_BEGIN

class Transform4f
{
public:
						Transform4f();
						~Transform4f();

	inline void			setIdentity();

	inline void			setTranslation( const Vector3f& vTranslation );
	inline Vector3f		getTranslation() const;

	inline void			setRotation( const Quaternionf& qRotation );

	inline Quaternionf	getQuaternion() const;

	inline const float*	data() const;
	inline float*		data();

	inline Transform4f	operator*( const Transform4f& mOther );
	inline float		operator()( const uint32 uiRow, const uint32 uiCol ) const;

private:
	typedef Eigen::Transform<float, 3, Eigen::Affine> EigenTransform4f;

	EigenTransform4f	_m;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		setIdentity
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	Transform4f::setIdentity()
{
	_m.setIdentity();
}

//-----------------------------------------------------------------------------
// Name:		setTranslation
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline void	Transform4f::setTranslation( const Vector3f& vTranslation )
{
	_m.translation() = vTranslation._v;
}

//-----------------------------------------------------------------------------
// Name:		getTranslation
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline Vector3f	Transform4f::getTranslation() const
{
	Vector3f vTranslation;

	vTranslation._v = _m.translation();
	return	( vTranslation );
}

//-----------------------------------------------------------------------------
// Name:		setRotation
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline void	Transform4f::setRotation( const Quaternionf& qRotation )
{
	_m.linear() = qRotation._q.toRotationMatrix();
}

//-----------------------------------------------------------------------------
// Name:		getQuaternion
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline Quaternionf	Transform4f::getQuaternion() const
{
	Quaternionf qRotation;

	qRotation._q = _m.rotation();
	return	( qRotation );
}

//-----------------------------------------------------------------------------
// Name:		data
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const float*	Transform4f::data() const
{
	return	( _m.data() );
}

//-----------------------------------------------------------------------------
// Name:		data
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
float*	Transform4f::data()
{
	return	( _m.data() );
}

//-----------------------------------------------------------------------------
// Name:		operator*
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline Transform4f	Transform4f::operator*( const Transform4f& mOther )
{
	Transform4f mResult;

	mResult._m = _m * mOther._m;
	return	( mResult );
}

//-----------------------------------------------------------------------------
// Name:		operator()
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline float	Transform4f::operator()(const uint32	uiRow, 
										const uint32	uiCol) const
{
	return	( _m( uiRow, uiCol ) );
}

KOSMO_CORE_NS_END

#endif