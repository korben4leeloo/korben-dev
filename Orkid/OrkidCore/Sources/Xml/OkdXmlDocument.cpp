//*****************************************************************************
//
//	File:		OkdXmlDocument.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdXmlDocument.h"

#include	ORKID_CORE_H(String/OkdString)

//-----------------------------------------------------------------------------
// Name:		OkdXmlDocument constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdXmlDocument::OkdXmlDocument()
: _pXmlBuffer( 0 )
{
	_pXmlDocument = new rapidxml::xml_document<>();
}

//-----------------------------------------------------------------------------
// Name:		OkdXmlDocument destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdXmlDocument::~OkdXmlDocument()
{
	delete _pXmlDocument;
}

//-----------------------------------------------------------------------------
// Name:		load
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
bool	OkdXmlDocument::load(const OkdString&	strFileName)
{
	OkdFileStream xmlFile( strFileName, OkdFileStream::OpenModeIn );

	_pXmlBuffer = new char[(uint32)xmlFile.length()];
	xmlFile.read( _pXmlBuffer, xmlFile.length() );

	_pXmlDocument->parse<0>( _pXmlBuffer );

	return	( true );
}
