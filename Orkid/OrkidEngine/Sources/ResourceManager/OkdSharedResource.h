//*****************************************************************************
//
//	Class:		OkdSharedResource
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdSharedResource_h__
#define __OrkidEngine_OkdSharedResource_h__

#include	"Root.h"

//#include	ORKID_CORE_H(Memory/OkdSharedPtr)
#include	ORKID_CORE_H(String/OkdString)

typedef OrkidErrorCode (*pfnLoadResource)( void* pData, void* pResult );

template<pfnLoadResource TLoadFunc>
class OkdSharedResource
{
public:
	enum ResourceLocation
	{
		RES_LOC_MEMORY,
		RES_LOC_FILE
	};

						OkdSharedResource( const OkdString& strResourceName, const OkdString& strResourceLocName, const ResourceLocation eResourceLoc );
	virtual				~OkdSharedResource();

	void				load( void* pData, void* pResult );
	void				unload();

private:
	OkdString			_strResourceName;
	OkdString			_strResourceLocName;
	ResourceLocation	_eResourceLoc;
	uint				_uiLoadRefCount;
	//OkdSharedPtr<T>		_resourcePtr;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		OkdSharedResource constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<pfnLoadResource TLoadFunc>
OkdSharedResource<TLoadFunc>::OkdSharedResource(const OkdString&		strResourceName, 
												const OkdString&		strResourceLocName,
												const ResourceLocation	eResourceLoc)
: _strResourceName		( strResourceName )
, _strResourceLocName	( strResourceLocName )
, _eResourceLoc			( eResourceLoc )
, _uiLoadRefCount		( 0 )
{

}

//-----------------------------------------------------------------------------
// Name:		OkdSharedResource destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<pfnLoadResource TLoadFunc>
OkdSharedResource<TLoadFunc>::~OkdSharedResource()
{

}

//-----------------------------------------------------------------------------
// Name:		load
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<pfnLoadResource TLoadFunc>
void	OkdSharedResource<TLoadFunc>::load(void*	pData, 
										   void*	pResult )
{
	OrkidErrorCode eResult = TLoadFunc( pData, pResult );
	_uiLoadRefCount++;
}

//-----------------------------------------------------------------------------
// Name:		unload
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<pfnLoadResource TLoadFunc>
void	OkdSharedResource<TLoadFunc>::unload()
{
	ORKID_ASSERT( _uiLoadRefCount > 0 );

	if	( _uiLoadRefCount > 0 )
	{
		_uiLoadRefCount--;
	}
}

#endif