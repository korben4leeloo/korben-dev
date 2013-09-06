//*****************************************************************************
//
//	Class:		OkdNode
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdNode_h__
#define __OrkidEngine_OkdNode_h__

#include	"OrkidNodesRoot.h"

#include	ORKID_CORE_H(Containers/OkdList)
#include	ORKID_CORE_H(Math/Geometry/OkdMatrix4f)

class OkdNode;
typedef OkdList<OkdNode*> OkdNodeList;

class OkdNode
{
public:
							OkdNode();
							~OkdNode();

	inline const OkdNode*	getParentNode() const;
	inline void				addChildNode( OkdNode* pChildNode );

private:
	inline void				setParentNode( OkdNode* pParentNode );

	OkdNode*				_pParentNode;
	OkdNodeList				_childrenNodes;

	OkdMatrix4f				_mWorld;
	OkdMatrix4f				_mLocal;
};

#endif