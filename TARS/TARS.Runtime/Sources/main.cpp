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
#include TARS_CORE_H(Containers/TkList)
#include TARS_CORE_H(Containers/TkVector)

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

	TkList<TkString> l;

	l.pushBack( s1 );
	l.pushBack( s4 );
	l.pushBack( s5 );
	l.pushBack( s6 );

	TkVector<TkString> v;

	v.pushBack( s1 );
	v.pushBack( s4 );
	v.pushBack( s5 );
	v.pushBack( s6 );

	//l.remove( l.find( s5 ) );

	TkWin32App* pWin32App = new TkWin32App( hInstance );

	pWin32App->createWindow();
	pWin32App->runMessageLoop();	

	return 0;
}
