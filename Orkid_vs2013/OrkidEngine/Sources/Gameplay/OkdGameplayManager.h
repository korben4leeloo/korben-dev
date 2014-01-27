//*****************************************************************************
//
//	Class:		OkdGameplayManager
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdGameplayManager_h__
#define __OrkidEngine_OkdGameplayManager_h__

#include	"Root.h"

#include	ORKID_CORE_H(Singleton/OkdSingleton)

class OkdGameplayManager: public OkdSingleton<OkdGameplayManager>
{
	friend class OkdSingleton<OkdGameplayManager>;

public:
				

private:
	OkdGameplayManager();
	~OkdGameplayManager();
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif