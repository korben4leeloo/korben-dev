//*****************************************************************************
//
//	File:		QmUnitTest.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "QmUnitTest.h"

#include QUANTUM_CORE_H(Containers/QmMap)
#include QUANTUM_CORE_H(Containers/QmTree)

//-----------------------------------------------------------------------------
// Name:		QmUnitTest constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmUnitTest::QmUnitTest()
{
	
}

//-----------------------------------------------------------------------------
// Name:		QmUnitTest destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmUnitTest::~QmUnitTest()
{
	
}

//-----------------------------------------------------------------------------
// Name:		launch
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void QmUnitTest::launch()
{
	TestQmMap();
	TestQmTree();
}

//-----------------------------------------------------------------------------
// Name:		TestQmMap
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void QmUnitTest::TestQmMap()
{
	QmMap<QmString, int> m;

	QmMap<QmString, int>::iterator it1 = m.pushBack( "test", 1 );
	QmMap<QmString, int>::iterator it2 = m.pushBack( "plouf", 2 );
	QmMap<QmString, int>::iterator it3 = m.pushBack( "caca", 3 );

	QmMap<QmString, int>::iterator it4 = m.insertAfter( it2, "kiki", 5 );
	QmMap<QmString, int>::iterator it5 = m.insertBefore( it4, "debile", 7 );

	m.insertAfter( m.head(), "papi", 9 );
	m.insertBefore( m.head(), "papa", 11 );
	m.insertAfter( m.queue(), "caradoc", 13 );
	m.insertBefore( m.queue(), "perceval", 17 );

	m.remove( "plouf" );
	m.remove( "papa" );
	m.remove( "caradoc" );

	m.pushBack( "kiki", 19 );
	m.insertAfter( m.find( "perceval" ), "debile", 21 );
}

//-----------------------------------------------------------------------------
// Name:		TestQmTree
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void QmUnitTest::TestQmTree()
{
	typedef QmTree<int> QmIntTree;
	typedef QmIntTree::QmTreeNode QmIntNode;

	QmIntTree test;
	QmIntNode* r = test.getRoot();
	QmIntNode* n = test.createNode();
}
