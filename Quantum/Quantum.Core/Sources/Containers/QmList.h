//*****************************************************************************
//
//	Class:		QmList
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __QUANTUM_CORE_QM_LIST_H__
#define __QUANTUM_CORE_QM_LIST_H__

template<class T>
struct QmListNode
{
	template<class U, class NodeType> friend class QmList;

protected:
	QmListNode( const T& value );

	QmListNode*	_pPrev;
	QmListNode*	_pNext;
	T			_value;
};

template<class T, class NodeType = QmListNode<T>>
class QmList
{
public:
						QmList();
						~QmList();

	NodeType*			pushBack( const T& value );
	NodeType*			pushFront( const T& value );
	NodeType*			insertAfter( const NodeType* position, const T& value );
	NodeType*			insertBefore( const NodeType* position, const T& value );
	void				remove( const T& value );
	void				remove( NodeType* pListNode );
	NodeType*			find( const T& value );

	inline NodeType*	head();
	inline NodeType*	queue();

private:
	NodeType*			_pHead	= nullptr;
	NodeType*			_pQueue	= nullptr;
	uint32				_uiSize	= 0;
};

//*****************************************************************************
//	Template methods declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		QmList constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, class NodeType>
QmList<T, NodeType>::QmList()
{

}

//-----------------------------------------------------------------------------
// Name:		QmList destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, class NodeType>
QmList<T, NodeType>::~QmList()
{

}

//-----------------------------------------------------------------------------
// Name:		pushBack
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, class NodeType>
NodeType* QmList<T, NodeType>::pushBack( const T& value )
{
	NodeType* pListNode = new NodeType( value );

	if ( _pHead )
	{
		QUANTUM_ASSERT( _pQueue );

		pListNode->_pPrev	= _pQueue;
		_pQueue->_pNext		= pListNode;
		_pQueue				= pListNode;
	}
	else
	{
		_pHead	= pListNode;
		_pQueue = pListNode;
	}

	_uiSize++;

	return ( pListNode );
}

//-----------------------------------------------------------------------------
// Name:		pushFront
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, class NodeType>
NodeType* QmList<T, NodeType>::pushFront( const T&	value )
{
	NodeType* pListNode = new NodeType( value );

	if ( _pHead )
	{
		QUANTUM_ASSERT( _pQueue );

		pListNode->_pNext	= _pHead;
		_pHead->_pPrev		= pListNode;
		_pHead				= pListNode;
	}
	else
	{
		_pHead	= pListNode;
		_pQueue = pListNode;
	}

	_uiSize++;

	return ( NodeType*( pListNode ) );
}

//-----------------------------------------------------------------------------
// Name:		insertAfter
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, class NodeType>
NodeType* QmList<T, NodeType>::insertAfter( const NodeType* position, const T& value )
{
	QUANTUM_ASSERT( position.isValid() );
	QUANTUM_ASSERT( _pHead );

	NodeType* pListNode = new NodeType( value );

	pListNode->_pPrev			= position._pListNode;
	pListNode->_pNext			= position._pListNode->_pNext;
	position._pListNode->_pNext = pListNode;

	if ( _pQueue == position._pListNode )
	{
		_pQueue = pListNode;
	}

	_uiSize++;

	return ( NodeType*( pListNode ) );
}

//-----------------------------------------------------------------------------
// Name:		insertBefore
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, class NodeType>
NodeType* QmList<T, NodeType>::insertBefore( const NodeType* position, const T& value )
{
	if ( _uiSize == 0 )
	{
		return ( pushBack( value ) );
	}

	QUANTUM_ASSERT( position.isValid() );
	QUANTUM_ASSERT( _pHead );

	NodeType* pListNode = new NodeType( value );

	pListNode->_pPrev			= position._pListNode->_pPrev;
	pListNode->_pNext			= position._pListNode;
	position._pListNode->_pPrev = pListNode;

	if ( _pHead == position._pListNode )
	{
		_pHead = pListNode;
	}

	_uiSize++;

	return ( NodeType*( pListNode ) );
}

//-----------------------------------------------------------------------------
// Name:		find
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, class NodeType>
NodeType* QmList<T, NodeType>::find( const T& value )
{
	NodeType* it( _pHead );

	while ( it.isValid() && ( *it != value ) )
	{
		it++;
	}

	return (it);
}

//-----------------------------------------------------------------------------
// Name:		remove
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, class NodeType>
void QmList<T, NodeType>::remove( const T& value )
{
	NodeType* pNode = _pHead;

	while ( pNode )
	{
		if ( pNode->_value == value )
		{
			NodeType* pPrev = pNode->_pPrev;
			NodeType* pNext = pNode->_pNext;

			if	( pPrev )
			{
				pPrev->_pNext = pNext;
			}
			else
			{
				_pHead = pNext;
			}

			if	( pNext )
			{
				pNext->_pPrev = pPrev;
			}
			else
			{
				_pQueue = pPrev;
			}

			QUANTUM_ASSERT( _uiSize > 0 );
			_uiSize--;
		}

		pNode = pNode->_pNext;
	}
}

//-----------------------------------------------------------------------------
// Name:		remove
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, class NodeType>
void QmList<T, NodeType>::remove( NodeType* pListNode )
{
	NodeType* pPrev = pListNode->_pPrev;
	NodeType* pNext = pListNode->_pNext;

	if	( pPrev )
	{
		pPrev->_pNext = pNext;
	}
	else
	{
		_pHead = pNext;
	}

	if	( pNext )
	{
		pNext->_pPrev = pPrev;
	}
	else
	{
		_pQueue = pPrev;
	}

	QUANTUM_ASSERT( _uiSize > 0 );
	_uiSize--;
}

//-----------------------------------------------------------------------------
// Name:		head
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, class NodeType>
NodeType* QmList<T, NodeType>::head()
{
	return ( _pHead );
}

//-----------------------------------------------------------------------------
// Name:		queue
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, class NodeType>
NodeType* QmList<T, NodeType>::queue()
{
	return ( _pQueue );
}

//-----------------------------------------------------------------------------
// Name:		QmListNode constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
QmListNode<T>::QmListNode( const T&	value )
: _pPrev( nullptr )
, _pNext( nullptr )
, _value( value )
{

}

#endif