//*****************************************************************************
//
//	File:		OkdResourceDatabase.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdResourceDatabase.h"
#include	<stdlib.h>
#include	<direct.h>
#include	<Windows.h>

#include	ORKID_CORE_H(String/OkdString)
#include	ORKID_CORE_H(Stream/OkdFileStream)
#include	ORKID_CORE_H(Xml/OkdXmlDocument)

#define	RESOURCE_DATABASE_PATH_ENV	"KORBEN_DEV_RESOURCE_DB_PATH"

const char* OkdResourceDatabase::_strResourceRelativePath[OrkidResourceTypeCount] = 
{
	"Meshes",
	"Scenes"
};

//-----------------------------------------------------------------------------
// Name:		OkdResourceDatabase constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdResourceDatabase::OkdResourceDatabase()
: _pDatabaseXmlDoc	( 0 )
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
	_strResourceDatabasePath = retrieveResourceDatabasePath();
	createResourceDirectories();

	if	( !loadResourceDatabaseXmlFile() )
	{
		return;
	}

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

	if	( _pDatabaseXmlDoc )
	{
		delete _pDatabaseXmlDoc;
		_pDatabaseXmlDoc = 0;
	}

	_strResourceDatabasePath = "";
}

//-----------------------------------------------------------------------------
// Name:		retrieveResourceDatabasePath
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const char*	OkdResourceDatabase::retrieveResourceDatabasePath() const
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
// Name:		loadResourceDatabaseXmlFile
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
bool	OkdResourceDatabase::loadResourceDatabaseXmlFile()
{
	if	( _strResourceDatabasePath.size() == 0 )
	{
		ORKID_BREAK();
		return	( false );
	}

	/*OkdString strResourceDBFilePath( pResourceDBPath );
	strResourceDBFilePath += "\\resources.xml";

	if	( !OkdFileStream::exist( strResourceDBFilePath ) )
	{
		ORKID_BREAK();
		return	( false );
	}

	_pDatabaseXmlDoc = new OkdXmlDocument();
	_pDatabaseXmlDoc->load( strResourceDBFilePath );*/

	return	( true );
}

//-----------------------------------------------------------------------------
// Name:		openResourceFileStream
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream*	OkdResourceDatabase::openResourceFileStream(const OkdResourceType	eResourceType, 
															const OkdString&		strResourceName, 
															const OpenStreamMode	eOpenStreamMode)
{
	ORKID_ASSERT( _bOpen );

	OkdString	strRelativeSourcePath	= _strResourceRelativePath[eResourceType];
	OkdString	strResourcePath			= _strResourceDatabasePath + "\\" + strRelativeSourcePath;
	OkdString	strResourceFile			= strResourcePath + "\\" + strResourceName + ".okd";
	bool		bResourcePathExist		= OkdFileStream::dirExist( strResourcePath );
	int			nFileOpenMode;

	switch	( eOpenStreamMode )
	{
	case OpenStreamLoad:
		if	( !OkdFileStream::exist( strResourceFile ) )
		{
			return	( 0 );
		}

		nFileOpenMode = OkdFileStream::OpenModeIn | OkdFileStream::OpenModeBinary;
		break;

	case OpenStreamSave:
		nFileOpenMode = OkdFileStream::OpenModeOut | OkdFileStream::OpenModeTrunc | OkdFileStream::OpenModeBinary;
		break;

	default:
		ORKID_BREAK();
		return	( 0 );
	}

	OkdFileStream* pResourceFileStream = new OkdFileStream( strResourceFile, nFileOpenMode );

	return	( pResourceFileStream );
}

//-----------------------------------------------------------------------------
// Name:		closeResourceFileStream
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdResourceDatabase::closeResourceFileStream(OkdFileStream** ppResourceFileStream)
{
	OkdFileStream* pStream = *ppResourceFileStream;

	pStream->close();
	pStream = 0;
}

//-----------------------------------------------------------------------------
// Name:		createResourceDirectories
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdResourceDatabase::createResourceDirectories()
{
	for	( uint32 i = 0; i < OrkidResourceTypeCount; i++ )
	{
		OkdVector<OkdString>	tokens;
		OkdString				strRelativeSourcePath	= _strResourceRelativePath[i];
		OkdString				strTempPath				= _strResourceDatabasePath;
		uint32					uiTokensCount			= strRelativeSourcePath.split( "\\", tokens );

		for	( uint32 uiTokenIndex = 0; uiTokenIndex < uiTokensCount; uiTokenIndex++ )
		{
			strTempPath += "\\";
			strTempPath += tokens[uiTokenIndex];

			if	( !OkdFileStream::dirExist( strTempPath ) )
			{
				if	( _mkdir( strTempPath ) == -1 )
				{
					continue;
				}
			}
		}
	}
}

////-----------------------------------------------------------------------------
//// Name:		createResourceDatabaseXmlFile
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//void	OkdResourceDatabase::createResourceDatabaseXmlFile(const OkdString&	strFileName)
//{
//	/*_pDatabaseXmlDoc = new OkdXmlDocument();
//
//	OkdXmlNode* pDeclarationNode = _pDatabaseXmlDoc->allocate_node( rapidxml::node_declaration );
//	pDeclarationNode->append_attribute( _pDatabaseXmlDoc->allocate_attribute( "version", "1.0" ) );
//	pDeclarationNode->append_attribute( _pDatabaseXmlDoc->allocate_attribute("encoding", "utf-8") );
//	_pDatabaseXmlDoc->append_node( pDeclarationNode );
//
//	OkdXmlNode* pRootNode = _pDatabaseXmlDoc->allocate_node( rapidxml::node_element, "Resources" );
//	_pDatabaseXmlDoc->append_node( pRootNode );*/
//}
