//*****************************************************************************
//
//	Class:		QmSlot
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __QUANTUM_CORE_QM_SLOT_h__
#define __QUANTUM_CORE_QM_SLOT_h__

#include	"Root.h"

#define	QM_DECLARE_SLOT( SlotClass, SlotName, ... ) typedef QmSlot<SlotClass, __VA_ARGS__> Qm##SlotName##Slot; \
	void SlotName( __VA_ARGS__ ); \
	void init##SlotName##Slot() { SlotName##Slot.init( this , &SlotClass::SlotName ); } \
	Qm##SlotName##Slot SlotName##Slot;

template<class...SlotArgs>
class QmAbstractSlot
{
public:
	virtual void	receive( SlotArgs...args ) = 0;

protected:
					QmAbstractSlot();
	virtual			~QmAbstractSlot();
};

template<class T, class...SlotArgs>
class QmSlot: public QmAbstractSlot<SlotArgs...>
{
//private:
public:
	typedef void (T::*QmPfnSlotFunc)(SlotArgs...args);

public:
	typedef T ReceiverType;

					QmSlot();
	virtual			~QmSlot();

	void			init( T* pReceiver, QmPfnSlotFunc pfnSlot );
	virtual void	receive( SlotArgs...args );

private:
	T*				_pReceiver	= nullptr;
	QmPfnSlotFunc	_pfnSlot	= nullptr;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		QmAbstractSlot constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class...SlotArgs>
QmAbstractSlot<SlotArgs...>::QmAbstractSlot()
{
	
}

//-----------------------------------------------------------------------------
// Name:		QmAbstractSlot destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class...SlotArgs>
QmAbstractSlot<SlotArgs...>::~QmAbstractSlot()
{
	
}

//-----------------------------------------------------------------------------
// Name:		QmSlot constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, class...SlotArgs>
QmSlot<T, SlotArgs...>::QmSlot()
{
	
}

//-----------------------------------------------------------------------------
// Name:		QmSlot destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, class...SlotArgs>
QmSlot<T, SlotArgs...>::~QmSlot()
{
	
}

//-----------------------------------------------------------------------------
// Name:		receive
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, class...SlotArgs>
void QmSlot<T, SlotArgs...>::init( T* pReceiver, QmPfnSlotFunc pfnSlot )
{
	QUANTUM_ASSERT( pReceiver );
	QUANTUM_ASSERT( pfnSlot );

	_pReceiver	= pReceiver;
	_pfnSlot	= pfnSlot;
}

//-----------------------------------------------------------------------------
// Name:		receive
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<class T, class...SlotArgs>
void QmSlot<T, SlotArgs...>::receive(SlotArgs...args)
{
	QUANTUM_ASSERT( _pReceiver );
	QUANTUM_ASSERT( _pfnSlot );

	if	( _pReceiver && _pfnSlot )
	{
		(_pReceiver->*_pfnSlot)( args... );
	}
}

#endif
