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
		static void displayDataCallback( const int& nData )
		{
			printf( "%d\n", nData );
		}
	};

	KmBinarySearchTree<int32> bt;

	std::default_random_engine			generator;
	std::uniform_int_distribution<int>	distribution(0,1000);

	for ( uint32 i = 0; i < 50; i++ )
	{
		int dice_roll = distribution(generator);
		printf( "Generating value %d\n", dice_roll );
		bt.insert( dice_roll );
	}

	bt.traverseInOrder( Local::displayDataCallback );
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
	startUnitTests();
	return	( 0 );
}

