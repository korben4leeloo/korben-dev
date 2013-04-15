#include "qtogre.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtOgre w;
	w.show();
	return a.exec();
}
