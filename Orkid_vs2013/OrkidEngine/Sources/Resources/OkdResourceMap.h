//*****************************************************************************
//
//	Class:		OkdResourceMap
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdResourceMap_h__
#define __OrkidEngine_OkdResourceMap_h__

#include	"Root.h"

#include	ORKID_CORE_H(Containers/OkdMap)
#include	ORKID_ENGINE_H(Resources/Allocators/OkdResourceAllocator)
#include	ORKID_ENGINE_H(Resources/Allocators/OkdResourceAllocator)

template<class T>
class OkdResourceMap: public OkdMap<OkdResourceKey, T*>
{
public:
								OkdResourceMap();

	T*							allocate();
	inline void					setAllocator( pfnOkdResourceAllocator<T> fnResourceAllocator );

	T*							addResource( const OkdString& strResourceName );
	bool						removeResource( const OkdResourceKey& resourceKey );

protected:
	pfnOkdResourceAllocator<T>	_fnAllocator;
};

template<class T>
class OkdDefaultResourceMap: public OkdResourceMap<T>
{
public:
	OkdDefaultResourceMap();
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		OkdResourceMap constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
OkdResourceMap<T>::OkdResourceMap()
: _fnAllocator( 0 )
{

}

//-----------------------------------------------------------------------------
// Name:		allocate
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
T*	OkdResourceMap<T>::allocate()
{
	if	( _fnAllocator )
	{
		return	( _fnAllocator() );
	}

	return	( 0 );
}

//-----------------------------------------------------------------------------
// Name:		setAllocator
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void	OkdResourceMap<T>::setAllocator(pfnOkdResourceAllocator<T>	fnResourceAllocator)
{
	_fnAllocator = fnResourceAllocator;
}

//-----------------------------------------------------------------------------
// Name:		addResource
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
T*	OkdResourceMap<T>::addResource(const OkdString&	strResourceName)
{
	OkdResourceKey	resourceKey	= OkdCrc32::getCrc32( strResourceName );
	iterator		itResource	= add( resourceKey, 0 );

	if	( itResource->second == 0 )
	{
		T* pResource = allocate();

		pResource->_resourceKey		= resourceKey;
		pResource->_strResourceName	= strResourceName;

		itResource->second = pResource;
	}

	return	( itResource->second );
}

//-----------------------------------------------------------------------------
// Name:		removeResource
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
bool	OkdResourceMap<T>::removeResource(const OkdResourceKey& resourceKey)
{
	const_iterator	itResource	= find( resourceKey );
	T*				pResource	= (*itResource).second;
	bool			bValid		= ( itResource != end() );

	ORKID_ASSERT( bValid );

	delete pResource;
	remove( resourceKey );

	return	( bValid );
}

//-----------------------------------------------------------------------------
// Name:		OkdDefaultResourceMap constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
OkdDefaultResourceMap<T>::OkdDefaultResourceMap()
{
	_fnAllocator = []()
	{
		return	( new T() );
	};
}

#endif
