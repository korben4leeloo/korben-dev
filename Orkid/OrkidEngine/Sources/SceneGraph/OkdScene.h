//*****************************************************************************
//
//	Class:		OkdScene
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdScene_h__
#define __OrkidEngine_OkdScene_h__

#include	"Root.h"

#include	ORKID_ENGINE_H(Resources/OkdAbstractResource)

class OkdNode;
class OkdMeshInstance;
class OkdString;

class OkdScene: public OkdAbstractResource
{
public:
	template<class T> friend class OkdResourceRef;

	inline OkdNode*		getRootNode();

	OkdNode*			createNode( OkdNode* pParentNode = 0 );

	// OkdAbstractResource implementation
	virtual void		read( OkdFileStream* pStream );
	virtual void		write( OkdFileStream* pStream );

private:
						OkdScene();
						~OkdScene();

	OkdNode*			_pRootNode;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		getRootNode
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdNode*	OkdScene::getRootNode()
{
	return	( _pRootNode );
}

#endif