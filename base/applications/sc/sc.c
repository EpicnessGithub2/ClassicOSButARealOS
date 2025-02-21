/*
 * PROJECT:     classicOS Services
 * LICENSE:     GPL - See COPYING in the top level directory
 * FILE:        base/applications/sc/sc.c
 * PURPOSE:     parse command line
 * COPYRIGHT:   Copyright 2005 - 2006 Ged Murphy <gedmurphy@gmail.com>
 *
 */

#include "sc.h"

SC_HANDLE hSCManager;

VOID
ReportLastError(VOID)
{
    LPVOID lpMsgBuf;
    DWORD RetVal;

    DWORD ErrorCode = GetLastError();
    if (ErrorCode != ERROR_SUCCESS)
    {
        RetVal = FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
                               FORMAT_MESSAGE_FROM_SYSTEM |
                               FORMAT_MESSAGE_IGNORE_INSERTS,
                               NULL,
                               ErrorCode,
                               MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), /* Default language */
                               (LPTSTR) &lpMsgBuf,
                               0,
                               NULL );

        if (RetVal != 0)
        {
            _tprintf(_T("%s"), (LPTSTR)lpMsgBuf);
            LocalFree(lpMsgBuf);
        }
    }
}


static INT
ScControl(LPCTSTR Server,       // remote machine name
          LPCTSTR Command,      // sc command
          LPCTSTR *ServiceArgs, // any options
          DWORD ArgCount)       // argument counter
{
    LPCTSTR ServiceName = NULL;

    if (Server)
    {
        _tprintf(_T("Remote service control is not yet implemented\n"));
        return 2;
    }

    if (!lstrcmpi(Command, _T("query")))
    {
        Query(ServiceArgs,
              ArgCount,
              FALSE);
    }
    else if (!lstrcmpi(Command, _T("queryex")))
    {
        Query(ServiceArgs,
              ArgCount,
              TRUE);
    }
    else if (!lstrcmpi(Command, _T("start")))
    {
        if (ArgCount > 0)
        {
            ServiceName = *ServiceArgs++;
            ArgCount--;

            Start(ServiceName,
                  ServiceArgs,
                  ArgCount);
        }
        else
            StartUsage();
    }
    else if (!lstrcmpi(Command, _T("pause")))
    {
        if (ArgCount > 0)
        {
            ServiceName = *ServiceArgs++;
            ArgCount--;

            Control(SERVICE_CONTROL_PAUSE,
                    ServiceName,
                    ServiceArgs,
                    ArgCount);
        }
        else
            PauseUsage();
    }
    else if (!lstrcmpi(Command, _T("interrogate")))
    {
        if (ArgCount > 0)
        {
            ServiceName = *ServiceArgs++;
            ArgCount--;

            Control(SERVICE_CONTROL_INTERROGATE,
                    ServiceName,
                    ServiceArgs,
                    ArgCount);
        }
        else
            InterrogateUsage();
    }
    else if (!lstrcmpi(Command, _T("stop")))
    {
        if (ArgCount > 0)
        {
            ServiceName = *ServiceArgs++;
            ArgCount--;

            Control(SERVICE_CONTROL_STOP,
                    ServiceName,
                    ServiceArgs,
                    ArgCount);
        }
        else
            StopUsage();
    }
    else if (!lstrcmpi(Command, _T("continue")))
    {
        if (ArgCount > 0)
        {
            ServiceName = *ServiceArgs++;
            ArgCount--;

            Control(SERVICE_CONTROL_CONTINUE,
                    ServiceName,
                    ServiceArgs,
                    ArgCount);
        }
        else
            ContinueUsage();
    }
    else if (!lstrcmpi(Command, _T("delete")))
    {
        if (ArgCount > 0)
        {
            ServiceName = *ServiceArgs++;
            ArgCount--;

            Delete(ServiceName);
        }
        else
            DeleteUsage();
    }
    else if (!lstrcmpi(Command, _T("create")))
    {
        Create(ServiceArgs, ArgCount);
    }
    else if (!lstrcmpi(Command, _T("control")))
    {
        INT ControlCode = 0;

        if (ArgCount > 1)
        {
            ServiceName = *ServiceArgs++;
            ArgCount--;

            if (!lstrcmpi(ServiceArgs[0], _T("paramchange")))
                ControlCode = SERVICE_CONTROL_PARAMCHANGE;
            else if (!lstrcmpi(ServiceArgs[0], _T("netbindadd")))
                ControlCode = SERVICE_CONTROL_NETBINDADD;
            else if (!lstrcmpi(ServiceArgs[0], _T("netbindremove")))
                ControlCode = SERVICE_CONTROL_NETBINDREMOVE;
            else if (!lstrcmpi(ServiceArgs[0], _T("netbindenable")))
                ControlCode = SERVICE_CONTROL_NETBINDENABLE;
            else if (!lstrcmpi(ServiceArgs[0], _T("netbinddisable")))
                ControlCode = SERVICE_CONTROL_NETBINDDISABLE;
            else
            {
                ControlCode = _ttoi(ServiceArgs[0]);
                if ((ControlCode < 128) || (ControlCode > 255))
                    ControlCode = 0;
            }

            ServiceArgs++;
            ArgCount--;

            if (ControlCode != 0)
                Control(ControlCode,
                        ServiceName,
                        ServiceArgs,
                        ArgCount);
            else
                ControlUsage();
        }
        else
            ControlUsage();
    }
    else if (!lstrcmpi(Command, _T("sdshow")))
    {
        if (ArgCount > 0)
        {
            ServiceName = *ServiceArgs++;
            ArgCount--;

            SdShow(ServiceName);
        }
        else
            SdShowUsage();
    }
    else if (!lstrcmpi(Command, _T("sdset")))
    {
        LPCTSTR SecurityDescriptor;

        if (ArgCount > 1)
        {
            ServiceName = *ServiceArgs++;
            ArgCount--;

            SecurityDescriptor = *ServiceArgs++;
            ArgCount--;

            SdSet(ServiceName, SecurityDescriptor);
        }
        else
            SdSetUsage();
    }
    else if (!lstrcmpi(Command, _T("qc")))
    {
        if (ArgCount > 0)
        {
            ServiceName = *ServiceArgs++;
            ArgCount--;

            QueryConfig(ServiceName);
        }
        else
            QueryConfigUsage();
    }
    else if (!lstrcmpi(Command, _T("qdescription")))
    {
        if (ArgCount > 0)
        {
            ServiceName = *ServiceArgs++;
            ArgCount--;

            QueryDescription(ServiceName);
        }
        else
            QueryDescriptionUsage();
    }
    else if (!lstrcmpi(Command, _T("qfailure")))
    {
        if (ArgCount > 0)
        {
            ServiceName = *ServiceArgs++;
            ArgCount--;

            QueryFailure(ServiceName);
        }
        else
            QueryFailureUsage();
    }
    else if (!lstrcmpi(Command, _T("description")))
    {
        LPCTSTR Description = NULL;

        if (ArgCount > 0)
        {
            ServiceName = *ServiceArgs++;
            ArgCount--;

            if (ArgCount > 0)
            {
                Description = *ServiceArgs++;
                ArgCount--;
            }

            SetDescription(ServiceName, Description);
        }
        else
            SetDescriptionUsage();
    }
    else if (!lstrcmpi(Command, _T("config")))
    {
        SetConfig(ServiceArgs, ArgCount);
    }
    else if (!lstrcmpi(Command, _T("failure")))
    {
        SetFailure(ServiceArgs, ArgCount);
    }
    else if (!lstrcmpi(Command, _T("GetDisplayName")))
    {
        if (ArgCount > 0)
        {
            ServiceName = *ServiceArgs++;
            ArgCount--;

            GetDisplayName(ServiceName);
        }
        else
            GetDisplayNameUsage();
    }
    else if (!lstrcmpi(Command, _T("GetKeyName")))
    {
        if (ArgCount > 0)
        {
            ServiceName = *ServiceArgs++;
            ArgCount--;

            GetKeyName(ServiceName);
        }
        else
            GetKeyNameUsage();
    }
    else if (!lstrcmpi(Command, _T("EnumDepend")))
    {
        if (ArgCount > 0)
        {
            ServiceName = *ServiceArgs++;
            ArgCount--;

            EnumDepend(ServiceName);
        }
        else
            EnumDependUsage();
    }
    else
    {
        MainUsage();
    }

    return 0;
}

int _tmain(int argc, LPCTSTR argv[])
{
    LPCTSTR Server = NULL;   // remote machine
    LPCTSTR Command = NULL;  // sc command
    LPCTSTR *Args = NULL;    // Any remaining args

    if (argc < 2)
    {
        MainUsage();
        return -1;
    }

    /* get server name */
    if ((argv[1][0] == '\\') && (argv[1][1] == '\\'))
    {
        if (argc < 3)
        {
            MainUsage();
            return -1;
        }

        Server = argv[1];
        Command = argv[2];
        if (argc > 3)
            Args = &argv[3];

        return ScControl(Server,
                         Command,
                         Args,
                         argc-3);
    }
    else
    {
        Command = argv[1];
        if (argc > 2)
            Args = &argv[2];

        return ScControl(Server,
                         Command,
                         Args,
                         argc-2);
    }
}
