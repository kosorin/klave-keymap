#include "compose.km.h"

#include <stddef.h>
#include "progmem.h"
#include "send_string_keycodes.h"


#define XC_DIACRITIC_PREFIX_ACUTE "'"
#define XC_DIACRITIC_PREFIX_CARON "<"
#define XC_DIACRITIC_PREFIX_ARING "*"

const char *compose_map[XC__COUNT][2] = {
    [XC_Ua    ] = { XC_DIACRITIC_PREFIX_ACUTE"u", XC_DIACRITIC_PREFIX_ACUTE"U" }, // ú Ú
    [XC_Ea    ] = { XC_DIACRITIC_PREFIX_ACUTE"e", XC_DIACRITIC_PREFIX_ACUTE"E" }, // é É
    [XC_Ia    ] = { XC_DIACRITIC_PREFIX_ACUTE"i", XC_DIACRITIC_PREFIX_ACUTE"I" }, // í Í
    [XC_Oa    ] = { XC_DIACRITIC_PREFIX_ACUTE"o", XC_DIACRITIC_PREFIX_ACUTE"O" }, // ó Ó
    [XC_Aa    ] = { XC_DIACRITIC_PREFIX_ACUTE"a", XC_DIACRITIC_PREFIX_ACUTE"A" }, // á Á
    [XC_Ya    ] = { XC_DIACRITIC_PREFIX_ACUTE"y", XC_DIACRITIC_PREFIX_ACUTE"Y" }, // ý Ý
    [XC_Ec    ] = { XC_DIACRITIC_PREFIX_CARON"e", XC_DIACRITIC_PREFIX_CARON"E" }, // ě Ě
    [XC_Rc    ] = { XC_DIACRITIC_PREFIX_CARON"r", XC_DIACRITIC_PREFIX_CARON"R" }, // ř Ř
    [XC_Tc    ] = { XC_DIACRITIC_PREFIX_CARON"t", XC_DIACRITIC_PREFIX_CARON"T" }, // ť Ť
    [XC_Zc    ] = { XC_DIACRITIC_PREFIX_CARON"z", XC_DIACRITIC_PREFIX_CARON"Z" }, // ž Ž
    [XC_Sc    ] = { XC_DIACRITIC_PREFIX_CARON"s", XC_DIACRITIC_PREFIX_CARON"S" }, // š Š
    [XC_Dc    ] = { XC_DIACRITIC_PREFIX_CARON"d", XC_DIACRITIC_PREFIX_CARON"D" }, // ď Ď
    [XC_Cc    ] = { XC_DIACRITIC_PREFIX_CARON"c", XC_DIACRITIC_PREFIX_CARON"C" }, // č Č
    [XC_Nc    ] = { XC_DIACRITIC_PREFIX_CARON"n", XC_DIACRITIC_PREFIX_CARON"N" }, // ň Ň
    [XC_Ur    ] = { XC_DIACRITIC_PREFIX_ARING"u", XC_DIACRITIC_PREFIX_ARING"U" }, // ů Ů
    [XC_DEG   ] = { "*0", NULL }, // ° Znak stupně
    [XC_ACUTE ] = { NULL, NULL }, // ´ Čárka
    [XC_CARON ] = { NULL, NULL }, // ˇ Háček
    [XC_BDQUO ] = { NULL, NULL }, // „ Počáteční uvozovka dvojitá
    [XC_LDQUO ] = { NULL, NULL }, // “ Koncová uvozovka dvojitá / Anglická počáteční uvozovka dvojitá
    [XC_BSQUO ] = { NULL, NULL }, // ‚ Počáteční uvozovka jednoduchá
    [XC_LSQUO ] = { NULL, NULL }, // ‘ Koncová uvozovka jednoduchá / Anglická počáteční uvozovka jednoduchá
    [XC_RAQUO ] = { NULL, NULL }, // » Dvojité lomené uvozovky vpravo
    [XC_LAQUO ] = { NULL, NULL }, // « Dvojité lomené uvozovky vlevo
    [XC_RSAQUO] = { NULL, NULL }, // › Jednoduché lomené uvozovky vpravo
    [XC_LSAQUO] = { NULL, NULL }, // ‹ Jednoduché lomené uvozovky vlevo
    [XC_RDQUO ] = { NULL, NULL }, // ” Anglická koncová uvozovka dvojitá
    [XC_RSQUO ] = { NULL, NULL }, // ’ Anglická koncová uvozovka jednoduchá
    [XC_NDASH ] = { "--,", NULL }, // – En pomlčka
    [XC_MDASH ] = { "---", NULL }, // — Em pomlčka
    [XC_NBSP  ] = { "  ", NULL }, //   Nepřerušující mezera
    [XC_ELLIP ] = { "..", NULL }, // … Výpustka
    [XC_MIDDOT] = { ".-", NULL }, // · Middle dot
    [XC_EURO  ] = { NULL, NULL }, // € Euro
    [XC_CENT  ] = { NULL, NULL }, // ¢ Cent
    [XC_POUND ] = { NULL, NULL }, // £ Pound
    [XC_CURR  ] = { NULL, NULL }, // ¤ Currency
    [XC_YEN   ] = { NULL, NULL }, // ¥ Yen
    [XC_WON   ] = { NULL, NULL }, // ₩ Won
    [XC_RUPEE ] = { NULL, NULL }, // ₹ Rupee
    [XC_BTC   ] = { NULL, NULL }, // ₿ Bitcoin
	[XC_SEC   ] = { "s!", NULL }, // §
	[XC_PAR   ] = { "p!", NULL }, // ¶
	[XC_CHECK ] = { NULL, NULL }, // ✓
	[XC_CROSS ] = { NULL, NULL }, // ✗
	[XC_INF   ] = { NULL, NULL }, // ∞
	[XC_PERM  ] = { NULL, NULL }, // ‰
	[XC_IBANG ] = { NULL, NULL }, // ‽
	[XC_OBOX  ] = { NULL, NULL }, // ␣
	[XC_SQRT  ] = { NULL, NULL }, // √
	[XC_SPRIME] = { NULL, NULL }, // ′
	[XC_DPRIME] = { NULL, NULL }, // ″
};
