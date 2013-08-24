#include <maya/MFnPlugin.h>
#include <maya/MPxFileTranslator.h>
#include <maya/MFileIO.h>
#include <maya/MItDependencyNodes.h>
#include <maya/MItDag.h>
#include <maya/MDagPath.h>
#include <maya/MFnDagNode.h>
#include <maya/MFnTransform.h>
#include <maya/MVector.h>

#include <QFile>
#include <QTextStream>

class OrkidFileTranslator: public MPxFileTranslator
{
public:
	virtual bool 	haveWriteMethod() const;
	virtual MStatus writer( const MFileObject &file, const MString &optionsString, FileAccessMode mode );
	static void*	creator();
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
	MItDag		itDag( MItDag::kDepthFirst, MFn::kInvalid, &status );

	while	( itDag.isDone() == false )
	{
		MDagPath dagPath;
		status = itDag.getPath( dagPath );

		MFnDagNode	dagNode( dagPath, &status );
		QString		strNodeName( dagNode.name().asChar() );
		QString		strFullPathName( dagPath.fullPathName().asChar() );
		QString		strNodeTypeName( dagNode.typeName().asChar() );

		for	( uint i = 0; i < itDag.depth(); i++ )
		{
			exportStream << "\t";
		}

		exportStream << strNodeName << ": " << strNodeTypeName << " - Path: " << strFullPathName;

		if	( dagPath.hasFn( MFn::kTransform ) )
		{
			MFnTransform	fnTransform( dagPath, &status );
			MVector			vLocal = fnTransform.getTranslation( MSpace::kTransform, &status );

			exportStream << " - Local transform: " << vLocal.x << " " << vLocal.y << " " << vLocal.z;
		}

		exportStream << "\n";

		itDag.next();
	}

	exportStream << "\n\nDependecy Nodes\n";

	MItDependencyNodes itDependencyNodes( MFn::kInvalid, &status );

	while	( itDependencyNodes.isDone() == false )
	{
		MFnDependencyNode	dependencyNode( itDependencyNodes.thisNode(), &status );
		QString				strDependencyNodeName( dependencyNode.name().asChar() );
		QString				strDependencyNodeTypeName( dependencyNode.typeName().asChar() );

		exportStream << strDependencyNodeName << ": " << strDependencyNodeTypeName << "\n";

		itDependencyNodes.next();
	}

	exportFile.close();

	return	( MStatus::kSuccess );
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