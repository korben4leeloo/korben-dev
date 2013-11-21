//*****************************************************************************
//
//	Class:		OkdString
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdString_h__
#define __OrkidCore_OkdString_h__

#include	"Root.h"

#include	ORKID_CORE_H(Stream/OkdFileStream)
#include	ORKID_CORE_H(Containers/OkdVector)

#include	<string>
#include	<functional>

class OkdString
{
public:
	friend class std::hash<OkdString>;
	friend class OkdFileStream;

						OkdString();
						OkdString( const char* pBuffer );
						OkdString( const std::string& s );
						~OkdString();

	void				replace( const OkdString& strSource, const OkdString& strTarget );
	void				split( const OkdString& strDelimiter, OkdVector<OkdString>& outTokens );

	inline operator		const char*() const;
	inline bool			operator==( const OkdString& other ) const;
	inline OkdString&	operator+=( const OkdString& other );
	inline OkdString	operator+( const OkdString& other );

	inline uint32		size() const;
	inline bool			isEmpty() const;

private:
	std::string			_str;
};

// Defines std::hash for OkdString to be used in std hashed containers
namespace std
{
	template<>
	class hash<OkdString>
	{
	public:
		std::size_t operator()(const OkdString& s) const 
		{
			std::size_t h = std::hash<std::string>()(s._str);
			return	( h );
		}
	};
}

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		operator const char*()
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdString::operator const char*() const
{
	return	( _str.data() );
}

//-----------------------------------------------------------------------------
// Name:		operator==
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
bool OkdString::operator==(const OkdString& other) const
{
	return	( _str == other._str );
}

//-----------------------------------------------------------------------------
// Name:		operator+=
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdString& OkdString::operator+=(const OkdString& other)
{
	_str += other._str;
	return	( *this );
}

//-----------------------------------------------------------------------------
// Name:		operator+
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdString OkdString::operator+(const OkdString& other)
{
	OkdString strTemp( _str + other._str );
	return	( strTemp );
}

//-----------------------------------------------------------------------------
// Name:		size
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
uint32 OkdString::size() const
{
	return	( _str.size() );
}

//-----------------------------------------------------------------------------
// Name:		isEmpty
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
bool OkdString::isEmpty() const
{
	return	( size() == 0 );
}

#endif
