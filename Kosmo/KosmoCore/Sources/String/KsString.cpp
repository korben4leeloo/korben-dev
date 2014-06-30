//*****************************************************************************
//
//	File:		KsString.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"KsString.h"

#include	<string.h>

KsString KsString::_nullString( NULL );
KsString KsString::_emptyString( "" );

//-----------------------------------------------------------------------------
// Name:		KsString constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KsString::KsString(const char*	pcData)
: _pcBuffer	( NULL )
, _uiLength	( 0 )
{
	copy( pcData );
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
	copy( other.getData() );
}

//-----------------------------------------------------------------------------
// Name:		KsString constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KsString::KsString(KsString&&	other)
{
	_pcBuffer = other._pcBuffer;
	_uiLength = other._uiLength;

	other._pcBuffer = NULL;
	other._uiLength = 0;
}

//-----------------------------------------------------------------------------
// Name:		KsString destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KsString::~KsString()
{
	if	(_pcBuffer )
	{
		delete[] _pcBuffer;
	}
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
		copy( other.getData() );
	}

	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator=
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KsString& KsString::operator=(KsString&&	other)
{
	if	( &other != this )
	{
		if	( _pcBuffer )
		{
			delete[] _pcBuffer;
		}

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
void	KsString::copy(const char*	pcData)
{
	if	( _pcBuffer )
	{
		delete[] _pcBuffer;
	}

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
void	KsString::append(const char*	pcData)
{
	uint32 uiDataLength = (uint32)strlen( pcData );

	if	( uiDataLength > 0 )
	{
		uint32	uiNewLength	= _uiLength + uiDataLength;
		char*	pcBuffer	= new char[uiNewLength+1];

		strcpy_s( pcBuffer, uiNewLength + 1, _pcBuffer );
		strcat_s( pcBuffer, uiNewLength + 1, pcData );

		if	( _pcBuffer )
		{
			delete[] _pcBuffer;
		}

		_uiLength	= uiNewLength;
		_pcBuffer	= pcBuffer;
	}
}

//-----------------------------------------------------------------------------
// Name:		join
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KsString KsString::join(const char*	pcSourceData1, 
						const char*	pcSourceData2)
{
	KsString result( KsString::_nullString );

	result._uiLength = (uint32)( strlen( pcSourceData1 ) + strlen( pcSourceData2 ) );
	result._pcBuffer = new char[result._uiLength+1];

	strcpy_s( result._pcBuffer, result._uiLength + 1, pcSourceData1 );
	strcat_s( result._pcBuffer, result._uiLength + 1, pcSourceData2 );

	return	( result );
}
