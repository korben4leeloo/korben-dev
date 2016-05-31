//*****************************************************************************
//
//	Class:		OkdVector4f
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdVector4f_h__
#define __OrkidCore_OkdVector4f_h__

#include	"Root.h"

class OkdVector4f
{
private:
				typedef Eigen::Vector4f EigenVec4f;

public:
				OkdVector4f();
				~OkdVector4f();

private:
	EigenVec4f	_v;
};

#endif