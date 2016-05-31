//*****************************************************************************
//
//	File:		OkdMeshInfo.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdMeshInfo.h"

#include	ORKID_CORE_H(Stream/OkdFileStream)

//-----------------------------------------------------------------------------
// Name:		OkdMeshInfo constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdMeshInfo::OkdMeshInfo()
: _uiVertexCount	( 0 )
, _uiPolygonCount	( 0 )
{

}

//-----------------------------------------------------------------------------
// Name:		OkdMeshInfo constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdMeshInfo::OkdMeshInfo(const uint	uiVertexCount, 
						 const uint uiPolygonCount)
: _uiVertexCount	( uiVertexCount )
, _uiPolygonCount	( uiPolygonCount )
{

}

//-----------------------------------------------------------------------------
// Name:		OkdMeshInfo destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdMeshInfo::~OkdMeshInfo()
{
	
}

//-----------------------------------------------------------------------------
// Name:		read
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdMeshInfo::read(OkdFileStream* pStream)
{
	OkdFileStream& stream = *pStream;

	stream >> _uiVertexCount;
	stream >> _uiPolygonCount;
}

//-----------------------------------------------------------------------------
// Name:		write
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdMeshInfo::write(OkdFileStream* pStream)
{
	OkdFileStream& stream = *pStream;

	stream << _uiVertexCount;
	stream << _uiPolygonCount;
}
