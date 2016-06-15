//*****************************************************************************
//
//	File:		main.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "Root.h"

#include <Windows.h>

#include TARS_CORE_H(Application/TkWin32App)
#include TARS_CORE_H(Window/TkWin32Wnd)
#include TARS_CORE_H(Events/TkEventManager)
#include TARS_CORE_H(String/TkString)

//-----------------------------------------------------------------------------
// Name:		WinMain
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
int WinMain( __in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in_opt LPSTR lpCmdLine, __in int nShowCmd )
{
	/*TkWin32Wnd*		pMainWindow		= new TkWin32Wnd();
	TkEventManager*	pEventManager	= new TkEventManager();

	pMainWindow->setEventManager( pEventManager );
	pMainWindow->create( hInstance );
	pMainWindow->show();*/

	/*while ( 1 )
	{
		Sleep( 0 );
	}*/

	TkString s1;
	TkString s2( 0 );
	TkString s3( "" );
	TkString s4( "prout" );
	TkString s5 = "prout prout";
	TkString s6 = s4;

	TkString s7 = s1 + s2;

	s7 = s1 + s6;
	s7 = s6 + s4;
	s7 = s5 + s4;
	s7 = s6 + "troululu";

	TkWin32App* pWin32App = new TkWin32App( hInstance );

	pWin32App->createWindow();
	pWin32App->runMessageLoop();	

	return 0;
}
