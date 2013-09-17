//*****************************************************************************
//
//	Class:		OkdFileStream
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdFileStream_h__
#define __OrkidCore_OkdFileStream_h__

//#include	<QtCore/QDataStream>
//#include	<QtCore/QTextStream>

#include <fstream>
typedef	std::fstream OkdFileStream;

////-----------------------------------------------------------------------------
//// Name:		operator<<
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//OkdFileStream& operator<<(OkdFileStream&	stream, 
//						  const char*		str)
//{
//	stream.write( str, strlen(str) );
//	return	( stream );
//}

//typedef QDataStream OkdBinaryStream;
//typedef QTextStream OkdTextStream;

//class OkdFileStream
//{
//public:
//				OkdFileStream();
//				~OkdFileStream();
//
//	inline void	write( const char* pcBuffer, const uint uiBufferSize );
//
//private:
//	QDataStream	_stream;
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
//void	OkdFileStream::write(const char*	pcBuffer, 
//						 const uint		uiBufferSize)
//{
//	_stream.writeRawData( pcBuffer, uiBufferSize );
//}

#endif