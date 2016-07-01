//*****************************************************************************
//
//	File:		TarsRoot.h
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_ROOT_H__
#define __TARS_ROOT_H__

#include <stddef.h>
#include <stdint.h>
#include <assert.h>

// Debug macros
#ifdef _DEBUG
	#ifndef TARS_DEBUG
		#define TARS_DEBUG
	#endif
#endif

// Assertions
#ifdef TARS_DEBUG
	#define TARS_ASSERT( condition ) assert( condition )
	#define TARS_BREAK() TARS_ASSERT( false )
#else
	#define TARS_ASSERT( condition )
	#define TARS_BREAK()
#endif

// Compile-time messaging
#define	TARS_MSG_START	">>>>>>>>>>>>>>>>>>>> "
#define	TARS_MSG_END	" <<<<<<<<<<<<<<<<<<<<\n"
#define TARS_MSG( msg ) __pragma(message( "\n\t" ## TARS_MSG_START ## "[COMPILE-TIME MESSAGE] " ## msg ## TARS_MSG_END ) )
#define TARS_TODO( msg ) TARS_MSG( "TODO: " ## msg )

// Include macros
#ifdef USE_TARS_CORE
#define TARS_CORE_H( header ) <TARS.Core/Sources/header.h>
#endif

#ifdef USE_TARS_RUNTIME
#define TARS_RUNTIME_H( header ) <TARS.Runtime/Sources/header.h>
#endif

// Integer types
typedef int8_t		int8;
typedef int16_t		int16;
typedef int32_t		int32;
typedef int64_t		int64;
typedef uint8_t		uint8;
typedef uint16_t	uint16;
typedef uint32_t	uint32;
typedef uint64_t	uint64;

#endif