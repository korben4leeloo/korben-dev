#include <maya/MFnPlugin.h>
#include <maya/MPxFileTranslator.h>
#include <maya/MFileIO.h>
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
	const MString strFileName = file.fullName();
	QFile exportFile( strFileName.asChar() );
	MStatus status;

	exportFile.open( QIODevice::WriteOnly );

	QTextStream exportStream( &exportFile );

	MItDag itDag( MItDag::kDepthFirst, MFn::kInvalid, &status );

	while	( itDag.isDone() == false )
	{
		MDagPath dagPath;
		status = itDag.getPath( dagPath );
		MFnDagNode dagNode( dagPath, &status );

		QString strNodeName( dagNode.name().asChar() );
		QString strNodeTypeName( dagNode.typeName().asChar() );

		exportStream << strNodeName << ": " << strNodeTypeName << "\n";

		if	( dagPath.hasFn( MFn::kTransform ) )
		{
			MFnTransform fnTransform( dagPath, &status );
			MVector v = fnTransform.getTranslation( MSpace::kTransform, &status );

			exportStream << "\t" << v.x << " " << v.y << " " << v.z << "\n";
		}

		itDag.next();
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