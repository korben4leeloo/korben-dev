//*****************************************************************************
//
//	Class:		KmList
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __KosmoCore_KmList_h__
#define __KosmoCore_KmList_h__

#include	"Root.h"

KOSMO_CORE_NAMESPACE_BEGIN

template<class T>
class KmList
{
private:
	struct KmListNode
	{
					KmListNode( const T& value );

		KmListNode*	_pPrev;
		KmListNode*	_pNext;
		T			_value;
	};

public:
	class KmIterator
	{
		friend class KmList;

	public:
							KmIterator();
							/*Iterator( const Iterator& other );
							Iterator( const Iterator&& other );*/
							//~KmListIterator();

		inline bool			isValid() const;

		inline KmIterator&	operator=( const KmIterator& other );

		inline KmIterator&	operator++();
		KmIterator&			operator++(int);

		inline KmIterator&	operator--();
		KmIterator&			operator--(int);

		T&					operator*();
		T*					operator->();

	private:
							KmIterator( KmListNode* pListNode );

		KmListNode*			_pListNode;
	};

						KmList();
						~KmList();

	KmIterator			pushBack( const T& value );
	KmIterator			pushFront( const T& value );
	KmIterator			insert( const KmIterator& position, const T& value );
	void				remove( const KmIterator& position );

	KmIterator			find( const T& value );

	inline KmIterator	begin();
	inline KmIterator	end();

private:
	KmListNode*			_pHead;
	KmListNode*			_pLast;
	uint32				_uiSize;
};

//*****************************************************************************
//	Template methods declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		KmList constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
KmList<T>::KmList()
: _pHead	( NULL )
, _pLast	( NULL )
, _uiSize	( 0 )
{
	
}

//-----------------------------------------------------------------------------
// Name:		KmList destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
KmList<T>::~KmList()
{
	
}

//-----------------------------------------------------------------------------
// Name:		pushBack
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename KmList<T>::KmIterator KmList<T>::pushBack(const T&	value)
{
	KmListNode* pListNode = new KmListNode( value );

	if	( _pHead )
	{
		KOSMO_ASSERT( _pLast );

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

	return	( KmIterator( pListNode ) );
}

//-----------------------------------------------------------------------------
// Name:		pushFront
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename KmList<T>::KmIterator KmList<T>::pushFront(const T&	value)
{
	KmListNode* pListNode = new KmListNode( value );

	if	( _pHead )
	{
		KOSMO_ASSERT( _pLast );

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

	return	( KmIterator( pListNode ) );
}

//-----------------------------------------------------------------------------
// Name:		insert
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename KmList<T>::KmIterator KmList<T>::insert(const KmIterator&	position, 
												 const T&			value)
{
	KOSMO_ASSERT( position.isValid() );
	KOSMO_ASSERT( _pHead );

	KmListNode* pListNode = new KmListNode( value );

	pListNode->_pPrev			= position._pListNode;
	pListNode->_pNext			= position._pListNode->_pNext;
	position._pListNode->_pNext	= pListNode;

	if ( _pLast == position._pListNode )
	{
		_pLast = pListNode;
	}

	_uiSize++;
	
	return	( KmIterator( pListNode ) );
}

//-----------------------------------------------------------------------------
// Name:		find
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename KmList<T>::KmIterator KmList<T>::find( const T& value )
{
	KmIterator it( _pHead );

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
typename KmList<T>::KmIterator KmList<T>::begin()
{
	return	( KmIterator( _pHead ) );
}

//-----------------------------------------------------------------------------
// Name:		end
// Created:		2013-08-26
//
//-----------------------------------------------------------------------------
template<class T>
typename KmList<T>::KmIterator KmList<T>::end()
{
	return	( KmIterator( _pLast ) );
}

//-----------------------------------------------------------------------------
// Name:		KmIterator constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
KmList<T>::KmIterator::KmIterator()
: _pListNode( NULL )
{
	
}

//-----------------------------------------------------------------------------
// Name:		KmIterator constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
KmList<T>::KmIterator::KmIterator(KmListNode*	pListNode)
: _pListNode( pListNode )
{
	
}

//-----------------------------------------------------------------------------
// Name:		isValid
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
bool KmList<T>::KmIterator::isValid() const
{
	return	( _pListNode != NULL );
}

//-----------------------------------------------------------------------------
// Name:		operator=
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename KmList<T>::KmIterator& KmList<T>::KmIterator::operator=(const KmIterator&	other)
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
T& KmList<T>::KmIterator::operator*()
{
	KOSMO_ASSERT( isValid() );
	return	( _pListNode->_value );
}

//-----------------------------------------------------------------------------
// Name:		operator->
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
T* KmList<T>::KmIterator::operator->()
{
	KOSMO_ASSERT( isValid() );
	return	( &_pListNode->_value );
}

//-----------------------------------------------------------------------------
// Name:		operator++
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
typename KmList<T>::KmIterator& KmList<T>::KmIterator::operator++()
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
typename KmList<T>::KmIterator& KmList<T>::KmIterator::operator++(int)
{
	KOSMO_ASSERT( isValid() );

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
typename KmList<T>::KmIterator& KmList<T>::KmIterator::operator--()
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
typename KmList<T>::KmIterator& KmList<T>::KmIterator::operator--(int)
{
	KOSMO_ASSERT( isValid() && _pListNode->_pPrev );

	if	( _pListNode )
	{
		_pListNode = _pListNode->_pPrev;
	}

	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		KmListNode constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
KmList<T>::KmListNode::KmListNode(const T&	value)
: _pPrev	( NULL )
, _pNext	( NULL )
, _value	( value )
{
	
}

KOSMO_CORE_NAMESPACE_END

#endif