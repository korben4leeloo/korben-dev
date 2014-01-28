//*****************************************************************************
//
//	File:		OkdFreeCameraGameplay.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdFreeCameraGameplay.h"

//-----------------------------------------------------------------------------
// Name:		OkdFreeCameraGameplay constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFreeCameraGameplay::OkdFreeCameraGameplay()
: _pCamera( 0 )
{

}

//-----------------------------------------------------------------------------
// Name:		OkdFreeCameraGameplay destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdFreeCameraGameplay::~OkdFreeCameraGameplay()
{

}

#include <tuple>

enum TuplePos
{
	TuplePos0,
	TuplePos1,
	TuplePos2,
	TuplePos3
};

//-----------------------------------------------------------------------------
// Name:		update
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdFreeCameraGameplay::update()
{
	std::tuple<float, int, char> t;

	int f = std::get<TuplePos0>(t);
}
