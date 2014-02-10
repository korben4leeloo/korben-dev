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
#include	"../../OrkidCore/Sources/OrkidCoreRoot.h"

// Defines for inclusions
#define	ORKID_ENGINE_H(file) <OrkidEngine/Sources/file.h>

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

template<class T>
using pfnOkdResourceAllocator = T* (*)();

#endif
