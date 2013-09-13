//*****************************************************************************
//
//	Class:		OkdStream
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdStream_h__
#define __OrkidCore_OkdStream_h__

#include	<QDataStream>

class OkdStream
{
public:
				OkdStream();
				~OkdStream();

	inline void	write( const char* pcBuffer, const uint uiBufferSize );

private:
	QDataStream	_stream;
};

//*****************************************************************************
//
//	Inline functions declarations
//
//*****************************************************************************

//-----------------------------------------------------------------------------
// Name:		unitX
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdStream::write(const char*	pcBuffer, 
						 const uint		uiBufferSize)
{
	_stream.writeRawData( pcBuffer, uiBufferSize );
}

#endif