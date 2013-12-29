//*****************************************************************************
//
//	Class:		OkdEditorMainWnd
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEditor_OkdEditorMainWnd_h__
#define __OrkidEditor_OkdEditorMainWnd_h__

#include "OrkidEditorRoot.h"

#include <QtWidgets/QMainWindow>
#include "ui_OkdEditorMainWnd.h"

#include	<QTimer>

class QThread;

class OkdEditorMainWnd : public QMainWindow
{
								Q_OBJECT

public:
								OkdEditorMainWnd( QWidget* pParentWidget = 0 );
								~OkdEditorMainWnd();

public slots:
	void						loopUpdate();
	void						runtimeExeThreadStarted();

private:
	Ui::OkdEditorMainWndClass	ui;
	QTimer						_loopTimer;
	QThread*					_pRuntimeDllThread;
};

#endif // __OrkidEditor_OkdEditorMainWnd_h__
