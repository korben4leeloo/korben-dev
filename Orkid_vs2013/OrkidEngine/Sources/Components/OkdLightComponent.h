//*****************************************************************************
//
//	Class:		OkdLightComponent
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdLightComponent_h__
#define __OrkidCore_OkdLightComponent_h__

#include	"Root.h"
#include	ORKID_CORE_H(Components/OkdAbstractComponent)

class OkdLightComponent: public OkdAbstractComponent
{
public:
			OkdLightComponent();
	virtual	~OkdLightComponent();

	OKD_MAKE_COMPONENT( OkdLightComponent, "LightComponent" )

private:
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif
