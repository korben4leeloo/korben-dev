//*****************************************************************************
//
//	File:		OrkidEigenGeometryTransformPlugin.h
//
//	Created:	2013-08-26
//
//*****************************************************************************

class OrkidVec3f;

inline void setTranslation( const OrkidVec3f& v )
{
	translation() = v;
}