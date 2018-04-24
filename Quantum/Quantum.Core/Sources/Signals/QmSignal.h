//*****************************************************************************
//
//	Class:		QmSignal
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __QUANTUM_CORE_QM_SIGNAL_h__
#define __QUANTUM_CORE_QM_SIGNAL_h__

#include	"Root.h"

#include	QUANTUM_CORE_H(Signals/QmSlot)
#include	QUANTUM_CORE_H(Containers/QmList)

#define	QM_DECLARE_SIGNAL( SignalName, ... ) typedef QmSignal<__VA_ARGS__> Qm##SignalName##Signal; \
	Qm##SignalName##Signal SignalName##Signal;

#define	QM_SIGNAL_CONNECT( sender, SignalName, receiver, SlotName ) \
	receiver->init##SlotName##Slot(); \
	sender->SignalName##Signal.connect( receiver, &receiver->SlotName##Slot )

#define	QM_SIGNAL_SEND( sender, SignalName, ... ) sender->SignalName##Signal.send( __VA_ARGS__ );

template<class...SignalArgs>
class QmSignal
{
	typedef QmList<QmAbstractSlot<SignalArgs...>*> QmSlotList;

public:
				QmSignal();
				~QmSignal();

	template<typename SlotType>
	void		connect( SlotType* pReceiver, QmAbstractSlot<SignalArgs...>* pSlot );

	void		send( SignalArgs...args );

private:
	QmSlotList	_slots;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		QmSignal constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class...SignalArgs>
QmSignal<SignalArgs...>::QmSignal()
{
	
}

//-----------------------------------------------------------------------------
// Name:		QmSignal destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class...SignalArgs>
QmSignal<SignalArgs...>::~QmSignal()
{
	
}

//-----------------------------------------------------------------------------
// Name:		connect
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class...SignalArgs>
template<typename SlotType>
void QmSignal<SignalArgs...>::connect(SlotType* pReceiver, QmAbstractSlot<SignalArgs...>* pSlot)
{
	_slots.pushBack( pSlot );
}

//-----------------------------------------------------------------------------
// Name:		send
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class...SignalArgs>
void QmSignal<SignalArgs...>::send(SignalArgs...args)
{
	QmSlotList::iterator it = _slots.begin();

	while	( it.isValid() )
	{
		(*it)->receive( args... );
		it++;
	}
}

#endif
