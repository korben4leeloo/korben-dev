//*****************************************************************************
//
//	Class:		OkdCrc32
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdCrc32_h__
#define __OrkidCore_OkdCrc32_h__

#include	"Root.h"

class OkdString;

class OkdCrc32
{
public:
	static uint32	getCrc32( const OkdString& strBuffer );
	static uint32	getCrc32( const void* pBuffer, const uint32 uiBufferSize );

private:
					OkdCrc32();
					~OkdCrc32();

	static uint32	computeCrc32( const uint8 uiByte, const uint32 uiInputCrc32 );

	static uint32	_crcTable[];
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif
