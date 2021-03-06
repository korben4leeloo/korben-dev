//*****************************************************************************
//
//	Class:		OkdFreeCameraGameplay
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdFreeCameraGameplay_h__
#define __OrkidEngine_OkdFreeCameraGameplay_h__

#include	"Root.h"
#include	ORKID_ENGINE_H(Gameplay/OkdAbstractGameplay)

class OkdCamera;

class OkdFreeCameraGameplay: public OkdAbstractGameplay
{
public:
					OkdFreeCameraGameplay();
					~OkdFreeCameraGameplay();

	virtual void	update();

	inline void		setCamera( OkdCamera* pCamera );

private:
	OkdCamera*		_pCamera;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		setCamera
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdFreeCameraGameplay::setCamera(OkdCamera*	pCamera)
{
	_pCamera = pCamera;
}

#endif