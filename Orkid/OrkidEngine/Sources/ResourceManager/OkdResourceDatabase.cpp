//*****************************************************************************
//
//	File:		OkdResourceDatabase.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdResourceDatabase.h"
#include	<stdlib.h>

#include	ORKID_CORE_H(String/OkdString)
#include	ORKID_CORE_H(Xml/OkdXmlFile)

#define	RESOURCE_DATABASE_PATH_ENV	"KORBEN_DEV_RESOURCE_DB_PATH"

//-----------------------------------------------------------------------------
// Name:		OkdResourceDatabase constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourceDatabase::OkdResourceDatabase()
: _pDatabaseXmlFile	( 0 )
, _bOpen			( false )
{

}

//-----------------------------------------------------------------------------
// Name:		OkdResourceDatabase destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourceDatabase::~OkdResourceDatabase()
{
	close();
}

//-----------------------------------------------------------------------------
// Name:		open
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdResourceDatabase::open()
{
	const char* pResourceDBPath = getResourceDatabasePath();

	if	( pResourceDBPath == 0 )
	{
		ORKID_BREAK();
		return;
	}

	OkdString strResourceDBFilePath( pResourceDBPath );
	strResourceDBFilePath += "\\resources.xml";

	if	( !OkdFileStream::exist( strResourceDBFilePath ) )
	{
		createResourceDatabaseXmlFile( strResourceDBFilePath );
	}
	else
	{
		_pResourceDBXmlFile = new OkdFileStream( strResourceDBFilePath, OkdFileStream::OpenModeIn );
	}

	//_pDatabaseXmlFile = new OkdXmlFile( pResourceDBPath );

	_bOpen = true;
}

//-----------------------------------------------------------------------------
// Name:		close
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdResourceDatabase::close()
{
	_bOpen = false;
}

//-----------------------------------------------------------------------------
// Name:		getResourceDatabasePath
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const char*	OkdResourceDatabase::getResourceDatabasePath() const
{
	char*	pBuffer = 0;
	uint32	uiRequiredSize;
	errno_t	result;

	// Get buffer size
	result = getenv_s( &uiRequiredSize, 0, 0, RESOURCE_DATABASE_PATH_ENV );

	if	( ( result == 0 ) && ( uiRequiredSize > 0 ) )
	{
		// Get value
		pBuffer = new char[uiRequiredSize];
		result = getenv_s( &uiRequiredSize, pBuffer, uiRequiredSize, RESOURCE_DATABASE_PATH_ENV );
	}

	return	( pBuffer );
}

//-----------------------------------------------------------------------------
// Name:		createResourceDatabaseXmlFile
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdResourceDatabase::createResourceDatabaseXmlFile(const OkdString&	strFileName)
{
	_pResourceDBXmlFile = new OkdFileStream( strFileName, OkdFileStream::OpenModeOut );
}
