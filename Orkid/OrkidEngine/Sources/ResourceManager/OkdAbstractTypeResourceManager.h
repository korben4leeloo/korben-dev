//*****************************************************************************
//
//	Class:		OkdAbstractTypeResourceManager
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdAbstractTypeResourceManager_h__
#define __OrkidEngine_OkdAbstractTypeResourceManager_h__

#include	"Root.h"

class OkdAbstractTypeResourceManager
{
public:
						OkdAbstractTypeResourceManager( const OrkidResourceType eResType );
	virtual				~OkdAbstractTypeResourceManager();

protected:
	OrkidResourceType	_resourceType;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif