//*****************************************************************************
//
//	Class:		KsWindow
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __KosmoCore_KsWindow_h__
#define __KosmoCore_KsWindow_h__

#include	"Root.h"
#include	<Windows.h>

KOSMO_CORE_NAMESPACE_BEGIN

class KsWindow
{
public:
							KsWindow();
							~KsWindow();

	void					create();	

private:
	static LRESULT CALLBACK	windowMessageCallback( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );

	HWND					_hWnd;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

KOSMO_CORE_NAMESPACE_END

#endif