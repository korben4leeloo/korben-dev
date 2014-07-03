//*****************************************************************************
//
//	Class:		KmString
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __KosmoCore_KmString_h__
#define __KosmoCore_KmString_h__

#include	"Root.h"

KOSMO_CORE_NAMESPACE_BEGIN

class KmString
{
public:
						KmString( const char* pcData = "" );
						KmString( const KmString& other );
						KmString( KmString&& other );
						~KmString();

	// Accessors
	inline const char*	getData() const;
	inline uint32		getLength() const;

	// Operators
	KmString&			operator=( const KmString& other );
	KmString&			operator=( KmString&& other );
	inline KmString&	operator=( const char* pcData );

	inline KmString&	operator+=( const KmString& other );
	inline KmString&	operator+=( const char* pcData );

	// String operations
	inline void			copy( const KmString& other );
	void				copy( const char* pcData );

	inline void			append( const KmString& other );
	void				append( const char* pcData );

	static KmString		join( const char* pcSourceData1, const char* pcSourceData2 );

	// Static members
	static KmString		_nullString;
	static KmString		_emptyString;

private:
	char*				_pcBuffer;
	uint32				_uiLength;
};

//*****************************************************************************
//	Inline methods declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		getLength
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
uint32	KmString::getLength() const
{
	return	( _uiLength );
}

//-----------------------------------------------------------------------------
// Name:		getData
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const char*	KmString::getData() const
{
	return	( _pcBuffer );
}

//-----------------------------------------------------------------------------
// Name:		copy
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	KmString::copy(const KmString&	other)
{
	copy( other.getData() );
}

//-----------------------------------------------------------------------------
// Name:		append
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	KmString::append(const KmString&	other)
{
	append( other.getData() );
}

//-----------------------------------------------------------------------------
// Name:		operator=
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KmString& KmString::operator=(const char*	pcData)
{
	copy( pcData );
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator+=
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KmString& KmString::operator+=(const KmString&	other)
{
	append( other.getData() );
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator+=
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
KmString& KmString::operator+=(const char*	pcData)
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
inline KmString operator+(const KmString&	lhs,
						  const KmString&	rhs)
{
	KmString result = KmString::join( lhs.getData(), rhs.getData() );
	return	( result );
}

//-----------------------------------------------------------------------------
// Name:		operator+
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline KmString operator+(const KmString&	other,
						  const char*		pcData)
{
	KmString result = KmString::join( other.getData(), pcData );
	return	( result );
}

//-----------------------------------------------------------------------------
// Name:		operator+
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
inline KmString operator+(const char*		pcData,
						  const KmString&	other)
{
	KmString result = KmString::join( pcData, other.getData() );
	return	( result );
}

KOSMO_CORE_NAMESPACE_END

#endif