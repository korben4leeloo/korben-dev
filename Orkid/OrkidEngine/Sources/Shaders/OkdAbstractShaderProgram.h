//*****************************************************************************
//
//	Class:		OkdAbstractShaderProgram
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdAbstractShaderProgram_h__
#define __OrkidEngine_OkdAbstractShaderProgram_h__

#include	"Root.h"

#include	ORKID_ENGINE_H(Resources/OkdAbstractResource)

class OkdAbstractShaderProgram: public OkdAbstractResource
{
public:
	virtual void	build() = 0;

private:
					OkdAbstractShaderProgram();
					virtual ~OkdAbstractShaderProgram();

	//OkdVector<
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif