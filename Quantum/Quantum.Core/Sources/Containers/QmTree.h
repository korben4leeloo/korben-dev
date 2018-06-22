//*****************************************************************************
//
//	Class:		QmTree
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __QUANTUM_CORE_TREE_H__
#define __QUANTUM_CORE_TREE_H__

#include QUANTUM_CORE_H(Containers/QmList)

template<class T>
class QmTree
{
public:
	class QmTreeNode
	{
		friend class QmTree<T>;
		template<class U, class NodeType> friend class QmList;

	private:
								QmTreeNode( const T& value = T() );
								~QmTreeNode();

		T						_data;
		QmTreeNode*				_pParent	= nullptr;
		QmTreeNode*				_pPrev		= nullptr;
		QmTreeNode*				_pNext		= nullptr;
		QmList<T, QmTreeNode>	_lChildren;
	};

						QmTree();
						~QmTree();

	inline QmTreeNode*	getRoot() { return _pRoot; }

	QmTreeNode*			createNode( QmTreeNode* pParent = nullptr );

private:
	QmTreeNode*			_pRoot = nullptr;
};

//*****************************************************************************
//	Template methods declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		QmTree constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
QmTree<T>::QmTree()
{
	_pRoot = new QmTreeNode();
}

//-----------------------------------------------------------------------------
// Name:		QmTree destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
QmTree<T>::~QmTree()
{
	delete _pRoot;
}

//-----------------------------------------------------------------------------
// Name:		createNode
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename QmTree<T>::QmTreeNode* QmTree<T>::createNode( QmTreeNode* pParent )
{
	QmTreeNode* pParentFallback = pParent ? pParent : _pRoot;
	QmTreeNode* pNode			= pParentFallback->_lChildren.pushBack( T() );

	pNode->_pParent = pParentFallback;

	return ( pNode );
}

//-----------------------------------------------------------------------------
// Name:		QmTree::QmTreeNode constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
QmTree<T>::QmTreeNode::QmTreeNode( const T& value )
: _data( value )
{
	
}

//-----------------------------------------------------------------------------
// Name:		QmTree::QmTreeNode destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
QmTree<T>::QmTreeNode::~QmTreeNode()
{
	if ( _pParent )
	{
		_pParent->_lChildren.remove( this );
	}
}

#endif