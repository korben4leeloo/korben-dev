//*****************************************************************************
//
//	Class:		OkdFileTranslator
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidMayaExporter_OkdFileTranslator_h__
#define __OrkidMayaExporter_OkdFileTranslator_h__

#include <maya/MPxFileTranslator.h>

class QFile;
class QTextStream;
class QDataStream;

class OkdFileTranslator: public MPxFileTranslator
{
public:
					OkdFileTranslator();
					~OkdFileTranslator();

	// MPxFileTranslator overloading
	virtual bool 	haveWriteMethod() const;
	virtual MStatus writer( const MFileObject& file, const MString& optionsString, FileAccessMode mode );

	// MFnPlugin creator
	static void*	creator();

private:
	void			beginExport( const MFileObject& file );
	void			endExport();

	void			exportSceneGraph();

	QFile*			_pExportFile;
	QFile*			_pExportLogFile;
	QDataStream*	_pExportStream;
	QTextStream*	_pExportLogStream;
};

#endif
