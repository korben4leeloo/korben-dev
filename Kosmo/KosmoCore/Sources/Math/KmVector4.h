//*****************************************************************************
//
//	Class:		KmVector4
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __KosmoCore_KmVector4_h__
#define __KosmoCore_KmVector4_h__

#include	"Root.h"

KOSMO_CORE_NAMESPACE_BEGIN

class KmVector3;

class KmVector4
{
public:
					KmVector4();
					KmVector4( const float x, const float y, const float z, const float w );
					~KmVector4();

private:
	Eigen::Vector4f	_v;
};

typedef KmVector4 KsVec4;

KOSMO_CORE_NAMESPACE_END

#endif