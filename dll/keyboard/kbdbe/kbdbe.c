/*
 * Belgian (point) Keyboard layout
 * Copyright (C) 2005 classicOS Development Team
 * Autor: i386DX
 */

/* ToDo - ToFix
 * Dead keys
 */

#define WIN32_NO_STATUS
#include <stdarg.h>
#include <windef.h>
#include <winuser.h>
#include <ndk/kbd.h>

#ifdef _M_IA64
#define ROSDATA static __declspec(allocate(".data"))
#else
#ifdef _MSC_VER
#pragma data_seg(".data")
#define ROSDATA static
#else
#define ROSDATA static __attribute__((section(".data")))
#endif
#endif

#define VK_EMPTY  0xff   /* The non-existent VK */

#define KNUMS     KBDNUMPAD|KBDSPECIAL /* Special + number pad */
#define KMEXT     KBDEXT|KBDMULTIVK    /* Multi + ext */

ROSDATA USHORT scancode_to_vk[] = {
  /* Numbers Row */
  /* - 00 - */
  /* 1 ...         2 ...         3 ...         4 ... */
  VK_EMPTY,     VK_ESCAPE,    '1',          '2',
  '3',          '4',          '5',          '6',
  '7',          '8',          '9',          '0',
  VK_OEM_2,     VK_OEM_MINUS, VK_BACK,
  /* - 0f - */
  /* First Letters Row */
  VK_TAB,       'A',          'Z',          'E',
  'R',          'T',          'Y',          'U',
  'I',          'O',          'P',          VK_OEM_4,
  VK_OEM_6,     VK_RETURN,
  /* - 1d - */
  /* Second Letters Row */
  VK_LCONTROL,
  'Q',          'S',          'D',          'F',
  'G',          'H',          'J',          'K',
  'L',          'M',          VK_OEM_7,     VK_OEM_3,
  VK_LSHIFT,    VK_OEM_5,
  /* - 2c - */
  /* Third letters row */
  'W',          'X',          'C',          'V',
  'B',          'N',          VK_OEM_COMMA,  VK_OEM_PERIOD,
  VK_OEM_1,     VK_OEM_PLUS,  VK_RSHIFT,
  /* - 37 - */
  /* Bottom Row */
  VK_MULTIPLY,  VK_LMENU,     VK_SPACE,     VK_CAPITAL,
  /* - 3b - */
  /* F-Keys */
  VK_F1, VK_F2, VK_F3, VK_F4, VK_F5, VK_F6,
  VK_F7, VK_F8, VK_F9, VK_F10,
  /* - 45 - */
  /* Locks */
  VK_NUMLOCK | KMEXT,
  VK_SCROLL | KBDMULTIVK,
  /* - 47 - */
  /* Number-Pad */
  VK_HOME | KNUMS,      VK_UP | KNUMS,         VK_PRIOR | KNUMS, VK_SUBTRACT,
  VK_LEFT | KNUMS,      VK_CLEAR | KNUMS,      VK_RIGHT | KNUMS, VK_ADD,
  VK_END | KNUMS,       VK_DOWN | KNUMS,       VK_NEXT | KNUMS,
  VK_INSERT | KNUMS,    VK_DELETE | KNUMS,
  /* - 54 - */
  /* Presumably PrtSc */
  VK_SNAPSHOT,
  /* - 55 - */
  /* Oddities, and the remaining standard F-Keys */
  VK_EMPTY,     VK_OEM_102,     VK_F11,       VK_F12,
  /* - 59 - */
  VK_CLEAR,     VK_EMPTY,     VK_EMPTY,     VK_EMPTY,     VK_EMPTY, /* EREOF */
  VK_EMPTY,     VK_EMPTY,     VK_EMPTY,     VK_EMPTY,     VK_EMPTY, /* ZOOM */
  VK_HELP,
  /* - 64 - */
  /* Even more F-Keys (for example, NCR keyboards from the early 90's) */
  VK_F13, VK_F14, VK_F15, VK_F16, VK_F17, VK_F18, VK_F19, VK_F20,
  VK_F21, VK_F22, VK_F23,
  /* - 6f - */
  /* Not sure who uses these codes */
  VK_EMPTY, VK_EMPTY, VK_EMPTY,
  /* - 72 - */
  VK_EMPTY, VK_EMPTY, VK_EMPTY, VK_EMPTY,
  /* - 76 - */
  /* One more f-key */
  VK_F24,
  /* - 77 - */
  VK_EMPTY, VK_EMPTY, VK_EMPTY, VK_EMPTY,
  VK_EMPTY, VK_EMPTY, VK_EMPTY, VK_EMPTY, /* PA1 */
};

ROSDATA VSC_VK extcode0_to_vk[] = {
  { 0x10, VK_MEDIA_PREV_TRACK | KBDEXT },
  { 0x19, VK_MEDIA_NEXT_TRACK | KBDEXT },
  { 0x1D, VK_RCONTROL | KBDEXT },
  { 0x20, VK_VOLUME_MUTE | KBDEXT },
  { 0x21, VK_LAUNCH_APP2 | KBDEXT },
  { 0x22, VK_MEDIA_PLAY_PAUSE | KBDEXT },
  { 0x24, VK_MEDIA_STOP | KBDEXT },
  { 0x2E, VK_VOLUME_DOWN | KBDEXT },
  { 0x30, VK_VOLUME_UP | KBDEXT },
  { 0x32, VK_BROWSER_HOME | KBDEXT },
  { 0x35, VK_DIVIDE | KBDEXT },
  { 0x37, VK_SNAPSHOT | KBDEXT },
  { 0x38, VK_RMENU | KBDEXT },
  { 0x47, VK_HOME | KBDEXT },
  { 0x48, VK_UP | KBDEXT },
  { 0x49, VK_PRIOR | KBDEXT },
  { 0x4B, VK_LEFT | KBDEXT },
  { 0x4D, VK_RIGHT | KBDEXT },
  { 0x4F, VK_END | KBDEXT },
  { 0x50, VK_DOWN | KBDEXT },
  { 0x51, VK_NEXT | KBDEXT },
  { 0x52, VK_INSERT | KBDEXT },
  { 0x53, VK_DELETE | KBDEXT },
  { 0x5B, VK_LWIN | KBDEXT },
  { 0x5C, VK_RWIN | KBDEXT },
  { 0x5D, VK_APPS | KBDEXT },
  { 0x5F, VK_SLEEP | KBDEXT },
  { 0x65, VK_BROWSER_SEARCH | KBDEXT },
  { 0x66, VK_BROWSER_FAVORITES | KBDEXT },
  { 0x67, VK_BROWSER_REFRESH | KBDEXT },
  { 0x68, VK_BROWSER_STOP | KBDEXT },
  { 0x69, VK_BROWSER_FORWARD | KBDEXT },
  { 0x6A, VK_BROWSER_BACK | KBDEXT },
  { 0x6B, VK_LAUNCH_APP1 | KBDEXT },
  { 0x6C, VK_LAUNCH_MAIL | KBDEXT },
  { 0x6D, VK_LAUNCH_MEDIA_SELECT | KBDEXT },
  { 0x1C, VK_RETURN | KBDEXT },
  { 0x46, VK_CANCEL | KBDEXT },
  { 0, 0 },
};

ROSDATA VSC_VK extcode1_to_vk[] = {
  { 0x1d, VK_PAUSE},
  { 0, 0 },
};

ROSDATA VK_TO_BIT modifier_keys[] = {
  { VK_SHIFT,   KBDSHIFT },
  { VK_CONTROL, KBDCTRL },
  { VK_MENU,    KBDALT },
  { 0,          0 }
};

ROSDATA MODIFIERS modifier_bits = {
  modifier_keys,
  6,
  { 0, 1, 2, 4, SHFT_INVALID, SHFT_INVALID, 3 } /* Modifier bit order, NONE, SHIFT, CTRL, ALT, MENU, SHIFT + MENU, CTRL + MENU */
};

ROSDATA VK_TO_WCHARS2 key_to_chars_2mod[] = {
  /* Normal vs Shifted */
  /* The numbers */
  { '4',           0, {0x27,      '4'} },
  { '5',	   0, {'(',       '5'} },
  { '7',           0, {0xE8,      '7'} },
  { '8',           0, {'!',       '8'} },
  { VK_OEM_2,      0, {')',       0xB0} },

  /* Specials */
  { VK_OEM_COMMA,  CAPLOK,   {',',      '?'} },
  { VK_OEM_PERIOD, CAPLOK,   {';',      '.'} },

  { VK_OEM_1,	   CAPLOK,   {':',      '/'} },
  { VK_OEM_3,      0, {0xB2,     0xB3 } },
  { VK_DECIMAL,    0, {'.',      '.'} },
  { VK_TAB,        0, {'\t',     '\t'} },
  { VK_ADD,        0, {'+',      '+'} },
  { VK_DIVIDE,     0, {'/',      '/'} },
  { VK_MULTIPLY,   0, {'*',      '*'} },
  { VK_SUBTRACT,   0, {'-',      '-'} },
  { 0, 0 }
};

ROSDATA VK_TO_WCHARS3 key_to_chars_3mod[] = {
  /* Normal, Shifted, Ctrl */

  /* The alphabet */
  { 'A',         CAPLOK,   {'a', 'A', 0x01} },
  { 'B',         CAPLOK,   {'b', 'B', 0x02} },
  { 'C',         CAPLOK,   {'c', 'C', 0x03} },
  { 'D',         CAPLOK,   {'d', 'D', 0x04} },
  { 'F',         CAPLOK,   {'f', 'F', 0x06} },
  { 'G',         CAPLOK,   {'g', 'G', 0x07} },
  { 'H',         CAPLOK,   {'h', 'H', 0x08} },
  { 'I',         CAPLOK,   {'i', 'I', 0x09} },
  { 'J',         CAPLOK,   {'j', 'J', 0x0a} },
  { 'K',         CAPLOK,   {'k', 'K', 0x0b} },
  { 'L',         CAPLOK,   {'l', 'L', 0x0c} },
  { 'M',         CAPLOK,   {'m', 'M', 0x0d} },
  { 'N',         CAPLOK,   {'n', 'N', 0x0e} },
  { 'O',         CAPLOK,   {'o', 'O', 0x0f} },
  { 'P',         CAPLOK,   {'p', 'P', 0x10} },
  { 'Q',         CAPLOK,   {'q', 'Q', 0x11} },
  { 'R',         CAPLOK,   {'r', 'R', 0x12} },
  { 'S',         CAPLOK,   {'s', 'S', 0x13} },
  { 'T',         CAPLOK,   {'t', 'T', 0x14} },
  { 'U',         CAPLOK,   {'u', 'U', 0x15} },
  { 'V',         CAPLOK,   {'v', 'V', 0x16} },
  { 'W',         CAPLOK,   {'w', 'W', 0x17} },
  { 'X',         CAPLOK,   {'x', 'X', 0x18} },
  { 'Y',         CAPLOK,   {'y', 'Y', 0x19} },
  { 'Z',         CAPLOK,   {'z', 'Z', 0x1a} },
  /* Legacy (telnet-style) ascii escapes */
  { VK_OEM_MINUS, 0, {'-',      '_',      0x1f} }, //0x1f unit separator 
  { VK_RETURN,    0, {'\r',     '\r',     '\n'} },

  { VK_BACK,      0, {'\b',     '\b',     0x7f} },
  { VK_ESCAPE,    0, {0x1b,     0x1b,     0x1b} },
  { VK_SPACE,     0, {' ',      ' ',      ' ' } },
  { VK_CANCEL,    0, {0x03,     0x03,     0x03} },
  { 0,0 }
};

ROSDATA VK_TO_WCHARS4 key_to_chars_4mod[] = {
  /* Normal, Shifted, Ctrl, Ctrl-Alt */

  /* Legacy Ascii generators */
  { '1',	 0, {'&',      '1',     WCH_NONE, '|'     } },
  { '2',         0, {0xE9,     '2',     WCH_NONE, '@'     } },
  { '3',         0, {'"',      '3',     WCH_NONE, '#'     } },
  { '6',	 0, {0xA7,     '6',     WCH_NONE, WCH_DEAD} },
  { '9',         0, {0xE7,     '9',     WCH_NONE, '{'     } },
  { '0',         0, {0xE0,     '0',     WCH_NONE, '}'     } },
  { VK_OEM_PLUS, 0, {'=',      '+',     WCH_NONE, WCH_DEAD} },

  { VK_OEM_4,    0, {WCH_DEAD, WCH_DEAD,WCH_NONE, '['     } },
  { VK_OEM_5,    CAPLOK,   {0xB5,     0xA3,    WCH_NONE, WCH_DEAD} },
  { VK_OEM_6,    0, {'$',      '*',     WCH_NONE, ']'     } },
  { VK_OEM_7,    0, {0xF9,     '%',     WCH_NONE, WCH_DEAD} },
  { VK_EMPTY ,   0, {0xb4,     '`',      '|',     WCH_NONE} },

  { 'E',         CAPLOK,   {'e',      'E',      0x05, 0x20ac} },
  { VK_EMPTY ,   0, {0xa8,     '^',      WCH_NONE, '~'} },

  { VK_OEM_102,  0, {'<',      '>',      0x001c,   '\\'} },
  { 0, 0 }
};

ROSDATA VK_TO_WCHARS5 key_to_chars_5mod[] = {
  /* Normal, Shifted, Ctrl, Ctrl-Alt, C-S-x */
  { '6', 0, {'6', '&', WCH_NONE, WCH_NONE, 0x1e /* RS */} },
  { 0, 0 }
};

ROSDATA VK_TO_WCHARS1 keypad_numbers[] = {
  { VK_NUMPAD0, 0, {'0'} },
  { VK_NUMPAD1, 0, {'1'} },
  { VK_NUMPAD2, 0, {'2'} },
  { VK_NUMPAD3, 0, {'3'} },
  { VK_NUMPAD4, 0, {'4'} },
  { VK_NUMPAD5, 0, {'5'} },
  { VK_NUMPAD6, 0, {'6'} },
  { VK_NUMPAD7, 0, {'7'} },
  { VK_NUMPAD8, 0, {'8'} },
  { VK_NUMPAD9, 0, {'9'} },
  { VK_DECIMAL, 0, {'.'} },
  { 0,0 }
};

#define vk_master(n,x) { (PVK_TO_WCHARS1)x, n, sizeof(x[0]) }

ROSDATA VK_TO_WCHAR_TABLE vk_to_wchar_master_table[] = {
  vk_master(3, key_to_chars_3mod),
  vk_master(4, key_to_chars_4mod),
  vk_master(5, key_to_chars_5mod),
  vk_master(2, key_to_chars_2mod),
  vk_master(1, keypad_numbers),
  { 0,0,0 }
};

ROSDATA VSC_LPWSTR key_names[] = {
  { 0x00, L"" },
  { 0x01, L"Esc" },
  { 0x0e, L"Backspace" },
  { 0x0f, L"Tab" },
  { 0x1c, L"Enter" },
  { 0x1d, L"Ctrl" },
  { 0x2a, L"Shift" },
  { 0x36, L"Right Shift" },
  { 0x37, L"Num *" },
  { 0x38, L"Alt" },
  { 0x39, L"Spatie" },
  { 0x3a, L"CAPLOK Lock" },
  { 0x3b, L"F1" },
  { 0x3c, L"F2" },
  { 0x3d, L"F3" },
  { 0x3e, L"F4" },
  { 0x3f, L"F5" },
  { 0x40, L"F6" },
  { 0x41, L"F7" },
  { 0x42, L"F8" },
  { 0x43, L"F9" },
  { 0x44, L"F10" },
  { 0x45, L"Pause" },
  { 0x46, L"Scroll Lock" },
  { 0x47, L"Num 7" },
  { 0x48, L"Num 8" },
  { 0x49, L"Num 9" },
  { 0x4a, L"Num -" },
  { 0x4b, L"Num 4" },
  { 0x4c, L"Num 5" },
  { 0x4d, L"Num 6" },
  { 0x4e, L"Num +" },
  { 0x4f, L"Num 1" },
  { 0x50, L"Num 2" },
  { 0x51, L"Num 3" },
  { 0x52, L"Num 0" },
  { 0x53, L"Num Del" },
  { 0x54, L"Sys Req" },
  { 0x57, L"F11" },
  { 0x58, L"F12" },
  { 0x7c, L"F13" },
  { 0x7d, L"F14" },
  { 0x7e, L"F15" },
  { 0x7f, L"F16" },
  { 0x80, L"F17" },
  { 0x81, L"F18" },
  { 0x82, L"F19" },
  { 0x83, L"F20" },
  { 0x84, L"F21" },
  { 0x85, L"F22" },
  { 0x86, L"F23" },
  { 0x87, L"F24" },
  { 0, NULL },
};

ROSDATA VSC_LPWSTR extended_key_names[] = {
  { 0x1c, L"Num Enter" },
  { 0x1d, L"Right Ctrl" },
  { 0x35, L"Num /" },
  { 0x37, L"Prnt Scrn" },
  { 0x38, L"Right Alt" },
  { 0x45, L"Num Lock" },
  { 0x46, L"Break" },
  { 0x47, L"Home" },
  { 0x48, L"Up" },
  { 0x49, L"Page Up" },
  { 0x4a, L"Left" },
  { 0x4c, L"Center" },
  { 0x4d, L"Right" },
  { 0x4f, L"End" },
  { 0x50, L"Down" },
  { 0x51, L"Page Down" },
  { 0x52, L"Insert" },
  { 0x53, L"Delete" },
  { 0x54, L"<classicOS>" },
  { 0x55, L"Help" },
  { 0x56, L"Left Windows" },
  { 0x5b, L"Right Windows" },
  { 0, NULL },
};

ROSDATA DEADKEY_LPWSTR dead_key_names[] = {
    L"\x005e"	L"Circumflex",
    L"\x007e"	L"Tilde",
    L"\x0060"	L"Grave",
    NULL
};

#define DEADTRANS(ch, accent, comp, flags) MAKELONG(ch, accent), comp, flags

ROSDATA DEADKEY dead_key[] = {
  /* � */
  { DEADTRANS(0x0061, 0x00a8, 0x00e4, 0x0000) }, // a -> �
  { DEADTRANS(0x0065, 0x00a8, 0x00eb, 0x0000) }, // e -> �
  { DEADTRANS(0x0069, 0x00a8, 0x00ef, 0x0000) }, // i -> �
  { DEADTRANS(0x006f, 0x00a8, 0x00f6, 0x0000) }, // o -> �
  { DEADTRANS(0x0075, 0x00a8, 0x00fc, 0x0000) }, // u -> �
  { DEADTRANS(0x0079, 0x00a8, 0x00ff, 0x0000) }, // y -> �
  { DEADTRANS(0x0041, 0x00a8, 0x00c4, 0x0000) }, // A -> �
  { DEADTRANS(0x0045, 0x00a8, 0x00cb, 0x0000) }, // E -> �
  { DEADTRANS(0x0049, 0x00a8, 0x00cf, 0x0000) }, // I -> �
  { DEADTRANS(0x004f, 0x00a8, 0x00d6, 0x0000) }, // O -> �
  { DEADTRANS(0x0055, 0x00a8, 0x00dc, 0x0000) }, // U -> �
  { DEADTRANS(0x0020, 0x00a8, 0x00a8, 0x0000) }, // Space -> �

  /* ^ */
  { DEADTRANS(0x0061, 0x005e, 0x00e2, 0x0000) }, // a -> �
  { DEADTRANS(0x0065, 0x005e, 0x00ea, 0x0000) }, // e -> �
  { DEADTRANS(0x0069, 0x005e, 0x00ee, 0x0000) }, // i -> �
  { DEADTRANS(0x006f, 0x005e, 0x00f4, 0x0000) }, // o -> �
  { DEADTRANS(0x0075, 0x005e, 0x00fb, 0x0000) }, // u -> �
  { DEADTRANS(0x0041, 0x005e, 0x00c2, 0x0000) }, // A -> �
  { DEADTRANS(0x0045, 0x005e, 0x00ca, 0x0000) }, // E -> �
  { DEADTRANS(0x0049, 0x005e, 0x00ce, 0x0000) }, // I -> �
  { DEADTRANS(0x004f, 0x005e, 0x00d4, 0x0000) }, // O -> �
  { DEADTRANS(0x0055, 0x005e, 0x00db, 0x0000) }, // U -> �
  { DEADTRANS(0x0020, 0x005e, 0x005e, 0x0000) }, // Space -> ^

  /* ~ */
  { DEADTRANS(0x0061, 0x007e, 0x00e3, 0x0000) }, // a -> �
  { DEADTRANS(0x006f, 0x007e, 0x00f5, 0x0000) }, // o -> �
  { DEADTRANS(0x006e, 0x007e, 0x00f1, 0x0000) }, // n -> �
  { DEADTRANS(0x0041, 0x007e, 0x00c3, 0x0000) }, // A -> �
  { DEADTRANS(0x004f, 0x007e, 0x00d5, 0x0000) }, // O -> �
  { DEADTRANS(0x004e, 0x007e, 0x00d1, 0x0000) }, // N -> �
  { DEADTRANS(0x0020, 0x007e, 0x007e, 0x0000) }, // Space -> ~

  /* � */
  { DEADTRANS(0x0061, 0x00b4, 0x00e1, 0x0000) }, // a -> �
  { DEADTRANS(0x0065, 0x00b4, 0x00e9, 0x0000) }, // e -> �
  { DEADTRANS(0x0069, 0x00b4, 0x00ed, 0x0000) }, // i -> �
  { DEADTRANS(0x006f, 0x00b4, 0x00f3, 0x0000) }, // o -> �
  { DEADTRANS(0x0075, 0x00b4, 0x00fa, 0x0000) }, // u -> �
  { DEADTRANS(0x0079, 0x00b4, 0x00fd, 0x0000) }, // y -> �
  { DEADTRANS(0x0041, 0x00b4, 0x00c1, 0x0000) }, // A -> �
  { DEADTRANS(0x0045, 0x00b4, 0x00c9, 0x0000) }, // E -> �
  { DEADTRANS(0x0049, 0x00b4, 0x00cd, 0x0000) }, // I -> �
  { DEADTRANS(0x004f, 0x00b4, 0x00d3, 0x0000) }, // O -> �
  { DEADTRANS(0x0055, 0x00b4, 0x00da, 0x0000) }, // U -> �
  { DEADTRANS(0x0059, 0x00b4, 0x00dd, 0x0000) }, // Y -> �
  { DEADTRANS(0x0020, 0x00b4, 0x00b4, 0x0000) }, // Space -> �

  /* ` */
  { DEADTRANS(0x0061, 0x0060, 0x00e0, 0x0000) }, // a -> �
  { DEADTRANS(0x0065, 0x0060, 0x00e8, 0x0000) }, // e -> �
  { DEADTRANS(0x0069, 0x0060, 0x00ec, 0x0000) }, // i -> �
  { DEADTRANS(0x006f, 0x0060, 0x00f2, 0x0000) }, // o -> �
  { DEADTRANS(0x0075, 0x0060, 0x00f9, 0x0000) }, // u -> �
  { DEADTRANS(0x0041, 0x0060, 0x00c0, 0x0000) }, // A -> �
  { DEADTRANS(0x0045, 0x0060, 0x00c8, 0x0000) }, // E -> �
  { DEADTRANS(0x0049, 0x0060, 0x00cc, 0x0000) }, // I -> �
  { DEADTRANS(0x004f, 0x0060, 0x00d2, 0x0000) }, // O -> �
  { DEADTRANS(0x0055, 0x0060, 0x00d9, 0x0000) }, // U -> �
  { DEADTRANS(0x0020, 0x0060, 0x0060, 0x0000) }, // Space -> `
  { 0, 0 }
};

/* Finally, the master table */
ROSDATA KBDTABLES keyboard_layout_table = {
  /* modifier assignments */
  &modifier_bits,

  /* character from vk tables */
  vk_to_wchar_master_table,

  /* diacritical marks -- currently implemented by wine code */
  dead_key,

  /* Key names */
  (VSC_LPWSTR *)key_names,
  (VSC_LPWSTR *)extended_key_names,
  dead_key_names, /* Dead key names */

  /* scan code to virtual key maps */
  scancode_to_vk,
  RTL_NUMBER_OF(scancode_to_vk),
  extcode0_to_vk,
  extcode1_to_vk,

  MAKELONG(KLLF_ALTGR, 1), /* Version 1.0 */

  /* Ligatures -- None in Dutch */
  0,
  0,
  NULL
};

PKBDTABLES WINAPI KbdLayerDescriptor(VOID) {
  return &keyboard_layout_table;
}

INT WINAPI
DllMain(
  PVOID hinstDll,
  ULONG dwReason,
  PVOID reserved)
{
  UNREFERENCED_PARAMETER(hinstDll);
  UNREFERENCED_PARAMETER(dwReason);
  UNREFERENCED_PARAMETER(reserved);
  return 1;
}
