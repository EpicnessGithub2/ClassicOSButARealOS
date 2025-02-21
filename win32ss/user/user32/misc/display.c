/*
 * PROJECT:         classicOS user32.dll
 * FILE:            win32ss/user/user32/misc/display.c
 * PURPOSE:         DDE
 * PROGRAMMER:      Casper S. Hornstrup (chorns@users.sourceforge.net)
 */

#include <user32.h>

WINE_DEFAULT_DEBUG_CHANNEL(user32);

#define SIZEOF_DEVMODEA_300 124
#define SIZEOF_DEVMODEA_400 148
#define SIZEOF_DEVMODEA_500 156
#define SIZEOF_DEVMODEW_300 188
#define SIZEOF_DEVMODEW_400 212
#define SIZEOF_DEVMODEW_500 220

/*
 * @implemented
 */
BOOL WINAPI
EnumDisplayDevicesA(
    LPCSTR lpDevice,
    DWORD iDevNum,
    PDISPLAY_DEVICEA lpDisplayDevice,
    DWORD dwFlags)
{
    BOOL rc;
    UNICODE_STRING Device;
    DISPLAY_DEVICEW DisplayDeviceW;

    if (!RtlCreateUnicodeStringFromAsciiz(&Device, (PCSZ)lpDevice))
    {
        SetLastError(ERROR_OUTOFMEMORY);
        return FALSE;
    }

    RtlZeroMemory(&DisplayDeviceW, sizeof(DISPLAY_DEVICEW));
    DisplayDeviceW.cb = sizeof(DISPLAY_DEVICEW);
    rc = NtUserEnumDisplayDevices(&Device,
                                  iDevNum,
                                  &DisplayDeviceW,
                                  dwFlags);
    if (rc)
    {
        /* Copy result from DisplayDeviceW to lpDisplayDevice. Buffers have the same size so result is always NULL terminated. */
        lpDisplayDevice->StateFlags = DisplayDeviceW.StateFlags;
        WideCharToMultiByte(CP_ACP, 0, DisplayDeviceW.DeviceName, -1,
                            lpDisplayDevice->DeviceName,
                            sizeof(lpDisplayDevice->DeviceName) / sizeof(lpDisplayDevice->DeviceName[0]),
                            NULL, NULL);
        WideCharToMultiByte(CP_ACP, 0, DisplayDeviceW.DeviceString, -1,
                            lpDisplayDevice->DeviceString,
                            sizeof(lpDisplayDevice->DeviceString) / sizeof(lpDisplayDevice->DeviceString[0]),
                            NULL, NULL);
        WideCharToMultiByte(CP_ACP, 0, DisplayDeviceW.DeviceID, -1,
                            lpDisplayDevice->DeviceID,
                            sizeof(lpDisplayDevice->DeviceID) / sizeof(lpDisplayDevice->DeviceID[0]),
                            NULL, NULL);
        WideCharToMultiByte(CP_ACP, 0, DisplayDeviceW.DeviceKey, -1,
                            lpDisplayDevice->DeviceKey,
                            sizeof(lpDisplayDevice->DeviceKey) / sizeof(lpDisplayDevice->DeviceKey[0]),
                            NULL, NULL);
    }

    RtlFreeUnicodeString(&Device);

    return rc;
}


/*
 * @implemented
 */
BOOL
WINAPI
EnumDisplayDevicesW(
    LPCWSTR lpDevice,
    DWORD iDevNum,
    PDISPLAY_DEVICEW lpDisplayDevice,
    DWORD dwFlags)
{
    UNICODE_STRING Device;
    BOOL rc;

    RtlInitUnicodeString(&Device, lpDevice);

    rc = NtUserEnumDisplayDevices(
             &Device,
             iDevNum,
             lpDisplayDevice,
             dwFlags);

    return rc;
}


/*
 * @implemented
 */
BOOL
WINAPI
EnumDisplayMonitors(
    HDC hdc,
    LPCRECT lprcClip,
    MONITORENUMPROC lpfnEnum,
    LPARAM dwData)
{
    INT iCount, i;
    HMONITOR *hMonitorList;
    LPRECT pRectList;
    HANDLE hHeap;
    BOOL ret = FALSE;

    /* get list of monitors/rects */
    iCount = NtUserEnumDisplayMonitors(hdc, lprcClip, NULL, NULL, 0);
    if (iCount < 0)
    {
        /* FIXME: SetLastError() */
        return FALSE;
    }
    if (iCount == 0)
    {
        return TRUE;
    }

    hHeap = GetProcessHeap();
    hMonitorList = HeapAlloc(hHeap, 0, sizeof (HMONITOR) * iCount);
    if (hMonitorList == NULL)
    {
        SetLastError(ERROR_NOT_ENOUGH_MEMORY);
        return FALSE;
    }
    pRectList = HeapAlloc(hHeap, 0, sizeof (RECT) * iCount);
    if (pRectList == NULL)
    {
        SetLastError(ERROR_NOT_ENOUGH_MEMORY);
        goto cleanup;
    }

    iCount = NtUserEnumDisplayMonitors(hdc, lprcClip, hMonitorList, pRectList, iCount);
    if (iCount <= 0)
    {
        /* FIXME: SetLastError() */
        goto cleanup;
    }

    /* enumerate list */
    for (i = 0; i < iCount; i++)
    {
        HMONITOR hMonitor = hMonitorList[i];
        LPRECT pMonitorRect = pRectList + i;
        HDC hMonitorDC = NULL;

        if (hdc != NULL)
        {
            /* make monitor DC */
            hMonitorDC = hdc;
        }

        if (!lpfnEnum(hMonitor, hMonitorDC, pMonitorRect, dwData))
            goto cleanup; /* return FALSE */
    }

    ret = TRUE;

cleanup:
    if(hMonitorList)
        HeapFree(hHeap, 0, hMonitorList);
    if(pRectList)
        HeapFree(hHeap, 0, pRectList);
    return ret;
}


/*
 * @implemented
 */
BOOL
WINAPI
EnumDisplaySettingsExA(
    LPCSTR lpszDeviceName,
    DWORD iModeNum,
    LPDEVMODEA lpDevMode,
    DWORD dwFlags)
{
    NTSTATUS Status;
    UNICODE_STRING usDeviceName;
    PUNICODE_STRING pusDeviceName = NULL;
    LPDEVMODEW lpExtendedDevMode;
    BOOL Result = FALSE;

    if (lpszDeviceName)
    {
        if (!RtlCreateUnicodeStringFromAsciiz(&usDeviceName, (PCSZ)lpszDeviceName))
        {
            SetLastError(ERROR_OUTOFMEMORY);
            return FALSE;
        }
        pusDeviceName = &usDeviceName;
    }

    /* Allocate memory for DEVMODEW and extra data */
    lpExtendedDevMode = RtlAllocateHeap(RtlGetProcessHeap(),
                                        HEAP_ZERO_MEMORY,
                                        sizeof(DEVMODEW) + lpDevMode->dmDriverExtra);
    if (!lpExtendedDevMode)
    {
        if (pusDeviceName)
            RtlFreeUnicodeString(&usDeviceName);

        return FALSE;
    }

    /* Initialize structure fields */
    lpExtendedDevMode->dmSize = sizeof(DEVMODEW);
    lpExtendedDevMode->dmDriverExtra = lpDevMode->dmDriverExtra;

    Status = NtUserEnumDisplaySettings(pusDeviceName, iModeNum, lpExtendedDevMode, dwFlags);

    if (pusDeviceName)
        RtlFreeUnicodeString(&usDeviceName);

    if (NT_SUCCESS(Status))
    {
        /* Store old structure size */
        WORD OldSize = lpDevMode->dmSize;

#define COPYS(f,len) WideCharToMultiByte(CP_THREAD_ACP, 0, lpExtendedDevMode->f, len, (LPSTR)lpDevMode->f, len, NULL, NULL)
#define COPYN(f) lpDevMode->f = lpExtendedDevMode->f

        COPYS(dmDeviceName, CCHDEVICENAME);
        COPYN(dmSpecVersion);
        COPYN(dmDriverVersion);
        COPYN(dmFields);
        COPYN(dmPosition.x);
        COPYN(dmPosition.y);
        COPYN(dmScale);
        COPYN(dmCopies);
        COPYN(dmDefaultSource);
        COPYN(dmPrintQuality);
        COPYN(dmColor);
        COPYN(dmDuplex);
        COPYN(dmYResolution);
        COPYN(dmTTOption);
        COPYN(dmCollate);
        COPYS(dmFormName,CCHFORMNAME);
        COPYN(dmLogPixels);
        COPYN(dmBitsPerPel);
        COPYN(dmPelsWidth);
        COPYN(dmPelsHeight);
        COPYN(dmDisplayFlags); // aka dmNup
        COPYN(dmDisplayFrequency);

        /* we're done with 0x300 fields */
        if (OldSize > SIZEOF_DEVMODEA_300)
        {
            COPYN(dmICMMethod);
            COPYN(dmICMIntent);
            COPYN(dmMediaType);
            COPYN(dmDitherType);
            COPYN(dmReserved1);
            COPYN(dmReserved2);

            /* we're done with 0x400 fields */
            if (OldSize > SIZEOF_DEVMODEA_400)
            {
                COPYN(dmPanningWidth);
                COPYN(dmPanningHeight);
            }
        }

        /* Restore old size */
        lpDevMode->dmSize = OldSize;

        /* Extra data presented? */
        if (lpDevMode->dmDriverExtra && lpExtendedDevMode->dmDriverExtra)
        {
            /* We choose the smallest size */
            if (lpDevMode->dmDriverExtra > lpExtendedDevMode->dmDriverExtra)
                lpDevMode->dmDriverExtra = lpExtendedDevMode->dmDriverExtra;

            /* Copy extra data */
            RtlCopyMemory((PUCHAR)lpDevMode + OldSize,
                          lpExtendedDevMode + 1,
                          lpDevMode->dmDriverExtra);
        }

        /* If the size of source structure is less, than used, we clean unsupported flags */
        if (OldSize < FIELD_OFFSET(DEVMODEA, dmPanningHeight))
            lpDevMode->dmFields &= ~DM_PANNINGHEIGHT;

        if (OldSize < FIELD_OFFSET(DEVMODEA, dmPanningWidth))
            lpDevMode->dmFields &= ~DM_PANNINGWIDTH;

        Result = TRUE;
    }

    /* Free memory */
    RtlFreeHeap(RtlGetProcessHeap(), 0, lpExtendedDevMode);

    return Result;
}


/*
 * @implemented
 */
BOOL
WINAPI
EnumDisplaySettingsA(
    LPCSTR lpszDeviceName,
    DWORD iModeNum,
    LPDEVMODEA lpDevMode)
{
    /* Fixup sizes */
    lpDevMode->dmSize = FIELD_OFFSET(DEVMODEA, dmICMMethod);
    lpDevMode->dmDriverExtra = 0;

    return EnumDisplaySettingsExA(lpszDeviceName, iModeNum, lpDevMode, 0);
}


/*
 * @implemented
 */
BOOL
WINAPI
EnumDisplaySettingsExW(
    LPCWSTR lpszDeviceName,
    DWORD iModeNum,
    LPDEVMODEW lpDevMode,
    DWORD dwFlags)
{
    NTSTATUS Status;
    UNICODE_STRING usDeviceName;
    PUNICODE_STRING pusDeviceName = NULL;
    LPDEVMODEW lpExtendedDevMode;
    BOOL Result = FALSE;

    if (lpszDeviceName)
    {
        RtlInitUnicodeString(&usDeviceName, lpszDeviceName);
        pusDeviceName = &usDeviceName;
    }

    /* Allocate memory for DEVMODEW and extra data */
    lpExtendedDevMode = RtlAllocateHeap(RtlGetProcessHeap(),
                                        HEAP_ZERO_MEMORY,
                                        sizeof(DEVMODEW) + lpDevMode->dmDriverExtra);
    if (!lpExtendedDevMode)
        return FALSE;

    /* Initialize structure fields */
    lpExtendedDevMode->dmSize = sizeof(DEVMODEW);
    lpExtendedDevMode->dmDriverExtra = lpDevMode->dmDriverExtra;

    Status = NtUserEnumDisplaySettings(pusDeviceName, iModeNum, lpExtendedDevMode, dwFlags);
    if (NT_SUCCESS(Status))
    {
        /* Store old structure sizes */
        WORD OldSize = lpDevMode->dmSize;
        WORD OldDriverExtra = lpDevMode->dmDriverExtra;

        /* Copy general data */
        RtlCopyMemory(lpDevMode, lpExtendedDevMode, OldSize);

        /* Restore old sizes */
        lpDevMode->dmSize = OldSize;
        lpDevMode->dmDriverExtra = OldDriverExtra;

        /* Extra data presented? */
        if (lpDevMode->dmDriverExtra && lpExtendedDevMode->dmDriverExtra)
        {
            /* We choose the smallest size */
            if (lpDevMode->dmDriverExtra > lpExtendedDevMode->dmDriverExtra)
                lpDevMode->dmDriverExtra = lpExtendedDevMode->dmDriverExtra;

            /* Copy extra data */
            RtlCopyMemory((PUCHAR)lpDevMode + OldSize,
                          lpExtendedDevMode + 1,
                          lpDevMode->dmDriverExtra);
        }

        /* If the size of source structure is less, than used, we clean unsupported flags */
        if (OldSize < FIELD_OFFSET(DEVMODEW, dmPanningHeight))
            lpDevMode->dmFields &= ~DM_PANNINGHEIGHT;

        if (OldSize < FIELD_OFFSET(DEVMODEW, dmPanningWidth))
            lpDevMode->dmFields &= ~DM_PANNINGWIDTH;

        Result = TRUE;
    }

    /* Free memory */
    RtlFreeHeap(RtlGetProcessHeap(), 0, lpExtendedDevMode);

    return Result;
}


/*
 * @implemented
 */
BOOL
WINAPI
EnumDisplaySettingsW(
    LPCWSTR lpszDeviceName,
    DWORD iModeNum,
    LPDEVMODEW lpDevMode)
{
    /* Fixup sizes */
    lpDevMode->dmSize = FIELD_OFFSET(DEVMODEW, dmICMMethod);
    lpDevMode->dmDriverExtra = 0;

    return EnumDisplaySettingsExW(lpszDeviceName, iModeNum, lpDevMode, 0);
}


/*
 * @implemented
 */
BOOL
WINAPI
GetMonitorInfoA(
    HMONITOR hMonitor,
    LPMONITORINFO lpmi)
{
    if (lpmi->cbSize == sizeof (MONITORINFO))
    {
        return NtUserGetMonitorInfo(hMonitor, lpmi);
    }
    else if (lpmi->cbSize != sizeof (MONITORINFOEXA))
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return FALSE;
    }
    else
    {
        MONITORINFOEXW miExW;
        INT res;

        miExW.cbSize = sizeof (MONITORINFOEXW);
        if (!NtUserGetMonitorInfo(hMonitor, (LPMONITORINFO)&miExW))
        {
            return FALSE;
        }
        memcpy(lpmi, &miExW, sizeof (MONITORINFO));
        res = WideCharToMultiByte(CP_THREAD_ACP, 0, miExW.szDevice, -1,
                                  ((LPMONITORINFOEXA)lpmi)->szDevice, CCHDEVICENAME,
                                  NULL, NULL);
        if (res == 0)
        {
            WARN("WideCharToMultiByte() failed!\n");
            return FALSE;
        }
    }

    return TRUE;
}


/*
 * @implemented
 */
BOOL
WINAPI
GetMonitorInfoW(
    HMONITOR hMonitor,
    LPMONITORINFO lpmi)
{
    return NtUserGetMonitorInfo(hMonitor, lpmi);
}


/*
 * @implemented
 */
HMONITOR
WINAPI
MonitorFromPoint(
    IN POINT ptPoint,
    IN DWORD dwFlags )
{
    return NtUserMonitorFromPoint(ptPoint, dwFlags);
}


/*
 * @implemented
 */
HMONITOR
WINAPI
MonitorFromRect(
    IN LPCRECT lpcRect,
    IN DWORD dwFlags )
{
    return NtUserMonitorFromRect(lpcRect, dwFlags);
}


/*
 * @implemented
 */
HMONITOR
WINAPI
MonitorFromWindow(
    IN HWND hWnd,
    IN DWORD dwFlags )
{
    return NtUserMonitorFromWindow(hWnd, dwFlags);
}


/*
 * @implemented
 */
LONG
WINAPI
ChangeDisplaySettingsExA(
    LPCSTR lpszDeviceName,
    LPDEVMODEA lpDevMode,
    HWND hwnd,
    DWORD dwflags,
    LPVOID lParam)
{
    LONG rc;
    UNICODE_STRING DeviceName;
    PUNICODE_STRING pDeviceName = &DeviceName;

    if (lpszDeviceName != NULL)
    {
        if (!RtlCreateUnicodeStringFromAsciiz(pDeviceName, (PCSZ)lpszDeviceName))
        {
            SetLastError(ERROR_OUTOFMEMORY);
            return DISP_CHANGE_BADPARAM; /* FIXME what to return? */
        }
    }
    else
        pDeviceName = NULL;

    if (lpDevMode != NULL)
    {
        LPDEVMODEW pDevModeW;
        pDevModeW = GdiConvertToDevmodeW(lpDevMode);
        if(pDevModeW)
        {
            rc = NtUserChangeDisplaySettings(pDeviceName, pDevModeW, dwflags, lParam);
            RtlFreeHeap(GetProcessHeap(), 0, pDevModeW);
        }
        else
            rc = DISP_CHANGE_SUCCESSFUL;
    }
    else
        rc = NtUserChangeDisplaySettings(pDeviceName, NULL, dwflags, lParam);

    if (lpszDeviceName != NULL)
        RtlFreeUnicodeString(&DeviceName);

    return rc;
}


/*
 * @implemented
 */
LONG
WINAPI
ChangeDisplaySettingsA(
    LPDEVMODEA lpDevMode,
    DWORD dwflags)
{
    if(lpDevMode)
        lpDevMode->dmDriverExtra = 0;
    return ChangeDisplaySettingsExA ( NULL, lpDevMode, NULL, dwflags, 0 );
}


/*
 * @implemented
 */
LONG
WINAPI
ChangeDisplaySettingsExW(
    LPCWSTR lpszDeviceName,
    LPDEVMODEW lpDevMode,
    HWND hwnd,
    DWORD dwflags,
    LPVOID lParam)
{
    LONG rc;
    UNICODE_STRING DeviceName;
    PUNICODE_STRING pDeviceName = &DeviceName;

    if (lpszDeviceName != NULL)
        RtlInitUnicodeString(pDeviceName, lpszDeviceName);
    else
        pDeviceName = NULL;

    rc = NtUserChangeDisplaySettings(pDeviceName, lpDevMode, dwflags, lParam);

    return rc;
}


/*
 * @implemented
 */
LONG
WINAPI
ChangeDisplaySettingsW(
    LPDEVMODEW lpDevMode,
    DWORD dwflags)
{
    if(lpDevMode)
        lpDevMode->dmDriverExtra = 0;
    return ChangeDisplaySettingsExW(NULL, lpDevMode, NULL, dwflags, 0);
}
