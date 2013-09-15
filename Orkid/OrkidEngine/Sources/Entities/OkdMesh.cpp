//*****************************************************************************
//
//	File:		OkdMesh.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdMesh.h"

#include	ORKID_CORE_H(Stream/OkdStream)

//-----------------------------------------------------------------------------
// Name:		OkdMesh constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdMesh::OkdMesh()
: _uiVertexCount	( 0 )
, _uiPolygonCount	( 0 )
, _uiNormalCount	( 0 )
, _uiUVCount		( 0 )
, _pVertexArray		( 0 )
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
void	OkdMesh::create(const float*	pVertexArray, 
						const uint		uiVertexCount,
						const uint		uiPolygonCount)
{
	releaseVertexArray();
	releasePolygonArray();

	_uiVertexCount	= uiVertexCount;
	_uiPolygonCount	= uiPolygonCount;

	_pVertexArray	= new OkdVector3f[uiVertexCount];
	_pPolygonArray	= new OkdMeshPolygon[uiPolygonCount];

	memcpy( _pVertexArray, pVertexArray, uiVertexCount * sizeof(OkdVector3f) );
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

		_pVertexArray	= 0;
		_uiVertexCount	= 0;
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

		_pPolygonArray	= 0;
		_uiPolygonCount	= 0;
	}
}

//-----------------------------------------------------------------------------
// Name:		writeToStream
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdMesh::writeToStream(OkdBinaryStream* pStream)
{
	ORKID_ASSERT( _pVertexArray );
	ORKID_ASSERT( _pPolygonArray );

	OkdBinaryStream& stream = *pStream;

	stream << _uiVertexCount;
	stream << _uiPolygonCount;

	stream.writeRawData( (const char*)_pVertexArray, _uiVertexCount * sizeof(OkdVector3f) );
	stream.writeRawData( (const char*)_pPolygonArray, _uiPolygonCount * sizeof(OkdMeshPolygon) );
}
