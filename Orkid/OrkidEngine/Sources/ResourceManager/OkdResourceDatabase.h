//*****************************************************************************
//
//	Class:		OkdResourceDatabase
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdResource_h__
#define __OrkidEngine_OkdResource_h__

#include	"Root.h"

class OkdXmlFile;
class OkdString;
class OkdFileStream;

class OkdResourceDatabase
{
public:
					OkdResourceDatabase();
					~OkdResourceDatabase();

	void			open();
	void			close();

private:
	const char*		getResourceDatabasePath() const;
	void			createResourceDatabaseXmlFile( const OkdString& strFileName );

	OkdFileStream*	_pResourceDBXmlFile;
	OkdXmlFile*		_pDatabaseXmlFile;
	bool			_bOpen;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif