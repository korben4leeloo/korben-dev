//*****************************************************************************
//
//	File:		OrkidQuatf.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OrkidQuatf.h"

#include	<Math/Geometry/OrkidQuatf.h>
#include	<Math/Geometry/OrkidVec3f.h>

//-----------------------------------------------------------------------------
// Name:		OrkidQuatf constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OrkidQuatf::OrkidQuatf()
{
	
}

//-----------------------------------------------------------------------------
// Name:		OrkidQuatf constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OrkidQuatf::OrkidQuatf(const OrkidVec3f&	vAxis, 
					   const float			fAngle)
{
	_q = EigenQuatf( EigenAngleAxisf( fAngle, vAxis._v ) );
}

//-----------------------------------------------------------------------------
// Name:		OrkidQuatf destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OrkidQuatf::~OrkidQuatf()
{

}
