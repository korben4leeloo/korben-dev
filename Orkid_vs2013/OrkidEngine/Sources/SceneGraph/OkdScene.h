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
//#include	ORKID_ENGINE_H(Resources/OkdResourcePtr)

class OkdNode;
class OkdMeshInstance;
class OkdString;
class OkdEntity;
class OkdCamera;
class OkdLight;
class OkdShape;
class OkdCreature;

//template<class T> class OkdResourceAllocator;
template<class T> class OkdDefaultResourceAllocator;

class OkdScene: public OkdAbstractResource
{
public:
	friend class OkdResourceManager;
	//friend class OkdResourceAllocator<OkdScene>;
	friend class OkdDefaultResourceAllocator<OkdScene>;

					ORKID_RESOURCE( OrkidScene )

	inline OkdNode*	getRootNode();

	OkdNode*		createNode( OkdNode* pParentNode = 0 );

	OkdCamera*		createCamera( OkdNode* pNode = 0 );
	OkdLight*		createLight( OkdNode* pNode = 0 );
	OkdShape*		createShape( OkdNode* pNode = 0 );
	OkdCreature*	createCreature( OkdNode* pNode = 0 );

	// OkdAbstractResource implementation
	virtual void	read( OkdFileStream* pStream );
	virtual void	write( OkdFileStream* pStream );

private:
					OkdScene();
					~OkdScene();

	OkdEntity*		createEntity( const OkdEntityType eEntityType, OkdNode* pNode = 0 );

	void			writeNode( OkdFileStream* pStream, OkdNode* pNode );
	void			readNode( OkdFileStream* pStream, OkdNode* pNode );

	OkdNode*		_pRootNode;
};

typedef OkdResourcePtr<OkdScene> OkdScenePtr;

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