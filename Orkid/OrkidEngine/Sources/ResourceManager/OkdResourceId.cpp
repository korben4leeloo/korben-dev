//*****************************************************************************
//
//	File:		OkdResourceId.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdResourceId.h"

//-----------------------------------------------------------------------------
// Name:		OkdResourceId constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourceId::OkdResourceId(const OrkidResourceType	eResourceType, 
							 const uint32				uiResourceId)
: _eResourceType	( eResourceType )
, _uiResourceId		( uiResourceId )
{
	
}

////-----------------------------------------------------------------------------
//// Name:		OkdResourceId constructor
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//OkdResourceId::OkdResourceId(const OrkidResourceType	eResourceType, 
//							 const OkdString&			strResourceName)
//: _eResourceType	( eResourceType )
//, _strResourceName	( strResourceName )
//{
//
//}

////-----------------------------------------------------------------------------
//// Name:		OkdResourceId constructor
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//OkdResourceId::OkdResourceId(const OrkidResourceType	uiResourceType)
//{
//
//}

//-----------------------------------------------------------------------------
// Name:		OkdResourceId destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourceId::~OkdResourceId()
{
	//clearResources();
}
