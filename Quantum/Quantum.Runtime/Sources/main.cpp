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
#include QUANTUM_CORE_H(Rendering/OpenGL/QmOpenGLContext)
#include QUANTUM_CORE_H(Rendering/OpenGL/QmOpenGLApi)
#include QUANTUM_CORE_H(Math/QmTransform)
#include QUANTUM_CORE_H(File/QmTextFile)

class QmPropertyDescriptor
{

};

class QmProperty
{
public:
	virtual void	setValue( const void* pValue ) = 0;
	virtual void*	getValue() = 0;
};

template<class T>
class QmPropertyBase: public QmProperty
{
public:
	inline			QmPropertyBase() {}
	inline			explicit QmPropertyBase( const T& value ) { _value = value; }

	virtual void	setValue( const void* pValue ) { _value = *((T*)pValue); }
	virtual void*	getValue() { return (void*)(&_value); }

	inline T&		operator=( const T& value ) { _value = value; return _value; }
	inline			operator T() { return _value; }

private:
	T				_value;
};

typedef QmPropertyBase<bool>		QmBoolProperty;
typedef QmPropertyBase<int>			QmIntProperty;
typedef QmPropertyBase<float>		QmFloatProperty;
typedef QmPropertyBase<double>		QmDoubleProperty;
typedef QmPropertyBase<QmString>	QmStringProperty;

class QmComponentDescriptor
{
private:
	QmString						_strTypeName;
	QmVector<QmPropertyDescriptor*>	_propertyDescriptors;
};

class QmComponent
{
	QmString	_strTypename;
};

class QmMeshComponent: public QmComponent
{
private:
	QmStringProperty	_strMeshFilePath;
	//QmBoolProperty		_bVisible = true;
};

class QmComponentManager
{
private:
	static QmVector<QmComponentDescriptor*> _componentDescriptors;
};

class QmEntity
{
private:
	QmString				_strEntityName;
	QmVector<QmComponent*>	_components;
};

//-----------------------------------------------------------------------------
// Name:		WinMain
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
int WinMain( __in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in_opt LPSTR lpCmdLine, __in int nShowCmd )
{
	QmFloatProperty		floatProp, floatProp2;
	QmDoubleProperty	doubleProp;
	QmIntProperty		intProp;
	QmStringProperty	stringProp( "test" );

	//floatProp = intProp;
	//floatProp = floatProp2;
	doubleProp = intProp;
	//intProp		= doubleProp;
	doubleProp = 1.0;

	// Create the application instance and init it
	QmApplication* pApplication = new QmApplication( hInstance );
	pApplication->init();
	
	// Create a window with an OpenGL context
	QmWindow*			pWindow			= pApplication->createWindow();
	QmOpenGLContext*	pOpenGLContext	= pWindow->createOpenGLContext();

	// Run the application loop
	pApplication->run();

	delete pApplication;

	return 0;
}
