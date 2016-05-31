//*****************************************************************************
//
//	File:		OkdMemManager.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdMemManager.h"

OkdMemManager* OkdMemManager::_pInstance = 0;

//void* operator new(size_t size)
//{									
//	return ::malloc( (uint)size );
//}

//void* operator new[](size_t size)
//{
//	return ::malloc( (uint)size );
//}

//void operator delete(void* ptr)
//{
//	::free( ptr );
//}

//void operator delete[](void* ptr)
//{
//	::free( ptr );
//}

//-----------------------------------------------------------------------------
// Name:		OkdMemManager constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdMemManager::OkdMemManager()
{

}

//-----------------------------------------------------------------------------
// Name:		OkdMemManager destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdMemManager::~OkdMemManager()
{
	
}
