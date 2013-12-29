//*****************************************************************************
//
//	Class:		OkdEntity
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdEntity_h__
#define __OrkidEngine_OkdEntity_h__

#include	"Root.h"

class OkdFileStream;

class OkdEntity
{
public:
	inline OkdEntityType	getEntityType() const;

	virtual void			read( OkdFileStream* pStream )	= 0;
	virtual void			write( OkdFileStream* pStream )	= 0;

protected:
							OkdEntity( const OkdEntityType eEntityType );
	virtual					~OkdEntity();

	OkdEntityType			_eEntityType;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		getEntityType
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdEntityType	OkdEntity::getEntityType() const
{
	return	( _eEntityType );
}

#endif