//*****************************************************************************
//
//	File:		QmCoreSignals.h
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_QmCoreSignals_h__
#define __OrkidCore_QmCoreSignals_h__

#include	"Root.h"

#include	QUANTUM_CORE_H(Signals/QmSignal)
#include	QUANTUM_CORE_H(Signals/QmSlot)

#define	QM_DECLARE_SIGNAL_AND_SLOT( SignalName, ... )	\
	QM_DECLARE_SIGNAL( SignalName, __VA_ARGS__ )		\
	QM_DECLARE_SLOT( SignalName, __VA_ARGS__ )

#endif
