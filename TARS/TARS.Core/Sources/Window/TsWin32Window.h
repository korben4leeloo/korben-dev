//*****************************************************************************
//
//	Class:		TsWin32Window
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __TARS_Core_TsWin32Window_h__
#define __TARS_Core_TsWin32Window_h__

#include <QtCore/QString>

struct HINSTANCE;
struct HWND;

class TsWin32Window
{
public:
			TsWin32Window( const QString& strWindowName, const int nClientWidth, const int nClientHeight );
			~TsWin32Window();

	void	create( const HINSTANCE& hInstance, const bool bShow );

private:
	QString	_strWindowName;
	int		_nClientWidth;
	int		_nClientHeight;

	HWND*	_hWnd;
};

#endif