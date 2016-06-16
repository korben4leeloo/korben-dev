//*****************************************************************************
//
//	Class:		TkList
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_CORE_TK_LIST_H__
#define __TARS_CORE_TK_LIST_H__

template<class T>
class TkList
{
private:
	struct TkListNode
	{
					TkListNode( const T& value );

		TkListNode*	_pPrev;
		TkListNode*	_pNext;
		T			_value;
	};

public:
	class TkIterator
	{
		friend class TkList;

	public:
							TkIterator();

		inline bool			isValid() const;

		inline TkIterator&	operator=( const TkIterator& other );

		inline TkIterator&	operator++();
		TkIterator&			operator++(int);

		inline TkIterator&	operator--();
		TkIterator&			operator--(int);

		T&					operator*();
		T*					operator->();

	private:
							TkIterator( TkListNode* pListNode );

		TkListNode*			_pListNode;
	};

						TkList();
						~TkList();

	TkIterator			pushBack( const T& value );
	TkIterator			pushFront( const T& value );
	TkIterator			insert( const TkIterator& position, const T& value );
	//void				remove( const TkIterator& position );

	TkIterator			find( const T& value );

	inline TkIterator	begin();
	inline TkIterator	end();

private:
	TkListNode*			_pHead;
	TkListNode*			_pLast;
	uint32				_uiSize;
};

//*****************************************************************************
//	Template methods declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		TkList constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
TkList<T>::TkList()
: _pHead	( nullptr )
, _pLast	( nullptr )
, _uiSize	( 0 )
{
	
}

//-----------------------------------------------------------------------------
// Name:		TkList destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
TkList<T>::~TkList()
{
	
}

//-----------------------------------------------------------------------------
// Name:		pushBack
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename TkList<T>::TkIterator TkList<T>::pushBack(const T&	value)
{
	TkListNode* pListNode = new TkListNode( value );

	if	( _pHead )
	{
		TARS_ASSERT( _pLast );

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

	return	( TkIterator( pListNode ) );
}

//-----------------------------------------------------------------------------
// Name:		pushFront
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename TkList<T>::TkIterator TkList<T>::pushFront(const T&	value)
{
	TkListNode* pListNode = new TkListNode( value );

	if	( _pHead )
	{
		TARS_ASSERT( _pLast );

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

	return	( TkIterator( pListNode ) );
}

//-----------------------------------------------------------------------------
// Name:		insert
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename TkList<T>::TkIterator TkList<T>::insert(const TkIterator&	position, 
												 const T&			value)
{
	TARS_ASSERT( position.isValid() );
	TARS_ASSERT( _pHead );

	TkListNode* pListNode = new TkListNode( value );

	pListNode->_pPrev			= position._pListNode;
	pListNode->_pNext			= position._pListNode->_pNext;
	position._pListNode->_pNext	= pListNode;

	if ( _pLast == position._pListNode )
	{
		_pLast = pListNode;
	}

	_uiSize++;
	
	return	( TkIterator( pListNode ) );
}

//-----------------------------------------------------------------------------
// Name:		find
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename TkList<T>::TkIterator TkList<T>::find( const T& value )
{
	TkIterator it( _pHead );

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
typename TkList<T>::TkIterator TkList<T>::begin()
{
	return	( TkIterator( _pHead ) );
}

//-----------------------------------------------------------------------------
// Name:		end
// Created:		2013-08-26
//
//-----------------------------------------------------------------------------
template<class T>
typename TkList<T>::TkIterator TkList<T>::end()
{
	return	( TkIterator( _pLast ) );
}

//-----------------------------------------------------------------------------
// Name:		TkIterator constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
TkList<T>::TkIterator::TkIterator()
: _pListNode( nullptr )
{
	
}

//-----------------------------------------------------------------------------
// Name:		TkIterator constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
TkList<T>::TkIterator::TkIterator(TkListNode*	pListNode)
: _pListNode( pListNode )
{
	
}

//-----------------------------------------------------------------------------
// Name:		isValid
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
bool TkList<T>::TkIterator::isValid() const
{
	return	( _pListNode != nullptr );
}

//-----------------------------------------------------------------------------
// Name:		operator=
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename TkList<T>::TkIterator& TkList<T>::TkIterator::operator=(const TkIterator&	other)
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
T& TkList<T>::TkIterator::operator*()
{
	TARS_ASSERT( isValid() );
	return	( _pListNode->_value );
}

//-----------------------------------------------------------------------------
// Name:		operator->
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
T* TkList<T>::TkIterator::operator->()
{
	TARS_ASSERT( isValid() );
	return	( &_pListNode->_value );
}

//-----------------------------------------------------------------------------
// Name:		operator++
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename TkList<T>::TkIterator& TkList<T>::TkIterator::operator++()
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
typename TkList<T>::TkIterator& TkList<T>::TkIterator::operator++(int)
{
	TARS_ASSERT( isValid() );

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
typename TkList<T>::TkIterator& TkList<T>::TkIterator::operator--()
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
typename TkList<T>::TkIterator& TkList<T>::TkIterator::operator--(int)
{
	TARS_ASSERT( isValid() && _pListNode->_pPrev );

	if	( _pListNode )
	{
		_pListNode = _pListNode->_pPrev;
	}

	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		TkListNode constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
TkList<T>::TkListNode::TkListNode(const T&	value)
: _pPrev	( nullptr )
, _pNext	( nullptr )
, _value	( value )
{
	
}

#endif