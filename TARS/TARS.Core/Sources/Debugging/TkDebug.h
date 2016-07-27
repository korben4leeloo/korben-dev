//*****************************************************************************
//
//	Class:		TkDebug
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_CORE_TK_DEBUG_H__
#define __TARS_CORE_TK_DEBUG_H__

#include "Root.h"

class TkString;

#define TARS_MESSAGE( fmt, ... ) TkDebug::outputMessage( TkString::format( fmt, __VA_ARGS__ ) )

class TkDebug
{
public:
					
	static void	outputMessage( const TkString& strOutputMessage );

private:
				TkDebug();
				~TkDebug();
};

#endif