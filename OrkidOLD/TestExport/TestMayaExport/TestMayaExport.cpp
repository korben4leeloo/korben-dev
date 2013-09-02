#include <maya/MFnPlugin.h>
#include <maya/MPxFileTranslator.h>
#include <maya/MFileIO.h>
#include <maya/MItDependencyNodes.h>
#include <maya/MItDag.h>
#include <maya/MDagPath.h>
#include <maya/MFnDagNode.h>
#include <maya/MFnTransform.h>
#include <maya/MFnMesh.h>
#include <maya/MVector.h>

#include <QFile>
#include <QTextStream>

QTextStream &	IndentTabs( QTextStream* pExportStream, uint uiDepth )
{
	for	( uint i = 0; i < uiDepth; i++ )
	{
		(*pExportStream) << "\t";
	}

	return	( *pExportStream );
}

class OrkidFileTranslator: public MPxFileTranslator
{
public:
	virtual bool 	haveWriteMethod() const;
	virtual MStatus writer( const MFileObject &file, const MString &optionsString, FileAccessMode mode );
	static void*	creator();

private:
	void			exportSceneGraph( QTextStream* pExportStream );
	void			exportDependencyNodes( QTextStream* pExportStream );
	void			exportMesh( MDagPath* pShapeDagPath );
};

bool OrkidFileTranslator::haveWriteMethod() const
{
	return	( true );
}

MStatus OrkidFileTranslator::writer(const MFileObject &file, const MString &optionsString, FileAccessMode mode)
{
	const MString	strFileName = file.fullName();
	QFile			exportFile( strFileName.asChar() );
	MStatus			status;

	exportFile.open( QIODevice::WriteOnly );

	QTextStream exportStream( &exportFile );
	
	exportSceneGraph( &exportStream );
	exportDependencyNodes( &exportStream );

	exportFile.close();

	return	( MStatus::kSuccess );
}

void OrkidFileTranslator::exportSceneGraph(QTextStream *	pExportStream)
{
	MStatus	status;
	//MItDag	itDag( MItDag::kDepthFirst, MFn::kInvalid, &status );
	MItDag	itDag( MItDag::kDepthFirst, MFn::kTransform, &status );

	while	( itDag.isDone() == false )
	{
		MDagPath dagPath;
		status = itDag.getPath( dagPath );

		MFnDagNode	dagNode( dagPath, &status );
		QString		strNodeName( dagNode.name().asChar() );
		QString		strFullPathName( dagPath.fullPathName().asChar() );
		QString		strNodeTypeName( dagNode.typeName().asChar() );
		uint		uiDepth = itDag.depth();

		IndentTabs( pExportStream, dagPath.length() ) << strNodeName << ": " << strNodeTypeName << " - Path: " << strFullPathName;

		MFnTransform	fnTransform( dagPath, &status );
		MVector			vLocal = fnTransform.getTranslation( MSpace::kTransform, &status );

		(*pExportStream) << " - Local transform: " << vLocal.x << " " << vLocal.y << " " << vLocal.z << "\n";

		status = dagPath.extendToShape();

		MFnDagNode	shapeDagNode( dagPath, &status );
		QString		strShapeNodeName( shapeDagNode.name().asChar() );
		QString		strShapeFullPathName( dagPath.fullPathName().asChar() );
		QString		strShapeNodeTypeName( shapeDagNode.typeName().asChar() );

		IndentTabs( pExportStream, dagPath.length() ) << strShapeNodeName << ": " << strShapeNodeTypeName << " - Path: " << strShapeFullPathName << "\n";

		if	( dagPath.hasFn( MFn::kMesh ) )
		{
			MFnMesh fnMesh( dagPath, &status );

			if	( status != MStatus::kSuccess )
			{
				QString strError( status.errorString().asChar() );
				IndentTabs( pExportStream, dagPath.length() + 1 ) << "Error: " << strError;
			}

			IndentTabs( pExportStream, dagPath.length() + 1 ) << "Polygons count: " << fnMesh.numPolygons( &status ) << "\n";
			IndentTabs( pExportStream, dagPath.length() + 1 ) << "Vertices count: " << fnMesh.numVertices( &status ) << "\n";
			IndentTabs( pExportStream, dagPath.length() + 1 ) << "Normals count: " << fnMesh.numNormals( &status ) << "\n";
			IndentTabs( pExportStream, dagPath.length() + 1 ) << "UVs count: " << fnMesh.numUVs( &status ) << "\n";
		}

		itDag.next();
	}
}

void OrkidFileTranslator::exportMesh( MDagPath* pShapeDagPath )
{

}

void	OrkidFileTranslator::exportDependencyNodes(QTextStream *	pExportStream)
{
	(*pExportStream) << "\n\nDependency Nodes\n";

	MStatus				status;
	MItDependencyNodes	itDependencyNodes( MFn::kInvalid, &status );

	while	( itDependencyNodes.isDone() == false )
	{
		MFnDependencyNode	dependencyNode( itDependencyNodes.thisNode(), &status );
		QString				strDependencyNodeName( dependencyNode.name().asChar() );
		QString				strDependencyNodeTypeName( dependencyNode.typeName().asChar() );

		(*pExportStream) << strDependencyNodeName << ": " << strDependencyNodeTypeName << "\n";

		itDependencyNodes.next();
	}
}

void* OrkidFileTranslator::creator()
{
	return	( (void*)(new OrkidFileTranslator()) );
}

MStatus __declspec(dllexport) initializePlugin(MObject obj)
{
	MFnPlugin	plugin( obj );
	MStatus		status;
	MString		strStatus;

	status = plugin.registerFileTranslator( "OrkidExporter", "", OrkidFileTranslator::creator );
	strStatus = status.errorString();

	return	( MStatus::kSuccess );
}

MStatus __declspec(dllexport) uninitializePlugin(MObject obj)
{
	return	( MStatus::kSuccess );
}
