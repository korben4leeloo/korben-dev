//*****************************************************************************
//
//	Class:		OkdList
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdList_h__
#define __OrkidCore_OkdList_h__

#include <QList>

template< class T>
class OkdList: public QList<T>
{
public:
	OkdList();
	~OkdList();

private:
};

#endif