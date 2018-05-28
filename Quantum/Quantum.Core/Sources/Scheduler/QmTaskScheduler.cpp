//*****************************************************************************
//
//	File:		QmTaskScheduler.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "QmTaskScheduler.h"

//-----------------------------------------------------------------------------
// Name:		QmTaskScheduler constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmTaskScheduler::QmTaskScheduler()
{
	
}

//-----------------------------------------------------------------------------
// Name:		QmTaskScheduler destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmTaskScheduler::~QmTaskScheduler()
{
	
}

//-----------------------------------------------------------------------------
// Name:		createTask
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void QmTaskScheduler::createTask( const uint32 uiTaskPriority, const QmStaticTask::QmPfnStaticTaskCallback pfnTaskCallback )
{
	if	( pfnTaskCallback != nullptr )
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

		_lTasks.insertBefore( it, new QmStaticTask( uiTaskPriority, pfnTaskCallback ) );
	}
}

//-----------------------------------------------------------------------------
// Name:		QmTaskScheduler constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmTaskScheduler::QmStaticTask::QmStaticTask( const uint32 uiTaskPriority, const QmPfnStaticTaskCallback pfnTaskCallback )
	: QmTaskBase( uiTaskPriority )
	, _pfnTaskCallback( pfnTaskCallback )
{

}

//-----------------------------------------------------------------------------
// Name:		QmTaskScheduler constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void QmTaskScheduler::QmStaticTask::execute()
{
	if ( _pfnTaskCallback )
	{
		_pfnTaskCallback();
	}
}

//-----------------------------------------------------------------------------
// Name:		execute
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void QmTaskScheduler::execute()
{
	QmTaskList::iterator it = _lTasks.begin();

	while ( it.isValid() )
	{
		(*it)->execute();
		it++;
	}
}
