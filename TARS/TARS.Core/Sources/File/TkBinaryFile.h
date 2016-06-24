//*****************************************************************************
//
//	Class:		TkBinaryFile
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_CORE_TK_BINARY_FILE_H__
#define __TARS_CORE_TK_BINARY_FILE_H__

#include "Root.h"

#include <cstdio>

class TkBinaryFile
{
	friend TkBinaryFile& operator<<( TkBinaryFile& file, const TkString& s );
	friend const TkBinaryFile& operator>>( const TkBinaryFile& file, TkString& s );

public:
												TkBinaryFile();
												~TkBinaryFile();

	void										open( const TkString& strFileName, const TARS_FILE_MODE eFileMode = TARS_FILE_MODE_IN_OUT_CREATE );
	void										close();

	// Stream operators ( input )
	inline TkBinaryFile&						operator<<( const bool b );
	inline TkBinaryFile&						operator<<( const char c );
	TkBinaryFile&								operator<<( const char* pcData );

	inline TkBinaryFile&						operator<<( const int8 n );
	inline TkBinaryFile&						operator<<( const int16 n );
	inline TkBinaryFile&						operator<<( const int32 n );
	inline TkBinaryFile&						operator<<( const int64 n );
	inline TkBinaryFile&						operator<<( const uint8 n );
	inline TkBinaryFile&						operator<<( const uint16 n );
	inline TkBinaryFile&						operator<<( const uint32 n );
	inline TkBinaryFile&						operator<<( const uint64 n );
	inline TkBinaryFile&						operator<<( const float f );
	inline TkBinaryFile&						operator<<( const double d );

	// Stream operators ( output )
	inline const TkBinaryFile&					operator>>( bool& b ) const;
	inline const TkBinaryFile&					operator>>( char& c ) const;
	inline const TkBinaryFile&					operator>>( char*& pcData ) const;

	inline const TkBinaryFile&					operator>>( int8& n ) const;
	inline const TkBinaryFile&					operator>>( int16& n ) const;
	inline const TkBinaryFile&					operator>>( int32& n ) const;
	inline const TkBinaryFile&					operator>>( int64& n ) const;
	inline const TkBinaryFile&					operator>>( uint8& n ) const;
	inline const TkBinaryFile&					operator>>( uint16& n ) const;
	inline const TkBinaryFile&					operator>>( uint32& n ) const;
	inline const TkBinaryFile&					operator>>( uint64& n ) const;
	inline const TkBinaryFile&					operator>>( float& f ) const;
	inline const TkBinaryFile&					operator>>( double& d ) const;

private:
	template<typename T> TkBinaryFile&			internalWrite( const T& value );
	template<typename T> const TkBinaryFile&	internalRead( T& value ) const;

	FILE*										_pFile;

	static const char*							_pcFileMode[TARS_FILE_MODE_COUNT];
};

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkBinaryFile& TkBinaryFile::operator<<( const bool b )
{
	(*this) << (char)( b ? 1 : 0 );
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkBinaryFile& TkBinaryFile::operator<<( const char c )
{
	putc( c, _pFile );
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkBinaryFile& TkBinaryFile::operator<<( const int8 n )
{
	putc( n, _pFile );
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkBinaryFile& TkBinaryFile::operator<<( const int16 n )
{
	return ( internalWrite( n ) );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkBinaryFile& TkBinaryFile::operator<<( const int32 n )
{
	return ( internalWrite( n ) );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkBinaryFile& TkBinaryFile::operator<<( const int64 n )
{
	return ( internalWrite( n ) );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkBinaryFile& TkBinaryFile::operator<<( const uint8 n )
{
	return ( internalWrite( n ) );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkBinaryFile& TkBinaryFile::operator<<( const uint16 n )
{
	return ( internalWrite( n ) );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkBinaryFile& TkBinaryFile::operator<<( const uint32 n )
{
	return ( internalWrite( n ) );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkBinaryFile& TkBinaryFile::operator<<( const uint64 n )
{
	return ( internalWrite( n ) );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkBinaryFile& TkBinaryFile::operator<<( const float f )
{
	return ( internalWrite( f ) );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkBinaryFile& TkBinaryFile::operator<<( const double d )
{
	return ( internalWrite( d ) );
}

//-----------------------------------------------------------------------------
// Name:		internalWrite
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<typename T>
TkBinaryFile& TkBinaryFile::internalWrite( const T& value )
{
	fwrite( &value, sizeof(T), 1, _pFile );
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const TkBinaryFile& TkBinaryFile::operator>>( bool& b ) const
{
	(*this) >> (char&)b;
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const TkBinaryFile& TkBinaryFile::operator>>( char& c ) const
{
	c = (char)getc( _pFile );
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const TkBinaryFile& TkBinaryFile::operator>>( char*& pcData ) const
{
	int nSize;
	(*this) >> nSize;

	pcData = new char[nSize+1];
	fread( pcData, 1, nSize, _pFile );
	pcData[nSize] = '\0';

	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const TkBinaryFile& TkBinaryFile::operator>>( int8& n ) const
{
	n = (int8)getc( _pFile );
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const TkBinaryFile& TkBinaryFile::operator>>( int16& n ) const
{
	return ( internalRead( n ) );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const TkBinaryFile& TkBinaryFile::operator>>( int32& n ) const
{
	return ( internalRead( n ) );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const TkBinaryFile& TkBinaryFile::operator>>( int64& n ) const
{
	return ( internalRead( n ) );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const TkBinaryFile& TkBinaryFile::operator>>( uint8& n ) const
{
	return ( internalRead( n ) );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const TkBinaryFile& TkBinaryFile::operator>>( uint16& n ) const
{
	return ( internalRead( n ) );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const TkBinaryFile& TkBinaryFile::operator>>( uint32& n ) const
{
	return ( internalRead( n ) );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const TkBinaryFile& TkBinaryFile::operator>>( uint64& n ) const
{
	return ( internalRead( n ) );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const TkBinaryFile& TkBinaryFile::operator>>( float& f ) const
{
	return ( internalRead( f ) );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const TkBinaryFile& TkBinaryFile::operator>>( double& d ) const
{
	return ( internalRead( d ) );
}

//-----------------------------------------------------------------------------
// Name:		internalRead
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<typename T>
const TkBinaryFile& TkBinaryFile::internalRead( T& value ) const
{
	fread( &value, sizeof(T), 1, _pFile );
	return ( *this );
}

#endif