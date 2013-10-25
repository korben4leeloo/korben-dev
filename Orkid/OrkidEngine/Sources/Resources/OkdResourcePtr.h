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

//template<class T, OrkidResourceType resourceType> class OkdResourceHandler;

#define	DECLARE_RESOURCE_PTR( ClassType, ResourceTypeEnum ) class ClassType; typedef OkdResourcePtr<ClassType, ResourceTypeEnum> ClassType##Ptr;

template<class T, OrkidResourceType resourceType>
class OkdResourcePtr
{
public:
						OkdResourcePtr();
						OkdResourcePtr( const OkdResourcePtr& resourcePtr );
						~OkdResourcePtr();

	OkdResourcePtr&		operator=( const OkdResourcePtr& resourcePtr );

	void				create( const OkdString& strResourceName );

private:
	typedef OkdResourceHandler<T, resourceType>	OkdTypeResourceHandler;

						//OkdResourcePtr( OkdResourceRef<T>* pResourceRef );
	
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

////-----------------------------------------------------------------------------
//// Name:		OkdResourcePtr constructor
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T>
//OkdResourcePtr<T>::OkdResourcePtr(OkdResourceRef<T>* pResourceRef)
//: _pResourceRef( pResourceRef )
//{
//	_pResourceRef->addRef();
//}

//-----------------------------------------------------------------------------
// Name:		OkdResourcePtr copy constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OrkidResourceType resourceType>
OkdResourcePtr<T, resourceType>::OkdResourcePtr(const OkdResourcePtr&	resourcePtr)
: _pResourceRef( resourcePtr._pResourceRef )
{
	_pResourceRef->addRef();
}

//-----------------------------------------------------------------------------
// Name:		OkdResourcePtr destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OrkidResourceType resourceType>
OkdResourcePtr<T, resourceType>::~OkdResourcePtr()
{
	if	( _pResourceRef->removeRef() == 0 )
	{
		OkdResourceManager*		pResourceManager	= OrkidEngine::instance()->getResourceManager();
		OkdTypeResourceHandler*	pResourceHandler	= (OkdTypeResourceHandler*)pResourceManager->getResourceHandler( resourceType );
		bool					bResult				= pResourceHandler->deleteResourceRef( _pResourceRef );

		ORKID_ASSERT( bResult );
	}
}

//-----------------------------------------------------------------------------
// Name:		create
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OrkidResourceType resourceType>
void OkdResourcePtr<T, resourceType>::create(const OkdString&	strResourceName)
{
	if	( _pResourceRef )
	{
		_pResourceRef->removeRef();
	}

	OkdResourceManager*		pResourceManager	= OrkidEngine::instance()->getResourceManager();
	OkdTypeResourceHandler*	pResourceHandler	= (OkdTypeResourceHandler*)pResourceManager->getResourceHandler( resourceType );

	_pResourceRef = pResourceHandler->createResourceRef( strResourceName );

	if	( _pResourceRef )
	{
		_pResourceRef->addRef();
	}
}

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

DECLARE_RESOURCE_PTR( OkdMesh, OrkidMesh )
DECLARE_RESOURCE_PTR( OkdScene, OrkidScene )

#endif