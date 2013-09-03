//*****************************************************************************
//
//	Class:		OkdNode
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdNode_h__
#define __OrkidEngine_OkdNode_h__

#include	<Containers/OkdList.h>
#include	<Math/Geometry/OkdMatrix4f.h>

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