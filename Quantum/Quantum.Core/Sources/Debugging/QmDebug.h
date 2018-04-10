//*****************************************************************************
//
//	Class:		QmDebug
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __QUANTUM_CORE_TK_DEBUG_H__
#define __QUANTUM_CORE_TK_DEBUG_H__

#include "Root.h"

class QmString;

#define QUANTUM_MESSAGE( fmt, ... ) QmDebug::outputMessage( QmString::format( fmt, __VA_ARGS__ ) )

class QmDebug
{
public:
					
	static void	outputMessage( const QmString& strOutputMessage );

private:
				QmDebug();
				~QmDebug();
};

#endif