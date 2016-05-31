//*****************************************************************************
//
//	Class:		OkdMeshComponent
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdMeshComponent_h__
#define __OrkidCore_OkdMeshComponent_h__

#include	"Root.h"
#include	ORKID_CORE_H(Framework/OkdAbstractComponent)

class OkdMeshComponent: public OkdAbstractComponent
{
public:
			OkdMeshComponent();
	virtual	~OkdMeshComponent();

	OKD_MAKE_COMPONENT( OkdMeshComponent, "MeshComponent" )

private:
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif
