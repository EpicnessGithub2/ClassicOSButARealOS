/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         classicOS Base API Server DLL
 * FILE:            subsystems/win/basesrv/init.c
 * PURPOSE:         Initialization
 * PROGRAMMERS:     Alex Ionescu (alex.ionescu@reactos.org)
 *                  Hermes Belusca-Maito (hermes.belusca@sfr.fr)
 *                  Pierre Schweitzer (pierre@reactos.org)
 */

/* INCLUDES *******************************************************************/

#include "basesrv.h"
#include "vdm.h"

#include <winreg.h>

#define NDEBUG
#include <debug.h>

#include "api.h"

/* GLOBALS ********************************************************************/

HANDLE BaseSrvDllInstance = NULL;
extern UNICODE_STRING BaseSrvKernel32DllPath;

/* Memory */
HANDLE BaseSrvHeap = NULL;          // Our own heap.
HANDLE BaseSrvSharedHeap = NULL;    // Shared heap with CSR. (CsrSrvSharedSectionHeap)
PBASE_STATIC_SERVER_DATA BaseStaticServerData = NULL;   // Data that we can share amongst processes. Initialized inside BaseSrvSharedHeap.

ULONG SessionId = 0;
ULONG ProtectionMode = 0;

PINIFILE_MAPPING BaseSrvIniFileMapping;

// Windows Server 2003 table from http://j00ru.vexillium.org/csrss_list/api_list.html#Windows_2k3
PCSR_API_ROUTINE BaseServerApiDispatchTable[BasepMaxApiNumber - BASESRV_FIRST_API_NUMBER] =
{
    BaseSrvCreateProcess,
    BaseSrvCreateThread,
    BaseSrvGetTempFile,
    BaseSrvExitProcess,
    BaseSrvDebugProcess,
    BaseSrvCheckVDM,
    BaseSrvUpdateVDMEntry,
    BaseSrvGetNextVDMCommand,
    BaseSrvExitVDM,
    BaseSrvIsFirstVDM,
    BaseSrvGetVDMExitCode,
    BaseSrvSetReenterCount,
    BaseSrvSetProcessShutdownParam,
    BaseSrvGetProcessShutdownParam,
    BaseSrvNlsSetUserInfo,
    BaseSrvNlsSetMultipleUserInfo,
    BaseSrvNlsCreateSection,
    BaseSrvSetVDMCurDirs,
    BaseSrvGetVDMCurDirs,
    BaseSrvBatNotification,
    BaseSrvRegisterWowExec,
    BaseSrvSoundSentryNotification,
    BaseSrvRefreshIniFileMapping,
    BaseSrvDefineDosDevice,
    BaseSrvSetTermsrvAppInstallMode,
    BaseSrvNlsUpdateCacheCount,
    BaseSrvSetTermsrvClientTimeZone,
    BaseSrvSxsCreateActivationContext,
    BaseSrvDebugProcess,
    BaseSrvRegisterThread,
    BaseSrvNlsGetUserInfo,
};

BOOLEAN BaseServerApiServerValidTable[BasepMaxApiNumber - BASESRV_FIRST_API_NUMBER] =
{
    TRUE,   // BaseSrvCreateProcess
    TRUE,   // BaseSrvCreateThread
    TRUE,   // BaseSrvGetTempFile
    FALSE,  // BaseSrvExitProcess
    FALSE,  // BaseSrvDebugProcess
    TRUE,   // BaseSrvCheckVDM
    TRUE,   // BaseSrvUpdateVDMEntry
    TRUE,   // BaseSrvGetNextVDMCommand
    TRUE,   // BaseSrvExitVDM
    TRUE,   // BaseSrvIsFirstVDM
    TRUE,   // BaseSrvGetVDMExitCode
    TRUE,   // BaseSrvSetReenterCount
    TRUE,   // BaseSrvSetProcessShutdownParam
    TRUE,   // BaseSrvGetProcessShutdownParam
    TRUE,   // BaseSrvNlsSetUserInfo
    TRUE,   // BaseSrvNlsSetMultipleUserInfo
    TRUE,   // BaseSrvNlsCreateSection
    TRUE,   // BaseSrvSetVDMCurDirs
    TRUE,   // BaseSrvGetVDMCurDirs
    TRUE,   // BaseSrvBatNotification
    TRUE,   // BaseSrvRegisterWowExec
    TRUE,   // BaseSrvSoundSentryNotification
    TRUE,   // BaseSrvRefreshIniFileMapping
    TRUE,   // BaseSrvDefineDosDevice
    TRUE,   // BaseSrvSetTermsrvAppInstallMode
    TRUE,   // BaseSrvNlsUpdateCacheCount
    TRUE,   // BaseSrvSetTermsrvClientTimeZone
    TRUE,   // BaseSrvSxsCreateActivationContext
    FALSE,  // BaseSrvDebugProcess
    TRUE,   // BaseSrvRegisterThread
    TRUE,   // BaseSrvNlsGetUserInfo
};

/*
 * On Windows Server 2003, CSR Servers contain
 * the API Names Table only in Debug Builds.
 */
#ifdef CSR_DBG
PCHAR BaseServerApiNameTable[BasepMaxApiNumber - BASESRV_FIRST_API_NUMBER] =
{
    "BaseCreateProcess",
    "BaseCreateThread",
    "BaseGetTempFile",
    "BaseExitProcess",
    "BaseDebugProcess",
    "BaseCheckVDM",
    "BaseUpdateVDMEntry",
    "BaseGetNextVDMCommand",
    "BaseExitVDM",
    "BaseIsFirstVDM",
    "BaseGetVDMExitCode",
    "BaseSetReenterCount",
    "BaseSetProcessShutdownParam",
    "BaseGetProcessShutdownParam",
    "BaseNlsSetUserInfo",
    "BaseNlsSetMultipleUserInfo",
    "BaseNlsCreateSection",
    "BaseSetVDMCurDirs",
    "BaseGetVDMCurDirs",
    "BaseBatNotification",
    "BaseRegisterWowExec",
    "BaseSoundSentryNotification",
    "BaseRefreshIniFileMapping",
    "BaseDefineDosDevice",
    "BaseSetTermsrvAppInstallMode",
    "BaseNlsUpdateCacheCount",
    "BaseSetTermsrvClientTimeZone",
    "BaseSxsCreateActivationContext",
    "BaseSrvDebugProcessStop",
    "BaseRegisterThread",
    "BaseNlsGetUserInfo",
};
#endif

/* FUNCTIONS ******************************************************************/

NTSTATUS
NTAPI
BaseSrvInitializeIniFileMappings(IN PBASE_STATIC_SERVER_DATA StaticServerData)
{
    /* Allocate the mapping blob */
    BaseSrvIniFileMapping = RtlAllocateHeap(BaseSrvSharedHeap,
                                            HEAP_ZERO_MEMORY,
                                            sizeof(*BaseSrvIniFileMapping));
    if (BaseSrvIniFileMapping == NULL)
    {
        DPRINT1("BASESRV: Unable to allocate memory in shared heap for IniFileMapping\n");
        return STATUS_NO_MEMORY;
    }

    /* Set it*/
    StaticServerData->IniFileMapping = BaseSrvIniFileMapping;

    /* FIXME: Do the work to initialize the mappings */
    return STATUS_SUCCESS;
}

NTSTATUS
NTAPI
CreateBaseAcls(OUT PACL* Dacl,
               OUT PACL* RestrictedDacl)
{
    PSID SystemSid, WorldSid, RestrictedSid;
    SID_IDENTIFIER_AUTHORITY NtAuthority = {SECURITY_NT_AUTHORITY};
    SID_IDENTIFIER_AUTHORITY WorldAuthority = {SECURITY_WORLD_SID_AUTHORITY};
    NTSTATUS Status;
    UCHAR KeyValueBuffer[0x40];
    PKEY_VALUE_PARTIAL_INFORMATION KeyValuePartialInfo;
    UNICODE_STRING KeyName;
    ULONG AclLength;
    ULONG ResultLength;
    HANDLE hKey;
    OBJECT_ATTRIBUTES ObjectAttributes;
    ULONG ObjectSecurityMode;
    ACCESS_MASK WorldAccess, RestrictedAccess;

    /* Open the Session Manager Key */
    RtlInitUnicodeString(&KeyName, SM_REG_KEY);
    InitializeObjectAttributes(&ObjectAttributes,
                               &KeyName,
                               OBJ_CASE_INSENSITIVE,
                               NULL,
                               NULL);
    Status = NtOpenKey(&hKey, KEY_READ, &ObjectAttributes);
    if (NT_SUCCESS(Status))
    {
        /* Read the key value */
        RtlInitUnicodeString(&KeyName, L"ProtectionMode");
        Status = NtQueryValueKey(hKey,
                                 &KeyName,
                                 KeyValuePartialInformation,
                                 KeyValueBuffer,
                                 sizeof(KeyValueBuffer),
                                 &ResultLength);

        /* Make sure it's what we expect it to be */
        KeyValuePartialInfo = (PKEY_VALUE_PARTIAL_INFORMATION)KeyValueBuffer;
        if ((NT_SUCCESS(Status)) && (KeyValuePartialInfo->Type == REG_DWORD) &&
            (*(PULONG)KeyValuePartialInfo->Data))
        {
            /* Save the Protection Mode */
            ProtectionMode = *(PULONG)KeyValuePartialInfo->Data;
        }

        /* Close the handle */
        NtClose(hKey);
    }

    /* Get object security mode */
    if (SessionId == 0 ||
        !NT_SUCCESS(NtQuerySystemInformation(SystemObjectSecurityMode, &ObjectSecurityMode, sizeof(ULONG), NULL)))
    {
        ObjectSecurityMode = 0;
    }

    /* Allocate the System SID */
    Status = RtlAllocateAndInitializeSid(&NtAuthority,
                                         1, SECURITY_LOCAL_SYSTEM_RID,
                                         0, 0, 0, 0, 0, 0, 0,
                                         &SystemSid);
    if (!NT_SUCCESS(Status))
    {
        return Status;
    }

    /* Allocate the World SID */
    Status = RtlAllocateAndInitializeSid(&WorldAuthority,
                                         1, SECURITY_WORLD_RID,
                                         0, 0, 0, 0, 0, 0, 0,
                                         &WorldSid);
    if (!NT_SUCCESS(Status))
    {
        RtlFreeSid(SystemSid);
        goto Return;
    }

    /* Allocate the restricted SID */
    Status = RtlAllocateAndInitializeSid(&NtAuthority,
                                         1, SECURITY_RESTRICTED_CODE_RID,
                                         0, 0, 0, 0, 0, 0, 0,
                                         &RestrictedSid);
    if (!NT_SUCCESS(Status))
    {
        RtlFreeSid(WorldSid);
        RtlFreeSid(SystemSid);
        goto Return;
    }

    /* Allocate one ACL with 3 ACEs each for one SID */
    AclLength = sizeof(ACL) + 3 * sizeof(ACCESS_ALLOWED_ACE) +
                    RtlLengthSid(SystemSid) +
                    RtlLengthSid(WorldSid)  +
                    RtlLengthSid(RestrictedSid);
    *Dacl = RtlAllocateHeap(BaseSrvHeap, 0, AclLength);
    if (*Dacl == NULL)
    {
        Status = STATUS_NO_MEMORY;
        goto FreeAndReturn;
    }

    /* Set the correct header fields */
    Status = RtlCreateAcl(*Dacl, AclLength, ACL_REVISION2);
    if (!NT_SUCCESS(Status))
    {
        RtlFreeHeap(BaseSrvHeap, 0, *Dacl);
        goto FreeAndReturn;
    }

    /* Setup access for anyone depending on object security mode */
    if (ObjectSecurityMode != 0)
    {
        /*
         * If we have restrictions on security mode, make it read only
         * it also means session ID is not 0
         */
        WorldAccess = DIRECTORY_QUERY | DIRECTORY_TRAVERSE;
    }
    else
    {
        /* Otherwise, open wide */
        WorldAccess = READ_CONTROL | DIRECTORY_QUERY | DIRECTORY_TRAVERSE | DIRECTORY_CREATE_OBJECT | DIRECTORY_CREATE_SUBDIRECTORY;
    }

    /* Give the appropriate rights to each SID */
    if (NT_SUCCESS(RtlAddAccessAllowedAce(*Dacl, ACL_REVISION2, WorldAccess, WorldSid)) &&
        NT_SUCCESS(RtlAddAccessAllowedAce(*Dacl, ACL_REVISION2, DIRECTORY_ALL_ACCESS, SystemSid)))
    {
        RtlAddAccessAllowedAce(*Dacl, ACL_REVISION2, DIRECTORY_TRAVERSE, RestrictedSid);
    }

    /* Now allocate the restricted DACL */
    *RestrictedDacl = RtlAllocateHeap(BaseSrvHeap, 0, AclLength);
    if (*RestrictedDacl == NULL)
    {
        Status = STATUS_NO_MEMORY;
        RtlFreeHeap(BaseSrvHeap, 0, *Dacl);
        goto FreeAndReturn;
    }

    /* Initialize it */
    Status = RtlCreateAcl(*RestrictedDacl, AclLength, ACL_REVISION2);
    if (!NT_SUCCESS(Status))
    {
        RtlFreeHeap(BaseSrvHeap, 0, *RestrictedDacl);
        RtlFreeHeap(BaseSrvHeap, 0, *Dacl);
        goto FreeAndReturn;
    }

    /* Setup access for restricted sid depending on session id and protection mode */
    if (SessionId == 0 || (ProtectionMode & 3) == 0)
    {
        /* If we have no session ID or if protection mode is not set, then open wide */
        RestrictedAccess = READ_CONTROL | DIRECTORY_QUERY | DIRECTORY_TRAVERSE | DIRECTORY_CREATE_OBJECT | DIRECTORY_CREATE_SUBDIRECTORY;
    }
    else
    {
        /* Otherwise, make read only */
        RestrictedAccess = READ_CONTROL | DIRECTORY_QUERY | DIRECTORY_TRAVERSE;
    }

    /* And add the same ACEs as before */
    Status = RtlAddAccessAllowedAce(*RestrictedDacl, ACL_REVISION2, WorldAccess, WorldSid);
    if (NT_SUCCESS(Status))
    {
        Status = RtlAddAccessAllowedAce(*RestrictedDacl, ACL_REVISION2, DIRECTORY_ALL_ACCESS, SystemSid);
        if (NT_SUCCESS(Status))
        {
            Status = RtlAddAccessAllowedAce(*RestrictedDacl, ACL_REVISION2, RestrictedAccess, RestrictedSid);
        }
    }

    /* The SIDs are captured, can free them now */
FreeAndReturn:
    RtlFreeSid(RestrictedSid);
    RtlFreeSid(WorldSid);
    RtlFreeSid(SystemSid);

Return:
    return Status;
}

VOID
NTAPI
BaseInitializeStaticServerData(IN PCSR_SERVER_DLL LoadedServerDll)
{
    NTSTATUS Status;
    BOOLEAN Success;
    WCHAR BnoBuffer[100];
    WCHAR Buffer[MAX_PATH];
    PWCHAR HeapBuffer;
    UNICODE_STRING SystemRootString;
    UNICODE_STRING UnexpandedSystemRootString = RTL_CONSTANT_STRING(L"%SystemRoot%");
    UNICODE_STRING BaseSrvCSDString;
    UNICODE_STRING BaseSrvWindowsDirectory;
    UNICODE_STRING BaseSrvWindowsSystemDirectory;
    UNICODE_STRING BnoString;
    OBJECT_ATTRIBUTES ObjectAttributes;
    HANDLE BaseSrvNamedObjectDirectory;
    HANDLE BaseSrvRestrictedObjectDirectory;
    PACL BnoDacl, BnoRestrictedDacl;
    PSECURITY_DESCRIPTOR BnoSd;
    HANDLE SymHandle;
    UNICODE_STRING DirectoryName, SymlinkName;
    ULONG LuidEnabled;
    RTL_QUERY_REGISTRY_TABLE BaseServerRegistryConfigurationTable[2] =
    {
        {
            NULL,
            RTL_QUERY_REGISTRY_DIRECT,
            L"CSDVersion",
            &BaseSrvCSDString,
            REG_NONE, NULL, 0
        },

        {0}
    };

    /* Initialize the memory */
    BaseSrvHeap = RtlGetProcessHeap();                  // Initialize our own heap.
    BaseSrvSharedHeap = LoadedServerDll->SharedSection; // Get the CSR shared heap.

    /* Get the session ID */
    SessionId = NtCurrentPeb()->SessionId;

    /* Get the Windows directory */
    RtlInitEmptyUnicodeString(&SystemRootString, Buffer, sizeof(Buffer));
    Status = RtlExpandEnvironmentStrings_U(NULL,
                                           &UnexpandedSystemRootString,
                                           &SystemRootString,
                                           NULL);
    ASSERT(NT_SUCCESS(Status));

    /* Create the base directory */
    Buffer[SystemRootString.Length / sizeof(WCHAR)] = UNICODE_NULL;
    Success = RtlCreateUnicodeString(&BaseSrvWindowsDirectory,
                                     SystemRootString.Buffer);
    ASSERT(Success);

    /* Create the system directory */
    wcscat(SystemRootString.Buffer, L"\\System32");
    Success = RtlCreateUnicodeString(&BaseSrvWindowsSystemDirectory,
                                     SystemRootString.Buffer);
    ASSERT(Success);

    /* Create the kernel32 path */
    wcscat(SystemRootString.Buffer, L"\\kernel32.dll");
    Success = RtlCreateUnicodeString(&BaseSrvKernel32DllPath,
                                     SystemRootString.Buffer);
    ASSERT(Success);

    if (SessionId != 0)
    {
        swprintf(BnoBuffer, L"\\Sessions\\%ld\\BaseNamedObjects", SessionId);
    }
    else
    {
        wcscpy(BnoBuffer, L"\\BaseNamedObjects");
    }
    RtlInitUnicodeString(&BnoString, BnoBuffer);

    /* Allocate the server data */
    BaseStaticServerData = RtlAllocateHeap(BaseSrvSharedHeap,
                                           HEAP_ZERO_MEMORY,
                                           sizeof(BASE_STATIC_SERVER_DATA));
    ASSERT(BaseStaticServerData != NULL);

    /* Process timezone information */
    BaseStaticServerData->TermsrvClientTimeZoneId = TIME_ZONE_ID_INVALID;
    BaseStaticServerData->TermsrvClientTimeZoneChangeNum = 0;
    Status = NtQuerySystemInformation(SystemTimeOfDayInformation,
                                      &BaseStaticServerData->TimeOfDay,
                                      sizeof(BaseStaticServerData->TimeOfDay),
                                      NULL);
    ASSERT(NT_SUCCESS(Status));

    /* Make a shared heap copy of the Windows directory */
    BaseStaticServerData->WindowsDirectory = BaseSrvWindowsDirectory;
    HeapBuffer = RtlAllocateHeap(BaseSrvSharedHeap,
                                 0,
                                 BaseSrvWindowsDirectory.MaximumLength);
    ASSERT(HeapBuffer);
    RtlCopyMemory(HeapBuffer,
                  BaseStaticServerData->WindowsDirectory.Buffer,
                  BaseSrvWindowsDirectory.MaximumLength);
    BaseStaticServerData->WindowsDirectory.Buffer = HeapBuffer;

    /* Make a shared heap copy of the System directory */
    BaseStaticServerData->WindowsSystemDirectory = BaseSrvWindowsSystemDirectory;
    HeapBuffer = RtlAllocateHeap(BaseSrvSharedHeap,
                                 0,
                                 BaseSrvWindowsSystemDirectory.MaximumLength);
    ASSERT(HeapBuffer);
    RtlCopyMemory(HeapBuffer,
                  BaseStaticServerData->WindowsSystemDirectory.Buffer,
                  BaseSrvWindowsSystemDirectory.MaximumLength);
    BaseStaticServerData->WindowsSystemDirectory.Buffer = HeapBuffer;

    /* This string is not used */
    RtlInitEmptyUnicodeString(&BaseStaticServerData->WindowsSys32x86Directory,
                              NULL,
                              0);

    /* Make a shared heap copy of the BNO directory */
    BaseStaticServerData->NamedObjectDirectory = BnoString;
    BaseStaticServerData->NamedObjectDirectory.MaximumLength = BnoString.Length +
                                                               sizeof(UNICODE_NULL);
    HeapBuffer = RtlAllocateHeap(BaseSrvSharedHeap,
                                 0,
                                 BaseStaticServerData->NamedObjectDirectory.MaximumLength);
    ASSERT(HeapBuffer);
    RtlCopyMemory(HeapBuffer,
                  BaseStaticServerData->NamedObjectDirectory.Buffer,
                  BaseStaticServerData->NamedObjectDirectory.MaximumLength);
    BaseStaticServerData->NamedObjectDirectory.Buffer = HeapBuffer;

    /*
     * Confirmed that in Windows, CSDNumber and RCNumber are actually Length
     * and MaximumLength of the CSD String, since the same UNICODE_STRING is
     * being queried twice, the first time as a ULONG!
     *
     * Somehow, in Windows this doesn't cause a buffer overflow, but it might
     * in classicOS, so this code is disabled until someone figures out WTF.
     */
    BaseStaticServerData->CSDNumber = 0;
    BaseStaticServerData->RCNumber = 0;

    /* Initialize the CSD string and query its value from the registry */
    RtlInitEmptyUnicodeString(&BaseSrvCSDString, Buffer, sizeof(Buffer));
    Status = RtlQueryRegistryValues(RTL_REGISTRY_WINDOWS_NT,
                                    L"",
                                    BaseServerRegistryConfigurationTable,
                                    NULL,
                                    NULL);
    if (NT_SUCCESS(Status))
    {
        /* Copy into the shared buffer */
        wcsncpy(BaseStaticServerData->CSDVersion,
                BaseSrvCSDString.Buffer,
                BaseSrvCSDString.Length / sizeof(WCHAR));
    }
    else
    {
        /* Indicate nothing is there */
        BaseSrvCSDString.Length = 0;
    }
    /* NULL-terminate */
    BaseStaticServerData->CSDVersion[BaseSrvCSDString.Length / sizeof(WCHAR)] = UNICODE_NULL;

    /* Cache the system information */
    Status = NtQuerySystemInformation(SystemBasicInformation,
                                      &BaseStaticServerData->SysInfo,
                                      sizeof(BaseStaticServerData->SysInfo),
                                      NULL);
    ASSERT(NT_SUCCESS(Status));

    /* Setup the ini file mappings */
    Status = BaseSrvInitializeIniFileMappings(BaseStaticServerData);
    ASSERT(NT_SUCCESS(Status));

    /* FIXME: Should query the registry for these */
    BaseStaticServerData->DefaultSeparateVDM = FALSE;
    BaseStaticServerData->IsWowTaskReady = FALSE;

    /* Allocate a security descriptor and create it */
    BnoSd = RtlAllocateHeap(BaseSrvHeap, 0, 1024);
    ASSERT(BnoSd);
    Status = RtlCreateSecurityDescriptor(BnoSd, SECURITY_DESCRIPTOR_REVISION);
    ASSERT(NT_SUCCESS(Status));

    /* Create the BNO and \Restricted DACLs */
    Status = CreateBaseAcls(&BnoDacl, &BnoRestrictedDacl);
    ASSERT(NT_SUCCESS(Status));

    /* Set the BNO DACL as active for now */
    Status = RtlSetDaclSecurityDescriptor(BnoSd, TRUE, BnoDacl, FALSE);
    ASSERT(NT_SUCCESS(Status));

    /* Create the BNO directory */
    InitializeObjectAttributes(&ObjectAttributes,
                               &BnoString,
                               OBJ_OPENIF | OBJ_PERMANENT | OBJ_CASE_INSENSITIVE,
                               NULL,
                               BnoSd);
    Status = NtCreateDirectoryObject(&BaseSrvNamedObjectDirectory,
                                     DIRECTORY_ALL_ACCESS,
                                     &ObjectAttributes);
    ASSERT(NT_SUCCESS(Status));

    /* Check if we are session 0 */
    if (SessionId == 0)
    {
        /* Mark this as a session 0 directory */
        Status = NtSetInformationObject(BaseSrvNamedObjectDirectory,
                                        ObjectSessionInformation,
                                        NULL,
                                        0);
        ASSERT(NT_SUCCESS(Status));
    }

    /* Check if LUID device maps are enabled */
    Status = NtQueryInformationProcess(NtCurrentProcess(),
                                       ProcessLUIDDeviceMapsEnabled,
                                       &LuidEnabled,
                                       sizeof(LuidEnabled),
                                       NULL);
    ASSERT(NT_SUCCESS(Status));
    BaseStaticServerData->LUIDDeviceMapsEnabled = (BOOLEAN)LuidEnabled;

    /* Initialize Global */
    if (!BaseStaticServerData->LUIDDeviceMapsEnabled ||
        NT_SUCCESS(RtlInitializeCriticalSectionAndSpinCount(&BaseSrvDDDBSMCritSec, 0x80000000)))
    {
        /* Make Global point back to BNO */
        RtlInitUnicodeString(&DirectoryName, L"Global");
        RtlInitUnicodeString(&SymlinkName, L"\\BaseNamedObjects");
        InitializeObjectAttributes(&ObjectAttributes,
                                   &DirectoryName,
                                   OBJ_OPENIF | OBJ_PERMANENT | OBJ_CASE_INSENSITIVE,
                                   BaseSrvNamedObjectDirectory,
                                   BnoSd);
        Status = NtCreateSymbolicLinkObject(&SymHandle,
                                            SYMBOLIC_LINK_ALL_ACCESS,
                                            &ObjectAttributes,
                                            &SymlinkName);
        if ((NT_SUCCESS(Status)) && SessionId == 0) NtClose(SymHandle);

        /* Make local point back to \Sessions\x\BNO */
        RtlInitUnicodeString(&DirectoryName, L"Local");
        ASSERT(SessionId == 0);
        InitializeObjectAttributes(&ObjectAttributes,
                                   &DirectoryName,
                                   OBJ_OPENIF | OBJ_PERMANENT | OBJ_CASE_INSENSITIVE,
                                   BaseSrvNamedObjectDirectory,
                                   BnoSd);
        Status = NtCreateSymbolicLinkObject(&SymHandle,
                                            SYMBOLIC_LINK_ALL_ACCESS,
                                            &ObjectAttributes,
                                            &BnoString);
        if ((NT_SUCCESS(Status)) && SessionId == 0) NtClose(SymHandle);

        /* Make Session point back to BNOLINKS */
        RtlInitUnicodeString(&DirectoryName, L"Session");
        RtlInitUnicodeString(&SymlinkName, L"\\Sessions\\BNOLINKS");
        InitializeObjectAttributes(&ObjectAttributes,
                                   &DirectoryName,
                                   OBJ_OPENIF | OBJ_PERMANENT | OBJ_CASE_INSENSITIVE,
                                   BaseSrvNamedObjectDirectory,
                                   BnoSd);
        Status = NtCreateSymbolicLinkObject(&SymHandle,
                                            SYMBOLIC_LINK_ALL_ACCESS,
                                            &ObjectAttributes,
                                            &SymlinkName);
        if ((NT_SUCCESS(Status)) && SessionId == 0) NtClose(SymHandle);

        /* Create the BNO\Restricted directory and set the restricted DACL */
        RtlInitUnicodeString(&DirectoryName, L"Restricted");
        Status = RtlSetDaclSecurityDescriptor(BnoSd, TRUE, BnoRestrictedDacl, FALSE);
        ASSERT(NT_SUCCESS(Status));
        InitializeObjectAttributes(&ObjectAttributes,
                                   &DirectoryName,
                                   OBJ_OPENIF | OBJ_PERMANENT | OBJ_CASE_INSENSITIVE,
                                   BaseSrvNamedObjectDirectory,
                                   BnoSd);
        Status = NtCreateDirectoryObject(&BaseSrvRestrictedObjectDirectory,
                                         DIRECTORY_ALL_ACCESS,
                                         &ObjectAttributes);
        ASSERT(NT_SUCCESS(Status));
    }
    else
    {
        /* That should never happen */
        ASSERT(FALSE);
    }

    /* Initialize NLS */
    BaseSrvNLSInit(BaseStaticServerData);

    /* Finally, set the pointer */
    LoadedServerDll->SharedSection = BaseStaticServerData;
}

NTSTATUS
NTAPI
BaseClientConnectRoutine(IN PCSR_PROCESS CsrProcess,
                         IN OUT PVOID  ConnectionInfo,
                         IN OUT PULONG ConnectionInfoLength)
{
    PBASESRV_API_CONNECTINFO ConnectInfo = (PBASESRV_API_CONNECTINFO)ConnectionInfo;

    if ( ConnectionInfo       == NULL ||
         ConnectionInfoLength == NULL ||
        *ConnectionInfoLength != sizeof(*ConnectInfo) )
    {
        DPRINT1("BASESRV: Connection failed - ConnectionInfo = 0x%p ; ConnectionInfoLength = 0x%p (%lu), expected %lu\n",
                ConnectionInfo,
                ConnectionInfoLength,
                ConnectionInfoLength ? *ConnectionInfoLength : (ULONG)-1,
                sizeof(*ConnectInfo));

        return STATUS_INVALID_PARAMETER;
    }

    /* Do the NLS connection */
    return BaseSrvNlsConnect(CsrProcess, ConnectionInfo, ConnectionInfoLength);
}

VOID
NTAPI
BaseClientDisconnectRoutine(IN PCSR_PROCESS CsrProcess)
{
    /* Cleanup VDM resources */
    BaseSrvCleanupVDMResources(CsrProcess);
}

CSR_SERVER_DLL_INIT(ServerDllInitialization)
{
    /* Setup the DLL Object */
    LoadedServerDll->ApiBase = BASESRV_FIRST_API_NUMBER;
    LoadedServerDll->HighestApiSupported = BasepMaxApiNumber;
    LoadedServerDll->DispatchTable = BaseServerApiDispatchTable;
    LoadedServerDll->ValidTable = BaseServerApiServerValidTable;
#ifdef CSR_DBG
    LoadedServerDll->NameTable = BaseServerApiNameTable;
#endif
    LoadedServerDll->SizeOfProcessData = 0;
    LoadedServerDll->ConnectCallback = BaseClientConnectRoutine;
    LoadedServerDll->DisconnectCallback = BaseClientDisconnectRoutine;
    LoadedServerDll->ShutdownProcessCallback = NULL;

    BaseSrvDllInstance = LoadedServerDll->ServerHandle;

    BaseInitializeStaticServerData(LoadedServerDll);

    /* Initialize DOS devices management */
    BaseInitDefineDosDevice();

    /* Initialize VDM support */
    BaseInitializeVDM();

    /* All done */
    return STATUS_SUCCESS;
}

BOOL
NTAPI
DllMain(IN HINSTANCE hInstanceDll,
        IN DWORD dwReason,
        IN LPVOID lpReserved)
{
    UNREFERENCED_PARAMETER(hInstanceDll);
    UNREFERENCED_PARAMETER(dwReason);
    UNREFERENCED_PARAMETER(lpReserved);

    if (DLL_PROCESS_DETACH == dwReason)
    {
        BaseCleanupDefineDosDevice();
    }

    return TRUE;
}

/* EOF */
