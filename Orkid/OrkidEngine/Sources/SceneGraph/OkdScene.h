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

#include	ORKID_ENGINE_H(ResourceManager/OkdResourceManager)

class OkdNode;
class OkdMeshInstance;
class OkdString;

class OkdScene
{
public:
	friend class OrkidEngine;

	OkdNode*			createNode( OkdNode* pParentNode = 0 );
	OkdMeshInstance*	createMeshInstance( const OkdString& strMeshName, OkdNode* pNode = 0 );

private:
						OkdScene( OkdResourceManager* pResourceManager );
						~OkdScene();

	OkdResourceManager*	_pResourceManager;
	OkdNode*			_pRootNode;
};

#endif