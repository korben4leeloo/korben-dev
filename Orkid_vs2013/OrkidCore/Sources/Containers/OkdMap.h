//*****************************************************************************
//
//	Class:		OkdMap
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdMap_h__
#define __OrkidCore_OkdMap_h__

#include	<unordered_map>

template<typename Key, typename Value>
class OkdMap
{
public:
	typedef typename std::unordered_map<Key, Value>::iterator		iterator;
	typedef typename std::unordered_map<Key, Value>::const_iterator	const_iterator;

	inline iterator					begin();
	inline iterator					end();
	inline const_iterator			end() const;
	inline void						clear();

	inline iterator					add( const Key& key, const Value& value );
	inline uint32					remove( const Key& key );
	inline void						remove( const_iterator& it );

	inline const_iterator			find( const Key& key ) const;
	inline bool						contains( const Key& key ) const;
	inline void						clearPointers();

	inline Value&					operator[]( const Key& key );

private:
	std::unordered_map<Key, Value>	_map;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		begin
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<typename Key, typename Value>
typename OkdMap<Key, Value>::iterator	OkdMap<Key, Value>::begin()
{
	return	( _map.begin() );
}

//-----------------------------------------------------------------------------
// Name:		end
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<typename Key, typename Value>
typename OkdMap<Key, Value>::iterator	OkdMap<Key, Value>::end()
{
	return	( _map.end() );
}

//-----------------------------------------------------------------------------
// Name:		end
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<typename Key, typename Value>
typename OkdMap<Key, Value>::const_iterator	OkdMap<Key, Value>::end() const
{
	return	( _map.end() );
}

//-----------------------------------------------------------------------------
// Name:		clear
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<typename Key, typename Value>
void	OkdMap<Key, Value>::clear()
{
	_map.clear();
}

//-----------------------------------------------------------------------------
// Name:		add
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<typename Key, typename Value>
typename OkdMap<Key, Value>::iterator	OkdMap<Key, Value>::add(const Key&		key, 
																const Value&	value)
{
	//std::pair<iterator, bool> itPair = _map.insert( std::make_pair<Key, Value>( key, value ) );
	std::pair<iterator, bool> itPair = _map.insert({ key, value });
	return	( itPair.first );
}

//-----------------------------------------------------------------------------
// Name:		remove
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<typename Key, typename Value>
uint32	OkdMap<Key, Value>::remove(const Key&	key)
{
	uint32 uiCount = _map.erase( key );
	return	( uiCount );
}

//-----------------------------------------------------------------------------
// Name:		remove
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<typename Key, typename Value>
void	OkdMap<Key, Value>::remove(const_iterator&	it)
{
	_map.erase( it );
}

//-----------------------------------------------------------------------------
// Name:		operator[]
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<typename Key, typename Value>
Value&	OkdMap<Key, Value>::operator[](const Key&	key)
{
	iterator itExist = _map.find( key );
	ORKID_ASSERT( itExist != _map.end() );

	return	( itExist->second );
}

//-----------------------------------------------------------------------------
// Name:		find
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<typename Key, typename Value>
typename OkdMap<Key, Value>::const_iterator	OkdMap<Key, Value>::find(const Key&	key) const
{
	const_iterator itExist = _map.find( key );
	return	( itExist );
}

//-----------------------------------------------------------------------------
// Name:		contains
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<typename Key, typename Value>
bool	OkdMap<Key, Value>::contains(const Key&	key) const
{
	const_iterator itExist = find( key );
	return	( itExist != _map.end() );
}

//-----------------------------------------------------------------------------
// Name:		clearPointers
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<typename Key, typename Value>
void	OkdMap<Key, Value>::clearPointers()
{
	iterator it = _map.begin();

	while	( it != _map.end() )
	{
		delete it->second;
		it++;
	}
}

#endif