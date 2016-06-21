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
public:
							TkBinaryFile();
							~TkBinaryFile();

	void					open( const TkString& strFileName, const TARS_FILE_MODE eFileMode = TARS_FILE_MODE_IN_OUT_CREATE );
	void					close();

	// Stream operators	
	inline TkBinaryFile&	operator<<( const bool b );
	inline TkBinaryFile&	operator<<( const char c );
	inline TkBinaryFile&	operator<<( const int8 n );
	inline TkBinaryFile&	operator<<( const int16 n );
	inline TkBinaryFile&	operator<<( const int32 n );
	inline TkBinaryFile&	operator<<( const int64 n );
	inline TkBinaryFile&	operator<<( const uint8 n );
	inline TkBinaryFile&	operator<<( const uint16 n );
	inline TkBinaryFile&	operator<<( const uint32 n );
	inline TkBinaryFile&	operator<<( const uint64 n );
	inline TkBinaryFile&	operator<<( const float f );
	inline TkBinaryFile&	operator<<( const double d );
	inline TkBinaryFile&	operator<<( const char* pcData );
	inline TkBinaryFile&	operator<<( const TkString& strData );

private:
	FILE*					_pFile;

	template<typename T>
	TkBinaryFile&			internalWrite( const T& value );

	static const char*		_pcFileMode[TARS_FILE_MODE_COUNT];

private:
};

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
	char buf[256];

	sprintf( buf, "%d", n );
	(*this) << buf;

	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkBinaryFile& TkBinaryFile::operator<<( const uint8 n )
{
	char buf[256];

	sprintf( buf, "%u", n );
	(*this) << buf;

	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkBinaryFile& TkBinaryFile::operator<<( const uint16 n )
{
	char buf[256];

	sprintf( buf, "%u", n );
	(*this) << buf;

	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkBinaryFile& TkBinaryFile::operator<<( const uint32 n )
{
	char buf[256];

	sprintf( buf, "%u", n );
	(*this) << buf;

	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkBinaryFile& TkBinaryFile::operator<<( const uint64 n )
{
	char buf[256];

	sprintf( buf, "%u", n );
	(*this) << buf;

	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkBinaryFile& TkBinaryFile::operator<<( const float f )
{
	char buf[256];

	sprintf( buf, "%f", f );
	(*this) << buf;

	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkBinaryFile& TkBinaryFile::operator<<( const double d )
{
	char buf[256];

	sprintf( buf, "%f", d );
	(*this) << buf;

	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkBinaryFile& TkBinaryFile::operator<<( const char* pcData )
{
	fputs( pcData, _pFile );
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkBinaryFile& TkBinaryFile::operator<<( const TkString& strData )
{
	fputs( strData.buffer(), _pFile );
	return ( *this );
}

#endif