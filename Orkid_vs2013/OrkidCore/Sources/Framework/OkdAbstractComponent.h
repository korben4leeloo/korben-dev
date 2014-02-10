//*****************************************************************************
//
//	Class:		OkdAbstractComponent
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdAbstractComponent_h__
#define __OrkidCore_OkdAbstractComponent_h__

#include	"Root.h"

#include	ORKID_CORE_H(String/OkdCrc32)
#include	ORKID_CORE_H(Memory/OkdSharedPtr)
#include	ORKID_CORE_H(Framework/OkdAbstractComponent)

#define	OKD_MAKE_COMPONENT( ClassName, ComponentName )								\
	static OkdAbstractComponent*	create() { return new ClassName(); }			\
	static const char*				getComponentName() { return ComponentName; }	\
	static OkdComponentId			getComponentId()								\
	{																				\
		static OkdComponentId componentId = OKD_INVALID_COMPONENT_ID;				\
																					\
		if	( componentId == OKD_INVALID_COMPONENT_ID )								\
		{																			\
			componentId = OkdCrc32::getCrc32( ComponentName );						\
		}																			\
																					\
		return componentId;															\
	}																				\
																					\
	virtual OkdComponentId OkdAbstractComponent::getTypeId() const					\
	{																				\
		return	( ClassName::getComponentId() );									\
	}																				

#define OKD_INVALID_COMPONENT_ID (OkdComponentId)0

class OkdAbstractComponent
{
public:
							OkdAbstractComponent();
	virtual					~OkdAbstractComponent();

	virtual OkdComponentId	getTypeId() const = 0;

private:
};

typedef OkdAbstractComponent* (*pfnComponentCreator)();
typedef OkdSharedPtr<OkdAbstractComponent> OkdComponentPtr;

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif
