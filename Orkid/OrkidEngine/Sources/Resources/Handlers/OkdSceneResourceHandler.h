//*****************************************************************************
//
//	Class:		OkdSceneResourceHandler
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdSceneResourceHandler_h__
#define __OrkidEngine_OkdSceneResourceHandler_h__

#include	"Root.h"

#include	ORKID_ENGINE_H(Resources/Handlers/OkdResourceHandler)

class OkdScene;

class OkdSceneResourceHandler: public OkdResourceHandler<OkdScene, OrkidScene>
{
	friend class OkdResourceManager;

public:
	virtual void	readResource( OkdScene* pResource, OkdFileStream* pResourceFileStream );
	virtual void	writeResource( OkdScene* pResource, OkdFileStream* pResourceFileStream );

private:
					OkdSceneResourceHandler();
	virtual			~OkdSceneResourceHandler();
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif