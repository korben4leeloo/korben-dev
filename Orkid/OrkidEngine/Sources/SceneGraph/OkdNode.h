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

	inline const OkdNode*	getParentNode() const;
	inline void				addChildNode( OkdNode* pChildNode );

private:
							OkdNode();
							~OkdNode();

	inline void				setParentNode( OkdNode* pParentNode );

	OkdNode*				_pParentNode;
	OkdNodeList				_childrenNodes;

	OkdEntity*				_pEntity;

	OkdMatrix4f				_mWorld;
	OkdMatrix4f				_mLocal;
};

#endif