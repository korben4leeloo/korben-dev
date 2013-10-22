//*****************************************************************************
//
//	File:		OkdResourceHandle.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdResourceHandle.h"

////-----------------------------------------------------------------------------
//// Name:		OkdResourceHandle constructor
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//OkdResourceHandle::OkdResourceHandle(const OkdResourceId&	resourceId, 
//									 void*					pData)
//: _resourceId		( resourceId )
//, _uiRefCount		( 0 )
//, _uiLoadRefCount	( 0 )
//, _pData			( pData )
//{
//
//}

//-----------------------------------------------------------------------------
// Name:		OkdResourceHandle constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourceHandle::OkdResourceHandle(void*				pData, 
									 const OkdString&	strResourceName)
: _uiRefCount		( 0 )
, _uiLoadRefCount	( 0 )
, _pData			( pData )
, _strResourceName	( strResourceName )
{

}

//-----------------------------------------------------------------------------
// Name:		OkdResourceHandle destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourceHandle::~OkdResourceHandle()
{

}
