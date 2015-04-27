//*****************************************************************************
//
//	File:		KmUnitTest.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"KosmoUnitTestRoot.h"

#ifdef KOSMO_UNIT_TEST_STRING

#include	KOSMO_CORE_H(String/KmString)

//-----------------------------------------------------------------------------
// Name:		testString
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
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

#endif

#ifdef KOSMO_UNIT_TEST_VECTOR

#include	KOSMO_CORE_H(Containers/KmVector)
#include	KOSMO_CORE_H(String/KmString)
#include	<vector>

//-----------------------------------------------------------------------------
// Name:		testVector
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
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

#endif

#ifdef KOSMO_UNIT_TEST_LIST

#include	KOSMO_CORE_H(Containers/KmList)
#include	KOSMO_CORE_H(String/KmString)
#include	<list>

//-----------------------------------------------------------------------------
// Name:		testList
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
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

	KmList<KmString>::KmIterator it2 = stringList.find( "test2" );

	stringList.insert( it2, "plouf" );
	it = stringList.pushBack( "test6" );

	it2 = stringList.find( "test5plouf" );
	stringList.insert( it2, "plouf2" );

	/*std::list<KmString> l;

	l.push_back( "plouf1" );
	std::list<KmString>::iterator std_it = l.begin();
	l.insert( std_it, "plouf2" );*/
}

#endif

#ifdef KOSMO_UNIT_TEST_BINARY_SEARCH_TREE

#include	KOSMO_CORE_H(Algorithms/BinaryTree/KmBinarySearchTree)
#include	<stdio.h>
#include	<random>

//-----------------------------------------------------------------------------
// Name:		testBinarySearchTree
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void testBinarySearchTree()
{
	struct Local
	{
		static void displayDataCallback( const uint32& nData )
		{
			printf( "%d\n", nData );
		}
	};

	static uint32 uiValueCount			= 50;
	static uint32 uiRemoveValueCount	= 10;

	uint32*									pValues = new uint32[uiValueCount];
	std::uniform_int_distribution<uint32>	distribution( 0, 1000 );
	std::default_random_engine				generator;
	KmBinarySearchTree<uint32>				bt;

	printf( "Filling tree\n" );
	printf( "------------\n" );

	for ( uint32 i = 0; i < uiValueCount; i++ )
	{
		uint32 uiValue = distribution( generator );

		printf( "Generating value %d\n", uiValue );
		pValues[i] = uiValue;
		bt.insert( uiValue );
	}

	printf( "\nIn order display: %d nodes\n", bt.getSize() );
	printf( "----------------\n" );

	bt.traverseInOrder( Local::displayDataCallback );
	printf( "\n" );

	printf( "Removing some values\n" );
	printf( "------------------\n" );

	for ( uint32 i = 0; i < uiRemoveValueCount; i++ )
	{
		uint32	uiRemoveIndex	= distribution( generator ) % uiValueCount;
		bool	bRemove			= bt.remove( pValues[uiRemoveIndex] );

		printf( "Removing value: %d --> %s\n", pValues[uiRemoveIndex], bRemove ? "OK" : "Not Found" );
	}

	printf( "\nIn order display after removing values: %d nodes\n", bt.getSize() );
	printf( "--------------------------------------\n" );

	bt.traverseInOrder( Local::displayDataCallback );

	bool bIsValidBST = bt.verify();

	printf( "\nIs tree valid: %s\n", bIsValidBST ? "true" : "false" );
	printf( "--------------------------------------\n" );

	delete[] pValues;
}

#endif

#ifdef KOSMO_UNIT_TEST_RESOURCES

#include	KOSMO_CORE_H(Resources/KmResourceManager)

class KmTestResource
{
public:
	static KmTestResource* create( const float f )
	{
		return( NULL );
	}
};

//typedef KmResourceManager<KmTestResource, KmTestResource> KmTestResourceManager;
typedef KmResourceManager<KmTestResource> KmTestResourceManager;

//-----------------------------------------------------------------------------
// Name:		testResource
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void testResource()
{
	KmResourceId resId;

	resId.m_nIndex	= 123;
	resId.m_nTag	= 5;

	KmTestResourceManager testResManager;
	//testResManager.create( "test", 1.0f );
	testResManager.create( "test" );
}

#endif

//-----------------------------------------------------------------------------
// Name:		startUnitTests
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void startUnitTests()
{
#ifdef KOSMO_UNIT_TEST_STRING
	testString();
#endif

#ifdef KOSMO_UNIT_TEST_VECTOR
	testVector();
#endif

#ifdef KOSMO_UNIT_TEST_LIST
	testList();
#endif

#ifdef KOSMO_UNIT_TEST_BINARY_SEARCH_TREE
	testBinarySearchTree();
#endif

#ifdef KOSMO_UNIT_TEST_RESOURCES
	testResource();
#endif
}

int main()
{
	char c;

	startUnitTests();

	printf( "\nPress a key to terminate" );
	scanf( "%c", &c );
	return	( 0 );
}

