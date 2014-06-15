//*****************************************************************************
//
//	Class:		Vector4f
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __KosmoCore_Vector4f_h__
#define __KosmoCore_Vector4f_h__

#include	"Root.h"

namespace Kosmo {

class Vector3f;

class Vector4f
{
public:
					Vector4f();
					Vector4f( const float x, const float y, const float z, const float w );
					~Vector4f();

					Vector4f( const Vector3f& v3f );

private:
	Eigen::Vector4f	_v;
};

} // namespace Kosmo

#endif