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
#include	ORKID_CORE_H(Components/OkdComponentContainer)

class OkdFileStream;

class OkdEntity: public OkdComponentContainer
{
public:
							OkdEntity();
							OkdEntity( const OkdEntityType eEntityType );
	virtual					~OkdEntity();

	inline OkdEntityType	getEntityType() const;

	virtual void			read( OkdFileStream* pStream );
	virtual void			write( OkdFileStream* pStream );

protected:
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