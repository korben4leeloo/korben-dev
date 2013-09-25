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

#include	<string>
#include	<functional>
//#include	<QtCore/QString>
//typedef QString OkdString;

class OkdString
{
public:
	friend class std::hash<OkdString>;
	friend class OkdFileStream;

						OkdString();
						OkdString( const char* pBuffer );
						~OkdString();

	void				replace( const OkdString& strSource, const OkdString& strTarget );

	//inline operator		QString() const;
	//inline operator		std::string() const;
	inline operator		const char*() const;
	//inline bool			operator==( const OkdString& left, const OkdString& right ) const;
	inline bool				operator==( const OkdString& other ) const;
	//friend inline OkdFileStream&	operator<<( OkdFileStream& stream, const OkdString& str );

	inline uint32		size() const;

private:
	//QString				_str;
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

////-----------------------------------------------------------------------------
//// Name:		operator std::string()
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//OkdString::operator std::string() const
//{
//	return	( _str );
//}

//-----------------------------------------------------------------------------
// Name:		operator const char*()
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdString::operator const char*() const
{
	return	( _str.data() );
}

////-----------------------------------------------------------------------------
//// Name:		operator QString()
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//OkdString::operator QString() const
//{
//	return	( _str );
//}

////-----------------------------------------------------------------------------
//// Name:		operator==
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//bool OkdString::operator==(const OkdString& left, 
//						   const OkdString& right) const
//{
//	return	( left._str == right._str );
//}

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
// Name:		operator==
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
uint32 OkdString::size() const
{
	return	( _str.size() );
}

//
////-----------------------------------------------------------------------------
//// Name:		operator==
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//OkdFileStream& OkdString::operator<<(OkdFileStream& stream) const
//{
//	stream << _str;
//}

////-----------------------------------------------------------------------------
//// Name:		operator<<
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//OkdFileStream& operator<<(OkdFileStream&	stream, 
//						  const OkdString&	str)
//{
//	//stream << str._str.;
//	stream.write( str._str.data(), str._str.size() );
//	return	( stream );
//}

#endif
