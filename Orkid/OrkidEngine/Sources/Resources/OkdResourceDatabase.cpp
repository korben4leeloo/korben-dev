//*****************************************************************************
//
//	File:		OkdResourceDatabase.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdResourceDatabase.h"
#include	<stdlib.h>

#include	ORKID_CORE_H(String/OkdString)
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
//// Name:		getResourceTypePath
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//OkdString	OkdResourceDatabase::getResourceTypePath( const OrkidResourceType eResourceType ) const
//{
//	//OkdString strResourceTypePath = _str
//}

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
