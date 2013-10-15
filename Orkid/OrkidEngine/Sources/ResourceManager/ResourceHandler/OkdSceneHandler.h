//*****************************************************************************
//
//	Class:		OkdSceneHandler
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdSceneHandler_h__
#define __OrkidEngine_OkdSceneHandler_h__

#include	"Root.h"

#include	ORKID_ENGINE_H(ResourceManager/ResourceHandler/OkdAbstractResourceHandler)


//class OkdSceneHandler: public OkdAbstractResourceHandlerSingleton<OkdSceneHandler>
//{
//	FRIEND_RESOURCE_HANDLER_SINGLETON(OkdSceneHandler)
//
//public:
//	virtual void	load( OkdResourceHandle* pResource );
//	virtual void	unload( OkdResourceHandle* pResource );
//
//protected:
//					OkdSceneHandler();
//					~OkdSceneHandler();
//};

class OkdSceneHandler: public OkdAbstractResourceHandler
{
	friend class OkdResourceManager;

public:
	virtual void	createResource( const OkdResourceId& resourceId );
	virtual void	loadResource( const OkdResourcePtr& resourcePtr );
	virtual void	unloadResource( const OkdResourcePtr& resourcePtr );
	virtual void	saveResource( const OkdResourcePtr& resourcePtr );

private:
					OkdSceneHandler();
	virtual			~OkdSceneHandler();
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif