//*****************************************************************************
//
//	Class:		QmDebug
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __QUANTUM_RUNTIME_UNIT_TEST_H__
#define __QUANTUM_RUNTIME_UNIT_TEST_H__

#include "Root.h"

class QmUnitTest
{
public:
			QmUnitTest();
			~QmUnitTest();

	void	launch();

private:
	void	TestQmMap();
	void	TestQmTree();
};

#endif