//*****************************************************************************
//
//	File:		OkdShape.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdShape.h"

#include	ORKID_ENGINE_H(Resources/OkdResourceManager)
#include	ORKID_ENGINE_H(Entities/OkdMesh)

//-----------------------------------------------------------------------------
// Name:		OkdShape constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdShape::OkdShape()
: OkdEntity( OrkidShape )
{
	
}

//-----------------------------------------------------------------------------
// Name:		OkdShape destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdShape::~OkdShape()
{
	
}

//-----------------------------------------------------------------------------
// Name:		read
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdShape::read(OkdFileStream* pStream)
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
void	OkdShape::write(OkdFileStream* pStream)
{
	(*pStream) << _meshPtr.getResourceName();
}
