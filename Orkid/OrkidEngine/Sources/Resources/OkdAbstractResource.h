//*****************************************************************************
//
//	Class:		OkdAbstractResource
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdAbstractResource_h__
#define __OrkidEngine_OkdAbstractResource_h__

#include	"Root.h"

#include	ORKID_CORE_H(String/OkdString)

class OkdFileStream;

#define	ORKID_RESOURCE( ResourceType ) inline static OkdResourceType getResourceType() { return ResourceType; }

class OkdAbstractResource
{
	template<class T> friend class OkdResourcePtr;
	friend class OkdResourceManager;

public:
	inline const OkdResourceKey&	getResourceKey() const;
	inline const OkdString&			getResourceName() const;

	virtual void					read( OkdFileStream* pStream )	= 0;
	virtual void					write( OkdFileStream* pStream )	= 0;

protected:
									OkdAbstractResource();
	virtual							~OkdAbstractResource();

	inline void						addRef();
	inline uint32					removeRef();

	OkdResourceKey					_resourceKey;
	uint32							_uiRefCount;
	uint32							_uiLoadRefCount;
	OkdString						_strResourceName;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		getResourceKey
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const OkdResourceKey&	OkdAbstractResource::getResourceKey() const
{
	return( _resourceKey );
}

//-----------------------------------------------------------------------------
// Name:		getResourceName
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const OkdString&	OkdAbstractResource::getResourceName() const
{
	return( _strResourceName );
}

//-----------------------------------------------------------------------------
// Name:		addRef
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdAbstractResource::addRef()
{
	_uiRefCount++;
}

//-----------------------------------------------------------------------------
// Name:		removeRef
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
uint32	OkdAbstractResource::removeRef()
{
	ORKID_ASSERT( _uiRefCount > 0 );
	_uiRefCount--;

	return( _uiRefCount );
}

#endif