// This file is converted by code7bit.
// code7bit: https://github.com/katahiromz/code7bit
// To revert conversion, please execute "code7bit -r <file>".
/* TRANSLATOR : Ardit Dani (Ard1t) (ardit.dani@gmail.com)
 * DATE OF TR:  29-11-2013
*/

#pragma once

static MUI_ENTRY sqALSetupInitPageEntries[] =
{
    {
        4,
        3,
        " Instalimi i classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        0,
        20,
        "Please wait while the classicOS Setup initializes itself",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_CENTER,
        TEXT_ID_STATIC
    },
    {
        0,
        21,
        "and discovers your devices...",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_CENTER,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "Please wait...",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY sqALLanguagePageEntries[] =
{
    {
        4,
        3,
        " Instalimi i classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "P\211rzgjedhja e Gjuh\211s",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        10,
        "\x07  Ju lutem p\211rzgjedhni gjuh\211n p\211r p\211rdorim gjat\211 instalimit.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        11,
        "   Kliko ENTER.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        13,
        "\x07  Kjo gjuh\211 do j\211te e parazgjedhur p\211r sistemin final.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "ENTER = Vazhdo  F3 = Dil",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY sqALWelcomePageEntries[] =
{
    {
        4,
        3,
        " Instalimi i classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "Mir\211 se vini n\211 instalimin e classicOS",
        TEXT_STYLE_HIGHLIGHT,
        TEXT_ID_STATIC
    },
    {
        6,
        11,
        "Kjo pjese e instalimit kopjon Sistemin Opererativ t\211 classicOS",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        12,
        "n\211 kompjuter dhe pergatit pjesen e dyt\211 t\211 instalimit.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        15,
        "\x07  Press ENTER to install or upgrade classicOS.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        17,
        "\x07  Kliko R p\211r t\211 riparuar ose apdejtuar classicOS.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        19,
        "\x07  Kliko L p\211r t\211 v\211zhguar Termat e Li\211enses dhe kushtet e classicOS.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        21,
        "\x07  Kliko F3 t\211 dilni pa instaluar classicOS.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        23,
        "P\211r m\211 shum\211 informacione mbi classicOS, ju lutem vizitoni:",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        24,
        "https://classicOS.org/",
        TEXT_STYLE_HIGHLIGHT,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "ENTER = Vazhdo  R = Riparo  L = Li\211ens\211  F3 = Dil",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY sqALIntroPageEntries[] =
{
    {
        4,
        3,
        " Instalimi i classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "classicOS Version Status",
        TEXT_STYLE_HIGHLIGHT,
        TEXT_ID_STATIC
    },
    {
            6,
            11,
            "classicOS 2k3",
            TEXT_STYLE_NORMAL,
            TEXT_ID_STATIC
        },
        {
            6,
            12,
            "classicOS 2k3 is an operating system made to look and function",
            TEXT_STYLE_NORMAL,
            TEXT_ID_STATIC
        },
        {
            6,
            13,
            "like Windows XP and Windows Server 2003.",
            TEXT_STYLE_NORMAL,
            TEXT_ID_STATIC
        },
        {
            6,
            15,
            "It has compatibility with most apps made for XP or Server 2003",
            TEXT_STYLE_NORMAL,
            TEXT_ID_STATIC
        },
        {
            6,
            16,
            "It is advised to install classicOS 2k3 on a VM, as I (the dev) haven't",
            TEXT_STYLE_NORMAL,
            TEXT_ID_STATIC
        },
        {
                6,
                17,
                "yet tested it on real hardware.",
                TEXT_STYLE_NORMAL,
                TEXT_ID_STATIC
            },
    {
        8,
        19,
        "\x07  Press ENTER to continue classicOS Setup.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        21,
        "\x07  Press F3 to quit without installing classicOS.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "ENTER = Continue   F3 = Quit",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY sqALLicensePageEntries[] =
{
    {
        4,
        3,
        " Instalimi i classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        6,
        "Li\211ensa:",
        TEXT_STYLE_HIGHLIGHT,
        TEXT_ID_STATIC
    },
    {
        8,
        8,
        "Sistemi classicOS \211sht\211 i li\211ensuar nd\211r termat e",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        9,
        "GNU GPL me pjes\211 q\211 p\211rmbajn\211 kode nga li\211ensa t\211 tjera",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        10,
        "n\211 p\211rputhje me X11 apo BSD dhe GNU LGPL li\211ens.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        11,
        "T\211 gjitha programet q\211 jan\211 pjes\211 e sistemit classicOS jan\211",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        12,
        "t\211 l\211shuara si dhe t\211 mirembajtura n\211n GNU GPL t\211",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        13,
        "li\211enses origjinale.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        15,
        "Ky sistem vjen me asnj\211 garanci opo kufizim mbi p\211rdorimin e tij,",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        16,
        "ruani ligjin e aplikueshem vendor dhe nd\211rkombetar. Li\211encimi i",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        17,
        "classicOS vet\211m mbulon shp\211rndarjen e pal\211ve t\211 treta.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        18,
        "N\211se p\211r ndonj\211 arsye ju nuk keni marr\211 nj\211 kopje t\211",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        19,
        "GNU General Public Li\211ense me classicOS ju lutem vizitoni",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        20,
        "http://www.gnu.org/licenses/licenses.html",
        TEXT_STYLE_HIGHLIGHT,
        TEXT_ID_STATIC
    },
    {
        8,
        22,
        "Garanci:",
        TEXT_STYLE_HIGHLIGHT,
        TEXT_ID_STATIC
    },
    {
        8,
        24,
        "Ky sistem \211sht\211 falas; shih burimet dhe kushtet p\211r kopjim.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        25,
        "Nuk ka asnj\211 GARNCI; as edhe p\211r TREGTUESHMERINE ose",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        26,
        "P\205RDORIMIT P\205R NJ\205 Q\205LLIM T\205 CAKTUAR",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "ENTER = Kthehu",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY sqALDevicePageEntries[] =
{
    {
        4,
        3,
        " Instalimi i classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "Lista e meposhtme tregon parametrat aktuale t\211 pajisjeve.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        24,
        11,
        "Komputer:",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_RIGHT,
        TEXT_ID_STATIC
    },
    {
        24,
        12,
        "Ekran:",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_RIGHT,
        TEXT_ID_STATIC
    },
    {
        24,
        13,
        "Tastier\211:",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_RIGHT,
        TEXT_ID_STATIC
    },
    {
        24,
        14,
        "Paraqitja e Tastier\211s:",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_RIGHT,
        TEXT_ID_STATIC
    },
    {
        24,
        16,
        "Prano:",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_RIGHT,
        TEXT_ID_STATIC
    },
    {
        25,
        16, "Prano k\211to konfigurime t\211 pajisjeve",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        19,
        "Ju mund t\211 ndryshoni parametrat e pajisjeve me butonat UP ose DOWN",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        20,
        "p\211r t\211 zgjedhur nj\211 hyrje. Pastaj ENTER t\211 p\211rzgjedhni alternativat",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        21,
        "konfiguruse.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        23,
        "N?se cilesimet jan\211 t\211 sakta, zgjidhni\"Prano konfigurimin e pajisjeve\"",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        24,
        "dhe klikoni ENTER.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "ENTER = Vazhdo   F3 = Dil",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY sqALRepairPageEntries[] =
{
    {
        4,
        3,
        " Instalimi i classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "Instalimi i classicOS \211sht\211 n\211 fazat e zhvillimit. Ajo ende nuk i",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        9,
        "mb\211shtet t\211 gjitha funksionet e nj\211 instalimi plot\211sisht t\211 p\211rdorsh\211m.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        12,
        "Funksionet e riparim nuk jan\211 implem\211ntuar ende.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        15,
        "\x07  Klikoni U p\211r t\211 Apdejtuar OS'in.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        17,
        "\x07  Klikoni R p\211r modulin e riparimit.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        19,
        "\x07  Kliko ESC p\211r ty kthyer tek menuja kryesore.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        21,
        "\x07  Kliko ENTER t\211 rinisni kompjuterin tuaj.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "ESC = Menuja Kryesore  U = Apdejto  R = Riparo  ENTER = Rinis sistemin",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY sqALUpgradePageEntries[] =
{
    {
        4,
        3,
        " Instalimi i classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "The classicOS Setup can upgrade one of the available classicOS installations",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        9,
        "listed below, or, if a classicOS installation is damaged, the Setup program",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        10,
        "can attempt to repair it.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        12,
        "The repair functions are not all implemented yet.",
        TEXT_STYLE_HIGHLIGHT,
        TEXT_ID_STATIC
    },
    {
        8,
        15,
        "\x07  Press UP or DOWN to select an OS installation.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        17,
        "\x07  Press U for upgrading the selected OS installation.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        19,
        "\x07  Press ESC to continue with a new installation.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        21,
        "\x07  Press F3 to quit without installing classicOS.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "U = Upgrade   ESC = Do not upgrade   F3 = Quit",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY sqALComputerPageEntries[] =
{
    {
        4,
        3,
        " Instalimi i classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "D\211shironi t\211 ndryshoni llojin e kompjuterit p\211r t\211 instaluar.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        10,
        "\x07  Klikoni butonat UP ose DOWN p\211r t\211 p\211rzgjedhur tipin e kompjuterit t\211 deshiruar.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        11,
        "   Pastaj klikoni ENTER.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        13,
        "\x07  Klikoni butonin ESC p\211r tu kthyer tek menuja e meparshme pa b\211r\211 ndryshime",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        14,
        "   tipin e kompjuterit.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "ENTER = Vazhdo   ESC = Anulo   F3 = Dil",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY sqALFlushPageEntries[] =
{
    {
        4,
        3,
        " Instalimi i classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        10,
        6,
        "Sistemi \211sht\211 tani duke u siguruar t\211 gjitha te dh\211nat jan\211 ruajtur n\211 diskun tuaj.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        10,
        8,
        "Kjo mund te marr\211 nje minut\211.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        10,
        9,
        "Kur te p\211rfundoi, kompjuteri juaj do t\211 riniset automatikisht.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "Pastro mbetjet",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY sqALQuitPageEntries[] =
{
    {
        4,
        3,
        " Instalimi i classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        10,
        6,
        "classicOS nuk \211sht\211 instaluar plot\211sisht.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        10,
        8,
        "Hiq floppy disk nga Drive A: dhe",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        10,
        9,
        "t\211 gjith\211 CD-ROMs nga CD-Drives.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        10,
        11,
        "Kliko ENTER t\211 rinisni kompjuterin tuaj.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "Ju lutem prisni...",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY sqALDisplayPageEntries[] =
{
    {
        4,
        3,
        " Instalimi i classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "Ju deshironi t\211 ndryshoje llojin e ekranit p\211r t\211 instaluar.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        10,
         "\x07  Klikoni butonat UP aso DOWN p\211r t\211 p\211rzgjedhur tipin e ekranin t\211 d\211shiruar.",
         TEXT_STYLE_NORMAL,
         TEXT_ID_STATIC
    },
    {
        8,
        11,
        "   Pastaj klikoni ENTER.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        13,
        "\x07  Klikoni butonin ESC  p\211r tu kthyer te menuja e meparshme pa b\211r\211 ndryshime",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        14,
        "   tipin e ekranit.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "ENTER = Vazhdo   ESC = Anulo   F3 = Dil",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY sqALSuccessPageEntries[] =
{
    {
        4,
        3,
        " Instalimi i classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        10,
        6,
        "Komponent\211t themelore t\211 classicOS jan\211 instaluar me sukses.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        10,
        8,
        "Hiqni floppy disk nga Drive A: dhe",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        10,
        9,
        "te gjith CD-ROMs nga CD-Drive.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        10,
        11,
        "Klikoni ENTER p\211r t\211 rinisur kompjuterin tuaj.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "ENTER = Rinis kompjuterin",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY sqALBootPageEntries[] =
{
    {
        4,
        3,
        " Instalimi i classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "Instalimi nuk mund t\211 instaloj\211 programin e bootloaderit ne kompjuterin tuaj",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        9,
        "hardisku",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        13,
        "Ju lutem fusni nje floppy disk t\211 formatuar n\211 drive A: dhe",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        14,
        "klikoni ENTER.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "ENTER = Vazhdo   F3 = Dil",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        NULL,
        0
    }

};

static MUI_ENTRY sqALSelectPartitionEntries[] =
{
    {
        4,
        3,
        " Instalimi i classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "Lista meposht tregon particionet dhe pjes\211n e paperdorur t\211 hard diskut",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        9,
        "p\211r particione t\211 reja.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        11,
        "\x07  Kliko butonin UP ose DOWN p\211r t\211 zgjedhur listen hyr\211se.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        13,
        "\x07  Kliko ENTER p\211r t\211 instaluar classicOS n\211 particionin e p\211rzgjedhur.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        15,
        "\x07  Press P to create a primary partition.",
//        "\x07  Kiko C p�r t� krijuar nj� particion t� ri.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        17,
        "\x07  Press E to create an extended partition.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        19,
        "\x07  Press L to create a logical partition.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        21,
        "\x07  Kliko D p\211r t\211 fshir\211 nj\211 particion ekzistues.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "Ju luttem prisni...",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY sqALChangeSystemPartition[] =
{
    {
        4,
        3,
        " classicOS 2k3 Service Pack 2 Setup ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "The current system partition of your computer",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        12,
        "on the system disk",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        16,
        "uses a format not supported by classicOS.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        18,
        "In order to successfully install classicOS, the Setup program must change",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        19,
        "the current system partition to a new one.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        21,
        "The new candidate system partition is:",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        25,
        "\x07  To accept this choice, press ENTER.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        27,
        "\x07  To manually change the system partition, press ESC to go back to",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        28,
        "   the partition selection list, then select or create a new system",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        29,
        "   partition on the system disk.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        32,
        "In case there are other operating systems that depend on the original",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        33,
        "system partition, you may need to either reconfigure them for the new",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        34,
        "system partition, or you may need to change the system partition back",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        35,
        "to the original one after finishing the installation of classicOS.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "ENTER = Continue   ESC = Cancel",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY sqALConfirmDeleteSystemPartitionEntries[] =
{
    {
        4,
        3,
        " Instalimi i classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "You have chosen to delete the system partition.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        10,
        "System partitions can contain diagnostic programs, hardware configuration",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        11,
        "programs, programs to start an operating system (like classicOS) or other",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        12,
        "programs provided by the hardware manufacturer.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        14,
        "Delete a system partition only when you are sure that there are no such",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        15,
        "programs on the partition, or when you are sure you want to delete them.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        16,
        "When you delete the partition, you might not be able to boot the",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        17,
        "computer from the harddisk until you finished the classicOS Setup.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        20,
        "\x07  Press ENTER to delete the system partition. You will be asked",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        21,
        "   to confirm the deletion of the partition again later.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        24,
        "\x07  Press ESC to return to the previous page. The partition will",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        25,
        "   not be deleted.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "ENTER=Continue  ESC=Cancel",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY sqALFormatPartitionEntries[] =
{
    {
        4,
        3,
        " Instalimi i classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "Formato particionin",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        10,
        "Instalimi tani do t\211 formatoj\211 particionin. Kliko ENTER p\211r t\211 vazhduar.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_FORMAT_PROMPT
    },
    {
        0,
        0,
        "ENTER = Vazhdo   F3 = Dil",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY sqALCheckFSEntries[] =
{
    {
        4,
        3,
        " Instalimi i classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "Instalimi tani \211sht\211 duke kontrolluar particionin e p\211rzgjedhur.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "Ju lutem prisni...",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY sqALInstallDirectoryEntries[] =
{
    {
        4,
        3,
        " Instalimi i classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "Instalimi i classicOS n\211 particionet e p\211rzgjedhura. Zgjidh nj\211",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        9,
        "skede ku deshironi t\211 instaloni classicOS:",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        14,
        "P\211r t\211 ndryshuar skeden e sygjeruar, klikoni BACKSPACE p\211r t\211 fshir\211",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        15,
        "karakteret dhe pastaj shkruani skeden q\211 d\211shironi q\211 classicOS",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        16,
        "t\211 instalohet.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "ENTER = Vazhdo   F3 = Dil",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY sqALFileCopyEntries[] =
{
    {
        4,
        3,
        " Instalimi i classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        0,
        12,
        "Ju lutem prisni nderkohe q\211 instaluesi i classicOS kopjon dokumentat tuaj",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_CENTER,
        TEXT_ID_STATIC
    },
    {
        0,
        13,
        "n\211 skedat p\211rkatese.",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_CENTER,
        TEXT_ID_STATIC
    },
    {
        0,
        14,
        "Kjo mund t\211 marr\211 disa minuta p\211r t\211 p\211rfunduar.",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_CENTER,
        TEXT_ID_STATIC
    },
    {
        50,
        0,
        "\xB3 Ju lutem prisni...    ",
        TEXT_TYPE_STATUS,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY sqALBootLoaderEntries[] =
{
    {
        4,
        3,
        " Instalimi i classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "Instalimi po instalon boot loaderin",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        12,
        "Instalo programin bootloader mbi harddisk (MBR dhe VBR).",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        13,
        "Instalo programin bootloader mbi harddisk (vetem VBR).",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        14,
        "Instalo bootloaderin ne nje floppy disk.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        15,
        "Kalo instalimin e bootloaderit.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "ENTER = Vazhdo   F3 = Dil",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY sqALBootLoaderInstallPageEntries[] =
{
    {
        4,
        3,
        " classicOS 2k3 Service Pack 2 Setup ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "Installing the bootloader onto the media, please wait...",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY sqALKeyboardSettingsEntries[] =
{
    {
        4,
        3,
        " Instalimi i classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "Ju deshironi t\211 ndryshoni llojin e tasti\211res p\211r t\211 instaluar.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        10,
        "\x07  Klikoni butonin UP ose DOWN p\211r t\211 p\211rzgjedhur tastieren e deshiruar.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        11,
        "   Kliko ENTER.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        13,
        "\x07  Kliko butonin ESC p\211r tu kthyer tek menuja e m\211parshme pa b\211r\211 ndryshimet e",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        14,
        "   tipit t\211 tastier\211s.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "ENTER = Vazhdo   ESC = Anulo   F3 = Dil",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY sqALLayoutSettingsEntries[] =
{
    {
        4,
        3,
        " Instalimi i classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "Ju lutem zgjidhni nj\211 p\211rzgjedhje t\211 instalimit.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        10,
        "\x07  Klikoni butoin UP ose DOWN p\211r t\211 p\211rzgjedhur paraqitjen e tastier\211s",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        11,
        "    s\211 deshiruar. Pastaj Klikoni ENTER.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        13,
        "\x07  Klikoni butonin ESC p\211r tu kthyer tek menuja e m\211parshme pa b\211r\211 ndryshimet e",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        14,
        "   perzgjedhura te tastier\211s.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "ENTER = Vazhdo   ESC = Anulo   F3 = Dil",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        NULL,
        0
    },

};

static MUI_ENTRY sqALPrepareCopyEntries[] =
{
    {
        4,
        3,
        " Instalimi i classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "Instalimi pergatit kompjuterin tuaj p\211r kopjimin e dokumentave t\211 classicOS.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "Ndertimi i list\211s s\211 dokumentave p\211r tu kopjuar...",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        NULL,
        0
    },

};

static MUI_ENTRY sqALSelectFSEntries[] =
{
    {
        4,
        3,
        " Instalimi i classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        17,
        "Zgjidh nj\211 sistem dokumentesh nga lista e meposhtme.",
        0
    },
    {
        8,
        19,
        "\x07  Klikoni UP ose DOWN p\211r tv p\211rzgjedhur sistemin e dokumentave.",
        0
    },
    {
        8,
        21,
        "\x07  Kliko ENTER p\211r t\211 formatuar particionin.",
        0
    },
    {
        8,
        23,
        "\x07  Kliko ESC p\211r t\211 p\211rzgjedhur nj\211 particion tjet\211r.",
        0
    },
    {
        0,
        0,
        "ENTER = Vazhdo   ESC = Anulo   F3 = Dil",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY sqALDeletePartitionEntries[] =
{
    {
        4,
        3,
        " Instalimi i classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "Ju keni zgjedhur p\211r t\211 fshir\211 particionin",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        18,
        "\x07  Kliko L p\211r t\211 fshir\211 particionin.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        11,
        19,
        "KUJDES: T\211 gjitha t\211 dh\211nat n\211 k\211t\211 PARTICION do t\211 humbin!",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        21,
        "\x07  Kliko ESC p\211r ta anuluar.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "L = Fshi Particionin   ESC = Anulo   F3 = Dil",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY sqALRegistryEntries[] =
{
    {
        4,
        3,
        " Instalimi i classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "Instalimi po apdejton sistemin e konfigurimit.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "Krijimi i kosheres s\211 rregjistrit...",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        NULL,
        0
    },

};

MUI_ERROR sqALErrorEntries[] =
{
    {
        // NOT_AN_ERROR
        "Success\n"
    },
    {
        // ERROR_NOT_INSTALLED
        "classicOS nuk \211shte instaluar plotesisht ne kompjuterin\n"
        "tuaj. N\211se dilni nga instalimi tani, ju do t\211 duhet t\211\n"
        "rifilloni instalimin e classicOS p\211rs\211ri.\n"
        "\n"
        "  \x07  Kliko ENTER p\211r t\211 vazhduar instalimin.\n"
        "  \x07  Kliko F3 t\211 dal\211sh nga instalimi.",
        "F3 = Dil  ENTER = Vazhdo"
    },
    {
        // ERROR_NO_BUILD_PATH
        "Failed to build the installation paths for the classicOS installation directory!\n"
        "ENTER = Reboot computer"
    },
    {
        // ERROR_SOURCE_PATH
        "You cannot delete the partition containing the installation source!\n"
        "ENTER = Reboot computer"
    },
    {
        // ERROR_SOURCE_DIR
        "You cannot install classicOS within the installation source directory!\n"
        "ENTER = Reboot computer"
    },
    {
        // ERROR_NO_HDD
        "Instalimi nuk mund t\211 gjej nj\211 harddisk.\n",
        "ENTER = Ristarto kompjuterin"
    },
    {
        // ERROR_NO_SOURCE_DRIVE
        "Instalimi nuk mund t\211 gjej burimin e t\211 dh\211nave/drive.\n",
        "ENTER = Ristarto kompjuterin"
    },
    {
        // ERROR_LOAD_TXTSETUPSIF
        "Instalimi d\211shtoj p\211r t\211 ngarkuar dokumentin TXTSETUP.SIF.\n",
        "ENTER = Ristarto kompjuterin"
    },
    {
        // ERROR_CORRUPT_TXTSETUPSIF
        "Instalimi zbuloj nj\211 dokument t\211 korruptuar TXTSETUP.SIF.\n",
        "ENTER = Ristarto kompjuterin"
    },
    {
        // ERROR_SIGNATURE_TXTSETUPSIF,
        "Instalimi zbuloj nj\211 firm\211 t\211 pavleshm\211 ne TXTSETUP.SIF.\n",
        "ENTER = Ristarto kompjuterin"
    },
    {
        // ERROR_DRIVE_INFORMATION
        "Instalimi nuk gjeti informacionet n\211 drive'rin e systemit.\n",
        "ENTER = Ristarto kompjuterin"
    },
    {
        // ERROR_WRITE_BOOT,
        "Instalimi deshtoj n\211 instalimin e %S bootcode n\211 particionin e sistemit.",
        "ENTER = Ristarto kompjuterin"
    },
    {
        // ERROR_LOAD_COMPUTER,
        "Instalimi d\211shtoj n\211 ngarkimin e list\211s s\211 kompjuterit.\n",
        "ENTER = Ristarto kompjuterin"
    },
    {
        // ERROR_LOAD_DISPLAY,
        "Instalimi d\211shtoj n\211 ngarkimin e list\211s s\211 konfigurimit t\211 ekranit.\n",
        "ENTER = Ristarto kompjuterin"
    },
    {
        // ERROR_LOAD_KEYBOARD,
        "Instalimi d\211shtoj n\211 ngarkimin e list\211s s\211 tipit t\211 p\211rzgjsdhjes t\211 tastier\211s.\n",
        "ENTER = Ristarto kompjuterin"
    },
    {
        // ERROR_LOAD_KBLAYOUT,
        "Instalimi d\211shtoj n\211 ngarkimin e list\211s s\211 tipit t\211 p\211rzgjedhjes t\211 tastier\211s.\n",
        "ENTER = Ristarto kompjuterin"
    },
    {
        // ERROR_WARN_PARTITION,
          "Instalimi zbuloi q\211 t\211 pakten nj\211 harddisk p\211rmban nj\211 mosp\211rputhshmeri\n"
          "n\211 tabel\211n e particionit q\211 nuk mund t\211 trajtohet tamam!\n"
          "\n"
          "Krijimi apo fshirja e particionit mund t\211 shkat\211rroi tabelen e partiocioneve.\n"
          "\n"
          "  \x07  Kliko F3 p\211r daljen nga instalimi.\n"
          "  \x07  Kliko ENTER p\211r t\211 vazhduar.",
          "F3 = Dil  ENTER = Vazhdo"
    },
    {
        // ERROR_NEW_PARTITION,
        "Tani ju mund t\211 krijoni nj\211 particion brenda\n"
        "nj\211 particioni ekzistues!\n"
        "\n"
        "  * Shtypni nj\211 tast \211far\211do p\211r t\211 vazhduar.",
        NULL
    },
    {
        // ERROR_DELETE_SPACE,
        "Ju nuk mund t\211 fshini hap\211sir\211 n\211 disk jasht particioneve!\n"
        "\n"
        "  * Shtypni nj\211 tast cfar\211do p\211r t\211 vazhduar.",
        NULL
    },
    {
        // ERROR_INSTALL_BOOTCODE,
        "Instalimi d\211shtoj n\211 instalimin e %S bootcode n\211 particionin e sistemit.",
        "ENTER = Ristarto kompjuterin"
    },
    {
        // ERROR_NO_FLOPPY,
        "Ska disk n\211 drive A:.",
        "ENTER = Vazhdo"
    },
    {
        // ERROR_UPDATE_KBSETTINGS,
        "Instalimi d\211shtoj n\211 ngarkimin e list\211s s\211 tipit tv p\211rzgjsdhjes t\211 tastier\211s.",
        "ENTER = Ristarto kompjuterin"
    },
    {
        // ERROR_UPDATE_DISPLAY_SETTINGS,
        "Instalimi d\211shtoi p\211r t\211 rinovuar konfigurimet e regjistrit.",
        "ENTER = Ristarto kompjuterin"
    },
    {
        // ERROR_IMPORT_HIVE,
        "Instalimi d\211shtoi n\211 importimin e skedes koshere.",
        "ENTER = Ristarto kompjuterin"
    },
    {
        // ERROR_FIND_REGISTRY
        "Instalimi d\211shtoi p\211r t\211 gjetur dokumentat e regjistrit t\211 t\211 dh\211nave.",
        "ENTER = Ristarto kompjuterin"
    },
    {
        // ERROR_CREATE_HIVE,
        "Instalimi d\211shtoi p\211r t krijuar rgjistrin e koshere.",
        "ENTER = Ristarto kompjuterin"
    },
    {
        // ERROR_INITIALIZE_REGISTRY,
        "Instalimi d\211shtoi n\211 nisjen e regjistrit.",
        "ENTER = Ristarto kompjuterin"
    },
    {
        // ERROR_INVALID_CABINET_INF,
        "Kabineti nuk ka t\211 vlefshme dokumentin inf.\n",
        "ENTER = Ristarto kompjuterin"
    },
    {
        // ERROR_CABINET_MISSING,
        "Kabineti nuk u gj\211nd.\n",
        "ENTER = Ristarto kompjuterin"
    },
    {
        // ERROR_CABINET_SCRIPT,
        "Kabineti ska asnj\211 skript konfigurimi.\n",
        "ENTER = Ristarto kompjuterin"
    },
    {
        // ERROR_COPY_QUEUE,
        "Installimi d\211shtoi rradh\211n e kopjimit t\211 dokumentave.\n",
        "ENTER = Ristarto kompjuterin"
    },
    {
        // ERROR_CREATE_DIR,
        "Instalimi nuk mund t\211 krijoj\211 skedat p\211r instalim.",
        "ENTER = Ristarto kompjuterin"
    },
    {
        // ERROR_TXTSETUP_SECTION,
        "Instalimi d\211shtoi p\211r t\211 gjetur '%S' seksionin\n"
        "ne TXTSETUP.SIF.\n",
        "ENTER = Ristarto kompjuterin"
    },
    {
        // ERROR_CABINET_SECTION,
        "Instalimi d\211shtoi p\211r t\211 gjetur '%S' seksionin\n"
        "ne kabinet.\n",
        "ENTER = Ristarto kompjuterin"
    },
    {
        // ERROR_CREATE_INSTALL_DIR
        "Instalimi nuk mund t\211 krijoj\211 skedat p\211r instalim.",
        "\211NT\211R = Ristarto kompjuterin"
    },
    {
        //�RROR_FIND_S�TUPDATA,
        "Instalimi d\211shtoi p\211r t\211 gjetur seksionin e 'SetupData'\n"
        "ne TXTSETUP.SIF.\n",
        "ENTER = Ristarto kompjuterin"
    },
    {
        // ERROR_WRITE_PTABLE,
        "Instalimi d\211shtoi p\211r t\211 shkruar tabelen e particionit.\n"
        "ENTER = Ristarto kompjuterin"
    },
    {
        // ERROR_ADDING_CODEPAGE,
        "Instalimi d\211shtoi p\211r t\211 shtuar codepage n\211 regjister.\n"
        "ENTER = Ristarto kompjuterin"
    },
    {
        // ERROR_UPDATE_LOCALESETTINGS,
        "Instalimi nuk mund t\211 v\211ndosi v\211ndnoshjen n\211 sistem.\n"
        "ENTER = Ristarto kompjuterin"
    },
    {
        // ERROR_ADDING_KBLAYOUTS,
        "Instalimi d\211shtoi p\211r t\211 shtuar zgj\211dhjen e tastier\211s n\211 regjister.\n"
        "ENTER = Ristarto kompjuterin"
    },
    {
        // ERROR_UPDATE_GEOID,
        "Instalimi nuk mund t\211 vendosni id geo.\n"
        "ENTER = Ristarto kompjuterin"
    },
    {
        // ERROR_DIRECTORY_NAME,
        "Invalid directory name.\n"
        "\n"
        "  * Press any key to continue."
    },
    {
        // ERROR_INSUFFICIENT_PARTITION_SIZE,
        "The selected partition is not large enough to install classicOS.\n"
        "The install partition must have a size of at least %lu MB.\n"
        "\n"
        "  * Shtypni nj\211 tast cfar\211do p\211r t\211 vazhduar.",
        NULL
    },
    {
        // ERROR_PARTITION_TABLE_FULL,
        "You cannot create a new primary or extended partition in the\n"
        "partition table of this disk because the partition table is full.\n"
        "\n"
        "  * Press any key to continue."
    },
    {
        // ERROR_ONLY_ONE_EXTENDED,
        "You cannot create more than one extended partition per disk.\n"
        "\n"
        "  * Press any key to continue."
    },
    {
        // ERROR_FORMATTING_PARTITION,
        "Setup is unable to format the partition:\n"
        " %S\n"
        "\n"
        "ENTER = Reboot computer"
    },
    {
        NULL,
        NULL
    }
};

MUI_PAGE sqALPages[] =
{
    {
        SETUP_INIT_PAGE,
        sqALSetupInitPageEntries
    },
    {
        LANGUAGE_PAGE,
        sqALLanguagePageEntries
    },
    {
        WELCOME_PAGE,
        sqALWelcomePageEntries
    },
    {
        INSTALL_INTRO_PAGE,
        sqALIntroPageEntries
    },
    {
        LICENSE_PAGE,
        sqALLicensePageEntries
    },
    {
        DEVICE_SETTINGS_PAGE,
        sqALDevicePageEntries
    },
    {
        REPAIR_INTRO_PAGE,
        sqALRepairPageEntries
    },
    {
        UPGRADE_REPAIR_PAGE,
        sqALUpgradePageEntries
    },
    {
        COMPUTER_SETTINGS_PAGE,
        sqALComputerPageEntries
    },
    {
        DISPLAY_SETTINGS_PAGE,
        sqALDisplayPageEntries
    },
    {
        FLUSH_PAGE,
        sqALFlushPageEntries
    },
    {
        SELECT_PARTITION_PAGE,
        sqALSelectPartitionEntries
    },
    {
        CHANGE_SYSTEM_PARTITION,
        sqALChangeSystemPartition
    },
    {
        CONFIRM_DELETE_SYSTEM_PARTITION_PAGE,
        sqALConfirmDeleteSystemPartitionEntries
    },
    {
        SELECT_FILE_SYSTEM_PAGE,
        sqALSelectFSEntries
    },
    {
        FORMAT_PARTITION_PAGE,
        sqALFormatPartitionEntries
    },
    {
        CHECK_FILE_SYSTEM_PAGE,
        sqALCheckFSEntries
    },
    {
        DELETE_PARTITION_PAGE,
        sqALDeletePartitionEntries
    },
    {
        INSTALL_DIRECTORY_PAGE,
        sqALInstallDirectoryEntries
    },
    {
        PREPARE_COPY_PAGE,
        sqALPrepareCopyEntries
    },
    {
        FILE_COPY_PAGE,
        sqALFileCopyEntries
    },
    {
        KEYBOARD_SETTINGS_PAGE,
        sqALKeyboardSettingsEntries
    },
    {
        BOOT_LOADER_PAGE,
        sqALBootLoaderEntries
    },
    {
        LAYOUT_SETTINGS_PAGE,
        sqALLayoutSettingsEntries
    },
    {
        QUIT_PAGE,
        sqALQuitPageEntries
    },
    {
        SUCCESS_PAGE,
        sqALSuccessPageEntries
    },
    {
        BOOT_LOADER_INSTALLATION_PAGE,
        sqALBootLoaderInstallPageEntries
    },
    {
        BOOT_LOADER_FLOPPY_PAGE,
        sqALBootPageEntries
    },
    {
        REGISTRY_PAGE,
        sqALRegistryEntries
    },
    {
        -1,
        NULL
    }
};

MUI_STRING sqALStrings[] =
{
    {STRING_PLEASEWAIT,
     "   Ju lutem prisni..."},
    {STRING_INSTALLCREATEPARTITION,
     "   ENTER = Install   P = Create Primary   E = Create Extended   F3 = Quit"},
//     "   ENTER = Instalo   C = Krijo Particion   F3 = Dil"},
    {STRING_INSTALLCREATELOGICAL,
     "   ENTER = Install   L = Create Logical Partition   F3 = Quit"},
    {STRING_INSTALLDELETEPARTITION,
     "   ENTER = Instalo   D = Fshi Particion   F3 = Dil"},
    {STRING_DELETEPARTITION,
     "   D = Delete Partition   F3 = Quit"},
    {STRING_PARTITIONSIZE,
     "Madh\211sia e particionit t\211 ri:"},
    {STRING_CHOOSENEWPARTITION,
//     "You have chosen to create a primary partition on"},
     "Ju keni zgjedhur p\211r t\211 krijuar nj\211 ndarje t\211 re n\211"},
    {STRING_CHOOSE_NEW_EXTENDED_PARTITION,
     "You have chosen to create an extended partition on"},
    {STRING_CHOOSE_NEW_LOGICAL_PARTITION,
     "You have chosen to create a logical partition on"},
    {STRING_HDDSIZE,
    "Ju lutem, jepini madh\211sin\211 e particionit t\211 ri n\211 megabajt."},
    {STRING_CREATEPARTITION,
     "   ENTER = Krijo Particion   ESC = Anulo   F3 = Dil"},
    {STRING_PARTFORMAT,
    "Ky particion do t\211 formatohet tani."},
    {STRING_NONFORMATTEDPART,
    "Ju zgjodh\211t classicOS p\211r tu instaluar n\211 nj\211 particion t'ri t\211 paformatuar."},
    {STRING_NONFORMATTEDSYSTEMPART,
    "The system partition is not formatted yet."},
    {STRING_NONFORMATTEDOTHERPART,
    "The new partition is not formatted yet."},
    {STRING_INSTALLONPART,
    "Instalimi i classicOS ne Particion"},
    {STRING_CONTINUE,
    "ENTER = Vazhdo"},
    {STRING_QUITCONTINUE,
    "F3 = Dil  ENTER = Vazhdo"},
    {STRING_REBOOTCOMPUTER,
    "ENTER = Ristarto kompjuterin"},
    {STRING_DELETING,
     "   Deleting file: %S"},
    {STRING_MOVING,
     "   Moving file: %S to: %S"},
    {STRING_RENAMING,
     "   Renaming file: %S to: %S"},
    {STRING_COPYING,
     "   Kopjo dokumentat: %S"},
    {STRING_SETUPCOPYINGFILES,
     "Instalimi po kopjon dokumentat..."},
    {STRING_REGHIVEUPDATE,
    "   Apdejtimi i kosheres s\211 regjistrit..."},
    {STRING_IMPORTFILE,
    "   Importimi %S..."},
    {STRING_DISPLAYSETTINGSUPDATE,
    "   Apdejtimi i regjistrit p\211r ekranin..."},
    {STRING_LOCALESETTINGSUPDATE,
    "   Apdejtimi i konfigurimit vendas..."},
    {STRING_KEYBOARDSETTINGSUPDATE,
    "   Apdejtimi i p\211rzgjedhj\211s se konfigurimit t\211 tastier\211s..."},
    {STRING_CODEPAGEINFOUPDATE,
    "   Shtimi i informacioneve codepage n\211 regjister..."},
    {STRING_DONE,
    "   Mbaruam..."},
    {STRING_REBOOTCOMPUTER2,
    "   ENTER = Ristarto kompjuterin"},
    {STRING_REBOOTPROGRESSBAR,
    " Your computer will reboot in %li second(s)... "},
    {STRING_CONSOLEFAIL1,
    "N\211 pamundesi p\211r t\211 hapur konsollin\r\n\r\n"},
    {STRING_CONSOLEFAIL2,
    "Shkaku m\211 i zakonsh\211m i k\211saj \211sht\211 arsyea e perdorimit t\211 nj\211 tastiere USB\r\n"},
    {STRING_CONSOLEFAIL3,
    "Tastierat USB nuk jan\211 t\211 mb\211shtetura ende plot\211sisht\r\n"},
    {STRING_FORMATTINGDISK,
    "Instalimi po formaton diskun tuaj"},
    {STRING_CHECKINGDISK,
    "Instalimi \211sht\211 duke kontrolluar diskun tuaj"},
    {STRING_FORMATDISK1,
    " Formato particionin si %S dokumentat e sistemit (formatim i shpejt\211) "},
    {STRING_FORMATDISK2,
    " Formato particionin si %S dokumentat e sistemit"},
    {STRING_KEEPFORMAT,
    " Mbaj dokumentat e sistemit siq jan\211 (pa ndryshime) "},
    {STRING_HDINFOPARTCREATE_1,
    "%s."},
    {STRING_HDINFOPARTDELETE_1,
    "on %s."},
    {STRING_PARTTYPE,
    "Tipi 0x%02x"},
    {STRING_HDDINFO_1,
    // "Harddisku %lu (%I64u %s), Port=%hu, Bus=%hu, Id=%hu (%wZ) [%s]"
    "%I64u %s Harddisku %lu (Port=%hu, Bus=%hu, Id=%hu) on %wZ [%s]"},
    {STRING_HDDINFO_2,
    // "Harddisku %lu (%I64u %s), Port=%hu, Bus=%hu, Id=%hu [%s]"
    "%I64u %s Harddisku %lu (Port=%hu, Bus=%hu, Id=%hu) [%s]"},
    {STRING_NEWPARTITION,
    "Instalimi krijoj nj\211 particion t\211 ri n\211"},
    {STRING_UNPSPACE,
    "Hap\211sire e papjesesezuar"},
    {STRING_MAXSIZE,
    "MB (max. %lu MB)"},
    {STRING_EXTENDED_PARTITION,
    "Extended Partition"},
    {STRING_UNFORMATTED,
    "I ri (papjesesezuar)"},
    {STRING_FORMATUNUSED,
    "E paperdorur"},
    {STRING_FORMATUNKNOWN,
    "E paditur"},
    {STRING_KB,
    "KB"},
    {STRING_MB,
    "MB"},
    {STRING_GB,
    "GB"},
    {STRING_ADDKBLAYOUTS,
    "Shtim e p\211rzgjedhjes s\211 tastier\211s"},
    {0, 0}
};
