//*****************************************************************************
//
//	Class:		OrkidMat4f
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OrkidMat4f_h__
#define __OrkidCore_OrkidMat4f_h__

#include	<Math/OrkidMathCommon.h>

class OrkidVec4f;

class OrkidMat4f//: public EigenTransform4f
{
public:
								OrkidMat4f();
								~OrkidMat4f();

								//typedef EigenTransform4f Base;

								//// This constructor allows you to construct MyVectorType from Eigen expressions
								//template<typename OtherDerived>
								//OrkidMat4f(const Eigen::MatrixBase<OtherDerived>& other)
								//	: EigenTransform4f(other)
								//{ }

								//// This method allows you to assign Eigen expressions to MyVectorType
								//template<typename OtherDerived>
								//OrkidMat4f & operator= (const Eigen::MatrixBase <OtherDerived>& other)
								//{
								//	this->Base::operator=(other);
								//	return *this;
								//}

	inline void					setTranslation( const OrkidVec4f& vTranslation );
	inline const OrkidVec4f&	getTranslation() const;

private:
	EigenTransform4f			_m;
};

#endif