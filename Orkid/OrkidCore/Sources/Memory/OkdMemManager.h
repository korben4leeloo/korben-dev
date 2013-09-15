//*****************************************************************************
//
//	Class:		OkdMemManager
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdMemManager_h__
#define __OrkidCore_OkdMemManager_h__

#include	"Root.h"
#include	<malloc.h>

class OkdMemManager
{
public:
	inline static void				create();
	inline static void				destroy();
	inline static OkdMemManager*	instance();

	inline void*					alloc( const uint uiAllocSize ) const;
	inline void*					allocAlign( const uint uiAllocSize, const uint uiAlign ) const;

private:
									OkdMemManager();
									~OkdMemManager();

	static OkdMemManager*			_pInstance;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		create
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdMemManager::create()
{
	destroy();
	_pInstance = new OkdMemManager();
}

//-----------------------------------------------------------------------------
// Name:		destroy
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdMemManager::destroy()
{
	if	( _pInstance )
	{
		delete _pInstance;
		_pInstance = 0;
	}
}

//-----------------------------------------------------------------------------
// Name:		instance
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdMemManager*	OkdMemManager::instance()
{
	ORKID_ASSERT( _pInstance );
	return	( _pInstance );
}

//-----------------------------------------------------------------------------
// Name:		alloc
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void*	OkdMemManager::alloc(const uint		uiAllocSize) const
{
	void* pMem = malloc( uiAllocSize );
	return	( pMem );
}

//-----------------------------------------------------------------------------
// Name:		allocAlign
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void*	OkdMemManager::allocAlign(const uint	uiAllocSize, 
								  const uint	uiAlign) const
{
	void* pMem = _aligned_malloc( uiAllocSize, uiAlign );
	return	( pMem );
}

#endif
