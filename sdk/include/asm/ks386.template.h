
HEADER("CR0 flags"),
CONSTANT(CR0_PE),
CONSTANT(CR0_MP),
CONSTANT(CR0_EM),
CONSTANT(CR0_TS),
CONSTANT(CR0_ET),
CONSTANT(CR0_NE),
CONSTANT(CR0_WP),
CONSTANT(CR0_AM), // not win 10
CONSTANT(CR0_NW),
CONSTANT(CR0_CD),
CONSTANT(CR0_PG),

HEADER("CR4 flags"),
CONSTANT(CR4_VME),
CONSTANT(CR4_PVI),
CONSTANT(CR4_TSD),
CONSTANT(CR4_DE),
CONSTANT(CR4_PSE),
CONSTANT(CR4_PAE),
CONSTANT(CR4_MCE),
CONSTANT(CR4_PGE),
CONSTANT(CR4_FXSR),
CONSTANT(CR4_XMMEXCPT),
//CONSTANT(CR4_PGE_V),
//CONSTANT(CR4_XSAVE),

HEADER("Debug Registers"),
CONSTANT(DR6_LEGAL),
CONSTANT(DR7_LEGAL),
CONSTANT(DR7_ACTIVE),
CONSTANT(DR7_RESERVED_MASK),

HEADER("EFLAGS"),
CONSTANT(EFLAGS_TF),
CONSTANT(EFLAGS_INTERRUPT_MASK),
CONSTANT(EFLAGS_V86_MASK),
CONSTANT(EFLAGS_ALIGN_CHECK),
CONSTANT(EFLAGS_VIF),
CONSTANT(EFLAGS_VIP),
CONSTANT(EFLAGS_USER_SANITIZE),
//CONSTANT(EFLAG_SELECT),

#if (NTDDI_VERSION >= NTDDI_VISTA)
HEADER("Hypervisor Enlightenment Definitions"),
CONSTANT(HV_MMU_USE_HYPERCALL_FOR_ADDRESS_SWITCH),
CONSTANT(HV_MMU_USE_HYPERCALL_FOR_LOCAL_FLUSH),
CONSTANT(HV_MMU_USE_HYPERCALL_FOR_REMOTE_FLUSH),
CONSTANT(HV_KE_USE_HYPERCALL_FOR_LONG_SPIN_WAIT),
#endif

HEADER("KeFeatureBits flags"),
CONSTANT(KF_V86_VIS),
CONSTANT(KF_RDTSC),
CONSTANT(KF_CR4),
CONSTANT(KF_GLOBAL_PAGE),
CONSTANT(KF_LARGE_PAGE),
CONSTANT(KF_CMPXCHG8B),
CONSTANT(KF_FAST_SYSCALL),
//CONSTANT(KF_XSTATE),

HEADER("KGDT selectors"),
CONSTANT(KGDT_NULL),
CONSTANT(KGDT_R0_CODE),
CONSTANT(KGDT_R0_DATA),
CONSTANT(KGDT_R3_CODE),
CONSTANT(KGDT_R3_DATA),
CONSTANT(KGDT_TSS),
CONSTANT(KGDT_R0_PCR),
CONSTANT(KGDT_R3_TEB),
CONSTANT(KGDT_VDM_TILE),
CONSTANT(KGDT_LDT),
CONSTANT(KGDT_DF_TSS),
CONSTANT(KGDT_NMI_TSS),
//CONSTANT(KGDT_R3_GS),
//CONSTANT(KGDT_STACK16),// obsolete
//CONSTANT(KGDT_CODE16), // obsolete

HEADER("Machine type definitions"),
CONSTANT(MACHINE_TYPE_ISA),
CONSTANT(MACHINE_TYPE_EISA),
CONSTANT(MACHINE_TYPE_MCA),

HEADER("MSR definitions"),
CONSTANT(MSR_AMD_ACCESS),
CONSTANT(MSR_IA32_MISC_ENABLE),
CONSTANT(MSR_EFER),

HEADER("MSR values"),
CONSTANT(MSR_NXE),
CONSTANT(XHF_NOEXECUTE),
CONSTANT(MSR_XD_ENABLE_MASK),

HEADER("WOW64 turbo dispatch system call types"),
CONSTANT(ServiceNoTurbo),
CONSTANT(Service0Arg),
CONSTANT(Service0ArgReloadState),
CONSTANT(Service1ArgSp),
CONSTANT(Service1ArgNSp),
CONSTANT(Service2ArgNSpNSp),
CONSTANT(Service2ArgNSpNSpReloadState),
CONSTANT(Service2ArgSpNSp),
CONSTANT(Service2ArgSpSp),
CONSTANT(Service2ArgNSpSp),
CONSTANT(Service3ArgNSpNSpNSp),
CONSTANT(Service3ArgSpSpSp),
CONSTANT(Service3ArgSpNSpNSp),
CONSTANT(Service3ArgSpNSpNSpReloadState),
CONSTANT(Service3ArgSpSpNSp),
CONSTANT(Service3ArgNSpSpNSp),
CONSTANT(Service3ArgSpNSpSp),
CONSTANT(Service4ArgNSpNSpNSpNSp),
CONSTANT(Service4ArgSpSpNSpNSp),
CONSTANT(Service4ArgSpSpNSpNSpReloadState),
CONSTANT(Service4ArgSpNSpNSpNSp),
CONSTANT(Service4ArgSpNSpNSpNSpReloadState),
CONSTANT(Service4ArgNSpSpNSpNSp),
CONSTANT(Service4ArgSpSpSpNSp),
CONSTANT(ServiceCpupTdQuerySystemTime),
CONSTANT(ServiceCpupTdGetCurrentProcessorNumber),
CONSTANT(ServiceCpupTdReadWriteFile),
CONSTANT(ServiceCpupTdDeviceIoControlFile),
CONSTANT(ServiceCpupTdRemoveIoCompletion),
CONSTANT(ServiceCpupTdWaitForMultipleObjects),
CONSTANT(ServiceCpupTdWaitForMultipleObjects32),
CONSTANT(Wow64ServiceTypesCount),

HEADER("VDM constants"),
CONSTANT(VDM_INDEX_Invalid),
CONSTANT(VDM_INDEX_0F),
CONSTANT(VDM_INDEX_ESPrefix),
CONSTANT(VDM_INDEX_CSPrefix),
CONSTANT(VDM_INDEX_SSPrefix),
CONSTANT(VDM_INDEX_DSPrefix),
CONSTANT(VDM_INDEX_FSPrefix),
CONSTANT(VDM_INDEX_GSPrefix),
CONSTANT(VDM_INDEX_OPER32Prefix),
CONSTANT(VDM_INDEX_ADDR32Prefix),
CONSTANT(VDM_INDEX_INSB),
CONSTANT(VDM_INDEX_INSW),
CONSTANT(VDM_INDEX_OUTSB),
CONSTANT(VDM_INDEX_OUTSW),
CONSTANT(VDM_INDEX_PUSHF),
CONSTANT(VDM_INDEX_POPF),
CONSTANT(VDM_INDEX_INTnn),
CONSTANT(VDM_INDEX_INTO),
CONSTANT(VDM_INDEX_IRET),
CONSTANT(VDM_INDEX_NPX),
CONSTANT(VDM_INDEX_INBimm),
CONSTANT(VDM_INDEX_INWimm),
CONSTANT(VDM_INDEX_OUTBimm),
CONSTANT(VDM_INDEX_OUTWimm),
CONSTANT(VDM_INDEX_INB),
CONSTANT(VDM_INDEX_INW),
CONSTANT(VDM_INDEX_OUTB),
CONSTANT(VDM_INDEX_OUTW),
CONSTANT(VDM_INDEX_LOCKPrefix),
CONSTANT(VDM_INDEX_REPNEPrefix),
CONSTANT(VDM_INDEX_REPPrefix),
CONSTANT(VDM_INDEX_CLI),
CONSTANT(VDM_INDEX_STI),
CONSTANT(VDM_INDEX_HLT),
CONSTANT(MAX_VDM_INDEX),

//HEADER("VDM feature bits"),
//CONSTANT(V86_VIRTUAL_INT_EXTENSIONS),
//CONSTANT(PM_VIRTUAL_INT_EXTENSIONS),

HEADER("XSAVE_AREA definitions"),
CONSTANT(XSTATE_MASK_LEGACY_FLOATING_POINT),
CONSTANT(XSTATE_MASK_LEGACY_SSE),
CONSTANT(XSTATE_MASK_LEGACY),
CONSTANT(XSTATE_MASK_GSSE),

//HEADER("Interrupt vector definitions"),
//CONSTANT(IOMMU_VECTOR),
//CONSTANT(STUB_VECTOR),
//CONSTANT(REBOOT_VECTOR),
//CONSTANT(IPI_VECTOR),
//CONSTANT(LOCAL_ERROR_VECTOR),
//CONSTANT(PERF_VECTOR),

HEADER("Miscellaneous constants"),
//CONSTANT(INITIAL_MXCSR),
//CONSTANT(IPI_FREEZE),
//CONSTANT(XSAVE_PRESENT),
SIZE(KTIMER_TABLE_SIZE, KTIMER_TABLE),
//CONSTANT(TRAP_FRAME_MARKER),
CONSTANT(FRAME_EDITED),
//CONSTANT(INTERRUPT_FRAME),
//CONSTANT(EXCEPTION_FRAME),
//CONSTANT(SYSCALL_FRAME),
//CONSTANT(KXMM_FRAME_SIZE),
//CONSTANT(KI_SLIST_FAULT_COUNT_MAXIMUM),
CONSTANT(PF_XMMI_INSTRUCTIONS_AVAILABLE),
CONSTANT(CPU_AMD),
CONSTANT(CPU_INTEL),
//CONSTANT(DEBUG_ACTIVE_MASK),
//CONSTANT(DEBUG_ACTIVE_MINIMAL_THREAD),
//CONSTANT(THREAD_LOCK_FLAGS_DBG_INSTRUMENTED),
//CONSTANT(X86AMD64_R3_LONG_MODE_CODE),
//CONSTANT(SEL_TYPE_NP),
//CONSTANT(TEB_FLAGS_SAFE_THUNK_CALL),
//CONSTANT(TEB_FLAGS_FIBER_SWAPPED),
//CONSTANT(KI_SPINLOCK_ORDER_PRCB_LOCK),
//CONSTANT(PROCESSOR_START_FLAG_FORCE_ENABLE_NX),

HEADER("** FIELD OFFSETS ***************"),

//HEADER("RtlBackoff offsets"),
//OFFSET(BoDelay, ????, Delay),
//SIZE(RtlBackoffLength, ????),

HEADER("CONTEXT offsets"),
OFFSET(CsContextFlags, CONTEXT, ContextFlags),
OFFSET(CsDr0, CONTEXT, Dr0),
OFFSET(CsDr1, CONTEXT, Dr1),
OFFSET(CsDr2, CONTEXT, Dr2),
OFFSET(CsDr3, CONTEXT, Dr3),
OFFSET(CsDr6, CONTEXT, Dr6),
OFFSET(CsDr7, CONTEXT, Dr7),
OFFSET(CsFloatSave, CONTEXT, FloatSave),
OFFSET(CsSegGs, CONTEXT, SegGs),
OFFSET(CsSegFs, CONTEXT, SegFs),
OFFSET(CsSegEs, CONTEXT, SegEs),
OFFSET(CsSegDs, CONTEXT, SegDs),
OFFSET(CsEdi, CONTEXT, Edi),
OFFSET(CsEsi, CONTEXT, Esi),
OFFSET(CsEbx, CONTEXT, Ebx),
OFFSET(CsEdx, CONTEXT, Edx),
OFFSET(CsEcx, CONTEXT, Ecx),
OFFSET(CsEax, CONTEXT, Eax),
OFFSET(CsEbp, CONTEXT, Ebp),
OFFSET(CsEip, CONTEXT, Eip),
OFFSET(CsSegCs, CONTEXT, SegCs),
OFFSET(CsEflags, CONTEXT, EFlags),
OFFSET(CsEsp, CONTEXT, Esp),
OFFSET(CsSegSs, CONTEXT, SegSs),
OFFSET(CsExtendedRegisters, CONTEXT, ExtendedRegisters),
//OFFSET(CsMxCsr, CONTEXT, MxCsr),
SIZE(ContextFrameLength, CONTEXT),
SIZE(CONTEXT_LENGTH, CONTEXT),

HEADER("KCALLOUT_FRAME offsets"),
OFFSET(CuInStk, KCALLOUT_FRAME, InitialStack), // 00000H
OFFSET(CuTrFr, KCALLOUT_FRAME, TrapFrame), // 00004H
OFFSET(CuCbStk, KCALLOUT_FRAME, CallbackStack), // 00008H
OFFSET(CuEdi, KCALLOUT_FRAME, Edi), // 0000CH
OFFSET(CuEsi, KCALLOUT_FRAME, Esi), // 00010H
OFFSET(CuEbx, KCALLOUT_FRAME, Ebx), // 00014H
OFFSET(CuEbp, KCALLOUT_FRAME, Ebp), // 00018H
OFFSET(CuRet, KCALLOUT_FRAME, ReturnAddress), // 0001CH
OFFSET(CuOutBf, KCALLOUT_FRAME, Result), // 00020H
OFFSET(CuOutLn, KCALLOUT_FRAME, ResultLength), // 00024H

//HEADER("??? offsets"),
//OFFSET(ErrHandler, ???, Handler),
//OFFSET(ErrNext, ???, Next),
//OFFSET(ErrLength, ???, Length),

HEADER("FLOATING_SAVE_AREA offsets"),
OFFSET(FpControlWord, FLOATING_SAVE_AREA, ControlWord),
OFFSET(FpStatusWord, FLOATING_SAVE_AREA, StatusWord),
OFFSET(FpTagWord, FLOATING_SAVE_AREA, TagWord),
OFFSET(FpErrorOffset, FLOATING_SAVE_AREA, ErrorOffset),
OFFSET(FpErrorSelector, FLOATING_SAVE_AREA, ErrorSelector),
OFFSET(FpDataOffset, FLOATING_SAVE_AREA, DataOffset),
OFFSET(FpDataSelector, FLOATING_SAVE_AREA, DataSelector),
OFFSET(FpRegisterArea, FLOATING_SAVE_AREA, RegisterArea),

HEADER("XSAVE_FORMAT offsets"),
OFFSET(FxControlWord, XSAVE_FORMAT, ControlWord),
OFFSET(FxStatusWord, XSAVE_FORMAT, StatusWord),
OFFSET(FxTagWord, XSAVE_FORMAT, TagWord),
OFFSET(FxErrorOpcode, XSAVE_FORMAT, ErrorOpcode),
OFFSET(FxErrorOffset, XSAVE_FORMAT, ErrorOffset),
OFFSET(FxErrorSelector, XSAVE_FORMAT, ErrorSelector),
OFFSET(FxDataOffset, XSAVE_FORMAT, DataOffset),
OFFSET(FxDataSelector, XSAVE_FORMAT, DataSelector),
OFFSET(FxMxCsr, XSAVE_FORMAT, MxCsr),
SIZE(XSAVE_FORMAT_SIZE, XSAVE_FORMAT),

HEADER("KGDTENTRY offsets"),
OFFSET(KgdtLimitLow, KGDTENTRY, LimitLow),
OFFSET(KgdtBaseLow, KGDTENTRY, BaseLow),
OFFSET(KgdtHighWord, KGDTENTRY, HighWord),
OFFSET(KgdtBaseMid, KGDTENTRY, HighWord.Bytes.BaseMid),
OFFSET(KgdtLimitHi, KGDTENTRY, HighWord.Bytes.Flags2),
OFFSET(KgdtBaseHi, KGDTENTRY, HighWord.Bytes.BaseHi),

HEADER("KPRCB offsets"),
OFFSET(PbCurrentThread, KPRCB, CurrentThread),
OFFSET(PbNextThread, KPRCB, NextThread),
OFFSET(PbIdleThread, KPRCB, IdleThread),
//OFFSET(PbNestingLevel, KPRCB, NestingLevel),
OFFSET(PbCpuType, KPRCB, CpuType),
OFFSET(PbCpuID, KPRCB, CpuID),
OFFSET(PbCpuStep, KPRCB, CpuStep),
OFFSET(PbProcessorState, KPRCB, ProcessorState),
OFFSET(PbParentNode, KPRCB, ParentNode),
//OFFSET(PbPriorityState, KPRCB, PriorityState),
OFFSET(PbHalReserved, KPRCB, HalReserved),
//OFFSET(PbCFlushSize, KPRCB, CFlushSize),
//OFFSET(PbCpuVendor, KPRCB, CpuVendor),
//OFFSET(PbGroupSetMember, KPRCB, GroupSetMember),
OFFSET(PbNumber, KPRCB, Number),
//OFFSET(PbClockOwner, KPRCB, ClockOwner),
OFFSET(PbLockQueue, KPRCB, LockQueue),
OFFSET(PbInterruptCount, KPRCB, InterruptCount),
OFFSET(PbKernelTime, KPRCB, KernelTime),
OFFSET(PbUserTime, KPRCB, UserTime),
OFFSET(PbDpcTime, KPRCB, DpcTime),
OFFSET(PbInterruptTime, KPRCB, InterruptTime),
OFFSET(PbAdjustDpcThreshold, KPRCB, AdjustDpcThreshold),
OFFSET(PbPageColor, KPRCB, PageColor),
OFFSET(PbDebuggerSavedIRQL, KPRCB, DebuggerSavedIRQL),
OFFSET(PbNodeShiftedColor, KPRCB, NodeShiftedColor),
OFFSET(PbSecondaryColorMask, KPRCB, SecondaryColorMask),
//OFFSET(PbAlignmentFixupCount, KPRCB, AlignmentFixupCount),
//OFFSET(PbExceptionDispatchCount, KPRCB, ExceptionDispatchCount),
OFFSET(PbSystemCalls, KPRCB, KeSystemCalls),
OFFSET(PbPPLookasideList, KPRCB, PPLookasideList),
OFFSET(PbPPNPagedLookasideList, KPRCB, PPNPagedLookasideList),
OFFSET(PbPPPagedLookasideList, KPRCB, PPPagedLookasideList),
OFFSET(PbPacketBarrier, KPRCB, PacketBarrier),
OFFSET(PbReverseStall, KPRCB, ReverseStall),
OFFSET(PbIpiFrame, KPRCB, IpiFrame),
OFFSET(PbCurrentPacket, KPRCB, CurrentPacket),
OFFSET(PbTargetSet, KPRCB, TargetSet),
OFFSET(PbWorkerRoutine, KPRCB, WorkerRoutine),
OFFSET(PbIpiFrozen, KPRCB, IpiFrozen),
OFFSET(PbRequestSummary, KPRCB, RequestSummary),
//OFFSET(PbDpcList, KPRCB, DpcList),
//OFFSET(PbDpcLock, KPRCB, DpcLock),
//OFFSET(PbDpcCount, KPRCB, DpcCount),
OFFSET(PbDpcStack, KPRCB, DpcStack),
OFFSET(PbMaximumDpcQueueDepth, KPRCB, MaximumDpcQueueDepth),
OFFSET(PbDpcRequestRate, KPRCB, DpcRequestRate),
OFFSET(PbMinimumDpcRate, KPRCB, MinimumDpcRate),
OFFSET(PbDpcLastCount, KPRCB, DpcLastCount),
OFFSET(PbPrcbLock, KPRCB, PrcbLock),
OFFSET(PbQuantumEnd, KPRCB, QuantumEnd),
OFFSET(PbDpcRoutineActive, KPRCB, DpcRoutineActive),
OFFSET(PbIdleSchedule, KPRCB, IdleSchedule),
//OFFSET(PbNormalDpcState, KPRCB, NormalDpcState),
//OFFSET(PbKeSpinLockOrdering, KPRCB, KeSpinLockOrdering),
OFFSET(PbDeferredReadyListHead, KPRCB, DeferredReadyListHead),
OFFSET(PbReadySummary, KPRCB, ReadySummary),
OFFSET(PbWaitListHead, KPRCB, WaitListHead),
//OFFSET(PbStartCycle, KPRCB, StartCycle),
//OFFSET(PbCycleTime, KPRCB, CycleTime),
//OFFSET(PbHighCycleTime, KPRCB, HighCycleTime),
OFFSET(PbDispatcherReadyListHead, KPRCB, DispatcherReadyListHead),
OFFSET(PbChainedInterruptList, KPRCB, ChainedInterruptList),
//OFFSET(PbSpinLockAcquireCount, KPRCB, SpinLockAcquireCount),
//OFFSET(PbSpinLockContentionCount, KPRCB, SpinLockContentionCount),
//OFFSET(PbSpinLockSpinCount, KPRCB, SpinLockSpinCount),
//OFFSET(PbContext, KPRCB, Context),
//OFFSET(PbIsrStack, KPRCB, IsrStack),
//OFFSET(PbVectorToInterruptObject, KPRCB, VectorToInterruptObject),
//OFFSET(PbEntropyBuffer, KPRCB, EntropyTimingState.Buffer),
//OFFSET(PbMailbox, KPRCB, Mailbox),
SIZE(ProcessorBlockLength, KPRCB),

HEADER("KPCR offsets"),
OFFSET(PcExceptionList, KIPCR, NtTib.ExceptionList),
//OFFSET(PcInitialStack, KIPCR, InitialStack),
//OFFSET(PcMxCsr, KIPCR, MxCsr),
OFFSET(PcTssCopy, KIPCR, TssCopy),
OFFSET(PcContextSwitches, KIPCR, ContextSwitches),
OFFSET(PcSetMemberCopy, KIPCR, SetMemberCopy),
OFFSET(PcTeb, KIPCR, NtTib.Self),
OFFSET(PcSelfPcr, KIPCR, SelfPcr),
OFFSET(PcPrcb, KIPCR, Prcb),
OFFSET(PcIrql, KIPCR, Irql),
OFFSET(PcIRR, KIPCR, IRR),
OFFSET(PcIrrActive, KIPCR, IrrActive),
OFFSET(PcIDR, KIPCR, IDR),
OFFSET(PcIdt, KIPCR, IDT),
OFFSET(PcGdt, KIPCR, GDT),
OFFSET(PcTss, KIPCR, TSS),
OFFSET(PcSetMember, KIPCR, SetMember),
OFFSET(PcStallScaleFactor, KIPCR, StallScaleFactor),
OFFSET(PcNumber, KIPCR, Number),
OFFSET(PcVdmAlert, KIPCR, VdmAlert),
OFFSET(PcHal, KIPCR, HalReserved),
OFFSET(PcPrcbData, KIPCR, PrcbData),
OFFSET(PcCurrentThread, KIPCR, PrcbData.CurrentThread),
//OFFSET(PcNestingLevel, KIPCR, PrcbData.NestingLevel),
OFFSET(PcParentNode, KIPCR, PrcbData.ParentNode),
OFFSET(PcInterruptCount, KIPCR, PrcbData.InterruptCount),
//OFFSET(PcDpcRequestSummary, KIPCR, PrcbData.DpcRequestSummary),
//OFFSET(PcStartCycles, KIPCR, PrcbData.StartCycles),
//OFFSET(PcCycleTime, KIPCR, PrcbData.CycleTime),
//OFFSET(PcHighCycleTime, KIPCR, PrcbData.HighCycleTime),
SIZE(ProcessorControlRegisterLength, KIPCR),

// Processor Start Block Offset Definitions
//HEADER("??? offsets"),
//OFFSET(PsbCompletionFlag, ???, PsbCompletionFlag),
//OFFSET(PsbFlags, ???, PsbCompletionFlag),
//OFFSET(PsbTiledMemoryMap, ???, PsbCompletionFlag),
//OFFSET(PsbSelfMap, ???, PsbCompletionFlag),
//OFFSET(PsbProcessorState, ???, PsbCompletionFlag),
//SIZE(ProcessorStartBlockLength, ???, PsbCompletionFlag),

HEADER("PEB offsets"),
OFFSET(PebBeingDebugged, PEB, BeingDebugged),
OFFSET(PebKernelCallbackTable, PEB, KernelCallbackTable),

HEADER("KPROCESSOR_STATE offsets"),
OFFSET(PsContextFrame, KPROCESSOR_STATE, ContextFrame),
OFFSET(PsSpecialRegisters, KPROCESSOR_STATE, SpecialRegisters),
SIZE(ProcessorStateLength, KPROCESSOR_STATE),

HEADER("KSPECIAL_REGISTERS offsets"),
OFFSET(SrCr0, KSPECIAL_REGISTERS, Cr0),
OFFSET(SrCr2, KSPECIAL_REGISTERS, Cr2),
OFFSET(SrCr3, KSPECIAL_REGISTERS, Cr3),
OFFSET(SrCr4, KSPECIAL_REGISTERS, Cr4),
OFFSET(SrKernelDr0, KSPECIAL_REGISTERS, KernelDr0),
OFFSET(SrKernelDr1, KSPECIAL_REGISTERS, KernelDr1),
OFFSET(SrKernelDr2, KSPECIAL_REGISTERS, KernelDr2),
OFFSET(SrKernelDr3, KSPECIAL_REGISTERS, KernelDr3),
OFFSET(SrKernelDr6, KSPECIAL_REGISTERS, KernelDr6),
OFFSET(SrKernelDr7, KSPECIAL_REGISTERS, KernelDr7),
OFFSET(SrGdtr, KSPECIAL_REGISTERS, Gdtr),
OFFSET(SrIdtr, KSPECIAL_REGISTERS, Idtr),
OFFSET(SrTr, KSPECIAL_REGISTERS, Tr),
OFFSET(SrLdtr, KSPECIAL_REGISTERS, Ldtr),
//OFFSET(SrXcr0, KSPECIAL_REGISTERS, Xcr0),
//OFFSET(SrExceptionList, KSPECIAL_REGISTERS, ExceptionList),

HEADER("KSYSTEM_TIME offsets"),
OFFSET(StLowTime, KSYSTEM_TIME, LowTime),
OFFSET(StHigh1Time, KSYSTEM_TIME, High1Time),
OFFSET(StHigh2Time, KSYSTEM_TIME, High2Time),

//HEADER("KSWITCH_FRAME offsets"),
//SIZE(SwitchFrameLength, KSWITCH_FRAME),

HEADER("TEB offsets (duplicates Te* definitions!)"),
OFFSET(TbExceptionList, TEB, NtTib.ExceptionList),
OFFSET(TbStackBase, TEB, NtTib.StackBase),
OFFSET(TbStackLimit, TEB, NtTib.StackLimit),
OFFSET(TbVersion, TEB, NtTib.Version),
OFFSET(TbFiberData, TEB, NtTib.FiberData),
OFFSET(TbArbitraryUserPointer, TEB, NtTib.ArbitraryUserPointer),
OFFSET(TbEnvironmentPointer, TEB, EnvironmentPointer),
OFFSET(TbClientId, TEB, ClientId),
OFFSET(TbThreadLocalStoragePointer, TEB, ThreadLocalStoragePointer),
OFFSET(TbCountOfOwnedCriticalSections, TEB, CountOfOwnedCriticalSections),
OFFSET(TbCsrClientThread, TEB, CsrClientThread),
OFFSET(TbWOW32Reserved, TEB, WOW32Reserved),
OFFSET(TbSystemReserved1, TEB, SystemReserved1),
OFFSET(TbExceptionCode, TEB, ExceptionCode),
OFFSET(TbGdiThreadLocalInfo, TEB, GdiThreadLocalInfo),
OFFSET(TbglDispatchTable, TEB, glDispatchTable),
OFFSET(TbglSectionInfo, TEB, glSectionInfo),
OFFSET(TbglSection, TEB, glSection),
OFFSET(TbglTable, TEB, glTable),
OFFSET(TbglCurrentRC, TEB, glCurrentRC),
OFFSET(TbglContext, TEB, glContext),
OFFSET(TbDeallocationStack, TEB, DeallocationStack),
OFFSET(TbVdm, TEB, Vdm),
OFFSET(TbGdiBatchCount, TEB, GdiBatchCount),
//OFFSET(TeSameTebFlags, TEB, SameTebFlags),
OFFSET(TebPeb, TEB, ProcessEnvironmentBlock),

HEADER("KTRAP_FRAME"),
OFFSET(TsDbgEbp, KTRAP_FRAME, DbgEbp),
OFFSET(TsDbgEip, KTRAP_FRAME, DbgEip),
OFFSET(TsDbgArgMark, KTRAP_FRAME, DbgArgMark),
OFFSET(TsTempSegCs, KTRAP_FRAME, TempSegCs),
//OFFSET(TsLogging, KTRAP_FRAME, Logging),
//OFFSET(TsFrameType, KTRAP_FRAME, FrameType),
OFFSET(TsTempEsp, KTRAP_FRAME, TempEsp),
OFFSET(TsDr0, KTRAP_FRAME, Dr0),
OFFSET(TsDr1, KTRAP_FRAME, Dr1),
OFFSET(TsDr2, KTRAP_FRAME, Dr2),
OFFSET(TsDr3, KTRAP_FRAME, Dr3),
OFFSET(TsDr6, KTRAP_FRAME, Dr6),
OFFSET(TsDr7, KTRAP_FRAME, Dr7),
OFFSET(TsSegGs, KTRAP_FRAME, SegGs),
OFFSET(TsSegEs, KTRAP_FRAME, SegEs),
OFFSET(TsSegDs, KTRAP_FRAME, SegDs),
OFFSET(TsEdx, KTRAP_FRAME, Edx),
OFFSET(TsEcx, KTRAP_FRAME, Ecx),
OFFSET(TsEax, KTRAP_FRAME, Eax),
OFFSET(TsPreviousPreviousMode, KTRAP_FRAME, PreviousPreviousMode),
//OFFSET(TsMxCsr, KTRAP_FRAME, MxCsr),
OFFSET(TsExceptionList, KTRAP_FRAME, ExceptionList),
//OFFSET(TsEntropyQueueDpc, KTRAP_FRAME, EntropyQueueDpc),
OFFSET(TsSegFs, KTRAP_FRAME, SegFs),
OFFSET(TsEdi, KTRAP_FRAME, Edi),
OFFSET(TsEsi, KTRAP_FRAME, Esi),
OFFSET(TsEbx, KTRAP_FRAME, Ebx),
OFFSET(TsEbp, KTRAP_FRAME, Ebp),
OFFSET(TsErrCode, KTRAP_FRAME, ErrCode),
OFFSET(TsEip, KTRAP_FRAME, Eip),
OFFSET(TsSegCs, KTRAP_FRAME, SegCs),
OFFSET(TsEflags, KTRAP_FRAME, EFlags),
OFFSET(TsHardwareEsp, KTRAP_FRAME, HardwareEsp),
OFFSET(TsHardwareSegSs, KTRAP_FRAME, HardwareSegSs),
OFFSET(TsDbgArgPointer, KTRAP_FRAME, DbgArgPointer), // not in win10
OFFSET(TsV86Es, KTRAP_FRAME, V86Es),
OFFSET(TsV86Ds, KTRAP_FRAME, V86Ds),
OFFSET(TsV86Fs, KTRAP_FRAME, V86Fs),
OFFSET(TsV86Gs, KTRAP_FRAME, V86Gs),
SIZE(KTRAP_FRAME_LENGTH, KTRAP_FRAME),
CONSTANT(KTRAP_FRAME_ALIGN),

HEADER("KTSS offsets"),
OFFSET(TssEsp0, KTSS, Esp0),
OFFSET(TssCR3, KTSS, CR3),
OFFSET(TssEip, KTSS, Eip),
OFFSET(TssEFlags, KTSS, EFlags),
OFFSET(TssEax, KTSS, Eax),
OFFSET(TssEbx, KTSS, Ebx),
OFFSET(TssEcx, KTSS, Ecx),
OFFSET(TssEdx, KTSS, Edx),
OFFSET(TssEsp, KTSS, Esp),
OFFSET(TssEbp, KTSS, Ebp),
OFFSET(TssEsi, KTSS, Esi),
OFFSET(TssEdi, KTSS, Edi),
OFFSET(TssEs, KTSS, Es),
OFFSET(TssCs, KTSS, Cs),
OFFSET(TssSs, KTSS, Ss),
OFFSET(TssDs, KTSS, Ds),
OFFSET(TssFs, KTSS, Fs),
OFFSET(TssGs, KTSS, Gs),
OFFSET(TssLDT, KTSS, LDT),
OFFSET(TssIoMapBase, KTSS, IoMapBase),
OFFSET(TssIoMaps, KTSS, IoMaps),
SIZE(TssLength, KTSS),

//HEADER("VDM_PROCESS_OBJECTS??? offsets"),
//VpVdmTib equ 00098H

HEADER("XSTATE_CONFIGURATION offsets"),
OFFSET(XcfgEnabledFeatures, XSTATE_CONFIGURATION, EnabledFeatures),
#if (NTDDI_VERSION >= NTDDI_WIN10)
OFFSET(XcfgEnabledVolatileFeatures, XSTATE_CONFIGURATION, EnabledFeatures),
#endif

HEADER("XSTATE_CONTEXT offsets"),
OFFSET(XctxMask, XSTATE_CONTEXT, Mask),
OFFSET(XctxLength, XSTATE_CONTEXT, Length),
OFFSET(XctxArea, XSTATE_CONTEXT, Area),

HEADER("XSAVE_AREA offsets"),
OFFSET(XsaHeader, XSAVE_AREA, Header),
SIZE(XsaHeaderLength, XSAVE_AREA_HEADER),
//CONSTANTX(XSAVE_ALIGN, _alignof(XSAVE_AREA)),

HEADER("Data access macros"),
RAW("#define USERDATA ds:[HEX(0FFDF0000)]"),
RAW("#define PCR fs:"),

#if (NTDDI_VERSION >= NTDDI_WIN8)
HEADER("KNODE offsets"),
OFFSET(NdIdleCpuSet, KNODE, IdleCpuSet),
#endif

//HEADER("ETW definitions for interrupt tracing"),
//SIZE(EtwTSLength, ???, TSLength),

//HEADER("WOW64 shared information block definitions"),
//OFFSET(PwWow64Info, ???, IdleCpuSet),
//OFFSET(WiCpuFlags, ???, IdleCpuSet),
//CONSTANT(WOW64_CPUFLAGS_SOFTWARE),


/// Unknown stuff:

CONSTANT(NPX_STATE_NOT_LOADED),
CONSTANT(NPX_STATE_LOADED),
//CONSTANT(NPX_MASK_LAZY),

// classicOS stuff here
HEADER("KPCR"),
OFFSET(KPCR_EXCEPTION_LIST, KPCR, NtTib.ExceptionList),
OFFSET(KPCR_PERF_GLOBAL_GROUP_MASK, KIPCR, PerfGlobalGroupMask),
OFFSET(KPCR_CONTEXT_SWITCHES, KPCR, ContextSwitches),
OFFSET(KPCR_TEB, KIPCR, Used_Self),
OFFSET(KPCR_SELF, KIPCR, SelfPcr),
OFFSET(KPCR_PRCB, KPCR, Prcb),
OFFSET(KPCR_IDT, KIPCR, IDT),
OFFSET(KPCR_GDT, KIPCR, GDT),
OFFSET(KPCR_TSS, KPCR, TSS),
OFFSET(KPCR_STALL_SCALE_FACTOR, KPCR, StallScaleFactor),
OFFSET(KPCR_PRCB_DATA, KIPCR, PrcbData),
OFFSET(KPCR_CURRENT_THREAD, KIPCR, PrcbData.CurrentThread),
OFFSET(KPCR_PRCB_NEXT_THREAD, KIPCR, PrcbData.NextThread),
OFFSET(KPCR_PRCB_DPC_QUEUE_DEPTH, KIPCR, PrcbData.DpcData[0].DpcQueueDepth),
OFFSET(KPCR_PRCB_DPC_STACK, KIPCR, PrcbData.DpcStack),
OFFSET(KPCR_PRCB_MAXIMUM_DPC_QUEUE_DEPTH, KIPCR, PrcbData.MaximumDpcQueueDepth),
OFFSET(KPCR_PRCB_DPC_ROUTINE_ACTIVE, KIPCR, PrcbData.DpcRoutineActive),
OFFSET(KPCR_PRCB_TIMER_REQUEST, KIPCR, PrcbData.TimerRequest),
OFFSET(KPCR_PRCB_QUANTUM_END, KIPCR, PrcbData.QuantumEnd),
OFFSET(KPCR_PRCB_DEFERRED_READY_LIST_HEAD, KIPCR, PrcbData.DeferredReadyListHead),
OFFSET(KPCR_PRCB_POWER_STATE_IDLE_FUNCTION, KIPCR, PrcbData.PowerState.IdleFunction),

HEADER("KTRAP_FRAME"),
OFFSET(KTRAP_FRAME_DEBUGEBP, KTRAP_FRAME, DbgEbp),
OFFSET(KTRAP_FRAME_DEBUGEIP, KTRAP_FRAME, DbgEip),
OFFSET(KTRAP_FRAME_TEMPESP, KTRAP_FRAME, TempEsp),
OFFSET(KTRAP_FRAME_DR0, KTRAP_FRAME, Dr0),
OFFSET(KTRAP_FRAME_DR1, KTRAP_FRAME, Dr1),
OFFSET(KTRAP_FRAME_DR2, KTRAP_FRAME, Dr2),
OFFSET(KTRAP_FRAME_DR3, KTRAP_FRAME, Dr3),
OFFSET(KTRAP_FRAME_DR6, KTRAP_FRAME, Dr6),
OFFSET(KTRAP_FRAME_DR7, KTRAP_FRAME, Dr7),
OFFSET(KTRAP_FRAME_GS, KTRAP_FRAME, SegGs),
OFFSET(KTRAP_FRAME_ES, KTRAP_FRAME, SegEs),
OFFSET(KTRAP_FRAME_DS, KTRAP_FRAME, SegDs),
OFFSET(KTRAP_FRAME_EDX, KTRAP_FRAME, Edx),
OFFSET(KTRAP_FRAME_ECX, KTRAP_FRAME, Ecx),
OFFSET(KTRAP_FRAME_EAX, KTRAP_FRAME, Eax),
OFFSET(KTRAP_FRAME_PREVIOUS_MODE, KTRAP_FRAME, PreviousPreviousMode),
OFFSET(KTRAP_FRAME_EXCEPTION_LIST, KTRAP_FRAME, ExceptionList),
OFFSET(KTRAP_FRAME_FS, KTRAP_FRAME, SegFs),
OFFSET(KTRAP_FRAME_EDI, KTRAP_FRAME, Edi),
OFFSET(KTRAP_FRAME_ESI, KTRAP_FRAME, Esi),
OFFSET(KTRAP_FRAME_EBX, KTRAP_FRAME, Ebx),
OFFSET(KTRAP_FRAME_EBP, KTRAP_FRAME, Ebp),
OFFSET(KTRAP_FRAME_ERROR_CODE, KTRAP_FRAME, ErrCode),
OFFSET(KTRAP_FRAME_EIP, KTRAP_FRAME, Eip),
OFFSET(KTRAP_FRAME_CS, KTRAP_FRAME, SegCs),
OFFSET(KTRAP_FRAME_EFLAGS, KTRAP_FRAME, EFlags),
OFFSET(KTRAP_FRAME_ESP, KTRAP_FRAME, HardwareEsp),
OFFSET(KTRAP_FRAME_SS, KTRAP_FRAME, HardwareSegSs),
OFFSET(KTRAP_FRAME_V86_ES, KTRAP_FRAME, V86Es),
OFFSET(KTRAP_FRAME_V86_DS, KTRAP_FRAME, V86Ds),
OFFSET(KTRAP_FRAME_V86_FS, KTRAP_FRAME, V86Fs),
OFFSET(KTRAP_FRAME_V86_GS, KTRAP_FRAME, V86Gs),
SIZE(KTRAP_FRAME_SIZE, KTRAP_FRAME),

HEADER("CONTEXT"),
OFFSET(CONTEXT_FLAGS, CONTEXT, ContextFlags),
OFFSET(CONTEXT_SEGGS, CONTEXT, SegGs),
OFFSET(CONTEXT_SEGFS, CONTEXT, SegFs),
OFFSET(CONTEXT_SEGES, CONTEXT, SegEs),
OFFSET(CONTEXT_SEGDS, CONTEXT, SegDs),
OFFSET(CONTEXT_EDI, CONTEXT, Edi),
OFFSET(CONTEXT_ESI, CONTEXT, Esi),
OFFSET(CONTEXT_EBX, CONTEXT, Ebx),
OFFSET(CONTEXT_EDX, CONTEXT, Edx),
OFFSET(CONTEXT_ECX, CONTEXT, Ecx),
OFFSET(CONTEXT_EAX, CONTEXT, Eax),
OFFSET(CONTEXT_EBP, CONTEXT, Ebp),
OFFSET(CONTEXT_EIP, CONTEXT, Eip),
OFFSET(CONTEXT_SEGCS, CONTEXT, SegCs),
OFFSET(CONTEXT_EFLAGS, CONTEXT, EFlags),
OFFSET(CONTEXT_ESP, CONTEXT, Esp),
OFFSET(CONTEXT_SEGSS, CONTEXT, SegSs),
SIZE(CONTEXT_FRAME_LENGTH, CONTEXT),

HEADER("FIBER"),
OFFSET(FIBER_PARAMETER, FIBER, FiberData),
OFFSET(FIBER_EXCEPTION_LIST, FIBER, ExceptionList),
OFFSET(FIBER_STACK_BASE, FIBER, StackBase),
OFFSET(FIBER_STACK_LIMIT, FIBER, StackLimit),
OFFSET(FIBER_DEALLOCATION_STACK, FIBER, DeallocationStack),
OFFSET(FIBER_CONTEXT, FIBER, FiberContext),
OFFSET(FIBER_CONTEXT_FLAGS, FIBER, FiberContext.ContextFlags),
OFFSET(FIBER_CONTEXT_EAX, FIBER, FiberContext.Eax),
OFFSET(FIBER_CONTEXT_EBX, FIBER, FiberContext.Ebx),
OFFSET(FIBER_CONTEXT_ECX, FIBER, FiberContext.Ecx),
OFFSET(FIBER_CONTEXT_EDX, FIBER, FiberContext.Edx),
OFFSET(FIBER_CONTEXT_ESI, FIBER, FiberContext.Esi),
OFFSET(FIBER_CONTEXT_EDI, FIBER, FiberContext.Edi),
OFFSET(FIBER_CONTEXT_EBP, FIBER, FiberContext.Ebp),
OFFSET(FIBER_CONTEXT_EIP, FIBER, FiberContext.Eip),
OFFSET(FIBER_CONTEXT_ESP, FIBER, FiberContext.Esp),
OFFSET(FIBER_CONTEXT_DR6, FIBER, FiberContext.Dr6),
OFFSET(FIBER_CONTEXT_FLOAT_SAVE_CONTROL_WORD, FIBER, FiberContext.FloatSave.ControlWord),
OFFSET(FIBER_CONTEXT_FLOAT_SAVE_STATUS_WORD, FIBER, FiberContext.FloatSave.StatusWord),
OFFSET(FIBER_CONTEXT_FLOAT_SAVE_TAG_WORD, FIBER, FiberContext.FloatSave.TagWord),
OFFSET(FIBER_GUARANTEED_STACK_BYTES, FIBER, GuaranteedStackBytes),
OFFSET(FIBER_FLS_DATA, FIBER, FlsData),
OFFSET(FIBER_ACTIVATION_CONTEXT_STACK, FIBER, ActivationContextStackPointer),

HEADER("KTSS"),
OFFSET(KTSS_IOMAPBASE, KTSS, IoMapBase),
OFFSET(KTSS_ESP0, KTSS, Esp0),

HEADER("EXCEPTION_RECORD"),
OFFSET(EXCEPTION_RECORD_EXCEPTION_CODE, EXCEPTION_RECORD, ExceptionCode),
OFFSET(EXCEPTION_RECORD_EXCEPTION_FLAGS, EXCEPTION_RECORD, ExceptionFlags),
OFFSET(EXCEPTION_RECORD_EXCEPTION_RECORD, EXCEPTION_RECORD, ExceptionRecord),
OFFSET(EXCEPTION_RECORD_EXCEPTION_ADDRESS, EXCEPTION_RECORD, ExceptionAddress),
OFFSET(EXCEPTION_RECORD_NUMBER_PARAMETERS, EXCEPTION_RECORD, NumberParameters),
OFFSET(EXCEPTION_RECORD_EXCEPTION_ADDRESS, EXCEPTION_RECORD, ExceptionAddress),
SIZE(SIZEOF_EXCEPTION_RECORD, EXCEPTION_RECORD),
CONSTANT(EXCEPTION_RECORD_LENGTH),

HEADER("EXCEPTION_POINTERS"),
OFFSET(EXCEPTION_POINTERS_EXCEPTION_RECORD, EXCEPTION_POINTERS, ExceptionRecord),
OFFSET(EXCEPTION_POINTERS_CONTEXT_RECORD, EXCEPTION_POINTERS, ContextRecord),
SIZE(SIZEOF_EXCEPTION_POINTERS, EXCEPTION_POINTERS),

HEADER("KTHREAD"),
OFFSET(KTHREAD_DEBUG_ACTIVE, KTHREAD, Header.DebugActive),
OFFSET(KTHREAD_INITIAL_STACK, KTHREAD, InitialStack),
OFFSET(KTHREAD_STACK_LIMIT, KTHREAD, StackLimit),
OFFSET(KTHREAD_TEB, KTHREAD, Teb),
OFFSET(KTHREAD_KERNEL_STACK, KTHREAD, KernelStack),
OFFSET(KTHREAD_APCSTATE_PROCESS, KTHREAD, ApcState.Process),
OFFSET(KTHREAD_PENDING_KERNEL_APC, KTHREAD, ApcState.KernelApcPending),
OFFSET(KTHREAD_CONTEXT_SWITCHES, KTHREAD, ContextSwitches),
OFFSET(KTHREAD_STATE_, KTHREAD, State),
OFFSET(KTHREAD_NPX_STATE, KTHREAD, NpxState),
OFFSET(KTHREAD_WAIT_IRQL, KTHREAD, WaitIrql),
OFFSET(KTHREAD_WAIT_REASON, KTHREAD, WaitReason),
OFFSET(KTHREAD_COMBINED_APC_DISABLE, KTHREAD, CombinedApcDisable),
OFFSET(KTHREAD_SPECIAL_APC_DISABLE, KTHREAD, SpecialApcDisable),
OFFSET(KTHREAD_LARGE_STACK, KTHREAD, LargeStack),
OFFSET(KTHREAD_TRAP_FRAME, KTHREAD, TrapFrame),
OFFSET(KTHREAD_CALLBACK_STACK, KTHREAD, CallbackStack),
OFFSET(KTHREAD_APC_STATE_INDEX, KTHREAD, ApcStateIndex),
OFFSET(KTHREAD_STACK_BASE, KTHREAD, StackBase),

HEADER("KPROCESS"),
OFFSET(KPROCESS_DIRECTORY_TABLE_BASE, KPROCESS, DirectoryTableBase),
OFFSET(KPROCESS_LDT_DESCRIPTOR0, KPROCESS, LdtDescriptor),
OFFSET(KPROCESS_LDT_DESCRIPTOR1, KPROCESS, LdtDescriptor.HighWord),
OFFSET(KPROCESS_INT21_DESCRIPTOR0, KPROCESS, Int21Descriptor),
OFFSET(KPROCESS_INT21_DESCRIPTOR1, KPROCESS, Int21Descriptor.Access),
OFFSET(KPROCESS_IOPM_OFFSET, KPROCESS, IopmOffset),

HEADER("TEB"),
OFFSET(TEB_EXCEPTION_LIST, TEB, NtTib.ExceptionList),
OFFSET(TEB_STACK_BASE, TEB, NtTib.StackBase),
OFFSET(TEB_STACK_LIMIT, TEB, NtTib.StackLimit),
OFFSET(TEB_FIBER_DATA, TEB, NtTib.FiberData),
OFFSET(TEB_SELF, TEB, NtTib.Self),
OFFSET(TEB_PEB, TEB, ProcessEnvironmentBlock),
OFFSET(TEB_EXCEPTION_CODE, TEB, ExceptionCode),
OFFSET(TEB_ACTIVATION_CONTEXT_STACK_POINTER, TEB, ActivationContextStackPointer),
OFFSET(TEB_GL_TABLE, TEB, glTable),
OFFSET(TEB_DEALLOCATION_STACK, TEB, DeallocationStack),
OFFSET(TEB_GDI_BATCH_COUNT, TEB, GdiBatchCount),
OFFSET(TEB_GUARANTEED_STACK_BYTES, TEB, GuaranteedStackBytes),
OFFSET(TEB_FLS_DATA, TEB, FlsData),

HEADER("PEB"),
OFFSET(PEB_KERNEL_CALLBACK_TABLE, PEB, KernelCallbackTable),

HEADER("Misc"),
CONSTANT(NPX_FRAME_LENGTH),
CONSTANT(FN_CR0_NPX_STATE),
CONSTANT(FP_CONTROL_WORD),
CONSTANT(FP_STATUS_WORD),
CONSTANT(FP_TAG_WORD),
CONSTANT(FP_DATA_SELECTOR),
CONSTANT(CBSTACK_RESULT),
CONSTANT(CBSTACK_RESULT_LENGTH),
CONSTANT(CBSTACK_TRAP_FRAME),
CONSTANT(CBSTACK_CALLBACK_STACK),
SIZE(SIZEOF_FX_SAVE_AREA, FX_SAVE_AREA),
CONSTANT(KUSER_SHARED_SYSCALL),
CONSTANT(EXCEPTION_EXECUTE_HANDLER),
CONSTANT(STATUS_CALLBACK_POP_STACK),
CONSTANT(CONTEXT_ALIGNED_SIZE),
CONSTANT(PROCESSOR_FEATURE_FXSR),
CONSTANT(KUSER_SHARED_SYSCALL_RET),
CONSTANT(USER_SHARED_DATA),
CONSTANT(USER_SHARED_DATA_PROCESSOR_FEATURES),

