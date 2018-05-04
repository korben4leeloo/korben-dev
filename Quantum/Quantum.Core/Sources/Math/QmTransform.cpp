////*****************************************************************************
////
////	File:		QmTransform.cpp
////	Created:	2013-08-26
////
////*****************************************************************************
//
//#include "QmTransform.h"
//#include <glm/gtc/matrix_transform.hpp>
//
////-----------------------------------------------------------------------------
//// Name:		inverse
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//QmTransform QmTransform::inverse() const
//{
//	QmTransform inverseTransform;
//
//	inverseTransform._rotation		= glm::conjugate( _rotation );
//	inverseTransform._translation	= -( inverseTransform._rotation * _translation );
//
//	inverseTransform._scale.x = 1.0f / _scale.x;
//	inverseTransform._scale.y = 1.0f / _scale.y;
//	inverseTransform._scale.z = 1.0f / _scale.z;
//
//	return	( inverseTransform );
//}
//
////-----------------------------------------------------------------------------
//// Name:		toMat4x4
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//inline glm::mat4x4 QmTransform::toMat4x4() const
//{
//	glm::mat4x4 m;
//
//	m = glm::scale( m, glm::vec3( _scale ) );
//	m = glm::translate( m, glm::vec3( _translation ) );
//	m *= toMat4( _rotation );
//		
//	return	( m );
//}
//
////-----------------------------------------------------------------------------
//// Name:		operator*
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//QmTransform operator*(const QmTransform& lhs, const QmTransform& rhs)
//{
//	QmTransform result;
//
//	result._rotation	= rhs._rotation * lhs._rotation;
//	result._translation	= rhs._rotation * lhs._translation + rhs._translation;
//	result._scale		= rhs._scale * lhs._scale;
//
//	return	(result);
//}
