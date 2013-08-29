//*****************************************************************************
//
//	Class:		OrkidNode
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OrkidNode_h__
#define __OrkidEngine_OrkidNode_h__

#include	<Containers/OrkidList.h>

class OrkidNode
{
public:
				OrkidNode();
				~OrkidNode();

private:
	OrkidList<OrkidNode*>	_childrenNodes;
};

#endif