//*****************************************************************************
//
//	Class:		QmResourceManager
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __QUANTUM_CORE_RESOURCE_MANAGER_H__
#define __QUANTUM_CORE_RESOURCE_MANAGER_H__

#include "Root.h"

class QmResourceManager
{
	friend class QmApplication;

public:
	void	loadResourceDefinitions();			

private:
			QmResourceManager();
			~QmResourceManager();
};

#endif