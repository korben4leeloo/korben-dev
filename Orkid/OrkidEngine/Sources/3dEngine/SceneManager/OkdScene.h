//*****************************************************************************
//
//	Class:		OkdScene
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdScene_h__
#define __OrkidEngine_OkdScene_h__

class OrkidNode;

class OkdScene
{
public:
				OkdScene();
				~OkdScene();

private:
	OrkidNode*	_pRootNode;
};

#endif