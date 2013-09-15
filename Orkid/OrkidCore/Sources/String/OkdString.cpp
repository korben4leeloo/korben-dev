//*****************************************************************************
//
//	File:		OkdString.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

//#include	"OkdString.h"
//
////-----------------------------------------------------------------------------
//// Name:		OkdString constructor
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//OkdString::OkdString()
//{
//
//}
//
////-----------------------------------------------------------------------------
//// Name:		OkdString constructor
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//OkdString::OkdString(const char*	pBuffer)
//: _str( pBuffer )
//{
//
//}
//
////-----------------------------------------------------------------------------
//// Name:		OkdString destructor
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//OkdString::~OkdString()
//{
//	
//}
//
////-----------------------------------------------------------------------------
//// Name:		replace
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//void	OkdString::replace( const OkdString& strSourcePattern, const OkdString& strTargetPattern )
//{
//	int uiOffset				= 0;
//	int nPatternPos				= _str.find( strSourcePattern._str, uiOffset );
//	int nSourcePatternLength	= strlen( strSourcePattern._str.data() );
//	int nTargetPatternLength	= strlen( strTargetPattern._str.data() );
//
//	while	( nPatternPos != std::string::npos )
//	{
//		_str.replace( nPatternPos, nSourcePatternLength, strTargetPattern._str );
//		nPatternPos = _str.find( strSourcePattern._str, nPatternPos + nTargetPatternLength );
//	}
//}
