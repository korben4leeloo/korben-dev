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

	//TkBinaryFile file;
	TkTextFile file;
	TkString s( "prout" );
	float f = ( 1.0f / 30.0f );
	double d = ( 1.0 / 30.0 );

	file.open( "D:/test.txt" );

	file << 'h' << "\n";
	file << 123 << "\n";
	file << s  << "\n";
	file << f << "\n";
	file << "tars" << "\n";
	file << d << "\n";
	file << s;

	char str[256];
    sprintf_s(str, "%.18f", d);

    OutputDebugString(str);

	file.close();

	file.open( "D:/test.txt", TARS_FILE_MODE_IN );

	char c;
	int n;
	char* s2;
	char* s3;
	float f1;
	double d1;
	TkString s4;

	file >> c;
	file >> n;
	file >> s4;
	file >> f1;
	file >> s3;
	file >> d1;
	file >> s2;

	pWin32App->createWindow();
	pWin32App->runMessageLoop();

	return 0;
}
