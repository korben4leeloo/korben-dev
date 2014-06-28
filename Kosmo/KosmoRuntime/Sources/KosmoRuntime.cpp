//*****************************************************************************
//
//	File:		KosmoRuntime.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"KosmoRuntimeRoot.h"

#include	KOSMO_CORE_H(GUI/KsWindow)
#include	KOSMO_CORE_H(String/KsString)

//-----------------------------------------------------------------------------
// Name:		main
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
int main()
{
	KsString str;
	KsString str2( "plouf toto" );
	KsString str3( str2 );

	str2 = str2;
	str2 = str;
	str = str3;
	str = "toto plouf";

	return	( 0 );
}

//-----------------------------------------------------------------------------
// Name:		WinMain
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
int CALLBACK WinMain(_In_ HINSTANCE	hInstance, 
					 _In_ HINSTANCE	hPrevInstance,
					 _In_ LPSTR		lpCmdLine,
					 _In_ int		nCmdShow)
{
	KsWindow	kosmoWindow;
	MSG			msg;

	kosmoWindow.create();

	bool bRunning = true;

	while	( bRunning )
	{
		while	( PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) )
		{
			// If we have a message to process, process it
			if	( msg.message == WM_QUIT )
			{
				bRunning = false; // Set bRunning to false if we have a message to quit
			}
			else
			{
				TranslateMessage( &msg );
				DispatchMessage( &msg );
			}
		}

		// If we don't have a message to process
	}

	return	( (int)msg.wParam );
}
