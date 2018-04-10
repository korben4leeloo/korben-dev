//*****************************************************************************
//
//	File:		QmString.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "QmString.h"

#include <cstring>

#include QUANTUM_CORE_H(File/QmBinaryFile)
#include QUANTUM_CORE_H(File/QmTextFile)

//-----------------------------------------------------------------------------
// Name:		QmString constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmString::QmString()
: _pcBuffer	( nullptr )
, _nSize	( 0 )
{
	
}

//-----------------------------------------------------------------------------
// Name:		QmString constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmString::QmString( const char* pcBuffer )
: _pcBuffer	( nullptr )
, _nSize	( 0 )
{
	copy( pcBuffer );
}

//-----------------------------------------------------------------------------
// Name:		QmString constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmString::QmString( const QmString& rhs )
: _pcBuffer	( nullptr )
, _nSize	( 0 )
{
	copy( rhs._pcBuffer );
}

//-----------------------------------------------------------------------------
// Name:		QmString destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmString::~QmString()
{
	clear();
}

//-----------------------------------------------------------------------------
// Name:		split
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void QmString::split( const QmString& strSeparator, QmVector<QmString>& tokens )
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
				QmString strToken = extract( nLastBufferIndex, nBufferIndex );

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
QmString QmString::extract( const uint32 nStartPos, const int32 nEndPos )
{
	QmString strResult;

	if	( nStartPos < _nSize )
	{
		int32 nExtractSize = ( ( nEndPos == -1 ) || ( nEndPos > (int32)_nSize ) ) ? ( (int32)_nSize - nStartPos ) : ( nEndPos - nStartPos );
		QUANTUM_ASSERT( nExtractSize >= 0 );

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
QmString& QmString::operator=( const QmString& rhs )
{
	copy( rhs._pcBuffer );
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		copy
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void QmString::copy( const char* pcBuffer )
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
bool operator==( const QmString& lhs, const QmString& rhs )
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
bool operator!=( const QmString& lhs, const QmString& rhs )
{
	return ( !( lhs == rhs ) );
}

//-----------------------------------------------------------------------------
// Name:		operator+
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmString operator+( const QmString& lhs, const QmString& rhs )
{
	QmString strResult;

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
QmBinaryFile& operator<<( QmBinaryFile& file, const QmString& s )
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
const QmBinaryFile& operator>>( const QmBinaryFile& file, QmString& s )
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
QmTextFile& operator<<( QmTextFile& file, const QmString& s )
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
const QmTextFile& operator>>( const QmTextFile& file, QmString& s )
{
	s.clear();

	file >> s._pcBuffer;
	s._nSize = (uint32)strlen( s._pcBuffer );

	return ( file );
}
