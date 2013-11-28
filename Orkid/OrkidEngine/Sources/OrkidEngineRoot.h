//*****************************************************************************
//
//	File:		OrkidEngineRoot.h
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OrkidEngineRoot_h__
#define __OrkidCore_OrkidEngineRoot_h__

#include	"../../OrkidRoot.h"

enum OkdResourceType
{
	OrkidMesh,
	OrkidScene,

	OrkidResourceTypeCount,
	OrkidResourceTypeUnknown = 0xFFFFFFFF
};

enum OkdEntityType
{
	OrkidCamera,
	OrkidLight,
	OrkidShape,
	OrkidCharacter,

	OrkidEntityTypeCount,
	OrkidEntityTypeUnknown = 0xFFFFFFFF
};

#endif
