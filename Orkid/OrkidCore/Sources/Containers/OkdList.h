//*****************************************************************************
//
//	Class:		OkdList
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdList_h__
#define __OrkidCore_OkdList_h__

#include <list>

template<typename T>
class OkdList
{
public:
	typedef typename std::list<T>::iterator			iterator;
	typedef typename std::list<T>::const_iterator	const_iterator;

							OkdList();
							~OkdList();

	inline void				add( T& t );
	inline void				remove( T& t );
	inline uint32			size() const;

	inline iterator			begin();
	inline const_iterator	begin() const;

	inline iterator			end();
	inline const_iterator	end() const;

private:
	std::list<T>			_list;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		OkdList constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<typename T>
OkdList<T>::OkdList()
{

}

//-----------------------------------------------------------------------------
// Name:		OkdList destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<typename T>
OkdList<T>::~OkdList()
{

}

//-----------------------------------------------------------------------------
// Name:		add
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<typename T>
void	OkdList<T>::add( T& t )
{
	_list.push_back( t );
}

//-----------------------------------------------------------------------------
// Name:		remove
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<typename T>
void	OkdList<T>::remove( T& t )
{
	_list.remove( t );
}

//-----------------------------------------------------------------------------
// Name:		size
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<typename T>
uint32	OkdList<T>::size() const
{
	return	( _list.size() );
}

//-----------------------------------------------------------------------------
// Name:		begin
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<typename T>
typename OkdList<T>::iterator	OkdList<T>::begin()
{
	return	( _list.begin() );
}

//-----------------------------------------------------------------------------
// Name:		begin
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<typename T>
typename OkdList<T>::const_iterator	OkdList<T>::begin() const
{
	return	( _list.begin() );
}

//-----------------------------------------------------------------------------
// Name:		end
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<typename T>
typename OkdList<T>::iterator	OkdList<T>::end()
{
	return	( _list.end() );
}

//-----------------------------------------------------------------------------
// Name:		end
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<typename T>
typename OkdList<T>::const_iterator	OkdList<T>::end() const
{
	return	( _list.end() );
}

#endif
