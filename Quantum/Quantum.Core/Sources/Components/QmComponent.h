//*****************************************************************************
//
//	Class:		QmComponent
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __QUANTUM_CORE_TK_COMPONENT_H__
#define __QUANTUM_CORE_TK_COMPONENT_H__

#include "Root.h"

class QmComponentDescriptor;

class QmComponent
{
public:
							QmComponent();
							~QmComponent();

private:
	QmComponentDescriptor*	_pDescriptor;
};

#endif