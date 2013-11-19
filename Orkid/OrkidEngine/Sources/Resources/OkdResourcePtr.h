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
#include	ORKID_ENGINE_H(Resources/Handlers/OkdResourceHandler)
#include	ORKID_ENGINE_H(Resources/OkdResourceManager)
#include	ORKID_CORE_H(String/OkdCrc32)

template<class T, OrkidResourceType resourceType>
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

private:
	typedef OkdResourceHandler<T, resourceType>	OkdTypeResourceHandler;
	
	OkdResourceRef<T>*	_pResourceRef;
};

//-----------------------------------------------------------------------------
// Name:		OkdResourcePtr constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OrkidResourceType resourceType>
OkdResourcePtr<T, resourceType>::OkdResourcePtr()
: _pResourceRef( 0 )
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdResourcePtr copy constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OrkidResourceType resourceType>
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
template<class T, OrkidResourceType resourceType>
OkdResourcePtr<T, resourceType>::~OkdResourcePtr()
{
	unbind();
}

//-----------------------------------------------------------------------------
// Name:		OkdResourcePtr copy constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OrkidResourceType resourceType>
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
template<class T, OrkidResourceType resourceType>
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
template<class T, OrkidResourceType resourceType>
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
template<class T, OrkidResourceType resourceType>
T* OkdResourcePtr<T, resourceType>::getResource()
{
	return	( _pResourceRef->getResource() );
}

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

class OkdMesh;
class OkdScene;

typedef OkdResourcePtr<OkdMesh, OrkidMesh> OkdMeshPtr;
typedef OkdResourcePtr<OkdScene, OrkidScene> OkdScenePtr;

#endif