//*****************************************************************************
//
//	Class:		QmEntity
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __QUANTUM_CORE_TK_ENTITY_H__
#define __QUANTUM_CORE_TK_ENTITY_H__

#include "Root.h"

class QmEntityComponent;

class QmEntity
{
public:
									QmEntity();
									~QmEntity();

private:
	QmVector<QmEntityComponent*>	_components;
};

#endif