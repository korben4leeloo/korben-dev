//*****************************************************************************
//
//	Class:		QmString
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __QUANTUM_CORE_TK_STRING_H__
#define __QUANTUM_CORE_TK_STRING_H__

#include "Root.h"
#include <cstdio>

#include QUANTUM_CORE_H(Containers/QmVector)

class QmBinaryFile;
class QmTextFile;

class QmString
{
	// Operators
	friend bool operator==( const QmString& lhs, const QmString& rhs );
	friend bool operator!=( const QmString& lhs, const QmString& rhs );
	friend QmString operator+( const QmString& lhs, const QmString& rhs );

	// Stream operators
	friend const QmBinaryFile& operator>>( const QmBinaryFile& file, QmString& s );
	friend const QmTextFile& operator>>( const QmTextFile& file, QmString& s );

public:
						QmString();
						QmString( const char* pcBuffer );
						QmString( const QmString& rhs );
						~QmString();

	QmString&			operator=( const QmString& rhs );

	inline const char*	buffer() const;
	inline uint32		size() const;
	inline bool			isEmpty() const;

	void				split( const QmString& strSeparator, QmVector<QmString>& tokens );
	QmString			extract( const uint32 nStartPos, const int32 nEndPos = -1 );

	template<typename...FormatArgs>
	static QmString		format( const char* pcFormat, FormatArgs...formatArgs );

	static QmString		fromUnicode( void* pcBuffer );

private:
	inline void			clear();
	void				copy( const char* pcBuffer );

	char*				_pcBuffer;
	uint32				_nSize;
};

//-----------------------------------------------------------------------------
// Name:		format
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
template<typename...FormatArgs>
QmString QmString::format( const char* pcFormat, FormatArgs...formatArgs )
{
	uint32	uiMaxBufferSize = 1024;
	int32	nCount			= -1;
	char*	pcTempBuffer	= nullptr;
	bool	bCopy			= true;

	while	( bCopy )
	{
		delete[] pcTempBuffer;

		pcTempBuffer = new char[uiMaxBufferSize];
		nCount = _snprintf( pcTempBuffer, uiMaxBufferSize, pcFormat, formatArgs... );

		bCopy = ( nCount < 0 ) || ( nCount == uiMaxBufferSize );
		uiMaxBufferSize *= 2;
	}

	QmString strResult;
	strResult.copy( pcTempBuffer );

	return ( strResult );
}

//-----------------------------------------------------------------------------
// Name:		clear
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void QmString::clear()
{
	delete[] _pcBuffer;

	_pcBuffer	= nullptr;
	_nSize		= 0;
}

//-----------------------------------------------------------------------------
// Name:		buffer
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
const char* QmString::buffer() const
{
	return ( _pcBuffer );
}

//-----------------------------------------------------------------------------
// Name:		size
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
uint32 QmString::size() const
{
	return ( _nSize );
}

//-----------------------------------------------------------------------------
// Name:		isEmpty
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
bool QmString::isEmpty() const
{
	return ( _nSize == 0 );
}

QmBinaryFile& operator<<( QmBinaryFile& file, const QmString& s );

#endif