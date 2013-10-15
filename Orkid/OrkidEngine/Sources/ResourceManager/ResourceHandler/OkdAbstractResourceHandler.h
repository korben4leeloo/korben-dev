//*****************************************************************************
//
//	Class:		OkdAbstractResourceHandler
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdAbstractResourceHandler_h__
#define __OrkidEngine_OkdAbstractResourceHandler_h__

#include	"Root.h"

#include	ORKID_CORE_H(String/OkdString)
#include	ORKID_CORE_H(Containers/OkdMap)

class OkdResourcePtr;
class OkdResourceId;

//#define	FRIEND_RESOURCE_HANDLER_SINGLETON(SingletonClass) \
//	friend SingletonClass*	OkdAbstractResourceHandlerSingleton<SingletonClass>::create(); \
//	friend void				OkdAbstractResourceHandlerSingleton<SingletonClass>::destroy();

class OkdAbstractResourceHandler
{
public:
	virtual void					createResource( const OkdResourceId& resourceId )	= 0;
	virtual void					loadResource( const OkdResourcePtr& resourcePtr )	= 0;
	virtual void					unloadResource( const OkdResourcePtr& resourcePtr )	= 0;
	virtual void					saveResource( const OkdResourcePtr& resourcePtr )	= 0;

	//inline const char*				getResourceTypeName() const;
	//inline const OrkidResourceType	getResourceType() const;

protected:
									//OkdAbstractResourceHandler(const OrkidResourceType eResourceType);
									OkdAbstractResourceHandler();
	virtual							~OkdAbstractResourceHandler();

private:
	typedef OkdMap<OkdString, OkdResourcePtr>	_resourceMap;
	//OkdList<OkdResourceHandle*>		_resourceList;
	//const char*						_strResourceTypeName;
	//OrkidResourceType				_eResourceType;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

////-----------------------------------------------------------------------------
//// Name:		getResourceTypeName
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//const char*	OkdAbstractResourceHandler::getResourceTypeName() const
//{
//	return	( _strResourceTypeName );
//}

////-----------------------------------------------------------------------------
//// Name:		getResourceType
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//const OrkidResourceType	OkdAbstractResourceHandler::getResourceType() const
//{
//	return	( _eResourceType );
//}


////*****************************************************************************
////
////	Class:		OkdAbstractResourceHandlerSingleton
////
////	Created:	2013-08-26
////
////*****************************************************************************
//
//template<class T>
//class OkdAbstractResourceHandlerSingleton: public OkdAbstractResourceHandler
//{
//public:
//	inline static T*	create();
//	inline static void	destroy();
//	inline static T*	instance();
//
//protected:
//						OkdAbstractResourceHandlerSingleton(const OrkidResourceType eResourceType);
//						~OkdAbstractResourceHandlerSingleton();
//
//	static T*			_pInstance;
//};
//
//template<class T> T* OkdAbstractResourceHandlerSingleton<T>::_pInstance = 0;
//
////*****************************************************************************
////	Inline functions declarations
////*****************************************************************************
//
////-----------------------------------------------------------------------------
//// Name:		OkdSharedPtr constructor
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T>
//OkdAbstractResourceHandlerSingleton<T>::OkdAbstractResourceHandlerSingleton(const OrkidResourceType eResourceType)
//: OkdAbstractResourceHandler( eResourceType )
//{
//	
//}
//
////-----------------------------------------------------------------------------
//// Name:		OkdSharedPtr destructor
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T>
//OkdAbstractResourceHandlerSingleton<T>::~OkdAbstractResourceHandlerSingleton()
//{
//	
//}
//
////-----------------------------------------------------------------------------
//// Name:		create
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T>
//T*	OkdAbstractResourceHandlerSingleton<T>::create()
//{
//	destroy();
//
//	_pInstance = new T();
//	return	( _pInstance );
//}
//
////-----------------------------------------------------------------------------
//// Name:		destroy
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T>
//void	OkdAbstractResourceHandlerSingleton<T>::destroy()
//{
//	if	( _pInstance )
//	{
//		delete _pInstance;
//		_pInstance = 0;
//	}
//}
//
////-----------------------------------------------------------------------------
//// Name:		instance
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T>
//T*	OkdAbstractResourceHandlerSingleton<T>::instance()
//{
//	ORKID_ASSERT( _pInstance );
//	return	( _pInstance );
//}

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif