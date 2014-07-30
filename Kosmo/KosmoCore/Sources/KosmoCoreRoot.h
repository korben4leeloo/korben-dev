//*****************************************************************************
//
//	File:		KosmoCoreRoot.h
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __KosmoCore_KosmoCoreRoot_h__
#define __KosmoCore_KosmoCoreRoot_h__

#include	<stdint.h>
#include	<cassert>

#define	KOSMO_CORE_NAMESPACE_BEGIN	\
namespace Kosmo				\
{							\
	namespace Core			\
	{						\

#define	KOSMO_CORE_NAMESPACE_END	\
	}						\
}							\

//#define KOSMO_ASSERT( condition ) assert( condition );
//#define KOSMO_ASSERT( condition ) if ( !((bool)condition) ) __debugbreak();
#define KOSMO_ASSERT( condition ) if ( !(condition) ) __debugbreak();

// Defines for inclusions
#define	KOSMO_CORE_H(file)	<KosmoCore/Sources/file.h>

//#include	ORKID_CORE_H(Memory/OkdMemManager)

typedef uint8_t			uint8;
typedef uint16_t		uint16;
typedef uint32_t		uint32;
typedef uint64_t		uint64;

typedef int8_t			int8;
typedef int16_t			int16;
typedef int32_t			int32;
typedef int64_t			int64;

typedef unsigned char	KmByte;

KOSMO_CORE_NAMESPACE_BEGIN
KOSMO_CORE_NAMESPACE_END
using namespace Kosmo::Core;

#endif
