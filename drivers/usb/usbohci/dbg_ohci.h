/*
 * PROJECT:     classicOS USB OHCI Miniport Driver
 * LICENSE:     GPL-2.0+ (https://spdx.org/licenses/GPL-2.0+)
 * PURPOSE:     USBOHCI debugging declarations
 * COPYRIGHT:   Copyright 2017-2018 Vadim Galyant <vgal@rambler.ru>
 */

#ifndef DBG_OHCI_H__
#define DBG_OHCI_H__

#if DBG

    #ifndef NDEBUG_OHCI_TRACE
        #define DPRINT_OHCI(fmt, ...) do { \
            if (DbgPrint("(%s:%d) " fmt, __RELFILE__, __LINE__, ##__VA_ARGS__))  \
                DbgPrint("(%s:%d) DbgPrint() failed!\n", __RELFILE__, __LINE__); \
        } while (0)
    #else
        #if defined(_MSC_VER)
            #define DPRINT_OHCI __noop
        #else
            #define DPRINT_OHCI(...) do {if(0) {DbgPrint(__VA_ARGS__);}} while(0)
        #endif
    #endif

#else /* not DBG */

    #if defined(_MSC_VER)
        #define DPRINT_OHCI __noop
    #else
        #define DPRINT_OHCI(...) do {if(0) {DbgPrint(__VA_ARGS__);}} while(0)
    #endif /* _MSC_VER */

#endif /* not DBG */

#endif /* DBG_OHCI_H__ */
