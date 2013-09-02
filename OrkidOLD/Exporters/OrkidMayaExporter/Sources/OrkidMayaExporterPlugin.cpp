//*****************************************************************************
//
//	File:		OrkidMayaExporterPlugin.cpp
//
//	Created:	2013-08-26
//
//*****************************************************************************

#include "OrkidMayaExporterCommon.h"
#include "OrkidFileTranslator.h"

#include <maya/MFnPlugin.h>
#include <maya/MPxFileTranslator.h>

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

	status = plugin.registerFileTranslator( "OrkidExporter", "", OrkidFileTranslator::creator );
	strStatus = status.errorString();

	return	( MStatus::kSuccess );
}

//-----------------------------------------------------------------------------
// Name:		uninitializePlugin
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
MStatus ORKID_EXPORT uninitializePlugin(MObject obj)
{
	return	( MStatus::kSuccess );
}