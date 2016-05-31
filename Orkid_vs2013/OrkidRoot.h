//*****************************************************************************
//
//	File:		OrkidRoot.h
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidRoot_h__
#define __OrkidRoot_h__

#include	<assert.h>
#include	<iosfwd>
#include	<stdint.h>

// Defines for inclusions
//#define	ORKID_CORE_H(file)			<OrkidCore/Sources/file.h>
//#define	ORKID_ENGINE_H(file)		<OrkidEngine/Sources/file.h>
#define	ORKID_EDITOR_H(file)		<OrkidEditor/Sources/file.h>
#define	ORKID_RUNTIME_H(file)		<OrkidRuntime/Sources/file.h>
#define	ORKID_MAYA_EXPORTER_H(file)	<OrkidExporters/OrkidMayaExporter/Sources/file.h>

//#define	ORKID_MATH_H(file)			ORKID_CORE_H(Math/file)

#define	ORKID_ASSERT(a)				assert(a)
#define	ORKID_BREAK()				assert(false)

// Math defines
#define OKD_PI				3.14159265358979323846
#define DEG_TO_RAD( angle )	( angle / 180.0f * (float)OKD_PI )

// DLL import/export defines
#ifdef ORKID_DLL
	#define ORKID_EXPORT __declspec(dllexport)
#else
	#define ORKID_EXPORT __declspec(dllimport)
#endif

// Helpers macros
#define OKD_CLEAR_POINTER( p )	\
	if	( p )					\
	{							\
		delete p;				\
		p = 0;					\
	}

// Typedefs
typedef unsigned int	uint;

typedef uint8_t			uint8;
typedef uint16_t		uint16;
typedef uint32_t		uint32;
typedef uint64_t		uint64;

typedef int8_t			int8;
typedef int16_t			int16;
typedef int32_t			int32;

// Enums
enum OrkidErrorCode
{
	OKD_OK,
	OKD_FAIL,
};

#endif
