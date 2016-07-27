//*****************************************************************************
//
//	Class:		TkEntityComponent
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_CORE_TK_ENTITY_COMPONENT_H__
#define __TARS_CORE_TK_ENTITY_COMPONENT_H__

#include "Root.h"

class TkEntityProperty;

class TkEntityComponent
{
public:
								TkEntityComponent();
								~TkEntityComponent();

private:
	TkVector<TkEntityProperty*>	_properties;
};

#endif