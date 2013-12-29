//*****************************************************************************
//
//	File:		OkdFile.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

//#include	"OkdFile.h"
//
//#include	ORKID_CORE_H(String/OkdString)
//
////#include	<io.h>
//
////-----------------------------------------------------------------------------
//// Name:		OkdFile constructor
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//OkdFile::OkdFile()
////: _pFile( 0 )
////: _nFileHandle( -1 )
//{
//	
//}
//
////-----------------------------------------------------------------------------
//// Name:		OkdFile destructor
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//OkdFile::~OkdFile()
//{
//	close();
//}
//
////-----------------------------------------------------------------------------
//// Name:		open
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//void	OkdFile::open(const OkdString&			strFileName, 
//					  const OrkidFileOpenMode	openMode)
//{
//	close();
//
//	_file.open( strFileName, 0 );
//
//	//_file.setFileName( strFileName );
//
//	/*errno_t result = fopen_s( &_pFile, pcFileName, "" );
//	ORKID_ASSERT( result == 0 );*/
//
//	/*errno_t result = _sopen_s( &_nFileHandle, pcFileName, 0, 0, 0 );
//	ORKID_ASSERT( result == 0 );*/
//}
//
////-----------------------------------------------------------------------------
//// Name:		close
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//void	OkdFile::close()
//{
//	_file.close();
//
//	/*if	( _pFile )
//	{
//		fclose( _pFile );
//		_pFile = 0;
//	}*/
//
//	/*if	( _nFileHandle != -1 )
//	{
//		_close( _nFileHandle );
//		_nFileHandle = -1;
//	}*/
//}
