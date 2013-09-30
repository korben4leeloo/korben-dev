//*****************************************************************************
//
//	File:		OkdXmlFile.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdXmlFile.h"

#include	ORKID_CORE_H(String/OkdString)

//#include	<xercesc/util/PlatformUtils.hpp>
//#include	<xercesc/sax/HandlerBase.hpp>
//#include	<xercesc/parsers/XercesDOMParser.hpp>
//#include	<xercesc/dom/DOMImplementation.hpp>
//#include	<xercesc/dom/DOMDocument.hpp>
//
//XERCES_CPP_NAMESPACE_USE

//-----------------------------------------------------------------------------
// Name:		OkdXmlFile constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdXmlFile::OkdXmlFile(const OkdString&	strFileName)
{
	/*XMLPlatformUtils::Initialize();

	_pXmlErrorHandler	= new HandlerBase();
	_pXmlParser			= new XercesDOMParser();

	_pXmlParser->setErrorHandler( _pXmlErrorHandler );
	_pXmlParser->parse( strFileName );

	DOMImplementation* i = DOMImplementation::getImplementation();
	DOMDocument* doc = i->createDocument();*/
}

//-----------------------------------------------------------------------------
// Name:		OkdXmlFile destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdXmlFile::~OkdXmlFile()
{
	/*delete _pXmlParser;
	delete _pXmlErrorHandler;

	XMLPlatformUtils::Terminate();*/
}
