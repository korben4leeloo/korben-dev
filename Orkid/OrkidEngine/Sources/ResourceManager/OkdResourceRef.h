//*****************************************************************************
//
//	Class:		OkdResourceRef
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdResourceRef_h__
#define __OrkidEngine_OkdResourceRef_h__

#include	"Root.h"

#include	ORKID_CORE_H(String/OkdString)

template<class T>
class OkdResourceRef
{
public:

private:
				OkdResourceRef();
				~OkdResourceRef();

	uint32		_uiRefCount;
	uint32		_uiLoadRefCount;
	T*			_pData;
	OkdString	_strResourceName;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif