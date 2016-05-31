////*****************************************************************************
////
////	Class:		OkdCamera
////
////	Created:	2013-08-26
////
////*****************************************************************************
//
//#ifndef __OrkidEngine_OkdCamera_h__
//#define __OrkidEngine_OkdCamera_h__
//
//#include	"Root.h"
//
//#include	ORKID_ENGINE_H(Entities/OkdEntity)
//#include	ORKID_CORE_H(Math/OkdMatrix4f)
//
//class OkdFileStream;
//
//class OkdCamera: public OkdEntity
//{
//	friend class OkdEntityFactory;
//
//					ORKID_ALIGNED_NEW( 16 )
//
//public:
//	virtual void	read( OkdFileStream* pStream );
//	virtual void	write( OkdFileStream* pStream );
//
//	inline void		setFieldOfView( const float fFieldOfView );
//	inline void		setNearClipPlane( const float fNearClipPlane );
//	inline void		setFarClipPlane( const float fFarClipPlane );
//
//private:
//					OkdCamera();
//	virtual			~OkdCamera();
//
//	OkdMatrix4f		_mPerspective;
//
//	float			_fFieldOfView;
//	float			_fNearClipPlane;
//	float			_fFarClipPlane;
//};
//
////*****************************************************************************
////	Inline functions declarations
////*****************************************************************************
//
////-----------------------------------------------------------------------------
//// Name:		setFieldOfView
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//void	OkdCamera::setFieldOfView(const float	fFieldOfView)
//{
//	_fFieldOfView = fFieldOfView;
//}
//
////-----------------------------------------------------------------------------
//// Name:		setNearClipPlane
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//void	OkdCamera::setNearClipPlane( const float	fNearClipPlane )
//{
//	_fNearClipPlane = fNearClipPlane;
//}
////-----------------------------------------------------------------------------
//// Name:		setFarClipPlane
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//void	OkdCamera::setFarClipPlane( const float	fFarClipPlane )
//{
//	_fFarClipPlane = fFarClipPlane;
//}
//
//#endif