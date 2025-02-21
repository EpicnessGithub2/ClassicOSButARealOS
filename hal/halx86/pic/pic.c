/*
 * PROJECT:         classicOS HAL
 * LICENSE:         BSD - See COPYING.ARM in the top level directory
 * PURPOSE:         HAL PIC Management and Control Code
 * PROGRAMMERS:     classicOS Portable Systems Group
 */

/* INCLUDES *******************************************************************/

#include <hal.h>

#define NDEBUG
#include <debug.h>

VOID
NTAPI
HalpEndSoftwareInterrupt(IN KIRQL OldIrql,
                         IN PKTRAP_FRAME TrapFrame);

/* GLOBALS ********************************************************************/

#ifndef _MINIHAL_
/*
 * This table basically keeps track of level vs edge triggered interrupts.
 * Windows has 250+ entries, but it seems stupid to replicate that since the PIC
 * can't actually have that many.
 *
 * When a level interrupt is registered, the respective pointer in this table is
 * modified to point to a dimiss routine for level interrupts instead.
 *
 * The other thing this table does is special case IRQ7, IRQ13 and IRQ15:
 *
 * - If an IRQ line is deasserted before it is acknowledged due to a noise spike
 *   generated by an expansion device (since the IRQ line is low during the 1st
 *   acknowledge bus cycle), the i8259 will keep the line low for at least 100ns
 *   When the spike passes, a pull-up resistor will return the IRQ line to high.
 *   Since the PIC requires the input be high until the first acknowledge, the
 *   i8259 knows that this was a spurious interrupt, and on the second interrupt
 *   acknowledge cycle, it reports this to the CPU. Since no valid interrupt has
 *   actually happened Intel hardcoded the chip to report IRQ7 on the master PIC
 *   and IRQ15 on the slave PIC (IR7 either way).
 *
 *   "ISA System Architecture", 3rd Edition, states that these cases should be
 *   handled by reading the respective Interrupt Service Request (ISR) bits from
 *   the affected PIC, and validate whether or not IR7 is set. If it isn't, then
 *   the interrupt is spurious and should be ignored.
 *
 *   Note that for a spurious IRQ15, we DO have to send an EOI to the master for
 *   IRQ2 since the line was asserted by the slave when it received the spurious
 *   IRQ15!
 *
 * - When the 80287/80387 math co-processor generates an FPU/NPX trap, this is
 *   connected to IRQ13, so we have to clear the busy latch on the NPX port.
 */
PHAL_DISMISS_INTERRUPT HalpSpecialDismissTable[16] =
{
    HalpDismissIrqGeneric,
    HalpDismissIrqGeneric,
    HalpDismissIrqGeneric,
    HalpDismissIrqGeneric,
    HalpDismissIrqGeneric,
    HalpDismissIrqGeneric,
    HalpDismissIrqGeneric,
    HalpDismissIrq07,
#if defined(SARCH_PC98)
    HalpDismissIrq08,
#else
    HalpDismissIrqGeneric,
#endif
    HalpDismissIrqGeneric,
    HalpDismissIrqGeneric,
    HalpDismissIrqGeneric,
    HalpDismissIrqGeneric,
#if defined(SARCH_PC98)
    HalpDismissIrqGeneric,
#else
    HalpDismissIrq13,
#endif
    HalpDismissIrqGeneric,
    HalpDismissIrq15
};

/*
 * These are the level IRQ dismissal functions that get copied in the table
 * above if the given IRQ is actually level triggered.
 */
PHAL_DISMISS_INTERRUPT HalpSpecialDismissLevelTable[16] =
{
    HalpDismissIrqLevel,
    HalpDismissIrqLevel,
    HalpDismissIrqLevel,
    HalpDismissIrqLevel,
    HalpDismissIrqLevel,
    HalpDismissIrqLevel,
    HalpDismissIrqLevel,
    HalpDismissIrq07Level,
#if defined(SARCH_PC98)
    HalpDismissIrq08Level,
#else
    HalpDismissIrqLevel,
#endif
    HalpDismissIrqLevel,
    HalpDismissIrqLevel,
    HalpDismissIrqLevel,
    HalpDismissIrqLevel,
#if defined(SARCH_PC98)
    HalpDismissIrqLevel,
#else
    HalpDismissIrq13Level,
#endif
    HalpDismissIrqLevel,
    HalpDismissIrq15Level
};

/* This table contains the static x86 PIC mapping between IRQLs and IRQs */
extern ULONG KiI8259MaskTable[32];

/* This table indicates which IRQs, if pending, can preempt a given IRQL level */
extern ULONG FindHigherIrqlMask[32];

/* Denotes minimum required IRQL before we can process pending SW interrupts */
KIRQL SWInterruptLookUpTable[8] =
{
    PASSIVE_LEVEL,                 /* IRR 0 */
    PASSIVE_LEVEL,                 /* IRR 1 */
    APC_LEVEL,                     /* IRR 2 */
    APC_LEVEL,                     /* IRR 3 */
    DISPATCH_LEVEL,                /* IRR 4 */
    DISPATCH_LEVEL,                /* IRR 5 */
    DISPATCH_LEVEL,                /* IRR 6 */
    DISPATCH_LEVEL                 /* IRR 7 */
};

#if defined(__GNUC__)

#define HalpDelayedHardwareInterrupt(x)                             \
    VOID __cdecl HalpHardwareInterrupt##x(VOID);                    \
    VOID                                                            \
    __cdecl                                                         \
    HalpHardwareInterrupt##x(VOID)                                  \
    {                                                               \
        asm volatile ("int $%c0\n"::"i"(PRIMARY_VECTOR_BASE + x));  \
    }

#elif defined(_MSC_VER)

#define HalpDelayedHardwareInterrupt(x)                             \
    VOID __cdecl HalpHardwareInterrupt##x(VOID);                    \
    VOID                                                            \
    __cdecl                                                         \
    HalpHardwareInterrupt##x(VOID)                                  \
    {                                                               \
        __asm                                                       \
        {                                                           \
            int PRIMARY_VECTOR_BASE + x                             \
        }                                                           \
    }

#else
#error Unsupported compiler
#endif

/* Pending/delayed hardware interrupt handlers */
HalpDelayedHardwareInterrupt(0);
HalpDelayedHardwareInterrupt(1);
HalpDelayedHardwareInterrupt(2);
HalpDelayedHardwareInterrupt(3);
HalpDelayedHardwareInterrupt(4);
HalpDelayedHardwareInterrupt(5);
HalpDelayedHardwareInterrupt(6);
HalpDelayedHardwareInterrupt(7);
HalpDelayedHardwareInterrupt(8);
HalpDelayedHardwareInterrupt(9);
HalpDelayedHardwareInterrupt(10);
HalpDelayedHardwareInterrupt(11);
HalpDelayedHardwareInterrupt(12);
HalpDelayedHardwareInterrupt(13);
HalpDelayedHardwareInterrupt(14);
HalpDelayedHardwareInterrupt(15);

/* Handlers for pending interrupts */
PHAL_SW_INTERRUPT_HANDLER SWInterruptHandlerTable[20] =
{
    (PHAL_SW_INTERRUPT_HANDLER)KiUnexpectedInterrupt,
    HalpApcInterrupt,
    HalpDispatchInterrupt,
    (PHAL_SW_INTERRUPT_HANDLER)KiUnexpectedInterrupt,
    HalpHardwareInterrupt0,
    HalpHardwareInterrupt1,
    HalpHardwareInterrupt2,
    HalpHardwareInterrupt3,
    HalpHardwareInterrupt4,
    HalpHardwareInterrupt5,
    HalpHardwareInterrupt6,
    HalpHardwareInterrupt7,
    HalpHardwareInterrupt8,
    HalpHardwareInterrupt9,
    HalpHardwareInterrupt10,
    HalpHardwareInterrupt11,
    HalpHardwareInterrupt12,
    HalpHardwareInterrupt13,
    HalpHardwareInterrupt14,
    HalpHardwareInterrupt15
};

/* Handlers for pending software interrupts when we already have a trap frame*/
PHAL_SW_INTERRUPT_HANDLER_2ND_ENTRY SWInterruptHandlerTable2[3] =
{
    (PHAL_SW_INTERRUPT_HANDLER_2ND_ENTRY)(PVOID)KiUnexpectedInterrupt,
    HalpApcInterrupt2ndEntry,
    HalpDispatchInterrupt2ndEntry
};

LONG HalpEisaELCR;

/* FUNCTIONS ******************************************************************/

VOID
NTAPI
HalpInitializePICs(IN BOOLEAN EnableInterrupts)
{
    ULONG EFlags;
    EISA_ELCR Elcr;
    ULONG i, j;
    BOOLEAN ElcrFound;

    /* Save EFlags and disable interrupts */
    EFlags = __readeflags();
    _disable();

    /* Initialize and mask the PIC */
    HalpInitializeLegacyPICs();

    /* Read EISA Edge/Level Register for master and slave */
    Elcr.Bits = (__inbyte(EISA_ELCR_SLAVE) << 8) | __inbyte(EISA_ELCR_MASTER);

#if defined(SARCH_PC98)
    /* Force defaults when ELCR is not supported */
    if (Elcr.Bits == 0xFFFF)
    {
        Elcr.Master.Irq0Level = 0;
        Elcr.Master.Irq1Level = 0;
        Elcr.Master.Irq7Level = 0;
        Elcr.Slave.Irq8Level = 0;
    }
    ElcrFound = TRUE;
#else
    /* IRQs 0, 1, 2, 8, and 13 are system-reserved and must be edge */
    ElcrFound = (!(Elcr.Master.Irq0Level) && !(Elcr.Master.Irq1Level) && !(Elcr.Master.Irq2Level) &&
                 !(Elcr.Slave.Irq8Level) && !(Elcr.Slave.Irq13Level));
#endif

    if (ElcrFound)
    {
        /* ELCR is as it's supposed to be, save it */
        HalpEisaELCR = Elcr.Bits;

        /* Scan for level interrupts */
        for (i = 1, j = 0; j < 16; i <<= 1, j++)
        {
            if (HalpEisaELCR & i)
            {
                /* Switch handler to level */
                SWInterruptHandlerTable[j + 4] = HalpHardwareInterruptLevel;

                /* Switch dismiss to level */
                HalpSpecialDismissTable[j] = HalpSpecialDismissLevelTable[j];
            }
        }
    }

    /* Report cascade IRQ usage */
    HalpRegisterVector(IDT_INTERNAL,
                       PRIMARY_VECTOR_BASE + PIC_CASCADE_IRQ,
                       PRIMARY_VECTOR_BASE + PIC_CASCADE_IRQ,
                       HIGH_LEVEL);

    /* Restore interrupt state */
    if (EnableInterrupts) EFlags |= EFLAGS_INTERRUPT_MASK;
    __writeeflags(EFlags);
}

UCHAR
FASTCALL
HalpIrqToVector(UCHAR Irq)
{
    return (PRIMARY_VECTOR_BASE + Irq);
}

UCHAR
FASTCALL
HalpVectorToIrq(UCHAR Vector)
{
    return (Vector - PRIMARY_VECTOR_BASE);
}

KIRQL
FASTCALL
HalpVectorToIrql(UCHAR Vector)
{
    return (PROFILE_LEVEL - (Vector - PRIMARY_VECTOR_BASE));
}

/* IRQL MANAGEMENT ************************************************************/

/*
 * @implemented
 */
KIRQL
NTAPI
KeGetCurrentIrql(VOID)
{
    /* Return the IRQL */
    return KeGetPcr()->Irql;
}

/*
 * @implemented
 */
KIRQL
NTAPI
KeRaiseIrqlToDpcLevel(VOID)
{
    PKPCR Pcr = KeGetPcr();
    KIRQL CurrentIrql;

    /* Save and update IRQL */
    CurrentIrql = Pcr->Irql;
    Pcr->Irql = DISPATCH_LEVEL;

#if DBG
    /* Validate correct raise */
    if (CurrentIrql > DISPATCH_LEVEL) KeBugCheck(IRQL_NOT_GREATER_OR_EQUAL);
#endif

    /* Return the previous value */
    return CurrentIrql;
}

/*
 * @implemented
 */
KIRQL
NTAPI
KeRaiseIrqlToSynchLevel(VOID)
{
    PKPCR Pcr = KeGetPcr();
    KIRQL CurrentIrql;

    /* Save and update IRQL */
    CurrentIrql = Pcr->Irql;
    Pcr->Irql = SYNCH_LEVEL;

#if DBG
    /* Validate correct raise */
    if (CurrentIrql > SYNCH_LEVEL)
    {
        /* Crash system */
        KeBugCheckEx(IRQL_NOT_GREATER_OR_EQUAL,
                     CurrentIrql,
                     SYNCH_LEVEL,
                     0,
                     1);
    }
#endif

    /* Return the previous value */
    return CurrentIrql;
}

/*
 * @implemented
 */
KIRQL
FASTCALL
KfRaiseIrql(IN KIRQL NewIrql)
{
    PKPCR Pcr = KeGetPcr();
    KIRQL CurrentIrql;

    /* Read current IRQL */
    CurrentIrql = Pcr->Irql;

#if DBG
    /* Validate correct raise */
    if (CurrentIrql > NewIrql)
    {
        /* Crash system */
        Pcr->Irql = PASSIVE_LEVEL;
        KeBugCheck(IRQL_NOT_GREATER_OR_EQUAL);
    }
#endif

    /* Set new IRQL */
    Pcr->Irql = NewIrql;

    /* Return old IRQL */
    return CurrentIrql;
}


/*
 * @implemented
 */
VOID
FASTCALL
KfLowerIrql(IN KIRQL OldIrql)
{
    ULONG EFlags;
    ULONG PendingIrql, PendingIrqlMask;
    PKPCR Pcr = KeGetPcr();
    PIC_MASK Mask;

#if DBG
    /* Validate correct lower */
    if (OldIrql > Pcr->Irql)
    {
        /* Crash system */
        Pcr->Irql = HIGH_LEVEL;
        KeBugCheck(IRQL_NOT_LESS_OR_EQUAL);
    }
#endif

    /* Save EFlags and disable interrupts */
    EFlags = __readeflags();
    _disable();

    /* Set old IRQL */
    Pcr->Irql = OldIrql;

    /* Check for pending software interrupts and compare with current IRQL */
    PendingIrqlMask = Pcr->IRR & FindHigherIrqlMask[OldIrql];
    if (PendingIrqlMask)
    {
        /* Check if pending IRQL affects hardware state */
        BitScanReverse(&PendingIrql, PendingIrqlMask);
        if (PendingIrql > DISPATCH_LEVEL)
        {
            /* Set new PIC mask */
            Mask.Both = Pcr->IDR & 0xFFFF;
            __outbyte(PIC1_DATA_PORT, Mask.Master);
            __outbyte(PIC2_DATA_PORT, Mask.Slave);

            /* Clear IRR bit */
            Pcr->IRR ^= (1 << PendingIrql);
        }

        /* Now handle pending interrupt */
        SWInterruptHandlerTable[PendingIrql]();
    }

    /* Restore interrupt state */
    __writeeflags(EFlags);
}

/* SOFTWARE INTERRUPTS ********************************************************/

/*
 * @implemented
 */
VOID
FASTCALL
HalRequestSoftwareInterrupt(IN KIRQL Irql)
{
    ULONG EFlags;
    PKPCR Pcr = KeGetPcr();
    KIRQL PendingIrql;

    /* Save EFlags and disable interrupts */
    EFlags = __readeflags();
    _disable();

    /* Mask out the requested bit */
    Pcr->IRR |= (1 << Irql);

    /* Check for pending software interrupts and compare with current IRQL */
    PendingIrql = SWInterruptLookUpTable[Pcr->IRR & 3];
    if (PendingIrql > Pcr->Irql) SWInterruptHandlerTable[PendingIrql]();

    /* Restore interrupt state */
    __writeeflags(EFlags);
}

/*
 * @implemented
 */
VOID
FASTCALL
HalClearSoftwareInterrupt(IN KIRQL Irql)
{
    /* Mask out the requested bit */
    KeGetPcr()->IRR &= ~(1 << Irql);
}

PHAL_SW_INTERRUPT_HANDLER_2ND_ENTRY
FASTCALL
HalpEndSoftwareInterrupt2(IN KIRQL OldIrql,
                          IN PKTRAP_FRAME TrapFrame)
{
    ULONG PendingIrql, PendingIrqlMask, PendingIrqMask;
    PKPCR Pcr = KeGetPcr();
    PIC_MASK Mask;

    UNREFERENCED_PARAMETER(TrapFrame);

    /* Set old IRQL */
    Pcr->Irql = OldIrql;

    /* Loop checking for pending interrupts */
    while (TRUE)
    {
        /* Check for pending software interrupts and compare with current IRQL */
        PendingIrqlMask = Pcr->IRR & FindHigherIrqlMask[OldIrql];
        if (!PendingIrqlMask) return NULL;

        /* Check for in-service delayed interrupt */
        if (Pcr->IrrActive & 0xFFFFFFF0) return NULL;

        /* Check if pending IRQL affects hardware state */
        BitScanReverse(&PendingIrql, PendingIrqlMask);
        if (PendingIrql > DISPATCH_LEVEL)
        {
            /* Set new PIC mask */
            Mask.Both = Pcr->IDR & 0xFFFF;
            __outbyte(PIC1_DATA_PORT, Mask.Master);
            __outbyte(PIC2_DATA_PORT, Mask.Slave);

            /* Set active bit otherwise, and clear it from IRR */
            PendingIrqMask = (1 << PendingIrql);
            Pcr->IrrActive |= PendingIrqMask;
            Pcr->IRR ^= PendingIrqMask;

            /* Handle delayed hardware interrupt */
            SWInterruptHandlerTable[PendingIrql]();

            /* Handling complete */
            Pcr->IrrActive ^= PendingIrqMask;
        }
        else
        {
            /* No need to loop checking for hardware interrupts */
            return SWInterruptHandlerTable2[PendingIrql];
        }
    }

    return NULL;
}

/* EDGE INTERRUPT DISMISSAL FUNCTIONS *****************************************/

FORCEINLINE
BOOLEAN
_HalpDismissIrqGeneric(IN KIRQL Irql,
                       IN ULONG Irq,
                       OUT PKIRQL OldIrql)
{
    PIC_MASK Mask;
    KIRQL CurrentIrql;
    I8259_OCW2 Ocw2;
    PKPCR Pcr = KeGetPcr();

    /* First save current IRQL and compare it to the requested one */
    CurrentIrql = Pcr->Irql;

    /* Check if this interrupt is really allowed to happen */
    if (Irql > CurrentIrql)
    {
        /* Set the new IRQL and return the current one */
        Pcr->Irql = Irql;
        *OldIrql = CurrentIrql;

        /* Prepare OCW2 for EOI */
        Ocw2.Bits = 0;
        Ocw2.EoiMode = SpecificEoi;

        /* Check which PIC needs the EOI */
        if (Irq >= 8)
        {
#if defined(SARCH_PC98)
            I8259_OCW3 Ocw3;
            I8259_ISR Isr;

            /* Send the EOI for the IRQ */
            __outbyte(PIC2_CONTROL_PORT, Ocw2.Bits | ((Irq - 8) & 0xFF));

            /* Request the ISR */
            Ocw3.Bits = 0;
            Ocw3.Sbo = 1;
            Ocw3.ReadRequest = ReadIsr;
            __outbyte(PIC2_CONTROL_PORT, Ocw3.Bits);

            /* Read the ISR */
            Isr.Bits = __inbyte(PIC2_CONTROL_PORT);

            /* Check if the interrupt serviced was the only one from the slave PIC */
            if (Isr.Bits == 0)
            {
                /* If ISR is empty, send the EOI for cascade IRQ on the master PIC */
                __outbyte(PIC1_CONTROL_PORT, Ocw2.Bits | PIC_CASCADE_IRQ);
            }
#else
            /* Send the EOI for the IRQ */
            __outbyte(PIC2_CONTROL_PORT, Ocw2.Bits | ((Irq - 8) & 0xFF));

            /* Send the EOI for cascade IRQ on the master PIC */
            __outbyte(PIC1_CONTROL_PORT, Ocw2.Bits | PIC_CASCADE_IRQ);
#endif
        }
        else
        {
            /* Send the EOI for the IRQ */
            __outbyte(PIC1_CONTROL_PORT, Ocw2.Bits | (Irq & 0xFF));
        }

        /* Enable interrupts and return success */
        _enable();
        return TRUE;
    }

    /* Update the IRR so that we deliver this interrupt when the IRQL is proper */
    Pcr->IRR |= (1 << (Irq + 4));

    /* Set new PIC mask to real IRQL level, since the optimization is lost now */
    Mask.Both = (KiI8259MaskTable[CurrentIrql] | Pcr->IDR) & 0xFFFF;
    __outbyte(PIC1_DATA_PORT, Mask.Master);
    __outbyte(PIC2_DATA_PORT, Mask.Slave);

    /* Now lie and say this was spurious */
    return FALSE;
}

BOOLEAN
NTAPI
HalpDismissIrqGeneric(IN KIRQL Irql,
                      IN ULONG Irq,
                      OUT PKIRQL OldIrql)
{
    /* Run the inline code */
    return _HalpDismissIrqGeneric(Irql, Irq, OldIrql);
}

BOOLEAN
NTAPI
HalpDismissIrq15(IN KIRQL Irql,
                 IN ULONG Irq,
                 OUT PKIRQL OldIrql)
{
    I8259_OCW3 Ocw3;
    I8259_OCW2 Ocw2;
    I8259_ISR Isr;

    /* Request the ISR */
    Ocw3.Bits = 0;
    Ocw3.Sbo = 1; /* This encodes an OCW3 vs. an OCW2 */
    Ocw3.ReadRequest = ReadIsr;
    __outbyte(PIC2_CONTROL_PORT, Ocw3.Bits);

    /* Read the ISR */
    Isr.Bits = __inbyte(PIC2_CONTROL_PORT);

    /* Is IRQ15 really active (this is IR7) */
    if (Isr.Irq7 == FALSE)
    {
        /* It isn't, so we have to EOI cascade IRQ */
        Ocw2.Bits = 0;
        Ocw2.EoiMode = SpecificEoi;
        __outbyte(PIC1_CONTROL_PORT, Ocw2.Bits | PIC_CASCADE_IRQ);

        /* And now fail since this was spurious */
        return FALSE;
    }

    /* Do normal interrupt dismiss */
    return _HalpDismissIrqGeneric(Irql, Irq, OldIrql);
}

BOOLEAN
NTAPI
HalpDismissIrq13(IN KIRQL Irql,
                 IN ULONG Irq,
                 OUT PKIRQL OldIrql)
{
    /* Clear the FPU busy latch */
    __outbyte(0xF0, 0);

    /* Do normal interrupt dismiss */
    return _HalpDismissIrqGeneric(Irql, Irq, OldIrql);
}

#if defined(SARCH_PC98)
BOOLEAN
NTAPI
HalpDismissIrq08(
    _In_ KIRQL Irql,
    _In_ ULONG Irq,
    _Out_ PKIRQL OldIrql)
{
    /* Clear the FPU busy latch */
    __outbyte(CPU_IO_o_FPU_BUSY_LATCH, 0);

    /* Do normal interrupt dismiss */
    return _HalpDismissIrqGeneric(Irql, Irq, OldIrql);
}
#endif

BOOLEAN
NTAPI
HalpDismissIrq07(IN KIRQL Irql,
                 IN ULONG Irq,
                 OUT PKIRQL OldIrql)
{
    I8259_OCW3 Ocw3;
    I8259_ISR Isr;

    /* Request the ISR */
    Ocw3.Bits = 0;
    Ocw3.Sbo = 1;
    Ocw3.ReadRequest = ReadIsr;
    __outbyte(PIC1_CONTROL_PORT, Ocw3.Bits);

    /* Read the ISR */
    Isr.Bits = __inbyte(PIC1_CONTROL_PORT);

    /* Is IRQ 7 really active? If it isn't, this is spurious so fail */
    if (Isr.Irq7 == FALSE) return FALSE;

    /* Do normal interrupt dismiss */
    return _HalpDismissIrqGeneric(Irql, Irq, OldIrql);
}

/* LEVEL INTERRUPT DISMISSAL FUNCTIONS ****************************************/

FORCEINLINE
BOOLEAN
_HalpDismissIrqLevel(IN KIRQL Irql,
                     IN ULONG Irq,
                     OUT PKIRQL OldIrql)
{
    PIC_MASK Mask;
    KIRQL CurrentIrql;
    I8259_OCW2 Ocw2;
    PKPCR Pcr = KeGetPcr();

    /* Update the PIC */
    Mask.Both = (KiI8259MaskTable[Irql] | Pcr->IDR) & 0xFFFF;
    __outbyte(PIC1_DATA_PORT, Mask.Master);
    __outbyte(PIC2_DATA_PORT, Mask.Slave);

    /* Update the IRR so that we clear this interrupt when the IRQL is proper */
    Pcr->IRR |= (1 << (Irq + 4));

    /* Save current IRQL */
    CurrentIrql = Pcr->Irql;

    /* Prepare OCW2 for EOI */
    Ocw2.Bits = 0;
    Ocw2.EoiMode = SpecificEoi;

    /* Check which PIC needs the EOI */
    if (Irq >= 8)
    {
#if defined(SARCH_PC98)
        I8259_OCW3 Ocw3;
        I8259_ISR Isr;

        /* Send the EOI for the IRQ */
        __outbyte(PIC2_CONTROL_PORT, Ocw2.Bits | ((Irq - 8) & 0xFF));

        /* Request the ISR */
        Ocw3.Bits = 0;
        Ocw3.Sbo = 1;
        Ocw3.ReadRequest = ReadIsr;
        __outbyte(PIC2_CONTROL_PORT, Ocw3.Bits);

        /* Read the ISR */
        Isr.Bits = __inbyte(PIC2_CONTROL_PORT);

        /* Check if the interrupt serviced was the only one from the slave PIC */
        if (Isr.Bits == 0)
        {
            /* If ISR is empty, send the EOI for cascade IRQ on the master PIC */
            __outbyte(PIC1_CONTROL_PORT, Ocw2.Bits | PIC_CASCADE_IRQ);
        }
#else
        /* Send the EOI for the IRQ */
        __outbyte(PIC2_CONTROL_PORT, Ocw2.Bits | ((Irq - 8) & 0xFF));

        /* Send the EOI for cascade IRQ on the master PIC */
        __outbyte(PIC1_CONTROL_PORT, Ocw2.Bits | PIC_CASCADE_IRQ);
#endif
    }
    else
    {
        /* Send the EOI for the IRQ */
        __outbyte(PIC1_CONTROL_PORT, Ocw2.Bits | (Irq & 0xFF));
    }

    /* Check if this interrupt should be allowed to happen */
    if (Irql > CurrentIrql)
    {
        /* Set the new IRQL and return the current one */
        Pcr->Irql = Irql;
        *OldIrql = CurrentIrql;

        /* Enable interrupts and return success */
        _enable();
        return TRUE;
    }

    /* Now lie and say this was spurious */
    return FALSE;
}

BOOLEAN
NTAPI
HalpDismissIrqLevel(IN KIRQL Irql,
                    IN ULONG Irq,
                    OUT PKIRQL OldIrql)
{
    /* Run the inline code */
    return _HalpDismissIrqLevel(Irql, Irq, OldIrql);
}

BOOLEAN
NTAPI
HalpDismissIrq15Level(IN KIRQL Irql,
                      IN ULONG Irq,
                      OUT PKIRQL OldIrql)
{
    I8259_OCW3 Ocw3;
    I8259_OCW2 Ocw2;
    I8259_ISR Isr;

    /* Request the ISR */
    Ocw3.Bits = 0;
    Ocw3.Sbo = 1; /* This encodes an OCW3 vs. an OCW2 */
    Ocw3.ReadRequest = ReadIsr;
    __outbyte(PIC2_CONTROL_PORT, Ocw3.Bits);

    /* Read the ISR */
    Isr.Bits = __inbyte(PIC2_CONTROL_PORT);

    /* Is IRQ15 really active (this is IR7) */
    if (Isr.Irq7 == FALSE)
    {
        /* It isn't, so we have to EOI cascade IRQ */
        Ocw2.Bits = 0;
        Ocw2.EoiMode = SpecificEoi;
        __outbyte(PIC1_CONTROL_PORT, Ocw2.Bits | PIC_CASCADE_IRQ);

        /* And now fail since this was spurious */
        return FALSE;
    }

    /* Do normal interrupt dismiss */
    return _HalpDismissIrqLevel(Irql, Irq, OldIrql);
}

BOOLEAN
NTAPI
HalpDismissIrq13Level(IN KIRQL Irql,
                      IN ULONG Irq,
                      OUT PKIRQL OldIrql)
{
    /* Clear the FPU busy latch */
    __outbyte(0xF0, 0);

    /* Do normal interrupt dismiss */
    return _HalpDismissIrqLevel(Irql, Irq, OldIrql);
}

#if defined(SARCH_PC98)
BOOLEAN
NTAPI
HalpDismissIrq08Level(
    _In_ KIRQL Irql,
    _In_ ULONG Irq,
    _Out_ PKIRQL OldIrql)
{
    /* Clear the FPU busy latch */
    __outbyte(CPU_IO_o_FPU_BUSY_LATCH, 0);

    /* Do normal interrupt dismiss */
    return _HalpDismissIrqLevel(Irql, Irq, OldIrql);
}
#endif

BOOLEAN
NTAPI
HalpDismissIrq07Level(IN KIRQL Irql,
                      IN ULONG Irq,
                      OUT PKIRQL OldIrql)
{
    I8259_OCW3 Ocw3;
    I8259_ISR Isr;

    /* Request the ISR */
    Ocw3.Bits = 0;
    Ocw3.Sbo = 1;
    Ocw3.ReadRequest = ReadIsr;
    __outbyte(PIC1_CONTROL_PORT, Ocw3.Bits);

    /* Read the ISR */
    Isr.Bits = __inbyte(PIC1_CONTROL_PORT);

    /* Is IRQ 7 really active? If it isn't, this is spurious so fail */
    if (Isr.Irq7 == FALSE) return FALSE;

    /* Do normal interrupt dismiss */
    return _HalpDismissIrqLevel(Irql, Irq, OldIrql);
}

PHAL_SW_INTERRUPT_HANDLER
__cdecl
HalpHardwareInterruptLevel2(VOID)
{
    PKPCR Pcr = KeGetPcr();
    ULONG PendingIrqlMask, PendingIrql;

    /* Check for pending software interrupts and compare with current IRQL */
    PendingIrqlMask = Pcr->IRR & FindHigherIrqlMask[Pcr->Irql];
    if (PendingIrqlMask)
    {
        /* Check for in-service delayed interrupt */
        if (Pcr->IrrActive & 0xFFFFFFF0) return NULL;

        /* Check if pending IRQL affects hardware state */
        BitScanReverse(&PendingIrql, PendingIrqlMask);

        /* Clear IRR bit */
        Pcr->IRR ^= (1 << PendingIrql);

        /* Now handle pending interrupt */
        return SWInterruptHandlerTable[PendingIrql];
    }

    return NULL;
}

/* SYSTEM INTERRUPTS **********************************************************/

/*
 * @implemented
 */
BOOLEAN
NTAPI
HalEnableSystemInterrupt(IN ULONG Vector,
                         IN KIRQL Irql,
                         IN KINTERRUPT_MODE InterruptMode)
{
    ULONG Irq;
    PKPCR Pcr = KeGetPcr();
    PIC_MASK PicMask;

    /* Validate the IRQ */
    Irq = Vector - PRIMARY_VECTOR_BASE;
    if (Irq >= CLOCK2_LEVEL) return FALSE;

    /* Check for level interrupt */
    if (InterruptMode == LevelSensitive)
    {
        /* Switch handler to level */
        SWInterruptHandlerTable[Irq + 4] = HalpHardwareInterruptLevel;

        /* Switch dismiss to level */
        HalpSpecialDismissTable[Irq] = HalpSpecialDismissLevelTable[Irq];
    }

    /* Disable interrupts */
    _disable();

    /* Update software IDR */
    Pcr->IDR &= ~(1 << Irq);

    /* Set new PIC mask */
    PicMask.Both = (KiI8259MaskTable[Pcr->Irql] | Pcr->IDR) & 0xFFFF;
    __outbyte(PIC1_DATA_PORT, PicMask.Master);
    __outbyte(PIC2_DATA_PORT, PicMask.Slave);

    /* Enable interrupts and exit */
    _enable();
    return TRUE;
}

/*
 * @implemented
 */
VOID
NTAPI
HalDisableSystemInterrupt(IN ULONG Vector,
                          IN KIRQL Irql)
{
    ULONG IrqMask;
    PIC_MASK PicMask;

    /* Compute new combined IRQ mask */
    IrqMask = 1 << (Vector - PRIMARY_VECTOR_BASE);

    /* Disable interrupts */
    _disable();

    /* Update software IDR */
    KeGetPcr()->IDR |= IrqMask;

    /* Read current interrupt mask */
    PicMask.Master = __inbyte(PIC1_DATA_PORT);
    PicMask.Slave = __inbyte(PIC2_DATA_PORT);

    /* Add the new disabled interrupt */
    PicMask.Both |= IrqMask;

    /* Write new interrupt mask */
    __outbyte(PIC1_DATA_PORT, PicMask.Master);
    __outbyte(PIC2_DATA_PORT, PicMask.Slave);

    /* Bring interrupts back */
    _enable();
}

/*
 * @implemented
 */
BOOLEAN
NTAPI
HalBeginSystemInterrupt(IN KIRQL Irql,
                        IN ULONG Vector,
                        OUT PKIRQL OldIrql)
{
    ULONG Irq;

    /* Get the IRQ and call the proper routine to handle it */
    Irq = Vector - PRIMARY_VECTOR_BASE;
    return HalpSpecialDismissTable[Irq](Irql, Irq, OldIrql);
}

/*
 * @implemented
 */
PHAL_SW_INTERRUPT_HANDLER_2ND_ENTRY
FASTCALL
HalEndSystemInterrupt2(IN KIRQL OldIrql,
                       IN PKTRAP_FRAME TrapFrame)
{
    ULONG PendingIrql, PendingIrqlMask, PendingIrqMask;
    PKPCR Pcr = KeGetPcr();
    PIC_MASK Mask;

    /* Set old IRQL */
    Pcr->Irql = OldIrql;

    /* Check for pending software interrupts and compare with current IRQL */
    PendingIrqlMask = Pcr->IRR & FindHigherIrqlMask[OldIrql];
    if (PendingIrqlMask)
    {
        /* Check for in-service delayed interrupt */
        if (Pcr->IrrActive & 0xFFFFFFF0) return NULL;

        /* Loop checking for pending interrupts */
        while (TRUE)
        {
            /* Check if pending IRQL affects hardware state */
            BitScanReverse(&PendingIrql, PendingIrqlMask);
            if (PendingIrql > DISPATCH_LEVEL)
            {
                /* Set new PIC mask */
                Mask.Both = Pcr->IDR & 0xFFFF;
                __outbyte(PIC1_DATA_PORT, Mask.Master);
                __outbyte(PIC2_DATA_PORT, Mask.Slave);

                /* Now check if this specific interrupt is already in-service */
                PendingIrqMask = (1 << PendingIrql);
                if (Pcr->IrrActive & PendingIrqMask) return NULL;

                /* Set active bit otherwise, and clear it from IRR */
                Pcr->IrrActive |= PendingIrqMask;
                Pcr->IRR ^= PendingIrqMask;

                /* Handle delayed hardware interrupt */
                SWInterruptHandlerTable[PendingIrql]();

                /* Handling complete */
                Pcr->IrrActive ^= PendingIrqMask;

                /* Check if there's still interrupts pending */
                PendingIrqlMask = Pcr->IRR & FindHigherIrqlMask[Pcr->Irql];
                if (!PendingIrqlMask) break;
            }
            else
            {
                /* Now handle pending software interrupt */
                return SWInterruptHandlerTable2[PendingIrql];
            }
        }
    }

    return NULL;
}

/* SOFTWARE INTERRUPT TRAPS ***************************************************/

FORCEINLINE
DECLSPEC_NORETURN
VOID
_HalpApcInterruptHandler(IN PKTRAP_FRAME TrapFrame)
{
    KIRQL CurrentIrql;
    PKPCR Pcr = KeGetPcr();

    /* Save the current IRQL and update it */
    CurrentIrql = Pcr->Irql;
    Pcr->Irql = APC_LEVEL;

    /* Remove DPC from IRR */
    Pcr->IRR &= ~(1 << APC_LEVEL);

    /* Enable interrupts and call the kernel's APC interrupt handler */
    _enable();
    KiDeliverApc(((KiUserTrap(TrapFrame)) || (TrapFrame->EFlags & EFLAGS_V86_MASK)) ?
                UserMode : KernelMode,
                NULL,
                TrapFrame);

    /* Disable interrupts and end the interrupt */
    _disable();
    HalpEndSoftwareInterrupt(CurrentIrql, TrapFrame);

    /* Exit the interrupt */
    KiEoiHelper(TrapFrame);
}

DECLSPEC_NORETURN
VOID
FASTCALL
HalpApcInterrupt2ndEntry(IN PKTRAP_FRAME TrapFrame)
{
    /* Do the work */
    _HalpApcInterruptHandler(TrapFrame);
}

DECLSPEC_NORETURN
VOID
FASTCALL
HalpApcInterruptHandler(IN PKTRAP_FRAME TrapFrame)
{
    /* Set up a fake INT Stack */
    TrapFrame->EFlags = __readeflags();
    TrapFrame->SegCs = KGDT_R0_CODE;
    TrapFrame->Eip = TrapFrame->Eax;

    /* Build the trap frame */
    KiEnterInterruptTrap(TrapFrame);

    /* Do the work */
    _HalpApcInterruptHandler(TrapFrame);
}

FORCEINLINE
KIRQL
_HalpDispatchInterruptHandler(VOID)
{
    KIRQL CurrentIrql;
    PKPCR Pcr = KeGetPcr();

    /* Save the current IRQL and update it */
    CurrentIrql = Pcr->Irql;
    Pcr->Irql = DISPATCH_LEVEL;

    /* Remove DPC from IRR */
    Pcr->IRR &= ~(1 << DISPATCH_LEVEL);

    /* Enable interrupts and call the kernel's DPC interrupt handler */
    _enable();
    KiDispatchInterrupt();
    _disable();

    /* Return IRQL */
    return CurrentIrql;
}

DECLSPEC_NORETURN
VOID
FASTCALL
HalpDispatchInterrupt2ndEntry(IN PKTRAP_FRAME TrapFrame)
{
    KIRQL CurrentIrql;

    /* Do the work */
    CurrentIrql = _HalpDispatchInterruptHandler();

    /* End the interrupt */
    HalpEndSoftwareInterrupt(CurrentIrql, TrapFrame);

    /* Exit the interrupt */
    KiEoiHelper(TrapFrame);
}

PHAL_SW_INTERRUPT_HANDLER
__cdecl
HalpDispatchInterrupt2(VOID)
{
    ULONG PendingIrqlMask, PendingIrql;
    KIRQL OldIrql;
    PIC_MASK Mask;
    PKPCR Pcr = KeGetPcr();

    /* Do the work */
    OldIrql = _HalpDispatchInterruptHandler();

    /* Restore IRQL */
    Pcr->Irql = OldIrql;

    /* Check for pending software interrupts and compare with current IRQL */
    PendingIrqlMask = Pcr->IRR & FindHigherIrqlMask[OldIrql];
    if (PendingIrqlMask)
    {
        /* Check if pending IRQL affects hardware state */
        BitScanReverse(&PendingIrql, PendingIrqlMask);
        if (PendingIrql > DISPATCH_LEVEL)
        {
            /* Set new PIC mask */
            Mask.Both = Pcr->IDR & 0xFFFF;
            __outbyte(PIC1_DATA_PORT, Mask.Master);
            __outbyte(PIC2_DATA_PORT, Mask.Slave);

            /* Clear IRR bit */
            Pcr->IRR ^= (1 << PendingIrql);
        }

        /* Now handle pending interrupt */
        return SWInterruptHandlerTable[PendingIrql];
    }

    return NULL;
}

ULONG
NTAPI
HalpGetRootInterruptVector(IN ULONG BusInterruptLevel,
                           IN ULONG BusInterruptVector,
                           OUT PKIRQL Irql,
                           OUT PKAFFINITY Affinity)
{
    UCHAR SystemVector;

    /* Validate the IRQ */
    if (BusInterruptLevel > 23)
    {
        /* Invalid vector */
        DPRINT1("IRQ %lx is too high!\n", BusInterruptLevel);
        return 0;
    }

    /* Get the system vector */
    SystemVector = HalpIrqToVector((UCHAR)BusInterruptLevel);

    /* Return the IRQL and affinity */
    *Irql = HalpVectorToIrql(SystemVector);
    *Affinity = HalpDefaultInterruptAffinity;
    ASSERT(HalpDefaultInterruptAffinity);

    /* Return the vector */
    return SystemVector;
}

#else /* _MINIHAL_ */

KIRQL
NTAPI
KeGetCurrentIrql(VOID)
{
    return PASSIVE_LEVEL;
}

VOID
FASTCALL
KfLowerIrql(
    IN KIRQL OldIrql)
{
}

KIRQL
FASTCALL
KfRaiseIrql(
    IN KIRQL NewIrql)
{
    return NewIrql;
}

#endif /* !_MINIHAL_ */
