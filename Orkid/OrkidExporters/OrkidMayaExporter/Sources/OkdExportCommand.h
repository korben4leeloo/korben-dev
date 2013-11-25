//*****************************************************************************
//
//	Class:		OkdExportCommand
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidMayaExporter_OkdExportCommand_h__
#define __OrkidMayaExporter_OkdExportCommand_h__

#include	"OrkidMayaExporterRoot.h"
#include	<maya/MPxCommand.h>

#include	ORKID_CORE_H(String/OkdString)

class OrkidEngine;
class OkdFileStream;
class OkdScene;
class OkdNode;
class MFnDagNode;

class OkdExportCommand: public MPxCommand
{
public:
						OkdExportCommand();
						~OkdExportCommand();

	// MPxCommand overloading
	virtual MStatus   	doIt(const MArgList& args);
	static void*		creator();

private:
	void				beginExport();
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
