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
// Name:		QmTaskScheduler constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmTaskScheduler::QmTask::QmTask( const uint32 uiTaskPriority, const QmPfnTaskCallback pfnTaskCallback )
: _uiTaskPriority	( uiTaskPriority )
, _pfnTaskCallback	( pfnTaskCallback ) 
{

}

//-----------------------------------------------------------------------------
// Name:		createTask
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void QmTaskScheduler::createTask( const uint32 uiTaskPriority, const QmPfnTaskCallback pfnTaskCallback )
{
	if	( pfnTaskCallback != nullptr )
	{
		QmTaskList::QmIterator it = _lTasks.begin();

		while	( it.isValid() )
		{
			if	( uiTaskPriority > it->_uiTaskPriority )
			{
				it++;
			}
			else
			{
				break;
			}
		}

		_lTasks.insertBefore( it, QmTask( uiTaskPriority, pfnTaskCallback ) );
	}
}

//-----------------------------------------------------------------------------
// Name:		execute
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void QmTaskScheduler::execute()
{
	QmTaskList::QmIterator it = _lTasks.begin();
	
	while	( it.isValid() )
	{
		it->_pfnTaskCallback();
		it++;
	}
}
