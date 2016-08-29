﻿//*****************************************************************************
//
//	File:		TkDebug.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "TkDebug.h"

#include <Windows.h>

//-----------------------------------------------------------------------------
// Name:		TkDebug constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkDebug::TkDebug()
{
	
}

//-----------------------------------------------------------------------------
// Name:		TkDebug destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkDebug::~TkDebug()
{
	
}

//-----------------------------------------------------------------------------
// Name:		outputMessage
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void TkDebug::outputMessage( const TkString& strOutputMessage )
{
	OutputDebugString( (LPCSTR)strOutputMessage.buffer() );
	OutputDebugString( "\n" );
}