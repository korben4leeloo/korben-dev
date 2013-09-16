//*****************************************************************************
//
//	Class:		OkdEntity
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdEntity_h__
#define __OrkidEngine_OkdEntity_h__

#include	"Root.h"

class OkdNode;

class OkdEntity
{
public:

protected:
				OkdEntity();
				virtual ~OkdEntity();

private:
	OkdNode*	_pNode;
};

#endif