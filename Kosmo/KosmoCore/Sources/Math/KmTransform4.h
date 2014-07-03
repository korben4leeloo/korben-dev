//*****************************************************************************
//
//	Class:		KmTransform4
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __KosmoCore_KmTransform4_h__
#define __KosmoCore_KmTransform4_h__

#include	"Root.h"

#include	KOSMO_CORE_H(Math/KmVector3)
#include	KOSMO_CORE_H(Math/KmQuaternion)

KOSMO_CORE_NAMESPACE_BEGIN

class KmTransform4
{
public:
						KmTransform4();
						~KmTransform4();

	inline void			setIdentity();

	inline void			setTranslation( const KmVector3& vTranslation );
	inline KmVector3		getTranslation() const;

	inline void			setRotation( const KmQuaternion& qRotation );

	inline KmQuaternion	getQuaternion() const;

	inline const float*	data() const;
	inline float*		data();

	inline KmTransform4	operator*( const KmTransform4& mOther );
	inline float		operator()( const uint32 uiRow, const uint32 uiCol ) const;

private:
	typedef Eigen::Transform<float, 3, Eigen::Affine> EigenTransform4f;

	EigenTransform4f	_m;
};

//*****************************************************************************
//	Inline methods declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		setIdentity
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	KmTransform4::setIdentity()
{
	_m.setIdentity();
}

//-----------------------------------------------------------------------------
// Name:		setTranslation
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline void	KmTransform4::setTranslation( const KmVector3& vTranslation )
{
	_m.translation() = vTranslation._v;
}

//-----------------------------------------------------------------------------
// Name:		getTranslation
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline KmVector3	KmTransform4::getTranslation() const
{
	KmVector3 vTranslation;

	vTranslation._v = _m.translation();
	return	( vTranslation );
}

//-----------------------------------------------------------------------------
// Name:		setRotation
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline void	KmTransform4::setRotation( const KmQuaternion& qRotation )
{
	_m.linear() = qRotation._q.toRotationMatrix();
}

//-----------------------------------------------------------------------------
// Name:		getQuaternion
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline KmQuaternion	KmTransform4::getQuaternion() const
{
	KmQuaternion qRotation;

	qRotation._q = _m.rotation();
	return	( qRotation );
}

//-----------------------------------------------------------------------------
// Name:		data
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const float*	KmTransform4::data() const
{
	return	( _m.data() );
}

//-----------------------------------------------------------------------------
// Name:		data
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
float*	KmTransform4::data()
{
	return	( _m.data() );
}

//-----------------------------------------------------------------------------
// Name:		operator*
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline KmTransform4	KmTransform4::operator*( const KmTransform4& mOther )
{
	KmTransform4 mResult;

	mResult._m = _m * mOther._m;
	return	( mResult );
}

//-----------------------------------------------------------------------------
// Name:		operator()
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline float	KmTransform4::operator()(const uint32	uiRow, 
										const uint32	uiCol) const
{
	return	( _m( uiRow, uiCol ) );
}

KOSMO_CORE_NAMESPACE_END

#endif