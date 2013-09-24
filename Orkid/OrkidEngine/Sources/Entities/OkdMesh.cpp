//*****************************************************************************
//
//	File:		OkdMesh.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdMesh.h"

//-----------------------------------------------------------------------------
// Name:		OkdMesh constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdMesh::OkdMesh()
: _pVertexArray		( 0 )
, _pPolygonArray	( 0 )
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdMesh destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdMesh::~OkdMesh()
{
	releaseVertexArray();
	releasePolygonArray();
}

//-----------------------------------------------------------------------------
// Name:		create
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdMesh::create(const OkdMeshInfo&	meshInfo)
{
	uint uiVertexCount	= meshInfo.getVertexCount();
	uint uiPolygonCount	= meshInfo.getVertexCount();

	releaseVertexArray();
	releasePolygonArray();

	_meshInfo = meshInfo;

	_pVertexArray	= new OkdVector3f[uiVertexCount];
	_pPolygonArray	= new OkdMeshPolygon[uiPolygonCount];
}

//-----------------------------------------------------------------------------
// Name:		setVertexArray
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdMesh::setVertexArray(const float*	pVertexArray)
{
	memcpy( _pVertexArray, pVertexArray, _meshInfo.getVertexCount() * sizeof(OkdVector3f) );
}

//-----------------------------------------------------------------------------
// Name:		setPolygon
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdMesh::setPolygon(const uint	uiPolygonIndex, 
							const uint*	pVertexIdArray)
{
	memcpy( _pPolygonArray[uiPolygonIndex]._vertexIdArray, pVertexIdArray, 3 * sizeof(uint) );
}

//-----------------------------------------------------------------------------
// Name:		releaseVertexArray
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdMesh::releaseVertexArray()
{
	if	( _pVertexArray )
	{
		delete[] _pVertexArray;

		_pVertexArray = 0;
		_meshInfo.setVertexCount( 0 );
	}
}

//-----------------------------------------------------------------------------
// Name:		releasePolygonArray
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdMesh::releasePolygonArray()
{
	if	( _pPolygonArray )
	{
		delete[] _pPolygonArray;

		_pPolygonArray = 0;
		_meshInfo.setPolygonCount( 0 );
	}
}

//-----------------------------------------------------------------------------
// Name:		write
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdMesh::write(OkdFileStream* pStream)
{
	ORKID_ASSERT( _pVertexArray );
	ORKID_ASSERT( _pPolygonArray );

	OkdFileStream& stream = *pStream;

	_meshInfo.write( pStream );

	stream.write( (const char*)_pVertexArray, _meshInfo.getVertexCount() * sizeof(OkdVector3f) );
	stream.write( (const char*)_pPolygonArray, _meshInfo.getPolygonCount() * sizeof(OkdMeshPolygon) );
}

////-----------------------------------------------------------------------------
//// Name:		load
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//void	OkdMesh::load(OkdMesh* pMesh)
//{
//	
//}

////-----------------------------------------------------------------------------
//// Name:		load
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//void	OkdMesh::load(OkdMeshResource* pMeshResource)
//{
//
//}
