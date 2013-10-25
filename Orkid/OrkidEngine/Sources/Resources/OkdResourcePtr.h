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

#include	ORKID_ENGINE_H(Resources/OkdResourceRef)

template<class T>
class OkdResourcePtr
{
	template<class T, OrkidResourceType ResourceType> friend class OkdBaseResourceManager;

public:
						OkdResourcePtr( const OkdResourcePtr<T>& resourcePtr );
						~OkdResourcePtr();

	OkdResourcePtr&		operator=( const OkdResourcePtr& resourcePtr );

private:
						OkdResourcePtr( OkdResourceRef<T>* pResourceRef );
	
	OkdResourceRef<T>*	_pResourceRef;
};

//-----------------------------------------------------------------------------
// Name:		OkdResourcePtr constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
OkdResourcePtr<T>::OkdResourcePtr(OkdResourceRef<T>* pResourceRef)
: _pResourceRef( pResourceRef )
{
	_pResourceRef->addRef();
}

//-----------------------------------------------------------------------------
// Name:		OkdResourcePtr copy constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
OkdResourcePtr<T>::OkdResourcePtr(const OkdResourcePtr<T>&	resourcePtr)
: _pResourceRef( resourcePtr._pResourceRef )
{
	pResourceRef->addRef();
}

//-----------------------------------------------------------------------------
// Name:		OkdResourcePtr destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
OkdResourcePtr<T>::~OkdResourcePtr()
{
	if	( _pResourceRef->removeRef() == 0 )
	{
		delete _pResourceRef;
	}
}

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif