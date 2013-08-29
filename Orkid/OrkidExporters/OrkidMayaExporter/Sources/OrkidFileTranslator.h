//*****************************************************************************
//
//	Class:		OrkidFileTranslator
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidMayaExporter_OrkidFileTranslator_h__
#define __OrkidMayaExporter_OrkidFileTranslator_h__

#include <maya/MPxFileTranslator.h>

class QFile;
class QTextStream;

class OrkidFileTranslator: public MPxFileTranslator
{
public:
					OrkidFileTranslator();
					~OrkidFileTranslator();

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
	QTextStream*	_pExportStream;
};

#endif
