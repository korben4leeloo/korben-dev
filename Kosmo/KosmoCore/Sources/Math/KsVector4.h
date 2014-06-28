//*****************************************************************************
//
//	Class:		KsVector4
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __KosmoCore_KsVector4_h__
#define __KosmoCore_KsVector4_h__

#include	"Root.h"

KOSMO_CORE_NAMESPACE_BEGIN

class KsVector3;

class KsVector4
{
public:
					KsVector4();
					KsVector4( const float x, const float y, const float z, const float w );
					~KsVector4();

private:
	Eigen::Vector4f	_v;
};

typedef KsVector4 KsVec4;

KOSMO_CORE_NAMESPACE_END

#endif