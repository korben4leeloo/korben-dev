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
	class QmIterator
	{
		friend class QmList;

	public:
							QmIterator();

		inline bool			isValid() const;

		inline QmIterator&	operator=( const QmIterator& other );

		inline QmIterator&	operator++();
		QmIterator&			operator++(int);

		inline QmIterator&	operator--();
		QmIterator&			operator--(int);

		T&					operator*();
		T*					operator->();

	private:
							QmIterator( QmListNode* pListNode );

		QmListNode*			_pListNode;
	};

						QmList();
						~QmList();

	QmIterator			pushBack( const T& value );
	QmIterator			pushFront( const T& value );
	QmIterator			insertAfter( const QmIterator& position, const T& value );
	QmIterator			insertBefore( const QmIterator& position, const T& value );
	//void				remove( const QmIterator& position );

	QmIterator			find( const T& value );

	inline QmIterator	begin();
	inline QmIterator	end();

private:
	QmListNode*			_pHead;
	QmListNode*			_pLast;
	uint32				_uiSize;
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
typename QmList<T>::QmIterator QmList<T>::pushBack(const T&	value)
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

	return	( QmIterator( pListNode ) );
}

//-----------------------------------------------------------------------------
// Name:		pushFront
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename QmList<T>::QmIterator QmList<T>::pushFront(const T&	value)
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

	return	( QmIterator( pListNode ) );
}

//-----------------------------------------------------------------------------
// Name:		insertAfter
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename QmList<T>::QmIterator QmList<T>::insertAfter(const QmIterator&	position, 
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
	
	return	( QmIterator( pListNode ) );
}

//-----------------------------------------------------------------------------
// Name:		insertBefore
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename QmList<T>::QmIterator QmList<T>::insertBefore(const QmIterator&	position, 
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
	
	return	( QmIterator( pListNode ) );
}

//-----------------------------------------------------------------------------
// Name:		find
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename QmList<T>::QmIterator QmList<T>::find( const T& value )
{
	QmIterator it( _pHead );

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
typename QmList<T>::QmIterator QmList<T>::begin()
{
	return	( QmIterator( _pHead ) );
}

//-----------------------------------------------------------------------------
// Name:		end
// Created:		2013-08-26
//
//-----------------------------------------------------------------------------
template<class T>
typename QmList<T>::QmIterator QmList<T>::end()
{
	return	( QmIterator( _pLast ) );
}

//-----------------------------------------------------------------------------
// Name:		QmIterator constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
QmList<T>::QmIterator::QmIterator()
: _pListNode( nullptr )
{
	
}

//-----------------------------------------------------------------------------
// Name:		QmIterator constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
QmList<T>::QmIterator::QmIterator(QmListNode*	pListNode)
: _pListNode( pListNode )
{
	
}

//-----------------------------------------------------------------------------
// Name:		isValid
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
bool QmList<T>::QmIterator::isValid() const
{
	return	( _pListNode != nullptr );
}

//-----------------------------------------------------------------------------
// Name:		operator=
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename QmList<T>::QmIterator& QmList<T>::QmIterator::operator=(const QmIterator&	other)
{
	_pListNode = other._pListNode;
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator*
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
T& QmList<T>::QmIterator::operator*()
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
T* QmList<T>::QmIterator::operator->()
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
typename QmList<T>::QmIterator& QmList<T>::QmIterator::operator++()
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
typename QmList<T>::QmIterator& QmList<T>::QmIterator::operator++(int)
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
typename QmList<T>::QmIterator& QmList<T>::QmIterator::operator--()
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
typename QmList<T>::QmIterator& QmList<T>::QmIterator::operator--(int)
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