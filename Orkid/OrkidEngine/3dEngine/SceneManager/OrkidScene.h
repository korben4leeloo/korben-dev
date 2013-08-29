//*****************************************************************************
//
//	Class:		OrkidScene
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OrkidScene_h__
#define __OrkidEngine_OrkidScene_h__

class OrkidNode;

class OrkidScene
{
public:
				OrkidScene();
				~OrkidScene();

private:
	OrkidNode*	_pRootNode;
};

#endif