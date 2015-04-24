//*****************************************************************************
//
//	File:		KosmoCoreRoot.h
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __KosmoCore_KosmoCoreRoot_h__
#define __KosmoCore_KosmoCoreRoot_h__

#include	<stddef.h>
#include	<stdint.h>
#include	<cassert>

// Architecture macros definition
#if defined( _M_X64 ) || defined ( _M_AMD64 )
	#define	KOSMO_X64
#else
	#define	KOSMO_X86
#endif

// Namespace macros definition
#define	KOSMO_CORE_NAMESPACE_BEGIN	namespace Kosmo	{ namespace Core {
#define	KOSMO_CORE_NAMESPACE_END	} }

// Compile-time messaging
#define	KOSMO_MSG_START ">>>>>>>>>>>>>>>>>>>> "
#define	KOSMO_MSG_END	" <<<<<<<<<<<<<<<<<<<<\n"

#define KOSMO_MSG( msg ) __pragma(message( "\n\t" ## KOSMO_MSG_START ## "[COMPILE-TIME MESSAGE] " ## msg ## KOSMO_MSG_END ) )

#define KOSMO_TODO( msg ) KOSMO_MSG( "TODO: " ## msg )

// Assertion macros definition
#ifdef KOSMO_X64
	#define KOSMO_ASSERT( condition ) if ( !(condition) ) __debugbreak();
#elif defined KOSMO_X86
	#define KOSMO_ASSERT( condition ) if ( !(condition) ) __asm int 3
#else
	#define KOSMO_ASSERT( condition )
#endif

// Inclusions macros definition
#define	KOSMO_CORE_H(file)	<KosmoCore/Sources/file.h>

// Primitive typedefs
typedef uint8_t			uint8;
typedef uint16_t		uint16;
typedef uint32_t		uint32;
typedef uint64_t		uint64;

typedef int8_t			int8;
typedef int16_t			int16;
typedef int32_t			int32;
typedef int64_t			int64;

typedef unsigned char	KmByte;

// Common namespace usage
KOSMO_CORE_NAMESPACE_BEGIN
KOSMO_CORE_NAMESPACE_END
using namespace Kosmo::Core;

#endif
