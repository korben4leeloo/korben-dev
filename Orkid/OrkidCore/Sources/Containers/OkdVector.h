//*****************************************************************************
//
//	Class:		OkdVector
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdVector_h__
#define __OrkidCore_OkdVector_h__

#include <QVector>

template< class T>
class OkdVector: public QVector<T>
{
public:
	OkdVector();
	~OkdVector();

private:
};

#endif