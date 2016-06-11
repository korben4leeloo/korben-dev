//*****************************************************************************
//
//	File:		main.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include <Windows.h>

#include <Application/TsWin32App.h>
#include <Window/TsWin32Wnd.h>
#include <Events/TsEventManager.h>

//-----------------------------------------------------------------------------
// Name:		WinMain
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
int WinMain( __in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in_opt LPSTR lpCmdLine, __in int nShowCmd )
{
	/*TsWin32Wnd*		pMainWindow		= new TsWin32Wnd();
	TsEventManager*	pEventManager	= new TsEventManager();

	pMainWindow->setEventManager( pEventManager );
	pMainWindow->create( hInstance );
	pMainWindow->show();*/

	/*while ( 1 )
	{
		Sleep( 0 );
	}*/

	TsWin32App* pWin32App = new TsWin32App( hInstance );

	pWin32App->createWindow();
	pWin32App->createWindow();
	pWin32App->runMessageLoop();

	return 0;
}
