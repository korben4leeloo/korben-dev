//*****************************************************************************
//
//	Class:		OkdTransformComponent
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdTransformComponent_h__
#define __OrkidCore_OkdTransformComponent_h__

#include	"Root.h"
#include	ORKID_CORE_H(Framework/OkdAbstractComponent)

class OkdTransformComponent: public OkdAbstractComponent
{
public:
			OkdTransformComponent();
	virtual	~OkdTransformComponent();

	OKD_MAKE_COMPONENT( OkdTransformComponent, "TransformComponent" )

private:
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif
