//*****************************************************************************
//
//	Class:		KmComponentProperty
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __KosmoCore_KmComponentProperty_h__
#define __KosmoCore_KmComponentProperty_h__

#include	"Root.h"

#include	KOSMO_CORE_H(String/KmString)

KOSMO_CORE_NAMESPACE_BEGIN

class KmComponentProperty
{
public:
							KmComponentProperty( const KmString& propertyName );
							~KmComponentProperty();

	// Accessors
	inline const KmString&	getPropertyName() const;

private:
	KmString				_propertyName;
};

//*****************************************************************************
//	Inline methods declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		getPropertyName
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const KmString&	KmComponentProperty::getPropertyName() const
{
	return	( _propertyName );
}

KOSMO_CORE_NAMESPACE_END

#endif