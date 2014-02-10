//*****************************************************************************
//
//	File:		OrkidCoreRoot.h
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OrkidCoreRoot_h__
#define __OrkidCore_OrkidCoreRoot_h__

#include	"../../OrkidRoot.h"

// Defines for inclusions
#define	ORKID_CORE_H(file)	<OrkidCore/Sources/file.h>
#define	ORKID_MATH_H(file)	ORKID_CORE_H(Math/file)

#include	ORKID_CORE_H(Memory/OkdMemManager)

typedef uint32 OkdComponentId;

#endif
