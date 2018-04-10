//*****************************************************************************
//
//	Class:		QmOpenGLContext
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __QUANTUM_CORE_TK_WGL_CONTEXT_H__
#define __QUANTUM_CORE_TK_WGL_CONTEXT_H__

#include "Root.h"
#include <Windows.h>

class QmWindow;

class QmOpenGLContext
{
	friend class QmWindow;

public:
	inline bool	isValid() const;

private:
				QmOpenGLContext();
				~QmOpenGLContext();

	void		create( QmWindow* pWindow );
	void		destroy();

	void		getOpenGLVersion( int32& nMajorVersion, int32& nMinorVersion );
	void		checkExtensions( const HDC& hDC );

	QmWindow*	_pWindow;
	HGLRC		_hGLRC;
};

//-----------------------------------------------------------------------------
// Name:		isValid
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
bool QmOpenGLContext::isValid() const
{
	return ( _hGLRC != nullptr );
}

#endif