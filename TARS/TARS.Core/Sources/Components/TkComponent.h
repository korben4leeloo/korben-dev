//*****************************************************************************
//
//	Class:		TkComponent
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_CORE_TK_COMPONENT_H__
#define __TARS_CORE_TK_COMPONENT_H__

#include "Root.h"

class TkComponentDescriptor;

class TkComponent
{
public:
							TkComponent();
							~TkComponent();

private:
	TkComponentDescriptor*	_pDescriptor;
};

#endif