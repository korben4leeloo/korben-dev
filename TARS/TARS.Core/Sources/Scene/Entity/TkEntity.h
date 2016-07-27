//*****************************************************************************
//
//	Class:		TkEntity
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_CORE_TK_ENTITY_H__
#define __TARS_CORE_TK_ENTITY_H__

#include "Root.h"

class TkEntityComponent;

class TkEntity
{
public:
									TkEntity();
									~TkEntity();

private:
	TkVector<TkEntityComponent*>	_components;
};

#endif