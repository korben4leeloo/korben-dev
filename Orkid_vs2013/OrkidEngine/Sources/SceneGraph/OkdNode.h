//*****************************************************************************
//
//	Class:		OkdNode
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdNode_h__
#define __OrkidEngine_OkdNode_h__

#include	"Root.h"

#include	ORKID_CORE_H(Containers/OkdList)
#include	ORKID_CORE_H(Math/OkdMatrix4f)

class OkdEntity;
class OkdNode;

typedef OkdList<OkdNode*>	OkdNodeList;
typedef OkdList<OkdEntity*>	OkdEntityList;

class OkdNode
{
public:
	friend class OkdScene;

								ORKID_ALIGNED_NEW( 16 )

	inline const OkdNode*		getParentNode() const;
	inline void					addChildNode( OkdNode* pChildNode );
	inline void					removeChildNode( OkdNode* pChildNode );
	inline uint32				getChildCount() const;
	inline const OkdNodeList&	getNodeList() const;

	inline void					addEntity( OkdEntity* pEntity );
	inline uint32				getEntityCount() const;
	inline const OkdEntityList&	getEntityList() const;

	inline const OkdMatrix4f&	getWorldTransform() const;

	inline void					setLocalTransform( const OkdMatrix4f& mTransform);
	inline const OkdMatrix4f&	getLocalTransform() const;

private:
								OkdNode();
								~OkdNode();

	inline void					setParentNode( OkdNode* pParentNode );

	OkdMatrix4f					_mWorld;
	OkdMatrix4f					_mLocal;

	OkdNode*					_pParentNode;
	OkdNodeList					_childrenNodes;
	OkdEntityList				_entities;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		setParentNode
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdNode::setParentNode(OkdNode*	pParentNode)
{
	_pParentNode = pParentNode;
}

//-----------------------------------------------------------------------------
// Name:		getParentNode
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const OkdNode*	OkdNode::getParentNode() const
{
	return	( _pParentNode );
}

//-----------------------------------------------------------------------------
// Name:		addChildNode
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdNode::addChildNode(OkdNode*	pChildNode)
{
	_childrenNodes.add( pChildNode );
	pChildNode->setParentNode( this );
}

//-----------------------------------------------------------------------------
// Name:		removeChildNode
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdNode::removeChildNode(OkdNode*	pChildNode)
{
	_childrenNodes.remove( pChildNode );
	pChildNode->setParentNode( 0 );
}

//-----------------------------------------------------------------------------
// Name:		getChildCount
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
uint32	OkdNode::getChildCount() const
{
	return	( _childrenNodes.size() );
}

//-----------------------------------------------------------------------------
// Name:		getNodeList
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const OkdNodeList&	OkdNode::getNodeList() const
{
	return	( _childrenNodes );
}

//-----------------------------------------------------------------------------
// Name:		addEntity
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdNode::addEntity(OkdEntity*	pEntity)
{
	_entities.add( pEntity );
}

//-----------------------------------------------------------------------------
// Name:		getEntityCount
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
uint32	OkdNode::getEntityCount() const
{
	return	( _entities.size() );
}


//-----------------------------------------------------------------------------
// Name:		getEntityList
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const OkdEntityList&	OkdNode::getEntityList() const
{
	return	( _entities );
}

//-----------------------------------------------------------------------------
// Name:		getWorldTransform
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const OkdMatrix4f&	OkdNode::getWorldTransform() const
{
	return	( _mWorld );
}

//-----------------------------------------------------------------------------
// Name:		setLocalTransform
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdNode::setLocalTransform(const OkdMatrix4f&	mTransform)
{
	_mLocal = mTransform;
}

//-----------------------------------------------------------------------------
// Name:		getLocalTransform
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const OkdMatrix4f&	OkdNode::getLocalTransform() const
{
	return	( _mLocal );
}

#endif