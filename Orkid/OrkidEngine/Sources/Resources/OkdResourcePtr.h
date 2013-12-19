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
	T*					_pResource;
};

//-----------------------------------------------------------------------------
// Name:		OkdResourcePtr constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OkdResourceType resourceType>
OkdResourcePtr<T, resourceType>::OkdResourcePtr()
: _pResource( 0 )
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
	_pResource = resourcePtr._pResource;

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

	_pResource = resourcePtr._pResource;

	if	( _pResource )
	{
		_pResource->addRef();
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
	OkdResourceManager*			pResourceManager = OrkidEngine::instance()->getResourceManager();
	OkdAbstractResourceHandler*	pResourceHandler = pResourceManager->getResourceHandler( resourceType );

	ORKID_ASSERT( pResourceHandler );

	if	( pResourceHandler )
	{
		T* pResource = static_cast<T*>(pResourceHandler->addResource( strResourceName ));

		if	( pResource && ( pResource != _pResource ) )
		{
			unbind();

			_pResource = pResource;
			_pResource->addRef();
		}
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
	if	( _pResource )
	{
		OkdResourceManager*			pResourceManager	= OrkidEngine::instance()->getResourceManager();
		OkdAbstractResourceHandler*	pResourceHandler	= pResourceManager->getResourceHandler( resourceType );
		
		if	( _pResource->removeRef() == 0 )
		{
			pResourceHandler->removeResource( _pResource );
		}
		
		_pResource = 0;
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
	return	( _pResource );
}

//-----------------------------------------------------------------------------
// Name:		getResourceName
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OkdResourceType resourceType>
const OkdString&	OkdResourcePtr<T, resourceType>::getResourceName() const
{
	return	( _pResource->getResourceName() );
}

//-----------------------------------------------------------------------------
// Name:		load
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, OkdResourceType resourceType>
void OkdResourcePtr<T, resourceType>::load()
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
		OkdFileStream*			pResourceFileStream	= pResourceDatabase->openResourceFileStream( resourceType, _pResource->getResourceName(), OkdResourceDatabase::OpenStreamLoad );

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
template<class T, OkdResourceType resourceType>
void OkdResourcePtr<T, resourceType>::save()
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
		OkdFileStream*			pResourceFileStream	= pResourceDatabase->openResourceFileStream( resourceType, _pResource->getResourceName(), OkdResourceDatabase::OpenStreamSave );

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