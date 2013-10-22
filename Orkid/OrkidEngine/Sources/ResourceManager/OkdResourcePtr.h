//*****************************************************************************
//
//	Class:		OkdResourcePtr
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdResourcePtr_h__
#define __OrkidEngine_OkdResourcePtr_h__

#include	"Root.h"

//#include	ORKID_CORE_H(Memory/OkdSharedPtr)
//#include	ORKID_ENGINE_H(ResourceManager/OkdResourceManager)
//#include	ORKID_ENGINE_H(ResourceManager/OkdResourceId)
//#include	ORKID_ENGINE_H(OrkidEngine)

class OkdResourceHandle;

class OkdResourcePtr
{
public:
	friend class OkdResourceManager;

									OkdResourcePtr( const OkdResourcePtr& resourcePtr );
									~OkdResourcePtr();

	/*inline OkdResourceHandle*		getResourceHandle();
	inline const OkdResourceHandle*	getResourceHandle() const;
	inline uint						getRefCount() const;

	inline void						load();
	inline void						unload();
	inline uint						getLoadRefCount() const;*/

	OkdResourcePtr&					operator=( const OkdResourcePtr& resourcePtr );

protected:
									OkdResourcePtr( OkdResourceHandle* pResourceHandle );

		void						destroy();
	
	OkdResourceHandle*				_pResourceHandle;
	/*OkdSharedPtrRef*				_pRefCount;
	OkdSharedPtrRef*				_pLoadRefCount;
	bool							_bHasLoadRef;*/
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

////-----------------------------------------------------------------------------
//// Name:		getResourceHandle
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//OkdResourceHandle*	OkdResourcePtr::getResourceHandle()
//{
//	return	( _pResourceHandle );
//}
//
////-----------------------------------------------------------------------------
//// Name:		getResourceHandle
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//const OkdResourceHandle*	OkdResourcePtr::getResourceHandle() const
//{
//	return	( _pResourceHandle );
//}
//
////-----------------------------------------------------------------------------
//// Name:		getRefCount
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//uint	OkdResourcePtr::getRefCount() const
//{
//	return	( _pRefCount->getRefCount() );
//}
//
////-----------------------------------------------------------------------------
//// Name:		getLoadRefCount
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//uint	OkdResourcePtr::getLoadRefCount() const
//{
//	return	( _pLoadRefCount->getRefCount() );
//}

#endif