//*****************************************************************************
//
//	Class:		OkdScene
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdScene_h__
#define __OrkidEngine_OkdScene_h__

#include	"Root.h"

class OkdNode;
class OkdMesh;

class OkdScene
{
public:
				OkdScene();
				~OkdScene();

	OkdNode*	createNode( OkdNode* pParentNode = 0 );
	OkdMesh*	createMesh( OkdNode* pNode = 0 );

private:
	OkdNode*	_pRootNode;
};

#endif