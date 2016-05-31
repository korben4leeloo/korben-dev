//*****************************************************************************
//
//	Class:		OkdVector
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdVector_h__
#define __OrkidCore_OkdVector_h__

#include <vector>

template<typename T>
class OkdVector
{
public:
					OkdVector();
					~OkdVector();

	inline void		add( T& t );
	inline void		clear();
	inline uint		size() const;
	inline const T&	operator[]( uint index ) const;

private:
	std::vector<T>	_vec;
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
OkdVector<T>::OkdVector()
{

}

//-----------------------------------------------------------------------------
// Name:		OkdList destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<typename T>
OkdVector<T>::~OkdVector()
{

}

//-----------------------------------------------------------------------------
// Name:		add
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<typename T>
void	OkdVector<T>::add( T& t )
{
	_vec.push_back( t );
}

//-----------------------------------------------------------------------------
// Name:		clear
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<typename T>
void	OkdVector<T>::clear()
{
	_vec.clear();
}

//-----------------------------------------------------------------------------
// Name:		size
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<typename T>
uint	OkdVector<T>::size() const
{
	return	( _vec.size() );
}

//-----------------------------------------------------------------------------
// Name:		size
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<typename T>
const T&	OkdVector<T>::operator[](uint	index) const
{
	return	( _vec[index] );
}

#endif