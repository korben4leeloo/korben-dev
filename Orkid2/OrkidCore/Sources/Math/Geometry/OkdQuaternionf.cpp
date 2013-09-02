//*****************************************************************************
//
//	File:		OkdQuaternionf.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdQuaternionf.h"

#include	<Math/Geometry/OkdQuaternionf.h>
#include	<Math/Geometry/OkdVector3f.h>

//-----------------------------------------------------------------------------
// Name:		OkdQuaternionf constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdQuaternionf::OkdQuaternionf()
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdQuaternionf constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdQuaternionf::OkdQuaternionf(const OkdVector3f&	vAxis, 
					   const float			fAngle)
{
	_q = EigenQuatf( EigenAngleAxisf( fAngle, vAxis._v ) );
}

//-----------------------------------------------------------------------------
// Name:		OkdQuaternionf destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdQuaternionf::~OkdQuaternionf()
{

}
