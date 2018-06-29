//*****************************************************************************
//
//	Class:		QmMap
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __QUANTUM_CORE_QM_STD_LIST_H__
#define __QUANTUM_CORE_QM_STD_LIST_H__

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

		inline bool			isValid() const;

		inline iterator&	operator=( const iterator& other );

		inline bool			operator==( const iterator& other );
		inline bool			operator!=( const iterator& other );

		inline iterator&	operator++();
		iterator&			operator++(int);

		inline iterator&	operator--();
		iterator&			operator--(int);

		inline KeyType&		key();
		inline ValueType&	value();

		/*T&					operator*();
		T*					operator->();*/

	private:
							iterator( QmMapNode* pMapNode );

		QmMapNode*			_pMapNode;
	};

					QmMap();
					~QmMap();

	iterator		insert( const KeyType& key, const ValueType& value );
	void			remove( const KeyType& key );
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
template<class T>
QmMap<T>::QmMap()
{
	
}

//-----------------------------------------------------------------------------
// Name:		QmMap destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
QmMap<T>::~QmMap()
{
	
}

//-----------------------------------------------------------------------------
// Name:		insert
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename QmMap<T>::iterator QmMap<T>::insert(const KeyType& key, const ValueType& value)
{
	QUANTUM_ASSERT( _pHead );

	iterator it = find( key );

	if	( it.isValid() )
	{
		it.value() = value;
	}
	else
	{
		QmMapNode* pMapNode = new QmMapNode( key, value );

		pMapNode->_pPrev			= position._pMapNode;
		pMapNode->_pNext			= position._pMapNode->_pNext;
		position._pMapNode->_pNext	= pMapNode;

		if ( _pQueue == position._pMapNode )
		{
			_pQueue = pMapNode;
		}

		_uiSize++;
	}
	
	return	( iterator( pMapNode ) );
}

//-----------------------------------------------------------------------------
// Name:		find
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename QmMap<T>::iterator QmMap<T>::find( const KeyType& key )
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
template<class T>
void QmMap<T>::remove( const T& value )
{
	iterator it( _pHead );

	while ( it.isValid() )
	{
		if ( *it == value )
		{
			QmMapNode* pNode = it._pMapNode;
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

			if ( !pNext )
			{
				return;
			}

			it._pMapNode = pNext;
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
typename QmMap<T>::iterator QmMap<T>::head()
{
	return	( iterator( _pHead ) );
}

//-----------------------------------------------------------------------------
// Name:		queue
// Created:		2013-08-26
//
//-----------------------------------------------------------------------------
template<class T>
typename QmMap<T>::iterator QmMap<T>::queue()
{
	return	( iterator( _pQueue ) );
}

//-----------------------------------------------------------------------------
// Name:		iterator constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
QmMap<T>::iterator::iterator()
: _pMapNode( nullptr )
{
	
}

//-----------------------------------------------------------------------------
// Name:		iterator constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
QmMap<T>::iterator::iterator(QmMapNode*	pMapNode)
: _pMapNode( pMapNode )
{
	
}

//-----------------------------------------------------------------------------
// Name:		isValid
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
bool QmMap<T>::iterator::isValid() const
{
	return	( _pMapNode != nullptr );
}

//-----------------------------------------------------------------------------
// Name:		operator=
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename QmMap<T>::iterator& QmMap<T>::iterator::operator=(const iterator&	other)
{
	_pMapNode = other._pMapNode;
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator==
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
bool QmMap<T>::iterator::operator==(const iterator&	other)
{
	return	( isValid() && ( _pMapNode == other._pMapNode ) );
}

//-----------------------------------------------------------------------------
// Name:		operator!=
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
bool QmMap<T>::iterator::operator!=(const iterator&	other)
{
	return	( !( *this == other ) );
}

//-----------------------------------------------------------------------------
// Name:		operator*
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
T& QmMap<T>::iterator::operator*()
{
	QUANTUM_ASSERT( isValid() );
	return	( _pMapNode->_value );
}

//-----------------------------------------------------------------------------
// Name:		operator->
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
T* QmMap<T>::iterator::operator->()
{
	QUANTUM_ASSERT( isValid() );
	return	( &_pMapNode->_value );
}

//-----------------------------------------------------------------------------
// Name:		operator++
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename QmMap<T>::iterator& QmMap<T>::iterator::operator++()
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
typename QmMap<T>::iterator& QmMap<T>::iterator::operator++(int)
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
template<class T>
typename QmMap<T>::iterator& QmMap<T>::iterator::operator--()
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
typename QmMap<T>::iterator& QmMap<T>::iterator::operator--(int)
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
template<class T>
QmMap<T>::QmMapNode::QmMapNode(const T&	value)
: _pPrev	( nullptr )
, _pNext	( nullptr )
, _value	( value )
{
	
}

#endif