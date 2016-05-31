//*****************************************************************************
//
//	Class:		OkdFile
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdFile_h__
#define __OrkidCore_OkdFile_h__

#include	"Root.h"

//#include	<fstream>

//#include	<QtCore/QFile>

//typedef	QFile OkdFile;

//class OkdString;
//
//class OkdFile
//{
//public:
//	enum OrkidFileOpenMode
//	{
//		OKD_FILE_OPEN_MODE_NEW			= 1 << 0,
//		OKD_FILE_OPEN_MODE_APPEND		= 1 << 1,
//		OKD_FILE_OPEN_MODE_READ			= 1 << 2,
//		OKD_FILE_OPEN_MODE_WRITE		= 1 << 3,
//
//		OKD_FILE_OPEN_MODE_READWRITE	= OKD_FILE_OPEN_MODE_READ | OKD_FILE_OPEN_MODE_WRITE
//	};
//
//					OkdFile();
//					~OkdFile();
//
//	void			open( const OkdString& strFileName, const OrkidFileOpenMode openMode );
//	void			close();
//
//	inline void		write( const char* pBuffer, const uint uiLength );
//
//	//inline OkdFile&	operator<<( OkdString& str );
//
//private:
//	//QFile			_file;
//	std::fstream	_file;
//};
//
////*****************************************************************************
////	Inline functions declarations
////*****************************************************************************
//
////-----------------------------------------------------------------------------
//// Name:		write
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//void	OkdFile::write(const char*	pBuffer, 
//					   const uint	uiLength)
//{
//	_file.write( pBuffer, uiLength );
//}

////-----------------------------------------------------------------------------
//// Name:		operator<<
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//OkdFile&	OkdFile::operator<<( OkdString& str )
//{
//	
//}

#endif