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
class OkdMap: public std::unordered_map<Key, Value>
{

};

#endif