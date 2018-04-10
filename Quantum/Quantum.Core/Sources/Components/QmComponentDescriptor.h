//*****************************************************************************
//
//	Class:		QmComponentDescriptor
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __QUANTUM_CORE_TK_COMPONENT_DESCRIPTOR_H__
#define __QUANTUM_CORE_TK_COMPONENT_DESCRIPTOR_H__

#include "Root.h"

class QmPropertyDescriptor;

class QmComponentDescriptor
{
public:
								QmComponentDescriptor();
								~QmComponentDescriptor();

private:
	QmVector<QmPropertyDescriptor*>	_properties;
};

#endif