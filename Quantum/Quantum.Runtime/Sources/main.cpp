//*****************************************************************************
//
//	File:		main.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "Root.h"

#include <Windows.h>

#include QUANTUM_CORE_H(Application/QmApplication)
#include QUANTUM_CORE_H(Rendering/Window/QmWindow)
#include QUANTUM_CORE_H(Rendering/D3D/QmD3DContext)
#include QUANTUM_RUNTIME_H(UnitTest/QmUnitTest)

//#define QUANTUM_UNIT_TESTS

//#include QUANTUM_CORE_H(Rendering/OpenGL/QmOpenGLContext)
//#include QUANTUM_CORE_H(Rendering/OpenGL/QmOpenGLApi)

//#include <d3d11.h>
//
//IDXGISwapChain* SwapChain;
//ID3D11Device* d3d11Device;
//ID3D11DeviceContext* d3d11DevCon;
//ID3D11RenderTargetView* renderTargetView;
//
//float red = 0.0f;
//float green = 0.0f;
//float blue = 0.0f;
//int colormodr = 1;
//int colormodg = 1;
//int colormodb = 1;

//void RenderScene()
//{
//	//Update the colors of our scene
//    red += colormodr * 0.00005f;
//    green += colormodg * 0.00002f;
//    blue += colormodb * 0.00001f;
//
//    if(red >= 1.0f || red <= 0.0f)
//        colormodr *= -1;
//    if(green >= 1.0f || green <= 0.0f)
//        colormodg *= -1;
//    if(blue >= 1.0f || blue <= 0.0f)
//        colormodb *= -1;
//
//    //Clear our backbuffer to the updated color
//	const float bgColor[4] = { red, green, blue, 1.0f };
//
//    d3d11DevCon->ClearRenderTargetView(renderTargetView, bgColor);
//
//    //Present the backbuffer to the screen
//    SwapChain->Present(0, 0);
//}

#pragma comment( lib, "rpcrt4.lib" )

class QmGuid
{
public:
	static QmGuid create()
	{
		UUID uuid;

		RPC_STATUS rpcStatus = UuidCreate( &uuid );
		QmGuid guid;

		if ( rpcStatus == RPC_S_OK )
		{
			guid._b0_32 = uuid.Data1;
			guid._b1_16 = uuid.Data2;
			guid._b2_16 = uuid.Data3;
			
			((char*)(&guid._b3_16))[0] = uuid.Data4[1];
			((char*)(&guid._b3_16))[1] = uuid.Data4[0];

			guid._b4_48[0] = uuid.Data4[2];
			guid._b4_48[1] = uuid.Data4[3];
			guid._b4_48[2] = uuid.Data4[4];
			guid._b4_48[3] = uuid.Data4[5];
			guid._b4_48[4] = uuid.Data4[6];
			guid._b4_48[5] = uuid.Data4[7];
		}

		return guid;
	}

private:
	uint32	_b0_32;
	uint16	_b1_16;
	uint16	_b2_16;
	uint16	_b3_16;
	uint8	_b4_48[6];
};

template<class T>
class QmPropertyBase
{
public:
	QmPropertyBase() {}
	QmPropertyBase( const T& value ): _value( value ) {}

	inline void		setValue( const T& value ) { _value = value; }
	inline const T&	getValue() const { return _value; }

	inline QmPropertyBase<T>& operator=( const T& other )
	{
		if	( &other != &_value )
		{
			_value = other;
		}

		return *this;
	}

private:
	T				_value;
};

typedef QmPropertyBase<bool>		QmBoolProperty;
typedef QmPropertyBase<QmString>	QmStringProperty;

class QmComponentDescriptor
{
public:
	QmComponentDescriptor( const QmString& componentName ): _name( componentName ) {}

private:
	QmString _name;
};

class QmComponent
{
public:
	virtual const QmComponentDescriptor* getDescriptor() const = 0;
};

class QmEntity
{
public:
	QmEntity( const QmString& name ): _name( name ) {}

	void					addComponent( QmComponent* pComponent ) { _components.pushBack( pComponent ); }

private:
	QmString				_name;
	QmGuid					_id;
	QmVector<QmComponent*>	_components;
};

#define QUANTUM_COMPONENT_DECLARE \
	public:	\
		const QmComponentDescriptor* getDescriptor() const { return &_descriptor; } \
	\
	private: \
		static QmComponentDescriptor _descriptor;

#define QUANTUM_COMPONENT_DEFINE( Class, Name ) \
	QmComponentDescriptor Class::_descriptor( #Name );
	

class QmMeshComponent: public QmComponent
{
	QUANTUM_COMPONENT_DECLARE

public:
	inline void setMeshData( const QmString& meshDataName ) { _meshDataName = meshDataName; }

private:
	QmStringProperty	_meshDataName;
	QmBoolProperty		_bVisible = false;
};

QUANTUM_COMPONENT_DEFINE( QmMeshComponent, MeshComponent )

//-----------------------------------------------------------------------------
// Name:		createScene
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void createScene()
{
	QmGuid entityGuid = QmGuid::create();

	QmEntity e( "test_entity" );
	QmMeshComponent* mc = new QmMeshComponent();

	mc->setMeshData( "cube" );

	e.addComponent( mc );
}

//-----------------------------------------------------------------------------
// Name:		WinMain
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
int WinMain( __in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in_opt LPSTR lpCmdLine, __in int nShowCmd )
{
#ifdef QUANTUM_UNIT_TESTS
	// Unit tests
	QmUnitTest unitTest;
	unitTest.launch();
#endif

	// Create the application instance and init it
	QmApplication* pApplication = new QmApplication( hInstance );
	pApplication->init();
	
	// Create a window with a Direct3D context
	QmWindow*		pWindow		= pApplication->createWindow();
	QmD3DContext*	pD3DContext	= pApplication->createD3DContext( pWindow );

	// create test scene
	createScene();

	// Run the application loop
	pApplication->run();

	delete pApplication;

	return 0;
}
