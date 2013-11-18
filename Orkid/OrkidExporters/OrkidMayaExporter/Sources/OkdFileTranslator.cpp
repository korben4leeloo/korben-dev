//*****************************************************************************
//
//	File:		OkdFileTranslator.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdFileTranslator.h"

// Orkid includes
#include	ORKID_CORE_H(String/OkdString)
#include	ORKID_CORE_H(Stream/OkdFileStream)
//#include	ORKID_CORE_H(Stream/OkdFile)

#include	ORKID_ENGINE_H(OrkidEngine)
#include	ORKID_ENGINE_H(SceneGraph/OkdScene)
#include	ORKID_ENGINE_H(Entities/OkdMesh)
#include	ORKID_ENGINE_H(Resources/OkdResourcePtr)

// Maya includes
#include	<maya/MItDag.h>
#include	<maya/MDagPath.h>
#include	<maya/MFnDagNode.h>
#include	<maya/MFnTransform.h>
#include	<maya/MFnMesh.h>

#define	USE_LOG_INFOS

#ifdef USE_LOG_INFOS
	#define	WRITE_LOG_INFOS( uiIndent, logInfos )									\
		for	( uint uiIndentIndex = 0; uiIndentIndex < uiIndent; uiIndentIndex++ )	\
		{																			\
			(*_pExportLogStream) << "\t";											\
		}																			\
																					\
		(*_pExportLogStream) << logInfos;
#else
	#define	WRITE_LOG_INFOS( uiIndent, logInfos )
#endif

//-----------------------------------------------------------------------------
// Name:		OkdFileTranslator constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFileTranslator::OkdFileTranslator()
//: _pExportFile		( 0 )
: _pExportStream	( 0 )
//, _pExportLogFile	( 0 )
, _pExportLogStream	( 0 )
, _pOrkidEngine		( 0 )
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
MStatus	OkdFileTranslator::writer(const MFileObject&	file, 
								  const MString&		optionsString, 
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
	MStatus				status;
	MItDag				itDag( MItDag::kDepthFirst, MFn::kTransform, &status );
	/*OkdResourceManager*	pExportResourceManager	= _pOrkidEngine->addResourceManager( "ExportResourceManager" );
	OkdScene*			pExportScene			= _pOrkidEngine->addScene( "ExportScene", "ExportResourceManager" );*/
	//OkdScene*			pExportScene			= _pOrkidEngine->addScene( "ExportScene" );
	OkdScenePtr	scenePtr;

	//scenePtr.create( 

	while	( itDag.isDone() == false )
	{
		MDagPath dagPath;
		status = itDag.getPath( dagPath );

		// Get transform infos
		MFnDagNode		dagNode( dagPath, &status );
		OkdString		strNodeName( dagNode.name().asChar() );
		OkdString		strFullPathName( dagPath.fullPathName().asChar() );
		OkdString		strNodeTypeName( dagNode.typeName().asChar() );
		MFnTransform	fnTransform( dagPath, &status );
		MVector			vLocal = fnTransform.getTranslation( MSpace::kTransform, &status );

		WRITE_LOG_INFOS( dagPath.length(), strNodeName << ": " << strNodeTypeName << " - Path: " << strFullPathName << " - Local transform: " << vLocal.x << " " << vLocal.y << " " << vLocal.z << "\n" );

		// Get mesh infos
		status = dagPath.extendToShape();

		MFnDagNode	shapeDagNode( dagPath, &status );
		OkdString	strShapeNodeName( shapeDagNode.name().asChar() );
		OkdString	strShapeFullPathName( dagPath.fullPathName().asChar() );
		OkdString	strShapeNodeTypeName( shapeDagNode.typeName().asChar() );

		WRITE_LOG_INFOS( dagPath.length(), strShapeNodeName << ": " << strShapeNodeTypeName << " - Path: " << strShapeFullPathName << "\n" );

		if	( dagPath.hasFn( MFn::kMesh ) )
		{
			MFnMesh		fnMesh( dagPath, &status );
			uint		uiVertexCount	= fnMesh.numVertices( &status );
			uint		uiPolygonCount	= fnMesh.numPolygons( &status );
			OkdMeshInfo	meshInfo( uiVertexCount, uiPolygonCount );
			OkdMesh*	pOrkidMesh		= 0;//pExportScene->createMesh();

			WRITE_LOG_INFOS( dagPath.length() + 1, "Polygons count: " << uiPolygonCount << "\n" );
			WRITE_LOG_INFOS( dagPath.length() + 1, "Vertices count: " << fnMesh.numVertices( &status ) << "\n" );
			WRITE_LOG_INFOS( dagPath.length() + 1, "Normals count: " << fnMesh.numNormals( &status ) << "\n" );
			WRITE_LOG_INFOS( dagPath.length() + 1, "UVs count: " << fnMesh.numUVs( &status ) << "\n" );

			const float* pLocalPoints = fnMesh.getRawPoints( &status );

			pOrkidMesh->create( meshInfo );
			pOrkidMesh->setVertexArray( pLocalPoints );

			//_pExportStream->writeRawData( (char*)pLocalPoints, uiVertexCount * 3 * sizeof(pLocalPoints[0]) );
			
			for	( uint i = 0; i < uiPolygonCount; i++ )
			{
				if	( fnMesh.polygonVertexCount( i, &status ) != 3 )
				{
					WRITE_LOG_INFOS( dagPath.length() + 1, "Polygon " << i << " is not a triangle" );
					return;
				}

				int vertexIdArray[3];

				fnMesh.getPolygonTriangleVertices( i, 0, vertexIdArray );
				pOrkidMesh->setPolygon( i, (const uint*)vertexIdArray );

				//(*_pExportStream) << vertexIdArray[0] << vertexIdArray[1] << vertexIdArray[2];
				WRITE_LOG_INFOS( dagPath.length() + 1, vertexIdArray[0] << " " << vertexIdArray[1] << " " << vertexIdArray[2] << "\n" );
			}

			pOrkidMesh->write( _pExportStream );
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
	OkdString		strLogFileName( strFileName.asChar() );

	_strSceneName = strLogFileName;

	strLogFileName.replace( ".okd", ".log" );

	_pExportStream		= new OkdFileStream( strFileName.asChar(), OkdFileStream::OpenModeOut | OkdFileStream::OpenModeTrunc | OkdFileStream::OpenModeBinary );
	_pExportLogStream	= new OkdFileStream( strLogFileName, OkdFileStream::OpenModeOut | OkdFileStream::OpenModeTrunc );

	_pOrkidEngine = OrkidEngine::create();

	// Create export file
	//_pExportFile = new OkdFile( strFileName.asChar() );
	//_pExportFile->open( QIODevice::WriteOnly );

	// Create export stream
	//_pExportStream = new OkdBinaryStream( _pExportFile );

	// Create export log file
	//_pExportLogFile = new OkdFile( strLogFileName );
	//_pExportLogFile->open( QIODevice::WriteOnly );

	// Create export log stream
	//_pExportLogStream = new OkdTextStream( _pExportLogFile );
}

//-----------------------------------------------------------------------------
// Name:		endExport
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdFileTranslator::endExport()
{
	//_pExportFile->close();
	//_pExportLogFile->close();

	_pExportStream->close();
	_pExportLogStream->close();

	_pOrkidEngine = 0;
	OrkidEngine::destroy();
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