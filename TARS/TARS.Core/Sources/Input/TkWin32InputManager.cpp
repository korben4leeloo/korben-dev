//*****************************************************************************
//
//	File:		TkWin32InputManager.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include "TkWin32InputManager.h"

#include <Windows.h>

#define HID_USAGE_PAGE_GENERIC	1
#define HID_USAGE_KEYBOARD		6
#define HID_USAGE_MOUSE			2

//-----------------------------------------------------------------------------
// Name:		TkWin32InputManager constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkWin32InputManager::TkWin32InputManager()
{
	
}

//-----------------------------------------------------------------------------
// Name:		TkWin32InputManager destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
TkWin32InputManager::~TkWin32InputManager()
{
	
}

//-----------------------------------------------------------------------------
// Name:		registerDevices
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void TkWin32InputManager::registerDevices()
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
		TARS_ASSERT( 0 );
	}
}

//-----------------------------------------------------------------------------
// Name:		enumDevices
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void TkWin32InputManager::enumDevices()
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
