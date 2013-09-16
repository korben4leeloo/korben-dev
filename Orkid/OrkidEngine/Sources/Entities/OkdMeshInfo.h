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

	void			writeToStream( OkdFileStream* pStream );

private:
	uint			_uiVertexCount;
	uint			_uiPolygonCount;
};

#endif