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
private:
	template<class T>
	class OkdSharedPtrRefCount
	{
	public:
				OkdSharedPtrRefCount();
				~OkdSharedPtrRefCount();

	private:
		void addRef()
		{
			_uiRefCount++;
		}

		uint			_uiRefCount;
	};

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
	
	T*						_pObject;
	OkdSharedPtrRefCount*	_pRefCount;
};

#endif
