//*****************************************************************************
//
//	Class:		QmHierarchicalGraph
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __QUANTUM_CORE_HIERARCHICAL_GRAPH_H__
#define __QUANTUM_CORE_HIERARCHICAL_GRAPH_H__

//#include QUANTUM_CORE_H(Containers/QmList)

template<class T>
class QmListEx
{
public:
	struct QmListExNode
	{
		QmListExNode() {}

		QmListExNode*	_pPrev;
		QmListExNode*	_pNext;
	};

	QmListEx() { _pHead = new T(); }
	~QmListEx() {}

	void		pushBack( T* pListNode );
	void		pushFront( T* pListNode );
	//void		insertAfter( T* pAfterListNode, const T& value );
	//void		insertBefore( const iterator& position, const T& value );
	void		remove( T* pListNode );

	inline T*	begin() { return static_cast<T*>(_pHead); }
	inline T*	end();

private:
	QmListExNode *		_pHead;
	QmListExNode*		_pLast;
	uint32	_uiSize;
};

template<class T>
class QmHierarchicalGraph
{
private:
	

public:
	class NODE
	{
	public:

	private:
		NODE( const T& value );
		~NODE();

		T				_data;
		NODE*			_pParent = nullptr;
		QmList<NODE*>	_lChildren;
	};

			QmHierarchicalGraph( const T& rootValue );
			~QmHierarchicalGraph();


private:

	NODE*	_pRoot;
};

//*****************************************************************************
//	Template methods declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		QmHierarchicalGraph constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
QmHierarchicalGraph<T>::QmHierarchicalGraph( const T& rootValue )
{
	//_pRoot = new NODE( rootValue );
}

//-----------------------------------------------------------------------------
// Name:		QmHierarchicalGraph destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
QmHierarchicalGraph<T>::~QmHierarchicalGraph()
{
	//delete _pRoot;
}

//-----------------------------------------------------------------------------
// Name:		QmHierarchicalGraph::NODE constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
QmHierarchicalGraph<T>::NODE::NODE( const T& value )
: _data( value )
{
	
}

//-----------------------------------------------------------------------------
// Name:		QmHierarchicalGraph::NODE destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
QmHierarchicalGraph<T>::NODE::~NODE()
{
	if ( _pParent )
	{
		//_pParent->_lChildren.remove( this );
	}
}

#endif