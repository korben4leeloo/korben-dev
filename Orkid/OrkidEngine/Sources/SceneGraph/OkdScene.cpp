//*****************************************************************************
//
//	File:		OkdScene.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdScene.h"

#include	ORKID_ENGINE_H(SceneGraph/OkdNode)
#include	ORKID_CORE_H(Stream/OkdFileStream)
#include	ORKID_ENGINE_H(OrkidEngine)
#include	ORKID_ENGINE_H(Entities/OkdEntityFactory)
#include	ORKID_ENGINE_H(Entities/OkdEntity)
#include	ORKID_ENGINE_H(Entities/OkdCamera)
#include	ORKID_ENGINE_H(Entities/OkdLight)
#include	ORKID_ENGINE_H(Entities/OkdShape)
#include	ORKID_ENGINE_H(Entities/OkdCreature)

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
OkdNode*	OkdScene::createNode(OkdNode*	pParentNode)
{
	OkdNode* pNode				= new OkdNode();
	OkdNode* pRealParentNode	= pParentNode ? pParentNode : _pRootNode;

	pRealParentNode->addChildNode( pNode );

	return	( pNode );
}

//-----------------------------------------------------------------------------
// Name:		createEntity
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdEntity*	OkdScene::createEntity(const OkdEntityType	eEntityType,
								   OkdNode*				pNode)
{
	OkdEntityFactory*	pEntityFactory	= OrkidEngine::instance()->getEntityFactory();
	OkdEntity*			pEntity			= pEntityFactory->createEntity( eEntityType );
	OkdNode*			pEntityNode		= pNode ? pNode : _pRootNode;

	pEntityNode->addEntity( pEntity );

	return	( pEntity );
}

//-----------------------------------------------------------------------------
// Name:		createCamera
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdCamera*	OkdScene::createCamera(OkdNode*	pNode)
{
	return	( static_cast<OkdCamera*>(createEntity( OrkidCamera, pNode ) ) );
}

//-----------------------------------------------------------------------------
// Name:		createLight
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdLight*	OkdScene::createLight(OkdNode*	pNode)
{
	return	( static_cast<OkdLight*>(createEntity( OrkidLight, pNode ) ) );
}

//-----------------------------------------------------------------------------
// Name:		createShape
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdShape*	OkdScene::createShape(OkdNode*	pNode)
{
	return	( static_cast<OkdShape*>(createEntity( OrkidShape, pNode ) ) );
}

//-----------------------------------------------------------------------------
// Name:		createCreature
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdCreature*	OkdScene::createCreature(OkdNode*	pNode)
{
	return	( static_cast<OkdCreature*>(createEntity( OrkidCreature, pNode ) ) );
}

//-----------------------------------------------------------------------------
// Name:		read
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdScene::read(OkdFileStream* pStream)
{
	readNode( pStream, _pRootNode );
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
	const OkdEntityList&			entityList		= pNode->getEntityList();
	OkdEntityList::const_iterator	itEntity		= entityList.begin();
	OkdEntityList::const_iterator	itEntityEnd		= entityList.end();
	uint32							uiEntityCount	= entityList.size();

	stream << uiEntityCount;

	while	( itEntity != itEntityEnd )
	{
		OkdEntity* pEntity = *itEntity;

		stream << pEntity->getEntityType();
		pEntity->write( pStream );
		itEntity++;
	}

	// Write child nodes
	const OkdNodeList&			nodeList	= pNode->getNodeList();
	OkdNodeList::const_iterator	itNode		= nodeList.begin();
	OkdNodeList::const_iterator	itNodeEnd	= nodeList.end();
	uint32						uiNodeCount	= nodeList.size();

	stream << uiNodeCount;

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

	// Read entities
	uint32 uiEntityCount;

	stream >> uiEntityCount;

	for	( uint32 i = 0; i < uiEntityCount; i++ )
	{
		OkdEntityType eEntityType;
		stream >> (unsigned int&)eEntityType;

		OkdEntity* pEntity = createEntity( eEntityType, pNode );
		pEntity->read( pStream );
	}

	// Write child nodes
	uint32 uiNodeCount;

	stream >> uiNodeCount;

	for	( uint32 i = 0; i < uiNodeCount; i++ )
	{
		OkdNode* pChildNode = createNode( pNode );
		readNode( pStream, pChildNode );
	}
}
