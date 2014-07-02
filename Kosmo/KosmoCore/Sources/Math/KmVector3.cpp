//*****************************************************************************
//
//	File:		KmVector3.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"KmVector3.h"

//-----------------------------------------------------------------------------
// Name:		KmVector3 constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KmVector3::KmVector3()
{
	
}

//-----------------------------------------------------------------------------
// Name:		KmVector3 constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KmVector3::KmVector3(const float x, 
				   const float y, 
				   const float z)
{
	_v = Eigen::Vector3f( x, y, z );
}

//-----------------------------------------------------------------------------
// Name:		KmVector3 destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KmVector3::~KmVector3()
{

}
