//*****************************************************************************
//
//	Class:		QmApplication
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __QUANTUM_CORE_TK_WIN32_APP_H__
#define __QUANTUM_CORE_TK_WIN32_APP_H__

#include "Root.h"
#include <Windows.h>

#include QUANTUM_CORE_H(Containers/QmVector)
#include QUANTUM_CORE_H(Scheduler/QmTaskScheduler)

class QmWindow;
class QmInputManager;

class QmApplication
{
public:
							QmApplication( const HINSTANCE& hInstance );
							~QmApplication();

	inline HINSTANCE		getInstanceHandle() const;
	inline QmInputManager*	getInputManager();
	inline QmTaskScheduler*	getTaskScheduler();

	void					init();

	QmWindow*				createWindow();
	void					destroyWindows();

	int64_t					run();

private:
	QmInputManager*			createInputManager();

	void					destroy();

	HINSTANCE				_hInstance;
	QmInputManager*			_pInputManager;
	QmVector<QmWindow*>		_windowArray;

	QmTaskScheduler			_TaskScheduler;
};

//-----------------------------------------------------------------------------
// Name:		getInstanceHandle
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
HINSTANCE QmApplication::getInstanceHandle() const
{
	return ( _hInstance );
}

//-----------------------------------------------------------------------------
// Name:		getInputManager
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmInputManager* QmApplication::getInputManager()
{
	QUANTUM_ASSERT( _pInputManager );
	return ( _pInputManager );
}

//-----------------------------------------------------------------------------
// Name:		getTaskScheduler
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmTaskScheduler* QmApplication::getTaskScheduler()
{
	return ( &_TaskScheduler );
}

#endif