//*****************************************************************************
//
//	File:		OkdFileTranslator.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdFileTranslator.h"

#include	ORKID_ENGINE_H(Entities/OkdMesh)

// Maya includes
#include	<maya/MItDag.h>
#include	<maya/MDagPath.h>
#include	<maya/MFnDagNode.h>
#include	<maya/MFnTransform.h>
#include	<maya/MFnMesh.h>

// Qt includes
#include	<QFile>
#include	<QTextStream>
#include	<QDataStream>

#define	WRITE_LOG_INFOS( uiIndent, logInfos )									\
	for	( uint uiIndentIndex = 0; uiIndentIndex < uiIndent; uiIndentIndex++ )	\
	{																			\
		(*_pExportLogStream) << "\t";											\
	}																			\
																				\
	(*_pExportLogStream) << logInfos;

//-----------------------------------------------------------------------------
// Name:		OkdFileTranslator constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileTranslator::OkdFileTranslator()
: _pExportFile		( 0 )
, _pExportStream	( 0 )
, _pExportLogFile	( 0 )
, _pExportLogStream	( 0 )
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdFileTranslator destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileTranslator::~OkdFileTranslator()
{
	
}

//-----------------------------------------------------------------------------
//	Name:		haveWriteMethod
//
//	Created:	2013-08-26
//-----------------------------------------------------------------------------
bool	OkdFileTranslator::haveWriteMethod() const
{
	return	( true );
}

//-----------------------------------------------------------------------------
// Name:		writer
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
MStatus	OkdFileTranslator::writer(const MFileObject &	file, 
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
void	OkdFileTranslator::exportSceneGraph()
{
	MStatus	status;
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
			uint	uiVertexCount	= fnMesh.numVertices( &status );
			uint	uiPolygonCount	= fnMesh.numPolygons( &status );
			OkdMesh	orkidMesh;

			WRITE_LOG_INFOS( dagPath.length() + 1, "Polygons count: " << uiPolygonCount << "\n" );
			WRITE_LOG_INFOS( dagPath.length() + 1, "Vertices count: " << fnMesh.numVertices( &status ) << "\n" );
			WRITE_LOG_INFOS( dagPath.length() + 1, "Normals count: " << fnMesh.numNormals( &status ) << "\n" );
			WRITE_LOG_INFOS( dagPath.length() + 1, "UVs count: " << fnMesh.numUVs( &status ) << "\n" );

			const float* pLocalPoints = fnMesh.getRawPoints( &status );

			orkidMesh.create( pLocalPoints, uiVertexCount, uiPolygonCount );

			_pExportStream->writeRawData( (char*)pLocalPoints, uiVertexCount * 3 * sizeof(pLocalPoints[0]) );

			std::string s = "test";

			s.replace( "st", "kk" );
			
			for	( uint i = 0; i < uiPolygonCount; i++ )
			{
				if	( fnMesh.polygonVertexCount( i, &status ) != 3 )
				{
					WRITE_LOG_INFOS( dagPath.length() + 1, "Polygon " << i << " is not a triangle" );
					return;
				}

				int vertexIdArray[3];

				fnMesh.getPolygonTriangleVertices( i, 0, vertexIdArray );
				orkidMesh.setPolygon( i, (const uint*)vertexIdArray );

				(*_pExportStream) << vertexIdArray[0] << vertexIdArray[1] << vertexIdArray[2];
				WRITE_LOG_INFOS( dagPath.length() + 1, vertexIdArray[0] << " " << vertexIdArray[1] << " " << vertexIdArray[2] << "\n" );
			}
		}

		itDag.next();
	}
}

//-----------------------------------------------------------------------------
// Name:		beginExport
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdFileTranslator::beginExport(const MFileObject &	file)
{
	const MString	strFileName = file.fullName();
	QString			strLogFileName( strFileName.asChar() );

	strLogFileName.replace( ".okd", ".log" );

	// Create export file
	_pExportFile = new QFile( strFileName.asChar() );
	_pExportFile->open( QIODevice::WriteOnly );

	// Create export stream
	_pExportStream = new QDataStream( _pExportFile );

	// Create export log file
	_pExportLogFile = new QFile( strLogFileName );
	_pExportLogFile->open( QIODevice::WriteOnly );

	// Create export log stream
	_pExportLogStream = new QTextStream( _pExportLogFile );
}

//-----------------------------------------------------------------------------
// Name:		endExport
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdFileTranslator::endExport()
{
	_pExportFile->close();
	_pExportLogFile->close();
}

//-----------------------------------------------------------------------------
// Name:		creator
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void*	OkdFileTranslator::creator()
{
	return	( (void*)(new OkdFileTranslator()) );
}