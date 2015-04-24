//*****************************************************************************
//
//	Class:		KmResourceManager
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __KosmoCore_KmResourceManager_h__
#define __KosmoCore_KmResourceManager_h__

#include	"Root.h"

#include	<type_traits>

#include	KOSMO_CORE_H(Resources/KmResourceId)
#include	KOSMO_CORE_H(String/KmString)
#include	KOSMO_CORE_H(Containers/KmVector)

KOSMO_CORE_NAMESPACE_BEGIN

template<class U>
class KmDefaultSerializer
{
public:
	template<class...Args> static U* create( Args...args )
	{
		U* pResourceData = new U( args... );
		return( pResourceData );
	}
};

template<class T, class Serializer = KmDefaultSerializer<T>>
class KmResourceManager
{
public:
										KmResourceManager();
										~KmResourceManager();

	template<class...Args> KmResourceId	create( const KmString& sResourceName, Args...args );
	template<class...Args> KmResourceId	load( const KmString& sResourceName, Args...args );
	template<class...Args> void			save( const KmResourceId resourceId, Args...args );

	//KmResourceId						acquire( const KmString& sResourceName );
	void								release( const KmResourceId resourceId );

	const T*							getData( const KmResourceId resourceId ) const;
	T*									getData( const KmResourceId resourceId );

private:
	struct KmResourceEntry
	{
		uint32		m_nRefCount	: 23;
		uint32		m_nTag		: 8;
		uint32		m_bUsed		: 1;

		KmString	m_sName;
		T*			m_pResource;
	};

	KmVector<KmResourceEntry>			m_resourceArray;
	KmVector<KmResourceEntry*>			m_freeSlotStack;
};

//*****************************************************************************
//	Template methods declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		KmResourceManager constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, class Serializer>
KmResourceManager<T, Serializer>::KmResourceManager()
{
	
}

//-----------------------------------------------------------------------------
// Name:		KmResourceManager destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, class Serializer>
KmResourceManager<T, Serializer>::~KmResourceManager()
{
	
}

//-----------------------------------------------------------------------------
// Name:		create
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, class Serializer>
template<class...CreateArgs>
KmResourceId KmResourceManager<T, Serializer>::create(const KmString& sResourceName, CreateArgs...args)
{
	KmResourceEntry resourceEntry;

	memset( &resourceEntry, 0, sizeof(resourceEntry) );

	resourceEntry.m_nRefCount	= 1;
	resourceEntry.m_nTag		= 1;
	resourceEntry.m_bUsed		= 1;

	m_resourceArray.add( resourceEntry );

	KmResourceId resourdeId;

	resourdeId.m_nIndex = 1;
	resourdeId.m_nTag	= 1;

	T* pResourceData = Serializer::create( args... );

	return	( resourdeId );
}

KOSMO_CORE_NAMESPACE_END

#endif