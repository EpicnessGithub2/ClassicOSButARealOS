/*
 * COPYRIGHT:   See COPYING in the top level directory
 * PROJECT:     classicOS SerialUI DLL
 * FILE:        serialui.h
 * PURPOSE:     header file
 * PROGRAMMERS: Saveliy Tretiakov (saveliyt@mail.ru)
 */

#define WIN32_NO_STATUS
#define _INC_WINDOWS
#define COM_NO_WINDOWS_H
#include <stdarg.h>
#include <windef.h>
#include <winbase.h>
#include <winuser.h>
#include <winnls.h>

#include "resource.h"

#define UNIMPLEMENTED \
  return ERROR_CALL_NOT_IMPLEMENTED ;

#define DEFAULT_BAUD_INDEX 6
#define DEFAULT_BYTESIZE_INDEX 3
#define DEFAULT_PARITY_INDEX 2
#define DEFAULT_STOPBITS_INDEX 0

typedef struct _DIALOG_INFO
{
	LPCWSTR lpszDevice;
	UINT InitialFlowIndex;
	LPCOMMCONFIG lpCC;
} DIALOG_INFO, *LPDIALOG_INFO;

typedef struct _PARITY_INFO
{
	BYTE Parity;
	UINT StrId;
} PARITY_INFO, *PPARITY_INFO;

typedef struct _STOPBIT_INFO
{
	BYTE StopBit;
	UINT StrId;
} STOPBIT_INFO, *PSTOPBIT_INFO;


/************************************
 *
 *  EXPORTS
 *
 ************************************/

DWORD WINAPI drvCommConfigDialogW(LPCWSTR lpszDevice,
	HWND hWnd,
	LPCOMMCONFIG lpCommConfig);

DWORD WINAPI drvCommConfigDialogA(LPCSTR lpszDevice,
	HWND hWnd,
	LPCOMMCONFIG lpCommConfig);

DWORD WINAPI drvSetDefaultCommConfigW(LPCWSTR lpszDevice,
	LPCOMMCONFIG lpCommConfig,
	DWORD dwSize);

DWORD WINAPI drvSetDefaultCommConfigA(LPCSTR lpszDevice,
	LPCOMMCONFIG lpCommConfig,
	DWORD dwSize);

DWORD WINAPI drvGetDefaultCommConfigW(LPCWSTR lpszDevice,
	LPCOMMCONFIG lpCommConfig,
	LPDWORD lpdwSize);

DWORD WINAPI drvGetDefaultCommConfigA(LPCSTR lpszDevice,
	LPCOMMCONFIG lpCommConfig,
	LPDWORD lpdwSize);


/************************************
 *
 *  INTERNALS
 *
 ************************************/

INT_PTR
CALLBACK
CommDlgProc(
	HWND hDlg,
	UINT Msg,
	WPARAM wParam,
	LPARAM lParam);

VOID OkButton(HWND hDlg);


