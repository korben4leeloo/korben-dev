//*****************************************************************************
//
//	Class:		OkdMeshResourceHandler
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdMeshResourceHandler_h__
#define __OrkidEngine_OkdMeshResourceHandler_h__

#include	"Root.h"

#include	ORKID_ENGINE_H(Resources/Handlers/OkdResourceHandler)

class OkdMesh;


//class OkdMeshHandler: public OkdAbstractResourceHandlerSingleton<OkdMeshHandler>
//{
//	FRIEND_RESOURCE_HANDLER_SINGLETON(OkdMeshHandler)
//
//public:
//	virtual void	load( OkdResourceHandle* pResource );
//	virtual void	unload( OkdResourceHandle* pResource );
//
//protected:
//					OkdMeshHandler();
//					~OkdMeshHandler();
//};

class OkdMeshResourceHandler: public OkdResourceHandler<OkdMesh, OrkidMesh>
{
	friend class OkdResourceManager;

public:

private:
			OkdMeshResourceHandler();
	virtual	~OkdMeshResourceHandler();
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif