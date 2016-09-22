//*****************************************************************************
//
//	Class:		TkComponentDescriptor
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_CORE_TK_COMPONENT_DESCRIPTOR_H__
#define __TARS_CORE_TK_COMPONENT_DESCRIPTOR_H__

#include "Root.h"

class TkPropertyDescriptor;

class TkComponentDescriptor
{
public:
								TkComponentDescriptor();
								~TkComponentDescriptor();

private:
	TkVector<TkPropertyDescriptor*>	_properties;
};

#endif