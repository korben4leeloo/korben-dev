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

#include	ORKID_ENGINE_H(Resources/OkdResourceManager)

class OkdNode;
class OkdMeshInstance;
class OkdString;

class OkdScene
{
public:
	template<class T> friend class OkdResourceRef;

	inline OkdNode*		getRootNode();

	OkdNode*			createNode( OkdNode* pParentNode = 0 );
	OkdMeshInstance*	createMeshInstance( const OkdString& strMeshName, OkdNode* pNode = 0 );

private:
						OkdScene();
						~OkdScene();

	OkdNode*			_pRootNode;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		getRootNode
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdNode*	OkdScene::getRootNode()
{
	return	( _pRootNode );
}

#endif