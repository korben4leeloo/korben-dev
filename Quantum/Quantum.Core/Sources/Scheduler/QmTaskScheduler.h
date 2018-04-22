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
#include QUANTUM_CORE_H(Containers/QmList)

class QmTaskScheduler
{
public:
	typedef void (*QmPfnTaskCallback)();

				QmTaskScheduler();
				~QmTaskScheduler();

	void		createTask( const uint32 uiTaskPriority, const QmPfnTaskCallback pfnTaskCallback );
	void		execute();

private:
	struct QmTask
	{
								QmTask( const uint32 uiTaskPriority, const QmPfnTaskCallback pfnTaskCallback );

		uint32					_uiTaskPriority;
		const QmPfnTaskCallback	_pfnTaskCallback = nullptr;	
	};

	typedef QmList<QmTask> QmTaskList;

	QmTaskList	_lTasks;
};

#endif