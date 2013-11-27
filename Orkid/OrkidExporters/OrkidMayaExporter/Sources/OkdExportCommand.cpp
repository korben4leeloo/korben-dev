//*****************************************************************************
//
//	File:		OkdExportCommand.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdExportCommand.h"

// Orkid includes
#include	ORKID_CORE_H(String/OkdString)
#include	ORKID_CORE_H(Stream/OkdFileStream)

#include	ORKID_ENGINE_H(OrkidEngine)
#include	ORKID_ENGINE_H(SceneGraph/OkdScene)
#include	ORKID_ENGINE_H(SceneGraph/OkdNode)
#include	ORKID_ENGINE_H(Entities/OkdMesh)
#include	ORKID_ENGINE_H(Entities/OkdMeshInstance)
#include	ORKID_ENGINE_H(Resources/OkdResourcePtr)

// Maya includes
#include	<maya/MItDag.h>
#include	<maya/MDagPath.h>
#include	<maya/MFnDagNode.h>
#include	<maya/MFnTransform.h>
#include	<maya/MFnMesh.h>
#include	<maya/MFileIO.h>
#include	<maya/MFileObject.h>

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
// Name:		OkdExportCommand constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdExportCommand::OkdExportCommand()
: _pExportStream	( 0 )
, _pExportLogStream	( 0 )
, _pOrkidEngine		( 0 )
, _pOrkidScene		( 0 )
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdExportCommand destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdExportCommand::~OkdExportCommand()
{
	
}

//-----------------------------------------------------------------------------
// Name:		doIt
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
MStatus	OkdExportCommand::doIt(const MArgList&	args)
{
	beginExport();
	exportSceneGraph();
	endExport();

	return	( MStatus::kSuccess );
}

//-----------------------------------------------------------------------------
// Name:		exportSceneGraph
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdExportCommand::exportSceneGraph()
{
	MItDag		itDag( MItDag::kDepthFirst, MFn::kInvalid, &_status );
	MDagPath	rootPath;
	OkdScenePtr	scenePtr;

	// Create the scene
	scenePtr.bind( _strSceneName );
	_pOrkidScene = scenePtr.getResource();

	// Iterate through all the nodes starting at the world node
	itDag.getPath( rootPath );

	MFnDagNode rootDagNode( rootPath, &_status );
	exportDagNode( rootDagNode, 0 );

	_pOrkidScene = 0;
	scenePtr.save();
}

//-----------------------------------------------------------------------------
// Name:		exportDagNode
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdExportCommand::exportDagNode(const MFnDagNode&	fnDagNode, 
										OkdNode*			pParentNode)
{
	OkdString	strNodeName( fnDagNode.name().asChar() );
	OkdString	strNodeTypeName( fnDagNode.typeName().asChar() );
	MFn::Type	eNodeType		= fnDagNode.object().apiType();
	bool		bIsDefaultNode	= fnDagNode.isDefaultNode();
	OkdNode*	pOrkidNode		= 0;
	MDagPath	nodePath;

	fnDagNode.getPath( nodePath );

	OkdString strNodePathName( nodePath.fullPathName().asChar() );
	WRITE_LOG_INFOS( nodePath.length(), strNodeName << ": " << strNodeTypeName << " - Path: " << strNodePathName << "\n" );

	switch	( eNodeType )
	{
	case MFn::kWorld:
		pOrkidNode = _pOrkidScene->getRootNode();
		break;

	case MFn::kTransform:
		if	( !bIsDefaultNode )
		{
			pOrkidNode = exportTransform( nodePath, pParentNode );
		}
		break;

	case MFn::kMesh:
		exportMesh( nodePath, pParentNode );
		break;

	default:
		break;
	}

	if	( pOrkidNode )
	{
		uint uiChildCount = fnDagNode.childCount();

		for	( uint i = 0; i < uiChildCount; i++ )
		{
			MFnDagNode childNode( fnDagNode.child( i ), &_status );
			exportDagNode( childNode, pOrkidNode );
		}

		uint32 uiChildNodeCount = pOrkidNode->getChildCount();
		uint32 uiEntityCount	= pOrkidNode->getEntityCount();

		if	( ( uiChildNodeCount == 0 ) && ( uiEntityCount == 0 ) )
		{
			pParentNode->removeChildNode( pOrkidNode );
		}
	}
}

//-----------------------------------------------------------------------------
// Name:		exportTransform
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdNode*	OkdExportCommand::exportTransform(const MDagPath&	transformPath, 
											  OkdNode*			pParentNode)
{
	MFnTransform	fnTransform( transformPath, &_status );
	MVector			vLocal		= fnTransform.getTranslation( MSpace::kTransform, &_status );
	OkdNode*		pOrkidNode	= _pOrkidScene->createNode( pParentNode );

	WRITE_LOG_INFOS( transformPath.length(), "Local transform: " << vLocal.x << " " << vLocal.y << " " << vLocal.z << "\n" );

	return	( pOrkidNode );
}

//-----------------------------------------------------------------------------
// Name:		exportMesh
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdExportCommand::exportMesh(const MDagPath&	meshPath, 
									 OkdNode*			pNode)
{
	MFnMesh			fnMesh( meshPath, &_status );
	uint			uiVertexCount	= fnMesh.numVertices( &_status );
	uint			uiPolygonCount	= fnMesh.numPolygons( &_status );
	const float*	pLocalPoints	= fnMesh.getRawPoints( &_status );
	OkdMeshInfo		meshInfo( uiVertexCount, uiPolygonCount );
	OkdMeshPtr		meshPtr;
	
	meshPtr.bind( fnMesh.name().asChar() );
	
	OkdMesh* pOrkidMesh = meshPtr.getResource();
	
	WRITE_LOG_INFOS( meshPath.length() + 1, "Normals count: " << fnMesh.numNormals( &_status ) << "\n" );
	WRITE_LOG_INFOS( meshPath.length() + 1, "UVs count: " << fnMesh.numUVs( &_status ) << "\n" );
	WRITE_LOG_INFOS( meshPath.length() + 1, "Vertices count: " << fnMesh.numVertices( &_status ) << "\n" );
	
	for	( uint i = 0; i < uiVertexCount; i++ )
	{
		WRITE_LOG_INFOS( meshPath.length() + 2, pLocalPoints[3*i] << ", " << pLocalPoints[3*i+1] << ", " << pLocalPoints[3*i+2] << "\n" );
	}
	
	pOrkidMesh->create( meshInfo );
	pOrkidMesh->setVertexArray( pLocalPoints );
	
	WRITE_LOG_INFOS( meshPath.length() + 1, "Polygons count: " << uiPolygonCount << "\n" );
				
	for	( uint i = 0; i < uiPolygonCount; i++ )
	{
		if	( fnMesh.polygonVertexCount( i, &_status ) != 3 )
		{
			WRITE_LOG_INFOS( meshPath.length() + 2, "Polygon " << i << " is not a triangle" );
			return;
		}
	
		int vertexIdArray[3];
	
		fnMesh.getPolygonTriangleVertices( i, 0, vertexIdArray );
		pOrkidMesh->setPolygon( i, (const uint*)vertexIdArray );
	
		WRITE_LOG_INFOS( meshPath.length() + 2, vertexIdArray[0] << ", " << vertexIdArray[1] << ", " << vertexIdArray[2] << "\n" );
	}

	OkdMeshInstance* pMeshInstance = new OkdMeshInstance();

	pMeshInstance->setMeshPtr( meshPtr );
	pNode->addEntity( pMeshInstance );

	//meshPtr.save();
}

//-----------------------------------------------------------------------------
// Name:		beginExport
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdExportCommand::beginExport()
{
	_pOrkidEngine = OrkidEngine::create();

	MString		strFileName = MFileIO::currentFile();
	OkdString	strLogFileName;
	MFileObject sceneFileObject;

	sceneFileObject.setRawFullName( strFileName );

	MString strFilePath		= sceneFileObject.resolvedPath();
	MString strSceneName	= sceneFileObject.resolvedName();
	uint	uiDotPosition	= strSceneName.rindex( '.' );

	_strSceneName = strSceneName.substring( 0, uiDotPosition - 1 ).asChar();

	strLogFileName = strFilePath.asChar();
	strLogFileName += _strSceneName + ".log";

	_pExportLogStream = new OkdFileStream( strLogFileName, OkdFileStream::OpenModeOut | OkdFileStream::OpenModeTrunc );
}

//-----------------------------------------------------------------------------
// Name:		endExport
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdExportCommand::endExport()
{
	_pExportLogStream->close();
	_pOrkidEngine = 0;

	OrkidEngine::destroy();
}

//-----------------------------------------------------------------------------
// Name:		creator
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void*	OkdExportCommand::creator()
{
	return	( (void*)(new OkdExportCommand()) );
}