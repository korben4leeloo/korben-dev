//*****************************************************************************
//
//	File:		TkString.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "Root.h"
#include "TkString.h"

#include <cstring>

//-----------------------------------------------------------------------------
// Name:		TkString constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkString::TkString()
: _pcBuffer	( NULL )
, _nSize	( 0 )
{
	
}

//-----------------------------------------------------------------------------
// Name:		TkString constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkString::TkString( const char* pcBuffer )
: _pcBuffer	( NULL )
, _nSize	( 0 )
{
	copy( pcBuffer );
}

//-----------------------------------------------------------------------------
// Name:		TkString constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkString::TkString( const TkString& rhs )
: _pcBuffer	( NULL )
, _nSize	( 0 )
{
	copy( rhs._pcBuffer );
}

//-----------------------------------------------------------------------------
// Name:		TkString destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkString::~TkString()
{
	clear();
}

//-----------------------------------------------------------------------------
// Name:		operator=
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkString& TkString::operator=( const TkString& rhs )
{
	copy( rhs._pcBuffer );
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		copy
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void TkString::copy( const char* pcBuffer )
{
	clear();

	if ( pcBuffer )
	{
		_nSize = (uint32)strlen( pcBuffer );

		if ( _nSize > 0 )
		{
			_pcBuffer = new char[_nSize+1];
			strcpy( _pcBuffer, pcBuffer );
			_pcBuffer[_nSize] = '\0';
		}
	}
}

//-----------------------------------------------------------------------------
// Name:		clear
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
bool operator==( const TkString& lhs, const TkString& rhs )
{
	if ( &lhs == &rhs )
	{
		return ( true );
	}

	if ( lhs._nSize == 0 )
	{
		return ( rhs._nSize == 0 );
	}
	else
	{
		return ( ( rhs._nSize > 0 ) && ( strcmp( lhs._pcBuffer, rhs._pcBuffer ) == 0 ) );
	}
}
