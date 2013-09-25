//*****************************************************************************
//
//	Class:		OkdMesh
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdMesh_h__
#define __OrkidEngine_OkdMesh_h__

#include	"Root.h"

#include	ORKID_ENGINE_H(Entities/OkdMeshInfo)
#include	ORKID_CORE_H(Math/OkdVector3f)
#include	ORKID_CORE_H(Stream/OkdFileStream)
//#include	ORKID_CORE_H(Memory/OkdSharedPtr)
//#include	ORKID_ENGINE_H(ResourceManager/OkdSharedResource)
#include	ORKID_ENGINE_H(ResourceManager/OkdResourceManager)

//class OkdMesh;
//typedef OkdSharedResource<OkdMesh> OkdMeshResource;

class OkdMeshHandler: public OkdAbstractResourceHandler
{

};

class OkdMesh
{
public:
	//friend class OkdSharedResource<OkdMesh>;
	//friend class OkdResourceManager;

	void			create( const OkdMeshInfo& meshInfo );

	void			setVertexArray( const float* pVertexArray );
	void			setPolygon( const uint uiPolygonIndex, const uint* pVertexIdArray );

	void			write( OkdFileStream* pStream );

	//static void		load( OkdMesh* pMesh );
	//static void		load( OkdMeshResource* pMeshResource );

	//friend class OkdSharedResource<OkdMesh, &OkdMesh::load>;
	//friend class OkdSharedPtr<OkdMesh>;
	//friend class OkdSharedResource<OkdMesh>;
	//friend class OkdSharedResourcePtr<OkdSharedResource, &OkdMesh::load>;

private:
	struct	OkdMeshPolygon
	{
		uint _vertexIdArray[3];
	};

	OkdMesh();
	~OkdMesh();

	void			releaseVertexArray();
	void			releasePolygonArray();

	OkdMeshInfo		_meshInfo;

	OkdVector3f*	_pVertexArray;
	OkdMeshPolygon*	_pPolygonArray;
};

//typedef OkdSharedResourcePtr<OkdMesh, &OkdMesh::load> OkdMeshResourcePtr;
//typedef OkdSharedResource<OkdMesh, &OkdMesh::load> OkdMeshResource;
//typedef OkdSharedPtr<OkdMeshResource> OkdMeshResourcePtr;

#endif