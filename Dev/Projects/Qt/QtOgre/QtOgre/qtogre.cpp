#include "qtogre.h"

#include <OgreRoot.h>
#include <OgreRenderWindow.h>
#include <OgreCamera.h>
#include <OgreViewport.h>
#include <OgreManualObject.h>

#include <QTimer>
#include <QElapsedTimer>
#include <QDebug>

static float fRotationSpeed = 2.0f;

QtOgre::QtOgre(QWidget *parent, Qt::WFlags flags)
: QMainWindow			(parent, flags)
, _pOgreRoot			( NULL )
, _pSceneManager		( NULL )
, _pCamera				( NULL )
, _pTriangleNode		( NULL )
, _pFrameTimer			( NULL )
, _pFrameElapsedTimer	( NULL )
{
	ui.setupUi(this);

	//centralWidget()->setAttribute( Qt::WA_PaintOnScreen, true );
	//centralWidget()->setAttribute( Qt::WA_NoBackground );

	_pOgreRoot = new Ogre::Root( "plugins.cfg", "" );

	const Ogre::RenderSystemList& renderers = _pOgreRoot->getAvailableRenderers();

	_pOgreRoot->setRenderSystem( renderers[0] );
	_pOgreRoot->initialise( false );

	Ogre::NameValuePairList windowParams;
	QString strHwnd = QString::number( (int)centralWidget()->winId() );

	windowParams["externalWindowHandle"] = strHwnd.toStdString();

	_pRenderWindow = _pOgreRoot->createRenderWindow( "TestWindow", centralWidget()->width(), centralWidget()->height(), false, &windowParams );

	Ogre::ResourceGroupManager::getSingletonPtr()->addResourceLocation( "../../Resources", "FileSystem", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, true );
	Ogre::ResourceGroupManager::getSingletonPtr()->initialiseAllResourceGroups();

	//_pRenderWindow = _pOgreRoot->createRenderWindow( "TestWindow", centralWidget()->width(), centralWidget()->height(), false );
	_pSceneManager = _pOgreRoot->createSceneManager( Ogre::ST_GENERIC, "TestScene" );
	_pCamera = _pSceneManager->createCamera( "TestSceneCamera" );
	_pViewport = _pRenderWindow->addViewport( _pCamera );

	_pViewport->setBackgroundColour( Ogre::ColourValue( 0.2f, 0.2f, 0.2f, 1.0f ) );

	_pCamera->setPosition( 0.0f, 0.0f, 3.0f );
	_pCamera->lookAt( 0.0f, 0.0f, 0.0f );
	_pCamera->setNearClipDistance( 0.1f );
	_pCamera->setAspectRatio( (float)centralWidget()->width() / (float)centralWidget()->height() );

	Ogre::ManualObject* pTriangleMesh = _pSceneManager->createManualObject();

	//pTriangleMesh->begin( "BaseWhite" );
	pTriangleMesh->begin( "TestMaterial" );

	pTriangleMesh->position( -0.5f, 0.0f, 0.0f );
	pTriangleMesh->colour( 1.0f, 0.0f, 0.0f, 1.0f );

	pTriangleMesh->position( 0.5f, 0.0f, 0.0f );
	pTriangleMesh->colour( 0.0f, 0.0f, 1.0f, 1.0f );

	pTriangleMesh->position( 0.0f, 1.0f, 0.0f );
	pTriangleMesh->colour( 0.0f, 1.0f, 0.0f, 1.0f );

	pTriangleMesh->triangle( 0, 1, 2 );
	pTriangleMesh->triangle( 0, 2, 1 );
	pTriangleMesh->end();

	//_pSceneManager->setAmbientLight( Ogre::ColourValue( 1.0f, 1.0f, 0.5f, 1.0f ) );
	_pTriangleNode = _pSceneManager->getRootSceneNode()->createChildSceneNode( "TriangleNode" );
	_pTriangleNode->attachObject( pTriangleMesh );

	//_pOgreRoot->startRendering();

	_pFrameTimer = new QTimer( this );
	_pFrameTimer->start( 0 );

	connect( _pFrameTimer, SIGNAL(timeout()), this, SLOT(OnFrameTimerTimeout()) );

	_pFrameElapsedTimer = new QElapsedTimer();
	_pFrameElapsedTimer->start();
}

QtOgre::~QtOgre()
{
	/*delete _pViewport;
	delete _pCamera;
	delete _pSceneManager;
	delete _pRenderWindow;*/
	delete _pOgreRoot;
}

void QtOgre::OnFrameTimerTimeout()
{
	_pOgreRoot->renderOneFrame();

	qint64	nElapsed				= _pFrameElapsedTimer->nsecsElapsed();
	float	fElapsedTimeInSeconds	= nElapsed / 1000000000.0f;
	float	fAngle					= fRotationSpeed * fElapsedTimeInSeconds;

	_pTriangleNode->yaw( Ogre::Radian( fAngle ) );

	//qDebug() << (double)nElapsed / 1000000.0;
	_pFrameElapsedTimer->start();
}

void QtOgre::resizeEvent( QResizeEvent* event )
{
	QWidget::resizeEvent( event );

	if	( _pRenderWindow )
	{
		_pRenderWindow->resize( centralWidget()->width(), centralWidget()->height() );
		_pRenderWindow->windowMovedOrResized();
		_pCamera->setAspectRatio( (float)centralWidget()->width() / (float)centralWidget()->height() );
		_pOgreRoot->renderOneFrame();
	}

	/*if(ogreCamera)
	{
		Ogre::Real aspectRatio = Ogre::Real(newSize.width()) / Ogre::Real(newSize.height());
		ogreCamera->setAspectRatio(aspectRatio);
	}*/
}

void QtOgre::paintEvent( QPaintEvent* event )
{
	//QWidget::paintEvent( event );

	if	( _pRenderWindow )
	{
		_pOgreRoot->renderOneFrame();
	}
}

//void QtOgre::mouseMoveEvent( QMouseEvent* event )
//{
//	QWidget::mouseMoveEvent( event );
//
//	if	( _pRenderWindow )
//	{
//		//ogreRenderWindow->resize(newSize.width(), newSize.height());
//		_pRenderWindow->windowMovedOrResized();
//	}
//
//	/*if(ogreCamera)
//	{
//		Ogre::Real aspectRatio = Ogre::Real(newSize.width()) / Ogre::Real(newSize.height());
//		ogreCamera->setAspectRatio(aspectRatio);
//	}*/
//}
//
//void QtOgre::moveEvent( QMoveEvent* event )
//{
//	QWidget::moveEvent( event );
//
//	if	( _pRenderWindow )
//	{
//		//ogreRenderWindow->resize(newSize.width(), newSize.height());
//		_pRenderWindow->windowMovedOrResized();
//	}
//
//	/*if(ogreCamera)
//	{
//		Ogre::Real aspectRatio = Ogre::Real(newSize.width()) / Ogre::Real(newSize.height());
//		ogreCamera->setAspectRatio(aspectRatio);
//	}*/
//}
//
//bool QtOgre::winEvent( MSG * message, long * result )
//{
//	if	( message->message == WM_WINDOWPOSCHANGING )
//	{
//		_pRenderWindow->windowMovedOrResized();
//	}
//
//	return QWidget::winEvent( message, result );
//}
//
//bool QtOgre::event( QEvent* event )
//{
//	return QWidget::event( event );
//
//	//if	( _pRenderWindow )
//	//{
//	//	//ogreRenderWindow->resize(newSize.width(), newSize.height());
//	//	_pRenderWindow->windowMovedOrResized();
//	//}
//
//	/*if(ogreCamera)
//	{
//		Ogre::Real aspectRatio = Ogre::Real(newSize.width()) / Ogre::Real(newSize.height());
//		ogreCamera->setAspectRatio(aspectRatio);
//	}*/
//}

//void QtOgre::showEvent( QShowEvent* event )
//{
//	QWidget::showEvent( event );
//
//	/*_pFrameTimer = new QTimer( this );
//	_pFrameTimer->start( 0 );
//
//	connect( _pFrameTimer, SIGNAL(timeout()), this, SLOT(OnFrameTimerTimeout()) );
//
//	_pFrameElapsedTimer = new QElapsedTimer();
//	_pFrameElapsedTimer->start();*/
//
//	//if	( _pOgreRoot == NULL )
//	//{
//	//	_pOgreRoot = new Ogre::Root( "plugins.cfg", "" );
//
//	//	const Ogre::RenderSystemList& renderers = _pOgreRoot->getAvailableRenderers();
//
//	//	_pOgreRoot->setRenderSystem( renderers[0] );
//	//	_pOgreRoot->initialise( false );
//
//	//	Ogre::NameValuePairList windowParams;
//	//	QString strHwnd = QString::number( (int)centralWidget()->winId() );
//
//	//	windowParams["externalWindowHandle"] = strHwnd.toStdString();
//
//	//	_pOgreRoot->createRenderWindow( "test", 500, 500, false/*, &windowParams*/ );
//	//	_pOgreRoot->startRendering();
//	//}
//}