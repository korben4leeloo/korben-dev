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

// Defines for inclusions
#define	ORKID_CORE_H(file)			<OrkidCore/Sources/file.h>
#define	ORKID_ENGINE_H(file)		<OrkidEngine/Sources/file.h>
#define	ORKID_EDITOR_H(file)		<OrkidEditor/Sources/file.h>
#define	ORKID_RUNTIME_H(file)		<OrkidRuntime/Sources/file.h>
#define	ORKID_MAYA_EXPORTER_H(file)	<OrkidExporters/OrkidMayaExporter/Sources/file.h>

#define	ORKID_MATH_H(file)			ORKID_CORE_H(Math/file)

#define	ORKID_ASSERT(a)				assert(a)

// DLL import/export defines
#ifdef ORKID_DLL
	#define ORKID_EXPORT __declspec(dllexport)
#else
	#define ORKID_EXPORT __declspec(dllimport)
#endif

// Typedefs
typedef unsigned int	uint;

// Enums
enum OrkidErrorCode
{
	OKD_OK,
	OKD_FAIL,
};

#endif
