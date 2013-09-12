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

	void			setVertexArray( const float* pVertexArray, uint uiVertexCount );
	void			setPolygonArray( const uint* pPolygonArray, uint uiPolygonCount );

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