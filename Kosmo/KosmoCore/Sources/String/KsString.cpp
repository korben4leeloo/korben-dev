//*****************************************************************************
//
//	File:		KsString.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"KsString.h"

#include	<string.h>

////-----------------------------------------------------------------------------
//// Name:		KsString constructor
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//KsString::KsString()
//: _uiLength	( 0 )
//{
//	_pcBuffer		= new char[_uiLength+1];
//	_pcBuffer[0]	= '\0';
//}

//-----------------------------------------------------------------------------
// Name:		KsString constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KsString::KsString(const char*	pcData)
: _pcBuffer	( NULL )
, _uiLength	( 0 )
{
	assign( pcData );
}

//-----------------------------------------------------------------------------
// Name:		KsString constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KsString::KsString(const KsString&	other)
: _pcBuffer	( NULL )
, _uiLength	( 0 )
{
	assign( other.getData() );
}

//-----------------------------------------------------------------------------
// Name:		KsString destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KsString::~KsString()
{
	delete[] _pcBuffer;
}

//-----------------------------------------------------------------------------
// Name:		operator=
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KsString& KsString::operator=(const KsString&	other)
{
	if	( &other != this )
	{
		assign( other.getData() );
	}

	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator=
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KsString& KsString::operator=(const char*	pcData)
{
	assign( pcData );
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		assign
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	KsString::assign(const char*	pcData)
{
	if	( _pcBuffer )
	{
		delete[] _pcBuffer;
	}

	_uiLength	= (uint32)strlen( pcData );
	_pcBuffer	= new char[_uiLength+1];

	strcpy_s( _pcBuffer, _uiLength + 1, pcData );
}
