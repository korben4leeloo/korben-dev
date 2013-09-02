//*****************************************************************************
//
//	Class:		OkdVector4f
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdVector4f_h__
#define __OrkidCore_OkdVector4f_h__

#include	<Math/OkdMathCommon.h>

class OkdVector4f//: public Eigen::Vector4f//: public EigenVector4f
{
	//friend class OkdMatrix4f;

public:
								OkdVector4f();
								~OkdVector4f();

								//typedef EigenVector4f Base;

								//// This constructor allows you to construct MyVectorType from Eigen expressions
								//template<typename OtherDerived>
								//OkdVector4f(const Eigen::MatrixBase<OtherDerived>& other)
								//	: EigenTransform4f(other)
								//{ }

								//// This method allows you to assign Eigen expressions to MyVectorType
								//template<typename OtherDerived>
								//OkdVector4f & operator= (const Eigen::MatrixBase <OtherDerived>& other)
								//{
								//	this->Base::operator=(other);
								//	return *this;
								//}

private:
	//EigenVector4f				_v;
};

#endif