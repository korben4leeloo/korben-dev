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
	virtual void	create( const OkdResourcePtr& resourcePtr );
	virtual void	load( const OkdResourcePtr& resourcePtr );
	virtual void	unload( const OkdResourcePtr& resourcePtr );

private:
					OkdMeshHandler();
					~OkdMeshHandler();
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif