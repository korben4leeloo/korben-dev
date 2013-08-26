//*****************************************************************************
//
//	Class:		OrkidFileTranslator
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidFileTranslator_h__
#define __OrkidFileTranslator_h__

#include <maya/MPxFileTranslator.h>

class QFile;
class QTextStream;

namespace Orkid
{
	class OrkidFileTranslator: public MPxFileTranslator
	{
	public:
						OrkidFileTranslator();
						~OrkidFileTranslator();

		// MPxFileTranslator overloading
		virtual bool 	haveWriteMethod() const;
		virtual MStatus writer( const MFileObject& file, const MString& optionsString, FileAccessMode mode );

		// MFnPlugin creator
		static void*	creator();

	private:
		void			beginExport( const MFileObject& file );
		void			endExport();

		void			exportSceneGraph();

		QFile*			_pExportFile;
		QTextStream*	_pExportStream;
	};
}

#endif
