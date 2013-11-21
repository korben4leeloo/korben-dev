//*****************************************************************************
//
//	Class:		OkdAbstractResource
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdAbstractResource_h__
#define __OrkidEngine_OkdAbstractResource_h__

#include	"Root.h"

class OkdFileStream;

class OkdAbstractResource
{
public:
	virtual void	read( OkdFileStream* pStream )	= 0;
	virtual void	write( OkdFileStream* pStream )	= 0;

	//virtual OrkidResourceType	getResourceType() const = 0;

protected:
					OkdAbstractResource();
	virtual			~OkdAbstractResource();
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif