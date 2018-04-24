//*****************************************************************************
//
//	Class:		QmList
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __QUANTUM_CORE_TK_LIST_H__
#define __QUANTUM_CORE_TK_LIST_H__

template<class T>
class QmList
{
private:
	struct QmListNode
	{
					QmListNode( const T& value );

		QmListNode*	_pPrev;
		QmListNode*	_pNext;
		T			_value;
	};

public:
	class iterator
	{
		friend class QmList;

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
							iterator( QmListNode* pListNode );

		QmListNode*			_pListNode;
	};

					QmList();
					~QmList();

	iterator		pushBack( const T& value );
	iterator		pushFront( const T& value );
	iterator		insertAfter( const iterator& position, const T& value );
	iterator		insertBefore( const iterator& position, const T& value );
	//void			remove( const iterator& position );

	iterator		find( const T& value );

	inline iterator	begin();
	inline iterator	end();

private:
	QmListNode*		_pHead;
	QmListNode*		_pLast;
	uint32			_uiSize;
};

//*****************************************************************************
//	Template methods declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		QmList constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
QmList<T>::QmList()
: _pHead	( nullptr )
, _pLast	( nullptr )
, _uiSize	( 0 )
{
	
}

//-----------------------------------------------------------------------------
// Name:		QmList destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
QmList<T>::~QmList()
{
	
}

//-----------------------------------------------------------------------------
// Name:		pushBack
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename QmList<T>::iterator QmList<T>::pushBack(const T&	value)
{
	QmListNode* pListNode = new QmListNode( value );

	if	( _pHead )
	{
		QUANTUM_ASSERT( _pLast );

		pListNode->_pPrev	= _pLast;
		_pLast->_pNext		= pListNode;
		_pLast				= pListNode;
	}
	else
	{
		_pHead = pListNode;
		_pLast = pListNode;
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
typename QmList<T>::iterator QmList<T>::pushFront(const T&	value)
{
	QmListNode* pListNode = new QmListNode( value );

	if	( _pHead )
	{
		QUANTUM_ASSERT( _pLast );

		pListNode->_pNext	= _pHead;
		_pHead->_pPrev		= pListNode;
		_pHead				= pListNode;
	}
	else
	{
		_pHead = pListNode;
		_pLast = pListNode;
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
typename QmList<T>::iterator QmList<T>::insertAfter(const iterator&	position, 
													  const T&			value)
{
	QUANTUM_ASSERT( position.isValid() );
	QUANTUM_ASSERT( _pHead );

	QmListNode* pListNode = new QmListNode( value );

	pListNode->_pPrev			= position._pListNode;
	pListNode->_pNext			= position._pListNode->_pNext;
	position._pListNode->_pNext	= pListNode;

	if ( _pLast == position._pListNode )
	{
		_pLast = pListNode;
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
typename QmList<T>::iterator QmList<T>::insertBefore(const iterator&	position, 
													   const T&				value)
{
	if	( _uiSize == 0 )
	{
		return ( pushBack( value ) );
	}

	QUANTUM_ASSERT( position.isValid() );
	QUANTUM_ASSERT( _pHead );

	QmListNode* pListNode = new QmListNode( value );

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
typename QmList<T>::iterator QmList<T>::find( const T& value )
{
	iterator it( _pHead );

	while ( it.isValid() && ( *it != value ) )
	{
		it++;
	}

	return	( it );
}

//-----------------------------------------------------------------------------
// Name:		begin
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename QmList<T>::iterator QmList<T>::begin()
{
	return	( iterator( _pHead ) );
}

//-----------------------------------------------------------------------------
// Name:		end
// Created:		2013-08-26
//
//-----------------------------------------------------------------------------
template<class T>
typename QmList<T>::iterator QmList<T>::end()
{
	return	( iterator( _pLast ) );
}

//-----------------------------------------------------------------------------
// Name:		iterator constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
QmList<T>::iterator::iterator()
: _pListNode( nullptr )
{
	
}

//-----------------------------------------------------------------------------
// Name:		iterator constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
QmList<T>::iterator::iterator(QmListNode*	pListNode)
: _pListNode( pListNode )
{
	
}

//-----------------------------------------------------------------------------
// Name:		isValid
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
bool QmList<T>::iterator::isValid() const
{
	return	( _pListNode != nullptr );
}

//-----------------------------------------------------------------------------
// Name:		operator=
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename QmList<T>::iterator& QmList<T>::iterator::operator=(const iterator&	other)
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
bool QmList<T>::iterator::operator==(const iterator&	other)
{
	return	( isValid() && ( _pListNode == other._pListNode ) );
}

//-----------------------------------------------------------------------------
// Name:		operator!=
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
bool QmList<T>::iterator::operator!=(const iterator&	other)
{
	return	( !( *this == other ) );
}

//-----------------------------------------------------------------------------
// Name:		operator*
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
T& QmList<T>::iterator::operator*()
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
T* QmList<T>::iterator::operator->()
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
typename QmList<T>::iterator& QmList<T>::iterator::operator++()
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
typename QmList<T>::iterator& QmList<T>::iterator::operator++(int)
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
typename QmList<T>::iterator& QmList<T>::iterator::operator--()
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
typename QmList<T>::iterator& QmList<T>::iterator::operator--(int)
{
	QUANTUM_ASSERT( isValid() && _pListNode->_pPrev );

	if	( _pListNode )
	{
		_pListNode = _pListNode->_pPrev;
	}

	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		QmListNode constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
QmList<T>::QmListNode::QmListNode(const T&	value)
: _pPrev	( nullptr )
, _pNext	( nullptr )
, _value	( value )
{
	
}

#endif