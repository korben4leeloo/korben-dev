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

#include	ORKID_CORE_H(String/OkdString)

class OrkidEngine;
class OkdFileStream;
class OkdScene;
class OkdNode;
class MFnDagNode;

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
	void				exportDagNode( const MFnDagNode& fnDagNode, OkdNode* pParentNode );

	OkdFileStream*		_pExportStream;
	OkdFileStream*		_pExportLogStream;
	OrkidEngine*		_pOrkidEngine;
	OkdString			_strSceneName;
	OkdScene*			_pOrkidScene;
};

#endif
