/*
 * COPYRIGHT:         See COPYING in the top level directory
 * PROJECT:           classicOS kernel
 * PURPOSE:           GDI Clipping Functions
 * FILE:              win32ss/gdi/eng/clip.c
 * PROGRAMER:         Jason Filby
 */

#include <win32k.h>
DBG_DEFAULT_CHANNEL(EngClip);


static __inline int
CompareRightDown(
    const RECTL *r1,
    const RECTL *r2)
{
    int Cmp;

    if (r1->top < r2->top)
    {
        Cmp = -1;
    }
    else if (r2->top < r1->top)
    {
        Cmp = +1;
    }
    else
    {
        ASSERT(r1->bottom == r2->bottom);
        if (r1->left < r2->left)
        {
            Cmp = -1;
        }
        else if (r2->left < r1->left)
        {
            Cmp = +1;
        }
        else
        {
            ASSERT(r1->right == r2->right);
            Cmp = 0;
        }
    }

    return Cmp;
}

static __inline int
CompareRightUp(
    const RECTL *r1,
    const RECTL *r2)
{
    int Cmp;

    if (r1->bottom < r2->bottom)
    {
        Cmp = +1;
    }
    else if (r2->bottom < r1->bottom)
    {
        Cmp = -1;
    }
    else
    {
        ASSERT(r1->top == r2->top);
        if (r1->left < r2->left)
        {
            Cmp = -1;
        }
        else if (r2->left < r1->left)
        {
            Cmp = +1;
        }
        else
        {
            ASSERT(r1->right == r2->right);
            Cmp = 0;
        }
    }

    return Cmp;
}

static __inline int
CompareLeftDown(
    const RECTL *r1,
    const RECTL *r2)
{
    int Cmp;

    if (r1->top < r2->top)
    {
        Cmp = -1;
    }
    else if (r2->top < r1->top)
    {
        Cmp = +1;
    }
    else
    {
        ASSERT(r1->bottom == r2->bottom);
        if (r1->right < r2->right)
        {
            Cmp = +1;
        }
        else if (r2->right < r1->right)
        {
            Cmp = -1;
        }
        else
        {
            ASSERT(r1->left == r2->left);
            Cmp = 0;
        }
    }

    return Cmp;
}

static __inline int
CompareLeftUp(
    const RECTL *r1,
    const RECTL *r2)
{
    int Cmp;

    if (r1->bottom < r2->bottom)
    {
        Cmp = +1;
    }
    else if (r2->bottom < r1->bottom)
    {
        Cmp = -1;
    }
    else
    {
        ASSERT(r1->top == r2->top);
        if (r1->right < r2->right)
        {
            Cmp = +1;
        }
        else if (r2->right < r1->right)
        {
            Cmp = -1;
        }
        else
        {
            ASSERT(r1->left == r2->left);
            Cmp = 0;
        }
    }
    return Cmp;
}

VOID
FASTCALL
IntEngInitClipObj(XCLIPOBJ *Clip)
{
    Clip->Rects = &Clip->rclBounds;
}

VOID FASTCALL
IntEngFreeClipResources(XCLIPOBJ *Clip)
{
    if (Clip->Rects != &Clip->rclBounds)
        EngFreeMem(Clip->Rects);
}


VOID
FASTCALL
IntEngUpdateClipRegion(
    XCLIPOBJ* Clip,
    ULONG count,
    const RECTL* pRect,
    const RECTL* rcBounds)
{
    if(count > 1)
    {
        RECTL* NewRects = EngAllocMem(0, FIELD_OFFSET(ENUMRECTS, arcl[count]), GDITAG_CLIPOBJ);

        if(NewRects != NULL)
        {
            Clip->RectCount = count;
            Clip->iDirection = CD_ANY;
            RtlCopyMemory(NewRects, pRect, count * sizeof(RECTL));

            Clip->iDComplexity = DC_COMPLEX;
            Clip->iFComplexity = ((Clip->RectCount <= 4) ? FC_RECT4 : FC_COMPLEX);
            Clip->iMode = TC_RECTANGLES;
            Clip->rclBounds = *rcBounds;

            if (Clip->Rects != &Clip->rclBounds)
                EngFreeMem(Clip->Rects);
            Clip->Rects = NewRects;
        }
    }
    else
    {
        Clip->iDirection = CD_ANY;

        Clip->iDComplexity = (((rcBounds->top == rcBounds->bottom) &&
                                     (rcBounds->left == rcBounds->right))
                                     ? DC_TRIVIAL : DC_RECT);

        Clip->iFComplexity = FC_RECT;
        Clip->iMode = TC_RECTANGLES;
        Clip->rclBounds = *rcBounds;
        Clip->RectCount = 1;
        if (Clip->Rects != &Clip->rclBounds)
            EngFreeMem(Clip->Rects);
        Clip->Rects = &Clip->rclBounds;
    }
}

/*
 * @implemented
 */
CLIPOBJ *
APIENTRY
EngCreateClip(VOID)
{
    XCLIPOBJ *Clip = EngAllocMem(FL_ZERO_MEMORY, sizeof(XCLIPOBJ), GDITAG_CLIPOBJ);
    if(Clip != NULL)
    {
        IntEngInitClipObj(Clip);
        TRACE("Created Clip Obj %p.\n", Clip);
        return (CLIPOBJ *)Clip;
    }

    ERR("Clip object allocation failed!\n");
    return NULL;
}

/*
 * @implemented
 */
VOID
APIENTRY
EngDeleteClip(
    _In_ _Post_ptr_invalid_ CLIPOBJ *pco)
{
    XCLIPOBJ* pxco = (XCLIPOBJ *)pco;
    TRACE("Deleting %p.\n", pco);
    IntEngFreeClipResources(pxco);
    EngFreeMem(pxco);
}

/*
 * @implemented
 */
ULONG
APIENTRY
CLIPOBJ_cEnumStart(
    _Inout_ CLIPOBJ *pco,
    _In_ BOOL bAll,
    _In_ ULONG iType,
    _In_ ULONG iDirection,
    _In_ ULONG cMaxRects)
{
    XCLIPOBJ* Clip = (XCLIPOBJ *)pco;
    SORTCOMP CompareFunc;

    Clip->bAll    = bAll;
    Clip->iType   = iType;
    Clip->EnumPos = 0;
    Clip->EnumMax = (cMaxRects > 0) ? cMaxRects : Clip->RectCount;

    if (CD_ANY != iDirection && Clip->iDirection != iDirection)
    {
        switch (iDirection)
        {
            case CD_RIGHTDOWN:
                CompareFunc = (SORTCOMP) CompareRightDown;
                break;

            case CD_RIGHTUP:
                CompareFunc = (SORTCOMP) CompareRightUp;
                break;

            case CD_LEFTDOWN:
                CompareFunc = (SORTCOMP) CompareLeftDown;
                break;

            case CD_LEFTUP:
                CompareFunc = (SORTCOMP) CompareLeftUp;
                break;

            default:
                ERR("Invalid iDirection %lu\n", iDirection);
                iDirection = Clip->iDirection;
                CompareFunc = NULL;
                break;
        }

        if (NULL != CompareFunc)
        {
            EngSort((PBYTE) Clip->Rects, sizeof(RECTL), Clip->RectCount, CompareFunc);
        }

        Clip->iDirection = iDirection;
    }

    /* Return the number of rectangles enumerated */
    if ((cMaxRects > 0) && (Clip->RectCount > cMaxRects))
    {
        return 0xFFFFFFFF;
    }

    return Clip->RectCount;
}

/*
 * @implemented
 */
BOOL
APIENTRY
CLIPOBJ_bEnum(
    _In_ CLIPOBJ *pco,
    _In_ ULONG cj,
    _Out_bytecap_(cj) ULONG *pulEnumRects)
{
    const RECTL* src;
    XCLIPOBJ* Clip = (XCLIPOBJ *)pco;
    ULONG nCopy;
    ENUMRECTS* pERects = (ENUMRECTS*)pulEnumRects;

    // Calculate how many rectangles we should copy
    nCopy = min( Clip->EnumMax - Clip->EnumPos,
            min( Clip->RectCount - Clip->EnumPos,
            (cj - sizeof(ULONG)) / sizeof(RECTL)));

    if(nCopy == 0)
    {
        return FALSE;
    }

    /* Copy rectangles */
    src = &Clip->Rects[Clip->EnumPos];
    RtlCopyMemory(pERects->arcl, src, nCopy * sizeof(RECTL));

    pERects->c = nCopy;

    Clip->EnumPos+=nCopy;

    return Clip->EnumPos < Clip->RectCount;
}

/* EOF */
