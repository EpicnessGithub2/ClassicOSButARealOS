/*
 * PROJECT:     classicOS Shell Extensions
 * LICENSE:     LGPL - See COPYING in the top level directory
 * FILE:        dll/shellext/devcpux/processor.c
 * PURPOSE:
 * COPYRIGHT:   Copyright 2007 Christoph von Wittich <Christoph_vW@classicOS.org>
 *
 */

#define WIN32_NO_STATUS
#define _INC_WINDOWS
#define COM_NO_WINDOWS_H
#include <stdarg.h>
#include <windef.h>
#include <winbase.h>
#include <winreg.h>
#include <winuser.h>
#include <setupapi.h>
#include <powrprof.h>
#include <strsafe.h>

#include "resource.h"

HINSTANCE g_hInstance = NULL;
INT_PTR CALLBACK ProcessorDlgProc (HWND hDlg, UINT uMessage, WPARAM wParam, LPARAM lParam);

BOOL
APIENTRY
DllMain (HANDLE hInstance, DWORD dwReason, LPVOID lpReserved)
{
    switch (dwReason)
    {
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_ATTACH:
        case DLL_PROCESS_DETACH:
            break;
    }

    g_hInstance = (HINSTANCE) hInstance;
    return TRUE;
}


BOOL
APIENTRY
PropSheetExtProc(PSP_PROPSHEETPAGE_REQUEST PropPageRequest, LPFNADDPROPSHEETPAGE fAddFunc, LPARAM lParam)
{
    PROPSHEETPAGE PropSheetPage;
    HPROPSHEETPAGE hPropSheetPage;

    if(PropPageRequest->PageRequested != SPPSR_ENUM_ADV_DEVICE_PROPERTIES)
        return FALSE;

    if ((!PropPageRequest->DeviceInfoSet) || (!PropPageRequest->DeviceInfoData))
        return FALSE;

    ZeroMemory(&PropSheetPage, sizeof(PROPSHEETPAGE));
    PropSheetPage.dwSize = sizeof(PROPSHEETPAGE);
    PropSheetPage.hInstance = g_hInstance;
    PropSheetPage.pszTemplate = MAKEINTRESOURCE(DLG_PROCESSORINFO);
    PropSheetPage.pfnDlgProc = ProcessorDlgProc;

    hPropSheetPage = CreatePropertySheetPage(&PropSheetPage);
    if(!hPropSheetPage)
        return FALSE;

    if(!(fAddFunc)(hPropSheetPage, lParam)) {
        DestroyPropertySheetPage (hPropSheetPage);
        return FALSE;
    }

    return TRUE;
}

void
AddFeature(WCHAR* szFeatures, size_t cbDest, WCHAR* Feature, BOOL* bFirst)
{
    if (!*bFirst)
        StringCbCatW(szFeatures, cbDest, L", ");
    *bFirst = FALSE;
    StringCbCatW(szFeatures, cbDest, Feature);
}

INT_PTR
CALLBACK
ProcessorDlgProc (HWND hDlg, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
    switch (uMessage) {
        case WM_INITDIALOG:
        {
            WCHAR szFeatures[MAX_PATH] = L"";
            WCHAR szModel[3];
            WCHAR szStepping[3];
            WCHAR szMhz[16];
            WCHAR szCurrentMhz[10];
            BOOL bFirst = TRUE;
            SYSTEM_INFO SystemInfo;
            PROCESSOR_POWER_INFORMATION PowerInfo;

            if (!LoadStringW(g_hInstance, IDS_MEGAHERTZ, szMhz, ARRAYSIZE(szMhz)))
            {
                StringCbCopyW(szMhz, sizeof(szMhz), L"%ld MHz");
            }

            if (IsProcessorFeaturePresent(PF_MMX_INSTRUCTIONS_AVAILABLE))
                AddFeature(szFeatures, sizeof(szFeatures), L"MMX", &bFirst);
            if (IsProcessorFeaturePresent(PF_XMMI_INSTRUCTIONS_AVAILABLE))
                AddFeature(szFeatures, sizeof(szFeatures), L"SSE", &bFirst);
            if (IsProcessorFeaturePresent(PF_XMMI64_INSTRUCTIONS_AVAILABLE))
                AddFeature(szFeatures, sizeof(szFeatures), L"SSE2", &bFirst);
            /*if (IsProcessorFeaturePresent(PF_SSE3_INSTRUCTIONS_AVAILABLE))
                AddFeature(szFeatures, sizeof(szFeatures), L"SSE3", &bFirst); */
            if (IsProcessorFeaturePresent(PF_3DNOW_INSTRUCTIONS_AVAILABLE))
                AddFeature(szFeatures, sizeof(szFeatures), L"3DNOW", &bFirst);

            SetDlgItemTextW(hDlg, IDC_FEATURES, szFeatures);

            GetSystemInfo(&SystemInfo);

            StringCbPrintfW(szModel, sizeof(szModel), L"%x", HIBYTE(SystemInfo.wProcessorRevision));
            StringCbPrintfW(szStepping, sizeof(szStepping), L"%d", LOBYTE(SystemInfo.wProcessorRevision));

            SetDlgItemTextW(hDlg, IDC_MODEL, szModel);
            SetDlgItemTextW(hDlg, IDC_STEPPING, szStepping);

            CallNtPowerInformation(11, NULL, 0, &PowerInfo, sizeof(PowerInfo));
            StringCbPrintfW(szCurrentMhz, sizeof(szCurrentMhz), szMhz, PowerInfo.CurrentMhz);
            SetDlgItemTextW(hDlg, IDC_CORESPEED, szCurrentMhz);

            return TRUE;
        }
    }
    return FALSE;
}
