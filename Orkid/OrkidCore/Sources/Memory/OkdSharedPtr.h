//*****************************************************************************
//
//	Class:		OkdSharedPtr
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdSharedPtr_h__
#define __OrkidCore_OkdSharedPtr_h__

#include	"Root.h"

template<class T>
class OkdSharedPtr
{
public:
					OkdSharedPtr()
					: _pObject		( 0 )
					, _uiRefCount	( 0 )
					{

					}

					OkdSharedPtr( T* pObject )
					: _pObject		( pObject )
					, _uiRefCount	( 0 )
					{

					}

					OkdSharedPtr( const OkdSharedPtr& sharedPtr );
					~OkdSharedPtr();

	OkdSharedPtr&	operator=( const OkdSharedPtr& sharedPtr );

private:
	void AddRefCount()
	{
		_uiRefCount++;
	}
	
	T*				_pObject;
	uint			_uiRefCount;
};

#endif
