//*****************************************************************************
//
//	File:		OkdFileStream.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdFileStream.h"

#include	<ios>
#include	<sys/stat.h>
#include	ORKID_CORE_H(String/OkdString)

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

	if	( nOpenMode & OpenModeIn )		nIosOpenMode &= std::ios::in;
	if	( nOpenMode & OpenModeOut )		nIosOpenMode &= std::ios::out;
	if	( nOpenMode & OpenModeAtEnd )	nIosOpenMode &= std::ios::ate;
	if	( nOpenMode & OpenModeAppend )	nIosOpenMode &= std::ios::app;
	if	( nOpenMode & OpenModeTrunc )	nIosOpenMode &= std::ios::trunc;
	if	( nOpenMode & OpenModeBinary )	nIosOpenMode &= std::ios::binary;

	_fs.open( strFileName, nIosOpenMode );
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
// Name:		exist
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
bool	OkdFileStream::exist(const OkdString&	strFileName)
{
	struct stat statBuf;

	int nResult = stat( strFileName, &statBuf );
	return	( nResult != -1 );
}
