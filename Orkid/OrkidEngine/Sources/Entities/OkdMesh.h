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
#include	ORKID_ENGINE_H(ResourceManager/OkdSharedResource)

class OkdMesh
{
public:
	//friend class OkdSharedPtr<OkdMesh>;

	void			create( const OkdMeshInfo& meshInfo );

	void			setVertexArray( const float* pVertexArray );
	void			setPolygon( const uint uiPolygonIndex, const uint* pVertexIdArray );

	void			write( OkdFileStream* pStream );

	static void		load( OkdMesh* pMesh );

	friend class OkdSharedResource<OkdMesh, &OkdMesh::load>;
	friend class OkdSharedPtr<OkdMesh>;

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

typedef OkdSharedResource<OkdMesh, &OkdMesh::load> OkdMeshResource;

#endif