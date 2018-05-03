//*****************************************************************************
//
//	Class:		QmTextFile
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __QUANTUM_CORE_TK_TEXT_FILE_H__
#define __QUANTUM_CORE_TK_TEXT_FILE_H__

#include "Root.h"

#include <cstdio>

class QmTextFile
{
	friend QmTextFile& operator<<( QmTextFile& file, const QmString& s );
	friend const QmTextFile& operator>>( const QmTextFile& file, QmString& s );

public:
								QmTextFile();
								~QmTextFile();

	void						open( const QmString& strFileName, const QUANTUM_FILE_MODE eFileMode = QUANTUM_FILE_MODE_IN_OUT_CREATE );
	void						close();

	// Stream operators ( input )
	inline QmTextFile&			operator<<( const bool b );
	inline QmTextFile&			operator<<( const char c );
	inline QmTextFile&			operator<<( const char* pcData );

	inline QmTextFile&			operator<<( const int8 n );
	inline QmTextFile&			operator<<( const int16 n );
	inline QmTextFile&			operator<<( const int32 n );
	inline QmTextFile&			operator<<( const int64 n );
	inline QmTextFile&			operator<<( const uint8 n );
	inline QmTextFile&			operator<<( const uint16 n );
	inline QmTextFile&			operator<<( const uint32 n );
	inline QmTextFile&			operator<<( const uint64 n );
	inline QmTextFile&			operator<<( const float f );
	inline QmTextFile&			operator<<( const double d );

	// Stream operators ( output )
	inline const QmTextFile&	operator>>( bool& b ) const;
	inline const QmTextFile&	operator>>( char& c ) const;
	inline const QmTextFile&	operator>>( char*& pcData ) const;

	inline const QmTextFile&	operator>>( int8& n ) const;
	inline const QmTextFile&	operator>>( int16& n ) const;
	inline const QmTextFile&	operator>>( int32& n ) const;
	inline const QmTextFile&	operator>>( int64& n ) const;
	inline const QmTextFile&	operator>>( uint8& n ) const;
	inline const QmTextFile&	operator>>( uint16& n ) const;
	inline const QmTextFile&	operator>>( uint32& n ) const;
	inline const QmTextFile&	operator>>( uint64& n ) const;
	inline const QmTextFile&	operator>>( float& f ) const;
	inline const QmTextFile&	operator>>( double& d ) const;

private:
	void						trimWhitespaceCharacters() const;

	FILE*						_pFile;
	uint64						_nSize;

	static const char*			_pcFileMode[QUANTUM_FILE_MODE_COUNT];

private:
};

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmTextFile& QmTextFile::operator<<( const bool b )
{
	(*this) << (char)b;
	_nSize = ftell( _pFile );
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmTextFile& QmTextFile::operator<<( const char c )
{
	putc( c, _pFile );
	_nSize = ftell( _pFile );
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmTextFile& QmTextFile::operator<<( const char* pcData )
{
	fputs( pcData, _pFile );
	_nSize = ftell( _pFile );
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmTextFile& QmTextFile::operator<<( const int8 n )
{
	fprintf( _pFile, "%d", n );
	_nSize = ftell( _pFile );
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmTextFile& QmTextFile::operator<<( const int16 n )
{
	fprintf( _pFile, "%d", n );
	_nSize = ftell( _pFile );
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmTextFile& QmTextFile::operator<<( const int32 n )
{
	fprintf( _pFile, "%d", n );
	_nSize = ftell( _pFile );
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmTextFile& QmTextFile::operator<<( const int64 n )
{
	fprintf( _pFile, "%lld", n );
	_nSize = ftell( _pFile );
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmTextFile& QmTextFile::operator<<( const uint8 n )
{
	fprintf( _pFile, "%u", n );
	_nSize = ftell( _pFile );
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmTextFile& QmTextFile::operator<<( const uint16 n )
{
	fprintf( _pFile, "%u", n );
	_nSize = ftell( _pFile );
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmTextFile& QmTextFile::operator<<( const uint32 n )
{
	fprintf( _pFile, "%u", n );
	_nSize = ftell( _pFile );
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmTextFile& QmTextFile::operator<<( const uint64 n )
{
	fprintf( _pFile, "%llu", n );
	_nSize = ftell( _pFile );
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmTextFile& QmTextFile::operator<<( const float f )
{
	fprintf( _pFile, "%.9f", f );
	_nSize = ftell( _pFile );
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmTextFile& QmTextFile::operator<<( const double d )
{
	fprintf( _pFile, "%.17f", d );
	_nSize = ftell( _pFile );
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const QmTextFile& QmTextFile::operator>>( bool& b ) const
{
	(*this) >> (char&)b;
	trimWhitespaceCharacters();
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const QmTextFile& QmTextFile::operator>>( char& c ) const
{
	c = (char)getc( _pFile );
	trimWhitespaceCharacters();
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const QmTextFile& QmTextFile::operator>>( char*& pcData ) const
{
	int32	nStartPos	= ftell( _pFile );
	char	c			= fgetc( _pFile );

	while	( !feof( _pFile ) && ( c != '\n' ) )
	{
		c = fgetc( _pFile );
	}

	int32 nSize = ftell( _pFile ) - nStartPos - 1;

	if	( nSize > 0 )
	{
		pcData = new char[nSize];
		fseek( _pFile, nStartPos, SEEK_SET );
		fread( pcData, 1, nSize, _pFile );
		pcData[nSize-1] = '\0';
	}
	else
	{
		pcData = nullptr;
	}

	trimWhitespaceCharacters();
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const QmTextFile& QmTextFile::operator>>( int8& n ) const
{
	n = (int8)getc( _pFile );
	trimWhitespaceCharacters();
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const QmTextFile& QmTextFile::operator>>( int16& n ) const
{
	fscanf( _pFile, "%hd", &n );
	trimWhitespaceCharacters();
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const QmTextFile& QmTextFile::operator>>( int32& n ) const
{
	fscanf( _pFile, "%d", &n );
	trimWhitespaceCharacters();
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const QmTextFile& QmTextFile::operator>>( int64& n ) const
{
	fscanf( _pFile, "%lld", &n );
	trimWhitespaceCharacters();
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const QmTextFile& QmTextFile::operator>>( uint8& n ) const
{
	fscanf( _pFile, "%hhd", &n );
	trimWhitespaceCharacters();
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const QmTextFile& QmTextFile::operator>>( uint16& n ) const
{
	fscanf( _pFile, "%hd", &n );
	trimWhitespaceCharacters();
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const QmTextFile& QmTextFile::operator>>( uint32& n ) const
{
	fscanf( _pFile, "%d", &n );
	trimWhitespaceCharacters();
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const QmTextFile& QmTextFile::operator>>( uint64& n ) const
{
	fscanf( _pFile, "%lld", &n );
	trimWhitespaceCharacters();
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const QmTextFile& QmTextFile::operator>>( float& f ) const
{
	fscanf( _pFile, "%f", &f );
	trimWhitespaceCharacters();
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const QmTextFile& QmTextFile::operator>>( double& d ) const
{
	fscanf( _pFile, "%lf", &d );
	trimWhitespaceCharacters();
	return ( *this );
}

#endif