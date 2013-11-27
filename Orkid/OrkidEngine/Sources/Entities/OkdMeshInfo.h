//*****************************************************************************
//
//	Class:		OkdMeshInfo
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdMeshInfo_h__
#define __OrkidEngine_OkdMeshInfo_h__

#include	"Root.h"

class OkdFileStream;

class OkdMeshInfo
{
public:
					OkdMeshInfo();
					OkdMeshInfo( const uint uiVertexCount, const uint uiPolygonCount );
					~OkdMeshInfo();

	inline void		setVertexCount( const uint uiVertexCount );
	inline uint		getVertexCount() const;

	inline void		setPolygonCount( const uint uiPolygonCount );
	inline uint		getPolygonCount() const;

	void			read( OkdFileStream* pStream );
	void			write( OkdFileStream* pStream );

private:
	uint			_uiVertexCount;
	uint			_uiPolygonCount;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		setVertexCount
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdMeshInfo::setVertexCount( const uint uiVertexCount )
{
	_uiVertexCount = uiVertexCount;
}

//-----------------------------------------------------------------------------
// Name:		getVertexCount
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
uint	OkdMeshInfo::getVertexCount() const
{
	return	( _uiVertexCount );
}

//-----------------------------------------------------------------------------
// Name:		setPolygonCount
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdMeshInfo::setPolygonCount( const uint uiPolygonCount )
{
	_uiPolygonCount = uiPolygonCount;
}

//-----------------------------------------------------------------------------
// Name:		getPolygonCount
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
uint	OkdMeshInfo::getPolygonCount() const
{
	return	( _uiPolygonCount );
}


#endif