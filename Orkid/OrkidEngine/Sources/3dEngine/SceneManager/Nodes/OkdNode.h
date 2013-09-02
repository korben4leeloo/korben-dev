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
#include	<Math/OkdMathCommon.h>

class OkdNode;
typedef OkdList<OkdNode*> OkdNodeList;

class OkdNode
{
public:
							OkdNode();
							~OkdNode();

	inline void				setParentNode( OkdNode* pParentNode );
	inline const OkdNode*	getParentNode() const;

	inline void				addChildNode( OkdNode* pChildNode );

private:
	OkdNode*				_pParentNode;
	OkdNodeList			_childrenNodes;
};

#endif