//*****************************************************************************
//
//	File:		OkdMayaExporterPlugin.cpp
//
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OrkidMayaExporterRoot.h"

#include	ORKID_MAYA_EXPORTER_H(OkdFileTranslator)
#include	ORKID_MAYA_EXPORTER_H(OkdExportCommand)

#include	<maya/MFnPlugin.h>
#include	<maya/MPxFileTranslator.h>

//-----------------------------------------------------------------------------
// Name:		initializePlugin
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
MStatus ORKID_EXPORT initializePlugin(MObject obj)
{
	MFnPlugin	plugin( obj );
	MStatus		status;
	MString		strStatus;

	status = plugin.registerFileTranslator( "OrkidExporter", "", OkdFileTranslator::creator );
	strStatus = status.errorString();

	status = plugin.registerCommand( "orkidExport", OkdExportCommand::creator );

	return	( MStatus::kSuccess );
}

//-----------------------------------------------------------------------------
// Name:		uninitializePlugin
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
MStatus ORKID_EXPORT uninitializePlugin(MObject obj)
{
	MFnPlugin	plugin( obj );
	MStatus		status = plugin.deregisterCommand( "orkidExport" );

	return	( MStatus::kSuccess );
}