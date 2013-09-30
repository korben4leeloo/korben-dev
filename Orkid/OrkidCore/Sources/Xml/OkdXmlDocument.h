//*****************************************************************************
//
//	Class:		OkdXmlDocument
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdXmlDocument_h__
#define __OrkidCore_OkdXmlDocument_h__

#include	"Root.h"
#include	<rapidxml/rapidxml.hpp>

class OkdString;

typedef rapidxml::xml_node<char>		OkdXmlNode;
typedef rapidxml::xml_attribute<char>	OkdXmlAttribute;

class OkdXmlDocument: public rapidxml::xml_document<char>
{
public:
								OkdXmlDocument();
								~OkdXmlDocument();

	bool						load( const OkdString& strFileName );
	bool						save( const OkdString& strFileName );

private:
	char*						_pXmlBuffer;
	//rapidxml::xml_document<>*	_pXmlDocument;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif
