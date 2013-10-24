//*****************************************************************************
//
//	Class:		OkdResourceHandle
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdResourceHandle_h__
#define __OrkidEngine_OkdResourceHandle_h__

#include	"Root.h"

//#include	ORKID_CORE_H(Memory/OkdSharedPtr)
//#include	ORKID_ENGINE_H(ResourceManager/OkdResourceManager)
//#include	ORKID_ENGINE_H(ResourceManager/OkdResourceId)
//#include	ORKID_ENGINE_H(OrkidEngine)

#include	ORKID_CORE_H(String/OkdString)

class OkdResourceHandle
{
friend class OkdResourceManager;
//friend class OkdResourcePtr;

public:
	//inline const OkdResourceId&	getResourceId() const;
	
private:
		 			//OkdResourceHandle( const OkdResourceId& resourceId, void* pData );
					OkdResourceHandle( void* pData, const OkdString& strResourceName );
					~OkdResourceHandle();

	inline void		addRef();
	inline uint32	removeRef();

	inline void		addLoadRef();
	inline uint32	removeLoadRef();

	//OkdResourceId	_resourceId;
	uint32			_uiRefCount;
	uint32			_uiLoadRefCount;
	void*			_pData;
	OkdString		_strResourceName;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		addRef
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void OkdResourceHandle::addRef()
{
	_uiRefCount++;
}

//-----------------------------------------------------------------------------
// Name:		removeRef
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
uint32 OkdResourceHandle::removeRef()
{
	ORKID_ASSERT( _uiRefCount > 0 );

	_uiRefCount--;
	return	( _uiRefCount );
}

//-----------------------------------------------------------------------------
// Name:		addLoadRef
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void OkdResourceHandle::addLoadRef()
{
	_uiLoadRefCount++;
}

//-----------------------------------------------------------------------------
// Name:		removeLoadRef
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
uint32 OkdResourceHandle::removeLoadRef()
{
	ORKID_ASSERT( _uiLoadRefCount > 0 );

	_uiLoadRefCount--;
	return	( _uiLoadRefCount );
}

////-----------------------------------------------------------------------------
//// Name:		getResourceId
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//const OkdResourceId& OkdResourceHandle::getResourceId() const
//{
//	return	( _resourceId );
//}

#endif