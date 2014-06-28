//*****************************************************************************
//
//	Class:		KsTransform4
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __KosmoCore_KsTransform4_h__
#define __KosmoCore_KsTransform4_h__

#include	"Root.h"

#include	KOSMO_CORE_H(Math/KsVector3)
#include	KOSMO_CORE_H(Math/KsQuaternion)

KOSMO_CORE_NS_BEGIN

class KsTransform4
{
public:
						KsTransform4();
						~KsTransform4();

	inline void			setIdentity();

	inline void			setTranslation( const KsVector3& vTranslation );
	inline KsVector3		getTranslation() const;

	inline void			setRotation( const KsQuaternion& qRotation );

	inline KsQuaternion	getQuaternion() const;

	inline const float*	data() const;
	inline float*		data();

	inline KsTransform4	operator*( const KsTransform4& mOther );
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
void	KsTransform4::setIdentity()
{
	_m.setIdentity();
}

//-----------------------------------------------------------------------------
// Name:		setTranslation
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline void	KsTransform4::setTranslation( const KsVector3& vTranslation )
{
	_m.translation() = vTranslation._v;
}

//-----------------------------------------------------------------------------
// Name:		getTranslation
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline KsVector3	KsTransform4::getTranslation() const
{
	KsVector3 vTranslation;

	vTranslation._v = _m.translation();
	return	( vTranslation );
}

//-----------------------------------------------------------------------------
// Name:		setRotation
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline void	KsTransform4::setRotation( const KsQuaternion& qRotation )
{
	_m.linear() = qRotation._q.toRotationMatrix();
}

//-----------------------------------------------------------------------------
// Name:		getQuaternion
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline KsQuaternion	KsTransform4::getQuaternion() const
{
	KsQuaternion qRotation;

	qRotation._q = _m.rotation();
	return	( qRotation );
}

//-----------------------------------------------------------------------------
// Name:		data
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const float*	KsTransform4::data() const
{
	return	( _m.data() );
}

//-----------------------------------------------------------------------------
// Name:		data
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
float*	KsTransform4::data()
{
	return	( _m.data() );
}

//-----------------------------------------------------------------------------
// Name:		operator*
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline KsTransform4	KsTransform4::operator*( const KsTransform4& mOther )
{
	KsTransform4 mResult;

	mResult._m = _m * mOther._m;
	return	( mResult );
}

//-----------------------------------------------------------------------------
// Name:		operator()
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline float	KsTransform4::operator()(const uint32	uiRow, 
										const uint32	uiCol) const
{
	return	( _m( uiRow, uiCol ) );
}

KOSMO_CORE_NS_END

#endif