//*****************************************************************************
//
//	Class:		KmBinarySearchTree
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __KosmoCore_KmBinarySearchTree_h__
#define __KosmoCore_KmBinarySearchTree_h__

#include	"Root.h"

KOSMO_CORE_NAMESPACE_BEGIN

template<class T>
class KmBinarySearchTree
{
public:
							KmBinarySearchTree();
							~KmBinarySearchTree();

private:
	struct KmNode
	{
		T		_value;
		KmNode*	_pLeft;
		KmNode*	_pRight;
	};

	KmNode*	_pRoot;
};

//*****************************************************************************
//	Template methods declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		KmBinarySearchTree constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
KmBinarySearchTree<T>::KmBinarySearchTree()
: _pRoot( NULL )
{
	
}

//-----------------------------------------------------------------------------
// Name:		KmBinarySearchTree destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
KmBinarySearchTree<T>::~KmBinarySearchTree()
{
	KOSMO_TODO( "Implement nodes deletion in KmBinarySearchTree destructor" )
}

KOSMO_CORE_NAMESPACE_END

#endif