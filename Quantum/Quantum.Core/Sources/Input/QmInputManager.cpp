//*****************************************************************************
//
//	File:		QmInputManager.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "QmInputManager.h"

#include <Windows.h>

#define HID_USAGE_PAGE_GENERIC	1
#define HID_USAGE_KEYBOARD		6
#define HID_USAGE_MOUSE			2

//-----------------------------------------------------------------------------
// Name:		QmInputManager constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmInputManager::QmInputManager()
{
	
}

//-----------------------------------------------------------------------------
// Name:		QmInputManager destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
QmInputManager::~QmInputManager()
{
	
}

//-----------------------------------------------------------------------------
// Name:		registerDevices
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void QmInputManager::registerDevices()
{
	RAWINPUTDEVICE inputDeviceList[2];

	// Keyboard
	inputDeviceList[0].usUsagePage	= HID_USAGE_PAGE_GENERIC;
	inputDeviceList[0].usUsage		= HID_USAGE_KEYBOARD;
	inputDeviceList[0].dwFlags		= 0;
	inputDeviceList[0].hwndTarget	= nullptr;

	// Mouse
	inputDeviceList[1].usUsagePage	= HID_USAGE_PAGE_GENERIC;
	inputDeviceList[1].usUsage		= HID_USAGE_MOUSE;
	inputDeviceList[1].dwFlags		= 0;
	inputDeviceList[1].hwndTarget	= nullptr;

	if ( RegisterRawInputDevices( inputDeviceList, 2, sizeof(RAWINPUTDEVICE) ) == FALSE )
	{
		//registration failed. Call GetLastError for the cause of the error
		QUANTUM_BREAK();
	}

	initWin32KeyMapper();
}

//-----------------------------------------------------------------------------
// Name:		enumDevices
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void QmInputManager::enumDevices()
{
	UINT nDeviceCount;

	if	( ( GetRawInputDeviceList( nullptr, &nDeviceCount, sizeof(RAWINPUTDEVICELIST) ) == (UINT)-1 ) || ( nDeviceCount == 0 ) )
	{
		return;
	}

	RAWINPUTDEVICELIST* pDeviceList = new RAWINPUTDEVICELIST[nDeviceCount];
	char				pcDeviceName[256];
	UINT				nNameLength = sizeof(pcDeviceName), nDeviceInfoSize = sizeof(RID_DEVICE_INFO);
	RID_DEVICE_INFO		deviceInfo;

	GetRawInputDeviceList( pDeviceList, &nDeviceCount, sizeof(RAWINPUTDEVICELIST) );

	for	( uint32 i = 0; i < nDeviceCount; i++ )
	{
		GetRawInputDeviceInfo( pDeviceList[i].hDevice, RIDI_DEVICENAME, pcDeviceName, &nNameLength );
		GetRawInputDeviceInfo( pDeviceList[i].hDevice, RIDI_DEVICEINFO, &deviceInfo, &nDeviceInfoSize );

		switch	( pDeviceList[i].dwType )
		{
		case RIM_TYPEKEYBOARD:
			break;

		case RIM_TYPEMOUSE:
			break;

		case RIM_TYPEHID:
			break;

		default:
			break;
		}
	}

	delete[] pDeviceList;
}

//-----------------------------------------------------------------------------
// Name:		OnInputReceived
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void QmInputManager::OnInputReceived( RAWINPUT* pRawInput )
{
	onRawInput( pRawInput );
}

//-----------------------------------------------------------------------------
// Name:		onRawInput
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void QmInputManager::onRawInput( RAWINPUT* pRawInput )
{
	switch	( pRawInput->header.dwType )
	{
	case RIM_TYPEKEYBOARD:
		{
			const RAWKEYBOARD& rawKeyboard = pRawInput->data.keyboard;

			switch	( rawKeyboard.Message )
			{
			case WM_KEYDOWN:
				_inputState.setKeyState( _win32KeyMapper[rawKeyboard.VKey], QmKeyStateDown );
				break;

			case WM_KEYUP:
				_inputState.setKeyState( _win32KeyMapper[rawKeyboard.VKey], QmKeyStateUp );
				break;

			default:
				break;
			}
		}
		break;

	case RIM_TYPEMOUSE:
		break;

	case RIM_TYPEHID:
		break;

	default:
		QUANTUM_BREAK();
		break;
	}
}

//-----------------------------------------------------------------------------
// Name:		initWin32KeyMapper
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void QmInputManager::initWin32KeyMapper()
{
	memset( _win32KeyMapper, QuantumKeyInvalid, sizeof(_win32KeyMapper) );

	_win32KeyMapper[0x41]			= QmKey_A;
	_win32KeyMapper[0x42]			= QmKey_B;
	_win32KeyMapper[0x43]			= QmKey_C;
	_win32KeyMapper[0x44]			= QmKey_D;
	_win32KeyMapper[0x45]			= QmKey_E;
	_win32KeyMapper[0x46]			= QmKey_F;
	_win32KeyMapper[0x47]			= QmKey_G;
	_win32KeyMapper[0x48]			= QmKey_H;
	_win32KeyMapper[0x49]			= QmKey_I;
	_win32KeyMapper[0x4A]			= QmKey_J;
	_win32KeyMapper[0x4B]			= QmKey_K;
	_win32KeyMapper[0x4C]			= QmKey_L;
	_win32KeyMapper[0x4D]			= QmKey_M;
	_win32KeyMapper[0x4E]			= QmKey_N;
	_win32KeyMapper[0x4F]			= QmKey_O;
	_win32KeyMapper[0x50]			= QmKey_P;
	_win32KeyMapper[0x51]			= QmKey_Q;
	_win32KeyMapper[0x52]			= QmKey_R;
	_win32KeyMapper[0x53]			= QmKey_S;
	_win32KeyMapper[0x54]			= QmKey_T;
	_win32KeyMapper[0x55]			= QmKey_U;
	_win32KeyMapper[0x56]			= QmKey_V;
	_win32KeyMapper[0x57]			= QmKey_W;
	_win32KeyMapper[0x58]			= QmKey_X;
	_win32KeyMapper[0x59]			= QmKey_Y;
	_win32KeyMapper[0x5A]			= QmKey_Z;
	_win32KeyMapper[0x30]			= QmKey_0;
	_win32KeyMapper[0x31]			= QmKey_1;
	_win32KeyMapper[0x32]			= QmKey_2;
	_win32KeyMapper[0x33]			= QmKey_3;
	_win32KeyMapper[0x34]			= QmKey_4;
	_win32KeyMapper[0x35]			= QmKey_5;
	_win32KeyMapper[0x36]			= QmKey_6;
	_win32KeyMapper[0x37]			= QmKey_7;
	_win32KeyMapper[0x38]			= QmKey_8;
	_win32KeyMapper[0x39]			= QmKey_9;
	_win32KeyMapper[VK_NUMPAD0]		= QmKey_Numpad0;
	_win32KeyMapper[VK_NUMPAD1]		= QmKey_Numpad1;
	_win32KeyMapper[VK_NUMPAD2]		= QmKey_Numpad2;
	_win32KeyMapper[VK_NUMPAD3]		= QmKey_Numpad3;
	_win32KeyMapper[VK_NUMPAD4]		= QmKey_Numpad4;
	_win32KeyMapper[VK_NUMPAD5]		= QmKey_Numpad5;
	_win32KeyMapper[VK_NUMPAD6]		= QmKey_Numpad6;
	_win32KeyMapper[VK_NUMPAD7]		= QmKey_Numpad7;
	_win32KeyMapper[VK_NUMPAD8]		= QmKey_Numpad8;
	_win32KeyMapper[VK_NUMPAD9]		= QmKey_Numpad9;
	_win32KeyMapper[VK_ADD]			= QmKey_NumpadAdd;
	_win32KeyMapper[VK_SUBTRACT]	= QmKey_NumpadSubstract;
	_win32KeyMapper[VK_RETURN]		= QmKey_Return;
	_win32KeyMapper[VK_ESCAPE]		= QmKey_Escape;
	_win32KeyMapper[VK_SPACE]		= QmKey_Space;
	_win32KeyMapper[VK_BACK]		= QmKey_Backspace;
	_win32KeyMapper[VK_DELETE]		= QmKey_Delete;
	_win32KeyMapper[VK_PRIOR]		= QmKey_PageUp;
	_win32KeyMapper[VK_NEXT]		= QmKey_PageDown;
	_win32KeyMapper[VK_HOME]		= QmKey_Home;
	_win32KeyMapper[VK_END]			= QmKey_End;
	_win32KeyMapper[VK_INSERT]		= QmKey_Insert;
	_win32KeyMapper[VK_LSHIFT]		= QmKey_LeftShift;
	_win32KeyMapper[VK_RSHIFT]		= QmKey_RightShift;
	_win32KeyMapper[VK_LCONTROL]	= QmKey_LeftControl;
	_win32KeyMapper[VK_RCONTROL]	= QmKey_RightControl;
	_win32KeyMapper[VK_F1]			= QmKey_F1;
	_win32KeyMapper[VK_F2]			= QmKey_F2;
	_win32KeyMapper[VK_F3]			= QmKey_F3;
	_win32KeyMapper[VK_F4]			= QmKey_F4;
	_win32KeyMapper[VK_F5]			= QmKey_F5;
	_win32KeyMapper[VK_F6]			= QmKey_F6;
	_win32KeyMapper[VK_F7]			= QmKey_F7;
	_win32KeyMapper[VK_F8]			= QmKey_F8;
	_win32KeyMapper[VK_F9]			= QmKey_F9;
	_win32KeyMapper[VK_F10]			= QmKey_F10;
	_win32KeyMapper[VK_F11]			= QmKey_F11;
	_win32KeyMapper[VK_F12]			= QmKey_F12;
}
