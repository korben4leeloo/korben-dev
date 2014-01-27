//*****************************************************************************
//
//	File:		OkdWindowsRawInputHandler.cpp
//	Created:	2013-08-26
//
//*****************************************************************************

#include	"OkdWindowsRawInputHandler.h"

// HID Usage Pages
#define	OKD_GENERIC_DESKTOP_DEVICE_USAGE_PAGE	0x01

// HID Usages
#define	OKD_MOUSE_USAGE							0x02
#define	OKD_KEYBOARD_USAGE						0x06

//-----------------------------------------------------------------------------
// Name:		OkdWindowsRawInputHandler constructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdWindowsRawInputHandler::OkdWindowsRawInputHandler()
{
	initializeDevices();
	initializeKeyMapping();
}

//-----------------------------------------------------------------------------
// Name:		OkdWindowsRawInputHandler destructor
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
OkdWindowsRawInputHandler::~OkdWindowsRawInputHandler()
{
	
}

//-----------------------------------------------------------------------------
// Name:		initializeDevices
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdWindowsRawInputHandler::initializeDevices()
{
	PRAWINPUTDEVICELIST pInputDeviceList = 0;
	UINT				uiDevicesCount;
	UINT				uiResult;

	uiResult = GetRawInputDeviceList( 0, &uiDevicesCount, sizeof(RAWINPUTDEVICELIST) );
	ORKID_ASSERT( uiResult != (UINT)-1 );

	if	( uiDevicesCount > 0 )
	{
		RAWINPUTDEVICE* pRegisterInputDevices	= new RAWINPUTDEVICE[uiDevicesCount];
		UINT			uiRegisterDevicesCount	= 0;

		pInputDeviceList	= new RAWINPUTDEVICELIST[uiDevicesCount];
		uiResult			= GetRawInputDeviceList( pInputDeviceList, &uiDevicesCount, sizeof(RAWINPUTDEVICELIST) );

		ORKID_ASSERT( uiResult == uiDevicesCount );

		for	( uint32 i = 0; i < uiDevicesCount; i++ )
		{
			UINT			uiDataSize;
			char*			pData;
			RID_DEVICE_INFO	deviceInfo;

			deviceInfo.cbSize = sizeof(RID_DEVICE_INFO);

			uiResult = GetRawInputDeviceInfo( pInputDeviceList[i].hDevice, RIDI_DEVICEINFO, 0, &uiDataSize );
			ORKID_ASSERT( uiResult == 0 );

			pData = new char[uiDataSize];
			uiResult = GetRawInputDeviceInfo( pInputDeviceList[i].hDevice, RIDI_DEVICEINFO, &deviceInfo, &uiDataSize );

			switch	( deviceInfo.dwType )
			{
			case RIM_TYPEMOUSE:
				{
					pRegisterInputDevices[uiRegisterDevicesCount].usUsagePage	= OKD_GENERIC_DESKTOP_DEVICE_USAGE_PAGE;
					pRegisterInputDevices[uiRegisterDevicesCount].usUsage		= OKD_MOUSE_USAGE;
					pRegisterInputDevices[uiRegisterDevicesCount].dwFlags		= 0;
					pRegisterInputDevices[uiRegisterDevicesCount].hwndTarget	= 0;
					uiRegisterDevicesCount++;
				}
				break;

			case RIM_TYPEKEYBOARD:
				{
					pRegisterInputDevices[uiRegisterDevicesCount].usUsagePage	= OKD_GENERIC_DESKTOP_DEVICE_USAGE_PAGE;
					pRegisterInputDevices[uiRegisterDevicesCount].usUsage		= OKD_KEYBOARD_USAGE;
					pRegisterInputDevices[uiRegisterDevicesCount].dwFlags		= 0;
					pRegisterInputDevices[uiRegisterDevicesCount].hwndTarget	= 0;
					uiRegisterDevicesCount++;
				}
				break;

			case RIM_TYPEHID:
				break;

			default:
				ORKID_BREAK();
				break;
			}

			delete[] pData;
		}

		if	( uiRegisterDevicesCount > 0 )
		{
			BOOL bResult = RegisterRawInputDevices( pRegisterInputDevices, uiRegisterDevicesCount, sizeof(RAWINPUTDEVICE) );
			ORKID_ASSERT( bResult == TRUE );
		}

		delete[] pRegisterInputDevices;
		delete[] pInputDeviceList;
	}
}

//-----------------------------------------------------------------------------
// Name:		initializeKeyMapping
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdWindowsRawInputHandler::initializeKeyMapping()
{
	memset( _keyMapping, OkdKey_Unknown, sizeof(_keyMapping) / sizeof(OkdKeyCode) );

	// Map Windows virtual key codes to OkdKeyCode
	_keyMapping[0x41] = OkdKey_A;
	_keyMapping[0x42] = OkdKey_B;
	_keyMapping[0x43] = OkdKey_C;
	_keyMapping[0x44] = OkdKey_D;
	_keyMapping[0x45] = OkdKey_E;
	_keyMapping[0x46] = OkdKey_F;
	_keyMapping[0x47] = OkdKey_G;
	_keyMapping[0x48] = OkdKey_H;
	_keyMapping[0x49] = OkdKey_I;
	_keyMapping[0x4A] = OkdKey_J;
	_keyMapping[0x4B] = OkdKey_K;
	_keyMapping[0x4C] = OkdKey_L;
	_keyMapping[0x4D] = OkdKey_M;
	_keyMapping[0x4E] = OkdKey_N;
	_keyMapping[0x4F] = OkdKey_O;
	_keyMapping[0x50] = OkdKey_P;
	_keyMapping[0x51] = OkdKey_Q;
	_keyMapping[0x52] = OkdKey_R;
	_keyMapping[0x53] = OkdKey_S;
	_keyMapping[0x54] = OkdKey_T;
	_keyMapping[0x55] = OkdKey_U;
	_keyMapping[0x56] = OkdKey_V;
	_keyMapping[0x57] = OkdKey_W;
	_keyMapping[0x58] = OkdKey_X;
	_keyMapping[0x59] = OkdKey_Y;
	_keyMapping[0x5A] = OkdKey_Z;
	
	_keyMapping[0x30] = OkdKey_0;
	_keyMapping[0x31] = OkdKey_1;
	_keyMapping[0x32] = OkdKey_2;
	_keyMapping[0x33] = OkdKey_3;
	_keyMapping[0x34] = OkdKey_4;
	_keyMapping[0x35] = OkdKey_5;
	_keyMapping[0x36] = OkdKey_6;
	_keyMapping[0x37] = OkdKey_7;
	_keyMapping[0x38] = OkdKey_8;
	_keyMapping[0x39] = OkdKey_9;
	
	_keyMapping[VK_NUMPAD0] = OkdKey_NumPad0;
	_keyMapping[VK_NUMPAD1] = OkdKey_NumPad1;
	_keyMapping[VK_NUMPAD2] = OkdKey_NumPad2;
	_keyMapping[VK_NUMPAD3] = OkdKey_NumPad3;
	_keyMapping[VK_NUMPAD4] = OkdKey_NumPad4;
	_keyMapping[VK_NUMPAD5] = OkdKey_NumPad5;
	_keyMapping[VK_NUMPAD6] = OkdKey_NumPad6;
	_keyMapping[VK_NUMPAD7] = OkdKey_NumPad7;
	_keyMapping[VK_NUMPAD8] = OkdKey_NumPad8;
	_keyMapping[VK_NUMPAD9] = OkdKey_NumPad9;
	
	_keyMapping[VK_LSHIFT]		= OkdKey_LeftShift;
	_keyMapping[VK_LCONTROL]	= OkdKey_LeftControl;
	_keyMapping[VK_LMENU]		= OkdKey_LeftAlt;
	
	_keyMapping[VK_RSHIFT]		= OkdKey_RightShift;
	_keyMapping[VK_RCONTROL]	= OkdKey_RightControl;
	_keyMapping[VK_RMENU]		= OkdKey_RightAlt;
	
	_keyMapping[VK_F1]	= OkdKey_F1;
	_keyMapping[VK_F2]	= OkdKey_F2;
	_keyMapping[VK_F3]	= OkdKey_F3;
	_keyMapping[VK_F4]	= OkdKey_F4;
	_keyMapping[VK_F5]	= OkdKey_F5;
	_keyMapping[VK_F6]	= OkdKey_F6;
	_keyMapping[VK_F7]	= OkdKey_F7;
	_keyMapping[VK_F8]	= OkdKey_F8;
	_keyMapping[VK_F9]	= OkdKey_F9;
	_keyMapping[VK_F10]	= OkdKey_F10;
	_keyMapping[VK_F11]	= OkdKey_F11;
	_keyMapping[VK_F12]	= OkdKey_F12;
	
	_keyMapping[VK_RETURN]	= OkdKey_Return;
	_keyMapping[VK_SPACE]	= OkdKey_Space;
	_keyMapping[VK_DELETE]	= OkdKey_Delete;
	_keyMapping[VK_BACK]	= OkdKey_Backspace;
	_keyMapping[VK_TAB]		= OkdKey_Tab;
	_keyMapping[VK_ESCAPE]	= OkdKey_Escape;
}

//-----------------------------------------------------------------------------
// Name:		process
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
void	OkdWindowsRawInputHandler::process(HRAWINPUT	hRawInput)
{
	UINT		dwSize;
	RAWINPUT*	pRawInputData;

	GetRawInputData( hRawInput, RID_INPUT, 0, &dwSize, sizeof(RAWINPUTHEADER) );
	pRawInputData = (RAWINPUT*)(new BYTE[dwSize]);

	GetRawInputData( hRawInput, RID_INPUT, pRawInputData, &dwSize, sizeof(RAWINPUTHEADER) );


}
