//*****************************************************************************
//
//	Class:		OkdFileTranslator
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidMayaExporter_OkdFileTranslator_h__
#define __OrkidMayaExporter_OkdFileTranslator_h__

#include	"OrkidMayaExporterRoot.h"
#include	<maya/MPxFileTranslator.h>

//class OkdFile;
//class OkdBinaryStream;
//class OkdTextStream;

class OkdFileTranslator: public MPxFileTranslator
{
public:
						OkdFileTranslator();
						~OkdFileTranslator();

	// MPxFileTranslator overloading
	virtual bool 		haveWriteMethod() const;
	virtual MStatus		writer( const MFileObject& file, const MString& optionsString, FileAccessMode mode );

	// MFnPlugin creator
	static void*		creator();

private:
	void				beginExport( const MFileObject& file );
	void				endExport();

	void				exportSceneGraph();

	/*OkdFile*			_pExportFile;
	OkdFile*			_pExportLogFile;*/
	/*OkdBinaryStream*	_pExportStream;
	OkdTextStream*		_pExportLogStream;*/
	OkdFileStream*		_pExportStream;
	OkdFileStream*		_pExportLogStream;
};

#endif
