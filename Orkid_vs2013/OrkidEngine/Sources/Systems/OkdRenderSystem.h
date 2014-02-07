//*****************************************************************************
//
//	Class:		OkdRenderSystem
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdRenderSystem_h__
#define __OrkidCore_OkdRenderSystem_h__

#include	"Root.h"

#include	ORKID_CORE_H(Systems/OkdAbstractSystem)

class OkdRenderSystem: public OkdAbstractSystem
{
public:
					OkdRenderSystem();
	virtual			~OkdRenderSystem();

	virtual void	update();

private:
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif
