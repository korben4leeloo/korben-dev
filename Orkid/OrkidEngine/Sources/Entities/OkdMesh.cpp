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
// Name:		setVertexArray
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdMesh::setVertexArray(const float*	pVertexArray, 
								uint			uiVertexCount )
{
	releaseVertexArray();

	_uiVertexCount = uiVertexCount;

	_pVertexArray = new OkdVector3f[uiVertexCount];
	memcpy( _pVertexArray, pVertexArray, uiVertexCount * 3 );
}

//-----------------------------------------------------------------------------
// Name:		setPolygonArray
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdMesh::setPolygonArray(const uint*	pPolygonArray, 
								 uint			uiPolygonCount)
{
	releasePolygonArray();

	_uiPolygonCount = uiPolygonCount;

	_pPolygonArray = new OkdMeshPolygon[uiPolygonCount];
	memcpy( _pPolygonArray, pPolygonArray, uiPolygonCount * 3 );
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
