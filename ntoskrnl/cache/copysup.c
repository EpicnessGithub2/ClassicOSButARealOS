/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         classicOS Kernel
 * FILE:            ntoskrnl/cache/copysup.c
 * PURPOSE:         Logging and configuration routines
 * PROGRAMMERS:     Alex Ionescu (alex.ionescu@reactos.org)
 */

/* INCLUDES *******************************************************************/

#include <ntoskrnl.h>
#include "newcc.h"
#include "section/newmm.h"
#define NDEBUG
#include <debug.h>

/* GLOBALS ********************************************************************/

ULONG CcFastMdlReadWait;
ULONG CcFastMdlReadNotPossible;
ULONG CcFastReadNotPossible;
ULONG CcFastReadWait;
ULONG CcFastReadNoWait;
ULONG CcFastReadResourceMiss;

#define TAG_COPY_READ  TAG('C', 'o', 'p', 'y')
#define TAG_COPY_WRITE TAG('R', 'i', 't', 'e')

/* FUNCTIONS ******************************************************************/

/*

CcCopyRead can be called for a region of any size and alignment, so we must
crawl the cache space, focusing one cache stripe after another and using
RtlCopyMemory to copy the input data into the cache.  In constrained memory,
pages faulted into new stripes are often taken from old stripes, causing the
old stripes to be flushed right away.  In the case of many short buffered in
order writes, like the ones generated by stdio, this can be really efficient.

*/
BOOLEAN
NTAPI
CcCopyRead(IN PFILE_OBJECT FileObject,
           IN PLARGE_INTEGER FileOffset,
           IN ULONG Length,
           IN BOOLEAN Wait,
           OUT PVOID Buffer,
           OUT PIO_STATUS_BLOCK IoStatus)
{
    PCHAR ReadBuffer;
    ULONG ReadLen;
    PVOID Bcb;
    PCHAR BufferTarget = (PCHAR)Buffer;
    LARGE_INTEGER CacheOffset, EndOfExtent, NextOffset;

    DPRINT("CcCopyRead(%x,%x,%d,%d,%x)\n",
           FileObject,
           FileOffset->LowPart,
           Length,
           Wait,
           Buffer);

    CacheOffset.QuadPart = FileOffset->QuadPart;
    EndOfExtent.QuadPart = FileOffset->QuadPart + Length;

    while (CacheOffset.QuadPart < EndOfExtent.QuadPart)
    {
        NextOffset.QuadPart = CacheOffset.QuadPart;
        NextOffset.LowPart = (NextOffset.LowPart + CACHE_STRIPE) & ~(CACHE_STRIPE-1);
        ReadLen = EndOfExtent.QuadPart - CacheOffset.QuadPart;
        if (CacheOffset.QuadPart + ReadLen > NextOffset.QuadPart)
        {
            ReadLen = NextOffset.QuadPart - CacheOffset.QuadPart;
        }

        DPRINT("Reading %d bytes in this go (at %08x%08x)\n",
               ReadLen,
               CacheOffset.HighPart,
               CacheOffset.LowPart);

        if (!CcPinRead(FileObject,
                       &CacheOffset,
                       ReadLen,
                       Wait ? PIN_WAIT : PIN_IF_BCB,
                       &Bcb,
                       (PVOID*)&ReadBuffer))
        {
            IoStatus->Status = STATUS_UNSUCCESSFUL;
            IoStatus->Information = 0;
            DPRINT("Failed CcCopyRead\n");
            return FALSE;
        }

        DPRINT("Copying %d bytes at %08x%08x\n",
               ReadLen,
               CacheOffset.HighPart,
               CacheOffset.LowPart);

        RtlCopyMemory(BufferTarget, ReadBuffer, ReadLen);

        BufferTarget += ReadLen;

        CacheOffset = NextOffset;
        CcUnpinData(Bcb);
    }

    IoStatus->Status = STATUS_SUCCESS;
    IoStatus->Information = Length;

    DPRINT("Done with CcCopyRead\n");

    return TRUE;
}

VOID
NTAPI
CcFastCopyRead(IN PFILE_OBJECT FileObject,
               IN ULONG FileOffset,
               IN ULONG Length,
               IN ULONG PageCount,
               OUT PVOID Buffer,
               OUT PIO_STATUS_BLOCK IoStatus)
{
    UNIMPLEMENTED_DBGBREAK();
}

BOOLEAN
NTAPI
CcCopyWrite(IN PFILE_OBJECT FileObject,
            IN PLARGE_INTEGER FileOffset,
            IN ULONG Length,
            IN BOOLEAN Wait,
            IN PVOID Buffer)
{
    INT Count = 0;
    BOOLEAN Result;
    PNOCC_BCB Bcb;
    PVOID WriteBuf;
    ULONG WriteLen;
    LARGE_INTEGER CurrentOffset = *FileOffset;
    LARGE_INTEGER EndOffset;
    LARGE_INTEGER NextOffset;

    EndOffset.QuadPart = CurrentOffset.QuadPart + Length;

    DPRINT("CcCopyWrite(%x,%x,%d,%d,%x)\n",
           FileObject,
           FileOffset->LowPart,
           Length,
           Wait,
           Buffer);

    while (CurrentOffset.QuadPart < EndOffset.QuadPart)
    {
        NextOffset.HighPart = CurrentOffset.HighPart;
        NextOffset.LowPart = (CurrentOffset.LowPart + CACHE_STRIPE) & ~(CACHE_STRIPE - 1);
        DPRINT("NextOffset %08x%08x\n", NextOffset.u.HighPart, NextOffset.u.LowPart);
        WriteLen = MIN(NextOffset.QuadPart - CurrentOffset.QuadPart, Length);

        DPRINT("Copying %x bytes from %08x%08x\n",
               WriteLen,
               CurrentOffset.u.HighPart,
               CurrentOffset.u.LowPart);

        DPRINT("CcPreparePinWrite\n");

        Result = CcPreparePinWrite(FileObject,
                                   &CurrentOffset,
                                   WriteLen,
                                   FALSE,
                                   Wait ? PIN_WAIT : PIN_IF_BCB,
                                   (PVOID *)&Bcb, &WriteBuf);

        DPRINT("Result %s %x %x\n", Result ? "TRUE" : "FALSE", Bcb, WriteBuf);
        if (!Result)
        {
            DPRINT1("CcPreparePinWrite Failed?\n");
            if (Wait)
                RtlRaiseStatus(STATUS_NOT_MAPPED_DATA);
            else
                return FALSE;
        }

        DPRINT("Copying actual memory to BCB#%x (@%x) (from buffer at %x)\n",
               Bcb - CcCacheSections,
               WriteBuf,
               Bcb->BaseAddress);

        RtlCopyMemory(WriteBuf, ((PCHAR)Buffer) + Count, WriteLen);
        Count += WriteLen;
        Length -= WriteLen;
        CurrentOffset = NextOffset;
        Bcb->Dirty = TRUE;
        CcUnpinData(Bcb);
    }

    DPRINT("Done with CcCopyWrite\n");

    return TRUE;
}

VOID
NTAPI
CcFastCopyWrite(IN PFILE_OBJECT FileObject,
                IN ULONG FileOffset,
                IN ULONG Length,
                IN PVOID Buffer)
{
    UNIMPLEMENTED_DBGBREAK();
}

BOOLEAN
NTAPI
CcCanIWrite(IN PFILE_OBJECT FileObject,
            IN ULONG BytesToWrite,
            IN BOOLEAN Wait,
            IN UCHAR Retrying)
{
    UNIMPLEMENTED_DBGBREAK();
    return FALSE;
}

VOID
NTAPI
CcDeferWrite(IN PFILE_OBJECT FileObject,
             IN PCC_POST_DEFERRED_WRITE PostRoutine,
             IN PVOID Context1,
             IN PVOID Context2,
             IN ULONG BytesToWrite,
             IN BOOLEAN Retrying)
{
    UNIMPLEMENTED_DBGBREAK();
}

/* EOF */
