//*****************************************************************************
//
//	File:		OkdSharedResource.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

//#include	"OkdSharedResource.h"

////-----------------------------------------------------------------------------
//// Name:		OkdSharedResource constructor
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//OkdSharedResource::OkdSharedResource(const OkdString&			strResourceName, 
//									 const OkdString&			strResourceLocName,
//									 const RESOURCE_LOCATION	eResourceLoc)
//: _strResourceName		( strResourceName )
//, _strResourceLocName	( strResourceLocName )
//, _eResourceLoc			( eResourceLoc )
//, _uiLoadRefCount		( 0 )
//{
//
//}
//
////-----------------------------------------------------------------------------
//// Name:		OkdSharedResource destructor
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//OkdSharedResource::~OkdSharedResource()
//{
//
//}
//
////-----------------------------------------------------------------------------
//// Name:		load
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//void	OkdSharedResource::load()
//{
//	_uiLoadRefCount++;
//}
//
////-----------------------------------------------------------------------------
//// Name:		unload
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//void	OkdSharedResource::unload()
//{
//	ORKID_ASSERT( _uiLoadRefCount > 0 );
//
//	if	( _uiLoadRefCount > 0 )
//	{
//		_uiLoadRefCount--;
//	}
//}
