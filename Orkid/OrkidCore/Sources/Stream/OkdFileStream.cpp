//*****************************************************************************
//
//	File:		OkdFileStream.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdFileStream.h"

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
							 const int			openMode)
: _fs( strFileName, openMode )
{

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
