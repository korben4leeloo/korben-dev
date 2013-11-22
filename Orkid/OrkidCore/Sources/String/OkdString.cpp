//*****************************************************************************
//
//	File:		OkdString.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdString.h"

//-----------------------------------------------------------------------------
// Name:		OkdString constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdString::OkdString()
{

}

//-----------------------------------------------------------------------------
// Name:		OkdString constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdString::OkdString(const std::string&	s)
: _str( s )
{

}

//-----------------------------------------------------------------------------
// Name:		OkdString constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdString::OkdString(const char*	pBuffer)
: _str( pBuffer )
{

}

//-----------------------------------------------------------------------------
// Name:		OkdString destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdString::~OkdString()
{
	
}

//-----------------------------------------------------------------------------
// Name:		replace
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdString::replace( const OkdString& strSourcePattern, const OkdString& strTargetPattern )
{
	int uiOffset				= 0;
	int nPatternPos				= _str.find( strSourcePattern._str, uiOffset );
	int nSourcePatternLength	= strlen( strSourcePattern._str.data() );
	int nTargetPatternLength	= strlen( strTargetPattern._str.data() );

	while	( nPatternPos != std::string::npos )
	{
		_str.replace( nPatternPos, nSourcePatternLength, strTargetPattern._str );
		nPatternPos = _str.find( strSourcePattern._str, nPatternPos + nTargetPatternLength );
	}
}

//-----------------------------------------------------------------------------
// Name:		split
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
uint32	OkdString::split(const OkdString&		strDelimiter, 
						 OkdVector<OkdString>&	outTokens)
{
	uint32	uiOffset		= 0;
	uint32	nPatternLength	= strDelimiter.size();
	int		nPatternPos		= _str.find( strDelimiter._str, uiOffset );

	outTokens.clear();

	while	( nPatternPos != std::string::npos )
	{
		OkdString strToken = _str.substr( uiOffset, nPatternPos - uiOffset );

		outTokens.add( strToken );

		uiOffset	= nPatternPos + nPatternLength;
		nPatternPos = _str.find( strDelimiter._str, uiOffset );
	}

	if	( uiOffset < _str.size() )
	{
		OkdString strToken = _str.substr( uiOffset, _str.size() );
		outTokens.add( strToken );
	}

	return	( outTokens.size() );
}