//*****************************************************************************
//
//	Class:		QmQuaternion
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __QUANTUM_CORE_TK_QUATERNION_H__
#define __QUANTUM_CORE_TK_QUATERNION_H__

#include	"Root.h"
#include	<glm/gtx/quaternion.hpp>

typedef glm::quat QmQuaternion;

inline QmQuaternion operator-( const QmQuaternion& q, const QmQuaternion& p );

#endif
