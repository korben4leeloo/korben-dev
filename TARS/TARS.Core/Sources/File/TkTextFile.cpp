//*****************************************************************************
//
//	File:		TkTextFile.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "TkTextFile.h"
#include <cctype>

const char* TkTextFile::_pcFileMode[TARS_FILE_MODE_COUNT] = { "r", "w", "a", "r+", "w+", "a+" };

//-----------------------------------------------------------------------------
// Name:		TkTextFile constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkTextFile::TkTextFile()
: _pFile( nullptr )
, _nSize( 0 )
{
	
}

//-----------------------------------------------------------------------------
// Name:		TkTextFile destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkTextFile::~TkTextFile()
{
	close();
}

//-----------------------------------------------------------------------------
// Name:		open
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void TkTextFile::open( const TkString& strFileName, const TARS_FILE_MODE eFileMode )
{
	_pFile = fopen( strFileName.buffer(), _pcFileMode[eFileMode] );

	if	( _pFile )
	{
		fseek( _pFile, 0, SEEK_END );
		_nSize = ftell( _pFile );
		fseek( _pFile, 0, SEEK_SET );
	}
}

//-----------------------------------------------------------------------------
// Name:		close
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void TkTextFile::close()
{
	if	( _pFile )
	{
		fclose( _pFile );
		_pFile = nullptr;
	}

	_nSize = 0;
}

//-----------------------------------------------------------------------------
// Name:		trimWhitespaceCharacters
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void TkTextFile::trimWhitespaceCharacters() const
{
	while ( !feof( _pFile ) && ( isspace( _pFile->_ptr[0] ) != 0 ) )
	{
		fgetc( _pFile );
	}
}
