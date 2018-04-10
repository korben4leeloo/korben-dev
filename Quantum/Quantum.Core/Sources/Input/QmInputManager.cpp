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
// Name:		onRawInput
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
uint64 QmInputManager::onRawInput( const uint64 nRawInputHandle )
{
	uint32 nRawInputSize;

	GetRawInputData( (HRAWINPUT)nRawInputHandle, RID_INPUT, nullptr, &nRawInputSize, sizeof(RAWINPUTHEADER) );

	RAWINPUT* rawInput = (RAWINPUT*)( new char[nRawInputSize] );

	if ( GetRawInputData((HRAWINPUT)nRawInputHandle, RID_INPUT, rawInput, &nRawInputSize, sizeof(RAWINPUTHEADER) ) != nRawInputSize )
	{
		return ( GetLastError() );
	}

	switch	( rawInput->header.dwType )
	{
	case RIM_TYPEKEYBOARD:
		{
			const RAWKEYBOARD& rawKeyboard = rawInput->data.keyboard;

			switch	( rawKeyboard.Message )
			{
			case WM_KEYDOWN:
				_inputState.setKeyState( _win32KeyMapper[rawKeyboard.VKey], TK_KEY_STATE_DOWN );
				break;

			case WM_KEYUP:
				_inputState.setKeyState( _win32KeyMapper[rawKeyboard.VKey], TK_KEY_STATE_UP );
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

	return ( DefRawInputProc( &rawInput, 1, sizeof(RAWINPUTHEADER) ) );
}

//-----------------------------------------------------------------------------
// Name:		initWin32KeyMapper
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void QmInputManager::initWin32KeyMapper()
{
	memset( _win32KeyMapper, TK_KEY_INVALID, sizeof(_win32KeyMapper) );

	_win32KeyMapper[0x41]			= TK_KEY_A;
	_win32KeyMapper[0x42]			= TK_KEY_B;
	_win32KeyMapper[0x43]			= TK_KEY_C;
	_win32KeyMapper[0x44]			= TK_KEY_D;
	_win32KeyMapper[0x45]			= TK_KEY_E;
	_win32KeyMapper[0x46]			= TK_KEY_F;
	_win32KeyMapper[0x47]			= TK_KEY_G;
	_win32KeyMapper[0x48]			= TK_KEY_H;
	_win32KeyMapper[0x49]			= TK_KEY_I;
	_win32KeyMapper[0x4A]			= TK_KEY_J;
	_win32KeyMapper[0x4B]			= TK_KEY_K;
	_win32KeyMapper[0x4C]			= TK_KEY_L;
	_win32KeyMapper[0x4D]			= TK_KEY_M;
	_win32KeyMapper[0x4E]			= TK_KEY_N;
	_win32KeyMapper[0x4F]			= TK_KEY_O;
	_win32KeyMapper[0x50]			= TK_KEY_P;
	_win32KeyMapper[0x51]			= TK_KEY_Q;
	_win32KeyMapper[0x52]			= TK_KEY_R;
	_win32KeyMapper[0x53]			= TK_KEY_S;
	_win32KeyMapper[0x54]			= TK_KEY_T;
	_win32KeyMapper[0x55]			= TK_KEY_U;
	_win32KeyMapper[0x56]			= TK_KEY_V;
	_win32KeyMapper[0x57]			= TK_KEY_W;
	_win32KeyMapper[0x58]			= TK_KEY_X;
	_win32KeyMapper[0x59]			= TK_KEY_Y;
	_win32KeyMapper[0x5A]			= TK_KEY_Z;
	_win32KeyMapper[0x30]			= TK_KEY_0;
	_win32KeyMapper[0x31]			= TK_KEY_1;
	_win32KeyMapper[0x32]			= TK_KEY_2;
	_win32KeyMapper[0x33]			= TK_KEY_3;
	_win32KeyMapper[0x34]			= TK_KEY_4;
	_win32KeyMapper[0x35]			= TK_KEY_5;
	_win32KeyMapper[0x36]			= TK_KEY_6;
	_win32KeyMapper[0x37]			= TK_KEY_7;
	_win32KeyMapper[0x38]			= TK_KEY_8;
	_win32KeyMapper[0x39]			= TK_KEY_9;
	_win32KeyMapper[VK_NUMPAD0]		= TK_KEY_NUMPAD_0;
	_win32KeyMapper[VK_NUMPAD1]		= TK_KEY_NUMPAD_1;
	_win32KeyMapper[VK_NUMPAD2]		= TK_KEY_NUMPAD_2;
	_win32KeyMapper[VK_NUMPAD3]		= TK_KEY_NUMPAD_3;
	_win32KeyMapper[VK_NUMPAD4]		= TK_KEY_NUMPAD_4;
	_win32KeyMapper[VK_NUMPAD5]		= TK_KEY_NUMPAD_5;
	_win32KeyMapper[VK_NUMPAD6]		= TK_KEY_NUMPAD_6;
	_win32KeyMapper[VK_NUMPAD7]		= TK_KEY_NUMPAD_7;
	_win32KeyMapper[VK_NUMPAD8]		= TK_KEY_NUMPAD_8;
	_win32KeyMapper[VK_NUMPAD9]		= TK_KEY_NUMPAD_9;
	_win32KeyMapper[VK_ADD]			= TK_KEY_NUMPAD_ADD;
	_win32KeyMapper[VK_SUBTRACT]	= TK_KEY_NUMPAD_SUBSTRACT;
	_win32KeyMapper[VK_RETURN]		= TK_KEY_RETURN;
	_win32KeyMapper[VK_ESCAPE]		= TK_KEY_ESCAPE;
	_win32KeyMapper[VK_SPACE]		= TK_KEY_SPACE;
	_win32KeyMapper[VK_BACK]		= TK_KEY_BACKSPACE;
	_win32KeyMapper[VK_DELETE]		= TK_KEY_DELETE;
	_win32KeyMapper[VK_PRIOR]		= TK_KEY_PAGE_UP;
	_win32KeyMapper[VK_NEXT]		= TK_KEY_PAGE_DOWN;
	_win32KeyMapper[VK_HOME]		= TK_KEY_HOME;
	_win32KeyMapper[VK_END]			= TK_KEY_END;
	_win32KeyMapper[VK_INSERT]		= TK_KEY_INSERT;
	_win32KeyMapper[VK_LSHIFT]		= TK_KEY_LSHIFT;
	_win32KeyMapper[VK_RSHIFT]		= TK_KEY_RSHIFT;
	_win32KeyMapper[VK_LCONTROL]	= TK_KEY_LCTRL;
	_win32KeyMapper[VK_RCONTROL]	= TK_KEY_RCTRL;
	_win32KeyMapper[VK_F1]			= TK_KEY_F1;
	_win32KeyMapper[VK_F2]			= TK_KEY_F2;
	_win32KeyMapper[VK_F3]			= TK_KEY_F3;
	_win32KeyMapper[VK_F4]			= TK_KEY_F4;
	_win32KeyMapper[VK_F5]			= TK_KEY_F5;
	_win32KeyMapper[VK_F6]			= TK_KEY_F6;
	_win32KeyMapper[VK_F7]			= TK_KEY_F7;
	_win32KeyMapper[VK_F8]			= TK_KEY_F8;
	_win32KeyMapper[VK_F9]			= TK_KEY_F9;
	_win32KeyMapper[VK_F10]			= TK_KEY_F10;
	_win32KeyMapper[VK_F11]			= TK_KEY_F11;
	_win32KeyMapper[VK_F12]			= TK_KEY_F12;
}
