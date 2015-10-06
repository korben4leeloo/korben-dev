//*****************************************************************************
//
//	Class:		KmRedBlackTree
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __KosmoCore_KmRedBlackTree_h__
#define __KosmoCore_KmRedBlackTree_h__

#include	"Root.h"

KOSMO_CORE_NAMESPACE_BEGIN

template<class T>
class KmRedBlackTree
{
public:
	typedef void (*TraverseCallback)( const T& data );

					KmRedBlackTree();
					~KmRedBlackTree();

	inline uint32	size() const;

	bool			insert( const T& data );
	bool			remove( const T& data );

	void			traverseInOrder( const TraverseCallback pfnTraverseCallback ) const;

	bool			verify() const;

private:
	struct KmNode
	{
		enum KmNodeColor
		{
			KmNodeColorBlack,
			KmNodeColorRed
		};

						KmNode();
						~KmNode();

		T*				_pData;
		KmNodeColor		_eColor;
		KmNode*			_pLeft;
		KmNode*			_pRight;
		KmNode*			_pParent;
	};

	KmNode*			createNode( KmNode* pParent, const T& data );

	bool			remove( KmNode*& pNode, const T& data );
	void			removeNode( KmNode*& pNode );
	bool			replaceNode( KmNode* pNode, KmNode* pReplaceNode );

	void			traverseInOrder( KmNode* pNode, const TraverseCallback pfnTraverseCallback ) const;

	KmNode*			find( const T& data ) const;
	KmNode*			findInOrderPredecessor( const KmNode* pNode ) const;
	KmNode*			findInOrderSuccessor( const KmNode* pNode ) const;

	void			enforceInsertion( KmNode* pInsertedNode );

	void			rotateLeft( KmNode* pNode );
	void			rotateRight( KmNode* pNode );

	bool			verify( KmNode* pNode, const T* pPrevData ) const;

	void			postOrderDestroy( KmNode*& pNode );

	// Helpers
	KmNode*			grandParent( const KmNode* pNode ) const;
	KmNode*			uncle( const KmNode* pNode ) const;
	KmNode*			sibling( const KmNode* pNode ) const;
	inline bool		isLeaf( const KmNode* pNode ) const;

	KmNode*			_pRoot;
	KmNode*			_pLeaf;
	uint32			_uiSize;
};

//*****************************************************************************
//	Template methods declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		KmRedBlackTree constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
KmRedBlackTree<T>::KmRedBlackTree()
: _uiSize( 0 )
{
	// Create leaf ( sentinel ) node and assign it to the root
	_pLeaf				= new KmNode();
	_pLeaf->_pLeft		= _pLeaf;
	_pLeaf->_pRight		= _pLeaf;
	_pLeaf->_pParent	= _pLeaf;

	_pRoot = _pLeaf;
}

//-----------------------------------------------------------------------------
// Name:		KmRedBlackTree destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
KmRedBlackTree<T>::~KmRedBlackTree()
{
	postOrderDestroy( _pRoot );
	delete _pLeaf;
}

//-----------------------------------------------------------------------------
// Name:		size
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
uint32 KmRedBlackTree<T>::size() const
{
	return	( _uiSize );
}

//-----------------------------------------------------------------------------
// Name:		createNode
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename KmRedBlackTree<T>::KmNode* KmRedBlackTree<T>::createNode(KmNode*	pParent,
																  const T&	data)
{
	KmNode* pNode = new KmNode();

	pNode->_pParent	= pParent;
	pNode->_eColor	= KmNode::KmNodeColorRed;
	pNode->_pLeft	= _pLeaf;
	pNode->_pRight	= _pLeaf;
	pNode->_pData	= new T( data );

	_uiSize++;

	return ( pNode );
}

//-----------------------------------------------------------------------------
// Name:		insert
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
bool KmRedBlackTree<T>::insert(const T&	data)
{
	KmNode**	ppNode	= &_pRoot;
	KmNode*		pParent	= NULL;

	while	( true )
	{
		if	( isLeaf( *ppNode ) )
		{
			*ppNode = createNode( pParent, data );
			enforceInsertion( *ppNode );

			return ( true );
		}
		else if ( data < *(*ppNode)->_pData )
		{
			pParent	= *ppNode;
			ppNode	= &(*ppNode)->_pLeft;
		}
		else if ( data > *(*ppNode)->_pData )
		{
			pParent	= *ppNode;
			ppNode	= &(*ppNode)->_pRight;
		}
		else
		{
			return ( false );
		}
	}
}

//-----------------------------------------------------------------------------
// Name:		find
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename KmRedBlackTree<T>::KmNode* KmRedBlackTree<T>::find(const T&	data) const
{
	KmNode* pNode = _pRoot;

	while	( !isLeaf( pNode ) )
	{
		if	( data == pNode->_data )
		{
			break;
		}
		else if ( data < pNode->_data )
		{
			pNode = pNode->_pLeft;
		}
		else if ( data > pNode->_data )
		{
			pNode = pNode->_pRight;
		}
	}

	return ( !isLeaf( pNode ) ? pNode : NULL );
}

//-----------------------------------------------------------------------------
// Name:		remove
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
bool KmRedBlackTree<T>::remove(const T&	data)
{
	KmNode* pNode = find( data );

	if	( pNode )
	{
		KmNode* pSubstitute = ( pSubstitute = findInOrderPredecessor( pNode ) ) ? pSubstitute : findInOrderSuccessor( pNode );

		if	( pSubstitute )
		{
			KmNode* pChild = isLeaf( pSubstitute->_pRight ) ? pSubstitute->_pLeft : pSubstitute->_pRight;

			pNode->_data = pSubstitute->_data;
			replaceNode( pSubstitute, pChild );

			

			return ( true );
		}
	}

	return ( false );



	//return	( remove( _pRoot, data ) );
}

//-----------------------------------------------------------------------------
// Name:		remove
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
bool KmRedBlackTree<T>::remove(KmNode*&	pNode, 
							   const T&	data)
{
	if ( pNode )
	{
		if ( data == pNode->_data )
		{
			removeNode( pNode );
			return	( true );
		}
		else if ( data < pNode->_data )
		{
			return	( remove( pNode->_pLeft, data ) );
		}
		else
		{
			return	( remove( pNode->_pRight, data ) );
		}
	}

	return	( false );
}

//-----------------------------------------------------------------------------
// Name:		removeNode
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void KmRedBlackTree<T>::removeNode(KmNode*&	pNode)
{
	KmNode* pLeftChild		= pNode->_pLeft;
	KmNode* pRightChild		= pNode->_pRight;
	KmNode* pNodeToDelete	= pNode;

	if ( pLeftChild )
	{
		if ( pRightChild )
		{
			// Two children cases
			replaceWithPredecessor( pNode );
			//replaceWithSuccessor( pNode );
		}
		else
		{
			// Left child only case
			pNode = pLeftChild;
		}
	}
	else if ( pRightChild )
	{
		// Right child only case
		pNode = pRightChild;
	}
	else
	{
		// No child case
		pNode = NULL;
	}

	delete pNodeToDelete;
	_uiSize--;
}

//-----------------------------------------------------------------------------
// Name:		replaceNode
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
bool KmRedBlackTree<T>::replaceNode(KmNode*	pNode, 
									KmNode*	pReplaceNode)
{
	if	( pNode == _pRoot )
	{
		_pRoot = pReplaceNode;
	}
	else
	{
		if	( pReplaceNode == pNode->_pLeft )
		{
			pNode->_pParent->_pLeft = pReplaceNode;
		}
		else if	( pReplaceNode == pNode->_pRight )
		{
			pNode->_pParent->_pRight = pReplaceNode;
		}
		else
		{
			return ( false );
		}
	}

	pReplaceNode->_pParent = isLeaf( pReplaceNode ) ? _pLeaf : pNode->_pParent;
	return ( true );
}

//-----------------------------------------------------------------------------
// Name:		findInOrderPredecessor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename KmRedBlackTree<T>::KmNode* KmRedBlackTree<T>::findInOrderPredecessor(const KmNode*	pNode) const
{
	KmNode* pInOrderPredecessor	= pNode->_pLeft;

	if	( !isLeaf( pInOrderPredecessor ) )
	{
		while ( !isLeaf( pInOrderPredecessor->_pRight ) )
		{
			pInOrderPredecessor	= pInOrderPredecessor->_pRight;
		}

		return ( pInOrderPredecessor );
	}

	return	( NULL );
}

//-----------------------------------------------------------------------------
// Name:		findInOrderSuccessor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename KmRedBlackTree<T>::KmNode* KmRedBlackTree<T>::findInOrderSuccessor(const KmNode*	pNode) const
{
	KmNode* pInOrderSuccessor = pNode->_pRight;

	if	( !isLeaf( pInOrderSuccessor ) )
	{
		while ( !isLeaf( pInOrderSuccessor->_pLeft ) )
		{
			pInOrderSuccessor = pInOrderSuccessor->_pLeft;
		}

		return ( pInOrderSuccessor );
	}

	return	( NULL );
}

//-----------------------------------------------------------------------------
// Name:		enforceInsertion
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void KmRedBlackTree<T>::enforceInsertion(KmNode*	pInsertedNode)
{
	// Algorithm source: https://en.wikipedia.org/wiki/Red%E2%80%93black_tree
	KmNode* pNode = pInsertedNode;

	// Case 1
	if ( pNode->_pParent == NULL )
	{
		pNode->_eColor = KmNode::KmNodeColorBlack;
	}
	// Case 2
	else if ( pNode->_pParent->_eColor == KmNode::KmNodeColorRed )
	{
		KmNode* pGrandParent	= grandParent( pNode );
		KmNode* pUncle			= uncle( pNode );

		// Case 3
		if ( pUncle && ( pUncle->_eColor == KmNode::KmNodeColorRed ) )
		{
			pNode->_pParent->_eColor	= KmNode::KmNodeColorBlack;
			pUncle->_eColor				= KmNode::KmNodeColorBlack;
			pGrandParent->_eColor		= KmNode::KmNodeColorRed;

			enforceInsertion( pGrandParent );
		}
		else
		{
			// Case 4
			if ( ( pNode == pNode->_pParent->_pRight ) && ( pNode->_pParent == pGrandParent->_pLeft ) )
			{
				rotateLeft( pNode->_pParent );
				pNode = pNode->_pLeft;
			}
			else if ( ( pNode == pNode->_pParent->_pLeft ) && ( pNode->_pParent == pGrandParent->_pRight ) )
			{
				rotateRight( pNode->_pParent );
				pNode = pNode->_pRight;
			}

			// Case 5
			pGrandParent = grandParent( pNode );

			pNode->_pParent->_eColor	= KmNode::KmNodeColorBlack;
			pGrandParent->_eColor		= KmNode::KmNodeColorRed;

			if	( pNode == pNode->_pParent->_pLeft )
			{
				rotateRight( pGrandParent );
			}
			else
			{
				rotateLeft( pGrandParent );
			}
		}
	}

	//KOSMO_ASSERT( verify() );
}

//-----------------------------------------------------------------------------
// Name:		rotateLeft
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void KmRedBlackTree<T>::rotateLeft(KmNode*	pNode)
{
	KmNode* pParent	= pNode->_pParent;
	KmNode* pRight	= pNode->_pRight;

	// Attach "right" to parent
	if ( pParent )
	{
		if	( pNode == pParent->_pLeft )
		{
			pParent->_pLeft = pRight;
		}
		else
		{
			pParent->_pRight = pRight;
		}
		
		pRight->_pParent = pParent;
	}
	else
	{
		// Node is root, so "right" becomes the root
		_pRoot				= pRight;
		pRight->_pParent	= NULL;
	}

	// Attach left child of "right" to "node" right
	pNode->_pRight = pRight->_pLeft;

	if ( pRight->_pLeft )
	{
		pRight->_pLeft->_pParent = pNode;
	}

	// Attach "node" to left of "right"
	pRight->_pLeft	= pNode;
	pNode->_pParent	= pRight;

	//KOSMO_ASSERT( verify() );
}

//-----------------------------------------------------------------------------
// Name:		rotateRight
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void KmRedBlackTree<T>::rotateRight(KmNode*	pNode)
{
	KmNode* pParent	= pNode->_pParent;
	KmNode* pLeft	= pNode->_pLeft;

	// Attach "left" to parent right
	if ( pParent )
	{
		if	( pNode == pParent->_pLeft )
		{
			pParent->_pLeft = pLeft;
		}
		else
		{
			pParent->_pRight = pLeft;
		}

		pLeft->_pParent = pParent;
	}
	else
	{
		// Node is root, so "left" becomes the root
		_pRoot			= pLeft;
		pLeft->_pParent	= NULL;
	}

	// Attach right child of "left" to "node" left
	pNode->_pLeft = pLeft->_pRight;

	if ( pLeft->_pRight )
	{
		pLeft->_pRight->_pParent = pNode;
	}

	// Attach "node" to right of "left"
	pLeft->_pRight	= pNode;
	pNode->_pParent	= pLeft;

	//KOSMO_ASSERT( verify() );
}

//-----------------------------------------------------------------------------
// Name:		traverseInOrder
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void KmRedBlackTree<T>::traverseInOrder(const TraverseCallback pfnTraverseCallback) const
{
	traverseInOrder( _pRoot, pfnTraverseCallback );
}

//-----------------------------------------------------------------------------
// Name:		traverseInOrder
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void KmRedBlackTree<T>::traverseInOrder(KmNode*					pNode, 
										const TraverseCallback	pfnTraverseCallback) const
{
	if ( !isLeaf( pNode ) )
	{
		traverseInOrder( pNode->_pLeft, pfnTraverseCallback );
		pfnTraverseCallback( *(pNode->_pData) );
		traverseInOrder( pNode->_pRight, pfnTraverseCallback );
	}
}

//-----------------------------------------------------------------------------
// Name:		verify
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
bool KmRedBlackTree<T>::verify() const
{
	const T* pPrevData = NULL;
	return	( verify( _pRoot, pPrevData ) );
}

//-----------------------------------------------------------------------------
// Name:		verify
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
bool KmRedBlackTree<T>::verify(KmNode*	pNode, 
							   const T*	pPrevData) const
{
	bool bIsValid = true;

	if	( !isLeaf( pNode ) )
	{
		bIsValid &= verify( pNode->_pLeft, pPrevData );
		
		if ( pPrevData )
		{
			bIsValid &= ( *pPrevData < *(pNode->_pData) );
		}

		pPrevData = pNode->_pData;

		bIsValid &= verify( pNode->_pRight, pPrevData );
	}

	return	( bIsValid );
}

//-----------------------------------------------------------------------------
// Name:		postOrderDestroy
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void KmRedBlackTree<T>::postOrderDestroy(KmNode*& pNode)
{
	if ( !isLeaf( pNode ) )
	{
		postOrderDestroy( pNode->_pLeft );
		postOrderDestroy( pNode->_pRight );
		delete pNode;
	}
}

//-----------------------------------------------------------------------------
// Name:		grandParent
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename KmRedBlackTree<T>::KmNode* KmRedBlackTree<T>::grandParent(const KmNode*	pNode) const
{
	return	( pNode->_pParent ? pNode->_pParent->_pParent : NULL );
}

//-----------------------------------------------------------------------------
// Name:		uncle
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename KmRedBlackTree<T>::KmNode* KmRedBlackTree<T>::uncle(const KmNode*	pNode) const
{
	KmNode* pGrandParent	= grandParent( pNode );
	KmNode* pUncle			= NULL;

	if ( pGrandParent )
	{
		pUncle = ( pNode->_pParent == pGrandParent->_pLeft ) ? pGrandParent->_pRight : pGrandParent->_pLeft;
	}

	return	( pUncle );
}

//-----------------------------------------------------------------------------
// Name:		grandParent
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename KmRedBlackTree<T>::KmNode* KmRedBlackTree<T>::sibling(const KmNode*	pNode) const
{
	KmNode* pParent = pNode ? pNode->_pParent : NULL;

	if	( pParent )
	{
		return ( ( pNode == pParent->_pLeft ) ? pParent->_pRight : pParent->_pLeft );
	}

	return ( NULL );
}

//-----------------------------------------------------------------------------
// Name:		isLeaf
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
bool KmRedBlackTree<T>::isLeaf(const KmNode*	pNode) const
{
	return ( pNode == _pLeaf );
}

//-----------------------------------------------------------------------------
// Name:		KmRedBlackTree::KmNode constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
KmRedBlackTree<T>::KmNode::KmNode()
: _pData	( NULL )
, _eColor	( KmNodeColorBlack )
, _pLeft	( NULL )
, _pRight	( NULL )
, _pParent	( NULL )
{
	
}

//-----------------------------------------------------------------------------
// Name:		KmRedBlackTree::KmNode destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
KmRedBlackTree<T>::KmNode::~KmNode()
{
	delete _pData;
}

KOSMO_CORE_NAMESPACE_END

#endif