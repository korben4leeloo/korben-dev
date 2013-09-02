//*****************************************************************************
//
//	File:		OrkidEigenGeometryTransformPlugin.h
//
//	Created:	2013-08-26
//
//*****************************************************************************

inline void setTranslation( const OrkidVec3f& v )
{
	translation() = v;
}

inline void setQuaternion( const OrkidQuatf& q )
{
	linear() = q.toRotationMatrix();
}
