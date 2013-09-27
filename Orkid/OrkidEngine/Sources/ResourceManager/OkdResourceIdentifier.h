//*****************************************************************************
//
//	Class:		OkdResourceIdentifier
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdResourceIdentifier_h__
#define __OrkidEngine_OkdResourceIdentifier_h__

#include	"Root.h"

class OkdResourceIdentifier
{
public:
								OkdResourceIdentifier( const OrkidResourceType eResourceType, const int32 nResourceId );
								OkdResourceIdentifier( const OrkidResourceType eResourceType );
								~OkdResourceIdentifier();

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
OrkidResourceType	OkdResourceIdentifier::getResourceType() const
{
	return	( _eResourceType );
}

//-----------------------------------------------------------------------------
// Name:		getResourceId
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
int32	OkdResourceIdentifier::getResourceId() const
{
	return	( _nResourceId );
}

#endif