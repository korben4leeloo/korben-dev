//*****************************************************************************
//
//	Class:		OkdSingleton
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdSingleton_h__
#define __OrkidCore_OkdSingleton_h__

#include	"Root.h"

#define	FRIEND_SINGLETON(SingletonClass) \
	friend SingletonClass*	OkdSingleton<SingletonClass>::create(); \
	friend void				OkdSingleton<SingletonClass>::destroy();

template<class T>
class OkdSingleton
{
public:
	inline static T*	create();
	inline static void	destroy();
	inline static T*	instance();

	virtual void		onCreate();

protected:
						OkdSingleton();
						~OkdSingleton();

	static T*			_pInstance;
};

template<class T> T* OkdSingleton<T>::_pInstance = 0;

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		OkdSharedPtr constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
OkdSingleton<T>::OkdSingleton()
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdSharedPtr destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
OkdSingleton<T>::~OkdSingleton()
{
	
}

//-----------------------------------------------------------------------------
// Name:		create
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
T*	OkdSingleton<T>::create()
{
	destroy();

	_pInstance = new T();
	_pInstance->onCreate();

	return	( _pInstance );
}

//-----------------------------------------------------------------------------
// Name:		destroy
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void	OkdSingleton<T>::destroy()
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
T*	OkdSingleton<T>::instance()
{
	ORKID_ASSERT( _pInstance );
	return	( _pInstance );
}

//-----------------------------------------------------------------------------
// Name:		onCreate
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void	OkdSingleton<T>::onCreate()
{
	
}

#endif
