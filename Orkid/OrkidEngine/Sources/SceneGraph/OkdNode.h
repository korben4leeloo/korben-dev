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
typedef OkdList<OkdNode*> OkdNodeList;

class OkdNode
{
public:
	friend class OkdScene;

							ORKID_ALIGNED_NEW( 16 )

	inline const OkdNode*	getParentNode() const;
	inline void				addChildNode( OkdNode* pChildNode );

private:
							OkdNode();
							~OkdNode();

	inline void				setParentNode( OkdNode* pParentNode );

	OkdMatrix4f				_mWorld;
	OkdMatrix4f				_mLocal;

	OkdNode*				_pParentNode;
	OkdNodeList				_childrenNodes;

	OkdEntity*				_pEntity;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		setParentNode
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdNode::setParentNode( OkdNode* pParentNode )
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
void	OkdNode::addChildNode(OkdNode *	pChildNode)
{
	_childrenNodes.add( pChildNode );
	pChildNode->setParentNode( this );
}

#endif