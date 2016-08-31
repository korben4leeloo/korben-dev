//*****************************************************************************
//
//	Class:		TkOpenGLApi
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_CORE_TK_OPEN_GL_API_H__
#define __TARS_CORE_TK_OPEN_GL_API_H__

#include "Root.h"

class TkOpenGLContext;

class TkOpenGLApi
{
public:
	static void	init();

private:
				TkOpenGLApi();
				~TkOpenGLApi();

	static bool	_bApiLoaded;
};

#endif