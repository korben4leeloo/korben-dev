//*****************************************************************************
//
//	Class:		KmWindow
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __KosmoCore_KmWindow_h__
#define __KosmoCore_KmWindow_h__

#include	"Root.h"
#include	<Windows.h>

KOSMO_CORE_NAMESPACE_BEGIN

class KmWindow
{
public:
							KmWindow();
							~KmWindow();

	void					create();	

private:
	static LRESULT CALLBACK	windowMessageCallback( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );

	HWND					_hWnd;
};

//*****************************************************************************
//	Inline methods declarations
//*****************************************************************************

KOSMO_CORE_NAMESPACE_END

#endif