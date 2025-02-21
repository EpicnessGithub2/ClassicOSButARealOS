/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         classicOS hive maker
 * FILE:            tools/mkhive/rtl.c
 * PURPOSE:         Runtime Library
 */

#include <stdlib.h>
#include <stdarg.h>

/* gcc defaults to cdecl */
#if defined(__GNUC__)
#undef __cdecl
#define __cdecl
#endif

#include "mkhive.h"
#include <bitmap.c>

/*
 * @implemented
 *
 * NOTES
 *  If source is NULL the length of source is assumed to be 0.
 */
VOID NTAPI
RtlInitUnicodeString(
    IN OUT PUNICODE_STRING DestinationString,
    IN PCWSTR SourceString)
{
    SIZE_T DestSize;

    if(SourceString)
    {
        DestSize = strlenW(SourceString) * sizeof(WCHAR);
        DestinationString->Length = (USHORT)DestSize;
        DestinationString->MaximumLength = (USHORT)DestSize + sizeof(WCHAR);
    }
    else
    {
        DestinationString->Length = 0;
        DestinationString->MaximumLength = 0;
    }

    DestinationString->Buffer = (PWCHAR)SourceString;
}

LONG NTAPI
RtlCompareUnicodeString(
    IN PCUNICODE_STRING String1,
    IN PCUNICODE_STRING String2,
    IN BOOLEAN CaseInSensitive)
{
    USHORT i;
    WCHAR c1, c2;

    for (i = 0; i <= String1->Length / sizeof(WCHAR) && i <= String2->Length / sizeof(WCHAR); i++)
    {
        if (CaseInSensitive)
        {
            c1 = RtlUpcaseUnicodeChar(String1->Buffer[i]);
            c2 = RtlUpcaseUnicodeChar(String2->Buffer[i]);
        }
        else
        {
            c1 = String1->Buffer[i];
            c2 = String2->Buffer[i];
        }

        if (c1 < c2)
            return -1;
        else if (c1 > c2)
            return 1;
    }

    return 0;
}

WCHAR NTAPI
RtlUpcaseUnicodeChar(
    IN WCHAR Source)
{
    USHORT Offset;

    if (Source < 'a')
        return Source;

    if (Source <= 'z')
        return (Source - ('a' - 'A'));

    Offset = 0;

    return Source + (SHORT)Offset;
}

VOID NTAPI
KeQuerySystemTime(
    OUT PLARGE_INTEGER CurrentTime)
{
    CurrentTime->QuadPart = 0;
}

PVOID NTAPI
ExAllocatePool(
    IN POOL_TYPE PoolType,
    IN SIZE_T NumberOfBytes)
{
    return (PVOID) malloc(NumberOfBytes);
}

VOID NTAPI
ExFreePool(
    IN PVOID p)
{
    free(p);
}

ULONG
__cdecl
DbgPrint(
  IN CHAR *Format,
  IN ...)
{
    va_list ap;
    va_start(ap, Format);
    vprintf(Format, ap);
    va_end(ap);

    return 0;
}

VOID
NTAPI
RtlAssert(IN PVOID FailedAssertion,
          IN PVOID FileName,
          IN ULONG LineNumber,
          IN PCHAR Message OPTIONAL)
{
    if (Message != NULL)
    {
        DbgPrint("Assertion \'%s\' failed at %s line %u: %s\n",
                 (PCHAR)FailedAssertion,
                 (PCHAR)FileName,
                 LineNumber,
                 Message);
    }
    else
    {
        DbgPrint("Assertion \'%s\' failed at %s line %u\n",
                 (PCHAR)FailedAssertion,
                 (PCHAR)FileName,
                 LineNumber);
    }

    //DbgBreakPoint();
}

// FIXME: DECLSPEC_NORETURN
VOID
NTAPI
KeBugCheckEx(
    IN ULONG BugCheckCode,
    IN ULONG_PTR BugCheckParameter1,
    IN ULONG_PTR BugCheckParameter2,
    IN ULONG_PTR BugCheckParameter3,
    IN ULONG_PTR BugCheckParameter4)
{
    printf("*** STOP: 0x%08X (0x%p,0x%p,0x%p,0x%p)",
           BugCheckCode,
           (PVOID)BugCheckParameter1,
           (PVOID)BugCheckParameter2,
           (PVOID)BugCheckParameter3,
           (PVOID)BugCheckParameter4);
    ASSERT(FALSE);
}

unsigned char BitScanForward(ULONG * Index, unsigned long Mask)
{
    *Index = 0;
    while (Mask && ((Mask & 1) == 0))
    {
        Mask >>= 1;
        ++(*Index);
    }
    return Mask ? 1 : 0;
}

unsigned char BitScanReverse(ULONG * const Index, unsigned long Mask)
{
    *Index = 0;
    while (Mask && ((Mask & (1 << 31)) == 0))
    {
        Mask <<= 1;
        ++(*Index);
    }
    return Mask ? 1 : 0;
}
