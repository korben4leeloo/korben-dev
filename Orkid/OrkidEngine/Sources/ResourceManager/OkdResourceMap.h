//*****************************************************************************
//
//	Class:		OkdResourceMap
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdResourceMap_h__
#define __OrkidEngine_OkdResourceMap_h__

#include	"Root.h"

#include	ORKID_CORE_H(Containers/OkdVector)
#include	ORKID_CORE_H(Containers/OkdList)

class OkdAbstractResourceHandler;
class OkdResourceHandle;

class OkdResourceMap
{
public:
									OkdResourceMap( OkdAbstractResourceHandler* pResourceHandler );
									~OkdResourceMap();

private:
	OkdAbstractResourceHandler*		_pResourceHandler;
	OkdVector<OkdResourceHandle*>	_resourceHandleArray;
	OkdList<uint32>					_freeResourceIndexList;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif