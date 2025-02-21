// This file is converted by code7bit.
// code7bit: https://github.com/katahiromz/code7bit
// To revert conversion, please execute "code7bit -r <file>".
/* Translated by ??? and Ismael Ferreras Morezuelas (Swyter) revised in 2020 by Julen Urizar Compains*/

#pragma once

static MUI_ENTRY esESSetupInitPageEntries[] =
{
    {
        4,
        3,
        " Instalaci\242n de classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        0,
        20,
        "Por favor, espere a que la instalaci\242n de classicOS se inicie",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_CENTER,
        TEXT_ID_STATIC
    },
    {
        0,
        21,
        "y analice los dispositivos...",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_CENTER,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "Por favor, espere...",
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

static MUI_ENTRY esESLanguagePageEntries[] =
{
    {
        4,
        3,
        " Instalaci\242n de classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "Selecci\242n de idioma",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        10,
        "\x07  Por favor, seleccione el idioma de la instalaci\242n.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        11,
        "   Luego, pulse INTRO.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        13,
        "\x07  El idioma seleccionado ser\240 el idioma del sistema.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "INTRO = Continuar F3 = Salir",
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

static MUI_ENTRY esESWelcomePageEntries[] =
{
    {
        4,
        3,
        " Instalaci\242n de classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "Bienvenido a la instalaci\242n de classicOS",
        TEXT_STYLE_HIGHLIGHT,
        TEXT_ID_STATIC
    },
    {
        6,
        11,
        "Este es el primer paso de instalaci\242n, que copiar\240 classicOS en",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        12,
        "el equipo y preparar\240 el segundo paso de instalaci\242n.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        15,
        "\x07  Pulse INTRO para instalar o actualizar classicOS.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        17,
//      "\x07  Pulse R para reparar una instalación de classicOS usando la Consola de Recuperación.",
        "\x07  Pulse R para reparar classicOS.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        19,
        "\x07  Pulse L para leer los T\202rminos y Condiciones de la licencia.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        21,
        "\x07  Pulse F3 para salir sin instalar classicOS.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        23,
        "Para m\240s informaci\242n sobre classicOS, visite la Web:",
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
        "   INTRO = Continuar  R = Reparar  L = Licencia  F3 = Salir",
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

static MUI_ENTRY esESIntroPageEntries[] =
{
    {
        4,
        3,
        " Instalaci\242n de classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "Situaci\242n de la Versi\242n de classicOS",
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
        "\x07  Pulse INTRO para continuar la instalaci\242n de classicOS.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        21,
        "\x07  Pulse F3 para salir sin instalar classicOS.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "ENTER = Continuar   F3 = Salir",
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

static MUI_ENTRY esESLicensePageEntries[] =
{
    {
        4,
        3,
        " Instalaci\242n de classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        6,
        "T\202rminos y Condiciones de la Licencia:",
        TEXT_STYLE_HIGHLIGHT,
        TEXT_ID_STATIC
    },
    {
        8,
        8,
        "classicOS se distribuye bajo los T\202rminos y Condiciones de",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        9,
        "la licencia GNU GPL, conteniendo secciones de c\242digo de",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        10,
        "licencias compatibles como son X11, o BSD y la GNU LGPL.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        11,
        "Todo el software que forma parte del sistema classicOS est\240,",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        12,
        "por tanto, publicado bajo la licencia GNU GPL, as\241 como",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        13,
        "manteniendo la licencia original.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        15,
        "Este software NO TIENE GARANT\326A ni restricciones de uso",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        16,
        "salvo las leyes locales e internacionales aplicables.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        17,
        "La licencia de classicOS cubre solo la distribuci\242n a terceros.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        18,
        "Si por alg\243n motivo no recibi\242 una copia de la",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        19,
        "GNU General Public License con classicOS visite:",
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
        "Garant\241as:",
        TEXT_STYLE_HIGHLIGHT,
        TEXT_ID_STATIC
    },
    {
        8,
        24,
        "Este es un software libre; lea el c\242digo para las condiciones de copia.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        25,
        "NO tiene garant\241a; ni siquiera MERCANTIL",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        26,
        "o de CUMPLIMIENTO DE PROP\340SITOS PARTICULARES",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "INTRO = Volver",
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

static MUI_ENTRY esESDevicePageEntries[] =
{
    {
        4,
        3,
        " Instalaci\242n de classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "La siguiente lista muestra la configuraci\242n actual de dispositivos.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        24,
        11,
        "Equipo:",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_RIGHT,
        TEXT_ID_STATIC
    },
    {
        24,
        12,
        "Pantalla:",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_RIGHT,
        TEXT_ID_STATIC
    },
    {
        24,
        13,
        "Tipo de teclado:",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_RIGHT,
        TEXT_ID_STATIC
    },
    {
        24,
        14,
        "Distrib. de teclado:",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_RIGHT,
        TEXT_ID_STATIC
    },
    {
        24,
        16,
        "Aceptar:",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_RIGHT,
        TEXT_ID_STATIC
    },
    {
        25,
        16, "Aceptar la configuraci\242n de los dispositivos",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        19,
        "Puede escoger la configuraci\242n de hardware con las teclas",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        20,
        "ARRIBA y ABAJO. Luego, pulse INTRO para cambiar a una",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        21,
        "configuraci\242n alternativa.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        23,
        "Cuando la configuraci\242n sea la correcta, escoja \"Aceptar la",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        24,
        "configuraci\242n de los dispostivos\" y pulse INTRO.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "   INTRO = Continuar   F3 = Salir",
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

static MUI_ENTRY esESRepairPageEntries[] =
{
    {
        4,
        3,
        " Instalaci\242n de classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "La instalaci\242n de classicOS se encuentra en una fase preliminar.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        9,
        "Todav\241a no posee todas las funciones de un instalador completo.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        12,
        "Las funciones de reparaci\242n a\243n no han sido implementadas.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        15,
        "\x07  Pulse U para actualizar el sistema operativo.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        17,
        "\x07  Pulse R para abrir la consola de reparaci\242n.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        19,
        "\x07  Pulse ESC para volver al men\243 principal.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        21,
        "\x07  Pulse INTRO para reiniciar el equipo.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "ESC = Men\243 inicial  U = Actualizar  R = Reparar  INTRO = Reiniciar",
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

static MUI_ENTRY esESUpgradePageEntries[] =
{
    {
        4,
        3,
        " Instalaci\242n de classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "El instalador puede actualizar una de las versiones de classicOS",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        9,
        "listadas a continuaci\242n o, si la instalaci\242n de classicOS est\240 da\244ada,",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        10,
        "puede intentar repararla.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        12,
        "Las funciones de reparaci\242n no est\240 implementadas todav\241a.",
        TEXT_STYLE_HIGHLIGHT,
        TEXT_ID_STATIC
    },
    {
        8,
        15,
        "\x07  Pulse ARRIBA o ABAJO para elegir una instalaci\242n del SO.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        17,
        "\x07  Pulse U para actualizar la instalaci\242n del SO elegida.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        19,
        "\x07  Pulse ESC para continuar con una instalaci\242n nueva.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        21,
        "\x07  Pulse F3 para salir sin instalar classicOS.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "U = Actualizar   ESC = No actualizar   F3 = Salir",
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

static MUI_ENTRY esESComputerPageEntries[] =
{
    {
        4,
        3,
        " Instalaci\242n de classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "Puede modificar el tipo de equipo en el que instalar\240 el SO.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        10,
        "\x07  Pulse ARRIBA y ABAJO para escoger modelo.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        11,
        "Luego, pulse INTRO.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        13,
        "\x07  Pulse ESC para volver a la p\240gina anterior sin cambiar",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        14,
        "el tipo de equipo.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "   INTRO = Continuar   ESC = Cancelar   F3 = Salir",
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

static MUI_ENTRY esESFlushPageEntries[] =
{
    {
        4,
        3,
        " Instalaci\242n de classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        10,
        6,
        "El sistema se est\240 asegurando que los datos est\240n en el disco.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        10,
        8,
        "Esta operaci\242n puede durar varios minutos.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        10,
        9,
        "Cuando haya terminado, el equipo se reiniciar\240 autom\240ticamente.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "Vaciando la cach\202",
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

static MUI_ENTRY esESQuitPageEntries[] =
{
    {
        4,
        3,
        " Instalaci\242n de classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        10,
        6,
        "classicOS no ha sido instalado completamente.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        10,
        8,
        "Retire cualquier disquete de la unidad A:",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        10,
        9,
        "y los CDs de sus respectivas unidades.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        10,
        11,
        "Pulse INTRO para reiniciar el equipo.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "Espere un momento...",
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

static MUI_ENTRY esESDisplayPageEntries[] =
{
    {
        4,
        3,
        " Instalaci\242n de classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "Puede modificar el tipo de pantalla a instalar.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        10,
         "\x07  Pulse ARRIBA y ABAJO para modificar la resoluci\303\263n.",
         TEXT_STYLE_NORMAL,
         TEXT_ID_STATIC
    },
    {
        8,
        11,
        "   Luego, pulse INTRO.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        13,
        "\x07  Pulse la tecla ESC para volver a la p\240gina anterior sin",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        14,
        "   modificar el tipo de pantalla.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "   INTRO = Continuar   ESC = Cancelar   F3 = Salir",
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

static MUI_ENTRY esESSuccessPageEntries[] =
{
    {
        4,
        3,
        " Instalaci\242n de classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        10,
        6,
        "Los componentes b\240sicos de classicOS han sido instalados correctamente.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        10,
        8,
        "Retire cualquier disquete de la unidad A: y",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        10,
        9,
        "los CDs de sus respectivas unidades.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        10,
        11,
        "Pulse INTRO para reiniciar el equipo.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "   INTRO = Reiniciar el equipo",
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

static MUI_ENTRY esESBootPageEntries[] =
{
    {
        4,
        3,
        " Instalaci\242n de classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "El instalador no pudo instalar el cargador de arranque en el disco",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        9,
        "duro del equipo",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        13,
        "Inserte un disquete formateado en la unidad A: y",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        14,
        "Pulse INTRO.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "   INTRO = Continuar   F3 = Salir",
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

static MUI_ENTRY esESSelectPartitionEntries[] =
{
    {
        4,
        3,
        " Instalaci\242n de classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "La siguiente lista muestra las particiones existentes y el espacio",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        9,
        "disponible en el disco para nuevas particiones.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        11,
        "\x07  Pulse ARRIBA o ABAJO para escoger un elemento de la lista.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        13,
        "\x07  Pulse INTRO para instalar classicOS en la Partici\242n seleccionada.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        15,
        "\x07  Pulse P para crear una Partici\242n Primaria.",
//        "\x07  Pulse C para crear una Nueva Partici\242n.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        17,
        "\x07  Pulse E para crear una Partici\242n Extendida.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        19,
        "\x07  Pulse L para crear una Partici\242n L\242gica.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        21,
        "\x07  Pulse D para eliminar una Partici\242n existente.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "Espere un momento, por favor...",
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

static MUI_ENTRY esESChangeSystemPartition[] =
{
    {
        4,
        3,
        " Instalaci\242n de classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "El sistema de particiones escogido en el disco del sistema",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        12,
        "de tu ordenador",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        16,
        "usa un formato que classicOS no puede gestionar.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        18,
        "Para poder instalar correctamente classicOS, el instalador deber\240 cambiar",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        19,
        "el sistema actual de particiones por uno nuevo.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        21,
        "La propuesta de sistema de partici\242n es:",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        25,
        "\x07  Para aceptar esta opci\242n, pulse INTRO.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        27,
        "\x07  Para cambiar manualmente el sistema de particiones, pulse ESC para volver",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        28,
        "   a la lista de selecci\242n de particiones, luego selecciona o crea un nuevo",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        29,
        "   sistema de pariciones en el disco del sistema.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        32,
        "En caso de que haya otro sistema operativo que depende del sistema",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        33,
        "original de particiones, probablemente necesite reconfigurarlo para",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        34,
        "la nueva partici\242n de sistema, o quiz\240s volver al sistema de particiones",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        35,
        "original una vez haya finalizado la instalaci\242n de classicOS.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "INTRO = Continuar   ESC = Cancelar",
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

static MUI_ENTRY esESConfirmDeleteSystemPartitionEntries[] =
{
    {
        4,
        3,
        " Instalaci\242n de classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "Ha solicitado eliminar la Partici\242n de Sistema.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        10,
        "\220sta puede contener programas de diagn\242stico, configuraci\242n de,",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        11,
        "dispositivos, software, sistemas de arranque de SO (como classicOS) o",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        12,
        "drivers o programas prove\241dos por el fabricante del hardware.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        14,
        "Elimine particiones del sistema \243nicamente si est\240 seguro de que no",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        15,
        "haya programas de ese tipo en la partici\242n, o cuando quiera borrarlos.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        16,
        "Al eliminar una partici\242n puede perder la posibilidad de arrancar el",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        17,
        "equipo desde ese disco duro hasta que termine de instalar classicOS.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        20,
        "\x07  Pulse INTRO para eliminar la Partici\242n del Sistema,",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        21,
        "   se le volver\240 a pedir confirmaci\242n m\240s tarde.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        24,
        "\x07  Pulse ESC para volver a la p\240gina anterior. Si lo hace ",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        25,
        "   la partici\242n no se eliminar\240.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "INTRO=Continuar  ESC=Cancelar",
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

static MUI_ENTRY esESFormatPartitionEntries[] =
{
    {
        4,
        3,
        " Instalaci\242n de classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "Formato de la partici\242n",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        10,
        "El instalador formatear\240 la partici\242n. Pulse INTRO para continuar.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_FORMAT_PROMPT
    },
    {
        0,
        0,
        "   INTRO = Continuar   F3 = Salir",
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

static MUI_ENTRY esESCheckFSEntries[] =
{
    {
        4,
        3,
        " Instalaci\242n de classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "El instalador est\240 comprobando la Partici\242n seleccionada.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "Espere un momento...",
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

static MUI_ENTRY esESInstallDirectoryEntries[] =
{
    {
        4,
        3,
        " Instalaci\242n de classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "El programa instalar\240 los archivos en la partici\242n seleccionada.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        9,
        "Seleccione el directorio donde quiere instalar classicOS:",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        14,
        "Para cambiar el directorio sugerido, Pulse RETROCESO para eliminar",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        15,
        "car\240cteres y escriba el directorio donde quiere instalar",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        6,
        16,
        "classicOS.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "   INTRO = Continuar   F3 = Salir",
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

static MUI_ENTRY esESFileCopyEntries[] =
{
    {
        4,
        3,
        " Instalaci\242n de classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        0,
        12,
        "Por favor, espere mientras el Instalador de classicOS copia",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_CENTER,
        TEXT_ID_STATIC
    },
    {
        0,
        13,
        "los archivos en el directorio de classicOS.",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_CENTER,
        TEXT_ID_STATIC
    },
    {
        0,
        14,
        "Esta operaci\242n puede durar varios minutos.",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_CENTER,
        TEXT_ID_STATIC
    },
    {
        50,
        0,
        "\xB3 Espere un momento...",
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

static MUI_ENTRY esESBootLoaderEntries[] =
{
    {
        4,
        3,
        " Instalaci\242n de classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "En este paso, el instalador crear\240 el cargador de arranque",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        12,
        "Instalar el cargador de arranque en el disco duro (MBR y VBR).",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        13,
        "Instalar el cargador de arranque en el disco duro (s\242lo VBR).",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        14,
        "Instalar el cargador de inicio en un disquete.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        15,
        "Omitir la instalaci\242n del cargador de arranque.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "   INTRO = Continuar   F3 = Salir",
        TEXT_TYPE_STATUS  | TEXT_PADDING_BIG,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY etESBootLoaderInstallPageEntries[] =
{
    {
        4,
        3,
        " Instalaci\242n de classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "Instalando sector de arranque en el disco, espere por favor...",
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

static MUI_ENTRY esESKeyboardSettingsEntries[] =
{
    {
        4,
        3,
        " Instalaci\242n de classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "Puede cambiar el tipo de teclado instalado.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        10,
        "\x07  Pulse ARRIBA o ABAJO para seleccionar el tipo de teclado.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        11,
        "   Luego, pulse INTRO.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        13,
        "\x07  Pulse la tecla ESC para volver a la p\240gina anterior sin cambiar",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        14,
        "   el tipo de teclado.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "   INTRO = Continuar   ESC = Cancelar   F3 = Salir",
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

static MUI_ENTRY esESLayoutSettingsEntries[] =
{
    {
        4,
        3,
        " Instalaci\242n de classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "Seleccione la distribuci\242n de teclado que quiera instalar.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        10,
        "\x07  Pulse ARRIBA o ABAJO para seleccionar la distribuci\242n de teclado",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        11,
        "   deseada. Luego, pulse INTRO.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        13,
        "\x07  Pulse la tecla ESC para volver a la p\240gina anterior sin cambiar",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        14,
        "   la distribuci\242n de teclado.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "   INTRO = Continuar   ESC = Cancelar   F3 = Salir",
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

static MUI_ENTRY esESPrepareCopyEntries[] =
{
    {
        4,
        3,
        " Instalaci\242n de classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "El instalador se prepara para copiar los archivos de classicOS.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "Creando la lista de archivos a copiar...",
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

static MUI_ENTRY esESSelectFSEntries[] =
{
    {
        4,
        3,
        " Instalaci\242n de classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        17,
        "Seleccione un sistema de archivos de la siguiente lista.",
        0
    },
    {
        8,
        19,
        "\x07  Pulse ARRIBA o ABAJO para seleccionar el sistema de archivos.",
        0
    },
    {
        8,
        21,
        "\x07  Pulse INTRO para formatear la Partici\242n.",
        0
    },
    {
        8,
        23,
        "\x07  Pulse ESC para seleccionar otra Partici\242n.",
        0
    },
    {
        0,
        0,
        "   INTRO = Continuar   ESC = Cancelar   F3 = Salir",
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

static MUI_ENTRY esESDeletePartitionEntries[] =
{
    {
        4,
        3,
        " Instalaci\242n de classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "Ha elegido eliminar la partici\242n",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        18,
        "\x07  Pulse L para eliminar la partici\242n.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        11,
        19,
        "ADVERTENCIA: \255Se perder\240n todos los datos de esta partici\242n!",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        8,
        21,
        "\x07  Pulse ESC para cancelar.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "   L = Eliminar partici\242n   ESC = Cancelar   F3 = Salir",
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

static MUI_ENTRY esESRegistryEntries[] =
{
    {
        4,
        3,
        " Instalaci\242n de classicOS 2k3 Service Pack 2 ",
        TEXT_STYLE_UNDERLINE,
        TEXT_ID_STATIC
    },
    {
        6,
        8,
        "El instalador est\240 actualizando la configuraci\242n del sistema.",
        TEXT_STYLE_NORMAL,
        TEXT_ID_STATIC
    },
    {
        0,
        0,
        "   Creando la estructura del Registro...",
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

MUI_ERROR esESErrorEntries[] =
{
    {
        // NOT_AN_ERROR
        "Completado correctamente\n"
    },
    {
        // ERROR_NOT_INSTALLED
        "classicOS no est\240 completamente instalado en su\n"
        "equipo. Si cierra ahora el Instalador, necesitar\240\n"
        "ejecutarlo otra vez para instalar classicOS.\n"
        "\n"
        "  \x07  Pulse INTRO para continuar con el instalador.\n"
        "  \x07  Pulse F3 para abandonar el instalador.",
        "F3 = Salir  INTRO = Continuar"
    },
    {
        // ERROR_NO_BUILD_PATH
        "\255Error creando las rutas de instalaci\242n para el directorio de classicOS!\n"
        "INTRO = Reiniciar el equipo"
    },
    {
        // ERROR_SOURCE_PATH
        "\255No puede eliminar la partici\242n que contiene el instalador!\n"
        "INTRO = Reiniciar el equipo"
    },
    {
        // ERROR_SOURCE_DIR
        "\255No puede instalar classicOS dentro del directorio fuente!\n"
        "INTRO = Reiniciar el equipo"
    },
    {
        // ERROR_NO_HDD
        "El instalador no pudo encontrar ning\243n disco duro.\n",
        "INTRO = Reiniciar el equipo"
    },
    {
        // ERROR_NO_SOURCE_DRIVE
        "El instalador no pudo encontrar su unidad fuente.\n",
        "INTRO = Reiniciar el equipo"
    },
    {
        // ERROR_LOAD_TXTSETUPSIF
        "El instalador fall\242 al cargar el archivo TXTSETUP.SIF .\n",
        "INTRO = Reiniciar el equipo"
    },
    {
        // ERROR_CORRUPT_TXTSETUPSIF
        "El instalador encontr\242 corrupto el archivo TXTSETUP.SIF .\n",
        "INTRO = Reiniciar el equipo"
    },
    {
        // ERROR_SIGNATURE_TXTSETUPSIF,
        "El instalador encontr\242 una firma incorrecta en TXTSETUP.SIF .\n",
        "INTRO = Reiniciar el equipo"
    },
    {
        // ERROR_DRIVE_INFORMATION
        "El instalador no pudo recibir informaci\242n del disco del sistema.\n",
        "INTRO = Reiniciar el equipo"
    },
    {
        // ERROR_WRITE_BOOT,
        "El instalador fall\242 al instalar el c\242digo de arranque %S en la Partici\242n del Sistema.",
        "INTRO = Reiniciar el equipo"
    },
    {
        // ERROR_LOAD_COMPUTER,
        "El instalador fall\242 al cargar la lista de tipos de equipos.\n",
        "INTRO = Reiniciar el equipo"
    },
    {
        // ERROR_LOAD_DISPLAY,
        "El instalador fall\242 al cargar la lista de resoluciones de pantalla.\n",
        "INTRO = Reiniciar el equipo"
    },
    {
        // ERROR_LOAD_KEYBOARD,
        "El instalador fall\242 al cargar la lista de teclados.\n",
        "INTRO = Reiniciar el equipo"
    },
    {
        // ERROR_LOAD_KBLAYOUT,
        "El instalador fall\242 al cargar la lista de distribuciones de teclado.\n",
        "INTRO = Reiniciar el equipo"
    },
    {
        // ERROR_WARN_PARTITION,
        "\255El instalador encontr\242 que al menos un disco duro contiene una tabla\n"
        "de partici\242n incompatible que no puede ser manejada correctamente!\n"
        "\n"
        "Crear o eliminar particiones puede destruir la tabla de particiones.\n"
        "\n"
        "  \x07  Pulse F3 para salir del instalador.\n"
        "  \x07  Pulse INTRO para continuar.",
        "F3 = Salir  INTRO = Continuar"
    },
    {
        // ERROR_NEW_PARTITION,
        "\255No puede crear una nueva partici\242n dentro\n"
        "de una partici\242n existente!\n"
        "\n"
        "  * Pulse cualquier tecla para continuar.",
        NULL
    },
    {
        // ERROR_DELETE_SPACE,
        "\255No se puede eliminar un espacio de disco sin particionar!\n"
        "\n"
        "  * Pulse cualquier tecla para continuar.",
        NULL
    },
    {
        // ERROR_INSTALL_BOOTCODE,
        "El instalador fall\242 al instalar el c\242digo de arranque %S en la partici\242n del sistema.",
        "INTRO = Reiniciar el equipo"
    },
    {
        // ERROR_NO_FLOPPY,
        "No hay disquete en la unidad A:.",
        "INTRO = Continuar"
    },
    {
        // ERROR_UPDATE_KBSETTINGS,
        "El instalador fall\242 al actualizar la configuraci\242n de distribuci\242n de teclado.",
        "INTRO = Reiniciar el equipo"
    },
    {
        // ERROR_UPDATE_DISPLAY_SETTINGS,
        "El instalador fall\242 al actualizar la configuraci\242n de la pantalla.",
        "INTRO = Reiniciar el equipo"
    },
    {
        // ERROR_IMPORT_HIVE,
        "El instalador fall\242 al importar un archivo de sub\240rbol.",
        "INTRO = Reiniciar el equipo"
    },
    {
        // ERROR_FIND_REGISTRY
        "El instalador fall\242 al buscar los archivos de datos de Registro.",
        "INTRO = Reiniciar el equipo"
    },
    {
        // ERROR_CREATE_HIVE,
        "El instalador fall\242 al crear el sub\240rbol en el Registro.",
        "INTRO = Reiniciar el equipo"
    },
    {
        // ERROR_INITIALIZE_REGISTRY,
        "El instalador fall\242 al iniciar el Registro.",
        "INTRO = Reiniciar el equipo"
    },
    {
        // ERROR_INVALID_CABINET_INF,
        "El Gabinete (CAB) no tiene un archivo inf v\240lido.\n",
        "INTRO = Reiniciar el equipo"
    },
    {
        // ERROR_CABINET_MISSING,
        "No se encuentra Gabinete (CAB).\n",
        "INTRO = Reiniciar el equipo"
    },
    {
        // ERROR_CABINET_SCRIPT,
        "El Gabinete (CAB) no tiene ning\243n script de instalaci\242n.\n",
        "INTRO = Reiniciar el equipo"
    },
    {
        // ERROR_COPY_QUEUE,
        "El instalador fall\242 al abrir la lista de archivos a copiar.\n",
        "INTRO = Reiniciar el equipo"
    },
    {
        // ERROR_CREATE_DIR,
        "El instalador no puede crear los directorios de instalaci\242n.",
        "INTRO = Reiniciar el equipo"
    },
    {
        // ERROR_TXTSETUP_SECTION,
        "El instalador fall\242 al buscar la secci\242n '%S'\n"
        "en TXTSETUP.SIF.\n",
        "INTRO = Reiniciar el equipo"
    },
    {
        // ERROR_CABINET_SECTION,
        "El instalador fall\242 al buscar la secci\242n '%S'\n"
        "en el Gabinete (CAB).\n",
        "INTRO = Reiniciar el equipo"
    },
    {
        // ERROR_CREATE_INSTALL_DIR
        "El instalador no puede crear el directorio de instalaci\242n.",
        "INTRO = Reiniciar el equipo"
    },
    {
        // ERROR_WRITE_PTABLE,
        "El instalador fall\242 al escribir la tabla de particiones.\n"
        "INTRO = Reiniciar el equipo"
    },
    {
        // ERROR_ADDING_CODEPAGE,
        "El instalador fall\242 al a\244adir el c\242digo de p\240ginas al Registro.\n"
        "INTRO = Reiniciar el equipo"
    },
    {
        // ERROR_UPDATE_LOCALESETTINGS,
        "El instalador no pudo configurar el idioma del sistema.\n"
        "INTRO = Reiniciar el equipo"
    },
    {
        // ERROR_ADDING_KBLAYOUTS,
        "El instalador no ha podido agregar la distribuci\242n de teclado al Registro.\n"
        "INTRO = Reiniciar el equipo"
    },
    {
        // ERROR_UPDATE_GEOID,
        "El instalador no ha podido configurar el ID geogr\240fico.\n"
        "INTRO = Reiniciar el equipo"
    },
    {
        // ERROR_DIRECTORY_NAME,
        "Nombre de carpeta no v\240lido.\n"
        "\n"
        "  * Pulse una tecla para continuar."
    },
    {
        // ERROR_INSUFFICIENT_PARTITION_SIZE,
        "La partici\242n selecionada no es lo suficientemente grande como para.\n"
        "instalar classicOS. Se necesita una partici\242n de al menos %lu MB.\n"
        "\n"
        "  * Pulse una tecla para continuar.",
        NULL
    },
    {
        // ERROR_PARTITION_TABLE_FULL,
        "No es posible a\244adir una Partici\242n Primaria o Extendida en la\n"
        "tabla de particiones de este disco porque est\240 completamente llena.\n"
        "\n"
        "  * Pulse una tecla para continuar."
    },
    {
        // ERROR_ONLY_ONE_EXTENDED,
        "No es posible crear m\240s de una Partici\242n Extendida por disco.\n"
        "\n"
        "  * Pulse una tecla para continuar."
    },
    {
        // ERROR_FORMATTING_PARTITION,
        "El instalador es incapaz de formatear la partici\242n:\n"
        " %S\n"
        "\n"
        "INTRO = reiniciar equipo"
    },
    {
        NULL,
        NULL
    }
};

MUI_PAGE esESPages[] =
{
    {
        SETUP_INIT_PAGE,
        esESSetupInitPageEntries
    },
    {
        LANGUAGE_PAGE,
        esESLanguagePageEntries
    },
    {
        WELCOME_PAGE,
        esESWelcomePageEntries
    },
    {
        INSTALL_INTRO_PAGE,
        esESIntroPageEntries
    },
    {
        LICENSE_PAGE,
        esESLicensePageEntries
    },
    {
        DEVICE_SETTINGS_PAGE,
        esESDevicePageEntries
    },
    {
        REPAIR_INTRO_PAGE,
        esESRepairPageEntries
    },
    {
        UPGRADE_REPAIR_PAGE,
        esESUpgradePageEntries
    },
    {
        COMPUTER_SETTINGS_PAGE,
        esESComputerPageEntries
    },
    {
        DISPLAY_SETTINGS_PAGE,
        esESDisplayPageEntries
    },
    {
        FLUSH_PAGE,
        esESFlushPageEntries
    },
    {
        SELECT_PARTITION_PAGE,
        esESSelectPartitionEntries
    },
    {
        CHANGE_SYSTEM_PARTITION,
        esESChangeSystemPartition
    },
    {
        CONFIRM_DELETE_SYSTEM_PARTITION_PAGE,
        esESConfirmDeleteSystemPartitionEntries
    },
    {
        SELECT_FILE_SYSTEM_PAGE,
        esESSelectFSEntries
    },
    {
        FORMAT_PARTITION_PAGE,
        esESFormatPartitionEntries
    },
    {
        CHECK_FILE_SYSTEM_PAGE,
        esESCheckFSEntries
    },
    {
        DELETE_PARTITION_PAGE,
        esESDeletePartitionEntries
    },
    {
        INSTALL_DIRECTORY_PAGE,
        esESInstallDirectoryEntries
    },
    {
        PREPARE_COPY_PAGE,
        esESPrepareCopyEntries
    },
    {
        FILE_COPY_PAGE,
        esESFileCopyEntries
    },
    {
        KEYBOARD_SETTINGS_PAGE,
        esESKeyboardSettingsEntries
    },
    {
        BOOT_LOADER_PAGE,
        esESBootLoaderEntries
    },
    {
        LAYOUT_SETTINGS_PAGE,
        esESLayoutSettingsEntries
    },
    {
        QUIT_PAGE,
        esESQuitPageEntries
    },
    {
        SUCCESS_PAGE,
        esESSuccessPageEntries
    },
    {
        BOOT_LOADER_INSTALLATION_PAGE,
        etESBootLoaderInstallPageEntries
    },
    {
        BOOT_LOADER_FLOPPY_PAGE,
        esESBootPageEntries
    },
    {
        REGISTRY_PAGE,
        esESRegistryEntries
    },
    {
        -1,
        NULL
    }
};

MUI_STRING esESStrings[] =
{
    {STRING_PLEASEWAIT,
     "   Espere un momento..."},
    {STRING_INSTALLCREATEPARTITION,
     "   INTRO = Instalar  P = Crear Primaria   E = Crear Extendida   F3 = Salir"},
    {STRING_INSTALLCREATELOGICAL,
     "   INTRO = Instalar  C = Crear Partici\242n L\242gica   F3 = Salir"},
    {STRING_DELETEPARTITION,
     "   D = Eliminar Partici\242n   F3 = Salir"},
    {STRING_INSTALLDELETEPARTITION,
     "   INTRO = Instalar   D = Eliminar partici\242n   F3 = Salir"},
    {STRING_PARTITIONSIZE,
     "Tama\244o de la nueva Partici\242n:"},
    {STRING_CHOOSENEWPARTITION,
     "Ha elegido crear una nueva Partici\242n Primaria en"},
    {STRING_CHOOSE_NEW_EXTENDED_PARTITION,
     "Ha elegido crear una nueva Partici\242n Extendida en"},
    {STRING_CHOOSE_NEW_LOGICAL_PARTITION,
     "Ha elegido crear una nueva Partici\242n L\242gica en"},
    {STRING_HDDSIZE,
    "Escriba el tama\244o de la nueva Partici\242n en megabytes."},
    {STRING_CREATEPARTITION,
     "   INTRO = Crear Partici\242n   ESC = Cancelar   F3 = Salir"},
    {STRING_PARTFORMAT,
    "A continuaci\242n se formatear\240 esta partici\242n."},
    {STRING_NONFORMATTEDPART,
    "Ha elegido instalar classicOS en una nueva Partici\242n o en una Partici\242n sin formato."},
    {STRING_NONFORMATTEDSYSTEMPART,
    "La Partici\242n del sistema todav\241a no ha sido formateada."},
    {STRING_NONFORMATTEDOTHERPART,
    "La Partici\242n nueva todav\241a no ha sido formateada."},
    {STRING_INSTALLONPART,
    "El instalador est\240 instalando classicOS en la Partici\242n"},
    {STRING_CONTINUE,
    "INTRO = Continuar"},
    {STRING_QUITCONTINUE,
    "F3 = Salir  INTRO = Continuar"},
    {STRING_REBOOTCOMPUTER,
    "INTRO = Reiniciar el equipo"},
    {STRING_DELETING,
     "   Eliminando archivo: %S"},
    {STRING_MOVING,
     "   Moviendo archivo: %S a: %S"},
    {STRING_RENAMING,
     "   Renombrando archivo: %S a: %S"},
    {STRING_COPYING,
     "   Copiando archivo: %S"},
    {STRING_SETUPCOPYINGFILES,
     "El instalador est\240 copiando archivos..."},
    {STRING_REGHIVEUPDATE,
    "   Actualizando el \240rbol del registro..."},
    {STRING_IMPORTFILE,
    "   Importando %S..."},
    {STRING_DISPLAYSETTINGSUPDATE,
    "   Actualizando configuraci\242n del tipo de pantalla..."},
    {STRING_LOCALESETTINGSUPDATE,
    "   Actualizando configuraci\242n regional..."},
    {STRING_KEYBOARDSETTINGSUPDATE,
    "   Actualizando configuraci\242n de distribuci\242n de teclado..."},
    {STRING_CODEPAGEINFOUPDATE,
    "   A\244adiendo informaci\242n al registro..."},
    {STRING_DONE,
    "   Terminado..."},
    {STRING_REBOOTCOMPUTER2,
    "   INTRO = Reiniciar el equipo"},
    {STRING_REBOOTPROGRESSBAR,
    " Tu ordenador se reiniciar\240 en %li segundo(s)... "},
    {STRING_CONSOLEFAIL1,
    "No se pudo abrir la consola\r\n\r\n"},
    {STRING_CONSOLEFAIL2,
    "La causa m\240s com\243n es la utilizaci\242n de un teclado USB\r\n"},
    {STRING_CONSOLEFAIL3,
    "Todav\241a no hay soporte del todo para los teclados USB\r\n"},
    {STRING_FORMATTINGDISK,
    "El instalador est\240 formateando el disco"},
    {STRING_CHECKINGDISK,
    "El instalador est\240 verificando el disco"},
    {STRING_FORMATDISK1,
    " Formatear la partici\242n con sistema de archivos %S (formato r\240pido) "},
    {STRING_FORMATDISK2,
    " Formatear la partici\242n con sistema de archivos %S "},
    {STRING_KEEPFORMAT,
    " Mantener el sistema de archivos actual (sin cambios) "},
    {STRING_HDINFOPARTCREATE_1,
    "%s."},
    {STRING_HDINFOPARTDELETE_1,
    "en %s."},
    {STRING_PARTTYPE,
    "Tipo 0x%02x"},
    {STRING_HDDINFO_1,
    // "Disco duro %lu (%I64u %s), Puerto=%hu, Bus=%hu, Id=%hu (%wZ) [%s]"
    "%I64u %s Disco duro %lu (Puerto=%hu, Bus=%hu, Id=%hu) en %wZ [%s]"},
    {STRING_HDDINFO_2,
    // "Disco duro %lu (%I64u %s), Puerto=%hu, Bus=%hu, Id=%hu [%s]"
    "%I64u %s Disco duro %lu (Puerto=%hu, Bus=%hu, Id=%hu) [%s]"},
    {STRING_NEWPARTITION,
    "El instalador ha creado una nueva Partici\242n en"},
    {STRING_UNPSPACE,
    "Espacio sin particionar"},
    {STRING_MAXSIZE,
    "MB (m\240x. %lu MB)"},
    {STRING_EXTENDED_PARTITION,
    "Partici\242n extendida"},
    {STRING_UNFORMATTED,
    "Nueva (sin formato)"},
    {STRING_FORMATUNUSED,
    "Libre"},
    {STRING_FORMATUNKNOWN,
    "Desconocido"},
    {STRING_KB,
    "KB"},
    {STRING_MB,
    "MB"},
    {STRING_GB,
    "GB"},
    {STRING_ADDKBLAYOUTS,
    "A\244adiendo distribuci\242n de teclado"},
    {0, 0}
};
