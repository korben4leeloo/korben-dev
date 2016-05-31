//*****************************************************************************
//
//	Class:		KmComponent
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __KosmoCore_KmComponent_h__
#define __KosmoCore_KmComponent_h__

#include	"Root.h"

#include	KOSMO_CORE_H(String/KmString)
#include	KOSMO_CORE_H(Containers/KmList)

KOSMO_CORE_NAMESPACE_BEGIN

class KmComponentProperty;

class KmComponent
{
public:
									KmComponent( const KmString& componentName );
									~KmComponent();

	// Accessors
	inline const KmString&			getName() const;

private:
	KmString						_componentName;
	KmList<KmComponentProperty*>	_propertyList;
};

//*****************************************************************************
//	Inline methods declarations
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		getName
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const KmString&	KmComponent::getName() const
{
	return	( _componentName );
}

KOSMO_CORE_NAMESPACE_END

#endif