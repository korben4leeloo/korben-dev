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
	{
		friend class TkList;

	public:

		inline bool			isValid() const;




		T&					operator*();
		T*					operator->();

	private:

		TkListNode*			_pListNode;
	};

						TkList();
						~TkList();




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

}

//-----------------------------------------------------------------------------
// Name:		pushFront
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
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

}

//-----------------------------------------------------------------------------
// Name:		insert
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
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
	
}

//-----------------------------------------------------------------------------
// Name:		find
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
{

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
{
}

//-----------------------------------------------------------------------------
// Name:		end
// Created:		2013-08-26
//
//-----------------------------------------------------------------------------
template<class T>
{
}

//-----------------------------------------------------------------------------
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
{
	
}

//-----------------------------------------------------------------------------
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
: _pListNode( pListNode )
{
	
}

//-----------------------------------------------------------------------------
// Name:		isValid
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
{
}

//-----------------------------------------------------------------------------
// Name:		operator=
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
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
, _value	( value )
{
	
}

#endif
