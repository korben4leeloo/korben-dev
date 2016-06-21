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
public:
						TkTextFile();
						~TkTextFile();

	void				open( const TkString& strFileName, const TARS_FILE_MODE eFileMode = TARS_FILE_MODE_IN_OUT_CREATE );
	void				close();

	// Stream operators	
	inline TkTextFile&	operator<<( const bool b );
	inline TkTextFile&	operator<<( const char c );
	inline TkTextFile&	operator<<( const int8 n );
	inline TkTextFile&	operator<<( const int16 n );
	inline TkTextFile&	operator<<( const int32 n );
	inline TkTextFile&	operator<<( const int64 n );
	inline TkTextFile&	operator<<( const uint8 n );
	inline TkTextFile&	operator<<( const uint16 n );
	inline TkTextFile&	operator<<( const uint32 n );
	inline TkTextFile&	operator<<( const uint64 n );
	inline TkTextFile&	operator<<( const float f );
	inline TkTextFile&	operator<<( const double d );
	inline TkTextFile&	operator<<( const char* pcData );
	inline TkTextFile&	operator<<( const TkString& strData );

private:
	FILE*				_pFile;

	static const char*	_pcFileMode[TARS_FILE_MODE_COUNT];

private:
};

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkTextFile& TkTextFile::operator<<( const bool b )
{
	(*this) << ( b ? "true" : "false" );
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
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkTextFile& TkTextFile::operator<<( const int8 n )
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
TkTextFile& TkTextFile::operator<<( const int16 n )
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
TkTextFile& TkTextFile::operator<<( const int32 n )
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
TkTextFile& TkTextFile::operator<<( const int64 n )
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
TkTextFile& TkTextFile::operator<<( const uint8 n )
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
TkTextFile& TkTextFile::operator<<( const uint16 n )
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
TkTextFile& TkTextFile::operator<<( const uint32 n )
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
TkTextFile& TkTextFile::operator<<( const uint64 n )
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
TkTextFile& TkTextFile::operator<<( const float f )
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
TkTextFile& TkTextFile::operator<<( const double d )
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
TkTextFile& TkTextFile::operator<<( const char* pcData )
{
	fputs( pcData, _pFile );
	return ( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkTextFile& TkTextFile::operator<<( const TkString& strData )
{
	fputs( strData.buffer(), _pFile );
	return ( *this );
}

#endif