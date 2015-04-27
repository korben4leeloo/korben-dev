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

	inline uint32	getSize() const;

	bool			insert( const T& data );
	bool			remove( const T& data );

	void			traverseInOrder( const TraverseCallback pfnTraverseCallback ) const;

	bool			verify() const;

private:
	struct KmNode
	{
				KmNode( const T& data );

		T		_data;
		KmNode*	_pLeft;
		KmNode*	_pRight;
	};

	bool			insert( KmNode*& pNode, const T& data );
	bool			remove( KmNode*& pNode, const T& data );

	void			traverseInOrder( KmNode* pNode, const TraverseCallback pfnTraverseCallback ) const;

	void			replaceWithPredecessor( KmNode*& pNode );
	void			replaceWithSuccessor( KmNode*& pNode );

	bool			verify( KmNode* pNode, const T*& pPrevData ) const;

	void			destroy( KmNode*& pNode );

	KmNode*			_pRoot;
	uint32			_uiSize;
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
: _pRoot	( NULL )
, _uiSize	( 0 )
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
// Name:		getSize
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
uint32 KmBinarySearchTree<T>::getSize() const
{
	return	( _uiSize );
}

//-----------------------------------------------------------------------------
// Name:		insert
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
bool KmBinarySearchTree<T>::insert(const T&	data)
{
	return	( insert( _pRoot, data ) );
}

//-----------------------------------------------------------------------------
// Name:		insert
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
bool KmBinarySearchTree<T>::insert(KmNode*&	pNode, 
								   const T&	data)
{
	if ( pNode == NULL )
	{
		pNode = new KmNode( data );
		_uiSize++;

		return	( true );
	}
	else if ( data < pNode->_data )
	{
		return	( insert( pNode->_pLeft, data ) );
	}
	else if ( data > pNode->_data )
	{
		return	( insert( pNode->_pRight, data ) );
	}

	return	( false );
}

//-----------------------------------------------------------------------------
// Name:		remove
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
bool KmBinarySearchTree<T>::remove(const T&	data)
{
	return	( remove( _pRoot, data ) );
}

//-----------------------------------------------------------------------------
// Name:		remove
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
bool KmBinarySearchTree<T>::remove(KmNode*&	pNode, 
								   const T&	data)
{
	if ( pNode )
	{
		if ( data == pNode->_data )
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
// Name:		replaceWithPredecessor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void KmBinarySearchTree<T>::replaceWithPredecessor(KmNode*&	pNode)
{
	KmNode* pHighestLeft		= pNode->_pLeft;
	KmNode* pHighestLeftParent	= NULL;

	while ( pHighestLeft->_pRight )
	{
		pHighestLeftParent	= pHighestLeft;
		pHighestLeft		= pHighestLeft->_pRight;
	}

	if ( pHighestLeftParent )
	{
		pHighestLeftParent->_pRight	= pHighestLeft->_pLeft;
		pHighestLeft->_pLeft		= pNode->_pLeft;
	}

	pHighestLeft->_pRight	= pNode->_pRight;
	pNode					= pHighestLeft;
}

//-----------------------------------------------------------------------------
// Name:		replaceWithSuccessor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void KmBinarySearchTree<T>::replaceWithSuccessor(KmNode*&	pNode)
{
	KmNode* pLowestRight		= pNode->_pRight;
	KmNode* pLowestRightParent	= NULL;

	while ( pLowestRight->_pLeft )
	{
		pLowestRightParent	= pLowestRight;
		pLowestRight		= pLowestRight->_pLeft;
	}

	if ( pLowestRightParent )
	{
		pLowestRightParent->_pLeft	= pLowestRight->_pRight;
		pLowestRight->_pRight		= pNode->_pRight;
	}

	pLowestRight->_pLeft	= pNode->_pLeft;
	pNode					= pLowestRight;
}

//-----------------------------------------------------------------------------
// Name:		traverseInOrder
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void KmBinarySearchTree<T>::traverseInOrder(const TraverseCallback pfnTraverseCallback) const
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
											const TraverseCallback	pfnTraverseCallback) const
{
	if ( pNode )
	{
		traverseInOrder( pNode->_pLeft, pfnTraverseCallback );
		pfnTraverseCallback( pNode->_data );
		traverseInOrder( pNode->_pRight, pfnTraverseCallback );
	}
}

//-----------------------------------------------------------------------------
// Name:		verify
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
bool KmBinarySearchTree<T>::verify() const
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
bool KmBinarySearchTree<T>::verify(KmNode*		pNode, 
								   const T*&	pPrevData) const
{
	bool bIsValid = true;

	if ( pNode )
	{
		bIsValid &= verify( pNode->_pLeft, pPrevData );
		
		if ( pPrevData )
		{
			bIsValid &= ( *pPrevData < pNode->_data );
		}

		pPrevData = &pNode->_data;

		bIsValid &= verify( pNode->_pRight, pPrevData );
	}

	return	( bIsValid );
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