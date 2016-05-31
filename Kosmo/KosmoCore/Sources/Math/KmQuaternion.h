//*****************************************************************************
//
//	Class:		KmQuaternion
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __KosmoCore_KmQuaternion_h__
#define __KosmoCore_KmQuaternion_h__

#include	"Root.h"
#include	<glm/gtx/quaternion.hpp>

KOSMO_CORE_NAMESPACE_BEGIN

typedef glm::quat KmQuaternion;

inline KmQuaternion operator-( const KmQuaternion& q, const KmQuaternion& p );

KOSMO_CORE_NAMESPACE_END

#endif
