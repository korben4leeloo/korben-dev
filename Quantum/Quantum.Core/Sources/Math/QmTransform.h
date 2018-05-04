////*****************************************************************************
////
////	Class:		QmTransform
////
////	Created:	2013-08-26
////
////*****************************************************************************
//
//#ifndef __QUANTUM_CORE_TK_TRANSFORM_H__
//#define __QUANTUM_CORE_TK_TRANSFORM_H__
//
//#include "Root.h"
//
//#include QUANTUM_CORE_H(Math/QmVector4)
//#include QUANTUM_CORE_H(Math/QmQuaternion)
//
//struct QmTransform
//{
//	QmQuaternion	_rotation;
//	QmVector4		_translation;
//	QmVector4		_scale;
//
//	inline QmTransform()
//	: _scale( 1.0f, 1.0f, 1.0f, 1.0f )
//	{
//		
//	}
//
//	inline void setTranslation(const float x, const float y, const float z)
//	{
//		_translation.x = x;
//		_translation.y = y;
//		_translation.z = z;
//	}
//
//	QmTransform inverse() const;
//
//	inline glm::mat4x4 toMat4x4() const;
//};
//
//QmTransform operator*( const QmTransform& lhs, const QmTransform& rhs );
//
//#endif
