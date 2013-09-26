//*****************************************************************************
//
//	Class:		OkdMeshHandler
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdMeshHandler_h__
#define __OrkidEngine_OkdMeshHandler_h__

#include	"Root.h"

#include	ORKID_ENGINE_H(ResourceManager/ResourceHandler/OkdAbstractResourceHandler)


class OkdMeshHandler: public OkdAbstractResourceHandlerSingleton<OkdMeshHandler>
{
	FRIEND_RESOURCE_HANDLER_SINGLETON(OkdMeshHandler)

public:
	virtual void	load( OkdSharedResource* pResource );
	virtual void	unload( OkdSharedResource* pResource );

protected:
					OkdMeshHandler();
					~OkdMeshHandler();
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif