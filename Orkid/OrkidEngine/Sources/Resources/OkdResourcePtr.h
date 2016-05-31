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
#include	ORKID_ENGINE_H(Resources/OkdResourceManager)
#include	ORKID_ENGINE_H(Resources/OkdResourceDatabase)

template<class T>
class OkdResourcePtr
{
	friend class OkdResourceManager;

public:
						OkdResourcePtr();
						OkdResourcePtr( const OkdResourcePtr& resourcePtr );
						~OkdResourcePtr();

	OkdResourcePtr&		operator=( const OkdResourcePtr& resourcePtr );

	//void				bind( const OkdString& strResourceName );
	//void				unbind();
	void				release();

	void				load();
	void				save();

	T*					getResource();
	const OkdString&	getResourceName() const;

protected:
						OkdResourcePtr( T* pResource );

	T*					_pResource;
};

//-----------------------------------------------------------------------------
// Name:		OkdResourcePtr constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
OkdResourcePtr<T>::OkdResourcePtr()
: _pResource( 0 )
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdResourcePtr copy constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
OkdResourcePtr<T>::OkdResourcePtr(const OkdResourcePtr&	resourcePtr)
{
	_pResource = resourcePtr._pResource;

	if	( _pResource )
	{
		_pResource->addRef();
	}
}

//-----------------------------------------------------------------------------
// Name:		OkdResourcePtr constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
OkdResourcePtr<T>::OkdResourcePtr(T*	pResource)
{
	_pResource = pResource;

	if	( _pResource )
	{
		_pResource->addRef();
	}
}

//-----------------------------------------------------------------------------
// Name:		OkdResourcePtr destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
OkdResourcePtr<T>::~OkdResourcePtr()
{
	//unbind();
	release();
}

//-----------------------------------------------------------------------------
// Name:		operator=
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
OkdResourcePtr<T>& OkdResourcePtr<T>::operator=(const OkdResourcePtr&	resourcePtr)
{
	//unbind();
	release();

	_pResource = resourcePtr._pResource;

	if	( _pResource )
	{
		_pResource->addRef();
	}

	return	( *this );
}

////-----------------------------------------------------------------------------
//// Name:		bind
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T>
//void OkdResourcePtr<T>::bind(const OkdString&	strResourceName)
//{
//	OkdResourceManager*			pResourceManager = OrkidEngine::instance()->getResourceManager();
//	OkdAbstractResourceHandler*	pResourceHandler = pResourceManager->getResourceHandler( T::getResourceType() );
//
//	ORKID_ASSERT( pResourceHandler );
//
//	if	( pResourceHandler )
//	{
//		T* pResource = static_cast<T*>(pResourceHandler->addResource( strResourceName ));
//
//		if	( pResource && ( pResource != _pResource ) )
//		{
//			unbind();
//
//			_pResource = pResource;
//			_pResource->addRef();
//		}
//	}
//}
//
////-----------------------------------------------------------------------------
//// Name:		unbind
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T>
//void OkdResourcePtr<T>::unbind()
//{
//	if	( _pResource )
//	{
//		OkdResourceManager*			pResourceManager	= OrkidEngine::instance()->getResourceManager();
//		OkdAbstractResourceHandler*	pResourceHandler	= pResourceManager->getResourceHandler( T::getResourceType() );
//		
//		if	( _pResource->removeRef() == 0 )
//		{
//			pResourceHandler->removeResource( _pResource );
//		}
//		
//		_pResource = 0;
//	}
//}

//-----------------------------------------------------------------------------
// Name:		release
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void OkdResourcePtr<T>::release()
{
	if	( _pResource )
	{
		if	( _pResource->removeRef() == 0 )
		{
			OkdResourceManager::removeResource<T>( _pResource->getResourceKey() );
		}

		_pResource = 0;
	}
}

//-----------------------------------------------------------------------------
// Name:		getResource
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
T*	OkdResourcePtr<T>::getResource()
{
	return	( _pResource );
}

//-----------------------------------------------------------------------------
// Name:		getResourceName
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
const OkdString&	OkdResourcePtr<T>::getResourceName() const
{
	return	( _pResource->getResourceName() );
}

//-----------------------------------------------------------------------------
// Name:		load
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void OkdResourcePtr<T>::load()
{
	ORKID_ASSERT( _pResource );

	if	( _pResource )
	{
		const OkdString& strResourceName = _pResource->getResourceName();

		if	( strResourceName.isEmpty() )
		{
			ORKID_BREAK();
			return;
		}

		OkdResourceDatabase*	pResourceDatabase	= OrkidEngine::instance()->getResourceDatabase();
		OkdFileStream*			pResourceFileStream	= pResourceDatabase->openResourceFileStream( T::getResourceType(), _pResource->getResourceName(), OkdResourceDatabase::OpenStreamLoad );

		if	( pResourceFileStream )
		{
			_pResource->read( pResourceFileStream );
			pResourceDatabase->closeResourceFileStream( &pResourceFileStream );
		}
	}
}

//-----------------------------------------------------------------------------
// Name:		save
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void OkdResourcePtr<T>::save()
{
	ORKID_ASSERT( _pResource );

	if	( _pResource )
	{
		const OkdString& strResourceName = _pResource->getResourceName();

		if	( strResourceName.isEmpty() )
		{
			ORKID_BREAK();
			return;
		}

		OkdResourceDatabase*	pResourceDatabase	= OrkidEngine::instance()->getResourceDatabase();
		OkdFileStream*			pResourceFileStream	= pResourceDatabase->openResourceFileStream( T::getResourceType(), _pResource->getResourceName(), OkdResourceDatabase::OpenStreamSave );

		if	( pResourceFileStream )
		{
			_pResource->write( pResourceFileStream );
			pResourceDatabase->closeResourceFileStream( &pResourceFileStream );
		}
	}
}

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif