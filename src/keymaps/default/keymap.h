#pragma once

#include QMK_KEYBOARD_H


// typedef union {
//     uint32_t raw;
//     struct {
//         bool foo_bar : 1;
//     };
// } user_config_t;


#if defined(UNICODEMAP_ENABLE)
enum unicode_names {
    U_Ual,
    U_Eal,
    U_Ial,
    U_Oal,
    U_Aal,
    U_Yal,
    U_Ecl,
    U_Rcl,
    U_Tcl,
    U_Zcl,
    U_Scl,
    U_Dcl,
    U_Ccl,
    U_Ncl,
    U_Url,
    U_Uau,
    U_Eau,
    U_Iau,
    U_Oau,
    U_Aau,
    U_Yau,
    U_Ecu,
    U_Rcu,
    U_Tcu,
    U_Zcu,
    U_Scu,
    U_Dcu,
    U_Ccu,
    U_Ncu,
    U_Uru,
    U__LETTER_PAIRS_END,
    U_DEG,
    U_ACUTE,
    U_CARON,
    U_BDQUO,
    U_LDQUO,
    U_BSQUO,
    U_LSQUO,
    U_RAQUO,
    U_LAQUO,
    U_RSAQUO,
    U_LSAQUO,
    U_RDQUO,
    U_RSQUO,
    U_NDASH,
    U_MDASH,
    U_NBSP,
    U_ELLIP,
    U_MIDDOT,
    U_EURO,
    U_CENT,
    U_POUND,
    U_CURR,
    U_YEN,
    U_WON,
    U_RUPEE,
    U_BTC,
    U_SEC,
    U_PAR,
    U_CHECK,
    U_CROSS,
    U_INF,
    U_PERM,
    U_IBANG,
    U_OBOX,
    U_SQRT,
    U_SPRIME,
    U_DPRIME,
};
#endif

#if defined(TAP_DANCE_ENABLE)
enum tap_dances {
};
#endif

enum layers {
    L_BASE,
#if defined(UNICODEMAP_ENABLE)
    L_UNICODE,
#endif
    L_LOWER,
    L_RAISE,
    L_ADJUST,
    L_GAME,
};

enum custom_keycodes {
    K_SAFE_RANGE = SAFE_RANGE,
#if defined(CUSTOM_LEADER_ENABLE)
    K_LEAD,
#endif
};


enum keycode_aliases {
#if !defined(CUSTOM_LEADER_ENABLE)
    K_LEAD = KC_NO,
#endif

#if defined(UNICODEMAP_ENABLE)
    K_UC = OSL(L_UNICODE),
#else
    K_UC = KC_NO,
#endif
    K_LWR = MO(L_LOWER),
    K_RSE = MO(L_RAISE),

    K_COMP = COMPOSE_KEY,
};
