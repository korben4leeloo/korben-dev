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
	virtual void	createResource( const OkdResourceId& resourceId );
	virtual void	loadResource( const OkdResourcePtr& resourcePtr );
	virtual void	unloadResource( const OkdResourcePtr& resourcePtr );
	virtual void	saveResource( const OkdResourcePtr& resourcePtr );

private:
					OkdMeshHandler();
	virtual			~OkdMeshHandler();
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif