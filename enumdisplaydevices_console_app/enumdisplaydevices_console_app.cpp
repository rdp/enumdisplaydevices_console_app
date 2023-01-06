// enumdisplaydevices_console_app.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>


int _tmain(int argc, _TCHAR* argv[])
{
	DISPLAY_DEVICE lDevice;
	lDevice.cb = sizeof(DISPLAY_DEVICE);
	int i = 0;
	while (EnumDisplayDevices(NULL, i, &lDevice, NULL) != 0) {
		wprintf(TEXT("display i: %d\ncb: %d\nDeviceName: %s\nDeviceString: %s\nStateFlags: %d\nDeviceID: %s\nDeviceKey: %s\n"),
			i,
			lDevice.cb,
			lDevice.DeviceName,
			lDevice.DeviceString,
			lDevice.StateFlags,
			lDevice.DeviceID,
			lDevice.DeviceKey
			);

		if (lDevice.StateFlags & DISPLAY_DEVICE_ATTACHED_TO_DESKTOP)
			printf("attached to desktop\n");

		if (lDevice.StateFlags & DISPLAY_DEVICE_PRIMARY_DEVICE)
			printf("device primary device\n");

	    if (lDevice.StateFlags & DISPLAY_DEVICE_ACTIVE)
			printf("display active\n");


		DISPLAY_DEVICE lDevice2;
		lDevice2.cb = sizeof(DISPLAY_DEVICE);
		int i2 = 0;
		while (EnumDisplayDevices(lDevice.DeviceName, i2, &lDevice2, NULL) != 0) {
			wprintf(TEXT("  Attached monitor i: %d of device %d\n  cb: %d\n  DeviceName: %s\n  DeviceString: %s\n  StateFlags: %d\n  DeviceID: %s\n  DeviceKey: %s\n"),
				i2,
				i,
				lDevice2.cb,
				lDevice2.DeviceName,
				lDevice2.DeviceString,
				lDevice2.StateFlags,
				lDevice2.DeviceID,
				lDevice2.DeviceKey
				);

			i2++;
		}


		i++;
	}

	return 0;
}

