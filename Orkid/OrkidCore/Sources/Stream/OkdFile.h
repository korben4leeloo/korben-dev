//*****************************************************************************
//
//	Class:		OkdFile
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidCore_OkdFile_h__
#define __OrkidCore_OkdFile_h__

//#include	<QFile>
//#include	<stdio.h>

class OkdFile
{
public:
	enum OrkidFileOpenMode
	{
		OKD_FILE_OPEN_MODE_NEW			= 1 << 0,
		OKD_FILE_OPEN_MODE_APPEND		= 1 << 1,
		OKD_FILE_OPEN_MODE_READ			= 1 << 2,
		OKD_FILE_OPEN_MODE_WRITE		= 1 << 3,

		OKD_FILE_OPEN_MODE_READWRITE	= OKD_FILE_OPEN_MODE_READ | OKD_FILE_OPEN_MODE_WRITE
	};

				OkdFile();
				~OkdFile();

	void		open( const char* pcFileName, const OrkidFileOpenMode openMode );
	void		close();

	inline void	write( const char* pcBuffer, const uint uiBufferSize );

private:
	//QFile		_file;
	//FILE*		_pFile;
	int			_nFileHandle;
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
void	OkdFile::write(const char*	pcBuffer, 
						 const uint		uiBufferSize)
{
	
}

#endif