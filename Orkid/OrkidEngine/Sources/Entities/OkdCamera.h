//*****************************************************************************
//
//	Class:		OkdCamera
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdCamera_h__
#define __OrkidEngine_OkdCamera_h__

#include	"Root.h"

#include	ORKID_ENGINE_H(Entities/OkdEntity)

class OkdFileStream;

class OkdCamera: public OkdEntity
{
	friend class OkdEntityFactory;

public:
	virtual void	read( OkdFileStream* pStream );
	virtual void	write( OkdFileStream* pStream );

private:
					OkdCamera();
	virtual			~OkdCamera();
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif