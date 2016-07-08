//*****************************************************************************
//
//	Class:		TkWglContext
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_CORE_TK_WGL_CONTEXT_H__
#define __TARS_CORE_TK_WGL_CONTEXT_H__

#include "Root.h"

class TkWin32Wnd;

class TkWglContext
{
public:
						TkWglContext( const TkWin32Wnd* pWindow );
						~TkWglContext();

	void				init();

private:
	const TkWin32Wnd*	_pWindow;
};

#endif