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
public:
			TkString();
			~TkString();

private:
	char*	_pcBuffer;
	int		_nSize;
};

#endif