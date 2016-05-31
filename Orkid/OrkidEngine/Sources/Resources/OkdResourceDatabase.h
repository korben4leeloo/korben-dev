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
	enum OpenStreamMode
	{
		OpenStreamLoad,
		OpenStreamSave
	};

	void					open();
	void					close();

	OkdFileStream*			openResourceFileStream( const OkdResourceType eResourceType, const OkdString& strResourceName, const OpenStreamMode eOpenStreamMode );
	void					closeResourceFileStream( OkdFileStream** ppResourceFileStream );

	inline const OkdString&	getResourceDatabasePath() const;

private:
							OkdResourceDatabase();
							~OkdResourceDatabase();

	const char*				retrieveResourceDatabasePath() const;
	void					createResourceDirectories();
	//void					createResourceDatabaseXmlFile( const OkdString& strFileName );
	bool					loadResourceDatabaseXmlFile();

	//OkdFileStream*			_pResourceDBXmlFile;
	OkdString				_strResourceDatabasePath;
	OkdXmlDocument*			_pDatabaseXmlDoc;
	bool					_bOpen;

	static const char*		_strResourceRelativePath[OrkidResourceTypeCount];
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		getResourceDatabasePath
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const OkdString&	OkdResourceDatabase::getResourceDatabasePath() const
{
	return	( _strResourceDatabasePath );
}

#endif