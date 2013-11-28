//*****************************************************************************
//
//	File:		OkdScene.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdScene.h"

#include	ORKID_ENGINE_H(SceneGraph/OkdNode)
#include	ORKID_CORE_H(Stream/OkdFileStream)
#include	ORKID_ENGINE_H(Entities/OkdEntity)

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
// Name:		writeNode
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdScene::writeNode(OkdFileStream*	pStream, 
							OkdNode*		pNode)
{
	OkdFileStream&		stream	= *pStream;
	const OkdMatrix4f&	mLocal	= pNode->getLocalTransform();

	stream << mLocal;

	// Write entities
	const OkdEntityList&			entityList	= pNode->getEntityList();
	OkdEntityList::const_iterator	itEntity	= entityList.begin();
	OkdEntityList::const_iterator	itEntityEnd	= entityList.end();

	while	( itEntity != itEntityEnd )
	{
		(*itEntity)->write( pStream );
		itEntity++;
	}

	// Write child nodes
	const OkdNodeList&			nodeList	= pNode->getNodeList();
	OkdNodeList::const_iterator	itNode		= nodeList.begin();
	OkdNodeList::const_iterator	itNodeEnd	= nodeList.end();

	while	( itNode != itNodeEnd )
	{
		writeNode( pStream, *itNode );
		itNode++;
	}
}

//-----------------------------------------------------------------------------
// Name:		readNode
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdScene::readNode(OkdFileStream*	pStream, 
						   OkdNode*			pNode)
{
	OkdFileStream&	stream = *pStream;
	OkdMatrix4f		mLocal;

	stream >> mLocal;

	//// Write entities
	//const OkdEntityList&			entityList	= pNode->getEntityList();
	//OkdEntityList::const_iterator	itEntity	= entityList.begin();
	//OkdEntityList::const_iterator	itEntityEnd	= entityList.end();

	//while	( itEntity != itEntityEnd )
	//{
	//	(*itEntity)->write( pStream );
	//	itEntity++;
	//}

	//// Write child nodes
	//const OkdNodeList&			nodeList	= pNode->getNodeList();
	//OkdNodeList::const_iterator	itNode		= nodeList.begin();
	//OkdNodeList::const_iterator	itNodeEnd	= nodeList.end();

	//while	( itNode != itNodeEnd )
	//{
	//	writeNode( pStream, *itNode );
	//	itNode++;
	//}
}
