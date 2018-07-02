//*****************************************************************************
//
//	Class:		QmMap
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __QUANTUM_CORE_QM_MAP_H__
#define __QUANTUM_CORE_QM_MAP_H__

template<class KeyType, class ValueType>
class QmMap
{
private:
	struct QmMapNode
	{
					QmMapNode( const KeyType& key, const ValueType& value );

		QmMapNode*	_pPrev;
		QmMapNode*	_pNext;
		KeyType		_key;
		ValueType	_value;
	};

public:
	class iterator
	{
		friend class QmMap;

	public:
								iterator();

		inline bool				isValid() const;

		inline const KeyType&	key() const;
		inline const ValueType&	value() const;
		inline void				setValue( const ValueType& value );

		inline iterator&		operator=( const iterator& other );

		inline bool				operator==( const iterator& other );
		inline bool				operator!=( const iterator& other );

		inline iterator&		operator++();
		iterator&				operator++(int);

		inline iterator&		operator--();
		iterator&				operator--(int);

	private:
								iterator( QmMapNode* pMapNode );

		QmMapNode*				_pMapNode;
	};

					QmMap();
					~QmMap();

	iterator		pushBack( const KeyType& key, const ValueType& value );
	iterator		insertAfter( const iterator& position, const KeyType& key, const ValueType& value );
	iterator		insertBefore( const iterator& position, const KeyType& key, const ValueType& value );
	void			remove( const KeyType& key );
	void			remove( const iterator& position );
	iterator		find( const KeyType& key );

	inline iterator	head();
	inline iterator	queue();

private:
	QmMapNode*		_pHead	= nullptr;
	QmMapNode*		_pQueue	= nullptr;
	uint32			_uiSize	= 0;
};

//*****************************************************************************
//	Template methods declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		QmMap constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class KeyType, class ValueType>
QmMap<KeyType, ValueType>::QmMap()
{
	
}

//-----------------------------------------------------------------------------
// Name:		QmMap destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class KeyType, class ValueType>
QmMap<KeyType, ValueType>::~QmMap()
{
	
}

//-----------------------------------------------------------------------------
// Name:		pushBack
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class KeyType, class ValueType>
typename QmMap<KeyType, ValueType>::iterator QmMap<KeyType, ValueType>::pushBack(const KeyType& key, const ValueType& value)
{
	iterator it = find( key );

	if	( it.isValid() )
	{
		remove( it );
	}
	
	QmMapNode* pMapNode = new QmMapNode( key, value );

	if ( _pHead )
	{
		QUANTUM_ASSERT( _pQueue );

		pMapNode->_pPrev	= _pQueue;
		_pQueue->_pNext		= pMapNode;			
		_pQueue				= pMapNode;
	}
	else
	{
		_pHead	= pMapNode;
		_pQueue	= pMapNode;
	}

	_uiSize++;

	return	( iterator( pMapNode ) );
}

//-----------------------------------------------------------------------------
// Name:		insertAfter
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class KeyType, class ValueType>
typename QmMap<KeyType, ValueType>::iterator QmMap<KeyType, ValueType>::insertAfter(const iterator&		position, 
																					const KeyType&		key, 
																					const ValueType&	value)
{
	QUANTUM_ASSERT( position.isValid() );
	QUANTUM_ASSERT( _pHead );

	iterator it = find( key );

	if	( it.isValid() )
	{
		remove( it );
	}

	QmMapNode* pMapNode = new QmMapNode( key, value );
	QmMapNode* pNext	= position._pMapNode->_pNext;

	pMapNode->_pPrev			= position._pMapNode;
	pMapNode->_pNext			= position._pMapNode->_pNext;
	position._pMapNode->_pNext	= pMapNode;

	if ( _pQueue == position._pMapNode )
	{
		_pQueue = pMapNode;
	}
	else
	{
		pNext->_pPrev = pMapNode;
	}

	_uiSize++;
	
	return	( iterator( pMapNode ) );
}

//-----------------------------------------------------------------------------
// Name:		insertBefore
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class KeyType, class ValueType>
typename QmMap<KeyType, ValueType>::iterator QmMap<KeyType, ValueType>::insertBefore(const iterator&	position, 
																					 const KeyType&		key, 
																					 const ValueType&	value)
{
	QUANTUM_ASSERT( position.isValid() );
	QUANTUM_ASSERT( _pHead );

	iterator it = find( key );

	if	( it.isValid() )
	{
		remove( it );
	}

	QmMapNode* pMapNode = new QmMapNode( key, value );
	QmMapNode* pPrev	= position._pMapNode->_pPrev;

	pMapNode->_pPrev			= position._pMapNode->_pPrev;
	pMapNode->_pNext			= position._pMapNode;
	position._pMapNode->_pPrev	= pMapNode;

	if ( _pHead == position._pMapNode )
	{
		_pHead = pMapNode;
	}
	else
	{
		pPrev->_pNext = pMapNode;
	}

	_uiSize++;
	
	return	( iterator( pMapNode ) );
}

//-----------------------------------------------------------------------------
// Name:		find
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class KeyType, class ValueType>
typename QmMap<KeyType, ValueType>::iterator QmMap<KeyType, ValueType>::find( const KeyType& key )
{
	iterator it( _pHead );

	while ( it.isValid() && ( it.key() != key ) )
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
template<class KeyType, class ValueType>
void QmMap<KeyType, ValueType>::remove( const KeyType& key )
{
	iterator it = find( key );

	if	( it.isValid() )
	{
		remove( it );
	}
}

//-----------------------------------------------------------------------------
// Name:		remove
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class KeyType, class ValueType>
void QmMap<KeyType, ValueType>::remove( const iterator& position )
{
	QUANTUM_ASSERT( position.isValid() );

	QmMapNode* pNode = position._pMapNode;
	QmMapNode* pPrev = pNode->_pPrev;
	QmMapNode* pNext = pNode->_pNext;

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
template<class KeyType, class ValueType>
typename QmMap<KeyType, ValueType>::iterator QmMap<KeyType, ValueType>::head()
{
	return	( iterator( _pHead ) );
}

//-----------------------------------------------------------------------------
// Name:		queue
// Created:		2013-08-26
//
//-----------------------------------------------------------------------------
template<class KeyType, class ValueType>
typename QmMap<KeyType, ValueType>::iterator QmMap<KeyType, ValueType>::queue()
{
	return	( iterator( _pQueue ) );
}

//-----------------------------------------------------------------------------
// Name:		iterator constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class KeyType, class ValueType>
QmMap<KeyType, ValueType>::iterator::iterator()
: _pMapNode( nullptr )
{
	
}

//-----------------------------------------------------------------------------
// Name:		iterator constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class KeyType, class ValueType>
QmMap<KeyType, ValueType>::iterator::iterator(QmMapNode*	pMapNode)
: _pMapNode( pMapNode )
{
	
}

//-----------------------------------------------------------------------------
// Name:		isValid
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class KeyType, class ValueType>
bool QmMap<KeyType, ValueType>::iterator::isValid() const
{
	return	( _pMapNode != nullptr );
}

//-----------------------------------------------------------------------------
// Name:		key
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class KeyType, class ValueType>
const KeyType& QmMap<KeyType, ValueType>::iterator::key() const
{
	return	( _pMapNode->_key );
}

//-----------------------------------------------------------------------------
// Name:		value
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class KeyType, class ValueType>
const ValueType& QmMap<KeyType, ValueType>::iterator::value() const
{
	return	( _pMapNode->_value );
}

//-----------------------------------------------------------------------------
// Name:		setValue
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class KeyType, class ValueType>
void QmMap<KeyType, ValueType>::iterator::setValue(const ValueType& value)
{
	_pMapNode->_value = value;
}

//-----------------------------------------------------------------------------
// Name:		operator=
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class KeyType, class ValueType>
typename QmMap<KeyType, ValueType>::iterator& QmMap<KeyType, ValueType>::iterator::operator=(const iterator&	other)
{
	_pMapNode = other._pMapNode;
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator==
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class KeyType, class ValueType>
bool QmMap<KeyType, ValueType>::iterator::operator==(const iterator&	other)
{
	return	( isValid() && ( _pMapNode == other._pMapNode ) );
}

//-----------------------------------------------------------------------------
// Name:		operator!=
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class KeyType, class ValueType>
bool QmMap<KeyType, ValueType>::iterator::operator!=(const iterator&	other)
{
	return	( !( *this == other ) );
}

//-----------------------------------------------------------------------------
// Name:		operator++
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class KeyType, class ValueType>
typename QmMap<KeyType, ValueType>::iterator& QmMap<KeyType, ValueType>::iterator::operator++()
{
	(*this)++;
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator++
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class KeyType, class ValueType>
typename QmMap<KeyType, ValueType>::iterator& QmMap<KeyType, ValueType>::iterator::operator++(int)
{
	QUANTUM_ASSERT( isValid() );

	if	( _pMapNode )
	{
		_pMapNode = _pMapNode->_pNext;
	}

	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator--
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class KeyType, class ValueType>
typename QmMap<KeyType, ValueType>::iterator& QmMap<KeyType, ValueType>::iterator::operator--()
{
	(*this)--;
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator--
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class KeyType, class ValueType>
typename QmMap<KeyType, ValueType>::iterator& QmMap<KeyType, ValueType>::iterator::operator--(int)
{
	QUANTUM_ASSERT( isValid() && _pMapNode->_pPrev );

	if	( _pMapNode )
	{
		_pMapNode = _pMapNode->_pPrev;
	}

	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		QmMapNode constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class KeyType, class ValueType>
QmMap<KeyType, ValueType>::QmMapNode::QmMapNode(const KeyType& key, const ValueType& value)
: _pPrev	( nullptr )
, _pNext	( nullptr )
, _key		( key )
, _value	( value )
{
	
}

#endif