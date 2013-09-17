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
: _pRootNode		( 0 )
, _pResourceManager	( 0 )
{
	
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
// Name:		initialize
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdScene::initialize( const OkdString& strResourceManager )
{
	_pRootNode = new OkdNode();
}

//-----------------------------------------------------------------------------
// Name:		createNode
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdNode*	OkdScene::createNode( OkdNode* pParentNode )
{
	OkdNode* pNode = new OkdNode();

	if	( pParentNode )
	{
		pParentNode->addChildNode( pNode );
	}
	else
	{
		_pRootNode->addChildNode( pNode );
	}

	return	( pNode );
}

//-----------------------------------------------------------------------------
// Name:		createMesh
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdMesh*	OkdScene::createMesh( OkdNode* pParentNode )
{
	return	( 0 );
}
