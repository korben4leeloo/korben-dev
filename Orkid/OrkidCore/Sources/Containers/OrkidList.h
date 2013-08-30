//*****************************************************************************
//
//	Class:		OrkidList
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OrkidList_h__
#define __OrkidCore_OrkidList_h__

#include <QList>

template< class T>
class OrkidList: public QList<T>
{
public:
	OrkidList();
	~OrkidList();

private:
};

#endif