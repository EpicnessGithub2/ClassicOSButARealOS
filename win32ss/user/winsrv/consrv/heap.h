/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         classicOS Console Server DLL
 * FILE:            win32ss/user/winsrv/consrv/heap.h
 * PURPOSE:         Heap Helpers
 * PROGRAMMERS:     Hermes Belusca-Maito (hermes.belusca@sfr.fr)
 */

#pragma once

/* See init.c */
extern HANDLE ConSrvHeap;

#define ConsoleAllocHeap(Flags, Size)   RtlAllocateHeap(ConSrvHeap, Flags, Size)
#define ConsoleFreeHeap(HeapBase)       RtlFreeHeap(ConSrvHeap, 0, HeapBase)
