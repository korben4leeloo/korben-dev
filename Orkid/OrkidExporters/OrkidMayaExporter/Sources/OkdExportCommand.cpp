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
#include	ORKID_ENGINE_H(Entities/OkdMesh)
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
	bool		bRecurse		= false;
	MDagPath	nodePath;

	switch	( eNodeType )
	{
	case MFn::kWorld:
		bRecurse = true;
		break;

	case MFn::kTransform:
		if	( !bIsDefaultNode )
		{
			pOrkidNode	= _pOrkidScene->createNode( pParentNode );
			bRecurse	= true;
		}
		break;

	case MFn::kMesh:
		break;

	default:
		break;
	}

	/*_status = fnDagNode.getPath( nodePath );

	if	( pParentNode )
	{
		bool bIsDefaultNode = fnDagNode.isDefaultNode();
		bool bHasTransform	= nodePath.hasFn( MFn::kTransform );

		if	( bIsDefaultNode || !bHasTransform )
		{
			return;
		}

		MFnTransform fnTransform( nodePath );
		pOrkidNode = _pOrkidScene->createNode( pParentNode );
	}
	else
	{
		pOrkidNode = _pOrkidScene->getRootNode();
	}*/

	if	( bRecurse )
	{
		uint uiChildCount = fnDagNode.childCount();

		for	( uint i = 0; i < uiChildCount; i++ )
		{
			MFnDagNode childNode( fnDagNode.child( i ), &_status );
			exportDagNode( childNode, pOrkidNode );
		}
	}
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