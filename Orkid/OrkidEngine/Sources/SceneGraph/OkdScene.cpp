//*****************************************************************************
//
//	File:		OkdScene.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdScene.h"

#include	ORKID_ENGINE_H(SceneGraph/OkdNode)

//-----------------------------------------------------------------------------
// Name:		OkdScene constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdScene::OkdScene()
{
	_pRootNode = new OkdNode();
}

//-----------------------------------------------------------------------------
// Name:		OkdScene destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdScene::~OkdScene()
{

}

//-----------------------------------------------------------------------------
// Name:		createNode
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdNode*	OkdScene::createNode( OkdNode* pParentNode )
{
	OkdNode* pNode				= new OkdNode();
	OkdNode* pRealParentNode	= pParentNode ? pParentNode : _pRootNode;

	pRealParentNode->addChildNode( pNode );

	return	( pNode );
}

//-----------------------------------------------------------------------------
// Name:		createMesh
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdMeshInstance*	OkdScene::createMeshInstance(const OkdString&	strMeshName, 
												 OkdNode*			pParentNode)
{
	return	( 0 );
}
