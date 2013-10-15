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

#include	ORKID_CORE_H(String/OkdString)

class OkdResourceId
{
public:
								//OkdResourceId( const OrkidResourceType eResourceType, const uint32 uiResourceId );
								//OkdResourceId( const OrkidResourceType eResourceType );
								OkdResourceId( const OrkidResourceType eResourceType, const OkdString& strResourceName );
								~OkdResourceId();

	inline OrkidResourceType	getResourceType() const;
	//inline uint32				getResourceId() const;
	inline const OkdString&		getResourceName() const;

private:
	OrkidResourceType			_eResourceType;
	//uint32						_uiResourceId;
	OkdString					_strResourceName;
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

////-----------------------------------------------------------------------------
//// Name:		getResourceId
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//uint32	OkdResourceId::getResourceId() const
//{
//	return	( _uiResourceId );
//}

//-----------------------------------------------------------------------------
// Name:		getResourceName
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const OkdString&	OkdResourceId::getResourceName() const
{
	return	( _strResourceName );
}

#endif