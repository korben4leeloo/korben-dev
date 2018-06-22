//*****************************************************************************
//
//	Class:		QmTaskScheduler
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __QUANTUM_CORE_TASK_SCHEDULER_H__
#define __QUANTUM_CORE_TASK_SCHEDULER_H__

#include "Root.h"
#include QUANTUM_CORE_H(Containers/QmStdList)

class QmTaskScheduler
{
private:
	// Define task structures
	struct QmTaskBase
	{
						QmTaskBase( const uint32 uiTaskPriority ): _uiTaskPriority( uiTaskPriority ) {}
		virtual void	execute() = 0;

		uint32			_uiTaskPriority;
	};

	template<class T>
	struct QmObjectTask: public QmTaskBase
	{
		typedef void (T::*QmPfnObjectTaskCallback)();

										QmObjectTask( const uint32 uiTaskPriority, T* pCaller, const QmPfnObjectTaskCallback pfnTaskCallback );
		virtual void					execute();

		T*								_pCaller			= nullptr;
		const QmPfnObjectTaskCallback	_pfnTaskCallback	= nullptr;
	};

	struct QmStaticTask: public QmTaskBase
	{
		typedef void (*QmPfnStaticTaskCallback)();

										QmStaticTask( const uint32 uiTaskPriority, const QmPfnStaticTaskCallback pfnTaskCallback );
		virtual void					execute();

		const QmPfnStaticTaskCallback	_pfnTaskCallback = nullptr;
	};

public:
							QmTaskScheduler();
							~QmTaskScheduler();

	template<class T> void	createTask( const uint32 uiTaskPriority, T* pCaller, const typename QmObjectTask<T>::QmPfnObjectTaskCallback pfnTaskCallback );
	void					createTask( const uint32 uiTaskPriority, const QmStaticTask::QmPfnStaticTaskCallback pfnTaskCallback );
	void					execute();

private:
	

	typedef QmStdList<QmTaskBase*> QmTaskList;

	QmTaskList	_lTasks;
};

//-----------------------------------------------------------------------------
// Name:		QmTaskScheduler constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
QmTaskScheduler::QmObjectTask<T>::QmObjectTask( const uint32 uiTaskPriority, T* pCaller, const QmPfnObjectTaskCallback pfnTaskCallback )
: QmTaskBase( uiTaskPriority )
, _pCaller			( pCaller )
, _pfnTaskCallback	( pfnTaskCallback ) 
{

}

//-----------------------------------------------------------------------------
// Name:		QmTaskScheduler constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void QmTaskScheduler::QmObjectTask<T>::execute()
{
	if ( _pCaller && _pfnTaskCallback )
	{
		_pCaller->_pfnTaskCallback();
	}
}

//-----------------------------------------------------------------------------
// Name:		createTask
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T>
void QmTaskScheduler::createTask( const uint32 uiTaskPriority, T* pCaller, const typename QmObjectTask<T>::QmPfnObjectTaskCallback pfnTaskCallback )
{
	if	( pCaller && pfnTaskCallback )
	{
		QmTaskList::iterator it = _lTasks.begin();

		while	( it.isValid() )
		{
			if	( uiTaskPriority > (*it)->_uiTaskPriority )
			{
				it++;
			}
			else
			{
				break;
			}
		}

		_lTasks.insertBefore( it, new QmObjectTask<T>( uiTaskPriority, pCaller, pfnTaskCallback ) );
	}
}

#endif