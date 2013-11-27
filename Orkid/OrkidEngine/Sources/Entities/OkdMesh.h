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

#include	ORKID_ENGINE_H(Resources/OkdAbstractResource)
#include	ORKID_ENGINE_H(Entities/OkdMeshInfo)

class OkdVector3f;

class OkdMesh: public OkdAbstractResource
{
	template<class T> friend class OkdResourceRef;

public:
	void			create( const OkdMeshInfo& meshInfo );

	void			setVertexArray( const float* pVertexArray );
	void			setPolygon( const uint uiPolygonIndex, const uint* pVertexIdArray );

	virtual void	read( OkdFileStream* pStream );
	virtual void	write( OkdFileStream* pStream );

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