//*****************************************************************************
//
//	Class:		TkString
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_CORE_TK_STRING_H__
#define __TARS_CORE_TK_STRING_H__

class TkString
{
	friend bool operator==( const TkString& lhs, const TkString& rhs );

public:
				TkString();
				TkString( const char* pcBuffer );
				TkString( const TkString& rhs );
				~TkString();

	TkString&	operator=( const TkString& rhs );

private:
	inline void	clear();
	void		copy( const char* pcBuffer );

	char*		_pcBuffer;
	uint32		_nSize;
};

//-----------------------------------------------------------------------------
// Name:		clear
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void TkString::clear()
{
	delete[] _pcBuffer;

	_pcBuffer	= NULL;
	_nSize		= 0;
}

#endif