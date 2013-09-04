#ifndef OKDEDITORMAINWND_H
#define OKDEDITORMAINWND_H

#include <QtWidgets/QMainWindow>
#include "ui_OkdEditorMainWnd.h"

#include	<QTimer>

class OkdEditorMainWnd : public QMainWindow
{
	Q_OBJECT

public:
	OkdEditorMainWnd(QWidget *parent = 0);
	~OkdEditorMainWnd();

public slots:
	void loopUpdate();

private:
	Ui::OkdEditorMainWndClass ui;
	QTimer _loopTimer;
};

#endif // OKDEDITORMAINWND_H
