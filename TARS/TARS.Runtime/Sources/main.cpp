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
#include TARS_CORE_H(File/TkTextFile)

//-----------------------------------------------------------------------------
// Name:		WinMain
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
int WinMain( __in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in_opt LPSTR lpCmdLine, __in int nShowCmd )
{
	TkWin32App* pWin32App = new TkWin32App( hInstance );

	//TkBinaryFile f;
	TkTextFile f;
	TkString s( "prout" );

	f.open( "D:/test.txt" );

	f << 'h';
	f << 123;
	f << 1.2536477;
	f << s;

	f.close();

	f.open( "D:/test.txt", TARS_FILE_MODE_IN );

	char c;
	int n;
	char* s2;
	double d;

	f >> c;
	f >> n;
	f >> d;
	f >> s2;

	pWin32App->createWindow();
	pWin32App->runMessageLoop();

	return 0;
}
