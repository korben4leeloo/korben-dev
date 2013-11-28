//*****************************************************************************
//
//	File:		OkdFileStream.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdFileStream.h"

#include	<ios>
#include	<sys/stat.h>
#include	<rapidxml/rapidxml_print.hpp>

#include	ORKID_CORE_H(String/OkdString)
#include	ORKID_CORE_H(Xml/OkdXmlDocument)
#include	ORKID_CORE_H(Math/OkdMatrix4f)

//-----------------------------------------------------------------------------
// Name:		OkdFileStream constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream::OkdFileStream()
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdFileStream constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream::OkdFileStream(const OkdString&	strFileName, 
							 const int			nOpenMode)
{
	int nIosOpenMode = 0;

	_bBinary = ( nOpenMode & OpenModeBinary ) != 0;

	if	( nOpenMode & OpenModeIn )		nIosOpenMode |= std::ios::in;
	if	( nOpenMode & OpenModeOut )		nIosOpenMode |= std::ios::out;
	if	( nOpenMode & OpenModeAtEnd )	nIosOpenMode |= std::ios::ate;
	if	( nOpenMode & OpenModeAppend )	nIosOpenMode |= std::ios::app;
	if	( nOpenMode & OpenModeTrunc )	nIosOpenMode |= std::ios::trunc;
	if	( _bBinary)						nIosOpenMode |= std::ios::binary;

	_fs.open( strFileName, nIosOpenMode );

	if	( !_fs.is_open() )
	{
		char err[1024];
		strerror_s( err, errno );
		ORKID_BREAK();
	}
}

//-----------------------------------------------------------------------------
// Name:		OkdFileStream destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream::~OkdFileStream()
{

}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator<<(const OkdString& str)
{
	_fs << str._str;
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator<<(const OkdXmlDocument& xmlDoc)
{
	_fs << xmlDoc;
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator<<(const OkdMatrix4f& m)
{
	const float* pMatrixData = m.data();
	write( (const char*)pMatrixData, sizeof(m) );

	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator>>(OkdString& str)
{
	_fs >> str._str;
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream& OkdFileStream::operator>>(OkdMatrix4f& m)
{
	float* pMatrixData = m.data();
	read( (char*)pMatrixData, sizeof(m) );

	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		exist
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
bool	OkdFileStream::exist(const OkdString&	strFileName)
{
	struct stat statBuf;

	int nResult = stat( strFileName, &statBuf );

	if	( nResult != -1 )
	{
		if	( ( statBuf.st_mode & S_IFREG ) == 0 )
		{
			nResult = -1;
		}
	}

	return	( nResult != -1 );
}

//-----------------------------------------------------------------------------
// Name:		dirExist
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
bool	OkdFileStream::dirExist(const OkdString&	strDirName)
{
	struct stat statBuf;

	int nResult = stat( strDirName, &statBuf );

	if	( nResult != -1 )
	{
		if	( ( statBuf.st_mode & S_IFDIR ) == 0 )
		{
			nResult = -1;
		}
	}

	return	( nResult != -1 );
}

//-----------------------------------------------------------------------------
// Name:		length
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
uint32	OkdFileStream::length(const OkdString&	strFileName)
{
	struct stat statBuf;

	int nResult = stat( strFileName, &statBuf );

	if	( nResult != -1 )
	{
		return	( statBuf.st_size );
	}

	return	( 0 );
}
