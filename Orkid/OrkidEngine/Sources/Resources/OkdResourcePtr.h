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

protected:
	//template<class U>
	//class OkdResourceRef
	//{
	//	friend class OkdResourcePtr<T, resourceType>;
	//	//template<class T, OkdResourceType resourceType> friend class OkdResourceHandler;

	//public:
	//	inline const OkdResourceKey&	getResourceKey() const;
	//	inline U*						getResource();
	//	inline const OkdString&			getResourceName() const;

	//private:
	//									OkdResourceRef( const OkdResourceKey& resourceKey, U* pResource, const OkdString& strResourceName );
	//									~OkdResourceRef();

	//	inline void						addRef();
	//	inline uint32					removeRef();

	//	OkdResourceKey					_resourceKey;
	//	uint32							_uiRefCount;
	//	uint32							_uiLoadRefCount;
	//	U*								_pResource;
	//	OkdString						_strResourceName;
	//};
	
	T*					_pResourceRef;
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
	OkdResourceManager*			pResourceManager	= OrkidEngine::instance()->getResourceManager();
	OkdAbstractResourceHandler*	pResourceHandler	= pResourceManager->getResourceHandler( resourceType );
	T*							pResourceRef		= static_cast<T*>(pResourceHandler->addResource( strResourceName ));

	if	( pResourceRef && ( pResourceRef != _pResourceRef ) )
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
		OkdResourceManager*			pResourceManager	= OrkidEngine::instance()->getResourceManager();
		OkdAbstractResourceHandler*	pResourceHandler	= pResourceManager->getResourceHandler( resourceType );
		
		if	( _pResourceRef->removeRef() == 0 )
		{
			pResourceHandler->removeResource( _pResourceRef );
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
	return	( _pResourceRef );
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

		OkdResourceDatabase*	pResourceDatabase	= OrkidEngine::instance()->getResourceDatabase();
		OkdFileStream*			pResourceFileStream	= pResourceDatabase->openResourceFileStream( resourceType, _pResourceRef->getResourceName(), OkdResourceDatabase::OpenStreamLoad );

		if	( pResourceFileStream )
		{
			_pResourceRef->read( pResourceFileStream );
			pResourceDatabase->closeResourceFileStream( &pResourceFileStream );
		}
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

		OkdResourceDatabase*	pResourceDatabase	= OrkidEngine::instance()->getResourceDatabase();
		OkdFileStream*			pResourceFileStream	= pResourceDatabase->openResourceFileStream( resourceType, _pResourceRef->getResourceName(), OkdResourceDatabase::OpenStreamSave );

		if	( pResourceFileStream )
		{
			_pResourceRef->write( pResourceFileStream );
			pResourceDatabase->closeResourceFileStream( &pResourceFileStream );
		}
	}
}

////-----------------------------------------------------------------------------
//// Name:		OkdResourceRef constructor
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T, OkdResourceType resourceType>
//template<class U>
//OkdResourcePtr<T, resourceType>::OkdResourceRef<U>::OkdResourceRef(const OkdResourceKey&	resourceKey,
//																   U*						pResource,
//																   const OkdString&			strResourceName)
//: _resourceKey		( resourceKey )
//, _pResource		( pResource )
//, _uiRefCount		( 0 )
//, _uiLoadRefCount	( 0 )
//, _strResourceName	( strResourceName )
//{
//	//_pResource = new T();
//}
//
////-----------------------------------------------------------------------------
//// Name:		OkdResourceRef destructor
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T, OkdResourceType resourceType>
//template<class U>
//OkdResourcePtr<T, resourceType>::OkdResourceRef<U>::~OkdResourceRef()
//{
//	/*if	( _pResource )
//	{
//		delete _pResource;
//	}*/
//}
//
////-----------------------------------------------------------------------------
//// Name:		getResourceKey
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T, OkdResourceType resourceType>
//template<class U>
//const OkdResourceKey&	OkdResourcePtr<T, resourceType>::OkdResourceRef<U>::getResourceKey() const
//{
//	return( _resourceKey );
//}
//
////-----------------------------------------------------------------------------
//// Name:		getResourceKey
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T, OkdResourceType resourceType>
//template<class U>
//U*	OkdResourcePtr<T, resourceType>::OkdResourceRef<U>::getResource()
//{
//	return( _pResource );
//}
//
////-----------------------------------------------------------------------------
//// Name:		getResourceName
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T, OkdResourceType resourceType>
//template<class U>
//const OkdString&	OkdResourcePtr<T, resourceType>::OkdResourceRef<U>::getResourceName() const
//{
//	return( _strResourceName );
//}
//
////-----------------------------------------------------------------------------
//// Name:		addRef
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T, OkdResourceType resourceType>
//template<class U>
//void	OkdResourcePtr<T, resourceType>::OkdResourceRef<U>::addRef()
//{
//	_uiRefCount++;
//}
//
////-----------------------------------------------------------------------------
//// Name:		removeRef
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T, OkdResourceType resourceType>
//template<class U>
//uint32	OkdResourcePtr<T, resourceType>::OkdResourceRef<U>::removeRef()
//{
//	ORKID_ASSERT( _uiRefCount > 0 );
//	_uiRefCount--;
//
//	return( _uiRefCount );
//}

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif