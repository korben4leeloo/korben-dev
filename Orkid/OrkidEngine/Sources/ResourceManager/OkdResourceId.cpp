//*****************************************************************************
//
//	File:		OkdResourceId.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdResourceId.h"

#include	ORKID_CORE_H(String/OkdCrc32)

//-----------------------------------------------------------------------------
// Name:		OkdResourceId constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourceId::OkdResourceId(const OrkidResourceType	eResourceType, 
							 const int32				nResourceId)
: _eResourceType	( eResourceType )
, _nResourceId		( nResourceId )
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdResourceId constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourceId::OkdResourceId(const OrkidResourceType	uiResourceType)
{

}

//-----------------------------------------------------------------------------
// Name:		OkdResourceId destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourceId::~OkdResourceId()
{
	//clearResources();
}
