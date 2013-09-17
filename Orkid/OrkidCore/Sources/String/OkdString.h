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

#include	<string>
#include	<functional>
//#include	<QtCore/QString>
//typedef QString OkdString;

class OkdString
{
public:
	friend class std::hash<OkdString>;

						OkdString();
						OkdString( const char* pBuffer );
						~OkdString();

	void				replace( const OkdString& strSource, const OkdString& strTarget );

	//inline operator		QString() const;
	//inline operator		std::string() const;
	inline operator		const char*() const;

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

#endif
