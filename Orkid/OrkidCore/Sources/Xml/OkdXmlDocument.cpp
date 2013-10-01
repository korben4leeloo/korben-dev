//*****************************************************************************
//
//	File:		OkdXmlDocument.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdXmlDocument.h"

#include	<rapidxml/rapidxml_print.hpp>
#include	ORKID_CORE_H(String/OkdString)

//-----------------------------------------------------------------------------
// Name:		OkdXmlDocument constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdXmlDocument::OkdXmlDocument()
//: _pXmlBuffer( 0 )
{
	//_pXmlDocument = new rapidxml::xml_document<>();
}

//-----------------------------------------------------------------------------
// Name:		OkdXmlDocument destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdXmlDocument::~OkdXmlDocument()
{
	//delete _pXmlDocument;

	/*if	( _pXmlBuffer )
	{
		delete _pXmlBuffer;
	}*/
}

//-----------------------------------------------------------------------------
// Name:		load
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
bool	OkdXmlDocument::load(const OkdString&	strFileName)
{
	OkdFileStream xmlFile( strFileName, OkdFileStream::OpenModeIn );

	if	( xmlFile.isOpen() == false )
	{
		ORKID_BREAK();
		return	( false );
	}

	char* pXmlBuffer = new char[(uint32)xmlFile.length()];
	xmlFile.read( pXmlBuffer, xmlFile.length() );
	parse<0>( pXmlBuffer );

	return	( true );
}

//-----------------------------------------------------------------------------
// Name:		save
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
bool	OkdXmlDocument::save(const OkdString&	strFileName)
{
	OkdFileStream xmlFile( strFileName, OkdFileStream::OpenModeOut | OkdFileStream::OpenModeTrunc );

	xmlFile << *this;
	xmlFile.close();

	return	( true );
}
