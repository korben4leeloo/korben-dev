//*****************************************************************************
//
//	Class:		OkdSlot
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdSlot_h__
#define __OrkidCore_OkdSlot_h__

#include	"Root.h"

#define	OKD_DECLARE_SLOT( SignalName, ... ) template<class T> using Okd##SignalName##Slot = OkdSlot<T, __VA_ARGS__>;

template<class...SlotArgs>
class OkdAbstractSlot
{
public:
	virtual void	receive( SlotArgs...args ) = 0;

protected:
					OkdAbstractSlot();
	virtual			~OkdAbstractSlot();
};

template<class T, class...SlotArgs>
class OkdSlot: public OkdAbstractSlot<SlotArgs...>
{
private:
	typedef void (T::*pfnSlotFunc)(SlotArgs...args);

public:
					OkdSlot( T* pReceiver, pfnSlotFunc slotFn );
	virtual			~OkdSlot();

	virtual void	receive( SlotArgs...args );

private:
	T*				_pReceiver;
	pfnSlotFunc		_slotFn;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		OkdAbstractSlot constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class...SlotArgs>
OkdAbstractSlot<SlotArgs...>::OkdAbstractSlot()
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdAbstractSlot destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class...SlotArgs>
OkdAbstractSlot<SlotArgs...>::~OkdAbstractSlot()
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdSlot constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, class...SlotArgs>
OkdSlot<T, SlotArgs...>::OkdSlot(T*				pReceiver, 
							     pfnSlotFunc	slotFn)
: _pReceiver	( pReceiver )
, _slotFn		( slotFn )
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdSlot destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, class...SlotArgs>
OkdSlot<T, SlotArgs...>::~OkdSlot()
{
	
}

//-----------------------------------------------------------------------------
// Name:		receive
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, class...SlotArgs>
void OkdSlot<T, SlotArgs...>::receive(SlotArgs...	args)
{
	ORKID_ASSERT( _pReceiver );
	ORKID_ASSERT( _slotFn );

	if	( _pReceiver && _slotFn )
	{
		(_pReceiver->*_slotFn)( args... );
	}
}

#endif
