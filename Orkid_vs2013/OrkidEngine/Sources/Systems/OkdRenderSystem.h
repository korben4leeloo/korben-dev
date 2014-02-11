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

	OkdAddComponentSlot<OkdRenderSystem>	_onAddComponentSlot;
	OkdRemoveComponentSlot<OkdRenderSystem>	_onRemoveComponentSlot;

private:
	void									onComponentAdded( const OkdEntity* pEntity, const OkdComponentId componentId );
	void									onComponentRemoved( const OkdEntity* pEntity, const OkdComponentId componentId );
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif
