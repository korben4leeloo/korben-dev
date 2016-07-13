//*****************************************************************************
//
//	Class:		TkWGLInterface
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_CORE_TK_WGL_INTERFACE_H__
#define __TARS_CORE_TK_WGL_INTERFACE_H__

#include "Root.h"

class TkWGLInterface
{
	friend class TkWGLContext;

private:
	static void	loadExtensions();
	static bool	_bExtensionsLoaded;
};

#endif