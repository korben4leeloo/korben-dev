//*****************************************************************************
//
//	File:		OkdEditorMainWnd.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdEditorMainWnd.h"

#include	<QLibrary>
#include	<QThread>

#include	<3dEngine/Renderer/OpenGL/OkdOpenGLContext.h>

//OkdOpenGLContext openGLContext;

//-----------------------------------------------------------------------------
// Name:		OkdEditorMainWnd constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdEditorMainWnd::OkdEditorMainWnd(QWidget *	pParentWidget)
: QMainWindow			( pParentWidget )
, _pRuntimeDllThread	( 0 )
{
	//typedef void (*OrkidRuntimeDllMainFunc)( HMODULE hRuntimeModule );
	typedef void (*RuntimeExeLaunchFunc)( HMODULE hRuntimeModule );

	ui.setupUi(this);

	_pRuntimeDllThread = new QThread( this );

	connect ( _pRuntimeDllThread, SIGNAL(started()), this, SLOT(runtimeExeThreadStarted()) );
	_pRuntimeDllThread->start();

	//openGLContext.create( (HWND)winId() );

	//connect( &_loopTimer, SIGNAL(timeout()), this, SLOT( loopUpdate() ) );
	//_loopTimer.start();

	/*QLibrary runtimeExe( "D:\\DevJJA\\SVN\\korben-dev\\Orkid\\Debug\\OrkidRuntimeDll.dll" );

	bool b = runtimeExe.load();
	OrkidRuntimeDllMainFunc runtimeMainPtr = (OrkidRuntimeDllMainFunc)runtimeExe.resolve( "orkidRuntimeDllMainEntry" );
	QString error = runtimeExe.errorString();

	(*runtimeMainPtr)( 0 );*/

	/*QLibrary runtimeExe( "D:\\DevJJA\\SVN\\korben-dev\\Orkid\\Debug\\OrkidRuntime.exe" );

	bool b = runtimeExe.load();
	QFunctionPointer runtimeMainPtr = runtimeExe.resolve( "launch" );
	QString error = runtimeExe.errorString();*/

	/*HMODULE hLib = LoadLibrary( L"D:\\DevJJA\\SVN\\korben-dev\\Orkid\\Debug\\OrkidRuntime.exe" );
	RuntimeExeLaunchFunc runtimeMainPtr = (RuntimeExeLaunchFunc)GetProcAddress( hLib, "launch" );*/

	/*HMODULE hLib = LoadLibrary( L"D:\\DevJJA\\SVN\\korben-dev\\Orkid\\Debug\\OrkidRuntimeDll.dll" );
	RuntimeExeLaunchFunc runtimeMainPtr = (RuntimeExeLaunchFunc)GetProcAddress( hLib, "launch" );

	if	( runtimeMainPtr )
	{
		(*runtimeMainPtr)( hLib );
	}*/

	/*HMODULE hLib = LoadLibrary( "D:\\DevJJA\\SVN\\korben-dev\\Orkid\\Debug\\OrkidRuntimeDll.dll" );
	GetProcAddress( hLib, "orkidRuntimeDllMainEntry" );*/
}

//-----------------------------------------------------------------------------
// Name:		OkdEditorMainWnd destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdEditorMainWnd::~OkdEditorMainWnd()
{

}

//-----------------------------------------------------------------------------
// Name:		runtimeExeThreadStarted
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdEditorMainWnd::runtimeExeThreadStarted()
{
	typedef void (*RuntimeExeLaunchFunc)( HMODULE hRuntimeModule, HWND hEmbeddedWnd );

	HMODULE hLib = LoadLibrary( L"D:\\DevJJA\\SVN\\korben-dev\\Orkid\\Debug\\OrkidRuntimeDll.dll" );
	RuntimeExeLaunchFunc runtimeMainPtr = (RuntimeExeLaunchFunc)GetProcAddress( hLib, "launch" );

	if	( runtimeMainPtr )
	{
		(*runtimeMainPtr)( hLib, (HWND)winId() );
	}
}

//-----------------------------------------------------------------------------
// Name:		loopUpdate
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void OkdEditorMainWnd::loopUpdate()
{
	//openGLContext.render();
}
