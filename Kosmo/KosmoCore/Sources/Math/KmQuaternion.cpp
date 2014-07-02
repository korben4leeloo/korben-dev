//*****************************************************************************
//
//	File:		KmQuaternion.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"KmQuaternion.h"

#include	KOSMO_CORE_H(Math/KmVector3)

//-----------------------------------------------------------------------------
// Name:		KmQuaternion constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KmQuaternion::KmQuaternion()
{
	
}

//-----------------------------------------------------------------------------
// Name:		KmQuaternion constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KmQuaternion::KmQuaternion(const KmVector3&	vAxis, 
						 const float		fAngle)
{
	_q = Eigen::Quaternionf( Eigen::AngleAxisf( fAngle, vAxis._v ) );
}

//-----------------------------------------------------------------------------
// Name:		KmQuaternion destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KmQuaternion::~KmQuaternion()
{

}
