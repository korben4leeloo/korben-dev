#ifndef QTOGRE_H
#define QTOGRE_H

#include <QtGui/QMainWindow>
#include "ui_qtogre.h"

class QTimer;
class QElapsedTimer;

namespace Ogre
{
	class Root;
	class RenderWindow;
	class SceneManager;
	class Camera;
	class Viewport;
}

class QtOgre : public QMainWindow
{
						Q_OBJECT

public:
						QtOgre(QWidget *parent = 0, Qt::WFlags flags = 0);
						~QtOgre();

protected:
	//virtual void		showEvent( QShowEvent* event );
	virtual void		resizeEvent( QResizeEvent* event );
	virtual void	paintEvent ( QPaintEvent * event );
	/*virtual void		mouseMoveEvent( QMouseEvent* event );
	virtual void		moveEvent( QMoveEvent* event );
	virtual bool		winEvent( MSG * message, long * result );
	virtual bool		event( QEvent * event );*/

private slots:
	void				OnFrameTimerTimeout();

private:
	Ui::QtOgreClass		ui;

	Ogre::Root*			_pOgreRoot;
	Ogre::RenderWindow*	_pRenderWindow;
	Ogre::SceneManager*	_pSceneManager;
	Ogre::Camera*		_pCamera;
	Ogre::Viewport*		_pViewport;

	QTimer*				_pFrameTimer;
	QElapsedTimer*		_pFrameElapsedTimer;
};

#endif // QTOGRE_H
