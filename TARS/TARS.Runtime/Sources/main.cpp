//*****************************************************************************
//
//	File:		main.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "Root.h"

#include <Windows.h>

#include TARS_CORE_H(Application/TkWin32App)
#include TARS_CORE_H(File/TkBinaryFile)

//-----------------------------------------------------------------------------
// Name:		WinMain
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
int WinMain( __in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in_opt LPSTR lpCmdLine, __in int nShowCmd )
{
	TkWin32App* pWin32App = new TkWin32App( hInstance );

	TkBinaryFile f;
	TkString s( "prout" );

	f.open( "D:/test.txt" );

	f << 'h' << "\n";
	f << 123;
	f << s << "\n";

	f.close();

	pWin32App->createWindow();
	pWin32App->runMessageLoop();

	return 0;
}
