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

class OkdMeshHandler: public OkdAbstractResourceHandler
{
	friend class OkdResourceManager;

public:
	virtual void*	allocateResource();
	virtual void	freeResource( void* pResource );

	virtual void	loadResource( void* pResource, const void* pResourceData );
	virtual void	unloadResource( void* pResource );
	virtual void	saveResource( const void* pResource, void* pResourceData );

private:
					OkdMeshHandler();
	virtual			~OkdMeshHandler();
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif