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
	_strResourceDatabasePath = getResourceDatabasePath();

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
// Name:		loadResourceDatabaseXmlFile
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
bool	OkdResourceDatabase::loadResourceDatabaseXmlFile()
{
	const char* pResourceDBPath = getResourceDatabasePath();

	if	( pResourceDBPath == 0 )
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

////-----------------------------------------------------------------------------
//// Name:		getResourcePath
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//OkdString	OkdResourceDatabase::getResourcePath(const OrkidResourceType	eResourceType, 
//												 const OkdString&			strResourceName)
//{
//	ORKID_ASSERT( _bOpen );
//
//	OkdString strResourceRelativePath	= _strResourceRelativePath[eResourceType];
//	OkdString strResourcePath			= _strResourceDatabasePath + _strResourceRelativePath[eResourceType] + "\\" + strResourceName + ".okd";
//
//	return	( strResourcePath );
//}

//-----------------------------------------------------------------------------
// Name:		openResourceFileStream
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileStream*	OkdResourceDatabase::openResourceFileStream(const OrkidResourceType	eResourceType, 
															const OkdString&		strResourceName, 
															const OpenStreamMode	eOpenStreamMode)
{
	ORKID_ASSERT( _bOpen );

	OkdString	strRelativeSourcePath	= _strResourceRelativePath[eResourceType];
	OkdString	strResourcePath			= _strResourceDatabasePath + "\\" + strRelativeSourcePath;
	bool		bResourcePathExist		= OkdFileStream::dirExist( strResourcePath );
	int			nFileOpenMode;

	switch	( eOpenStreamMode )
	{
	case OpenStreamLoad:
		if	( !bResourcePathExist )
		{
			return	( 0 );
		}

		nFileOpenMode = OkdFileStream::OpenModeIn | OkdFileStream::OpenModeBinary;
		break;

	case OpenStreamSave:
		if	( !bResourcePathExist )
		{
			OkdString				strTempPath = _strResourceDatabasePath;
			OkdVector<OkdString>	tokens;
		
			strRelativeSourcePath.split( "\\", tokens );

			uint32 uiTokensCount = tokens.size();

			for	( uint32 uiTokenIndex = 0; uiTokenIndex < uiTokensCount; uiTokenIndex++ )
			{
				strTempPath += "\\";
				strTempPath += tokens[uiTokenIndex];

				if	( !OkdFileStream::dirExist( strTempPath ) )
				{
					if	( _mkdir( strTempPath ) == -1 )
					{
						return	( 0 );
					}
				}
			}
		}

		nFileOpenMode = OkdFileStream::OpenModeOut | OkdFileStream::OpenModeTrunc | OkdFileStream::OpenModeBinary;
		break;

	default:
		ORKID_BREAK();
		return	( 0 );
	}

	OkdString		strResourceFile		= strResourcePath + "\\" + strResourceName + ".okd";
	OkdFileStream*	pResourceFileStream	= new OkdFileStream( strResourceFile, nFileOpenMode );

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
