//*****************************************************************************
//
//	File:		OkdCoreSignals.h
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdCoreSignals_h__
#define __OrkidCore_OkdCoreSignals_h__

#include	"Root.h"

#include	ORKID_CORE_H(Signals/OkdSignal)
#include	ORKID_CORE_H(Signals/OkdSlot)

#define	OKD_DECLARE_SIGNAL_AND_SLOT( SignalName, ... )	\
	OKD_DECLARE_SIGNAL( SignalName, __VA_ARGS__ )		\
	OKD_DECLARE_SLOT( SignalName, __VA_ARGS__ )

OKD_DECLARE_SIGNAL_AND_SLOT( CreateComponent, const OkdComponentId )
OKD_DECLARE_SIGNAL_AND_SLOT( RemoveComponent, const OkdComponentId )

#endif
