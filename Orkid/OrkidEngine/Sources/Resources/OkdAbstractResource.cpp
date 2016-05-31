//*****************************************************************************
//
//	File:		OkdAbstractResource.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdAbstractResource.h"

//-----------------------------------------------------------------------------
// Name:		OkdAbstractResource constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdAbstractResource::OkdAbstractResource()
: _resourceKey		( 0xFFFFFFFF )
, _uiRefCount		( 0 )
, _uiLoadRefCount	( 0 )
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdAbstractResource destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdAbstractResource::~OkdAbstractResource()
{

}
