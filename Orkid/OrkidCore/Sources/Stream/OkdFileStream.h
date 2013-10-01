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
class OkdXmlDocument;

class OkdFileStream
{
public:
	enum OrkidFileOpenMode
	{
		OpenModeIn		= 1 << 0,
		OpenModeOut	= 1 << 1,
		OpenModeAtEnd	= 1 << 2,
		OpenModeAppend	= 1 << 3,
		OpenModeTrunc	= 1 << 4,
		OpenModeBinary	= 1 << 5,
	
		OpenModeInOut	= OpenModeIn | OpenModeOut
	};

							OkdFileStream();
							OkdFileStream( const OkdString& strFileName, const int nOpenMode );
							~OkdFileStream();

	inline void				close();
	uint32					length();
	inline bool				isOpen() const;

	inline void				read( char* pcBuffer, const uint uiBufferSize );
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
	inline OkdFileStream&	operator<<( const char* pBuffer );
	OkdFileStream&			operator<<( const OkdString& str );
	OkdFileStream&			operator<<( const OkdXmlDocument& xmlDoc );

	static bool				exist( const OkdString& strFileName );

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
// Name:		read
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdFileStream::read(char*		pcBuffer, 
							const uint	uiBufferSize)
{
	_fs.read( pcBuffer, uiBufferSize );
}

//-----------------------------------------------------------------------------
// Name:		isOpen
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
bool	OkdFileStream::isOpen() const
{
	return	( _fs.is_open() );
}

////-----------------------------------------------------------------------------
//// Name:		buffer
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//const char*	OkdFileStream::buffer() const
//{
//	return	( _fs.rdbuf()-> );
//}

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

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator<<(const char* pBuffer)
{
	_fs << pBuffer;
	return	( *this );
}

////-----------------------------------------------------------------------------
//// Name:		exist
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//bool	OkdFileStream::exist()
//{
//	_fs.
//}

#endif