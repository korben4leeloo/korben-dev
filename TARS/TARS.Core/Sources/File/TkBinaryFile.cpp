//*****************************************************************************
//
//	File:		TkBinaryFile.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "TkBinaryFile.h"
#include <cstring>

const char* TkBinaryFile::_pcFileMode[TARS_FILE_MODE_COUNT] = { "rb", "wb", "ab", "r+b", "w+b", "a+b" };

//-----------------------------------------------------------------------------
// Name:		TkBinaryFile constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkBinaryFile::TkBinaryFile()
: _pFile( nullptr )
{
	
}

//-----------------------------------------------------------------------------
// Name:		TkBinaryFile destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkBinaryFile::~TkBinaryFile()
{
	close();
}

//-----------------------------------------------------------------------------
// Name:		open
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void TkBinaryFile::open( const TkString& strFileName, const TARS_FILE_MODE eFileMode )
{
	_pFile = fopen( strFileName.buffer(), _pcFileMode[eFileMode] );
}

//-----------------------------------------------------------------------------
// Name:		close
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void TkBinaryFile::close()
{
	if	( _pFile )
	{
		fclose( _pFile );
		_pFile = nullptr;
	}
}

//-----------------------------------------------------------------------------
// Name:		operator<<
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkBinaryFile& TkBinaryFile::operator<<( const char* pcData )
{
	uint32 uiSize = (uint32)strlen( pcData );

	(*this) << uiSize;
	fwrite( pcData, sizeof(char), uiSize, _pFile );
	return ( *this );
}
