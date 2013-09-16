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

class OkdMesh
{
public:
	void			create( const OkdMeshInfo& meshInfo );

	void			setVertexArray( const float* pVertexArray );
	void			setPolygon( const uint uiPolygonIndex, const uint* pVertexIdArray );

	void			writeToStream( OkdFileStream* pStream );

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

#endif