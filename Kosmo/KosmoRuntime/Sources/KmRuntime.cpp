//*****************************************************************************
//
//	File:		KosmoRuntime.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"KosmoRuntimeRoot.h"

#include	KOSMO_CORE_H(GUI/KmWindow)
#include	KOSMO_CORE_H(String/KmString)
#include	KOSMO_CORE_H(Containers/KmVector)
#include	KOSMO_CORE_H(Containers/KmList)

///////////// TEMPORARY /////////////////
#include	<stdio.h>
#include	<vector>
#include	<list>
/////////////////////////////////////////

void testString()
{
	KmString str;
	KmString str2( "plouf toto" );
	KmString str3( str2 );

	str2 = str2;
	str2 = str;
	str = str3;
	str = "toto plouf";

	KmString str4 = str + str2;

	str4 = str + str3;
	
	KmString str5;

	str5 = str4 + "test";
	str5 = "test" + str4;
}


void testVector()
{
	KmVector<KmString> stringVector;

	//stringVector.add( "test" );
	//stringVector.add( "test2" );

	for	( uint32 i = 0; i < 10; i++ )
	{
		stringVector.add( "test_test" );
	}

	stringVector.resize( 4 );
	stringVector.resize( 12 );
	stringVector.resize( 18 );
	stringVector.resize( 7 );

	const KmString& s = stringVector[2];

	stringVector[2] = "plouf";

	for	( uint32 i = 0; i < stringVector.getSize(); i++ )
	{
		char buf[64];
		sprintf_s( buf, "test_%d", i );
		stringVector[i] = buf;
	}

	stringVector.remove( 1 );
	stringVector.shrink();

	std::vector<KmString> vs;

	for	( uint32 i = 0; i < 7; i++ )
	{
		char buf[64];
		sprintf_s( buf, "test_%d", i );
		vs.push_back( buf );
	}

	vs.erase( vs.begin() + 1 );
}

void testList()
{
	KmList<KmString> stringList;

	stringList.pushBack( "test1" );
	stringList.pushBack( "test3" );
	stringList.pushBack( "test2" );

	KmList<KmString>::KmIterator it = stringList.begin();

	it++;
	*it = "test4";

	++it;
	it--;
	--it;

	*(it++) = "test5";
	it->append( "plouf" );

	KmList<KmString>::KmIterator it2;

	stringList.insert( it2, "plouf" );
	it = stringList.pushBack( "test6" );

	std::list<KmString> l;

	l.push_back( "plouf1" );
	std::list<KmString>::iterator std_it = l.begin();
	l.insert( std_it, "plouf2" );
}

//-----------------------------------------------------------------------------
// Name:		main
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
int main()
{
	//testString();
	//testVector();
	testList();

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
	KmWindow	kosmoWindow;
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
