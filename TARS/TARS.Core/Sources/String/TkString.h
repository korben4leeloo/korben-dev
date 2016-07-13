//*****************************************************************************
//
//	Class:		TkString
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_CORE_TK_STRING_H__
#define __TARS_CORE_TK_STRING_H__

#include "Root.h"

#include TARS_CORE_H(Containers/TkVector)

class TkBinaryFile;
class TkTextFile;

class TkString
{
	// Operators
	friend bool operator==( const TkString& lhs, const TkString& rhs );
	friend bool operator!=( const TkString& lhs, const TkString& rhs );
	friend TkString operator+( const TkString& lhs, const TkString& rhs );

	// Stream operators
	friend const TkBinaryFile& operator>>( const TkBinaryFile& file, TkString& s );
	friend const TkTextFile& operator>>( const TkTextFile& file, TkString& s );

public:
						TkString();
						TkString( const char* pcBuffer );
						TkString( const TkString& rhs );
						~TkString();

	TkString&			operator=( const TkString& rhs );

	inline const char*	buffer() const;
	inline uint32		size() const;
	inline bool			isEmpty() const;

	void				split( const TkString& strSeparator, TkVector<TkString>& tokens );
	TkString			extract( const uint32 nStartPos, const int32 nEndPos = -1 );

private:
	inline void			clear();
	void				copy( const char* pcBuffer );

	char*				_pcBuffer;
	uint32				_nSize;
};

//-----------------------------------------------------------------------------
// Name:		clear
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void TkString::clear()
{
	delete[] _pcBuffer;

	_pcBuffer	= nullptr;
	_nSize		= 0;
}

//-----------------------------------------------------------------------------
// Name:		buffer
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const char* TkString::buffer() const
{
	return ( _pcBuffer );
}

//-----------------------------------------------------------------------------
// Name:		size
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
uint32 TkString::size() const
{
	return ( _nSize );
}

//-----------------------------------------------------------------------------
// Name:		isEmpty
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
bool TkString::isEmpty() const
{
	return ( _nSize == 0 );
}

TkBinaryFile& operator<<( TkBinaryFile& file, const TkString& s );

#endif