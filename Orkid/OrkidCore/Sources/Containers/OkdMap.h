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
	inline void						clear();

	inline void						add( const Key& key, const Value& value );
	inline uint32					remove( const Key& key );

	inline bool						find( const Key& key, Value* pReturnValue );
	inline void						clearPointers();

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
void	OkdMap<Key, Value>::add(const Key&		key, 
								const Value&	value)
{
	const_iterator itExist = _map.find( key );

	if	( itExist == _map.end() )
	{
		_map[key] = value;
	}
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
// Name:		find
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<typename Key, typename Value>
bool	OkdMap<Key, Value>::find(const Key&	key, 
								 Value*		pReturnValue)
{
	iterator itExist = _map.find( key );

	if	( itExist != _map.end() )
	{
		*pReturnValue = itExist->second;
		return	( true );
	}

	return	( false );
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