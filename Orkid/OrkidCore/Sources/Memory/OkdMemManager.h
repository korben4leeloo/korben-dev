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
	inline void						free( void* ptr ) const;
	inline void						freeAlign( void* ptr ) const;

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
	void* pMem = ::malloc( uiAllocSize );
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

//-----------------------------------------------------------------------------
// Name:		free
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdMemManager::free(void*	ptr) const
{
	::free( ptr );
}

//-----------------------------------------------------------------------------
// Name:		freeAlign
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdMemManager::freeAlign(void*	ptr) const
{
	_aligned_free( ptr );
}

#define	ORKID_ALIGNED_NEW( align )											\
	void* operator new(size_t size)											\
	{																		\
		return OkdMemManager::instance()->allocAlign( (uint)size, align );	\
	}																		\
																			\
	void* operator new[](size_t size)										\
	{																		\
		return OkdMemManager::instance()->allocAlign( (uint)size, align );	\
	}																		\
																			\
	void operator delete(void* ptr)											\
	{																		\
		OkdMemManager::instance()->freeAlign(ptr);							\
	}																		\
																			\
	void operator delete[](void* ptr)										\
	{																		\
		OkdMemManager::instance()->freeAlign(ptr);							\
	}

#endif
