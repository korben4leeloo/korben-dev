//*****************************************************************************
//
//	File:		QuantumRoot.h
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __QUANTUM_ROOT_H__
#define __QUANTUM_ROOT_H__

#include <stddef.h>
#include <stdint.h>
#include <assert.h>

// Debug macros
#ifdef _DEBUG
	#ifndef QUANTUM_DEBUG
		#define QUANTUM_DEBUG
	#endif
#endif

// Assertions
#ifdef QUANTUM_DEBUG
	#define QUANTUM_ASSERT( condition ) assert( condition )
	#define QUANTUM_BREAK() QUANTUM_ASSERT( false )
#else
	#define QUANTUM_ASSERT( condition )
	#define QUANTUM_BREAK()
#endif

// Compile-time messaging
#define	QUANTUM_MSG_START	">>>>>>>>>>>>>>>>>>>> "
#define	QUANTUM_MSG_END	" <<<<<<<<<<<<<<<<<<<<\n"
#define QUANTUM_MSG( msg ) __pragma(message( "\n\t" ## QUANTUM_MSG_START ## "[COMPILE-TIME MESSAGE] " ## msg ## QUANTUM_MSG_END ) )
#define QUANTUM_TODO( msg ) QUANTUM_MSG( "TODO: " ## msg )

// Include macros
#ifdef USE_QUANTUM_CORE
#define QUANTUM_CORE_H( header ) <Quantum.Core/Sources/header.h>
#endif

#ifdef USE_QUANTUM_RUNTIME
#define QUANTUM_RUNTIME_H( header ) <Quantum.Runtime/Sources/header.h>
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

// Win32 types overriding
typedef void* QmWin32Handle;

#endif