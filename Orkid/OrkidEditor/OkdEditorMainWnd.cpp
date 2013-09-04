#include	"OkdEditorMainWnd.h"

#include	<3dEngine/Renderer/OpenGL/OkdOpenGLContext.h>

OkdOpenGLContext openGLContext;

OkdEditorMainWnd::OkdEditorMainWnd(QWidget *parent)
: QMainWindow(parent)
{
	ui.setupUi(this);

	openGLContext.create( (HWND)winId() );

	connect( &_loopTimer, SIGNAL(timeout()), this, SLOT( loopUpdate() ) );
	_loopTimer.start();
}

OkdEditorMainWnd::~OkdEditorMainWnd()
{

}

void OkdEditorMainWnd::loopUpdate()
{
	openGLContext.render();
}
