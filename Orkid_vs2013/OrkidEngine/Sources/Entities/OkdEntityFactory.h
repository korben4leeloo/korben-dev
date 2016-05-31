////*****************************************************************************
////
////	Class:		OkdEntityFactory
////
////	Created:	2013-08-26
////
////*****************************************************************************
//
//#ifndef __OrkidEngine_OkdEntityFactory_h__
//#define __OrkidEngine_OkdEntityFactory_h__
//
//#include	"Root.h"
//
//class OkdEntity;
//
//class OkdEntityFactory
//{
//	friend class OrkidEngine;
//
//public:
//	OkdEntity*					createEntity( const OkdEntityType eEntityType );
//
//private:
//	typedef OkdEntity* (*pfnEntityCreator)();
//
//								OkdEntityFactory();
//								~OkdEntityFactory();
//
//	template<class T>
//	static inline OkdEntity*	entityCreator();
//
//	static pfnEntityCreator		_pfnEntityCreators[OrkidEntityTypeCount];
//};
//
////*****************************************************************************
////	Inline functions declarations
////*****************************************************************************
//
////-----------------------------------------------------------------------------
//// Name:		entityCreator
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//template<class T>
//OkdEntity*	OkdEntityFactory::entityCreator()
//{
//	return	( new T() );
//}
//
//#endif