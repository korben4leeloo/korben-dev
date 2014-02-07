//*****************************************************************************
//
//	Class:		OkdSignal
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdSignal_h__
#define __OrkidCore_OkdSignal_h__

#include	"Root.h"

#include	ORKID_CORE_H(Signals/OkdSlot)
#include	ORKID_CORE_H(Containers/OkdList)

template<class...SlotArgs>
class OkdSignal
{
public:
	OkdSignal();
	~OkdSignal();

	void							connect( OkdSlot<SlotArgs...>* pSlot );
	void							send( SlotArgs...args );

private:
	typedef void (*pfnSlotFunc)(SlotArgs...args);

	OkdList<OkdSlot<SlotArgs...>*>	_slots;
};

//class OkdSignalManager
//{
//public:
//	template<
//	static void	connect( 
//
//private:
//	OkdSignalManager() {}
//	~OkdSignalManager() {}
//};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		OkdSignal constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class...SlotArgs>
OkdSignal<SlotArgs...>::OkdSignal()
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdSignal destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class...SlotArgs>
OkdSignal<SlotArgs...>::~OkdSignal()
{
	
}

//-----------------------------------------------------------------------------
// Name:		connect
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class...SlotArgs>
void OkdSignal<SlotArgs...>::connect(OkdSlot<SlotArgs...>*	pSlot)
{
	_slots.add( pSlot );
}

//-----------------------------------------------------------------------------
// Name:		send
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class...SlotArgs>
void OkdSignal<SlotArgs...>::send(SlotArgs...args)
{
	
}

#endif
