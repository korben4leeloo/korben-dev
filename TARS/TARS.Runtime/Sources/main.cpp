//*****************************************************************************
//
//	File:		main.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include <Windows.h>
#include <Window/TsWin32Window.h>

//-----------------------------------------------------------------------------
// Name:		WinMain
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
int WinMain( __in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in_opt LPSTR lpCmdLine, __in int nShowCmd )
{
	TsWin32Window* pMainWindow = new TsWin32Window();

	pMainWindow->create( hInstance );
	pMainWindow->show();

	while ( 1 );

	return 0;
}
