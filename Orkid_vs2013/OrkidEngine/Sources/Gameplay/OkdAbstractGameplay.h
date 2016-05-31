//*****************************************************************************
//
//	Class:		OkdAbstractGameplay
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdAbstractGameplay_h__
#define __OrkidEngine_OkdAbstractGameplay_h__

#include	"Root.h"

class OkdAbstractGameplay
{
public:
					OkdAbstractGameplay();
	virtual			~OkdAbstractGameplay();

	virtual void	update() = 0;

private:
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif