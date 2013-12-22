//*****************************************************************************
//
//	File:		OkdCreature.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdCreature.h"

//-----------------------------------------------------------------------------
// Name:		OkdCreature constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdCreature::OkdCreature()
: OkdEntity( OrkidCreature )
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdCreature destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdCreature::~OkdCreature()
{
	
}

//-----------------------------------------------------------------------------
// Name:		read
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdCreature::read(OkdFileStream* pStream)
{
	OkdString strMeshResourceName;

	(*pStream) >> strMeshResourceName;
	//_meshPtr = OkdResourceManager::addMesh( strMeshResourceName );
	_meshPtr = OkdResourceManager::addMesh( strMeshResourceName );
}

//-----------------------------------------------------------------------------
// Name:		write
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdCreature::write(OkdFileStream* pStream)
{
	(*pStream) << _meshPtr.getResourceName();
}
