//*****************************************************************************
//
//	File:		KmString.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "KmString.h"
#include <string.h>

KmString KmString::_nullString( NULL );
KmString KmString::_emptyString( "" );

//-----------------------------------------------------------------------------
// Name:		KmString constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KmString::KmString(const char*	pcData)
: _pcBuffer	( NULL )
, _uiLength	( 0 )
{
	copy( pcData );
}

//-----------------------------------------------------------------------------
// Name:		KmString constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KmString::KmString(const KmString&	other)
: _pcBuffer	( NULL )
, _uiLength	( 0 )
{
	copy( other.getData() );
}

//-----------------------------------------------------------------------------
// Name:		KmString constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KmString::KmString(KmString&&	other)
{
	_pcBuffer = other._pcBuffer;
	_uiLength = other._uiLength;

	other._pcBuffer = NULL;
	other._uiLength = 0;
}

//-----------------------------------------------------------------------------
// Name:		KmString destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KmString::~KmString()
{
	delete[] _pcBuffer;
}

//-----------------------------------------------------------------------------
// Name:		operator=
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KmString& KmString::operator=(const KmString&	other)
{
	if	( &other != this )
	{
		copy( other.getData() );
	}

	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator=
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KmString& KmString::operator=(KmString&&	other)
{
	if	( &other != this )
	{
		delete[] _pcBuffer;

		_pcBuffer = other._pcBuffer;
		_uiLength = other._uiLength;

		other._pcBuffer = NULL;
		other._uiLength = 0;
	}

	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		copy
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	KmString::copy(const char*	pcData)
{
	delete[] _pcBuffer;

	if	( pcData )
	{
		_uiLength = (uint32)strlen( pcData );
		_pcBuffer = new char[_uiLength+1];

		strcpy_s( _pcBuffer, _uiLength + 1, pcData );
	}
}

//-----------------------------------------------------------------------------
// Name:		append
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	KmString::append(const char*	pcData)
{
	uint32 uiDataLength = (uint32)strlen( pcData );

	if	( uiDataLength > 0 )
	{
		uint32	uiNewLength	= _uiLength + uiDataLength;
		char*	pcBuffer	= new char[uiNewLength+1];

		strcpy_s( pcBuffer, uiNewLength + 1, _pcBuffer );
		strcat_s( pcBuffer, uiNewLength + 1, pcData );

		delete[] _pcBuffer;

		_uiLength	= uiNewLength;
		_pcBuffer	= pcBuffer;
	}
}

//-----------------------------------------------------------------------------
// Name:		join
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KmString KmString::join(const char*	pcSourceData1, 
						const char*	pcSourceData2)
{
	KmString result( KmString::_nullString );

	result._uiLength = (uint32)( strlen( pcSourceData1 ) + strlen( pcSourceData2 ) );
	result._pcBuffer = new char[result._uiLength+1];

	strcpy_s( result._pcBuffer, result._uiLength + 1, pcSourceData1 );
	strcat_s( result._pcBuffer, result._uiLength + 1, pcSourceData2 );

	return	( result );
}

//-----------------------------------------------------------------------------
// Name:		operator==
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
bool KmString::operator==( const KmString&	other )
{
	return	( strcmp( _pcBuffer, other._pcBuffer ) == 0 );
}
