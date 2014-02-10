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

#define	OKD_DECLARE_SIGNAL( SignalName, ... ) typedef OkdSignal<__VA_ARGS__> Okd##SignalName##Signal;
#define	OKD_SIGNAL_CONNECT( sender, signal, receiver, slot ) sender->signal.connect( &receiver->slot )

template<class...SlotArgs>
class OkdSignal
{
	typedef OkdList<OkdAbstractSlot<SlotArgs...>*> OkdSlotList;

public:
				OkdSignal();
				~OkdSignal();

	void		connect( OkdAbstractSlot<SlotArgs...>* pSlot );
	void		send( SlotArgs...args );

private:
	OkdSlotList	_slots;
};

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
void OkdSignal<SlotArgs...>::connect(OkdAbstractSlot<SlotArgs...>*	pSlot)
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
	OkdSlotList::const_iterator it = _slots.begin();

	while	( it != _slots.end() )
	{
		(*it)->receive( args... );
		it++;
	}
}

#endif
