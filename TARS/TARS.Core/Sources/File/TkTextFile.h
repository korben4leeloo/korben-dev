//*****************************************************************************
//
//	Class:		TkTextFile
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_CORE_TK_TEXT_FILE_H__
#define __TARS_CORE_TK_TEXT_FILE_H__

#include "Root.h"

#include <cstdio>

class TkTextFile
{
	friend TkTextFile& operator<<( TkTextFile& file, const TkString& s );
	friend const TkTextFile& operator>>( const TkTextFile& file, TkString& s );

public:
								TkTextFile();
								~TkTextFile();

	void						open( const TkString& strFileName, const TARS_FILE_MODE eFileMode = TARS_FILE_MODE_IN_OUT_CREATE );
	void						close();

	// Stream operators ( input )
	inline TkTextFile&			operator<<( const bool b );
	inline TkTextFile&			operator<<( const char c );
	inline TkTextFile&			operator<<( const char* pcData );

	inline TkTextFile&			operator<<( const int8 n );
	inline TkTextFile&			operator<<( const int16 n );
	inline TkTextFile&			operator<<( const int32 n );
	inline TkTextFile&			operator<<( const int64 n );
	inline TkTextFile&			operator<<( const uint8 n );
	inline TkTextFile&			operator<<( const uint16 n );
	inline TkTextFile&			operator<<( const uint32 n );
	inline TkTextFile&			operator<<( const uint64 n );
	inline TkTextFile&			operator<<( const float f );
	inline TkTextFile&			operator<<( const double d );

	// Stream operators ( output )
	inline const TkTextFile&	operator>>( bool& b ) const;
	inline const TkTextFile&	operator>>( char& c ) const;
	inline const TkTextFile&	operator>>( char*& pcData ) const;

	inline const TkTextFile&	operator>>( int8& n ) const;
	inline const TkTextFile&	operator>>( int16& n ) const;
	inline const TkTextFile&	operator>>( int32& n ) const;
	inline const TkTextFile&	operator>>( int64& n ) const;
	inline const TkTextFile&	operator>>( uint8& n ) const;
	inline const TkTextFile&	operator>>( uint16& n ) const;
	inline const TkTextFile&	operator>>( uint32& n ) const;
	inline const TkTextFile&	operator>>( uint64& n ) const;
	inline const TkTextFile&	operator>>( float& f ) const;
	inline const TkTextFile&	operator>>( double& d ) const;

private:
	void						trimWhitespaceCharacters() const;

	FILE*						_pFile;
	uint64						_nSize;

	static const char*			_pcFileMode[TARS_FILE_MODE_COUNT];

private:
};

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkTextFile& TkTextFile::operator<<( const bool b )
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
TkTextFile& TkTextFile::operator<<( const char c )
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
TkTextFile& TkTextFile::operator<<( const char* pcData )
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
TkTextFile& TkTextFile::operator<<( const int8 n )
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
TkTextFile& TkTextFile::operator<<( const int16 n )
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
TkTextFile& TkTextFile::operator<<( const int32 n )
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
TkTextFile& TkTextFile::operator<<( const int64 n )
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
TkTextFile& TkTextFile::operator<<( const uint8 n )
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
TkTextFile& TkTextFile::operator<<( const uint16 n )
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
TkTextFile& TkTextFile::operator<<( const uint32 n )
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
TkTextFile& TkTextFile::operator<<( const uint64 n )
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
TkTextFile& TkTextFile::operator<<( const float f )
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
TkTextFile& TkTextFile::operator<<( const double d )
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
const TkTextFile& TkTextFile::operator>>( bool& b ) const
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
const TkTextFile& TkTextFile::operator>>( char& c ) const
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
const TkTextFile& TkTextFile::operator>>( char*& pcData ) const
{
	int32	nStartPos = ftell( _pFile );
	char	c;

	while	( ( ftell( _pFile ) != _nSize ) && ( _pFile->_ptr[0] != '\n' ) )
	{
		c = fgetc( _pFile );
	}

	int32 nSize = ftell( _pFile ) - nStartPos;

	if	( nSize )
	{
		pcData = new char[nSize+1];
		fseek( _pFile, nStartPos, SEEK_SET );
		fread( pcData, 1, nSize, _pFile );
		pcData[nSize] = '\0';
	}

	trimWhitespaceCharacters();
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const TkTextFile& TkTextFile::operator>>( int8& n ) const
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
const TkTextFile& TkTextFile::operator>>( int16& n ) const
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
const TkTextFile& TkTextFile::operator>>( int32& n ) const
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
const TkTextFile& TkTextFile::operator>>( int64& n ) const
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
const TkTextFile& TkTextFile::operator>>( uint8& n ) const
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
const TkTextFile& TkTextFile::operator>>( uint16& n ) const
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
const TkTextFile& TkTextFile::operator>>( uint32& n ) const
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
const TkTextFile& TkTextFile::operator>>( uint64& n ) const
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
const TkTextFile& TkTextFile::operator>>( float& f ) const
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
const TkTextFile& TkTextFile::operator>>( double& d ) const
{
	fscanf( _pFile, "%lf", &d );
	trimWhitespaceCharacters();
	return ( *this );
}

#endif