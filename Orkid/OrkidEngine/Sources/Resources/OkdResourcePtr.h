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

#include	ORKID_ENGINE_H(OrkidEngine)
#include	ORKID_ENGINE_H(Resources/OkdResourceRef)
#include	ORKID_ENGINE_H(Resources/Handlers/OkdResourceHandler)
#include	ORKID_ENGINE_H(Resources/OkdResourceManager)
#include	ORKID_CORE_H(String/OkdCrc32)

template<class T, OkdResourceType resourceType>
class OkdResourcePtr
{
public:
						OkdResourcePtr();
						OkdResourcePtr( const OkdResourcePtr& resourcePtr );
						~OkdResourcePtr();

	OkdResourcePtr&		operator=( const OkdResourcePtr& resourcePtr );

	void				bind( const OkdString& strResourceName );
	void				unbind();

	void				load();
	void				save();

	T*					getResource();
	const OkdString&	getResourceName() const;

private:
	typedef OkdResourceHandler<T, resourceType>	OkdTypeResourceHandler;
	
	OkdResourceRef<T>*	_pResourceRef;
};

//-----------------------------------------------------------------------------
// Name:		OkdResourcePtr constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OkdResourceType resourceType>
OkdResourcePtr<T, resourceType>::OkdResourcePtr()
: _pResourceRef( 0 )
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdResourcePtr copy constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OkdResourceType resourceType>
OkdResourcePtr<T, resourceType>::OkdResourcePtr(const OkdResourcePtr&	resourcePtr)
{
	_pResourceRef = resourcePtr._pResourceRef;

	if	( _pResourceRef )
	{
		_pResourceRef->addRef();
	}
}

//-----------------------------------------------------------------------------
// Name:		OkdResourcePtr destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OkdResourceType resourceType>
OkdResourcePtr<T, resourceType>::~OkdResourcePtr()
{
	unbind();
}

//-----------------------------------------------------------------------------
// Name:		OkdResourcePtr copy constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OkdResourceType resourceType>
OkdResourcePtr<T, resourceType>& OkdResourcePtr<T, resourceType>::operator=(const OkdResourcePtr&	resourcePtr)
{
	unbind();

	_pResourceRef = resourcePtr._pResourceRef;

	if	( _pResourceRef )
	{
		_pResourceRef->addRef();
	}

	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		bind
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OkdResourceType resourceType>
void OkdResourcePtr<T, resourceType>::bind(const OkdString&	strResourceName)
{
	OkdResourceManager*		pResourceManager	= OrkidEngine::instance()->getResourceManager();
	OkdTypeResourceHandler*	pResourceHandler	= (OkdTypeResourceHandler*)pResourceManager->getResourceHandler( resourceType );
	OkdResourceRef<T>*		pResourceRef		= pResourceHandler->addResource( strResourceName );

	if	( pResourceRef && 
		( _pResourceRef != pResourceRef ) )
	{
		unbind();

		_pResourceRef = pResourceRef;
		_pResourceRef->addRef();
	}
}

//-----------------------------------------------------------------------------
// Name:		unbind
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OkdResourceType resourceType>
void OkdResourcePtr<T, resourceType>::unbind()
{
	if	( _pResourceRef )
	{
		OkdResourceManager*		pResourceManager	= OrkidEngine::instance()->getResourceManager();
		OkdTypeResourceHandler*	pResourceHandler	= (OkdTypeResourceHandler*)pResourceManager->getResourceHandler( resourceType );
		
		if	( _pResourceRef->removeRef() == 0 )
		{
			pResourceHandler->removeResource( _pResourceRef->getResourceKey() );
			delete _pResourceRef;
		}
		
		_pResourceRef = 0;
	}
}

//-----------------------------------------------------------------------------
// Name:		getResource
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OkdResourceType resourceType>
T*	OkdResourcePtr<T, resourceType>::getResource()
{
	return	( _pResourceRef->getResource() );
}

//-----------------------------------------------------------------------------
// Name:		getResourceName
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OkdResourceType resourceType>
const OkdString&	OkdResourcePtr<T, resourceType>::getResourceName() const
{
	return	( _pResourceRef->getResourceName() );
}

//-----------------------------------------------------------------------------
// Name:		load
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OkdResourceType resourceType>
void OkdResourcePtr<T, resourceType>::load()
{
	ORKID_ASSERT( _pResourceRef );

	if	( _pResourceRef )
	{
		const OkdString& strResourceName = _pResourceRef->getResourceName();

		if	( strResourceName.isEmpty() )
		{
			ORKID_BREAK();
			return;
		}

		OkdResourceManager*		pResourceManager	= OrkidEngine::instance()->getResourceManager();
		OkdTypeResourceHandler*	pResourceHandler	= (OkdTypeResourceHandler*)pResourceManager->getResourceHandler( resourceType );

		pResourceHandler->loadResource( _pResourceRef );
	}
}

//-----------------------------------------------------------------------------
// Name:		save
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OkdResourceType resourceType>
void OkdResourcePtr<T, resourceType>::save()
{
	ORKID_ASSERT( _pResourceRef );

	if	( _pResourceRef )
	{
		const OkdString& strResourceName = _pResourceRef->getResourceName();

		if	( strResourceName.isEmpty() )
		{
			ORKID_BREAK();
			return;
		}

		OkdResourceManager*		pResourceManager	= OrkidEngine::instance()->getResourceManager();
		OkdTypeResourceHandler*	pResourceHandler	= (OkdTypeResourceHandler*)pResourceManager->getResourceHandler( resourceType );

		pResourceHandler->saveResource( _pResourceRef );
	}
}

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif