//*****************************************************************************
//
//	File:		Root.h
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __QUANTUM_CORE_FILE_ROOT_H__
#define __QUANTUM_CORE_FILE_ROOT_H__

#include "../Root.h"

enum QUANTUM_FILE_MODE
{
	QUANTUM_FILE_MODE_IN,
	QUANTUM_FILE_MODE_OUT,
	QUANTUM_FILE_MODE_OUT_APPEND,
	QUANTUM_FILE_MODE_IN_OUT,
	QUANTUM_FILE_MODE_IN_OUT_CREATE,
	QUANTUM_FILE_MODE_IN_OUT_APPEND,

	QUANTUM_FILE_MODE_COUNT
};

#endif