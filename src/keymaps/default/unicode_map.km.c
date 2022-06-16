#include "unicode_map.km.h"

#include "progmem.h"


const uint32_t unicode_map[] PROGMEM = {
    [U_Ual   ] = 0x00fa, // ú
    [U_Eal   ] = 0x00e9, // é
    [U_Ial   ] = 0x00ed, // í
    [U_Oal   ] = 0x00f3, // ó
    [U_Aal   ] = 0x00e1, // á
    [U_Yal   ] = 0x00fd, // ý
    [U_Ecl   ] = 0x011b, // ě
    [U_Rcl   ] = 0x0159, // ř
    [U_Tcl   ] = 0x0165, // ť
    [U_Zcl   ] = 0x017e, // ž
    [U_Scl   ] = 0x0161, // š
    [U_Dcl   ] = 0x010f, // ď
    [U_Ccl   ] = 0x010d, // č
    [U_Ncl   ] = 0x0148, // ň
    [U_Url   ] = 0x016f, // ů
    [U_Uau   ] = 0x00da, // Ú
    [U_Eau   ] = 0x00c9, // É
    [U_Iau   ] = 0x00cd, // Í
    [U_Oau   ] = 0x00d3, // Ó
    [U_Aau   ] = 0x00c1, // Á
    [U_Yau   ] = 0x00dd, // Ý
    [U_Ecu   ] = 0x011a, // Ě
    [U_Rcu   ] = 0x0158, // Ř
    [U_Tcu   ] = 0x0164, // Ť
    [U_Zcu   ] = 0x017d, // Ž
    [U_Scu   ] = 0x0160, // Š
    [U_Dcu   ] = 0x010e, // Ď
    [U_Ccu   ] = 0x010c, // Č
    [U_Ncu   ] = 0x0147, // Ň
    [U_Uru   ] = 0x016e, // Ů
    [U__LETTER_PAIRS_END] = 0x2327, // ⌧
    [U_DEG   ] = 0x00b0, // ° Znak stupně
    [U_ACUTE ] = 0x00b4, // ´ Čárka
    [U_CARON ] = 0x02c7, // ˇ Háček
    [U_BDQUO ] = 0x201e, // „ Počáteční uvozovka dvojitá
    [U_LDQUO ] = 0x201c, // “ Koncová uvozovka dvojitá / Anglická počáteční uvozovka dvojitá
    [U_BSQUO ] = 0x201a, // ‚ Počáteční uvozovka jednoduchá
    [U_LSQUO ] = 0x2018, // ‘ Koncová uvozovka jednoduchá / Anglická počáteční uvozovka jednoduchá
    [U_RAQUO ] = 0x00bb, // » Dvojité lomené uvozovky vpravo
    [U_LAQUO ] = 0x00ab, // « Dvojité lomené uvozovky vlevo
    [U_RSAQUO] = 0x203a, // › Jednoduché lomené uvozovky vpravo
    [U_LSAQUO] = 0x2039, // ‹ Jednoduché lomené uvozovky vlevo
    [U_RDQUO ] = 0x201d, // ” Anglická koncová uvozovka dvojitá
    [U_RSQUO ] = 0x2019, // ’ Anglická koncová uvozovka jednoduchá
    [U_NDASH ] = 0x2013, // – En pomlčka
    [U_MDASH ] = 0x2014, // — Em pomlčka
    [U_NBSP  ] = 0x00a0, //   Nepřerušující mezera
    [U_ELLIP ] = 0x2026, // … Výpustka
    [U_MIDDOT] = 0x00b7, // · Middle dot
    [U_EURO  ] = 0x20ac, // € Euro
    [U_CENT  ] = 0x00a2, // ¢ Cent
    [U_POUND ] = 0x00a3, // £ Pound
    [U_CURR  ] = 0x00a4, // ¤ Currency
    [U_YEN   ] = 0x00a5, // ¥ Yen
    [U_WON   ] = 0x20a9, // ₩ Won
    [U_RUPEE ] = 0x20b9, // ₹ Rupee
    [U_BTC   ] = 0x20bf, // ₿ Bitcoin
	[U_SEC   ] = 0x00a7, // §
	[U_PAR   ] = 0x00b6, // ¶
	[U_CHECK ] = 0x2713, // ✓
	[U_CROSS ] = 0x2717, // ✗
	[U_INF   ] = 0x221e, // ∞
	[U_PERM  ] = 0x2030, // ‰
	[U_IBANG ] = 0x203d, // ‽
	[U_OBOX  ] = 0x2423, // ␣
	[U_SQRT  ] = 0x221a, // √
	[U_SPRIME] = 0x2032, // ′
	[U_DPRIME] = 0x2033, // ″
};
