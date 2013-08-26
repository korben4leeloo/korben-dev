//*****************************************************************************
//
//	File:		OrkidFileTranslator.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "OrkidMayaExporterCommon.h"
#include "OrkidFileTranslator.h"

// Maya includes
#include <maya/MItDag.h>
#include <maya/MDagPath.h>
#include <maya/MFnDagNode.h>
#include <maya/MFnTransform.h>
#include <maya/MFnMesh.h>

// Qt includes
#include <QFile>
#include <QTextStream>

#define	WRITE_LOG_INFOS( uiIndent, logInfos )		\
	for	( uint i = 0; i < uiIndent; i++ )	\
	{												\
		(*_pExportStream) << "\t";					\
	}												\
													\
	(*_pExportStream) << logInfos;

////-----------------------------------------------------------------------------
//// Name:		OrkidFileTranslator constructor
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//QTextStream &	IndentTabs( QTextStream* pExportStream, uint uiDepth )
//{
//	for	( uint i = 0; i < uiDepth; i++ )
//	{
//		(*pExportStream) << "\t";
//	}
//
//	return	( *pExportStream );
//}

//-----------------------------------------------------------------------------
// Name:		OrkidFileTranslator constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OrkidFileTranslator::OrkidFileTranslator()
: _pExportFile		( 0 )
, _pExportStream	( 0 )
{
	
}

//-----------------------------------------------------------------------------
// Name:		OrkidFileTranslator destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OrkidFileTranslator::~OrkidFileTranslator()
{
	
}

//-----------------------------------------------------------------------------
//	Name:		haveWriteMethod
//
//	Created:	2013-08-26
//-----------------------------------------------------------------------------
bool	OrkidFileTranslator::haveWriteMethod() const
{
	return	( true );
}

//-----------------------------------------------------------------------------
// Name:		writer
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
MStatus	OrkidFileTranslator::writer(const MFileObject &	file, 
									const MString &		optionsString, 
									FileAccessMode		mode )
{
	beginExport( file );

	exportSceneGraph();
	//exportDependencyNodes( &exportStream );

	endExport();

	return	( MStatus::kSuccess );
}

//-----------------------------------------------------------------------------
// Name:		exportSceneGraph
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OrkidFileTranslator::exportSceneGraph()
{
	MStatus	status;
	//MItDag	itDag( MItDag::kDepthFirst, MFn::kInvalid, &status );
	MItDag	itDag( MItDag::kDepthFirst, MFn::kTransform, &status );

	while	( itDag.isDone() == false )
	{
		MDagPath dagPath;
		status = itDag.getPath( dagPath );

		// Get transform infos
		MFnDagNode		dagNode( dagPath, &status );
		QString			strNodeName( dagNode.name().asChar() );
		QString			strFullPathName( dagPath.fullPathName().asChar() );
		QString			strNodeTypeName( dagNode.typeName().asChar() );
		MFnTransform	fnTransform( dagPath, &status );
		MVector			vLocal = fnTransform.getTranslation( MSpace::kTransform, &status );

		WRITE_LOG_INFOS( dagPath.length(), strNodeName << ": " << strNodeTypeName << " - Path: " << strFullPathName << " - Local transform: " << vLocal.x << " " << vLocal.y << " " << vLocal.z << "\n" );

		// Get mesh infos
		status = dagPath.extendToShape();

		MFnDagNode	shapeDagNode( dagPath, &status );
		QString		strShapeNodeName( shapeDagNode.name().asChar() );
		QString		strShapeFullPathName( dagPath.fullPathName().asChar() );
		QString		strShapeNodeTypeName( shapeDagNode.typeName().asChar() );

		WRITE_LOG_INFOS( dagPath.length(), strShapeNodeName << ": " << strShapeNodeTypeName << " - Path: " << strShapeFullPathName << "\n" );

		if	( dagPath.hasFn( MFn::kMesh ) )
		{
			MFnMesh fnMesh( dagPath, &status );

			WRITE_LOG_INFOS( dagPath.length() + 1, "Polygons count: " << fnMesh.numPolygons( &status ) << "\n" );
			WRITE_LOG_INFOS( dagPath.length() + 1, "Vertices count: " << fnMesh.numVertices( &status ) << "\n" );
			WRITE_LOG_INFOS( dagPath.length() + 1, "Normals count: " << fnMesh.numNormals( &status ) << "\n" );
			WRITE_LOG_INFOS( dagPath.length() + 1, "UVs count: " << fnMesh.numUVs( &status ) << "\n" );
		}

		itDag.next();
	}
}

//-----------------------------------------------------------------------------
// Name:		beginExport
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OrkidFileTranslator::beginExport(const MFileObject &	file)
{
	const MString strFileName = file.fullName();

	// Create export file
	_pExportFile = new QFile( strFileName.asChar() );
	_pExportFile->open( QIODevice::WriteOnly );

	// Create export stream
	_pExportStream = new QTextStream( _pExportFile );
}

//-----------------------------------------------------------------------------
// Name:		endExport
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OrkidFileTranslator::endExport()
{
	_pExportFile->close();
}

//-----------------------------------------------------------------------------
// Name:		creator
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void*	OrkidFileTranslator::creator()
{
	return	( (void*)(new OrkidFileTranslator()) );
}