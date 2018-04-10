//*****************************************************************************
//
//	File:		QmBinaryFile.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "QmBinaryFile.h"
#include <cstring>

const char* QmBinaryFile::_pcFileMode[QUANTUM_FILE_MODE_COUNT] = { "rb", "wb", "ab", "r+b", "w+b", "a+b" };

//-----------------------------------------------------------------------------
// Name:		QmBinaryFile constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmBinaryFile::QmBinaryFile()
: _pFile( nullptr )
{
	
}

//-----------------------------------------------------------------------------
// Name:		QmBinaryFile destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmBinaryFile::~QmBinaryFile()
{
	close();
}

//-----------------------------------------------------------------------------
// Name:		open
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void QmBinaryFile::open( const QmString& strFileName, const QUANTUM_FILE_MODE eFileMode )
{
	_pFile = fopen( strFileName.buffer(), _pcFileMode[eFileMode] );
}

//-----------------------------------------------------------------------------
// Name:		close
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void QmBinaryFile::close()
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
QmBinaryFile& QmBinaryFile::operator<<( const char* pcData )
{
	uint32 uiSize = (uint32)strlen( pcData );

	(*this) << uiSize;
	fwrite( pcData, sizeof(char), uiSize, _pFile );
	return ( *this );
}
