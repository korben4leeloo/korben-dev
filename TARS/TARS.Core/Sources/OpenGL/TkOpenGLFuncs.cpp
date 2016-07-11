//*****************************************************************************
//
//	File:		TkOpenGLFuncs.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "TkOpenGLFuncs.h"

TARS_OPEN_GL_FUNC_DEF( PFNGLGETSTRINGIPROC, glGetStringi )

bool TkOpenGLFuncs::_bLoaded = false;

void TkOpenGLFuncs::load()
{
	if	( _bLoaded )
	{
		return;
	}

	TARS_OPEN_GL_FUNC_PROC( PFNGLGETSTRINGIPROC, glGetStringi )

	_bLoaded = true;
}

