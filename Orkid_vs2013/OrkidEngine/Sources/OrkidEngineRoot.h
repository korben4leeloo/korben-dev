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

	OrkidVertexShader,
	OrkidFragmentShader,
	OrkidGeometryShader,
	OrkidShaderProgram,

	OrkidResourceTypeCount,
	OrkidResourceTypeUnknown = 0xFFFFFFFF
};

enum OkdEntityType
{
	OrkidCamera,
	OrkidLight,
	OrkidShape,
	OrkidCreature,

	OrkidEntityTypeCount,
	OrkidEntityTypeUnknown = 0xFFFFFFFF
};

template<class T>
using pfnOkdResourceAllocator = T* (*)();

#endif
