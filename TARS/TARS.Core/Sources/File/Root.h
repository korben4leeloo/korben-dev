//*****************************************************************************
//
//	File:		Root.h
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_CORE_FILE_ROOT_H__
#define __TARS_CORE_FILE_ROOT_H__

#include "../Root.h"

enum TARS_FILE_MODE
{
	TARS_FILE_MODE_IN,
	TARS_FILE_MODE_OUT,
	TARS_FILE_MODE_OUT_APPEND,
	TARS_FILE_MODE_IN_OUT,
	TARS_FILE_MODE_IN_OUT_CREATE,
	TARS_FILE_MODE_IN_OUT_APPEND,

	TARS_FILE_MODE_COUNT
};

#endif