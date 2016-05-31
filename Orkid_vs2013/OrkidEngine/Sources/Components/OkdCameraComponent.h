//*****************************************************************************
//
//	Class:		OkdCameraComponent
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdCameraComponent_h__
#define __OrkidCore_OkdCameraComponent_h__

#include	"Root.h"
#include	ORKID_CORE_H(Framework/OkdAbstractComponent)

class OkdCameraComponent: public OkdAbstractComponent
{
public:
			OkdCameraComponent();
	virtual	~OkdCameraComponent();

	OKD_MAKE_COMPONENT( OkdCameraComponent, "CameraComponent" )

private:
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif
