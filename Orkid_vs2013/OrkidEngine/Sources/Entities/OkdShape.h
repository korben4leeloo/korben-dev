////*****************************************************************************
////
////	Class:		OkdShape
////
////	Created:	2013-08-26
////
////*****************************************************************************
//
//#ifndef __OrkidEngine_OkdShape_h__
//#define __OrkidEngine_OkdShape_h__
//
//#include	"Root.h"
//
//#include	ORKID_ENGINE_H(Entities/OkdEntity)
//#include	ORKID_ENGINE_H(Resources/OkdResourcePtr)
////#include	ORKID_ENGINE_H(Entities/OkdMesh)
//
//class OkdMesh;
//typedef OkdResourcePtr<OkdMesh> OkdMeshPtr;
//
//class OkdShape: public OkdEntity
//{
//	friend class OkdEntityFactory;
//
//public:
//	inline void		setMeshPtr( const OkdMeshPtr& meshPtr );
//
//	// OkdEntity implementation
//	virtual void	read( OkdFileStream* pStream );
//	virtual void	write( OkdFileStream* pStream );
//
//private:
//					OkdShape();
//	virtual			~OkdShape();
//
//	OkdMeshPtr		_meshPtr;
//};
//
////*****************************************************************************
////	Inline functions declarations
////*****************************************************************************
//
////-----------------------------------------------------------------------------
//// Name:		setMeshPtr
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//void	OkdShape::setMeshPtr(const OkdMeshPtr&	meshPtr)
//{
//	_meshPtr = meshPtr;
//}
//
//#endif