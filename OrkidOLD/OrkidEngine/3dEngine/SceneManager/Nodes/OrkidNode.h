//*****************************************************************************
//
//	Class:		OrkidNode
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OrkidNode_h__
#define __OrkidEngine_OrkidNode_h__

#include	<Containers/OrkidList.h>
#include	<Math/OrkidMathCommon.h>

class OrkidNode;
typedef OrkidList<OrkidNode*> OrkidNodeList;

class OrkidNode
{
public:
							OrkidNode();
							~OrkidNode();

	inline void				setParentNode( OrkidNode* pParentNode );
	inline const OrkidNode*	getParentNode() const;

	inline void				addChildNode( OrkidNode* pChildNode );

private:
	OrkidNode*				_pParentNode;
	OrkidNodeList			_childrenNodes;
};

#endif