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

#include	ORKID_CORE_H(Framework/OkdAbstractSystem)
#include	ORKID_CORE_H(Signals/OkdCoreSignals)

class OkdRenderSystem: public OkdAbstractSystem
{
public:
											OkdRenderSystem();
	virtual									~OkdRenderSystem();

	virtual void							update();

	OkdCreateComponentSlot<OkdRenderSystem>	_onCreateComponentSlot;
	OkdRemoveComponentSlot<OkdRenderSystem>	_onRemoveComponentSlot;

private:
	void									onComponentCreated( const OkdComponentId componentId );
	void									onComponentRemoved( const OkdComponentId componentId );
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif
