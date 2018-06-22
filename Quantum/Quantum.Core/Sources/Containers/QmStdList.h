//*****************************************************************************
//
//	Class:		QmStdList
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __QUANTUM_CORE_QM_STD_LIST_H__
#define __QUANTUM_CORE_QM_STD_LIST_H__

template<class T>
class QmStdList
{
private:
	struct QmStdListNode
	{
					QmStdListNode( const T& value );

		QmStdListNode*	_pPrev;
		QmStdListNode*	_pNext;
		T				_value;
	};

public:
	class iterator
	{
		friend class QmStdList;

	public:
							iterator();

		inline bool			isValid() const;

		inline iterator&	operator=( const iterator& other );

		inline bool			operator==( const iterator& other );
		inline bool			operator!=( const iterator& other );

		inline iterator&	operator++();
		iterator&			operator++(int);

		inline iterator&	operator--();
		iterator&			operator--(int);

		T&					operator*();
		T*					operator->();

	private:
							iterator( QmStdListNode* pListNode );

		QmStdListNode*		_pListNode;
	};

					QmStdList();
					~QmStdList();

	iterator		pushBack( const T& value );
	iterator		pushFront( const T& value );
	iterator		insertAfter( const iterator& position, const T& value );
	iterator		insertBefore( const iterator& position, const T& value );
	void			remove( const T& value );

	iterator		find( const T& value );

	inline iterator	head();
	inline iterator	queue();

private:
	QmStdListNode*	_pHead	= nullptr;
	QmStdListNode*	_pQueue	= nullptr;
	uint32			_uiSize	= 0;
};

//*****************************************************************************
//	Template methods declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		QmStdList constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
QmStdList<T>::QmStdList()
{
	
}

//-----------------------------------------------------------------------------
// Name:		QmStdList destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
QmStdList<T>::~QmStdList()
{
	
}

//-----------------------------------------------------------------------------
// Name:		pushBack
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename QmStdList<T>::iterator QmStdList<T>::pushBack(const T&	value)
{
	QmStdListNode* pListNode = new QmStdListNode( value );

	if	( _pHead )
	{
		QUANTUM_ASSERT( _pQueue );

		pListNode->_pPrev	= _pQueue;
		_pQueue->_pNext		= pListNode;
		_pQueue				= pListNode;
	}
	else
	{
		_pHead	= pListNode;
		_pQueue	= pListNode;
	}

	_uiSize++;

	return	( iterator( pListNode ) );
}

//-----------------------------------------------------------------------------
// Name:		pushFront
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename QmStdList<T>::iterator QmStdList<T>::pushFront(const T&	value)
{
	QmStdListNode* pListNode = new QmStdListNode( value );

	if	( _pHead )
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

	return	( iterator( pListNode ) );
}

//-----------------------------------------------------------------------------
// Name:		insertAfter
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename QmStdList<T>::iterator QmStdList<T>::insertAfter(const iterator&	position, 
													  const T&			value)
{
	QUANTUM_ASSERT( position.isValid() );
	QUANTUM_ASSERT( _pHead );

	QmStdListNode* pListNode = new QmStdListNode( value );

	pListNode->_pPrev			= position._pListNode;
	pListNode->_pNext			= position._pListNode->_pNext;
	position._pListNode->_pNext	= pListNode;

	if ( _pQueue == position._pListNode )
	{
		_pQueue = pListNode;
	}

	_uiSize++;
	
	return	( iterator( pListNode ) );
}

//-----------------------------------------------------------------------------
// Name:		insertBefore
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename QmStdList<T>::iterator QmStdList<T>::insertBefore(const iterator&	position, 
													   const T&				value)
{
	if	( _uiSize == 0 )
	{
		return ( pushBack( value ) );
	}

	QUANTUM_ASSERT( position.isValid() );
	QUANTUM_ASSERT( _pHead );

	QmStdListNode* pListNode = new QmStdListNode( value );

	pListNode->_pPrev			= position._pListNode->_pPrev;
	pListNode->_pNext			= position._pListNode;
	position._pListNode->_pPrev	= pListNode;

	if ( _pHead == position._pListNode )
	{
		_pHead = pListNode;
	}

	_uiSize++;
	
	return	( iterator( pListNode ) );
}

//-----------------------------------------------------------------------------
// Name:		find
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename QmStdList<T>::iterator QmStdList<T>::find( const T& value )
{
	iterator it( _pHead );

	while ( it.isValid() && ( *it != value ) )
	{
		it++;
	}

	return	( it );
}

//-----------------------------------------------------------------------------
// Name:		remove
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void QmStdList<T>::remove( const T& value )
{
	iterator it( _pHead );

	while ( it.isValid() )
	{
		if ( *it == value )
		{
			QmStdListNode* pNode = it._pListNode;
			QmStdListNode* pPrev = pNode->_pPrev;
			QmStdListNode* pNext = pNode->_pNext;

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

			if ( !pNext )
			{
				return;
			}

			it._pListNode = pNext;
		}

		it++;
	}
}

//-----------------------------------------------------------------------------
// Name:		head
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename QmStdList<T>::iterator QmStdList<T>::head()
{
	return	( iterator( _pHead ) );
}

//-----------------------------------------------------------------------------
// Name:		queue
// Created:		2013-08-26
//
//-----------------------------------------------------------------------------
template<class T>
typename QmStdList<T>::iterator QmStdList<T>::queue()
{
	return	( iterator( _pQueue ) );
}

//-----------------------------------------------------------------------------
// Name:		iterator constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
QmStdList<T>::iterator::iterator()
: _pListNode( nullptr )
{
	
}

//-----------------------------------------------------------------------------
// Name:		iterator constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
QmStdList<T>::iterator::iterator(QmStdListNode*	pListNode)
: _pListNode( pListNode )
{
	
}

//-----------------------------------------------------------------------------
// Name:		isValid
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
bool QmStdList<T>::iterator::isValid() const
{
	return	( _pListNode != nullptr );
}

//-----------------------------------------------------------------------------
// Name:		operator=
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename QmStdList<T>::iterator& QmStdList<T>::iterator::operator=(const iterator&	other)
{
	_pListNode = other._pListNode;
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator==
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
bool QmStdList<T>::iterator::operator==(const iterator&	other)
{
	return	( isValid() && ( _pListNode == other._pListNode ) );
}

//-----------------------------------------------------------------------------
// Name:		operator!=
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
bool QmStdList<T>::iterator::operator!=(const iterator&	other)
{
	return	( !( *this == other ) );
}

//-----------------------------------------------------------------------------
// Name:		operator*
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
T& QmStdList<T>::iterator::operator*()
{
	QUANTUM_ASSERT( isValid() );
	return	( _pListNode->_value );
}

//-----------------------------------------------------------------------------
// Name:		operator->
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
T* QmStdList<T>::iterator::operator->()
{
	QUANTUM_ASSERT( isValid() );
	return	( &_pListNode->_value );
}

//-----------------------------------------------------------------------------
// Name:		operator++
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename QmStdList<T>::iterator& QmStdList<T>::iterator::operator++()
{
	(*this)++;
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator++
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename QmStdList<T>::iterator& QmStdList<T>::iterator::operator++(int)
{
	QUANTUM_ASSERT( isValid() );

	if	( _pListNode )
	{
		_pListNode = _pListNode->_pNext;
	}

	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator--
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename QmStdList<T>::iterator& QmStdList<T>::iterator::operator--()
{
	(*this)--;
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator--
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename QmStdList<T>::iterator& QmStdList<T>::iterator::operator--(int)
{
	QUANTUM_ASSERT( isValid() && _pListNode->_pPrev );

	if	( _pListNode )
	{
		_pListNode = _pListNode->_pPrev;
	}

	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		QmStdListNode constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
QmStdList<T>::QmStdListNode::QmStdListNode(const T&	value)
: _pPrev	( nullptr )
, _pNext	( nullptr )
, _value	( value )
{
	
}

#endif