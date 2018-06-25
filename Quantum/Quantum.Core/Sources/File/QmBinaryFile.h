//*****************************************************************************
//
//	Class:		QmBinaryFile
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __QUANTUM_CORE_BINARY_FILE_H__
#define __QUANTUM_CORE_BINARY_FILE_H__

#include "Root.h"

#include <cstdio>

class QmBinaryFile
{
	friend QmBinaryFile& operator<<( QmBinaryFile& file, const QmString& s );
	friend const QmBinaryFile& operator>>( const QmBinaryFile& file, QmString& s );

public:
												QmBinaryFile();
												~QmBinaryFile();

	void										open( const QmString& strFileName, const QUANTUM_FILE_MODE eFileMode = QUANTUM_FILE_MODE_IN_OUT_CREATE );
	void										close();

	// Stream operators ( input )
	inline QmBinaryFile&						operator<<( const bool b );
	inline QmBinaryFile&						operator<<( const char c );
	QmBinaryFile&								operator<<( const char* pcData );

	inline QmBinaryFile&						operator<<( const int8 n );
	inline QmBinaryFile&						operator<<( const int16 n );
	inline QmBinaryFile&						operator<<( const int32 n );
	inline QmBinaryFile&						operator<<( const int64 n );
	inline QmBinaryFile&						operator<<( const uint8 n );
	inline QmBinaryFile&						operator<<( const uint16 n );
	inline QmBinaryFile&						operator<<( const uint32 n );
	inline QmBinaryFile&						operator<<( const uint64 n );
	inline QmBinaryFile&						operator<<( const float f );
	inline QmBinaryFile&						operator<<( const double d );

	// Stream operators ( output )
	inline const QmBinaryFile&					operator>>( bool& b ) const;
	inline const QmBinaryFile&					operator>>( char& c ) const;
	inline const QmBinaryFile&					operator>>( char*& pcData ) const;

	inline const QmBinaryFile&					operator>>( int8& n ) const;
	inline const QmBinaryFile&					operator>>( int16& n ) const;
	inline const QmBinaryFile&					operator>>( int32& n ) const;
	inline const QmBinaryFile&					operator>>( int64& n ) const;
	inline const QmBinaryFile&					operator>>( uint8& n ) const;
	inline const QmBinaryFile&					operator>>( uint16& n ) const;
	inline const QmBinaryFile&					operator>>( uint32& n ) const;
	inline const QmBinaryFile&					operator>>( uint64& n ) const;
	inline const QmBinaryFile&					operator>>( float& f ) const;
	inline const QmBinaryFile&					operator>>( double& d ) const;

private:
	template<typename T> QmBinaryFile&			internalWrite( const T& value );
	template<typename T> const QmBinaryFile&	internalRead( T& value ) const;

	FILE*										_pFile;

	static const char*							_pcFileMode[QUANTUM_FILE_MODE_COUNT];
};

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmBinaryFile& QmBinaryFile::operator<<( const bool b )
{
	(*this) << (char)( b ? 1 : 0 );
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmBinaryFile& QmBinaryFile::operator<<( const char c )
{
	putc( c, _pFile );
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmBinaryFile& QmBinaryFile::operator<<( const int8 n )
{
	putc( n, _pFile );
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmBinaryFile& QmBinaryFile::operator<<( const int16 n )
{
	return ( internalWrite( n ) );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmBinaryFile& QmBinaryFile::operator<<( const int32 n )
{
	return ( internalWrite( n ) );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmBinaryFile& QmBinaryFile::operator<<( const int64 n )
{
	return ( internalWrite( n ) );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmBinaryFile& QmBinaryFile::operator<<( const uint8 n )
{
	return ( internalWrite( n ) );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmBinaryFile& QmBinaryFile::operator<<( const uint16 n )
{
	return ( internalWrite( n ) );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmBinaryFile& QmBinaryFile::operator<<( const uint32 n )
{
	return ( internalWrite( n ) );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmBinaryFile& QmBinaryFile::operator<<( const uint64 n )
{
	return ( internalWrite( n ) );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmBinaryFile& QmBinaryFile::operator<<( const float f )
{
	return ( internalWrite( f ) );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmBinaryFile& QmBinaryFile::operator<<( const double d )
{
	return ( internalWrite( d ) );
}

//-----------------------------------------------------------------------------
// Name:		internalWrite
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<typename T>
QmBinaryFile& QmBinaryFile::internalWrite( const T& value )
{
	fwrite( &value, sizeof(T), 1, _pFile );
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const QmBinaryFile& QmBinaryFile::operator>>( bool& b ) const
{
	(*this) >> (char&)b;
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const QmBinaryFile& QmBinaryFile::operator>>( char& c ) const
{
	c = (char)getc( _pFile );
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const QmBinaryFile& QmBinaryFile::operator>>( char*& pcData ) const
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
const QmBinaryFile& QmBinaryFile::operator>>( int8& n ) const
{
	n = (int8)getc( _pFile );
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const QmBinaryFile& QmBinaryFile::operator>>( int16& n ) const
{
	return ( internalRead( n ) );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const QmBinaryFile& QmBinaryFile::operator>>( int32& n ) const
{
	return ( internalRead( n ) );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const QmBinaryFile& QmBinaryFile::operator>>( int64& n ) const
{
	return ( internalRead( n ) );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const QmBinaryFile& QmBinaryFile::operator>>( uint8& n ) const
{
	return ( internalRead( n ) );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const QmBinaryFile& QmBinaryFile::operator>>( uint16& n ) const
{
	return ( internalRead( n ) );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const QmBinaryFile& QmBinaryFile::operator>>( uint32& n ) const
{
	return ( internalRead( n ) );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const QmBinaryFile& QmBinaryFile::operator>>( uint64& n ) const
{
	return ( internalRead( n ) );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const QmBinaryFile& QmBinaryFile::operator>>( float& f ) const
{
	return ( internalRead( f ) );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const QmBinaryFile& QmBinaryFile::operator>>( double& d ) const
{
	return ( internalRead( d ) );
}

//-----------------------------------------------------------------------------
// Name:		internalRead
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<typename T>
const QmBinaryFile& QmBinaryFile::internalRead( T& value ) const
{
	fread( &value, sizeof(T), 1, _pFile );
	return ( *this );
}

#endif