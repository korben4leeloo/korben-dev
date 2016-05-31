//*****************************************************************************
//
//	Class:		KmTransform
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __KosmoCore_KmTransform_h__
#define __KosmoCore_KmTransform_h__

#include "Root.h"

#include KOSMO_CORE_H(Math/KmVector4)
#include KOSMO_CORE_H(Math/KmQuaternion)

struct KmTransform
{
	KmQuaternion	_rotation;
	KmVector4		_translation;
	KmVector4		_scale;

	inline KmTransform()
	: _scale( 1.0f, 1.0f, 1.0f, 1.0f )
	{
		
	}

	inline void setTranslation(const float x, const float y, const float z)
	{
		_translation.x = x;
		_translation.y = y;
		_translation.z = z;
	}

	KmTransform inverse() const;

	inline glm::mat4x4 toMat4x4() const;
};

KmTransform operator*( const KmTransform& lhs, const KmTransform& rhs );

#endif
