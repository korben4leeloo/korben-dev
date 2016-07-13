//*****************************************************************************
//
//	File:		TkString.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "TkString.h"

#include <cstring>

#include TARS_CORE_H(File/TkBinaryFile)
#include TARS_CORE_H(File/TkTextFile)

//-----------------------------------------------------------------------------
// Name:		TkString constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkString::TkString()
: _pcBuffer	( nullptr )
, _nSize	( 0 )
{
	
}

//-----------------------------------------------------------------------------
// Name:		TkString constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkString::TkString( const char* pcBuffer )
: _pcBuffer	( nullptr )
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
: _pcBuffer	( nullptr )
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
// Name:		split
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void TkString::split( const TkString& strSeparator, TkVector<TkString>& tokens )
{
	tokens.clear();

	if ( _pcBuffer )
	{
		uint32 nSeperatorSize	= strSeparator.size();
		uint32 nBufferIndexMax	= _nSize - nSeperatorSize + 1;
		uint32 nBufferIndex		= 0;
		uint32 nLastBufferIndex	= 0;

		while ( nBufferIndex <= nBufferIndexMax )
		{
			if ( ( nBufferIndex == nBufferIndexMax ) || ( strncmp( &_pcBuffer[nBufferIndex], strSeparator._pcBuffer, nSeperatorSize ) == 0 ) )
			{
				TkString strToken = extract( nLastBufferIndex, nBufferIndex );

				if	( strToken.isEmpty() == false )
				{
					tokens.pushBack( strToken );
				}

				nLastBufferIndex = nBufferIndex + nSeperatorSize;
			}

			nBufferIndex++;
		}
	}
}

//-----------------------------------------------------------------------------
// Name:		extract
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkString TkString::extract( const uint32 nStartPos, const int32 nEndPos )
{
	TkString strResult;

	if	( nStartPos < _nSize )
	{
		int32 nExtractSize = ( ( nEndPos == -1 ) || ( nEndPos > _nSize ) ) ? ( _nSize - nStartPos ) : ( nEndPos - nStartPos );
		TARS_ASSERT( nExtractSize >= 0 );

		if	( nExtractSize > 0 )
		{
			strResult._nSize	= nExtractSize;
			strResult._pcBuffer	= new char[nExtractSize+1];

			memcpy( strResult._pcBuffer, &_pcBuffer[nStartPos], nExtractSize );
			strResult._pcBuffer[nExtractSize] = '\0';
		}
	}

	return ( strResult );
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

			// No need to add the escape character, strcpy copies it
			strcpy( _pcBuffer, pcBuffer );
		}
	}
}

//-----------------------------------------------------------------------------
// Name:		operator==
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

//-----------------------------------------------------------------------------
// Name:		operator!=
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
bool operator!=( const TkString& lhs, const TkString& rhs )
{
	return ( !( lhs == rhs ) );
}

//-----------------------------------------------------------------------------
// Name:		operator+
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkString operator+( const TkString& lhs, const TkString& rhs )
{
	TkString strResult;

	if	( lhs._nSize == 0 )
	{
		strResult = rhs;
	}
	else if	( rhs._nSize == 0 )
	{
		strResult = lhs;
	}
	else
	{
		strResult._nSize	= lhs._nSize + rhs._nSize;
		strResult._pcBuffer	= new char[strResult._nSize+1];

		// No need to add the escape character, strcpy copies it
		strcpy( strResult._pcBuffer, lhs._pcBuffer );
		strcpy( strResult._pcBuffer + lhs._nSize, rhs._pcBuffer );
	}

	return ( strResult );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkBinaryFile& operator<<( TkBinaryFile& file, const TkString& s )
{
	file << s.size();
	fwrite( s.buffer(), 1, s.size(), file._pFile );
	return ( file );
}

//-----------------------------------------------------------------------------
// Name:		read
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const TkBinaryFile& operator>>( const TkBinaryFile& file, TkString& s )
{
	s.clear();

	file >> s._nSize;

	s._pcBuffer = new char[s._nSize+1];
	fread( s._pcBuffer, 1, s._nSize, file._pFile );
	s._pcBuffer[s._nSize] = '\0';

	return ( file );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkTextFile& operator<<( TkTextFile& file, const TkString& s )
{
	fputs( s.buffer(), file._pFile );
	file._nSize = ftell( file._pFile );
	return ( file );
}

//-----------------------------------------------------------------------------
// Name:		read
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const TkTextFile& operator>>( const TkTextFile& file, TkString& s )
{
	s.clear();

	file >> s._pcBuffer;
	s._nSize = (uint32)strlen( s._pcBuffer );

	return ( file );
}
