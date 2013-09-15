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
//#include	<QtCore/QString>
//typedef QString OkdString;

class OkdString
{
public:
						OkdString();
						OkdString( const char* pBuffer );
						~OkdString();

	inline const char*	toChar() const;

	void				replace( const OkdString& strSource, const OkdString& strTarget );

	//inline operator		QString() const;
	inline operator		std::string() const;

private:
	//QString				_str;
	std::string			_str;
};

////*****************************************************************************
////	Inline functions declarations
////*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		toChar
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const char* OkdString::toChar() const
{
	return	( _str.data() );
}

//-----------------------------------------------------------------------------
// Name:		operator QString()
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdString::operator std::string() const
{
	return	( _str );
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
