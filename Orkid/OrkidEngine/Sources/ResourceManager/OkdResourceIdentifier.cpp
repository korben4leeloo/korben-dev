//*****************************************************************************
//
//	File:		OkdResourceIdentifier.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdResourceIdentifier.h"

#include	ORKID_CORE_H(String/OkdCrc32)

//-----------------------------------------------------------------------------
// Name:		OkdResourceIdentifier constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourceIdentifier::OkdResourceIdentifier(const OrkidResourceType	eResourceType, 
											 const int32				nResourceId)
: _eResourceType	( eResourceType )
, _nResourceId		( nResourceId )
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdResourceIdentifier constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourceIdentifier::OkdResourceIdentifier(const OrkidResourceType	uiResourceType)
{

}

//-----------------------------------------------------------------------------
// Name:		OkdResourceIdentifier destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourceIdentifier::~OkdResourceIdentifier()
{
	//clearResources();
}
