//*****************************************************************************
//
//	File:		OkdScene.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdScene.h"

#include	ORKID_ENGINE_H(SceneGraph/OkdNode)
#include	ORKID_CORE_H(Stream/OkdFileStream)

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
// Name:		read
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdScene::read(OkdFileStream* pStream)
{
	
}

//-----------------------------------------------------------------------------
// Name:		write
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdScene::write(OkdFileStream* pStream)
{
	writeNode( pStream, _pRootNode );
}

//-----------------------------------------------------------------------------
// Name:		write
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdScene::writeNode(OkdFileStream*	pStream, 
							OkdNode*		pNode)
{
	OkdFileStream&		stream	= *pStream;
	const OkdMatrix4f&	mLocal	= pNode->getLocalTransform();

	stream << mLocal;
}

