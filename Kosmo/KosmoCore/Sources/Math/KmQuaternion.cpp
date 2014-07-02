//*****************************************************************************
//
//	File:		KsQuaternion.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"KsQuaternion.h"

#include	KOSMO_CORE_H(Math/KsVector3)

//-----------------------------------------------------------------------------
// Name:		KsQuaternion constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KsQuaternion::KsQuaternion()
{
	
}

//-----------------------------------------------------------------------------
// Name:		KsQuaternion constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KsQuaternion::KsQuaternion(const KsVector3&	vAxis, 
						 const float		fAngle)
{
	_q = Eigen::Quaternionf( Eigen::AngleAxisf( fAngle, vAxis._v ) );
}

//-----------------------------------------------------------------------------
// Name:		KsQuaternion destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KsQuaternion::~KsQuaternion()
{

}
