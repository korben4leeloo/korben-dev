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
						KsString( KsString&& other );
						~KsString();

	// Accessors
	inline const char*	getData() const;
	inline uint32		getLength() const;

	// Operators
	KsString&			operator=( const KsString& other );
	KsString&			operator=( KsString&& other );
	inline KsString&	operator=( const char* pcData );

	inline KsString&	operator+=( const KsString& other );
	inline KsString&	operator+=( const char* pcData );

	// String operations
	inline void			copy( const KsString& other );
	void				copy( const char* pcData );

	inline void			append( const KsString& other );
	void				append( const char* pcData );

	static KsString		join( const char* pcSourceData1, const char* pcSourceData2 );

	// Static members
	static KsString		_nullString;
	static KsString		_emptyString;

private:
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

//-----------------------------------------------------------------------------
// Name:		copy
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	KsString::copy(const KsString&	other)
{
	copy( other.getData() );
}

//-----------------------------------------------------------------------------
// Name:		append
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	KsString::append(const KsString&	other)
{
	append( other.getData() );
}

//-----------------------------------------------------------------------------
// Name:		operator=
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KsString& KsString::operator=(const char*	pcData)
{
	copy( pcData );
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator+=
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KsString& KsString::operator+=(const KsString&	other)
{
	append( other.getData() );
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator+=
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KsString& KsString::operator+=(const char*	pcData)
{
	append( pcData );
	return	( *this );
}

//*****************************************************************************
//	Global functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		operator+
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline KsString operator+(const KsString&	lhs,
						  const KsString&	rhs)
{
	KsString result = KsString::join( lhs.getData(), rhs.getData() );
	return	( result );
}

//-----------------------------------------------------------------------------
// Name:		operator+
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline KsString operator+(const KsString&	other,
						  const char*		pcData)
{
	KsString result = KsString::join( other.getData(), pcData );
	return	( result );
}

//-----------------------------------------------------------------------------
// Name:		operator+
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline KsString operator+(const char*		pcData,
						  const KsString&	other)
{
	KsString result = KsString::join( pcData, other.getData() );
	return	( result );
}

KOSMO_CORE_NAMESPACE_END

#endif