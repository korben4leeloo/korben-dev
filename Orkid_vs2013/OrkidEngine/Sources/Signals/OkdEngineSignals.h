//*****************************************************************************
//
//	File:		OkdEngineSignals.h
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdEngineSignals_h__
#define __OrkidCore_OkdEngineSignals_h__

#include	"Root.h"

#include	ORKID_CORE_H(Signals/OkdSignal)
#include	ORKID_CORE_H(Signals/OkdSlot)

#define	OKD_DECLARE_SIGNAL_AND_SLOT( SignalName, ... )							\
	typedef OkdSignal<__VA_ARGS__> Okd##SignalName##Signal;						\
	template<class T> using Okd##SignalName##Slot = OkdSlot<T, __VA_ARGS__>;

OKD_DECLARE_SIGNAL_AND_SLOT( CreateComponent, const OkdComponentId )
OKD_DECLARE_SIGNAL_AND_SLOT( RemoveComponent, const OkdComponentId )

#endif
