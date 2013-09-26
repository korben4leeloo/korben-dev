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

class OkdSharedResource;

#define	FRIEND_RESOURCE_HANDLER_SINGLETON(SingletonClass) \
	friend SingletonClass*	OkdAbstractResourceHandlerSingleton<SingletonClass>::create(); \
	friend void				OkdAbstractResourceHandlerSingleton<SingletonClass>::destroy();

class OkdAbstractResourceHandler
{
public:
	virtual void	load( OkdSharedResource* pResource )	= 0;
	virtual void	unload( OkdSharedResource* pResource )	= 0;

protected:
					OkdAbstractResourceHandler();
					~OkdAbstractResourceHandler();
};

template<class T>
class OkdAbstractResourceHandlerSingleton: public OkdAbstractResourceHandler
{
public:
	inline static T*	create();
	inline static void	destroy();
	inline static T*	instance();

protected:
						OkdAbstractResourceHandlerSingleton();
						~OkdAbstractResourceHandlerSingleton();

	static T*			_pInstance;
};

template<class T> T* OkdAbstractResourceHandlerSingleton<T>::_pInstance = 0;

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		OkdSharedPtr constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
OkdAbstractResourceHandlerSingleton<T>::OkdAbstractResourceHandlerSingleton()
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdSharedPtr destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
OkdAbstractResourceHandlerSingleton<T>::~OkdAbstractResourceHandlerSingleton()
{
	
}

//-----------------------------------------------------------------------------
// Name:		create
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
T*	OkdAbstractResourceHandlerSingleton<T>::create()
{
	destroy();

	_pInstance = new T();

	return	( _pInstance );
}

//-----------------------------------------------------------------------------
// Name:		destroy
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void	OkdAbstractResourceHandlerSingleton<T>::destroy()
{
	if	( _pInstance )
	{
		delete _pInstance;
		_pInstance = 0;
	}
}

//-----------------------------------------------------------------------------
// Name:		instance
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
T*	OkdAbstractResourceHandlerSingleton<T>::instance()
{
	ORKID_ASSERT( _pInstance );
	return	( _pInstance );
}

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif