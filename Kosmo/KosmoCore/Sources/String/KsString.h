//*****************************************************************************
//
//	Class:		KsString
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __KosmoCore_KsString_h__
#define __KosmoCore_KsString_h__

#include	"Root.h"

KOSMO_CORE_NAMESPACE_BEGIN

class KsString
{
public:
						KsString( const char* pcData = "" );
						KsString( const KsString& other );
						~KsString();

	KsString&			operator=( const KsString& other );
	KsString&			operator=( const char* pcData );

	inline const char*	getData() const;
	inline uint32		getLength() const;

private:
	void				assign( const char* pcData );

	char*				_pcBuffer;
	uint32				_uiLength;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		getLength
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
uint32	KsString::getLength() const
{
	return	( _uiLength );
}

//-----------------------------------------------------------------------------
// Name:		getData
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const char*	KsString::getData() const
{
	return	( _pcBuffer );
}

KOSMO_CORE_NAMESPACE_END

#endif