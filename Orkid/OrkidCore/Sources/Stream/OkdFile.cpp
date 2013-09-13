//*****************************************************************************
//
//	File:		OkdFile.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"Root.h"
#include	"OkdFile.h"

#include	<io.h>

//-----------------------------------------------------------------------------
// Name:		OkdFile constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFile::OkdFile()
//: _pFile( 0 )
: _nFileHandle( -1 )
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdFile destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFile::~OkdFile()
{
	close();
}

//-----------------------------------------------------------------------------
// Name:		open
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdFile::open(const char*				pcFileName, 
					  const OrkidFileOpenMode	openMode)
{
	close();

	/*errno_t result = fopen_s( &_pFile, pcFileName, "" );
	ORKID_ASSERT( result == 0 );*/

	errno_t result = _sopen_s( &_nFileHandle, pcFileName, 0, 0, 0 );
	ORKID_ASSERT( result == 0 );
}

//-----------------------------------------------------------------------------
// Name:		close
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdFile::close()
{
	/*if	( _pFile )
	{
		fclose( _pFile );
		_pFile = 0;
	}*/

	if	( _nFileHandle != -1 )
	{
		_close( _nFileHandle );
		_nFileHandle = -1;
	}
}
