//*****************************************************************************
//
//	Class:		OkdXmlFile
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdXmlFile_h__
#define __OrkidCore_OkdXmlFile_h__

#include	"Root.h"
//#include	<xercesc/util/XercesDefs.hpp>
//
//XERCES_CPP_NAMESPACE_BEGIN
//	class XercesDOMParser;
//	class ErrorHandler;
//XERCES_CPP_NAMESPACE_END

class OkdString;

class OkdXmlFile
{
public:
											OkdXmlFile( const OkdString& strFileName );
											~OkdXmlFile();

private:
	/*XERCES_CPP_NAMESPACE::XercesDOMParser*	_pXmlParser;
	XERCES_CPP_NAMESPACE::ErrorHandler*		_pXmlErrorHandler;*/
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif
