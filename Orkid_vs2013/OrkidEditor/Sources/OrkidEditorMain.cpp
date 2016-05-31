//*****************************************************************************
//
//	File:		OrkidEditorMain.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdEditorMainWnd.h"
#include	<QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication		orkidEditorApp( argc, argv );
	OkdEditorMainWnd	orkidEditorMainWnd;

	orkidEditorMainWnd.show();

	return	( orkidEditorApp.exec() );
}
