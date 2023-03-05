#include "compose.f.h"
#include "compose.km.h"

#include <stddef.h>
#include "progmem.h"
#include "send_string_keycodes.h"


#define XC_DIACRITIC_PREFIX_ACUTE "'"
#define XC_DIACRITIC_PREFIX_CARON "<"
#define XC_DIACRITIC_PREFIX_ARING "*"

compose_data_t compose_map[XC__COUNT] = {
    [XC_Ua    ] = (compose_data_t){ XC_DIACRITIC_PREFIX_ACUTE"u", XC_DIACRITIC_PREFIX_ACUTE"U" }, // ú Ú
    [XC_Ea    ] = (compose_data_t){ XC_DIACRITIC_PREFIX_ACUTE"e", XC_DIACRITIC_PREFIX_ACUTE"E" }, // é É
    [XC_Ia    ] = (compose_data_t){ XC_DIACRITIC_PREFIX_ACUTE"i", XC_DIACRITIC_PREFIX_ACUTE"I" }, // í Í
    [XC_Oa    ] = (compose_data_t){ XC_DIACRITIC_PREFIX_ACUTE"o", XC_DIACRITIC_PREFIX_ACUTE"O" }, // ó Ó
    [XC_Aa    ] = (compose_data_t){ XC_DIACRITIC_PREFIX_ACUTE"a", XC_DIACRITIC_PREFIX_ACUTE"A" }, // á Á
    [XC_Ya    ] = (compose_data_t){ XC_DIACRITIC_PREFIX_ACUTE"y", XC_DIACRITIC_PREFIX_ACUTE"Y" }, // ý Ý
    [XC_Ec    ] = (compose_data_t){ XC_DIACRITIC_PREFIX_CARON"e", XC_DIACRITIC_PREFIX_CARON"E" }, // ě Ě
    [XC_Rc    ] = (compose_data_t){ XC_DIACRITIC_PREFIX_CARON"r", XC_DIACRITIC_PREFIX_CARON"R" }, // ř Ř
    [XC_Tc    ] = (compose_data_t){ XC_DIACRITIC_PREFIX_CARON"t", XC_DIACRITIC_PREFIX_CARON"T" }, // ť Ť
    [XC_Zc    ] = (compose_data_t){ XC_DIACRITIC_PREFIX_CARON"z", XC_DIACRITIC_PREFIX_CARON"Z" }, // ž Ž
    [XC_Sc    ] = (compose_data_t){ XC_DIACRITIC_PREFIX_CARON"s", XC_DIACRITIC_PREFIX_CARON"S" }, // š Š
    [XC_Dc    ] = (compose_data_t){ XC_DIACRITIC_PREFIX_CARON"d", XC_DIACRITIC_PREFIX_CARON"D" }, // ď Ď
    [XC_Cc    ] = (compose_data_t){ XC_DIACRITIC_PREFIX_CARON"c", XC_DIACRITIC_PREFIX_CARON"C" }, // č Č
    [XC_Nc    ] = (compose_data_t){ XC_DIACRITIC_PREFIX_CARON"n", XC_DIACRITIC_PREFIX_CARON"N" }, // ň Ň
    [XC_Ur    ] = (compose_data_t){ XC_DIACRITIC_PREFIX_ARING"u", XC_DIACRITIC_PREFIX_ARING"U" }, // ů Ů
    [XC_DEG   ] = (compose_data_t){ "*0", NULL }, // ° Znak stupně
    [XC_ACUTE ] = (compose_data_t){ NULL, NULL }, // ´ Čárka
    [XC_CARON ] = (compose_data_t){ NULL, NULL }, // ˇ Háček
    [XC_BDQUO ] = (compose_data_t){ NULL, NULL }, // „ Počáteční uvozovka dvojitá
    [XC_LDQUO ] = (compose_data_t){ NULL, NULL }, // “ Koncová uvozovka dvojitá / Anglická počáteční uvozovka dvojitá
    [XC_BSQUO ] = (compose_data_t){ NULL, NULL }, // ‚ Počáteční uvozovka jednoduchá
    [XC_LSQUO ] = (compose_data_t){ NULL, NULL }, // ‘ Koncová uvozovka jednoduchá / Anglická počáteční uvozovka jednoduchá
    [XC_RAQUO ] = (compose_data_t){ NULL, NULL }, // » Dvojité lomené uvozovky vpravo
    [XC_LAQUO ] = (compose_data_t){ NULL, NULL }, // « Dvojité lomené uvozovky vlevo
    [XC_RSAQUO] = (compose_data_t){ NULL, NULL }, // › Jednoduché lomené uvozovky vpravo
    [XC_LSAQUO] = (compose_data_t){ NULL, NULL }, // ‹ Jednoduché lomené uvozovky vlevo
    [XC_RDQUO ] = (compose_data_t){ NULL, NULL }, // ” Anglická koncová uvozovka dvojitá
    [XC_RSQUO ] = (compose_data_t){ NULL, NULL }, // ’ Anglická koncová uvozovka jednoduchá
    [XC_NDASH ] = (compose_data_t){ "--.", NULL }, // – En pomlčka
    [XC_MDASH ] = (compose_data_t){ "---", NULL }, // — Em pomlčka
    [XC_NBSP  ] = (compose_data_t){ "  ", NULL }, //   Nepřerušující mezera
    [XC_ELLIP ] = (compose_data_t){ "..", NULL }, // … Výpustka
    [XC_MIDDOT] = (compose_data_t){ ".-", NULL }, // · Middle dot
    [XC_EURO  ] = (compose_data_t){ NULL, NULL }, // € Euro
    [XC_CENT  ] = (compose_data_t){ NULL, NULL }, // ¢ Cent
    [XC_POUND ] = (compose_data_t){ NULL, NULL }, // £ Pound
    [XC_CURR  ] = (compose_data_t){ NULL, NULL }, // ¤ Currency
    [XC_YEN   ] = (compose_data_t){ NULL, NULL }, // ¥ Yen
    [XC_WON   ] = (compose_data_t){ NULL, NULL }, // ₩ Won
    [XC_RUPEE ] = (compose_data_t){ NULL, NULL }, // ₹ Rupee
    [XC_BTC   ] = (compose_data_t){ NULL, NULL }, // ₿ Bitcoin
	[XC_SEC   ] = (compose_data_t){ "s!", NULL }, // §
	[XC_PAR   ] = (compose_data_t){ "p!", NULL }, // ¶
	[XC_CHECK ] = (compose_data_t){ NULL, NULL }, // ✓
	[XC_CROSS ] = (compose_data_t){ NULL, NULL }, // ✗
	[XC_INF   ] = (compose_data_t){ NULL, NULL }, // ∞
	[XC_PERM  ] = (compose_data_t){ NULL, NULL }, // ‰
	[XC_IBANG ] = (compose_data_t){ NULL, NULL }, // ‽
	[XC_OBOX  ] = (compose_data_t){ NULL, NULL }, // ␣
	[XC_SQRT  ] = (compose_data_t){ NULL, NULL }, // √
	[XC_SPRIME] = (compose_data_t){ NULL, NULL }, // ′
	[XC_DPRIME] = (compose_data_t){ NULL, NULL }, // ″
};
