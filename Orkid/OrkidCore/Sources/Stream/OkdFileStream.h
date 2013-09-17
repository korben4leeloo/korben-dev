//*****************************************************************************
//
//	Class:		OkdFileStream
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdFileStream_h__
#define __OrkidCore_OkdFileStream_h__

#include "Root.h"

//#include	<QtCore/QDataStream>
//#include	<QtCore/QTextStream>

#include <fstream>
//typedef	std::fstream OkdFileStream;

////-----------------------------------------------------------------------------
//// Name:		operator<<
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//OkdFileStream& operator<<(OkdFileStream&	stream, 
//						  const char*		str)
//{
//	stream.write( str, strlen(str) );
//	return	( stream );
//}

//typedef QDataStream OkdBinaryStream;
//typedef QTextStream OkdTextStream;

class OkdString;

class OkdFileStream
{
public:
							OkdFileStream();
							OkdFileStream( const OkdString& strFileName, const int openMode );
							~OkdFileStream();

	inline void				close();
		
	inline void				write( const char* pcBuffer, const uint uiBufferSize );

	inline OkdFileStream&	operator<<( const bool b );
	inline OkdFileStream&	operator<<( const char c );
	inline OkdFileStream&	operator<<( const unsigned char c );
	inline OkdFileStream&	operator<<( const short s );
	inline OkdFileStream&	operator<<( const unsigned short s );
	inline OkdFileStream&	operator<<( const int n );
	inline OkdFileStream&	operator<<( const unsigned int n );
	inline OkdFileStream&	operator<<( const long l );
	inline OkdFileStream&	operator<<( const unsigned long l );
	inline OkdFileStream&	operator<<( const float f );
	inline OkdFileStream&	operator<<( const double d );
	//inline OkdFileStream&	operator<<( const char* pBuffer );
	OkdFileStream&			operator<<( const OkdString& str );

private:
	std::fstream			_fs;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		close
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdFileStream::close()
{
	_fs.close();
}

//-----------------------------------------------------------------------------
// Name:		write
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdFileStream::write(const char*	pcBuffer, 
							 const uint		uiBufferSize)
{
	_fs.write( pcBuffer, uiBufferSize );
	
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator<<(const bool b)
{
	_fs << b;
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator<<(const char c)
{
	_fs << c;
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator<<(const unsigned char c)
{
	_fs << c;
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator<<(const short s)
{
	_fs << s;
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator<<(const unsigned short s)
{
	_fs << s;
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator<<(const int n)
{
	_fs << n;
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator<<(const unsigned int n)
{
	_fs << n;
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator<<(const long l)
{
	_fs << l;
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator<<(const unsigned long l)
{
	_fs << l;
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator<<(const float f)
{
	_fs << f;
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator<<(const double d)
{
	_fs << d;
	return	( *this );
}

////-----------------------------------------------------------------------------
//// Name:		operator<<
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//OkdFileStream& OkdFileStream::operator<<(const char* pBuffer)
//{
//	_fs << pBuffer;
//	return	( *this );
//}

#endif