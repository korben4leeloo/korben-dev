//*****************************************************************************
//
//	Class:		TkApplication
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_CORE_TK_WIN32_APP_H__
#define __TARS_CORE_TK_WIN32_APP_H__

#include "Root.h"
#include <Windows.h>

#include TARS_CORE_H(Containers/TkVector)

class TkWindow;
class TkInputManager;

class TkApplication
{
public:
							TkApplication( const HINSTANCE& hInstance );
							~TkApplication();

	inline HINSTANCE		getInstanceHandle() const;
	inline TkInputManager*	getInputManager() const;

	TkInputManager*			initInputs();
	//TkWindow*				initWindow();
	void					initWglContext();

	int64_t					run();

private:
	void					destroy();

	HINSTANCE				_hInstance;
	TkInputManager*			_pInputManager;
	TkVector<TkWindow*>		_windowArray;
};

//-----------------------------------------------------------------------------
// Name:		getInstanceHandle
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
HINSTANCE TkApplication::getInstanceHandle() const
{
	return ( _hInstance );
}

//-----------------------------------------------------------------------------
// Name:		getInputManager
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkInputManager* TkApplication::getInputManager() const
{
	return ( _pInputManager );
}

#endif