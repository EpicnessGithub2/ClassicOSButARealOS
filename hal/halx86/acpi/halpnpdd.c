/*
 * PROJECT:         classicOS HAL
 * LICENSE:         BSD - See COPYING.ARM in the top level directory
 * FILE:            hal/halx86/acpi/halpnpdd.c
 * PURPOSE:         HAL Plug and Play Device Driver
 * PROGRAMMERS:     classicOS Portable Systems Group
 */

/* INCLUDES *******************************************************************/

#include <hal.h>

#include <initguid.h>
#include <wdmguid.h>

#define NDEBUG
#include <debug.h>

typedef enum _EXTENSION_TYPE
{
    PdoExtensionType = 0xC0,
    FdoExtensionType
} EXTENSION_TYPE;

typedef enum _PDO_TYPE
{
    AcpiPdo = 0x80,
    WdPdo
} PDO_TYPE;

typedef struct _FDO_EXTENSION
{
    EXTENSION_TYPE ExtensionType;
    struct _PDO_EXTENSION* ChildPdoList;
    PDEVICE_OBJECT PhysicalDeviceObject;
    PDEVICE_OBJECT FunctionalDeviceObject;
    PDEVICE_OBJECT AttachedDeviceObject;
} FDO_EXTENSION, *PFDO_EXTENSION;

typedef struct _PDO_EXTENSION
{
    EXTENSION_TYPE ExtensionType;
    struct _PDO_EXTENSION* Next;
    PDEVICE_OBJECT PhysicalDeviceObject;
    PFDO_EXTENSION ParentFdoExtension;
    PDO_TYPE PdoType;
    PDESCRIPTION_HEADER WdTable;
    LONG InterfaceReferenceCount;
} PDO_EXTENSION, *PPDO_EXTENSION;

/* GLOBALS ********************************************************************/

PDRIVER_OBJECT HalpDriverObject;

/* PRIVATE FUNCTIONS **********************************************************/

NTSTATUS
NTAPI
HalpAddDevice(IN PDRIVER_OBJECT DriverObject,
              IN PDEVICE_OBJECT TargetDevice)
{
    NTSTATUS Status;
    PFDO_EXTENSION FdoExtension;
    PPDO_EXTENSION PdoExtension;
    PDEVICE_OBJECT DeviceObject, AttachedDevice;
    PDEVICE_OBJECT PdoDeviceObject;
    PDESCRIPTION_HEADER Wdrt;

    DPRINT("HAL: PnP Driver ADD!\n");

    /* Create the FDO */
    Status = IoCreateDevice(DriverObject,
                            sizeof(FDO_EXTENSION),
                            NULL,
                            FILE_DEVICE_BUS_EXTENDER,
                            0,
                            FALSE,
                            &DeviceObject);
    if (!NT_SUCCESS(Status))
    {
        /* Should not happen */
        DbgBreakPoint();
        return Status;
    }

    /* Setup the FDO extension */
    FdoExtension = DeviceObject->DeviceExtension;
    FdoExtension->ExtensionType = FdoExtensionType;
    FdoExtension->PhysicalDeviceObject = TargetDevice;
    FdoExtension->FunctionalDeviceObject = DeviceObject;
    FdoExtension->ChildPdoList = NULL;

    /* FDO is done initializing */
    DeviceObject->Flags &= ~DO_DEVICE_INITIALIZING;

    /* Attach to the physical device object (the bus) */
    AttachedDevice = IoAttachDeviceToDeviceStack(DeviceObject, TargetDevice);
    if (!AttachedDevice)
    {
        /* Failed, undo everything */
        IoDeleteDevice(DeviceObject);
        return STATUS_NO_SUCH_DEVICE;
    }

    /* Save the attachment */
    FdoExtension->AttachedDeviceObject = AttachedDevice;

    /* Create the PDO */
    Status = IoCreateDevice(DriverObject,
                            sizeof(PDO_EXTENSION),
                            NULL,
                            FILE_DEVICE_BUS_EXTENDER,
                            FILE_AUTOGENERATED_DEVICE_NAME,
                            FALSE,
                            &PdoDeviceObject);
    if (!NT_SUCCESS(Status))
    {
        /* Fail */
        DPRINT1("HAL: Could not create ACPI device object status=0x%08x\n", Status);
        return Status;
    }

    /* Setup the PDO device extension */
    PdoExtension = PdoDeviceObject->DeviceExtension;
    PdoExtension->ExtensionType = PdoExtensionType;
    PdoExtension->PhysicalDeviceObject = PdoDeviceObject;
    PdoExtension->ParentFdoExtension = FdoExtension;
    PdoExtension->PdoType = AcpiPdo;

    /* Add the PDO to the head of the list */
    PdoExtension->Next = FdoExtension->ChildPdoList;
    FdoExtension->ChildPdoList = PdoExtension;

    /* Initialization is finished */
    PdoDeviceObject->Flags &= ~DO_DEVICE_INITIALIZING;

    /* Find the ACPI watchdog table */
    Wdrt = HalAcpiGetTable(0, 'TRDW');
    if (Wdrt)
    {
        /* FIXME: TODO */
        DPRINT1("You have an ACPI Watchdog. That's great! You should be proud ;-)\n");
    }

    /* Return status */
    DPRINT("Device added %lx\n", Status);
    return Status;
}

NTSTATUS
NTAPI
HalpQueryInterface(IN PDEVICE_OBJECT DeviceObject,
                   IN CONST GUID* InterfaceType,
                   IN USHORT Version,
                   IN PVOID InterfaceSpecificData,
                   IN ULONG InterfaceBufferSize,
                   IN PINTERFACE Interface,
                   OUT PULONG Length)
{
    if (IsEqualIID(InterfaceType, &GUID_ACPI_REGS_INTERFACE_STANDARD))
    {
        DPRINT1("HalpQueryInterface(GUID_ACPI_REGS_INTERFACE_STANDARD) is UNIMPLEMENTED\n");
    }
    else if (IsEqualIID(InterfaceType, &GUID_ACPI_PORT_RANGES_INTERFACE_STANDARD))
    {
        DPRINT1("HalpQueryInterface(GUID_ACPI_PORT_RANGES_INTERFACE_STANDARD) is UNIMPLEMENTED\n");
    }
    else
    {
        DPRINT1("HalpQueryInterface({%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}) is UNIMPLEMENTED\n",
                InterfaceType->Data1, InterfaceType->Data2, InterfaceType->Data3,
                InterfaceType->Data4[0], InterfaceType->Data4[1],
                InterfaceType->Data4[2], InterfaceType->Data4[3],
                InterfaceType->Data4[4], InterfaceType->Data4[5],
                InterfaceType->Data4[6], InterfaceType->Data4[7]);
    }
    return STATUS_NOT_SUPPORTED;
}

NTSTATUS
NTAPI
HalpQueryDeviceRelations(IN PDEVICE_OBJECT DeviceObject,
                         IN DEVICE_RELATION_TYPE RelationType,
                         OUT PDEVICE_RELATIONS* DeviceRelations)
{
    EXTENSION_TYPE ExtensionType;
    PPDO_EXTENSION PdoExtension;
    PFDO_EXTENSION FdoExtension;
    PDEVICE_RELATIONS PdoRelations, FdoRelations;
    PDEVICE_OBJECT* ObjectEntry;
    ULONG i = 0, PdoCount = 0;

    /* Get FDO device extension and PDO count */
    FdoExtension = DeviceObject->DeviceExtension;
    ExtensionType = FdoExtension->ExtensionType;

    /* What do they want? */
    if (RelationType == BusRelations)
    {
        /* This better be an FDO */
        if (ExtensionType == FdoExtensionType)
        {
            /* Count how many PDOs we have */
            PdoExtension = FdoExtension->ChildPdoList;
            while (PdoExtension)
            {
                /* Next one */
                PdoExtension = PdoExtension->Next;
                PdoCount++;
            }

            /* Add the PDOs that already exist in the device relations */
            if (*DeviceRelations)
            {
                PdoCount += (*DeviceRelations)->Count;
            }

            /* Allocate our structure */
            FdoRelations = ExAllocatePoolWithTag(PagedPool,
                                                 FIELD_OFFSET(DEVICE_RELATIONS,
                                                              Objects) +
                                                 sizeof(PDEVICE_OBJECT) * PdoCount,
                                                 TAG_HAL);
            if (!FdoRelations) return STATUS_INSUFFICIENT_RESOURCES;

            /* Save our count */
            FdoRelations->Count = PdoCount;

            /* Query existing relations */
            ObjectEntry = FdoRelations->Objects;
            if (*DeviceRelations)
            {
                /* Check if there were any */
                if ((*DeviceRelations)->Count)
                {
                    /* Loop them all */
                    do
                    {
                        /* Copy into our structure */
                        *ObjectEntry++ = (*DeviceRelations)->Objects[i];
                    }
                    while (++i < (*DeviceRelations)->Count);
                }

                /* Free existing structure */
                ExFreePool(*DeviceRelations);
            }

            /* Now check if we have a PDO list */
            PdoExtension = FdoExtension->ChildPdoList;
            if (PdoExtension)
            {
                /* Loop the PDOs */
                do
                {
                    /* Save our own PDO and reference it */
                    *ObjectEntry++ = PdoExtension->PhysicalDeviceObject;
                    ObReferenceObject(PdoExtension->PhysicalDeviceObject);

                    /* Go to our next PDO */
                    PdoExtension = PdoExtension->Next;
                }
                while (PdoExtension);
            }

            /* Return the new structure */
            *DeviceRelations = FdoRelations;
            return STATUS_SUCCESS;
        }
    }
    else
    {
        /* The only other thing we support is a target relation for the PDO */
        if ((RelationType == TargetDeviceRelation) &&
            (ExtensionType == PdoExtensionType))
        {
            /* Only one entry */
            PdoRelations = ExAllocatePoolWithTag(PagedPool,
                                                 sizeof(DEVICE_RELATIONS),
                                                 TAG_HAL);
            if (!PdoRelations) return STATUS_INSUFFICIENT_RESOURCES;

            /* Fill it out and reference us */
            PdoRelations->Count = 1;
            PdoRelations->Objects[0] = DeviceObject;
            ObReferenceObject(DeviceObject);

            /* Return it */
            *DeviceRelations = PdoRelations;
            return STATUS_SUCCESS;
        }
    }

    /* We don't support anything else */
    return STATUS_NOT_SUPPORTED;
}

NTSTATUS
NTAPI
HalpQueryCapabilities(IN PDEVICE_OBJECT DeviceObject,
                      OUT PDEVICE_CAPABILITIES Capabilities)
{
    //PPDO_EXTENSION PdoExtension;
    NTSTATUS Status;
    PAGED_CODE();

    /* Get the extension and check for valid version */
    //PdoExtension = DeviceObject->DeviceExtension;
    ASSERT(Capabilities->Version == 1);
    if (Capabilities->Version == 1)
    {
        /* Can't lock or eject us */
        Capabilities->LockSupported = FALSE;
        Capabilities->EjectSupported = FALSE;

        /* Can't remove or dock us */
        Capabilities->Removable = FALSE;
        Capabilities->DockDevice = FALSE;

        /* Can't access us raw */
        Capabilities->RawDeviceOK = FALSE;

        /* We have a unique ID, and don't bother the user */
        Capabilities->UniqueID = TRUE;
        Capabilities->SilentInstall = TRUE;

        /* Fill out the adress */
        Capabilities->Address = InterfaceTypeUndefined;
        Capabilities->UINumber = InterfaceTypeUndefined;

        /* Fill out latencies */
        Capabilities->D1Latency = 0;
        Capabilities->D2Latency = 0;
        Capabilities->D3Latency = 0;

        /* Fill out supported device states */
        Capabilities->DeviceState[PowerSystemWorking] = PowerDeviceD0;
        Capabilities->DeviceState[PowerSystemHibernate] = PowerDeviceD3;
        Capabilities->DeviceState[PowerSystemShutdown] = PowerDeviceD3;
        Capabilities->DeviceState[PowerSystemSleeping3] = PowerDeviceD3;

        /* Done */
        Status = STATUS_SUCCESS;
    }
    else
    {
        /* Fail */
        Status = STATUS_NOT_SUPPORTED;
    }

    /* Return status */
    return Status;
}

NTSTATUS
NTAPI
HalpQueryResources(IN PDEVICE_OBJECT DeviceObject,
                   OUT PCM_RESOURCE_LIST *Resources)
{
    PPDO_EXTENSION DeviceExtension = DeviceObject->DeviceExtension;
    NTSTATUS Status;
    PCM_RESOURCE_LIST ResourceList;
    PIO_RESOURCE_REQUIREMENTS_LIST RequirementsList;
    PIO_RESOURCE_DESCRIPTOR Descriptor;
    PCM_PARTIAL_RESOURCE_DESCRIPTOR PartialDesc;
    ULONG i;
    PAGED_CODE();

    /* Only the ACPI PDO has requirements */
    if (DeviceExtension->PdoType == AcpiPdo)
    {
        /* Query ACPI requirements */
        Status = HalpQueryAcpiResourceRequirements(&RequirementsList);
        if (!NT_SUCCESS(Status)) return Status;

        ASSERT(RequirementsList->AlternativeLists == 1);

        /* Allocate the resourcel ist */
        ResourceList = ExAllocatePoolWithTag(PagedPool,
                                             sizeof(CM_RESOURCE_LIST),
                                             TAG_HAL);
        if (!ResourceList )
        {
            /* Fail, no memory */
            Status = STATUS_INSUFFICIENT_RESOURCES;
            ExFreePoolWithTag(RequirementsList, TAG_HAL);
            return Status;
        }

        /* Initialize it */
        RtlZeroMemory(ResourceList, sizeof(CM_RESOURCE_LIST));
        ResourceList->Count = 1;

        /* Setup the list fields */
        ResourceList->List[0].BusNumber = -1;
        ResourceList->List[0].InterfaceType = PNPBus;
        ResourceList->List[0].PartialResourceList.Version = 1;
        ResourceList->List[0].PartialResourceList.Revision = 1;
        ResourceList->List[0].PartialResourceList.Count = 0;

        /* Setup the first descriptor */
        PartialDesc = ResourceList->List[0].PartialResourceList.PartialDescriptors;

        /* Find the requirement descriptor for the SCI */
        for (i = 0; i < RequirementsList->List[0].Count; i++)
        {
            /* Get this descriptor */
            Descriptor = &RequirementsList->List[0].Descriptors[i];
            if (Descriptor->Type == CmResourceTypeInterrupt)
            {
                /* Copy requirements descriptor into resource descriptor */
                PartialDesc->Type = CmResourceTypeInterrupt;
                PartialDesc->ShareDisposition = Descriptor->ShareDisposition;
                PartialDesc->Flags = Descriptor->Flags;
                ASSERT(Descriptor->u.Interrupt.MinimumVector ==
                       Descriptor->u.Interrupt.MaximumVector);
                PartialDesc->u.Interrupt.Vector = Descriptor->u.Interrupt.MinimumVector;
                PartialDesc->u.Interrupt.Level = Descriptor->u.Interrupt.MinimumVector;
                PartialDesc->u.Interrupt.Affinity = 0xFFFFFFFF;

                ResourceList->List[0].PartialResourceList.Count++;

                break;
            }
        }

        /* Return resources and success */
        *Resources = ResourceList;

        ExFreePoolWithTag(RequirementsList, TAG_HAL);

        return STATUS_SUCCESS;
    }
    else if (DeviceExtension->PdoType == WdPdo)
    {
        /* Watchdog doesn't */
        return STATUS_NOT_SUPPORTED;
    }
    else
    {
        /* This shouldn't happen */
        return STATUS_UNSUCCESSFUL;
    }
}

NTSTATUS
NTAPI
HalpQueryResourceRequirements(IN PDEVICE_OBJECT DeviceObject,
                              OUT PIO_RESOURCE_REQUIREMENTS_LIST *Requirements)
{
    PPDO_EXTENSION DeviceExtension = DeviceObject->DeviceExtension;
    PAGED_CODE();

    /* Only the ACPI PDO has requirements */
    if (DeviceExtension->PdoType == AcpiPdo)
    {
        /* Query ACPI requirements */
        return HalpQueryAcpiResourceRequirements(Requirements);
    }
    else if (DeviceExtension->PdoType == WdPdo)
    {
        /* Watchdog doesn't */
        return STATUS_NOT_SUPPORTED;
    }
    else
    {
        /* This shouldn't happen */
        return STATUS_UNSUCCESSFUL;
    }
}

NTSTATUS
NTAPI
HalpQueryIdPdo(IN PDEVICE_OBJECT DeviceObject,
               IN BUS_QUERY_ID_TYPE IdType,
               OUT PUSHORT *BusQueryId)
{
    PPDO_EXTENSION PdoExtension;
    PDO_TYPE PdoType;
    PWCHAR CurrentId;
    WCHAR Id[100];
    NTSTATUS Status;
    SIZE_T Length = 0;
    PWCHAR Buffer;

    /* Get the PDO type */
    PdoExtension = DeviceObject->DeviceExtension;
    PdoType = PdoExtension->PdoType;

    /* What kind of ID is being requested? */
    DPRINT("ID: %d\n", IdType);
    switch (IdType)
    {
        case BusQueryDeviceID:
        case BusQueryHardwareIDs:

            /* What kind of PDO is this? */
            if (PdoType == AcpiPdo)
            {
                /* ACPI ID */
                CurrentId = L"ACPI_HAL\\PNP0C08";
                RtlCopyMemory(Id, CurrentId, (wcslen(CurrentId) * sizeof(WCHAR)) + sizeof(UNICODE_NULL));
                Length += (wcslen(CurrentId) * sizeof(WCHAR)) + sizeof(UNICODE_NULL);

                CurrentId = L"*PNP0C08";
                RtlCopyMemory(&Id[wcslen(Id) + 1], CurrentId, (wcslen(CurrentId) * sizeof(WCHAR)) + sizeof(UNICODE_NULL));
                Length += (wcslen(CurrentId) * sizeof(WCHAR)) + sizeof(UNICODE_NULL);
            }
            else if (PdoType == WdPdo)
            {
                /* WatchDog ID */
                CurrentId = L"ACPI_HAL\\PNP0C18";
                RtlCopyMemory(Id, CurrentId, (wcslen(CurrentId) * sizeof(WCHAR)) + sizeof(UNICODE_NULL));
                Length += (wcslen(CurrentId) * sizeof(WCHAR)) + sizeof(UNICODE_NULL);

                CurrentId = L"*PNP0C18";
                RtlCopyMemory(&Id[wcslen(Id) + 1], CurrentId, (wcslen(CurrentId) * sizeof(WCHAR)) + sizeof(UNICODE_NULL));
                Length += (wcslen(CurrentId) * sizeof(WCHAR)) + sizeof(UNICODE_NULL);
            }
            else
            {
                /* Unknown */
                return STATUS_NOT_SUPPORTED;
            }
            break;

        case BusQueryInstanceID:

            /* Instance ID */
            CurrentId = L"0";
            RtlCopyMemory(Id, CurrentId, (wcslen(CurrentId) * sizeof(WCHAR)) + sizeof(UNICODE_NULL));
            Length += (wcslen(CurrentId) * sizeof(WCHAR)) + sizeof(UNICODE_NULL);
            break;

        case BusQueryCompatibleIDs:
        default:

            /* We don't support anything else */
            return STATUS_NOT_SUPPORTED;
    }


    /* Allocate the buffer */
    Buffer = ExAllocatePoolWithTag(PagedPool,
                                   Length + sizeof(UNICODE_NULL),
                                   TAG_HAL);
    if (Buffer)
    {
        /* Copy the string and null-terminate it */
        RtlCopyMemory(Buffer, Id, Length);
        Buffer[Length / sizeof(WCHAR)] = UNICODE_NULL;

        /* Return string */
        *BusQueryId = Buffer;
        Status = STATUS_SUCCESS;
        DPRINT("Returning: %S\n", *BusQueryId);
    }
    else
    {
        /* Fail */
        Status = STATUS_INSUFFICIENT_RESOURCES;
    }

    /* Return status */
    return Status;
}

NTSTATUS
NTAPI
HalpQueryIdFdo(IN PDEVICE_OBJECT DeviceObject,
               IN BUS_QUERY_ID_TYPE IdType,
               OUT PUSHORT *BusQueryId)
{
    NTSTATUS Status;
    SIZE_T Length;
    PWCHAR Id;
    PWCHAR Buffer;

    /* What kind of ID is being requested? */
    DPRINT("ID: %d\n", IdType);
    switch (IdType)
    {
        case BusQueryDeviceID:
        case BusQueryHardwareIDs:

            /* This is our hardware ID */
            Id = HalHardwareIdString;
            break;

        case BusQueryInstanceID:

            /* And our instance ID */
            Id = L"0";
            break;

        default:

            /* We don't support anything else */
            return STATUS_NOT_SUPPORTED;
    }

    /* Calculate the length */
    Length = (wcslen(Id) * sizeof(WCHAR)) + sizeof(UNICODE_NULL);

    /* Allocate the buffer */
    Buffer = ExAllocatePoolWithTag(PagedPool,
                                   Length + sizeof(UNICODE_NULL),
                                   TAG_HAL);
    if (Buffer)
    {
        /* Copy the string and null-terminate it */
        RtlCopyMemory(Buffer, Id, Length);
        Buffer[Length / sizeof(WCHAR)] = UNICODE_NULL;

        /* Return string */
        *BusQueryId = Buffer;
        Status = STATUS_SUCCESS;
        DPRINT("Returning: %S\n", *BusQueryId);
    }
    else
    {
        /* Fail */
        Status = STATUS_INSUFFICIENT_RESOURCES;
    }

    /* Return status */
    return Status;
}

NTSTATUS
NTAPI
HalpDispatchPnp(IN PDEVICE_OBJECT DeviceObject,
                IN PIRP Irp)
{
    PIO_STACK_LOCATION IoStackLocation;
    //PPDO_EXTENSION PdoExtension;
    PFDO_EXTENSION FdoExtension;
    NTSTATUS Status;
    UCHAR Minor;

    /* Get the device extension and stack location */
    FdoExtension = DeviceObject->DeviceExtension;
    IoStackLocation = IoGetCurrentIrpStackLocation(Irp);
    Minor = IoStackLocation->MinorFunction;

    /* FDO? */
    if (FdoExtension->ExtensionType == FdoExtensionType)
    {
        /* Query the IRP type */
        switch (Minor)
        {
            case IRP_MN_QUERY_DEVICE_RELATIONS:

                /* Call the worker */
                DPRINT("Querying device relations for FDO\n");
                Status = HalpQueryDeviceRelations(DeviceObject,
                                                  IoStackLocation->Parameters.QueryDeviceRelations.Type,
                                                  (PVOID)&Irp->IoStatus.Information);
                break;

            case IRP_MN_QUERY_INTERFACE:

                /* Call the worker */
                DPRINT("Querying interface for FDO\n");
                Status = HalpQueryInterface(DeviceObject,
                                            IoStackLocation->Parameters.QueryInterface.InterfaceType,
                                            IoStackLocation->Parameters.QueryInterface.Size,
                                            IoStackLocation->Parameters.QueryInterface.InterfaceSpecificData,
                                            IoStackLocation->Parameters.QueryInterface.Version,
                                            IoStackLocation->Parameters.QueryInterface.Interface,
                                            (PVOID)&Irp->IoStatus.Information);
                break;


            case IRP_MN_QUERY_ID:

                /* Call the worker */
                DPRINT("Querying ID for FDO\n");
                Status = HalpQueryIdFdo(DeviceObject,
                                        IoStackLocation->Parameters.QueryId.IdType,
                                        (PVOID)&Irp->IoStatus.Information);
                break;

            case IRP_MN_QUERY_CAPABILITIES:

                /* Call the worker */
                DPRINT("Querying the capabilities for the FDO\n");
                Status = HalpQueryCapabilities(DeviceObject,
                                               IoStackLocation->Parameters.DeviceCapabilities.Capabilities);
                break;

            default:

                DPRINT("Other IRP: %lx\n", Minor);
                Status = STATUS_NOT_SUPPORTED;
                break;
        }

        /* What happpened? */
        if ((NT_SUCCESS(Status)) || (Status == STATUS_NOT_SUPPORTED))
        {
            /* Set the IRP status, unless this isn't understood */
            if (Status != STATUS_NOT_SUPPORTED)
            {
                Irp->IoStatus.Status = Status;
            }

            /* Pass it on */
            IoSkipCurrentIrpStackLocation(Irp);
            return IoCallDriver(FdoExtension->AttachedDeviceObject, Irp);
        }

        /* Otherwise, we failed, so set the status and complete the request */
        DPRINT1("IRP failed with status: %lx\n", Status);
        Irp->IoStatus.Status = Status;
        IoCompleteRequest(Irp, IO_NO_INCREMENT);
        return Status;
    }
    else
    {
        /* This is a PDO instead */
        ASSERT(FdoExtension->ExtensionType == PdoExtensionType);
        //PdoExtension = (PPDO_EXTENSION)FdoExtension;
        /* Query the IRP type */
        Status = STATUS_SUCCESS;
        switch (Minor)
        {
            case IRP_MN_START_DEVICE:

                /* We only care about a PCI PDO */
                DPRINT1("Start device received\n");
                /* Complete the IRP normally */
                break;

            case IRP_MN_REMOVE_DEVICE:

                /* Check if this is a PCI device */
                DPRINT1("Remove device received\n");

                /* We're done */
                Status = STATUS_SUCCESS;
                break;

            case IRP_MN_SURPRISE_REMOVAL:

                /* Inherit whatever status we had */
                DPRINT1("Surprise removal IRP\n");
                Status = Irp->IoStatus.Status;
                break;

            case IRP_MN_QUERY_DEVICE_RELATIONS:

                /* Query the device relations */
                DPRINT("Querying PDO relations\n");
                Status = HalpQueryDeviceRelations(DeviceObject,
                                                  IoStackLocation->Parameters.QueryDeviceRelations.Type,
                                                  (PVOID)&Irp->IoStatus.Information);
                break;

            case IRP_MN_QUERY_INTERFACE:

                /* Call the worker */
                DPRINT("Querying interface for PDO\n");
                Status = HalpQueryInterface(DeviceObject,
                                            IoStackLocation->Parameters.QueryInterface.InterfaceType,
                                            IoStackLocation->Parameters.QueryInterface.Size,
                                            IoStackLocation->Parameters.QueryInterface.InterfaceSpecificData,
                                            IoStackLocation->Parameters.QueryInterface.Version,
                                            IoStackLocation->Parameters.QueryInterface.Interface,
                                            (PVOID)&Irp->IoStatus.Information);
                break;

            case IRP_MN_QUERY_CAPABILITIES:

                /* Call the worker */
                DPRINT("Querying the capabilities for the PDO\n");
                Status = HalpQueryCapabilities(DeviceObject,
                                               IoStackLocation->Parameters.DeviceCapabilities.Capabilities);
                break;

            case IRP_MN_QUERY_RESOURCES:

                /* Call the worker */
                DPRINT("Querying the resources for the PDO\n");
                Status = HalpQueryResources(DeviceObject, (PVOID)&Irp->IoStatus.Information);
                break;

            case IRP_MN_QUERY_RESOURCE_REQUIREMENTS:

                /* Call the worker */
                DPRINT("Querying the resource requirements for the PDO\n");
                Status = HalpQueryResourceRequirements(DeviceObject,
                                                       (PVOID)&Irp->IoStatus.Information);
                break;

            case IRP_MN_QUERY_ID:

                /* Call the worker */
                DPRINT("Query the ID for the PDO\n");
                Status = HalpQueryIdPdo(DeviceObject,
                                        IoStackLocation->Parameters.QueryId.IdType,
                                        (PVOID)&Irp->IoStatus.Information);
                break;

            default:

                /* We don't handle anything else, so inherit the old state */
                DPRINT("Illegal IRP: %lx\n", Minor);
                Status = Irp->IoStatus.Status;
                break;
        }

        /* If it's not supported, inherit the old status */
        if (Status == STATUS_NOT_SUPPORTED) Status = Irp->IoStatus.Status;

        /* Complete the IRP */
        DPRINT("IRP completed with status: %lx\n", Status);
        Irp->IoStatus.Status = Status;
        IoCompleteRequest(Irp, IO_NO_INCREMENT);
        return Status;
    }
}

NTSTATUS
NTAPI
HalpDispatchWmi(IN PDEVICE_OBJECT DeviceObject,
                IN PIRP Irp)
{
    UNIMPLEMENTED_DBGBREAK("HAL: PnP Driver WMI!\n");
    return STATUS_SUCCESS;
}

NTSTATUS
NTAPI
HalpDispatchPower(IN PDEVICE_OBJECT DeviceObject,
                  IN PIRP Irp)
{
    PFDO_EXTENSION FdoExtension;

    DPRINT("HAL: PnP Driver Power!\n");
    FdoExtension = DeviceObject->DeviceExtension;
    if (FdoExtension->ExtensionType == FdoExtensionType)
    {
        PoStartNextPowerIrp(Irp);
        IoSkipCurrentIrpStackLocation(Irp);
        return PoCallDriver(FdoExtension->AttachedDeviceObject, Irp);
    }
    else
    {
        PoStartNextPowerIrp(Irp);
        Irp->IoStatus.Status = STATUS_SUCCESS;
        IoCompleteRequest(Irp, IO_NO_INCREMENT);
        return STATUS_SUCCESS;
    }
}

NTSTATUS
NTAPI
HalpDriverEntry(IN PDRIVER_OBJECT DriverObject,
                IN PUNICODE_STRING RegistryPath)
{
    NTSTATUS Status;
    PDEVICE_OBJECT TargetDevice = NULL;

    DPRINT("HAL: PnP Driver ENTRY!\n");

    /* This is us */
    HalpDriverObject = DriverObject;

    /* Set up add device */
    DriverObject->DriverExtension->AddDevice = HalpAddDevice;

    /* Set up the callouts */
    DriverObject->MajorFunction[IRP_MJ_PNP] = HalpDispatchPnp;
    DriverObject->MajorFunction[IRP_MJ_POWER] = HalpDispatchPower;
    DriverObject->MajorFunction[IRP_MJ_SYSTEM_CONTROL] = HalpDispatchWmi;

    /* Create the PDO and tell the PnP manager about us*/
    Status = IoReportDetectedDevice(DriverObject,
                                    InterfaceTypeUndefined,
                                    -1,
                                    -1,
                                    NULL,
                                    NULL,
                                    FALSE,
                                    &TargetDevice);
    if (!NT_SUCCESS(Status))
        return Status;

    TargetDevice->Flags &= ~DO_DEVICE_INITIALIZING;

    /* Set up the device stack */
    Status = HalpAddDevice(DriverObject, TargetDevice);
    if (!NT_SUCCESS(Status))
    {
        IoDeleteDevice(TargetDevice);
        return Status;
    }

    /* Return to kernel */
    return Status;
}

NTSTATUS
NTAPI
HaliInitPnpDriver(VOID)
{
    NTSTATUS Status;
    UNICODE_STRING DriverString;
    PAGED_CODE();

    /* Create the driver */
    RtlInitUnicodeString(&DriverString, L"\\Driver\\ACPI_HAL");
    Status = IoCreateDriver(&DriverString, HalpDriverEntry);

    /* Return status */
    return Status;
}

/* EOF */
