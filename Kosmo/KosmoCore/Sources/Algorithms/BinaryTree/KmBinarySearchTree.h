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
	typedef void (*TraverseCallback)( const T& data );

			KmBinarySearchTree();
			~KmBinarySearchTree();

	void	insert( const T& data );
	void	remove( const T& data );

	void	traverseInOrder( const TraverseCallback pfnTraverseCallback );

private:
	struct KmNode
	{
				KmNode( const T& data );

		T		_data;
		KmNode*	_pLeft;
		KmNode*	_pRight;
	};

	void	insert( KmNode*& pNode, const T& data );
	void	traverseInOrder( KmNode* pNode, const TraverseCallback pfnTraverseCallback );

	void	destroy( KmNode*& pNode );

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
	destroy( _pRoot );
}

//-----------------------------------------------------------------------------
// Name:		insert
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void KmBinarySearchTree<T>::insert(const T&	data)
{
	insert( _pRoot, data );
}

//-----------------------------------------------------------------------------
// Name:		insert
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void KmBinarySearchTree<T>::insert(KmNode*&	pNode, 
								   const T&	data)
{
	if ( pNode == NULL )
	{
		pNode = new KmNode( data );
	}
	else if ( data < pNode->_data )
	{
		insert( pNode->_pLeft, data );
	}
	else if ( data > pNode->_data )
	{
		insert( pNode->_pRight, data );
	}
}

//-----------------------------------------------------------------------------
// Name:		traverseInOrder
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void KmBinarySearchTree<T>::traverseInOrder(const TraverseCallback pfnTraverseCallback)
{
	traverseInOrder( _pRoot, pfnTraverseCallback );
}

//-----------------------------------------------------------------------------
// Name:		traverseInOrder
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void KmBinarySearchTree<T>::traverseInOrder(KmNode*					pNode, 
											const TraverseCallback	pfnTraverseCallback)
{
	if ( pNode )
	{
		traverseInOrder( pNode->_pLeft, pfnTraverseCallback );
		pfnTraverseCallback( pNode->_data );
		traverseInOrder( pNode->_pRight, pfnTraverseCallback );
	}
}

//-----------------------------------------------------------------------------
// Name:		destroy
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void KmBinarySearchTree<T>::destroy(KmNode*& pNode)
{
	if ( pNode )
	{
		destroy( pNode->_pLeft );
		destroy( pNode->_pRight );
		printf( "Destroying node with value %d\n", pNode->_data );
		delete pNode;
	}
}

//-----------------------------------------------------------------------------
// Name:		KmBinarySearchTree::KmNode constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
KmBinarySearchTree<T>::KmNode::KmNode(const T&	data)
: _data		( data )
, _pLeft	( NULL )
, _pRight	( NULL )
{
	
}

KOSMO_CORE_NAMESPACE_END

#endif