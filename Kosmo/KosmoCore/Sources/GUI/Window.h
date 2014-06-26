//*****************************************************************************
//
//	Class:		Window
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __KosmoCore_Window_h__
#define __KosmoCore_Window_h__

#include	"Root.h"
#include	<Windows.h>

KOSMO_CORE_NS_BEGIN

class Window
{
public:
			Window();
			~Window();

	void	create();	

private:
	HWND	_hwnd;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

KOSMO_CORE_NS_END

#endif