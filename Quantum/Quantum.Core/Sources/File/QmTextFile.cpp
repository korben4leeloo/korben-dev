//*****************************************************************************
//
//	File:		QmTextFile.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "QmTextFile.h"
#include <cctype>

const char* QmTextFile::_pcFileMode[QUANTUM_FILE_MODE_COUNT] = { "r", "w", "a", "r+", "w+", "a+" };

//-----------------------------------------------------------------------------
// Name:		QmTextFile constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmTextFile::QmTextFile()
: _pFile( nullptr )
, _nSize( 0 )
{
	
}

//-----------------------------------------------------------------------------
// Name:		QmTextFile destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmTextFile::~QmTextFile()
{
	close();
}

//-----------------------------------------------------------------------------
// Name:		open
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void QmTextFile::open( const QmString& strFileName, const QUANTUM_FILE_MODE eFileMode )
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
void QmTextFile::close()
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
void QmTextFile::trimWhitespaceCharacters() const
{
	char c = fgetc( _pFile );

	while ( !feof( _pFile ) && ( isspace( c ) != 0 ) )
	{
		c = fgetc( _pFile );
	}

	ungetc( c, _pFile );
}
