//*****************************************************************************
//
//	File:		OrkidMathCommon.h
//
//	Created:	2013-08-26
//
//*****************************************************************************

#define EIGEN_TRANSFORM_PLUGIN <Math/Geometry/OrkidEigenGeometryTransformPlugin.h>

#include	<Eigen/Geometry>

// Typedefs
/*typedef Eigen::Transform<float, 3, Eigen::Affine>	EigenTransform4f;
typedef Eigen::Vector4f								EigenVector4f;*/

typedef Eigen::Transform<float, 3, Eigen::Affine>	OrkidMat4f;
typedef Eigen::Vector4f								OrkidVec4f;
typedef Eigen::Vector3f								OrkidVec3f;