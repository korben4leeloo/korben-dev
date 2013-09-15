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

#include	ORKID_CORE_H(Math/OkdVector3f)

class OkdMesh
{
public:
					OkdMesh();
					~OkdMesh();

	void			create( const float* pVertexArray, const uint uiVertexCount, const uint uiPolygonCount );
	void			setPolygon( const uint uiPolygonIndex, const uint* pVertexIdArray );

	void			writeToStream( OkdBinaryStream* pStream );

private:
	struct	OkdMeshPolygon
	{
		uint _vertexIdArray[3];
	};

	void			releaseVertexArray();
	void			releasePolygonArray();

	uint			_uiVertexCount;
	uint			_uiPolygonCount;
	uint			_uiNormalCount;
	uint			_uiUVCount;

	OkdVector3f*	_pVertexArray;
	OkdMeshPolygon*	_pPolygonArray;
};

#endif