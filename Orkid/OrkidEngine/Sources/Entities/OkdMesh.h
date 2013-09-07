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

#include	ORKID_CORE_H(Containers/OkdVector)

class OkdMesh
{
public:
			OkdMesh();
			~OkdMesh();

private:
	uint	_uiVertexCount;
	uint	_uiPolygonCount;
	uint	_uiNormalCount;
	uint	_uiUVCount;

	//OrkidVector<
};

#endif