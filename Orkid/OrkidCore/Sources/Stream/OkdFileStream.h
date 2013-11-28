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
#include <fstream>

class OkdString;
class OkdXmlDocument;
class OkdMatrix4f;

class OkdFileStream
{
public:
	enum OrkidFileOpenMode
	{
		OpenModeIn		= 1 << 0,
		OpenModeOut		= 1 << 1,
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
	OkdFileStream&			operator<<( const OkdMatrix4f& m );

	inline OkdFileStream&	operator>>( bool& b );
	inline OkdFileStream&	operator>>( char& c );
	inline OkdFileStream&	operator>>( unsigned char& c );
	inline OkdFileStream&	operator>>( short& s );
	inline OkdFileStream&	operator>>( unsigned short& s );
	inline OkdFileStream&	operator>>( int& n );
	inline OkdFileStream&	operator>>( unsigned int& n );
	inline OkdFileStream&	operator>>( long& l );
	inline OkdFileStream&	operator>>( unsigned long& l );
	inline OkdFileStream&	operator>>( float& f );
	inline OkdFileStream&	operator>>( double& d );
	OkdFileStream&			operator>>( OkdString& str );
	OkdFileStream&			operator>>( OkdMatrix4f& m );

	static bool				exist( const OkdString& strFileName );
	static bool				dirExist( const OkdString& strDirName );
	static uint32			length( const OkdString& strFileName );

private:
	template<typename T>
	void					genericWrite( const T& value );
	template<typename T>
	void					genericRead( T& value );

	std::fstream			_fs;
	bool					_bBinary;
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

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator<<(const bool b)
{
	genericWrite<bool>( b );
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator<<(const char c)
{
	genericWrite<char>( c );
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator<<(const unsigned char c)
{
	genericWrite<unsigned char>( c );
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator<<(const short s)
{
	genericWrite<short>( s );
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator<<(const unsigned short s)
{
	//_fs << s;
	genericWrite<unsigned short>( s );
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator<<(const int n)
{
	genericWrite<int>( n );
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator<<(const unsigned int n)
{
	genericWrite<unsigned int>( n );
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator<<(const long l)
{
	genericWrite<long>( l );
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator<<(const unsigned long l)
{
	genericWrite<unsigned long>( l );
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator<<(const float f)
{
	genericWrite<float>( f );
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator<<(const double d)
{
	genericWrite<double>( d );
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

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator>>(bool& b)
{
	genericRead<bool>( b );
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator>>(char& c)
{
	genericRead<char>( c );
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator>>(unsigned char& c)
{
	genericRead<unsigned char>( c );
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator>>(short& s)
{
	genericRead<short>( s );
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator>>(unsigned short& s)
{
	genericRead<unsigned short>( s );
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator>>(int& n)
{
	genericRead<int>( n );
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator>>(unsigned int& n)
{
	genericRead<unsigned int>( n );
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator>>(long& l)
{
	genericRead<long>( l );
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator>>(unsigned long& l)
{
	genericRead<unsigned long>( l );
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator>>(float& f)
{
	genericRead<float>( f );
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator>>
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator>>(double& d)
{
	genericRead<double>( d );
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		genericWrite
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<typename T>
void OkdFileStream::genericWrite(const T&	value)
{
	if	( _bBinary )
	{
		write( (const char*)&value, sizeof(T) );
	}
	else
	{
		_fs << value;
	}
}

//-----------------------------------------------------------------------------
// Name:		genericRead
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<typename T>
void OkdFileStream::genericRead(T&	value)
{
	if	( _bBinary )
	{
		read( (char*)&value, sizeof(T) );
	}
	else
	{
		_fs >> value;
	}
}

#endif