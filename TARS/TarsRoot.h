//*****************************************************************************
//
//	File:		TarsRoot.h
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_ROOT_H__
#define __TARS_ROOT_H__

#include <stdint.h>

#ifdef USE_TARS_CORE
#define TARS_CORE_H( header ) <TARS.Core/Sources/header.h>
#endif

#ifdef USE_TARS_RUNTIME
#define TARS_RUNTIME_H( header ) <TARS.Runtime/Sources/header.h>
#endif

#endif