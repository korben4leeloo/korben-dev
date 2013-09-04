#include "OkdEditorMainWnd.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	OkdEditorMainWnd w;
	w.show();
	return a.exec();
}
