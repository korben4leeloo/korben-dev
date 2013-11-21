//*****************************************************************************
//
//	Class:		OkdResourceDatabase
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdResourceDatabase_h__
#define __OrkidEngine_OkdResourceDatabase_h__

#include	"Root.h"

#include	ORKID_CORE_H(Singleton/OkdSingleton)
#include	ORKID_CORE_H(Containers/OkdMap)
#include	ORKID_CORE_H(String/OkdString)

class OkdResourceHandle;
//class OkdFileStream;
class OkdXmlDocument;

class OkdResourceDatabase//: public OkdSingleton<OkdResourceDatabase>
{
	friend class OrkidEngine;

public:
	void				open();
	void				close();

	//OkdString			getResourceTypePath( const OrkidResourceType eResourceType ) const;

private:
	typedef OkdMap<uint32, OkdString> OkdResourceFileMap;

						OkdResourceDatabase();
						~OkdResourceDatabase();

	const char*			getResourceDatabasePath() const;
	//void				createResourceDatabaseXmlFile( const OkdString& strFileName );
	bool				loadResourceDatabaseXmlFile();

	//OkdFileStream*		_pResourceDBXmlFile;
	OkdString			_strResourceDatabasePath;
	OkdXmlDocument*		_pDatabaseXmlDoc;
	bool				_bOpen;
	OkdResourceFileMap	_resourceFileArray;

	static const char*	_strResourceRelativePath[OrkidResourceTypeCount];
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif