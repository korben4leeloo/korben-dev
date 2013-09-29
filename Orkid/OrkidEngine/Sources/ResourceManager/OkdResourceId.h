//*****************************************************************************
//
//	Class:		OkdResourceId
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdResourceId_h__
#define __OrkidEngine_OkdResourceId_h__

#include	"Root.h"

class OkdResourceId
{
public:
								OkdResourceId( const OrkidResourceType eResourceType, const int32 nResourceId );
								OkdResourceId( const OrkidResourceType eResourceType );
								~OkdResourceId();

	inline OrkidResourceType	getResourceType() const;
	inline int32				getResourceId() const;

private:
	OrkidResourceType			_eResourceType;
	int32						_nResourceId;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		getResourceType
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OrkidResourceType	OkdResourceId::getResourceType() const
{
	return	( _eResourceType );
}

//-----------------------------------------------------------------------------
// Name:		getResourceId
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
int32	OkdResourceId::getResourceId() const
{
	return	( _nResourceId );
}

#endif