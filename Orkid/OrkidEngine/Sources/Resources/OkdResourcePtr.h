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

template<class T, OrkidResourceType resourceType>
class OkdResourcePtr
{
public:
						OkdResourcePtr();
						OkdResourcePtr( const OkdResourcePtr& resourcePtr );
						~OkdResourcePtr();

	OkdResourcePtr&		operator=( const OkdResourcePtr& resourcePtr );

	void				create( const OkdString& strResourceName );
	void				bind( const OkdString& strResourceName );
	void				unbind();
	void				load();
	void				save();

private:
	typedef OkdResourceHandler<T, resourceType>	OkdTypeResourceHandler;

	void				bind( const OkdResourceKey& resourceKey );
	
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
	OkdResourceManager*		pResourceManager	= OrkidEngine::instance()->getResourceManager();
	OkdTypeResourceHandler*	pResourceHandler	= (OkdTypeResourceHandler*)pResourceManager->getResourceHandler( resourceType );

	_pResourceRef = pResourceHandler->bindResource( resourcePtr._pResourceRef );
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

	OkdResourceManager*		pResourceManager	= OrkidEngine::instance()->getResourceManager();
	OkdTypeResourceHandler*	pResourceHandler	= (OkdTypeResourceHandler*)pResourceManager->getResourceHandler( resourceType );

	_pResourceRef = pResourceHandler->bindResource( resourcePtr._pResourceRef );

	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		create
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OrkidResourceType resourceType>
void OkdResourcePtr<T, resourceType>::create(const OkdString&	strResourceName)
{
	unbind();

	OkdResourceManager*		pResourceManager	= OrkidEngine::instance()->getResourceManager();
	OkdTypeResourceHandler*	pResourceHandler	= (OkdTypeResourceHandler*)pResourceManager->getResourceHandler( resourceType );

	_pResourceRef = pResourceHandler->createResource( strResourceName );
}

//-----------------------------------------------------------------------------
// Name:		bind
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OrkidResourceType resourceType>
void OkdResourcePtr<T, resourceType>::bind(const OkdString&	strResourceName)
{
	unbind();

	OkdResourceManager*		pResourceManager	= OrkidEngine::instance()->getResourceManager();
	OkdTypeResourceHandler*	pResourceHandler	= (OkdTypeResourceHandler*)pResourceManager->getResourceHandler( resourceType );

	_pResourceRef = pResourceHandler->bindResource( strResourceName );
}

//-----------------------------------------------------------------------------
// Name:		bind
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OrkidResourceType resourceType>
void OkdResourcePtr<T, resourceType>::bind(const OkdResourceKey&	resourceKey)
{
	unbind();

	OkdResourceManager*		pResourceManager	= OrkidEngine::instance()->getResourceManager();
	OkdTypeResourceHandler*	pResourceHandler	= (OkdTypeResourceHandler*)pResourceManager->getResourceHandler( resourceType );

	_pResourceRef = pResourceHandler->bindResource( strResourceName );
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
		
		_pResourceRef = pResourceHandler->unbindResource( _pResourceRef );
	}
}

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

class OkdMesh;
class OkdScene;

typedef OkdResourcePtr<OkdMesh, OrkidMesh> OkdMeshPtr;
typedef OkdResourcePtr<OkdScene, OrkidScene> OkdScenePtr;

#endif