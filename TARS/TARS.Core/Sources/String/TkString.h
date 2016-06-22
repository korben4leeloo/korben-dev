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

class TkBinaryFile;

class TkString
{
	friend bool operator==( const TkString& lhs, const TkString& rhs );
	friend bool operator!=( const TkString& lhs, const TkString& rhs );
	friend TkString operator+( const TkString& lhs, const TkString& rhs );
	friend const TkBinaryFile& operator>>( const TkBinaryFile& file, TkString& s );

public:
						TkString();
						TkString( const char* pcBuffer );
						TkString( const TkString& rhs );
						~TkString();

	TkString&			operator=( const TkString& rhs );

	inline const char*	buffer() const;
	inline uint32		size() const;

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

TkBinaryFile& operator<<( TkBinaryFile& file, const TkString& s );

#endif