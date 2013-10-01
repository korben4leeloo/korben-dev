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
								OkdResourceId( const OrkidResourceType eResourceType, const uint32 uiResourceId );
								OkdResourceId( const OrkidResourceType eResourceType );
								~OkdResourceId();

	inline OrkidResourceType	getResourceType() const;
	inline uint32				getResourceId() const;

private:
	OrkidResourceType			_eResourceType;
	uint32						_uiResourceId;
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
uint32	OkdResourceId::getResourceId() const
{
	return	( _uiResourceId );
}

#endif